#include "pagedatetime.h"

PageDateTime::PageDateTime(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageDateTime::init()
{
    customButtonSave = new CustomButtonSave(this);
    customButtonCancel =new CustomButtonCancel(this);

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
