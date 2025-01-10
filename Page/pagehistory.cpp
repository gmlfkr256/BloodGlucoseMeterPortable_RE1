#include "pagehistory.h"

PageHistory::PageHistory(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageHistory::init()
{

    customButtonOK = new CustomButtonOK(this);
    customButtonCancel = new CustomButtonCancel(this);
    update();
}

void PageHistory::update()
{
    customButtonOK->update();
    customButtonCancel->update();

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

}
