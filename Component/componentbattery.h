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
    int nBatterySize = 0;

    bool bIsBatteryAlert15 = false;
    bool bIsBatteryAlert5 = false;
    int nBatteyTimer15 = 0;
    int nBatteyTimer5 = 0;

    gapiBatData_t batData;

    QString strDirPath = "/ImageComBattery";

    // Sliding window median filter
    static const int WINDOW_SIZE = 12;
    static const int MIN_SAMPLES = 3;
    int batteryWindow[WINDOW_SIZE];
    int windowCount;
    int windowIndex;
    int nCurrentIconLevel;
    int nFilteredBattery;

    int getFilteredBattery() const;
    int selectIconLevel(int batteryValue);

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
