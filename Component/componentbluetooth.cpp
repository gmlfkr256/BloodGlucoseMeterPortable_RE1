#include "componentbluetooth.h"

ComponentBluetooth::ComponentBluetooth(QWidget *parent) : CustomComponent(parent)
{
    this->setGeometry(437,0,54,73);
    init();
}

void ComponentBluetooth::init()
{
    labelBluetoothButton = new QLabel(this);
    labelBluetoothButton->setGeometry(9,17,36,36);
    bleAct.act = GAPI_BLE_ACT_DISABLE;
    bleStat.stat = GAPI_BLE_STAT_BLUE;
    update();
}

void ComponentBluetooth::update()
{
    QString pngPath;

    int resultBleAct, resultBleStat;

#if DEVICE
    resultBleAct = instance.guiApi.glucoseGetBleAct(&bleAct);
    resultBleStat = instance.guiApi.glucoseGetBleStat(&bleStat);
#else
    resultBleAct = GAPI_SUCCESS;
    resultBleStat = GAPI_SUCCESS;
#endif

    if(resultBleAct !=GAPI_FAIL)
    {
        switch (bleAct.act)
        {
        case GAPI_BLE_ACT_DISABLE:
            pngPath = "/Bluetooth_Off.png";
            break;
        case GAPI_BLE_ACT_ENABLE:
            if(resultBleStat!=GAPI_FAIL)
            {
                switch (bleStat.stat)
                {
                case GAPI_BLE_STAT_WHITE:
                    pngPath = "/Bluetooth_On.png";
                    break;
                case GAPI_BLE_STAT_BLUE:
                    pngPath = "/Bluetooth_Pairing.png";
                    break;
                case GAPI_BLE_STAT_MAX:
                    break;
                }
            }
            else
            {
                qDebug()<<"componentBluetooth glucoseGetBleStat Fail";
            }
            break;
        case GAPI_BLE_ACT_MAX:
            break;
        }

        if(pngPath!="")
        {
            instance.pixLoad(labelBluetoothButton,false,strDirPath,pngPath);
        }
        else
            qDebug()<<"componentBlutooth pngPath empty";
    }
    else
    {
        qDebug()<<"componentBlutooth glucoseGetBleAct Fail";
    }
}

void ComponentBluetooth::mousePressEvent(QMouseEvent* ev)
{
    if(instance.touchCheck(this->rect(),ev))
    {
        switch (bleAct.act)
        {
        case GAPI_BLE_ACT_DISABLE:
            bleAct.act = GAPI_BLE_ACT_ENABLE;
            break;
        case GAPI_BLE_ACT_ENABLE:
            bleAct.act = GAPI_BLE_ACT_DISABLE;
            break;
        case GAPI_BLE_ACT_MAX:
            break;
        }

        update();
#if DEVICE
        if(instance.guiApi.glucoseSetBleAct(&bleAct)==GAPI_FAIL)
            qDebug()<<"glucoseSetBleActFail";
#endif
    }
}

void ComponentBluetooth::pageShow()
{
    this->show();
}

void ComponentBluetooth::pageHide()
{
    this->hide();
}
