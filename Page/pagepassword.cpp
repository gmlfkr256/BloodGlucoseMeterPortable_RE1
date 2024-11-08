#include "pagepassword.h"

PagePassword::PagePassword(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PagePassword::init()
{
    setBgTopHide();

    labelTitle = new QLabel(this);
    labelTitle->setGeometry(0,30,640,50);
    labelTitle->setAlignment(Qt::AlignCenter);
    labelTitleSub = new QLabel(this);
    labelTitleSub->setGeometry(0,84,640,30);
    labelTitleSub->setAlignment(Qt::AlignCenter);

    for(int i=0; i<10; i++)
    {
        labelButtonNum[i] = new QLabel(this);
        labelButtonNum[i]->setStyleSheet("border: 1px solid #ebebeb;");
        labelButtonNum[i]->setFont(textResource.getFont(PAGE_PASSWORD,"labelButtonNum"));
        labelButtonNum[i]->setAlignment(Qt::AlignCenter);
        labelButtonNum[i]->setText(QString::number(i));

        if(i<5)
        {
            labelButtonNum[i]->setGeometry(i*128,240,128,120);
        }
        else
        {
            labelButtonNum[i]->setGeometry((i-5)*128,360,128,120);
        }
    }

    labelPasswordBg = new QLabel(this);

    for(int i=0; i<4; i++)
    {
        labelPasswordNum[i] = new QLabel(this);
    }

    labelButtonOK = new QLabel(this);
    labelButtonCancel = new QLabel(this);

    update();
}

void PagePassword::update()
{
    labelTitle->setFont(textResource.getFont(PAGE_PASSWORD,"labelTitle"));
    labelTitle->setText(textResource.getText(PAGE_PASSWORD,"labelTtite").at(0));
    labelTitleSub->setFont(textResource.getFont(PAGE_PASSWORD,"labelTitleSub"));
    labelTitleSub->setFont(textResource.getText(PAGE_PASSWORD,"labelTitleSub").at(0));
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
