#include "pagedebugusb.h"

PageDebugUsb::PageDebugUsb(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    this->setStyleSheet("background-color: black;");
    init();
}

void PageDebugUsb::init()
{
    labelBg = new QLabel(this);
    labelBg->setGeometry(0,0,640,480);
    labelBg->setStyleSheet("background-color: black;");

    QFont font = QFont(instance.fontSuit,32,QFont::Bold);

    labelTitle = new QLabel(this);
    labelTitle->setGeometry(0,20,640,50);
    labelTitle->setStyleSheet("color: white;");
    labelTitle->setFont(font);
    labelTitle->setAlignment(Qt::AlignCenter);
    labelTitle->setText("USB");

    labelUsbText = new QLabel(this);
    labelUsbText->setGeometry(50,200,250,50);
    labelUsbText->setStyleSheet("color: white;");
    labelUsbText->setFont(font);
    labelUsbText->setAlignment(Qt::AlignCenter);
    labelUsbText->setText("USB Status: ");

    labelUsbButton = new QLabel(this);
    labelUsbButton->setGeometry(350,100,250,250);
    labelUsbButton->setFont(font);
    labelUsbButton->setAlignment(Qt::AlignCenter);
    labelUsbButton->setStyleSheet("background-color: blue; color: white;");

    customButtonSave = new CustomButtonSave(this);
    customButtonCancel =new CustomButtonCancel(this);

    update();
}

void PageDebugUsb::update()
{
#if DEVICE
    if(!bIsGetUsbData)
        return;

    switch (usbData)
    {
    case GAPI_ACT_START:
        labelUsbButton->setText("Connect");
        labelUsbButton->setStyleSheet("background-color: red; color: white;");
        break;
    case GAPI_ACT_STOP:
        labelUsbButton->setText("DisConnect");
        labelUsbButton->setStyleSheet("background-color: white; color: black;");
        break;
    default:
        labelUsbButton->setText("Connect Info Fail");

        break;
    }
#else
    labelUsbButton->setText("Not Device");
#endif
}

void PageDebugUsb::pageShow()
{
    if(instance.guiApi.glucoseGetGdataStorage(&usbData) == GAPI_SUCCESS)
    {
        bIsGetUsbData = true;
    }
    else
    {
        bIsGetUsbData = false;
        labelUsbButton->setText("USB Get Fail");
    }

    update();
}

void PageDebugUsb::pageHide()
{
    emit signalShowPageNum(PAGE_DEBUG);
}

void PageDebugUsb::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonSave->geometry(),ev))
    {
#if DEVICE
        if(bIsGetUsbData)
            instance.guiApi.glucoseSetGdataStorage(usbData);
#endif
        pageHide();
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        pageHide();
    }

    if(instance.touchCheck(labelUsbButton->geometry(),ev))
    {
        if(usbData == GAPI_ACT_START)
        {
            usbData = GAPI_ACT_STOP;
        }
        else if(usbData == GAPI_ACT_STOP)
        {
            usbData = GAPI_ACT_START;
        }

        update();
    }
}
