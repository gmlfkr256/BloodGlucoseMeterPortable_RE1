#include "pagecalivalue.h"

PageCaliValue::PageCaliValue(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageCaliValue::init()
{
    customButtonOK = new CustomButtonOK(this);
    customButtonCancel = new CustomButtonCancel(this);
    componentSpinner[0] = new ComponentSpinner(this,QRect(10,107,200,250));
    componentSpinner[1] = new ComponentSpinner(this,QRect(220,107,200,250));
    componentSpinner[2] = new ComponentSpinner(this,QRect(430,107,200,250));
}

void PageCaliValue::update()
{
    customButtonOK->update();
    customButtonCancel->update();
    for(ComponentSpinner *spinner : componentSpinner)
    {
        spinner->update();
    }

    initSpinner();
}

void PageCaliValue::initSpinner()
{
    nValue = instance.caliUserInfo.glucose_val[instance.getCaliSelectIndex()];

    int nValueHan = nValue/100;
    int nValueTen = (nValue - nValueHan*100)/10;
    int nValueOne = nValue - nValueHan*100 - nValueTen*10;

    componentSpinner[0]->setValue(nValueHan);
    componentSpinner[1]->setValue(nValueTen);
    componentSpinner[2]->setValue(nValueOne);

}

void PageCaliValue::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        nValue = componentSpinner[0]->getValue()*100 + componentSpinner[1]->getValue()*10 + componentSpinner[2]->getValue();
        instance.setCaliValue(nValue);
        pageHide();
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        pageHide();
    }
}

void PageCaliValue::pageShow()
{
    update();
}

void PageCaliValue::pageHide()
{
    emit signalShowPageNum(PAGE_CALI_SELECT);
}
