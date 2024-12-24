#include "pagedatetime.h"

PageDateTime::PageDateTime(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageDateTime::init()
{
    labelBg = new QLabel(this);
    labelBg->setGeometry(25,183,590,90);

    labelBgLineTop = new QLabel(this);
    labelBgLineTop->setGeometry(25,183,590,1);
    labelBgLintBottom = new QLabel(this);
    labelBgLintBottom->setGeometry(25,272,590,1);

    labelLine[0] = new QLabel(this);
    labelLine[0]->setGeometry(185,183,31,90);
    labelLine[1] = new QLabel(this);
    labelLine[1]->setGeometry(286,183,31,90);

    labelColon = new QLabel(this);
    labelColon->setGeometry(506,183,14,90);

    comDateYear = new ComponentSpinnerDate(this,DATE_YEAR);
    comDateYear->setGeometry(55,92,130,270);

    comDateMonth = new ComponentSpinnerDate(this,DATE_MONTH);
    comDateMonth->setGeometry(216,92,70,270);

    comDateDay = new ComponentSpinnerDate(this,DATE_DAY);
    comDateDay->setGeometry(316,92,70,270);

    comDateHour = new ComponentSpinnerDate(this,DATE_HOUR);
    comDateHour->setGeometry(436,92,70,270);

    comDateMin = new ComponentSpinnerDate(this,DATE_MIN);
    comDateMin->setGeometry(520,92,70,270);

    listCom<<comDateYear<<comDateMonth<<comDateDay<<comDateHour<<comDateMin;

    for(ComponentSpinnerDate* com : listCom)
    {
        connect(com,&ComponentSpinnerDate::signalSetDateStatus,this,&PageDateTime::setDateStatus);
    }

    customButtonSave = new CustomButtonSave(this);
    customButtonCancel =new CustomButtonCancel(this);

    update();
}

void PageDateTime::update()
{
    customButtonSave->update();
    customButtonCancel->update();

    labelBg->setStyleSheet("background-color: #eeeeee;");
    labelBgLineTop->setStyleSheet("background-color: #c5c5c5;");
    labelBgLintBottom->setStyleSheet("background-color: #c5c5c5;");

    labelLine[0]->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
    labelLine[0]->setText("-");
    labelLine[1]->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
    labelLine[1]->setText("-");
    labelColon->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
    labelColon->setText(":");
}

void PageDateTime::setDateStatus(DateStatus dateStatus)
{
    for(ComponentSpinnerDate* com : listCom)
    {
        com->isSelect = false;
        if(com->dateStatus == dateStatus)
            com->isSelect = true;

        if(com->dateStatus == DATE_DAY || com->dateStatus == DATE_YEAR || com->dateStatus == DATE_MONTH)
        {
            QDate date(comDateYear->getDateValue(),comDateMonth->getDateValue(),1);
            com->nDayMax = date.daysInMonth();
        }

        com->update();
    }
}

void PageDateTime::pageShow()
{
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
    if(instance.touchCheck(customButtonSave->geometry(),ev))
    {
        pageHide();
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        pageHide();
    }
}
