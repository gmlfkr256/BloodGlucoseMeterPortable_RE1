#include "pageinit.h"

PageInit::PageInit(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageInit::init()
{
    for(int i=0; i<3; i++)
    {
        labelText[i] = new QLabel(this);
        labelText[i]->setGeometry(25,80+(i*75),590,75);
        labelText[i]->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        labelArrow[i] = new QLabel(this);
        labelArrow[i]->setGeometry(labelText[i]->x()+551,labelText[i]->y(),40,73);
    }
    for(int i=0; i<3; i++)
    {
        labelLine[i] = new QLabel(this);
        labelLine[i]->setGeometry(labelText[i]->x(),labelText[i]->y()+labelText[i]->height()-1,labelText[i]->width(),1);
    }

    customButtonOK = new CustomButtonOK(this);
    customButtonOK->setLongWidth(true);

    update();
}

void PageInit::update()
{
    for(int i=0; i<3; i++)
    {
        labelText[i]->setFont(textResource.getFont(PAGE_INIT,"labelText"));
        labelText[i]->setText(textResource.getText(PAGE_INIT,"labelText").at(i));
        instance.pixLoad(labelArrow[i],false,strDirPath,"/arrow.png");
    }

    for(int i=0; i<3; i++)
    {
        labelLine[i]->setStyleSheet("background-color: #c5c5c5;");
    }
}

void PageInit::pageShow()
{
    update();
}

void PageInit::pageHide()
{

}

void PageInit::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        emit signalShowPageNum(PAGE_MENU);
    }

    if(instance.touchCheck(labelText[0]->geometry(),ev))
    {
        instance.setInitIndex(INIT_FACTORY_Q);
        emit signalShowPageNum(PAGE_INIT_CONFIRM);
    }

    if(instance.touchCheck(labelText[1]->geometry(),ev))
    {
        instance.setInitIndex(INIT_BLUETOOTH_Q);
        emit signalShowPageNum(PAGE_INIT_CONFIRM);
    }

    if(instance.touchCheck(labelText[2]->geometry(),ev))
    {
        instance.setInitIndex(INIT_CALI_Q);
        emit signalShowPageNum(PAGE_INIT_CONFIRM);
    }
}
