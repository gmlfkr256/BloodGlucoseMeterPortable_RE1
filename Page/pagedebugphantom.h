#ifndef PAGEDEBUGPHANTOM_H
#define PAGEDEBUGPHANTOM_H

#include "page.h"

class PageDebugPhantom : public Page
{
    Q_OBJECT
public:
    PageDebugPhantom(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QLabel *labelBg;
    QLabel *labelTitle;
    QLabel *labelModeInfo;
    QLabel *labelPhantomText;
    QLabel *labelPhantomButton;
    CustomButtonSave *customButtonSave;
    CustomButtonCancel *customButtonCancel;

    bool bMenuShow = true;  //hrkim 20260909 팬텀 메뉴 노출 토글 (모드 설정은 PagePhantomMode로 이동)

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:
};

#endif // PAGEDEBUGPHANTOM_H
