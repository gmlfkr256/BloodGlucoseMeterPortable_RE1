#include "pagecaligainconfirm.h"

PageCaliGainConfirm::PageCaliGainConfirm(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageCaliGainConfirm::init()
{
    labelTextGainConfirm = new QLabel(this);
    labelTextGainConfirm->setGeometry(0,73,640,317);
    labelTextGainConfirm->setAlignment(Qt::AlignCenter);

    customButtonOk = new CustomButtonOK(this);
    customButtonCancel = new CustomButtonCancel(this);

    update();
}

void PageCaliGainConfirm::update()
{
    customButtonOk->update();
    customButtonCancel->update();

    labelTextGainConfirm->setFont(textResource.getFont(PAGE_CALI_GAIN_CONFIRM,"labelTextGainConfirm"));

    if(!instance.getGainCompleteCheck())
    {
        labelTextGainConfirm->setText(textResource.getText(PAGE_CALI_GAIN_CONFIRM,"labelTextGainConfirm").at(0));
    }
    else
    {
        labelTextGainConfirm->setText(textResource.getText(PAGE_CALI_GAIN_CONFIRM,"labelTextGainConfirm").at(1));
    }

    labelTextGainConfirm->setStyleSheet("color: #000000;");
}

void PageCaliGainConfirm::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOk->geometry(),ev))
    {
        if(instance.getGainCompleteCheck())
        {
            emit signalShowPageNum(PAGE_CALI_SELECT);
        }
        else
        {
            instance.setGraphMode(GRAPH_GAIN);
            emit signalShowPageNum(PAGE_GRAPH);
        }
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        if(instance.getGainCompleteCheck())
        {
            emit signalShowPageNum(PAGE_CALI_SELECT);
        }
        else
        {
            emit signalShowPageNum(PAGE_MENU);
        }
    }
}

void PageCaliGainConfirm::pageShow()
{

}

void PageCaliGainConfirm::pageHide()
{

}


