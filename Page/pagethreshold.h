#ifndef PAGETHRESHOLD_H
#define PAGETHRESHOLD_H

#include "page.h"

class PageThreshold : public Page
{
    Q_OBJECT
public:
    PageThreshold(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageThreshold";

    QLabel *labelTextLow;
    QLabel *labelTextHigh;

    QLabel *labelButtonLow;
    QLabel *labelButtonHigh;

    QLabel *labelValueLow;
    QLabel *labelValueHigh;

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

#endif // PAGETHRESHOLD_H
