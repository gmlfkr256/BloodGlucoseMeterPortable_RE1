#include "pagesleep.h"

PageSleep::PageSleep(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageSleep::init()
{
    for(int i=0; i<6; i++)
    {
        labelButton[i] = new QLabel(this);
        labelText[i] = new QLabel(this);
        labelText[i]->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    }

    labelButton[0]->setGeometry(53,124,40,40);
    labelText[0]->setGeometry(109,118,220,52);

    labelButton[1]->setGeometry(336,124,40,40);
    labelText[1]->setGeometry(392,118,220,52);

    labelButton[2]->setGeometry(53,216,40,40);
    labelText[2]->setGeometry(109,210,220,52);

    labelButton[3]->setGeometry(336,216,40,40);
    labelText[3]->setGeometry(392,210,220,52);

    labelButton[4]->setGeometry(53,308,40,40);
    labelText[4]->setGeometry(109,302,220,52);

    labelButton[5]->setGeometry(336,308,40,40);
    labelText[5]->setGeometry(392,302,220,52);

    update();
}

void PageSleep::update()
{
    for(int i=0; i<6; i++)
    {
        labelText[i]->setFont(textResource.getFont(PAGE_SLEEP,"labelText"));
        labelText[i]->setStyleSheet("color: #000000; ");
        labelText[i]->setText(textResource.getText(PAGE_SLEEP,"labelText").at(i));
        instance.pixLoad(labelButton[i],false,strDirPath,"/circleOFF.png");
    }

    instance.pixLoad(labelButton[sleepIndex],false,strDirPath,"/circleON.png");
}

void PageSleep::pageShow()
{
#if DEVICE
    instance.guiApi.glucoseGetDispData(&instance.dispData);
#endif

    switch (instance.dispData.ts_timeout)
    {
    case 30:
        sleepIndex = SLEEP_30S;
        break;
    case 60:
        sleepIndex = SLEEP_1M;
        break;
    case 180:
        sleepIndex = SLEEP_3M;
        break;
    case 300:
        sleepIndex = SLEEP_5M;
        break;
    case 600:
        sleepIndex = SLEEP_10M;
        break;
    case 0:
        sleepIndex = SLEEP_NONE;
        break;
    default:
        qDebug()<<"PageSleep get DispData Error - time: "<<instance.dispData.ts_timeout;
        break;
    }

    update();
}

void PageSleep::pageHide()
{
    emit signalShowPageNum(PAGE_MENU);
}

void PageSleep::mousePressEvent(QMouseEvent *ev)
{
    for(int i=0; i<6; i++)
    {
        if(instance.touchCheck(labelText[i]->geometry(),ev) || instance.touchCheck(labelButton[i]->geometry(),ev))
        {
            sleepIndex = static_cast<SleepIndex>(i);
            update();
        }
    }

    if(instance.touchCheck(customButtonSave->geometry(),ev))
    {
        switch (sleepIndex)
        {
        case SLEEP_30S:
            instance.dispData.ts_timeout = 30;
            break;
        case SLEEP_1M:
            instance.dispData.ts_timeout = 60;
            break;
        case SLEEP_3M:
            instance.dispData.ts_timeout = 180;
            break;
        case SLEEP_5M:
            instance.dispData.ts_timeout = 300;
            break;
        case SLEEP_10M:
            instance.dispData.ts_timeout = 600;
            break;
        case SLEEP_NONE:
            instance.dispData.ts_timeout = 0;
            break;
        default:
            qDebug()<<"PageSleep set DispData Error - index: "<<sleepIndex;
            break;
        }
#if DEVICE
        instance.guiApi.glucoseSetDispData(&instance.dispData);
#endif
        pageHide();
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        pageHide();
    }
}
