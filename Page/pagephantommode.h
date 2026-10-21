#ifndef PAGEPHANTOMMODE_H
#define PAGEPHANTOMMODE_H

#include "page.h"

//hrkim 20260909 팬텀 메뉴(메뉴 화면)에서 진입하는 팬텀 모드 설정 페이지
class PagePhantomMode : public Page
{
    Q_OBJECT
public:
    PagePhantomMode(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QLabel *labelBg;
    QLabel *labelTitle;
    QLabel *labelPhantomText;
    QLabel *labelPhantomButton;
    QLabel *labelDlabelResult;  //hrkim 20261021 디지털 라벨 삭제 결과 표시 (XW-0416)
    CustomButtonSave *customButtonSave;
    CustomButtonCancel *customButtonCancel;

    int nPhantomMode = GAPI_PHANTOM_MODE_NORMAL;
    bool bWaitConfirm = false;  //hrkim 20261021 라벨 삭제 후 SAVE 한 번 더 눌러야 SET (XW-0416)

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:
};

#endif // PAGEPHANTOMMODE_H
