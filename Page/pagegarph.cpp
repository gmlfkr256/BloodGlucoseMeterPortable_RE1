#include "pagegarph.h"

PageGarph::PageGarph(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageGarph::init()
{
    setBgTopHide();

    customButtonCancel = new CustomButtonCancel(this);
    customButtonCancel->setLongWidth(true);
}

void PageGarph::update()
{
    customButtonCancel->update();
}

void PageGarph::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        emit signalShowPageNum(PAGE_CALI_GAIN_CONFIRM);
    }
}

void PageGarph::pageShow()
{

}

void PageGarph::pageHide()
{

}
