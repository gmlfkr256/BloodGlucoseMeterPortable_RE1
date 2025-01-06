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

    CustomButtonOK* customButtonOK;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
signals:
    void signalShowPageNum(PageNum pageNum);
};

#endif // PAGEBATTERYPOPUP_H
