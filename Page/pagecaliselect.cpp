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
        labelSelectText[i] = new QLabel(this);
        labelSelectText[i]->setAlignment(Qt::AlignCenter);
        labelSelectNum[i] = new QLabel(this);
    }

    labelSelectButton[0]->setGeometry(160,90,150,180);
    labelSelectButton[1]->setGeometry(330,90,150,180);
    labelSelectButton[2]->setGeometry(80,280,150,180);
    labelSelectButton[3]->setGeometry(245,280,150,180);
    labelSelectButton[4]->setGeometry(410,280,150,180);

    for(int i=0; i<5; i++)
    {
        labelSelectText[i]->setGeometry(labelSelectButton[i]->geometry().x(),labelSelectButton[i]->y(),labelSelectButton[i]->width(),75);
        labelSelectNum[i]->setGeometry(labelSelectButton[i]->geometry().x()+33,labelSelectButton[i]->y()+75,85,85);
    }

    update();
}

void PageCaliSelect::update()
{
    for(int i=0; i<5; i++)
    {
        //labelSelectButton[i]->setStyleSheet("background-color: #f3f3f3; border-radius: 15px;");
        instance.pixLoad(labelSelectButton[i],false,strDirPath,"/buttonBg.png");

        labelSelectText[i]->setFont(textResource.getFont(PAGE_CALI_SELECT,"labelSelectText"));
        labelSelectText[i]->setStyleSheet("color: #cecece;");

        if(i<2)
            labelSelectText[i]->setText(textResource.getText(PAGE_CALI_SELECT,"labelSelectText").at(0));
        else
            labelSelectText[i]->setText(textResource.getText(PAGE_CALI_SELECT,"labelSelectText").at(1));
    }

    instance.pixLoad(labelSelectNum[0],false,strDirPath,"/num01.png");
    instance.pixLoad(labelSelectNum[1],false,strDirPath,"/num02.png");
    instance.pixLoad(labelSelectNum[2],false,strDirPath,"/num01.png");
    instance.pixLoad(labelSelectNum[3],false,strDirPath,"/num02.png");
    instance.pixLoad(labelSelectNum[4],false,strDirPath,"/num03.png");
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


