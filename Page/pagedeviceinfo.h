#ifndef PAGEDEVICEINFO_H
#define PAGEDEVICEINFO_H

#include "page.h"

class PageDeviceInfo : public Page
{
    Q_OBJECT
public:
    PageDeviceInfo(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageDeviceInfo";

    QLabel *labelLine[3];

    QLabel *labelDevBLEVerTitle;
    QLabel *labelDevBLEVerText;
    QLabel *labelDevHWVerTitle;
    QLabel *labelDevHWVerText;
    QLabel *labelDevSWVerTitle;
    QLabel *labelDevSWVerText;
    QLabel *labelDevSerialTitle;
    QLabel *labelDevSerialText;

    QList<QLabel*> listLabelTitle;
    QList<QLabel*> listLabelText;

    CustomButtonOK *customButtonOK;
    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:
    //void signalShowPageNum(PageNum pageNum);
};

#endif // PAGEDEVICEINFO_H
