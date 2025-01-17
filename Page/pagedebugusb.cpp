#include "pagedebugusb.h"

PageDebugUsb::PageDebugUsb(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    this->setStyleSheet("background-color: black;");
    init();
}

void PageDebugUsb::init()
{
    update();
}

void PageDebugUsb::update()
{

}

void PageDebugUsb::pageShow()
{
    update();
}

void PageDebugUsb::pageHide()
{

}

void PageDebugUsb::mousePressEvent(QMouseEvent *ev)
{

}
