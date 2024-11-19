#include "pagecaliselect.h"

PageCaliSelect::PageCaliSelect(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageCaliSelect::init()
{
    for(int i=0; i<5; i++)
    {
        labelSelectButton[i] = new QLabel(this);
    }

    labelSelectButton[0]->setGeometry(160,90,150,180);
    labelSelectButton[1]->setGeometry(330,90,150,180);
    labelSelectButton[2]->setGeometry(80,280,150,180);
    labelSelectButton[3]->setGeometry(245,280,150,180);
    labelSelectButton[4]->setGeometry(410,280,150,180);

    update();
}

void PageCaliSelect::update()
{
    for(int i=0; i<5; i++)
    {
        labelSelectButton[i]->setStyleSheet("background-color: #f3f3f3; border-radius: 15px;");
    }
}

void PageCaliSelect::mousePressEvent(QMouseEvent *ev)
{
    for(int i=0; i<5; i++)
    {
        if(instance.touchCheck(labelSelectButton[i]->geometry(),ev))
        {
            instance.setCaliSelectNum(static_cast<CaliSelNum>(i));
            emit signalShowPageNum(PAGE_CALI_SELECT_INFO);
        }
    }
}

void PageCaliSelect::pageShow()
{

}

void PageCaliSelect::pageHide()
{

}


