#ifndef PAGESLEEP_H
#define PAGESLEEP_H

#include "page.h"

class PageSleep : public Page
{
    Q_OBJECT
public:
    PageSleep(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageSleep";

    QLabel *labelButton[6];
    QLabel *labelText[6];

    SleepIndex sleepIndex = SLEEP_30S;
    CustomButtonSave *customButtonSave;
    CustomButtonCancel *customButtonCancel;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:
    void signalShowPageNum(PageNum pageNum);
};

#endif // PAGESLEEP_H
