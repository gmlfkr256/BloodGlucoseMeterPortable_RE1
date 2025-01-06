#include "pagebatterypopup.h"

PageBatteryPopup::PageBatteryPopup(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageBatteryPopup::init()
{
    labelImg = new QLabel(this);
    labelImg->setGeometry(240,125,160,98);

    labelText = new QLabel(this);
    labelText->setGeometry(0,253,640,52);
    labelText->setAlignment(Qt::AlignCenter);

    labelTextSub = new QLabel(this);
    labelTextSub->setGeometry(0,305,640,45);
    labelTextSub->setAlignment(Qt::AlignCenter);

    customButtonOK = new CustomButtonOK(this);
    customButtonOK->setLongWidth(true);

    timerPopup = new QTimer(this);
    connect(timerPopup,&QTimer::timeout,this,&PageBatteryPopup::updateTimer);
    update();
}

void PageBatteryPopup::update()
{
    customButtonOK->update();

    labelText->setFont(textResource.getFont(PAGE_BATPOPUP,"labelText"));
    labelTextSub->setFont(textResource.getFont(PAGE_BATPOPUP,"labelTextSub"));
    if(instance.isBatZero)
    {
        instance.pixLoad(labelImg,false,strDirPath,"/battery0.png");
        labelText->setText(textResource.getText(PAGE_BATPOPUP,"labelText").at(1));
        labelTextSub->setText(textResource.getText(PAGE_BATPOPUP,"labelTextSub").at(1));
    }
    else
    {
        instance.pixLoad(labelImg,false,strDirPath,"/battery15.png");
        labelText->setText(textResource.getText(PAGE_BATPOPUP,"labelText").at(0));
        labelTextSub->setText(textResource.getText(PAGE_BATPOPUP,"labelTextSub").at(0));
    }
}

void PageBatteryPopup::updateTimer()
{
    if(instance.isBatZero && !instance.isBatCharging)
        nBatterySleepCount++;
    else
        nBatterySleepCount = 0;

#if DEVICE
    if(nBatterySleepCount>=5)
        instance.guiApi.glucoseActPowerDown();
#endif
}

void PageBatteryPopup::pageShow()
{
    nBatterySleepCount = 0;
    if(instance.isBatZero)
        timerPopup->start(1000);

    update();
}

void PageBatteryPopup::pageHide()
{
    if(instance.isBatCharging && timerPopup->isActive())
        timerPopup->stop();

    emit signalShowPageNum(instance.currentPage);
}

void PageBatteryPopup::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        pageHide();
    }
}
