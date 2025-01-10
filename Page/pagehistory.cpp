#include "pagehistory.h"

PageHistory::PageHistory(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageHistory::init()
{
    labelBg = new QLabel(this);
    labelBg->setGeometry(40,179,350,105);

    labelLine[0] = new QLabel(this);
    labelLine[0]->setGeometry(180,201,28,62);
    labelLine[1] = new QLabel(this);
    labelLine[1]->setGeometry(281,201,28,62);

    comDateYear = new ComponentSpinnerDate(this,DATE_YEAR);
    comDateYear->setGeometry(50,74,130,315);
    comDateMonth = new ComponentSpinnerDate(this,DATE_MONTH);
    comDateMonth->setGeometry(211,74,70,315);
    comDateDay = new ComponentSpinnerDate(this,DATE_DAY);
    comDateDay->setGeometry(311,74,70,315);

    listCom<<comDateYear<<comDateMonth<<comDateDay;

    for(ComponentSpinnerDate* com: listCom)
    {
        connect(com,&ComponentSpinnerDate::signalSetDateStatus,this,&PageHistory::setDateStatus);
        connect(com,&ComponentSpinnerDate::signalChangeValue,this,&PageHistory::changeValue);
    }

    labelGradientTop = new QLabel(this);
    labelGradientTop->setAttribute(Qt::WA_TransparentForMouseEvents,true);
    labelGradientTop->setGeometry(40,73,350,96);
    labelGradientBottom = new QLabel(this);
    labelGradientBottom->setAttribute(Qt::WA_TransparentForMouseEvents,true);
    labelGradientBottom->setGeometry(40,294,350,96);

    labelArrowTop = new QLabel(this);
    labelArrowTop->setGeometry(395,83,70,70);
    labelArrowBottom = new QLabel(this);
    labelArrowBottom->setGeometry(395,310,70,70);

    labelButtonDayPlus = new QLabel(this);
    labelButtonDayPlus->setGeometry(474,90,148,76);
    labelButtonToday = new QLabel(this);
    labelButtonToday->setGeometry(474,194,148,76);
    labelButtonDayMinus = new QLabel(this);
    labelButtonDayMinus->setGeometry(474,295,148,76);

    customButtonOK = new CustomButtonOK(this);
    customButtonCancel = new CustomButtonCancel(this);
    update();
}

void PageHistory::update()
{
    customButtonOK->update();
    customButtonCancel->update();

    labelBg->setStyleSheet("border: 3px solid #077bdd; border-radius: 15px;");

    for(int i=0; i<2; i++)
    {
        labelLine[i]->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
        labelLine[i]->setText("-");
    }

    instance.pixLoad(labelGradientTop,false,strDirPath,"/gradientTop.png");
    instance.pixLoad(labelGradientBottom,false,strDirPath,"/gradientBottom.png");
    instance.pixLoad(labelArrowTop,false,strDirPath,"/arrowTop.png");
    instance.pixLoad(labelArrowBottom,false,strDirPath,"/arrowBottom.png");
}

void PageHistory::setDateStatus(DateStatus dateStatus)
{
    for(ComponentSpinnerDate* com : listCom)
    {
        com->isSelect = false;
        if(com->dateStatus == dateStatus)
            com->isSelect = true;

        com->update();
    }
}

void PageHistory::changeValue()
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

void PageHistory::pageShow()
{
    update();
}

void PageHistory::pageHide()
{

}

void PageHistory::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {

    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        emit signalShowPageNum(PAGE_MENU);
    }
}

void PageHistory::mouseReleaseEvent(QMouseEvent *ev)
{

}
