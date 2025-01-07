#include "componentclock.h"

ComponentClock::ComponentClock(QWidget *parent) : CustomComponent(parent)
{
    this->setGeometry(0,0,330,73);
    init();
}

void ComponentClock::init()
{
    timerClock = new QTimer(this);
    labelClock = new QLabel(this);
    labelClock->setGeometry(0,0,330,73);
    labelClock->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    labelClock->setStyleSheet("color:#ffffff; padding-left:26px");

    connect(timerClock,&QTimer::timeout,this,&ComponentClock::update);
    update();
    timerClock->start(1000);
}

void ComponentClock::update()
{
    QDateTime localTime(QDateTime::currentDateTime());
    QString day = QDateTime::currentDateTime().toString("dd");

    QLocale clockLocale = QLocale(QLocale::English,QLocale::UnitedStates);
    QString strLocale = clockLocale.toString(localTime,"MM-dd ddd hh:mm");


    labelClock->setFont(QFont(instance.fontSuit,instance.pixelToPoint(28),QFont::Bold));


    labelClock->setText(strLocale);

    instance.nSleepTimeCount++;

    if(instance.dispData.ts_timeout != 0 && static_cast<unsigned int>(instance.nSleepTimeCount) > instance.dispData.ts_timeout)
    {
#if DEVICE
        if(instance.guiApi.glucoseActPowerDown() == GAPI_FAIL)
            qDebug()<<"PowerDown Fail";
#endif
    }
}

void ComponentClock::pageShow()
{
    this->show();
}

void ComponentClock::pageHide()
{
    this->hide();
}
