#include "pagecalicheck.h"

PageCaliCheck::PageCaliCheck(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageCaliCheck::init()
{
    labelTextCheck = new QLabel(this);
    labelTextCheck->setGeometry(0,73,640,317);
    labelTextCheck->setAlignment(Qt::AlignCenter);

    customButtonOK = new CustomButtonOK(this);
    customButtonCancel = new CustomButtonCancel(this);

    update();
}

void PageCaliCheck::update()
{
    customButtonOK->update();
    customButtonCancel->update();

    labelTextCheck->setFont(textResource.getFont(PAGE_CALI_CHECK,"labelTextCheck"));

    if(!instance.getCaliGainCompleteCheck())
    {
        labelTextCheck->setText(textResource.getText(PAGE_CALI_CHECK,"labelTextCheck").at(0));
    }
    else
    {
        labelTextCheck->setText(textResource.getText(PAGE_CALI_CHECK,"labelTextCheck").at(1));
    }

    labelTextCheck->setStyleSheet("color: #000000;");
}

void PageCaliCheck::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        if(instance.getCaliGainCompleteCheck())
        {
            emit signalShowPageNum(PAGE_CALI_SELECT);
        }
        else
        {
            emit signalShowPageNum(PAGE_CALI_GAIN_CONFIRM);
        }
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        if(instance.getCaliGainCompleteCheck())
        {
            emit signalShowPageNum(PAGE_CALI_SELECT);
        }
        else
        {
            emit signalShowPageNum(PAGE_MENU);
        }
    }
}

void PageCaliCheck::pageShow()
{

}

void PageCaliCheck::pageHide()
{

}
