#include "phantomrelease.h"
#include "singleton.h"
#include <QDir>
#include <QFileInfo>
#include <QProcess>
#include <QRegularExpression>

//hrkim 20261026 sysmgr 하드웨어 시험 명령(HWTEST_ACT) — guiapi(HW팀 코드)를 고치지 않고 같은 IPC 로 보낸다 (공정 테스트 앱 Hal::hwTestAct 와 같은 길)
extern int vtIpcProcess (uint8_t msgId, uint8_t msgAct, void *dataP, int dLen);

namespace {
//=======================
// 설정 — 바꿀 일이 생기면 여기만 (XW-0446 A안, XW-0453)
//=======================
const char *DLABEL_DIR          = "mes-dlabel";         // p6 디지털 라벨 폴더 (Singleton::deleteDigitalLabel 과 같은 자리)
const char *DLABEL_PROD_FILE    = "prod_serial";        // 생산 시리얼 — 포팅 지그가 씀
const char *DLABEL_SHIP_FILE    = "ship_serial";        // 출하 시리얼 — 최종 테스트 PC 가 USB 로 씀 (라벨 (21) 값 한 줄)
const char *SERIAL_NUM_FILE     = "vdata/serial_num";   // sysmgr SN_SET 이 쓰는 파일 (p6 기준)
const char *RESULT_PREFIX       = "MESDL1";             // 결과 코드 머리 (mes 확정 2026-10-26)
const int   SHIP_SERIAL_MAX     = 62;                   // guiapi getFwVersion 버퍼 64 = 시리얼 + '\n' + NUL
const char *SHIP_SERIAL_PATTERN = "^[A-Za-z0-9-]+$";    // ':' 는 결과 코드 칸 구분자라 받지 않음
const bool  SHIP_SERIAL_REQUIRED = true;                // ship_serial 이 없으면 해제 안 함(D-54). false 면 기록을 건너뛰고 삭제만 (지금 흐름 호환)

const char *FT_DIR_DEFAULT      = "/home/root/factoryTest";                    // 공정 테스트 앱 폴더 (rootfs)
const char *FT_UNIT_DEFAULT     = "/etc/systemd/system/factorytest.service";   // 공정 테스트 앱 자동 기동 유닛
const char *FT_DIR_ENV          = "HZ_FACTORYTEST_DIR";    // 기기 시험 때만 경로를 바꾸는 환경변수 (평소 없음)
const char *FT_UNIT_ENV         = "HZ_FACTORYTEST_UNIT";
const char *FT_DEVMODE          = "devmode.sh";            // 공통 모듈 — 있으면 공정 테스트 앱이 깔린 것
const char *FT_BINARY           = "factoryTest";
const int   FT_SWITCH_TIMEOUT_MS = 15000;
const int   FT_PURGE_TIMEOUT_MS  = 30000;
const bool  FT_RETURN_PHANTOM_NORMAL = false;   // D-61 4번(공정 테스트 NORMAL·MASS 비교 뒤 Hr 결정): true 면 표식만 지우고 팬텀 NORMAL SET 으로 재부팅

const char *USB_UDC_CLASS_DIR   = "/sys/class/udc";        // <udc>/device/gadget/lun0/file — PC 가 꺼내면 빈 값
const char *USB_LUN_FILE        = "device/gadget/lun0/file";

#if !DEVICE
bool g_bMockUsb = false;    // PC 개발 모드: USB 연결 흉내
#endif
}

int PhantomRelease::runRelease(State &state)
{
    Singleton &instance = Singleton::getInstance();

    //1. ship_serial 읽기 → SN_SET → 되읽기 같은지 → sync
    if(!state.bSnDone)
    {
        state.strShipSerial.clear();
        state.strReadback.clear();

        //p6 가 다시 붙은 것을 확인한 뒤에만 읽고 기록한다 — 안 붙었으면 [USB 연결]부터 (USB 해제·다시 붙이기 포함)
        QString strBase = instance.getVdataMountPath();
        if(strBase.isEmpty() || usbMediaState() != USB_MEDIA_NONE)
        {
            qDebug()<<"[fail] release: p6 not mounted";
            return RESULT_NO_SHIP;
        }

        QString strDir = strBase + "/" + DLABEL_DIR + "/";
        state.strProdSerial = readFirstLine(strDir + DLABEL_PROD_FILE);
        QString strShip = readFirstLine(strDir + DLABEL_SHIP_FILE);

        if(strShip.isEmpty() && !SHIP_SERIAL_REQUIRED)
        {
            qDebug()<<"release: no ship_serial, skip SN_SET";
        }
        else
        {
            if(!isValidShipSerial(strShip))
            {
                qDebug()<<"[fail] release: ship_serial invalid:"<<strShip;
                return RESULT_NO_SHIP;
            }

            state.strShipSerial = strShip;
            if(!writeShipSerial(strBase, strShip, &state.strReadback))
                return RESULT_SN_FAIL;
        }
        state.bSnDone = true;
    }

    //2. mes-dlabel 삭제·sync·재확인 (XW-0416) — ship_serial 이 그 폴더 안에 있으므로 기록 뒤에
    if(!state.bDelDone)
    {
        if(instance.deleteDigitalLabel() == DLABEL_DELETE_FAIL)
            return RESULT_DEL_FAIL;
        state.bDelDone = true;
    }

    //3. 공정 테스트 앱 삭제 — 앞 단계가 모두 성공했을 때만 (앞에서 실패하면 앱이 남아 재작업 길이 유지됨)
    if(!state.bFtDone)
    {
        QString strErr;
        if(!purgeFactoryTest(&strErr))
        {
            qDebug()<<"[fail] release: purge"<<strErr;
            return RESULT_FT_FAIL;
        }
        state.bFtDone = true;
    }

    return RESULT_OK;
}

QString PhantomRelease::resultName(int nResult)
{
    switch(nResult)
    {
    case RESULT_OK:       return "OK";
    case RESULT_SN_FAIL:  return "SN-FAIL";
    case RESULT_DEL_FAIL: return "DEL-FAIL";
    case RESULT_NO_SHIP:  return "NO-SHIP";
    case RESULT_FT_FAIL:  return "FT-FAIL";
    default:              return "FAIL";
    }
}

QString PhantomRelease::resultCode(int nResult, const State &state)
{
    //하이픈만 써서 QR 영숫자 모드 유지 (밑줄이면 바이트 모드로 커짐)
    return QString("%1:%2:%3:%4").arg(RESULT_PREFIX, resultName(nResult), state.strReadback, state.strProdSerial);
}

QString PhantomRelease::readFirstLine(const QString &strPath)
{
    QFile file(strPath);
    if(!file.open(QIODevice::ReadOnly))
        return QString();

    //PC 가 CRLF 로 써도 같은 값 (첫 줄, 앞뒤 공백 제거)
    QString strLine = QString::fromUtf8(file.readLine(256)).trimmed();
    file.close();
    return strLine;
}

bool PhantomRelease::isValidShipSerial(const QString &strSerial)
{
    if(strSerial.isEmpty() || strSerial.size() > SHIP_SERIAL_MAX)
        return false;

    return QRegularExpression(SHIP_SERIAL_PATTERN).match(strSerial).hasMatch();
}

bool PhantomRelease::writeShipSerial(const QString &strBase, const QString &strSerial, QString *strReadback)
{
    //SN_SET 은 받은 값을 serial_num 에 그대로 쓰고(줄바꿈·sync 없음) 읽는 쪽 4곳은 마지막 1바이트를 줄바꿈으로 보고 뗀다
    //→ 시리얼 + "\n" 으로 한 번 쓰고 파일을 직접 되읽어 비교 (XW-0446 확인 ②)
    QByteArray baExpect = strSerial.toLatin1() + "\n";
    QString strPath = strBase + "/" + SERIAL_NUM_FILE;

#if DEVICE
    gapiHwTestActParam_t param;
    memset(&param, 0, sizeof(param));
    param.item = GAPI_HWTEST_ITEM_SN_SET;
    memcpy(param.opt, baExpect.constData(), qMin(baExpect.size(), GAPI_HWTEST_OPT_MAX_LEN - 1));
    if(vtIpcProcess((uint8_t)VTIPC_MSGID_HWTEST_ACT, (uint8_t)VTIPC_MSGACT_SET, &param, sizeof(param)) != GAPI_SUCCESS)
        qDebug()<<"[fail] release: SN_SET ipc fail";   //판정은 되읽기로
#else
    //PC 개발 모드: 실행 폴더 아래에 직접 쓴다 (모의)
    QDir().mkpath(QFileInfo(strPath).absolutePath());
    QFile fileMock(strPath);
    if(fileMock.open(QIODevice::WriteOnly))
    {
        fileMock.write(baExpect);
        fileMock.close();
    }
#endif

    QByteArray baRead;
    QFile file(strPath);
    if(file.open(QIODevice::ReadOnly))
    {
        baRead = file.read(128);
        file.close();
    }
    ::sync();   //SN_SET 은 sync 하지 않음 — SET(직후 재부팅) 전에 남도록

    //되읽은 값 = 기기가 보는 시리얼 (읽는 쪽처럼 마지막 1바이트를 뗌)
    QByteArray baShow = baRead.left(qMax(0, baRead.size() - 1));
    *strReadback = QString::fromLatin1(baShow).remove(QRegularExpression("[^\\x21-\\x7E]"));

    bool bOk = (baRead == baExpect);
    qDebug()<<"release: SN_SET"<<strSerial<<"readback"<<*strReadback<<(bOk ? "OK" : "FAIL");
    return bOk;
}

bool PhantomRelease::usbStart(QString *strErr)
{
#if DEVICE
    Singleton &instance = Singleton::getInstance();

    if(instance.guiApi.glucoseSetGdataStorage(GAPI_ACT_START) != GAPI_SUCCESS)
    {
        *strErr = "USB START FAIL";
        return false;
    }

    //guiapi 는 umount·modprobe 결과를 보지 않는다 → p6 가 내려가고 가젯이 p6 를 들고 있는지 직접 확인
    if(!instance.getVdataMountPath().isEmpty())
    {
        //p6 가 붙은 채 PC 에 내주면 양쪽에서 써서 깨질 수 있음 → 바로 되돌림
        QString strStop;
        usbStop(&strStop);
        *strErr = "P6 BUSY";
        return false;
    }

    if(usbMediaState() != USB_MEDIA_LOADED)
    {
        QString strStop;
        usbStop(&strStop);
        *strErr = "USB GADGET FAIL";
        return false;
    }

    qDebug()<<"usb: p6 opened to PC";
    return true;
#else
    Q_UNUSED(strErr);
    g_bMockUsb = true;
    return true;
#endif
}

bool PhantomRelease::usbStop(QString *strErr)
{
#if DEVICE
    Singleton &instance = Singleton::getInstance();

    //PC 가 꺼냈든(power-off 포함) 케이블을 뽑았든 기기 안의 일: 가젯 내리기 → p6 다시 붙이기
    if(instance.guiApi.glucoseSetGdataStorage(GAPI_ACT_STOP) != GAPI_SUCCESS)
    {
        *strErr = "USB STOP FAIL";
        return false;
    }

    if(usbMediaState() != USB_MEDIA_NONE)
    {
        *strErr = "USB GADGET LEFT";
        return false;
    }

    if(instance.getVdataMountPath().isEmpty())
    {
        *strErr = "P6 MOUNT FAIL";
        return false;
    }

    qDebug()<<"usb: p6 mounted again";
    return true;
#else
    Q_UNUSED(strErr);
    g_bMockUsb = false;
    return true;
#endif
}

int PhantomRelease::usbMediaState()
{
#if DEVICE
    QString strLun = usbLunFilePath();
    if(strLun.isEmpty())
        return USB_MEDIA_NONE;

    QFile file(strLun);
    if(!file.open(QIODevice::ReadOnly))
        return USB_MEDIA_NONE;

    QByteArray baFile = file.readAll().trimmed();
    file.close();
    return baFile.isEmpty() ? USB_MEDIA_EJECTED : USB_MEDIA_LOADED;
#else
    return g_bMockUsb ? USB_MEDIA_LOADED : USB_MEDIA_NONE;
#endif
}

QString PhantomRelease::usbLunFilePath()
{
    //저장장치 가젯이 올라와 있을 때만 생긴다 (g_ether 등 다른 가젯이면 없음)
    QDir dirUdc(USB_UDC_CLASS_DIR);
    const QStringList listUdc = dirUdc.entryList(QDir::AllEntries | QDir::NoDotAndDotDot);
    for(const QString &strUdc : listUdc)
    {
        QString strPath = dirUdc.absoluteFilePath(strUdc) + "/" + USB_LUN_FILE;
        if(QFileInfo::exists(strPath))
            return strPath;
    }
    return QString();
}

bool PhantomRelease::isFactoryTestInstalled()
{
    return QFileInfo::exists(factoryTestDir() + "/" + FT_DEVMODE);
}

bool PhantomRelease::switchToFactoryTest(bool bNoReboot, QString *strErr)
{
    QStringList listArgs("factorytest");
    if(bNoReboot)
        listArgs << "--no-reboot";

    return runDevmode(listArgs, FT_SWITCH_TIMEOUT_MS, strErr) == 0;
}

bool PhantomRelease::purgeFactoryTest(QString *strErr)
{
    QString strDir = factoryTestDir();

    //devmode.sh 가 없으면 이미 지워진 것 — 부르지 않고 남은 것만 본다 (factorytest 회신 2026-10-26)
    if(QFileInfo::exists(strDir + "/" + FT_DEVMODE))
    {
        if(runDevmode(QStringList("purge"), FT_PURGE_TIMEOUT_MS, strErr) != 0)
            return false;
    }

    //성공 = 바이너리·유닛이 없음 (이미 없으면 OK)
    if(QFileInfo::exists(strDir + "/" + FT_BINARY) || QFileInfo::exists(factoryTestUnit()))
    {
        *strErr = "factoryTest left";
        return false;
    }
    return true;
}

bool PhantomRelease::returnWithPhantomNormal()
{
    return FT_RETURN_PHANTOM_NORMAL;
}

int PhantomRelease::runDevmode(const QStringList &listArgs, int nTimeoutMs, QString *strErr)
{
    //셸 문자열을 조합하지 않고 sh + 고정 인자로 부른다 (실행 비트 불필요)
    QString strScript = factoryTestDir() + "/" + FT_DEVMODE;
    QProcess process;
    process.start("/bin/sh", QStringList(strScript) << listArgs);

    if(!process.waitForStarted(3000))
    {
        *strErr = "devmode start fail";
        return -1;
    }

    if(!process.waitForFinished(nTimeoutMs))
    {
        process.kill();
        process.waitForFinished(1000);
        *strErr = "devmode timeout";
        return -1;
    }

    QString strStderr = QString::fromUtf8(process.readAllStandardError()).trimmed();
    int nExit = (process.exitStatus() == QProcess::NormalExit) ? process.exitCode() : -1;
    qDebug()<<"devmode"<<listArgs<<"exit"<<nExit<<strStderr;

    //실패 까닭은 devmode.sh 가 stderr 한 줄로 낸다
    if(nExit != 0)
        *strErr = strStderr.isEmpty() ? QString("devmode exit %1").arg(nExit) : strStderr.section('\n', -1).left(60);
    return nExit;
}

QString PhantomRelease::factoryTestDir()
{
    if(qEnvironmentVariableIsSet(FT_DIR_ENV))
        return QString::fromLocal8Bit(qgetenv(FT_DIR_ENV));
    return FT_DIR_DEFAULT;
}

QString PhantomRelease::factoryTestUnit()
{
    if(qEnvironmentVariableIsSet(FT_UNIT_ENV))
        return QString::fromLocal8Bit(qgetenv(FT_UNIT_ENV));
    return FT_UNIT_DEFAULT;
}
