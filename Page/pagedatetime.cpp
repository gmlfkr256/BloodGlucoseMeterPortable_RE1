#include "pagedatetime.h"

PageDateTime::PageDateTime(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageDateTime::init()
{
    labelBg = new QLabel(this);
    labelBg->setGeometry(40,179,520,105);

    labelLine[0] = new QLabel(this);
    labelLine[0]->setGeometry(181,201,28,62);
    labelLine[1] = new QLabel(this);
    labelLine[1]->setGeometry(282,201,28,62);

    labelColon = new QLabel(this);
    labelColon->setGeometry(470,201,14,62);

    comDateYear = new ComponentSpinnerDate(this,DATE_YEAR);
    comDateYear->setGeometry(50,74,130,315);

    comDateMonth = new ComponentSpinnerDate(this,DATE_MONTH);
    comDateMonth->setGeometry(211,74,70,315);

    comDateDay = new ComponentSpinnerDate(this,DATE_DAY);
    comDateDay->setGeometry(311,74,70,315);

    comDateHour = new ComponentSpinnerDate(this,DATE_HOUR);
    comDateHour->setGeometry(405,74,70,315);

    comDateMin = new ComponentSpinnerDate(this,DATE_MIN);
    comDateMin->setGeometry(479,74,70,315);

    listCom<<comDateYear<<comDateMonth<<comDateDay<<comDateHour<<comDateMin;

    for(ComponentSpinnerDate* com : listCom)
    {
        connect(com,&ComponentSpinnerDate::signalSetDateStatus,this,&PageDateTime::setDateStatus);
        connect(com,&ComponentSpinnerDate::signalChangeValue,this,&PageDateTime::changeValue);
    }

    labelGradientTop = new QLabel(this);
    labelGradientTop->setGeometry(40,73,520,96);
    labelGradientTop->setAttribute(Qt::WA_TransparentForMouseEvents,true);
    labelGradientBottom = new QLabel(this);
    labelGradientBottom->setGeometry(40,294,520,96);
    labelGradientBottom->setAttribute(Qt::WA_TransparentForMouseEvents,true);

    labelArrowTop = new QLabel(this);
    labelArrowTop->setGeometry(565,83,70,70);
    labelArrowBottom = new QLabel(this);
    labelArrowBottom->setGeometry(565,310,70,70);

    customButtonSave = new CustomButtonSave(this);
    customButtonCancel =new CustomButtonCancel(this);

    update();
}

void PageDateTime::update()
{
    customButtonSave->update();
    customButtonCancel->update();

    labelBg->setStyleSheet("border: 3px solid #077bdd; border-radius: 15px;");

    labelLine[0]->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
    labelLine[0]->setText("-");
    labelLine[1]->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
    labelLine[1]->setText("-");
    labelColon->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
    labelColon->setText(":");

    instance.pixLoad(labelGradientTop,false,strDirPath,"/gradientTop.png");
    instance.pixLoad(labelGradientBottom,false,strDirPath,"/gradientBottom.png");
    instance.pixLoad(labelArrowTop,false,strDirPath,"/arrowTop.png");
    instance.pixLoad(labelArrowBottom,false,strDirPath,"/arrowBottom.png");
}

void PageDateTime::setDateStatus(DateStatus dateStatus)
{
    for(ComponentSpinnerDate* com : listCom)
    {
        com->isSelect = false;
        if(com->dateStatus == dateStatus)
            com->isSelect = true;

        com->update();
    }
}

void PageDateTime::changeValue()
{
    QDate date(comDateYear->getDateValue(),comDateMonth->getDateValue(),1);
    int maxDaysInMonth = date.daysInMonth();
    int currentDay = comDateDay->getDateValue();

    bool wasLastDay = (currentDay == comDateDay->nDayMax);

    comDateDay->nDayMax = maxDaysInMonth;

    if(wasLastDay)
    {
        comDateDay->setValue(maxDaysInMonth);
    }

    comDateDay->update();
}

void PageDateTime::pageShow()
{
    for(ComponentSpinnerDate* com : listCom)
        com->isSelect = false;

    comDateYear->isSelect = true;

    QDateTime dateTime(QDateTime::currentDateTime());

    comDateYear->setValue(dateTime.date().year());
    comDateMonth->setValue(dateTime.date().month());
    comDateDay->setValue(dateTime.date().day());
    comDateHour->setValue(dateTime.time().hour());
    comDateMin->setValue(dateTime.time().minute());

    update();
}

void PageDateTime::pageHide()
{
    emit signalShowPageNum(PAGE_MENU);
}

void PageDateTime::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(labelArrowTop->geometry(),ev))
    {
        for(ComponentSpinnerDate* com: listCom)
        {
            if(com->isSelect)
            {
                bIsArrowTouch = true;
                com->valuePlus();
            }
        }
    }

    if(instance.touchCheck(labelArrowBottom->geometry(),ev))
    {
        for(ComponentSpinnerDate* com: listCom)
        {
            if(com->isSelect)
            {
                bIsArrowTouch = true;
                com->valueMinus();
            }
        }
    }

    if(instance.touchCheck(customButtonSave->geometry(),ev))
    {
#if DEVICE == true
        int nYear = comDateYear->getDateValue();
        int nMonth = comDateMonth->getDateValue();
        int nDay = comDateDay->getDateValue();
        int nHour = comDateHour->getDateValue();
        int nMin = comDateMin->getDateValue();

        QString dateStr = QString("date %1%2%3%4%5")
                            .arg(nMonth, 2, 10, QChar('0'))
                            .arg(nDay, 2, 10, QChar('0'))
                            .arg(nHour, 2, 10, QChar('0'))
                            .arg(nMin, 2, 10, QChar('0'))
                            .arg(nYear, 4, 10, QChar('0'));

        system(dateStr.toStdString().c_str());

        dateStr = "hwclock -w";
        system(dateStr.toStdString().c_str());
#endif
        pageHide();
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        pageHide();
    }
}

void PageDateTime::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)

    if(bIsArrowTouch)
    {
        for(ComponentSpinnerDate *com : listCom)
        {
            com->timeStop();
        }
    }
}
