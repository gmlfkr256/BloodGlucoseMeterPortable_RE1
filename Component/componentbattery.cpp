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
    batData.charging = false;
    batDataPrev = batData;

    nBatterySize = batData.charge;
    nBatterySizePrev = batData.charge;

    timerBattery = new QTimer(this);
    connect(timerBattery,&QTimer::timeout,this,&ComponentBattery::update);
    timerBattery->start(1000);
    update();
}

void ComponentBattery::update()
{
    nBatteryCount++;

#if DEVICE
    if(instance.getProcCheck() == true)
        return;

    if(instance.guiApi.glucoseGetBatData(&batData) == GAPI_SUCCESS)
    {
        //qDebug()<<"batDataPrev.charge: "<<batDataPrev.charge<<", batDataPrev.charging: "<<batDataPrev.charging;
        //qDebug()<<"batData.charge: "<<batData.charge<<", batData.Charging: "<<batData.charging;
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
    batData.charging = (QRandomGenerator::global()->bounded(2) == 1);
    nBatterySize = batData.charge;

    if(nBatteryCount >= 60)
    {
        // 충전 중이면, 배터리 레벨이 증가했을 때만 아이콘 갱신
        if (batData.charging)
        {
            if (nBatterySize > nBatterySizePrev)
            {
                isUpdate = true;
            }
        }
        // 충전 중이 아니면, 배터리 레벨이 감소했을 때만 아이콘 갱신
        else
        {
            if (nBatterySize < nBatterySizePrev)
            {
                isUpdate = true;
            }
        }

        // “60초 전” 배터리값 업데이트
        nBatterySizePrev = nBatterySize;
        // 60초가 지난 후 카운터 리셋
        nBatteryCount = 0;
    }
    updateUI();
    //qDebug()<<"batData.charge: "<<batData.charge;
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
        /*
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

        }*/
        if(isUpdate)
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

            pngPathPrev = pngPath;
            isUpdate = false;
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
