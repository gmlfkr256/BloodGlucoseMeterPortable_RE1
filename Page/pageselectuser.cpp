#include "pageselectuser.h"

PageSelectUser::PageSelectUser(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageSelectUser::init()
{
    update();
}

void PageSelectUser::update()
{

}

void PageSelectUser::pageShow()
{
    update();
}

void PageSelectUser::pageHide()
{

}

void PageSelectUser::mousePressEvent(QMouseEvent *ev)
{

}
