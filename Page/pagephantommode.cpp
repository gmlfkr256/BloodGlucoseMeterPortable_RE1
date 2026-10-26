#include "pagephantommode.h"
#include "qrcodeimage.h"

namespace {
//hrkim 20261026 팬텀 화면 문구·시간 — 테스트 때 Hr 확인 후 바꿀 자리 (팬텀 화면은 영문 표기, 다국어 미적용) (XW-0446, XW-0453)
const char *TXT_FACTORY_TEST        = "FACTORY TEST";
const char *TXT_FACTORY_TEST_AGAIN  = "TOUCH AGAIN\nTO REBOOT";
const char *TXT_FACTORY_TEST_FAIL   = "FACTORY TEST FAIL";
const char *TXT_USB_CONNECT         = "USB CONNECT";
const char *TXT_USB_DISCONNECT      = "USB DISCONNECT";
const char *TXT_USB_CONNECTED       = "USB CONNECTED\nEJECT ON PC";
const char *TXT_USB_RELEASED        = "USB RELEASED";
const char *TXT_WORKING             = "WORKING...";
const char *TXT_REBOOTING           = "REBOOTING...";
const char *TXT_SAVE_TO_FINISH      = "SAVE TO FINISH";
const char *TXT_SAVE_TO_RETRY       = "SAVE TO RETRY";
const char *TXT_USB_TO_RETRY        = "CANCEL, THEN\nUSB CONNECT";

const int FT_CONFIRM_MS       = 5000;   // [FACTORY TEST] 두 번째 누름 대기
const int USB_POLL_MS         = 500;    // PC 꺼냄 감지 주기
const int USB_DETACH_POLLS    = 4;      // PC 가 잡았다가 놓은 상태가 이만큼(2초) 이어지면 해제 — 잠깐 끊김에 흔들리지 않게
const int REBOOT_FALLBACK_MS  = 10000;  // 재부팅이 안 오면 직접 (M4 명령 실패 대비)

QString resultTitle(int nResult)
{
    switch(nResult)
    {
    case PhantomRelease::RESULT_OK:       return "RELEASE OK";
    case PhantomRelease::RESULT_SN_FAIL:  return "SERIAL WRITE FAIL";
    case PhantomRelease::RESULT_DEL_FAIL: return "LABEL DELETE FAIL";
    case PhantomRelease::RESULT_NO_SHIP:  return "NO SHIP SERIAL";
    case PhantomRelease::RESULT_FT_FAIL:  return "FACTORY TEST\nDELETE FAIL";
    default:                              return "FAIL";
    }
}
}

PagePhantomMode::PagePhantomMode(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    this->setStyleSheet("background-color: black;");
    init();
}

void PagePhantomMode::init()
{
    labelBg = new QLabel(this);
    labelBg->setGeometry(0,0,640,480);
    labelBg->setStyleSheet("background-color: black;");

    QFont font = QFont(instance.fontSuit,32,QFont::Bold);
    QFont fontButton = QFont(instance.fontSuit,22,QFont::Bold);

    labelTitle = new QLabel(this);
    labelTitle->setGeometry(0,20,640,50);
    labelTitle->setStyleSheet("color: white;");
    labelTitle->setFont(font);
    labelTitle->setAlignment(Qt::AlignCenter);
    labelTitle->setText("PHANTOM");

    labelPhantomButton = new QLabel(this);
    labelPhantomButton->setGeometry(350,100,250,250);
    labelPhantomButton->setFont(font);
    labelPhantomButton->setAlignment(Qt::AlignCenter);
    labelPhantomButton->setStyleSheet("background-color: blue; color: white;");

    //hrkim 20261026 왼쪽 'Phantom:' 글자 자리에 [FACTORY TEST](왼쪽 위) · [USB CONNECT] (XW-0453, XW-0446)
    labelFactoryTest = new QLabel(this);
    labelFactoryTest->setGeometry(30,90,290,70);
    labelFactoryTest->setFont(fontButton);
    labelFactoryTest->setAlignment(Qt::AlignCenter);

    labelUsb = new QLabel(this);
    labelUsb->setGeometry(30,175,290,70);
    labelUsb->setFont(fontButton);
    labelUsb->setAlignment(Qt::AlignCenter);

    labelDlabelResult = new QLabel(this);
    labelDlabelResult->setGeometry(10,255,330,125);
    labelDlabelResult->setStyleSheet("color: white;");
    labelDlabelResult->setFont(QFont(instance.fontSuit,20,QFont::Bold));
    labelDlabelResult->setAlignment(Qt::AlignCenter);
    labelDlabelResult->setWordWrap(true);

    //hrkim 20261026 결과 화면: 왼쪽 큰 QR(스캔 확인 6px 이상 — 영숫자 v3 이면 8px), 오른쪽 결과 글자 (XW-0446)
    labelResultCode = new QLabel(this);
    labelResultCode->setGeometry(20,80,300,300);
    labelResultCode->setStyleSheet("color: white;");
    labelResultCode->setFont(QFont(instance.fontSuit,20,QFont::Bold));
    labelResultCode->setAlignment(Qt::AlignCenter);

    labelResultText = new QLabel(this);
    labelResultText->setGeometry(330,80,300,300);
    labelResultText->setStyleSheet("color: white;");
    labelResultText->setFont(QFont(instance.fontSuit,17,QFont::Bold));
    labelResultText->setAlignment(Qt::AlignCenter);
    labelResultText->setWordWrap(true);

    customButtonSave = new CustomButtonSave(this);
    customButtonCancel = new CustomButtonCancel(this);

    timerUsb = new QTimer(this);
    connect(timerUsb, &QTimer::timeout, this, &PagePhantomMode::checkUsb);

    timerFtConfirm = new QTimer(this);
    timerFtConfirm->setSingleShot(true);
    connect(timerFtConfirm, &QTimer::timeout, this, [this](){
        bFtConfirm = false;
        updateView();
    });

    timerReboot = new QTimer(this);
    timerReboot->setSingleShot(true);
    connect(timerReboot, &QTimer::timeout, this, [this](){
        qDebug()<<"factory test: no reboot, reboot directly";
#if DEVICE
        instance.guiApi.glucoseActReboot();
#endif
    });

    update();
}

void PagePhantomMode::update()
{
    if(nPhantomMode == GAPI_PHANTOM_MODE_MASS_PRODUCT)
    {
        labelPhantomButton->setText("MASS");
        labelPhantomButton->setStyleSheet("background-color: red; color: white;");
    }
    else if(nPhantomMode == GAPI_PHANTOM_MODE_QUALITY)
    {
        labelPhantomButton->setText("QUALITY");
        labelPhantomButton->setStyleSheet("background-color: green; color: white;");
    }
    else
    {
        labelPhantomButton->setText("OFF");
        labelPhantomButton->setStyleSheet("background-color: white; color: black;");
    }

    updateView();
}

//hrkim 20261026 화면 상태별 보이기 (XW-0446, XW-0453)
void PagePhantomMode::updateView()
{
    bool bIdle = (nView == VIEW_IDLE);
    bool bResult = (nView == VIEW_RESULT);

    labelPhantomButton->setVisible(bIdle);
    labelFactoryTest->setVisible(bIdle && bFtInstalled);
    labelUsb->setVisible(bIdle || nView == VIEW_USB);
    labelDlabelResult->setVisible(!bResult);
    labelResultCode->setVisible(bResult);
    labelResultText->setVisible(bResult);
    customButtonSave->setVisible(bIdle || bResult);
    customButtonCancel->setVisible(bIdle || bResult);

    labelFactoryTest->setText(bFtConfirm ? TXT_FACTORY_TEST_AGAIN : TXT_FACTORY_TEST);
    labelFactoryTest->setStyleSheet(bFtConfirm ? "background-color: orange; color: black;"
                                               : "background-color: #616161; color: white;");

    if(nView == VIEW_USB)
    {
        labelUsb->setText(TXT_USB_DISCONNECT);
        labelUsb->setStyleSheet("background-color: red; color: white;");
    }
    else
    {
        labelUsb->setText(TXT_USB_CONNECT);
        labelUsb->setStyleSheet("background-color: blue; color: white;");
    }
}

void PagePhantomMode::showMessage(const QString &strText, bool bError)
{
    labelDlabelResult->setStyleSheet(bError ? "color: red;" : "color: white;");
    labelDlabelResult->setText(strText);
    labelDlabelResult->repaint();   //오래 걸리는 동작 앞에서 바로 보이게
}

//hrkim 20261026 해제 결과 화면: 결과 코드 QR(PC 스캐너로 찍음) + 글자 (XW-0446)
void PagePhantomMode::showResult(int nResult)
{
    nView = VIEW_RESULT;
    updateView();

    setQrCode(labelResultCode, PhantomRelease::resultCode(nResult, releaseState));

    QString strNext;
    if(nResult == PhantomRelease::RESULT_OK)
        strNext = TXT_SAVE_TO_FINISH;
    else if(nResult == PhantomRelease::RESULT_NO_SHIP)
        strNext = TXT_USB_TO_RETRY;
    else
        strNext = TXT_SAVE_TO_RETRY;

    labelResultText->setStyleSheet(nResult == PhantomRelease::RESULT_OK ? "color: white;" : "color: red;");
    labelResultText->setText(QString("%1\n\nSHIP\n%2\nPROD\n%3\n\n%4")
                             .arg(resultTitle(nResult),
                                  releaseState.strReadback.isEmpty() ? "-" : releaseState.strReadback,
                                  releaseState.strProdSerial.isEmpty() ? "-" : releaseState.strProdSerial,
                                  strNext));
}

//hrkim 20261026 결과 코드 QR — 그리기는 qrCodePixmap(공용)으로 (XW-0446)
void PagePhantomMode::setQrCode(QLabel *label, const QString &strCode)
{
    int nVersion = 0, nScale = 0;
    QPixmap pixmap = qrCodePixmap(strCode, label->width(), &nVersion, &nScale);
    if(pixmap.isNull())
    {
        label->setText("QR ERROR");
        return;
    }

    label->setPixmap(pixmap);
    qDebug()<<"result code:"<<strCode<<"QR v"<<nVersion<<"scale"<<nScale;
}

void PagePhantomMode::pageShow()
{
    nPhantomMode = instance.nPhantomMode;
    bWaitConfirm = false;
    bFtConfirm = false;
    bFtInstalled = PhantomRelease::isFactoryTestInstalled();
    labelDlabelResult->clear();

    //hrkim 20261026 USB 를 못 거둔 채(가젯이 남았거나 p6 가 안 붙음) 돌아왔으면 USB 화면부터 — [USB DISCONNECT] 로 다시 붙임 (XW-0446)
    if(PhantomRelease::usbMediaState() != PhantomRelease::USB_MEDIA_NONE || instance.getVdataMountPath().isEmpty())
    {
        nView = VIEW_USB;
        showMessage(TXT_USB_CONNECTED);
        bUsbSeenConfigured = false;
        nUsbDetachCount = 0;
        timerUsb->start(USB_POLL_MS);
    }
    else
        nView = VIEW_IDLE;

    update();
}

void PagePhantomMode::pageHide()
{
    emit signalShowPageNum(PAGE_MENU);
}

//hrkim 20261026 [USB CONNECT]: p6 를 PC 에 이동식 디스크로 — 이전 해제 시도는 버림(PC 가 새로 씀) (XW-0446)
void PagePhantomMode::startUsb()
{
    showMessage(TXT_WORKING);
    releaseState = PhantomRelease::State();

    QString strErr;
    if(!PhantomRelease::usbStart(&strErr))
    {
        showMessage(strErr, true);
        return;
    }

    nView = VIEW_USB;
    updateView();
    showMessage(TXT_USB_CONNECTED);
    bUsbSeenConfigured = false;
    nUsbDetachCount = 0;
    timerUsb->start(USB_POLL_MS);
}

//hrkim 20261026 PC 가 꺼냈거나 [USB DISCONNECT]: 가젯 내리기 → p6 다시 붙이기 (XW-0446)
void PagePhantomMode::stopUsb()
{
    timerUsb->stop();

    QString strErr;
    if(!PhantomRelease::usbStop(&strErr))
    {
        //다시 붙이기 실패 — USB 화면에 남아 [USB DISCONNECT] 로 다시
        nView = VIEW_USB;
        updateView();
        showMessage(strErr, true);
        return;
    }

    nView = VIEW_IDLE;
    updateView();
    showMessage(TXT_USB_RELEASED);
}

void PagePhantomMode::checkUsb()
{
    //PC 작업 중 자동 꺼짐 막음
    instance.nSleepTimeCount = 0;

    //다른 화면(배터리 알림 등)으로 넘어가면 측정·소리가 p6 를 쓰므로 바로 되붙임
    if(!isVisible())
    {
        qDebug()<<"usb: page left, release";
        stopUsb();
        return;
    }

    //PC 가 꺼내기(eject) 명령을 보냄 → 자동 해제
    if(PhantomRelease::usbMediaState() != PhantomRelease::USB_MEDIA_LOADED)
    {
        stopUsb();
        return;
    }

    //PC 가 power-off(udisksctl — eject 명령 없이 포트만 끔)하거나 케이블을 뽑음 → 잡았다가 놓은 지 2초면 자동 해제 (실기 2026-10-26)
    if(PhantomRelease::usbHostConfigured())
    {
        bUsbSeenConfigured = true;
        nUsbDetachCount = 0;
    }
    else if(bUsbSeenConfigured && ++nUsbDetachCount >= USB_DETACH_POLLS)
    {
        qDebug()<<"usb: PC released (not configured)";
        stopUsb();
    }
}

//hrkim 20261026 [FACTORY TEST] 두 번째 누름: devmode.sh factorytest → 재부팅 (XW-0453, D-61)
void PagePhantomMode::goFactoryTest()
{
    nView = VIEW_REBOOT;
    updateView();
    showMessage(TXT_REBOOTING);

    bool bPhantomNormal = PhantomRelease::returnWithPhantomNormal();
    QString strErr;
    if(!PhantomRelease::switchToFactoryTest(bPhantomNormal, &strErr))
    {
        nView = VIEW_IDLE;
        updateView();
        showMessage(QString("%1\n%2").arg(TXT_FACTORY_TEST_FAIL, strErr), true);
        return;
    }

#if DEVICE
    if(bPhantomNormal)
    {
        //팬텀 값만 되돌림 — OFF 저장(해제 절차·메뉴 숨김)과 다른 길: 공정 테스트 앱이 지워지면 안 됨. SET 직후 sysmgr 재부팅
        instance.nPhantomMode = GAPI_PHANTOM_MODE_NORMAL;
        instance.guiApi.glucoseSetPhantomUsage(GAPI_PHANTOM_MODE_NORMAL);
    }
#endif
    timerReboot->start(REBOOT_FALLBACK_MS);
}

void PagePhantomMode::mousePressEvent(QMouseEvent *ev)
{
    //hrkim 20261026 재부팅 대기 중에는 입력 막음 (XW-0453)
    if(nView == VIEW_REBOOT)
        return;

    //hrkim 20261026 USB 연결 중에는 [USB DISCONNECT] 만 — p6 가 PC 에 열려 있어 저장·취소·모드 변경 막음 (XW-0446)
    if(nView == VIEW_USB)
    {
        if(instance.touchCheck(labelUsb->geometry(),ev))
            stopUsb();
        return;
    }

    //hrkim 20261026 [FACTORY TEST] 두 번 눌러야 (오조작 방지), 다른 곳을 누르면 취소 (XW-0453)
    if(nView == VIEW_IDLE && bFtInstalled && instance.touchCheck(labelFactoryTest->geometry(),ev))
    {
        if(!bFtConfirm)
        {
            bFtConfirm = true;
            updateView();
            timerFtConfirm->start(FT_CONFIRM_MS);
            return;
        }

        timerFtConfirm->stop();
        bFtConfirm = false;
        goFactoryTest();
        return;
    }
    if(bFtConfirm)
    {
        timerFtConfirm->stop();
        bFtConfirm = false;
        updateView();
    }

    if(instance.touchCheck(customButtonSave->geometry(),ev))
    {
        //hrkim 20260909 MASS/QUALITY → OFF 저장 = 테스트 종료: 팬텀 메뉴 숨김 (히든 토글로만 재노출)
        bool bTestEnd = (instance.nPhantomMode != GAPI_PHANTOM_MODE_NORMAL
                         && nPhantomMode == GAPI_PHANTOM_MODE_NORMAL);

        //hrkim 20261026 테스트 종료(팬텀 해제) = 출하 시리얼 기록·라벨 삭제·공정 테스트 앱 삭제를 SET(직후 재부팅) 앞에 → 결과 코드 → SAVE 한 번 더 눌러야 SET (XW-0446 A안)
        //실패면 SET 막음 (D-54·D-61) — SAVE 다시 누르면 끝난 단계는 건너뛰고 이어서
        if(bTestEnd && !bWaitConfirm)
        {
            if(nView == VIEW_RESULT)
            {
                labelResultText->setStyleSheet("color: white;");
                labelResultText->setText(TXT_WORKING);
                labelResultText->repaint();
            }
            else
                showMessage(TXT_WORKING);

            int nResult = PhantomRelease::runRelease(releaseState);

            //hrkim 20261026 결과 코드 QR 단계는 설정으로 뺄 수 있게 — 끄면 OK 일 때 아래 SET 으로 바로 (실패는 늘 결과 화면) (XW-0446, Hr "모듈화")
            if(nResult != PhantomRelease::RESULT_OK || PhantomRelease::resultConfirmStep())
            {
                showResult(nResult);
                bWaitConfirm = (nResult == PhantomRelease::RESULT_OK);
                return;
            }
        }

        //hrkim 20261021 메뉴 숨김 플래그를 SET 앞에 저장 (SET 직후 재부팅으로 유실 방지, XW-0416)
        if(bTestEnd)
            instance.savePhantomMenuShow(false);

        instance.nPhantomMode = nPhantomMode;
#if DEVICE
        instance.guiApi.glucoseSetPhantomUsage(nPhantomMode);
        instance.getCaliGainCompleteCheck();
#endif
        pageHide();
        return;
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        //hrkim 20261026 결과 화면의 취소는 기본 화면으로 (NO-SHIP 이면 여기서 [USB CONNECT] 부터 다시) — 끝난 단계는 그대로 둠 (XW-0446)
        if(nView == VIEW_RESULT)
        {
            nView = VIEW_IDLE;
            bWaitConfirm = false;
            labelDlabelResult->clear();
            updateView();
            return;
        }

        pageHide();
        return;
    }

    //hrkim 20261021 라벨 삭제 후 확인 대기 중에는 모드 변경 막음 (XW-0416)
    if(nView == VIEW_IDLE && !bWaitConfirm && instance.touchCheck(labelPhantomButton->geometry(),ev))
    {
        nPhantomMode = (nPhantomMode + 1) % GAPI_PHANTOM_MODE_END;
        labelDlabelResult->clear();
        update();
        return;
    }

    //hrkim 20261026 [USB CONNECT] (XW-0446)
    if(nView == VIEW_IDLE && instance.touchCheck(labelUsb->geometry(),ev))
        startUsb();
}
