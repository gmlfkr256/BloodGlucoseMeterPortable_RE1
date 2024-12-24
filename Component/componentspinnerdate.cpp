#include "componentspinnerdate.h"

ComponentSpinnerDate::ComponentSpinnerDate(QWidget *parent, DateStatus dateStatus) : CustomComponent(parent)
{
    this->dateStatus = dateStatus;
    init();
}

void ComponentSpinnerDate::init()
{
    timerPress = new QTimer(this);
    connect(timerPress, &QTimer::timeout,this,&ComponentSpinnerDate::handleTimerPress);

    vBoxLayout = new QVBoxLayout(this);
    vBoxLayout->setContentsMargins(0,0,0,0);
    vBoxLayout->setSpacing(0);

    labelTextTop = new QLabel(this);
    labelTextTop->setFixedHeight(90);
    labelTextTop->setAlignment(Qt::AlignCenter);
    labelTextTop->setAttribute(Qt::WA_TransparentForMouseEvents,true);
    labelTextValue = new QLabel(this);
    labelTextValue->setFixedHeight(90);
    labelTextValue->setAlignment(Qt::AlignCenter);
    labelTextBottom = new QLabel(this);
    labelTextBottom->setFixedHeight(90);
    labelTextBottom->setAlignment(Qt::AlignCenter);
    labelTextBottom->setAttribute(Qt::WA_TransparentForMouseEvents,true);

    vBoxLayout->addWidget(labelTextTop);
    vBoxLayout->addWidget(labelTextValue);
    vBoxLayout->addWidget(labelTextBottom);

    update();
}

void ComponentSpinnerDate::update()
{
    labelTextTop->hide();
    labelTextBottom->hide();

    labelTextTop->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelTextSub"));
    labelTextTop->setStyleSheet("color: #808080; padding-top: 14px;");

    if(isSelect)
    {
        labelTextValue->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelTextSelect"));
        labelTextValue->setStyleSheet("color: #077bdd;");
        labelTextTop->show();
        labelTextBottom->show();
    }
    else
    {
        labelTextValue->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
        labelTextValue->setStyleSheet("color: #000000;");
    }

    labelTextBottom->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelTextSub"));
    labelTextBottom->setStyleSheet("color: #808080; padding-bottom: 14px;");

    QString strValue,strValueTop,strValueBottom;
    bool isCheckYear = false;

    if(dateStatus == DATE_YEAR)
        isCheckYear = true;

    checkValueRange();

    strValueTop = QString("%1").arg(nValue + 1, isCheckYear ? 4 : 2, 10, QChar('0'));
    strValue = QString("%1").arg(nValue, isCheckYear ? 4 : 2, 10, QChar('0'));
    strValueBottom = QString("%1").arg(nValue - 1, isCheckYear ? 4 : 2, 10, QChar('0'));

    if(nValue+1>nMax)
    {
        strValueTop = "";
    }
    if(nValue-1<nMin)
    {
        strValueBottom = "";
    }

    labelTextTop->setText(strValueTop);
    labelTextValue->setText(strValue);
    labelTextBottom->setText(strValueBottom);
}

void ComponentSpinnerDate::setValue(int nValue)
{
    this->nValue = nValue;
    update();
}

void ComponentSpinnerDate::checkValueRange()
{
    switch (dateStatus)
    {
    case DATE_YEAR:
        nMin = nYearMin;
        nMax = nYearMax;
        break;
    case DATE_MONTH:
        nMin = nMonthMin;
        nMax = nMonthMax;
        break;
    case DATE_DAY:
        nMin = nDayMin;
        nMax = nDayMax;
        break;
    case DATE_HOUR:
        nMin = nHourMin;
        nMax = nHourMax;
        break;
    case DATE_MIN:
        nMin = nMinMin;
        nMax = nMinMax;
        break;
    }

    if(nValue<nMin)
        nValue = nMin;
    if(nValue>nMax)
    {
        nValue = nMax;
    }

}

int ComponentSpinnerDate::getDateValue()
{
    return nValue;
}

void ComponentSpinnerDate::handleTimerPress()
{
    if(isPlus)
    {
        nValue++;
    }
    else
    {
        nValue--;
    }
    update();
    emit signalChangeValue();
}

void ComponentSpinnerDate::pageShow()
{

}

void ComponentSpinnerDate::pageHide()
{

}

void ComponentSpinnerDate::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(labelTextValue->geometry(),ev))
    {
        if(isSelect == true)
        {
            isSelect = false;
        }
        else
        {
            isSelect = true;
        }

        emit signalSetDateStatus(dateStatus);
    }

    if(instance.touchCheck(labelTextTop->geometry(),ev) && labelTextTop->isVisible())
    {
        isPlus = true;
        handleTimerPress();
        timerPress->start(200);
    }

    if(instance.touchCheck(labelTextBottom->geometry(),ev) && labelTextBottom->isVisible())
    {
        isPlus = false;
        handleTimerPress();
        timerPress->start(200);
    }
}

void ComponentSpinnerDate::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)
    timerPress->stop();
}

