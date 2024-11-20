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

    gapiBatData_t batData;
    gapiBatData_t batDataPrev;

    QString strDirPath = "/ImageComBattery";
    QString pngPathPrev;

    QList<int> listBatterySize;

    void init();
public slots:
    void update() override;
    void updateUI();
    void pageShow() override;
    void pageHide() override;
};

#endif // COMPONENTBATTERY_H
