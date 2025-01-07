#ifndef PAGETRANS_H
#define PAGETRANS_H

#include "page.h"

class PageTrans : public Page
{
    Q_OBJECT
public:
    PageTrans(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageTrans";

    int selectedIndex = 0;
    QMap<int, QFont> fontMap;

    QLabel *labelWindow;
    QLabel *labelButton[3];
    QLabel *labelButtonCheck;
    QLabel *labelArrowTop;
    QLabel *labelArrowDown;
    QLabel *labelButtonGradientTop;
    QLabel *labelButtonGradientDown;

    DeviceLanguage deviceLan = KR;
    CustomButtonOK *customButtonOK;
    CustomButtonCancel *customButtonCancel;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
    void updateButton();
    void fontMapping();

signals:
    void signalShowPageNum(PageNum pageNum);
};

#endif // PAGETRANS_H
