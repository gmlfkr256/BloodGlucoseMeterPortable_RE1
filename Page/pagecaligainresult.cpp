#include "pagecaligainresult.h"

PageCaliGainResult::PageCaliGainResult(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageCaliGainResult::init()
{
    labelText = new QLabel(this);
    labelText->setGeometry(0,100,640,280);
    labelText->setAlignment(Qt::AlignCenter);

    customButtonOK = new CustomButtonOK(this);
    customButtonOK->setLongWidth(true);

    update();
}

void PageCaliGainResult::update()
{
    customButtonOK->update();

    labelText->setFont(textResource.getFont(PAGE_CALI_GAIN_RESULT,"labelText"));

    switch (instance.sysProcMonInfo.err_code)
    {
    case GAPI_PROC_ECODE_NORMAL:
        labelText->setText(textResource.getText(PAGE_CALI_GAIN_RESULT,"labelText").at(0));
        break;
    case GAPI_PROC_ECODE_TIMEOUT:
        labelText->setText(textResource.getText(PAGE_CALI_GAIN_RESULT,"labelText").at(1));
        break;
    }
}

void PageCaliGainResult::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        //if(instance.getCaliGainCompleteCheck())
        if(instance.caliUserInfo.led_sense == true)
        {
            emit signalShowPageNum(PAGE_CALI_SELECT);
        }
        else
        {
            emit signalShowPageNum(PAGE_MENU);
        }

        pageHide();
    }
}

void PageCaliGainResult::pageShow()
{
#if DEVICE
    instance.getCaliCompleteCheck();
#endif
    update();
}

void PageCaliGainResult::pageHide()
{

}
