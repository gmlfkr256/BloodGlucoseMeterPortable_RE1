#ifndef PHANTOMRELEASE_H
#define PHANTOMRELEASE_H

#include <QString>
#include <QStringList>

//hrkim 20261026 팬텀 해제(출하) 절차 · USB 연결 · 공정 테스트 앱 전환 — 화면(PagePhantomMode)과 분리한 동작 모음 (XW-0446 A안, XW-0453)
// 바꿀 일이 생기면 phantomrelease.cpp 맨 위 "설정" 블록만 보면 되게 경로·규칙·결과 코드를 한곳에 모았다.
// 스펙 원본: mes 저장소 docs/MES-디지털-라벨-설계.md §7-2(D-54·D-55) · §8(D-61)

class PhantomRelease
{
public:
    // 결과 코드 (QR 의 두 번째 칸)
    enum Result
    {
        RESULT_OK = 0,      // 기록·삭제·공정 테스트 앱 삭제 모두 끝 → 확인 터치로 SET
        RESULT_SN_FAIL,     // 출하 시리얼 기록 후 되읽은 값이 다름 → [팬텀 해제]만 다시
        RESULT_DEL_FAIL,    // 디지털 라벨(mes-dlabel) 삭제 실패 → [팬텀 해제]만 다시
        RESULT_NO_SHIP,     // ship_serial 없음·비었음·형식 틀림 (p6 안 붙음 포함) → [USB 연결]부터 다시
        RESULT_FT_FAIL      // 공정 테스트 앱 삭제(purge) 실패 → [팬텀 해제]만 다시
    };

    // 한 번의 해제 시도에서 끝난 단계 — 다시 누르면 끝난 단계는 건너뛴다
    // (예: 라벨 삭제 뒤 FT-FAIL 이면 ship_serial 이 이미 지워졌으므로 다시 읽지 않고 purge 만 다시)
    struct State
    {
        QString strProdSerial;  // mes-dlabel/prod_serial (QR 네 번째 칸)
        QString strShipSerial;  // mes-dlabel/ship_serial
        QString strReadback;    // SN_SET 뒤 vdata/serial_num 되읽은 값 (QR 세 번째 칸)
        bool bSnDone = false;
        bool bDelDone = false;
        bool bFtDone = false;
    };

    // 팬텀 해제: 남은 단계를 순서대로 (ship_serial 읽기 → SN_SET·되읽기·sync → mes-dlabel 삭제 → purge)
    static int runRelease(State &state);
    // 결과 코드 문자열: MESDL1:<결과>:<되읽은 출하 시리얼>:<생산 시리얼> (값이 없으면 빈칸)
    static QString resultCode(int nResult, const State &state);
    static QString resultName(int nResult);

    // [USB 연결]: p6 를 PC 에 이동식 디스크로 (guiapi glucoseSetGdataStorage) + 실제로 내줬는지 확인
    enum UsbMedia
    {
        USB_MEDIA_NONE = 0,     // 저장장치 가젯 없음
        USB_MEDIA_LOADED,       // PC 에 디스크로 열려 있음
        USB_MEDIA_EJECTED       // PC 가 꺼냄(안전 제거) — 가젯이 매체를 놓음
    };
    static bool usbStart(QString *strErr);
    static bool usbStop(QString *strErr);
    static int usbMediaState();
    static bool usbHostConfigured();    // PC 가 디스크로 잡고 있음 (UDC state "configured") — power-off·케이블 뽑기 감지용

    // 공정 테스트 앱 (공통 모듈 devmode.sh — 공정 테스트 앱 설치가 앱 폴더에 둔다)
    static bool isFactoryTestInstalled();
    static bool switchToFactoryTest(bool bNoReboot, QString *strErr);   // devmode.sh factorytest [--no-reboot]
    static bool purgeFactoryTest(QString *strErr);                      // devmode.sh purge + 남은 것 없는지 확인

    // 설정값 (화면에서도 쓰는 것)
    static bool returnWithPhantomNormal();  // [FACTORY TEST] 때 팬텀 값을 NORMAL 로 되돌릴지 (D-61 4번 결정 대기)

private:
    static QString readFirstLine(const QString &strPath);
    static bool isValidShipSerial(const QString &strSerial);
    static bool writeShipSerial(const QString &strBase, const QString &strSerial, QString *strReadback);
    static int runDevmode(const QStringList &listArgs, int nTimeoutMs, QString *strErr);
    static QString factoryTestDir();
    static QString factoryTestUnit();
    static QString usbLunFilePath();
    static QString usbUdcPath();
};

#endif // PHANTOMRELEASE_H
