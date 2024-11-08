#include "pagepassword.h"

PagePassword::PagePassword(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PagePassword::init()
{
    //setBgTopHide();

    labelTitle = new QLabel(this);
    labelTitle->setGeometry(0,30,640,50);
    labelTitleSub = new QLabel(this);
    labelTitleSub->setGeometry(0,84,640,30);

    for(int i=0; i<10; i++)
    {
        labelButtonNum[i] = new QLabel(this);
        labelButtonNum[i]->setStyleSheet("border: 1px solid #ebebeb;");
        if(i<5)
        {
            labelButtonNum[i]->setGeometry(i*128,240,128,120);
        }
        else
        {
            labelButtonNum[i]->setGeometry((i-4)*128,360,128,120);
        }
    }

    labelPasswordBg = new QLabel(this);

    for(int i=0; i<4; i++)
    {
        labelPasswordNum[i] = new QLabel(this);
    }

    labelButtonOK = new QLabel(this);
    labelButtonCancel = new QLabel(this);
}

void PagePassword::update()
{

}

void PagePassword::mousePressEvent(QMouseEvent *ev)
{

}

void PagePassword::pageShow()
{

}

void PagePassword::pageHide()
{

}
