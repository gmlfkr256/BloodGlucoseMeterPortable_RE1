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
    labelButtonDayPlus->setAlignment(Qt::AlignCenter);
    labelButtonToday = new QLabel(this);
    labelButtonToday->setGeometry(474,194,148,76);
    labelButtonToday->setAlignment(Qt::AlignCenter);
    labelButtonDayMinus = new QLabel(this);
    labelButtonDayMinus->setGeometry(474,295,148,76);
    labelButtonDayMinus->setAlignment(Qt::AlignCenter);

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

    labelButtonDayPlus->setStyleSheet("background-color:#000000; color: #ffffff; border-radius: 10px;");
    labelButtonDayPlus->setFont(textResource.getFont(PAGE_HISTORY,"labelButton"));
    labelButtonDayPlus->setText(textResource.getText(PAGE_HISTORY,"labelButton").at(0));
    labelButtonToday->setStyleSheet("background-color: #000000; color: #ffffff; border-radius: 10px;");
    labelButtonToday->setFont(textResource.getFont(PAGE_HISTORY,"labelButton"));
    labelButtonToday->setText(textResource.getText(PAGE_HISTORY,"labelButton").at(1));
    labelButtonDayMinus->setStyleSheet("background-color:#000000; color: #ffffff; border-radius: 10px;");
    labelButtonDayMinus->setFont(textResource.getFont(PAGE_HISTORY,"labelButton"));
    labelButtonDayMinus->setText(textResource.getText(PAGE_HISTORY,"labelButton").at(2));

    bool bIsHisDataValidCheck = false;

    for(int i=0; i<GAPI_TIME_MAX; i++)
    {
        //qDebug()<<"instance.hisInfo["<<getSelectedDateIndex()<<"].val["<<i<<"].valid_flag:"<<instance.hisInfo[getSelectedDateIndex()].val[i].valid_flag;
        if(instance.hisInfo[getSelectedDateIndex()].val[i].valid_flag != 0)
        {
            bIsHisDataValidCheck = true;
        }
    }

    if(bIsHisDataValidCheck)
        labelBg->setStyleSheet("border:3px solid red; border-radius: 15px;");

    QDate selectedDate(comDateYear->getDateValue(),comDateMonth->getDateValue(),comDateDay->getDateValue());

    if(selectedDate>=QDate::currentDate())
    {
        comDateYear->labelTextTop->setText("");
        comDateMonth->labelTextTop->setText("");
        comDateDay->labelTextTop->setText("");
    }
    else if(selectedDate<=QDate::currentDate().addDays(-90))
    {
        comDateYear->labelTextBottom->setText("");
        comDateMonth->labelTextBottom->setText("");
        comDateDay->labelTextBottom->setText("");
    }
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
    QDate selectedDate(comDateYear->getDateValue(),comDateMonth->getDateValue(),comDateDay->getDateValue());

    QDate currentDate = QDate::currentDate();
    QDate minDate = currentDate.addDays(-90);

    if(selectedDate>currentDate)
    {
        selectedDate = currentDate;
    }
    else if(selectedDate<minDate)
    {
        selectedDate = minDate;
    }


    QDate date(comDateYear->getDateValue(),comDateMonth->getDateValue(),1);
    int maxDaysInMonth = date.daysInMonth();
    int currentDay = selectedDate.day();

    bool wasLastDay = (currentDay == comDateDay->nDayMax);

    comDateDay->nDayMax = maxDaysInMonth;

    if(wasLastDay)
    {
        comDateDay->setValue(maxDaysInMonth);
    }
    else
        comDateDay->setValue(selectedDate.day());

    comDateYear->setValue(selectedDate.year());
    comDateMonth->setValue(selectedDate.month());
    comDateDay->update();

    update();
}

void PageHistory::getHistoryAll()
{
    qDebug()<<"getHistoryAll";
    instance.getHistoryAll();
}

int PageHistory::getSelectedDateIndex()
{
    //qDebug()<<"year: "<<comDateYear->getDateValue()<<", month: "<<comDateMonth->getDateValue()<<", day: "<<comDateDay->getDateValue();
    QDate currentDate = QDate::currentDate(); // 현재 날짜
    QDate selectedDate(comDateYear->getDateValue(), comDateMonth->getDateValue(), comDateDay->getDateValue()); // 선택된 날짜

    int daysDifference = currentDate.daysTo(selectedDate); // 현재 날짜 기준 차이 계산

    int nResult = -daysDifference;

    if(nResult > 90)
        nResult = 90;
    else if(nResult < 0)
        nResult = 0;

    return nResult;
}

void PageHistory::pageShow()
{
    getHistoryAll();

    for(ComponentSpinnerDate* com : listCom)
        com->isSelect = false;

    comDateYear->isSelect = true;

    QDateTime dateTime(QDateTime::currentDateTime());

    if(!dateSelected.isValid())
        dateSelected = dateTime.date();

    comDateYear->setValue(dateSelected.year());
    comDateMonth->setValue(dateSelected.month());
    comDateDay->setValue(dateSelected.day());

    update();
}

void PageHistory::pageHide()
{
    emit signalShowPageNum(PAGE_MENU);
}

void PageHistory::mousePressEvent(QMouseEvent *ev)
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

    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        dateSelected = QDate(comDateYear->getDateValue(),comDateMonth->getDateValue(),comDateDay->getDateValue());
        instance.nHisInfoSelectedIndex = getSelectedDateIndex();
        emit signalShowPageNum(PAGE_HISTORY_RESULT);
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        dateSelected = QDate();
        pageHide();
    }

    // 오늘 날짜로 설정
    if (instance.touchCheck(labelButtonToday->geometry(), ev))
    {
        QDate currentDate = QDate::currentDate();
        comDateYear->setValue(currentDate.year());
        comDateMonth->setValue(currentDate.month());
        comDateDay->setValue(currentDate.day());
        update();
    }

    // 플러스데이 버튼
    if (instance.touchCheck(labelButtonDayPlus->geometry(), ev))
    {
        QDate currentDate = QDate::currentDate();
        QDate selectedDate(comDateYear->getDateValue(), comDateMonth->getDateValue(), comDateDay->getDateValue());

        if (selectedDate.daysTo(currentDate) > 7) // 현재 날짜에서 -7일 이상
        {
            selectedDate = selectedDate.addDays(7);
        }
        else
        {
            selectedDate = currentDate; // 오늘로 설정
        }

        comDateYear->setValue(selectedDate.year());
        comDateMonth->setValue(selectedDate.month());
        comDateDay->setValue(selectedDate.day());
        update();
    }

    // 마이너스데이 버튼
    if (instance.touchCheck(labelButtonDayMinus->geometry(), ev))
    {
        QDate currentDate = QDate::currentDate();
        QDate minDate = currentDate.addDays(-90); // -90일 기준
        QDate limitDate = currentDate.addDays(-63); // -63일 기준
        QDate selectedDate(comDateYear->getDateValue(), comDateMonth->getDateValue(), comDateDay->getDateValue());

        if (selectedDate <= limitDate && selectedDate > minDate) // -63일 이후 && -90일 이전
        {
            selectedDate = minDate; // -90일로 설정
        }
        else if (selectedDate > minDate) // -90일 이후
        {
            selectedDate = selectedDate.addDays(-7);
        }

        comDateYear->setValue(selectedDate.year());
        comDateMonth->setValue(selectedDate.month());
        comDateDay->setValue(selectedDate.day());
        update();
    }
}

void PageHistory::mouseReleaseEvent(QMouseEvent *ev)
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
