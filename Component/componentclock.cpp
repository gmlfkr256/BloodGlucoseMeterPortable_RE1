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
    if(nDebugCount!=0)
    {
        nDebugClockCount++;
        if(nDebugClockCount>2)
        {
            nDebugClockCount=0;
            nDebugCount=0;
        }
    }

    labelClock->setFont(QFont(instance.fontSuit,instance.pixelToPoint(28),QFont::Bold));

    if(!instance.bIsHistorySelect)
    {
        QDateTime localTime(QDateTime::currentDateTime());
        QString day = QDateTime::currentDateTime().toString("dd");

        QLocale clockLocale = QLocale(QLocale::English,QLocale::UnitedStates);
        QString strLocale = clockLocale.toString(localTime,"MM-dd  ddd   hh:mm");

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
    else
    {
        QString strLocale;
        QString strDate = QString::number(instance.hisInfo[instance.nHisInfoSelectedIndex].date);

        if (strDate.isEmpty() || strDate.toInt() == 0) {
            QDate currentDate = QDate::currentDate();
            QDate calculatedDate = currentDate.addDays(-instance.nHisInfoSelectedIndex); // 전날 계산
            strDate = calculatedDate.toString("yyyyMMdd"); // yyyyMMdd 형식으로 설정
        }

        //qDebug() << "strDate: " << strDate;

        QDate date = QDate::fromString(strDate,"yyyyMMdd");
        QLocale clockLocale = QLocale(QLocale::English,QLocale::UnitedStates);

        if(date.isValid())
        {
            strLocale = clockLocale.toString(date,"MM-dd  ddd");//date.toString("MM-dd ddd");
            labelClock->setText(strLocale);
        }
        else
        {
            qDebug()<<"comClock history set fail";
        }
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

void ComponentClock::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
    if(instance.currentPage == PAGE_DEVICEINFO)
    {
        nDebugCount++;
        if(nDebugCount>=5)
            emit signalShowPageNum(PAGE_DEBUG);
    }
}
