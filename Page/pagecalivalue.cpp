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
}

void PageCaliValue::update()
{
    customButtonOK->update();
    customButtonCancel->update();
}

void PageCaliValue::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        pageHide();
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        pageHide();
    }
}

void PageCaliValue::pageShow()
{

}

void PageCaliValue::pageHide()
{
    emit signalShowPageNum(PAGE_CALI_SELECT);
}
