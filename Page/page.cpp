#include "page.h"

Page::Page(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(parent->geometry());
    init();
    initBG();
}

void Page::init()
{
    labelBg = new QLabel(this);
    labelBgTop = new QLabel(this);
}

void Page::initBG()
{
    labelBg->setGeometry(this->geometry());
    labelBg->setStyleSheet("background-color: #ffffff;");
    labelBgTop->setGeometry(0,0,640,73);
    labelBgTop->setStyleSheet("background-color: #212121");
}

void Page::setBgTopHide()
{
    labelBgTop->hide();
}

void Page::pageShow()
{
    this->show();
}

void Page::pageHide()
{
    this->hide();
}
