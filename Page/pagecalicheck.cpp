#include "pagecalicheck.h"

PageCaliCheck::PageCaliCheck(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageCaliCheck::init()
{
    labelTextCheck = new QLabel(this);

    customButtonOK = new CustomButtonOK(this);
    customButtonCancel = new CustomButtonCancel(this);

    update();
}

void PageCaliCheck::update()
{
    customButtonOK->update();
    customButtonCancel->update();

    if(instance.getCaliGainCompleteCheck())
    {

    }
}

void PageCaliCheck::mousePressEvent(QMouseEvent *ev)
{

}

void PageCaliCheck::pageShow()
{

}

void PageCaliCheck::pageHide()
{

}
