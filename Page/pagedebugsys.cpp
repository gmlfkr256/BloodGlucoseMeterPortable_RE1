#include "pagedebugsys.h"

PageDebugSys::PageDebugSys(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    this->setStyleSheet("backgrounr-color: black;");
    init();
}

void PageDebugSys::init()
{
    update();
}

void PageDebugSys::update()
{

}

void PageDebugSys::pageShow()
{
    update();
}

void PageDebugSys::pageHide()
{

}

void PageDebugSys::mousePressEvent(QMouseEvent *ev)
{

}
