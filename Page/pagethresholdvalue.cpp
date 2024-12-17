#include "pagethresholdvalue.h"

PageThresholdValue::PageThresholdValue(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageThresholdValue::init()
{
    customButtonOK = new CustomButtonOK(this);
    customButtonCancel = new CustomButtonCancel(this);
    componentSpinner[0] = new ComponentSpinner(this,QRect(10,107,200,250));
    componentSpinner[1] = new ComponentSpinner(this,QRect(220,107,200,250));
    componentSpinner[2] = new ComponentSpinner(this,QRect(430,107,200,250));

    update();
}

void PageThresholdValue::update()
{
    customButtonOK->update();
    customButtonCancel->update();
    for(ComponentSpinner *spinner : componentSpinner)
    {
        spinner->update();
    }
    initSpinner();
}

void PageThresholdValue::initSpinner()
{
    ThresholdIndex index = instance.getThresholdIndex();

    if(index == THRESHOLD_LOW)
    {
        nValue = instance.thresholdLow;
    }
    else if(index == THRESHOLD_HIGH)
    {
        nValue = instance.thresholdHigh;
    }
    else
    {
        qDebug()<<"ThressHold Index Fail";
    }

    if(nValue == 0)
        return;

    if(nValue<instance.nThresholdLimitLow)
        nValue = instance.nThresholdLimitLow;
    if(nValue>instance.nThresholdLimitHigh)
        nValue = instance.nThresholdLimitHigh;

    int nValueHan = nValue/100;
    int nValueTen = (nValue - nValueHan*100)/10;
    int nValueOne = nValue - nValueHan*100 - nValueTen*10;

    componentSpinner[0]->setValue(nValueHan);
    componentSpinner[1]->setValue(nValueTen);
    componentSpinner[2]->setValue(nValueOne);
}

void PageThresholdValue::pageShow()
{
    update();
}

void PageThresholdValue::pageHide()
{
    emit signalShowPageNum(PAGE_THRESHOLD);
}

void PageThresholdValue::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        nValue = componentSpinner[0]->getValue()*100 + componentSpinner[1]->getValue()*10 + componentSpinner[2]->getValue();
        instance.setThresholdValue(instance.getThresholdIndex(),nValue);
        pageHide();
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        pageHide();
    }
}


