#include "pagethreshold.h"

PageThreshold::PageThreshold(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageThreshold::init()
{
    labelImgLow = new QLabel(this);
    labelImgLow->setGeometry(0,111,640,120);
    labelImgHigh = new QLabel(this);
    labelImgHigh->setGeometry(0,231,640,120);

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

    labelValueRangeLow = new QLabel(this);
    labelValueRangeLow->setGeometry(467,156,45,33);
    labelValueRangeLow->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    labelValueRangeHigh = new QLabel(this);
    labelValueRangeHigh->setGeometry(467,274,45,33);
    labelValueRangeHigh->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    customButtonSave = new CustomButtonSave(this);
    customButtonCancel = new CustomButtonCancel(this);
    update();
}

void PageThreshold::update()
{
    customButtonSave->update();
    customButtonCancel->update();

    //QString strStyleSheetlabelText = "background-color: #ffffff; color: #000000; border-radius: 15px; border: 1px solid #ebebeb; padding-left: 34px;";
    //labelTextLow->setStyleSheet(strStyleSheetlabelText);
    //labelTextHigh->setStyleSheet(strStyleSheetlabelText);
    instance.pixLoad(labelImgLow,false,strDirPath,"/valueBg.png");
    instance.pixLoad(labelImgHigh,false,strDirPath,"/valueBg.png");

    labelTextLow->setStyleSheet("padding-left: 34px;");
    labelTextLow->setFont(textResource.getFont(PAGE_THRESHOLD,"labelText"));
    labelTextLow->setText(textResource.getText(PAGE_THRESHOLD,"labelText").at(0));

    labelTextHigh->setStyleSheet("padding-left: 34px;");
    labelTextHigh->setFont(textResource.getFont(PAGE_THRESHOLD,"labelText"));
    labelTextHigh->setText(textResource.getText(PAGE_THRESHOLD,"labelText").at(1));

    labelButtonLow->setFont(textResource.getFont(PAGE_THRESHOLD,"labelButton"));
    labelButtonLow->setText(textResource.getText(PAGE_THRESHOLD,"labelButton").at(0));
    labelButtonLow->setStyleSheet("background-color: #000000; color: #ffffff; border-radius: 10px;");
    labelButtonHigh->setFont(textResource.getFont(PAGE_THRESHOLD,"labelButton"));
    labelButtonHigh->setText(textResource.getText(PAGE_THRESHOLD,"labelButton").at(0));
    labelButtonHigh->setStyleSheet("background-color: #000000; color: #ffffff; border-radius: 10px;");

#if DEVICE
    if(instance.getUserNumber() != USER_MAX)
    {
        gapiGlucoseLimit_t glucoseLimit;
        instance.guiApi.glucoseGetGlucoseLimit(&glucoseLimit);
        instance.thresholdLow = glucoseLimit.low;
        instance.thresholdHigh = glucoseLimit.high;
    }
#endif

    labelValueLow->setFont(textResource.getFont(PAGE_THRESHOLD,"labelValue"));
    labelValueHigh->setFont(textResource.getFont(PAGE_THRESHOLD,"labelValue"));
    labelValueLow->setText(QString::number(instance.thresholdLow));
    labelValueHigh->setText(QString::number(instance.thresholdHigh));

    labelValueRangeLow->setFont(textResource.getFont(PAGE_THRESHOLD,"labelValueRange"));
    labelValueRangeLow->setText(textResource.getText(PAGE_THRESHOLD,"labelValueRange").at(0));
    labelValueRangeHigh->setFont(textResource.getFont(PAGE_THRESHOLD,"labelValueRange"));
    labelValueRangeHigh->setText(textResource.getText(PAGE_THRESHOLD,"labelValueRange").at(1));

    switch (instance.getDeviceLanguage())
    {
    case KR:
    case JP:
    case SC:
    case TC:
        break;
    case EN:
    case ES:
        break;
    case LAN_MAX:
        qDebug()<<"PageThreshold Value Range init language fail";
        break;
    }
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
    if(instance.touchCheck(labelButtonLow->geometry(),ev))
    {
        instance.setThresholdIndex(THRESHOLD_LOW);
        emit signalShowPageNum(PAGE_THRESHOLD_VALUE);
    }

    if(instance.touchCheck(labelButtonHigh->geometry(),ev))
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

