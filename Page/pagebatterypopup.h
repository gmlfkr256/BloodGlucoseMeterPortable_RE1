#ifndef PAGEBATTERYPOPUP_H
#define PAGEBATTERYPOPUP_H

#include "page.h"

class PageBatteryPopup : public Page
{
    Q_OBJECT
public:
    PageBatteryPopup(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageBatteryPopup";

    QLabel* labelImg;
    QLabel* labelText;
    QLabel* labelTextSub;

    QTimer* timerPopup;

    CustomButtonOK* customButtonOK;

    int nBatterySleepCount = 0;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
    void updateTimer();
signals:
    //void signalShowPageNum(PageNum pageNum);
};

#endif // PAGEBATTERYPOPUP_H
