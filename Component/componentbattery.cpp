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

    timerBattery = new QTimer(this);
    update();
    connect(timerBattery,&QTimer::timeout,this,&ComponentBattery::update);
    timerBattery->start(1000);
}

void ComponentBattery::update()
{

#if DEVICE
    if(instance.getProcCheck() == true)
        return;

    int result = instance.guiApi.glucoseGetBatData(&batData);

    if(result == GAPI_SUCCESS)
    {
        qDebug()<<"batDataPrev.charge: "<<batDataPrev.charge<<", batDataPrev.charging: "<<batDataPrev.charging;
        qDebug()<<"batData.charge: "<<batData.charge<<", batData.Charging: "<<batData.charging;
        batDataPrev = batData;
        updateUI();
    }
    else
    {
        qDebug()<<"Battery Information Loading Failed";
        return;
    }
#else
    batData.charge = QRandomGenerator::global()->bounded(101);
    batData.charging = 1;
    updateUI();
     qDebug()<<"batData.charge: "<<batData.charge;
#endif
}

void ComponentBattery::updateUI()
{
    QString pngPath;

    nBatterySize = batData.charge;

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
                pngPath += "10";
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

    QPixmap pixmap = instance.pixLoad(false,strDirPath,pngPath);
    labelBattery->setPixmap(pixmap.copy());
}

void ComponentBattery::pageShow()
{
    this->show();
}

void ComponentBattery::pageHide()
{
    this->hide();
}
