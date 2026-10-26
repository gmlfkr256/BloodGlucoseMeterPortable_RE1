#ifndef PAGEPHANTOMMODE_H
#define PAGEPHANTOMMODE_H

#include "page.h"
#include "phantomrelease.h"

//hrkim 20260909 팬텀 메뉴(메뉴 화면)에서 진입하는 팬텀 모드 설정 페이지
class PagePhantomMode : public Page
{
    Q_OBJECT
public:
    PagePhantomMode(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    //hrkim 20261026 화면 상태 (XW-0446 A안, XW-0453)
    enum ViewState
    {
        VIEW_IDLE = 0,  // 모드 선택 · [FACTORY TEST] · [USB CONNECT]
        VIEW_USB,       // p6 가 PC 에 열려 있음 — [USB DISCONNECT] 만 받음
        VIEW_RESULT,    // 해제 결과 + 결과 코드 QR
        VIEW_REBOOT     // 공정 테스트 앱으로 재부팅 대기 — 입력 막음
    };

    QLabel *labelBg;
    QLabel *labelTitle;
    QLabel *labelPhantomButton;
    QLabel *labelDlabelResult;  //hrkim 20261021 디지털 라벨 삭제 결과 표시 (XW-0416) → 20261026 USB·전환 안내 겸용
    QLabel *labelFactoryTest;   //hrkim 20261026 [FACTORY TEST] — 공정 테스트 앱이 깔려 있을 때만 (XW-0453)
    QLabel *labelUsb;           //hrkim 20261026 [USB CONNECT]/[USB DISCONNECT] (XW-0446)
    QLabel *labelResultCode;    //hrkim 20261026 결과 코드 QR (XW-0446)
    QLabel *labelResultText;    //hrkim 20261026 결과 글자 (XW-0446)
    CustomButtonSave *customButtonSave;
    CustomButtonCancel *customButtonCancel;

    int nPhantomMode = GAPI_PHANTOM_MODE_NORMAL;
    bool bWaitConfirm = false;  //hrkim 20261021 라벨 삭제 후 SAVE 한 번 더 눌러야 SET (XW-0416) → 20261026 해제 결과 OK 뒤 확인 대기

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
    void updateView();
    void showMessage(const QString &strText, bool bError = false);
    void showResult(int nResult);
    void setQrCode(QLabel *label, const QString &strCode);
    void startUsb();
    void stopUsb();
    void checkUsb();
    void goFactoryTest();

    int nView = VIEW_IDLE;
    bool bFtConfirm = false;                    // [FACTORY TEST] 첫 번째 누름 뒤 두 번째 대기
    bool bFtInstalled = false;
    PhantomRelease::State releaseState;         // 해제 시도에서 끝난 단계 (다시 누르면 이어서)
    bool bUsbSeenConfigured = false;            // 이번 USB 연결에서 PC 가 디스크로 잡은 적 있음
    int nUsbDetachCount = 0;                    // PC 가 놓은 뒤 이어진 감시 횟수
    QTimer *timerUsb;
    QTimer *timerFtConfirm;
    QTimer *timerReboot;

signals:
};

#endif // PAGEPHANTOMMODE_H
