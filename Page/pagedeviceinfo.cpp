#include "pagedeviceinfo.h"

PageDeviceInfo::PageDeviceInfo(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageDeviceInfo::init()
{
    listLabelTitle<<labelDevBLEVerTitle
                 <<labelDevHWVerTitle
                <<labelDevSWVerTitle
               <<labelDevSerialTitle;
    listLabelText<<labelDevBLEVerText
                <<labelDevHWVerText
               <<labelDevSWVerText
              <<labelDevSerialText;

    for(QLabel *label : listLabelTitle)
    {
        label = new QLabel(this);
        label->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    }

    for(QLabel *label : listLabelText)
    {
        label = new QLabel(this);
        label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    }

    labelDevBLEVerTitle->setGeometry(25,80,590,75);
    labelDevBLEVerText->setGeometry(25,80,590,75);

    labelDevHWVerTitle->setGeometry(25,155,590,75);
    labelDevHWVerText->setGeometry(25,155,590,75);

    labelDevSWVerTitle->setGeometry(25,230,590,75);
    labelDevSWVerText->setGeometry(25,230,590,75);

    labelDevSerialTitle->setGeometry(25,305,590,75);
    labelDevSerialText->setGeometry(25,305,590,75);

    for(int i=0; i<3; i++)
    {
        labelLine[i] = new QLabel(this);
        labelLine[i]->setGeometry(25,155+75*i,590,1);
    }

    customButtonOK = new CustomButtonOK(this);
    customButtonOK->setLongWidth(true);
    update();
}

void PageDeviceInfo::update()
{
    customButtonOK->update();

    for(int i=0; i<3; i++)
    {
        labelLine[i]->setStyleSheet("background-color: #c5c5c5;");
    }

    for(QLabel *label : listLabelTitle)
    {
        label->setFont(textResource.getFont(PAGE_DEVICEINFO,"labelTitle"));
    }

    for(QLabel *label : listLabelText)
    {
        label->setFont(textResource.getFont(PAGE_DEVICEINFO,"labelText"));
    }

    for(int i=0; i<listLabelTitle.size(); i++)
    {
        listLabelTitle.at(i)->setText(textResource.getText(PAGE_DEVICEINFO,"labelTitle").at(i));
    }
}

void PageDeviceInfo::pageShow()
{
    update();
}

void PageDeviceInfo::pageHide()
{
    emit signalShowPageNum(PAGE_MENU);
}

void PageDeviceInfo::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        pageHide();
    }
}


