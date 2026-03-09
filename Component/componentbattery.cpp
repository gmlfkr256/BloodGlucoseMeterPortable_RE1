#include "componentbattery.h"
#include <algorithm>

ComponentBattery::ComponentBattery(QWidget *parent) : CustomComponent(parent)
{
    this->setGeometry(563,22,50,30);
    init();
}

void ComponentBattery::init()
{
    labelBattery = new QLabel(this);
    labelBattery->setGeometry(0,0,this->width(),this->height());

    batData.charge = 100;
    nBatterySize = 100;

    // Empty window start — no prefill
    windowCount = 0;
    windowIndex = 0;
    nCurrentIconLevel = 100;
    nFilteredBattery = 100;

    timerBattery = new QTimer(this);
    connect(timerBattery,&QTimer::timeout,this,&ComponentBattery::update);
    QTimer::singleShot(1000, this, [this]() {
        update();
        timerBattery->start(5000);
    });
    updateUI();
}

void ComponentBattery::update()
{
#if DEVICE
    if(instance.getProcCheck() == true || instance.bIsDetachCtrlBat)
        return;

    if(instance.guiApi.glucoseGetBatData(&batData) == GAPI_SUCCESS)
    {

        DEBUG_BAT("batData.charge: "<<batData.charge<<", batData.Charging: "<<batData.charging);

        // Improvement 1: Input clamping
        nBatterySize = qBound(0, static_cast<int>(batData.charge), 100);
    }
    else
    {
        qDebug()<<"Battery Information Loading Failed";
        return;
    }
#else
    batData.charge = 100;
    //batData.charge = QRandomGenerator::global()->bounded(101);
    batData.charging = 0;//(QRandomGenerator::global()->bounded(2) == 1);
    nBatterySize = qBound(0, static_cast<int>(batData.charge), 100);
#endif

    // Improvement 2: Sliding window — add sample
    batteryWindow[windowIndex] = nBatterySize;
    windowIndex = (windowIndex + 1) % WINDOW_SIZE;
    if(windowCount < WINDOW_SIZE)
        windowCount++;

    // Improvement 3: Median filter
    nFilteredBattery = getFilteredBattery();

    DEBUG_BAT("filtered: "<<nFilteredBattery<<", windowCount: "<<windowCount);

    // Improvement 6: Alert logic uses filtered value
    if(batData.charging)
    {
        instance.isBatCharging = true;
        nBatteyTimer15 = 0;
        nBatteyTimer5 = 0;

        bIsBatteryAlert15 = false;
        bIsBatteryAlert5 = false;
    }
    else
    {
        instance.isBatCharging = false;
        if(nFilteredBattery <= 5)
        {
            nBatteyTimer15 = 0;
            nBatteyTimer5++;
        }
        else if(nFilteredBattery <= 15)
        {
            nBatteyTimer15++;
            nBatteyTimer5 = 0;
        }
        else
        {
            nBatteyTimer15 = 0;
            nBatteyTimer5 = 0;
        }

        if(nBatteyTimer15 >= 6 && !bIsBatteryAlert15)
        {
            bIsBatteryAlert15 = true;

            if(nFilteredBattery > 5)
            {
                instance.isBatZero = false;
                emit signalShowPageNum(PAGE_BATPOPUP);
            }
        }

        if(nBatteyTimer5 >= 6 && !bIsBatteryAlert5)
        {
            bIsBatteryAlert5 = true;

            instance.isBatZero = true;
            emit signalShowPageNum(PAGE_BATPOPUP);
        }
    }

    updateUI();
}

// Improvement 3: Median filter — robust against outliers
int ComponentBattery::getFilteredBattery() const
{
    if(windowCount == 0)
        return 100;

    int sorted[WINDOW_SIZE];
    for(int i = 0; i < windowCount; i++)
        sorted[i] = batteryWindow[i];

    std::sort(sorted, sorted + windowCount);

    if(windowCount % 2 == 1)
        return sorted[windowCount / 2];
    else
        return (sorted[windowCount / 2 - 1] + sorted[windowCount / 2]) / 2;
}

// Improvement 4: Hysteresis icon selection (±3%)
int ComponentBattery::selectIconLevel(int batteryValue)
{
    // Thresholds: 90/60/30/10 for descending, +3 for ascending
    if(nCurrentIconLevel == 100)
    {
        if(batteryValue < 90) return 75;
        return 100;
    }
    else if(nCurrentIconLevel == 75)
    {
        if(batteryValue >= 93) return 100;
        if(batteryValue < 60) return 50;
        return 75;
    }
    else if(nCurrentIconLevel == 50)
    {
        if(batteryValue >= 63) return 75;
        if(batteryValue < 30) return 15;
        return 50;
    }
    else if(nCurrentIconLevel == 15)
    {
        if(batteryValue >= 33) return 50;
        if(batteryValue < 10) return 5;
        return 15;
    }
    else // nCurrentIconLevel == 5
    {
        if(batteryValue >= 13) return 15;
        return 5;
    }
}

// Improvement 5: No special first-check branch — unified logic
void ComponentBattery::updateUI()
{
    // Skip icon update until we have enough samples to filter reliably
    if(windowCount >= MIN_SAMPLES)
        nCurrentIconLevel = selectIconLevel(nFilteredBattery);

    QString pngPath = "/nBattery";
    pngPath += QString::number(nCurrentIconLevel);

    if(batData.charging == true)
        pngPath += "_Charge.png";
    else
        pngPath += ".png";

    instance.pixLoad(labelBattery,false,strDirPath,pngPath);
}

void ComponentBattery::pageShow()
{
    this->show();
}

void ComponentBattery::pageHide()
{
    this->hide();
}
