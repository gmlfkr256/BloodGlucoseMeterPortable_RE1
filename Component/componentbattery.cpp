#include "componentbattery.h"

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

    timerBattery = new QTimer(this);
    connect(timerBattery,&QTimer::timeout,this,&ComponentBattery::update);
    timerBattery->start(5000);
    update();
}

void ComponentBattery::update()
{
#if DEVICE
    if(instance.getProcCheck() == true)
        return;

    if(instance.guiApi.glucoseGetBatData(&batData) == GAPI_SUCCESS)
    {
        //qDebug()<<"batDataPrev.charge: "<<batDataPrev.charge<<", batDataPrev.charging: "<<batDataPrev.charging;
        qDebug()<<"batData.charge: "<<batData.charge<<", batData.Charging: "<<batData.charging;
        nBatterySize = batData.charge;
        updateUI();
    }
    else
    {
        qDebug()<<"Battery Information Loading Failed";
        return;
    }
#else
    batData.charge = QRandomGenerator::global()->bounded(101);
    batData.charging = (QRandomGenerator::global()->bounded(2) == 1);
    nBatterySize = batData.charge;
#endif

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
        if(nBatterySize <= 5)
        {
            nBatteyTimer15 = 0;
            nBatteyTimer5++;
        }
        else if(nBatterySize <=15)
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

            if(nBatterySize > 5)
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


#if DEVICE == false
    updateUI();
#endif
}

void ComponentBattery::updateUI()
{
    QString pngPath;

    pngPath = "/nBattery";

    if(bIsBatteryFirstCheck)
    {
        if(nBatterySize>=90)
            pngPath += "100";
        else if(nBatterySize>=60)
            pngPath += "75";
        else if(nBatterySize>=30)
            pngPath += "50";
        else if(nBatterySize>=10)
            pngPath += "15";
        else
            pngPath += "5";

        bIsBatteryFirstCheck = false;
        pngPathPrev = pngPath;
    }
    else
    {
        listBatterySize<<nBatterySize;

        //qDebug()<<"list:"<<listBatterySize;
        if(listBatterySize.size()>=12)
        {
            int sum = std::accumulate(listBatterySize.begin(),listBatterySize.end(),0);
            int average = static_cast<int>(sum/listBatterySize.size());

            qDebug()<<"average: "<<average;
            if(average>=90)
                pngPath += "100";
            else if(average>=60)
                pngPath += "75";
            else if(average>=30)
                pngPath += "50";
            else if(average>=10)
                pngPath += "15";
            else
                pngPath += "5";

            listBatterySize.clear();
            pngPathPrev = pngPath;
        }
        else
        {
            pngPath = pngPathPrev;
        }
    }

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
