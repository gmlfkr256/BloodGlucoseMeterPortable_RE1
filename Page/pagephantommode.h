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
    CustomButtonSave *customButtonSave;
    CustomButtonCancel *customButtonCancel;

    int nPhantomMode = GAPI_PHANTOM_MODE_NORMAL;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:
};

#endif // PAGEPHANTOMMODE_H
