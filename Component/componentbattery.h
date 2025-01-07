#ifndef COMPONENTBATTERY_H
#define COMPONENTBATTERY_H

#include "customcomponent.h"

class ComponentBattery : public CustomComponent
{
    Q_OBJECT
public:
    ComponentBattery(QWidget* parent);

private:
    QLabel *labelBattery;
    QTimer *timerBattery;
    bool bIsBatteryFirstCheck = true;
    int nBatterySize = 0;
    int nBatteryCount = 0;

    bool bIsBatteryAlert15 = false;
    bool bIsBatteryAlert5 = false;
    int nBatteyTimer15 = 0;
    int nBatteyTimer5 = 0;

    gapiBatData_t batData;

    QString strDirPath = "/ImageComBattery";
    QString pngPathPrev;

    QList<int> listBatterySize;

    void init();
public slots:
    void update() override;
    void updateUI();
    void pageShow() override;
    void pageHide() override;

signals:
    void signalShowPageNum(PageNum pageNum);
};

#endif // COMPONENTBATTERY_H
