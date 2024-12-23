#include "pagedatetime.h"

PageDateTime::PageDateTime(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageDateTime::init()
{

    update();
}

void PageDateTime::update()
{
    customButtonSave->update();
    customButtonCancel->update();
}

void PageDateTime::pageShow()
{
    update();
}

void PageDateTime::pageHide()
{

}

void PageDateTime::mousePressEvent(QMouseEvent *ev)
{

}
