#include "pageupgradeconfirm.h"

PageUpgradeConfirm::PageUpgradeConfirm(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageUpgradeConfirm::init()
{
    labelText = new QLabel(this);
    labelText->setGeometry(50,100,540,280);
    labelText->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    customButtonOK = new CustomButtonOK(this);
    customButtonCancel = new CustomButtonCancel(this);

    update();
}

void PageUpgradeConfirm::update()
{
    customButtonOK->update();
    customButtonCancel->update();

    labelText->setFont(textResource.getFont(PAGE_UPGRADE_CONFIRM,"labelText"));
    labelText->setText(textResource.getText(PAGE_UPGRADE_CONFIRM,"labelText").at(0));
}

void PageUpgradeConfirm::pageShow()
{
#if DEVICE
    instance.guiApi.glucoseSetUpgradeStorage(GAPI_ACT_START);
#endif
    update();
}

void PageUpgradeConfirm::pageHide()
{
    emit signalShowPageNum(PAGE_MENU);
}

void PageUpgradeConfirm::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
#if DEVICE
        instance.guiApi.glucoseSetUpgradeStorage(GAPI_ACT_STOP);
        QTimer::singleShot(100,[this](){instance.guiApi.glucoseActReboot();});
#else
        pageHide();
#endif
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
#if DEVICE
        instance.guiApi.glucoseSetUpgradeStorage(GAPI_ACT_STOP);
#endif
        pageHide();
    }
}
