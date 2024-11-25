#include "pagecaliselectinfo.h"

PageCaliSelectInfo::PageCaliSelectInfo(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageCaliSelectInfo::init()
{
    labelSelectInfoText = new QLabel(this);
    labelSelectInfoText->setGeometry(0,73,640,317);
    labelSelectInfoText->setAlignment(Qt::AlignCenter);

    customButtonOK = new CustomButtonOK(this);
    customButtonCancel = new CustomButtonCancel(this);

    update();
}

void PageCaliSelectInfo::update()
{
    customButtonOK->update();
    customButtonCancel->update();

    labelSelectInfoText->setFont(textResource.getFont(PAGE_CALI_SELECT_INFO,"labelSelectInfoText"));

    int nSelectTextNum = 0;
    switch(instance.getCaliSelectIndex())
    {
    case CALI_0:
    case CALI_1:
        nSelectTextNum = 0;
        break;
    case CALI_2:
        nSelectTextNum = 1;
        break;
    case CALI_3:
        nSelectTextNum = 2;
        break;
    case CALI_4:
        nSelectTextNum = 3;
        break;
    case CALI_MAX:
        break;
    }

    labelSelectInfoText->setText(textResource.getText(PAGE_CALI_SELECT_INFO,"labelSelectInfoText").at(nSelectTextNum));
}

void PageCaliSelectInfo::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        emit signalShowPageNum(PAGE_CALI_CONFIRM);
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        emit signalShowPageNum(PAGE_CALI_SELECT);
    }
}

void PageCaliSelectInfo::pageShow()
{

}

void PageCaliSelectInfo::pageHide()
{

}

