#include "pagethreshold.h"

PageThreshold::PageThreshold(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageThreshold::init()
{
    labelTextLow = new QLabel(this);
    labelTextLow->setGeometry(23,115,595,105);
    labelTextLow->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    labelTextHigh = new QLabel(this);
    labelTextHigh->setGeometry(23,235,595,105);
    labelTextHigh->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    labelButtonLow = new QLabel(this);
    labelButtonLow->setGeometry(530,126,73,76);
    labelButtonLow->setAlignment(Qt::AlignCenter);
    labelButtonHigh = new QLabel(this);
    labelButtonHigh->setGeometry(530,250,73,76);
    labelButtonHigh->setAlignment(Qt::AlignCenter);

    labelValueLow = new QLabel(this);
    labelValueLow->setGeometry(375,135,90,59);
    labelValueLow->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    labelValueHigh = new QLabel(this);
    labelValueHigh->setGeometry(375,254,90,59);
    labelValueHigh->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    customButtonSave = new CustomButtonSave(this);
    customButtonCancel = new CustomButtonCancel(this);
    update();
}

void PageThreshold::update()
{
    customButtonSave->update();
    customButtonCancel->update();

    QString strStyleSheetlabelText = "background-color: #ffffff; color: #000000; border-radius: 15px; border: 1px solid #ebebeb; padding-left: 34px;";
    labelTextLow->setStyleSheet(strStyleSheetlabelText);
    labelTextHigh->setStyleSheet(strStyleSheetlabelText);

    labelTextLow->setFont(textResource.getFont(PAGE_THRESHOLD,"labelText"));
    labelTextLow->setText(textResource.getText(PAGE_THRESHOLD,"labelText").at(0));
    labelTextHigh->setFont(textResource.getFont(PAGE_THRESHOLD,"labelText"));
    labelTextHigh->setText(textResource.getText(PAGE_THRESHOLD,"labelText").at(1));

    labelButtonLow->setFont(textResource.getFont(PAGE_THRESHOLD,"labelButton"));
    labelButtonLow->setText(textResource.getText(PAGE_THRESHOLD,"labelButton").at(0));
    labelButtonHigh->setFont(textResource.getFont(PAGE_THRESHOLD,"labelButton"));
    labelButtonHigh->setText(textResource.getText(PAGE_THRESHOLD,"labelButton").at(0));

#if DEVICE
    gapiGlucoseLimit_t glucoseLimit;
    instance.guiApi.glucoseGetGlucoseLimit(&glucoseLimit);
    instance.thresholdLow = glucoseLimit.low;
    instance.thresholdHigh = glucoseLimit.high;
#endif

    labelValueLow->setFont(textResource.getFont(PAGE_THRESHOLD,"labelValue"));
    labelValueHigh->setFont(textResource.getFont(PAGE_THRESHOLD,"labelValue"));
    labelValueLow->setText(QString::number(instance.thresholdLow));
    labelValueHigh->setText(QString::number(instance.thresholdHigh));
}

void PageThreshold::pageShow()
{
    update();
}

void PageThreshold::pageHide()
{

}

void PageThreshold::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(labelTextLow->geometry(),ev))
    {
        instance.setThresholdIndex(THRESHOLD_LOW);
        emit signalShowPageNum(PAGE_THRESHOLD_VALUE);
    }

    if(instance.touchCheck(labelTextHigh->geometry(),ev))
    {
        instance.setThresholdIndex(THRESHOLD_HIGH);
        emit signalShowPageNum(PAGE_THRESHOLD_VALUE);
    }

    if(instance.touchCheck(customButtonSave->geometry(),ev))
    {
        emit signalShowPageNum(PAGE_MENU);
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        emit signalShowPageNum(PAGE_MENU);
    }
}

