#include "pageselectuser.h"

PageSelectUser::PageSelectUser(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageSelectUser::init()
{
    labelTitle = new QLabel(this);
    labelTitle->setGeometry(0,30,640,50);
    labelTitle->setAlignment(Qt::AlignCenter);
    labelTitle->setStyleSheet("color: #000000;");

    for(int i=0; i<USER_MAX; i++)
    {
        labelUser[i] = new QLabel(this);
        labelUser[i]->setStyleSheet("background-color: #dddddd; color: white;");
        labelUser[i]->setAlignment(Qt::AlignCenter);
    }

    if(labelUser[0]!=nullptr)
    {
        labelUser[0]->setGeometry(75,98,245,215);
        labelUser[0]->setText("User 1");
    }
    if(labelUser[1]!=nullptr)
    {
        labelUser[1]->setGeometry(320,98,24,215);
        labelUser[1]->setText("User 2");
    }

    update();
}

void PageSelectUser::update()
{
    labelTitle->setFont(textResource.getFont(PAGE_SELECT_USER,"labelTitle"));
    labelTitle->setText(textResource.getText(PAGE_SELECT_USER,"labelTitle").at(0));

    for(int i=0; i<USER_MAX; i++)
    {
        labelUser[i]->setFont(textResource.getFont(PAGE_SELECT_USER,"labelUser"));
    }
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
    for(int i=0; i<USER_MAX; i++)
    {
        if(instance.touchCheck(labelUser[i]->geometry(),ev))
        {
            instance.actUserLogin(i);
            emit signalShowPageNum(PAGE_MENU);
        }
    }
}
