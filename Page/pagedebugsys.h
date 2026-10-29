#ifndef PAGEDEBUGSYS_H
#define PAGEDEBUGSYS_H

#include "page.h"

class PageDebugSys : public Page
{
    Q_OBJECT
public:
    PageDebugSys(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    bool bIsGetSysData = false;

    QLabel *labelBg;
    QLabel *labelTitle;
    QLabel *labelModeText;
    QLabel *labelModeButton[3];    //hrkim 20261029 회전 버튼 1개 → 모드별 버튼 3개 (인덱스 = opr_mode 0 Normal, 1 Test, 2 Self) (XW-0478)

    CustomButtonSave *customButtonSave;
    CustomButtonCancel *customButtonCancel;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
};

#endif // PAGEDEBUGSYS_H
