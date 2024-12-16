#include "pageinitconfirm.h"

PageInitConfirm::PageInitConfirm(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageInitConfirm::init()
{
    labelText = new QLabel(this);
    labelText->setGeometry(0,100,640,280);
    labelText->setAlignment(Qt::AlignCenter);

    customButtonOK = new CustomButtonOK(this);
    customButtonCancel = new CustomButtonCancel(this);

    update();
}

void PageInitConfirm::update()
{
    customButtonOK->update();
    customButtonCancel->update();

    labelText->setFont(textResource.getFont(PAGE_INIT_CONFIRM,"labelText"));
    int nTextIndex = static_cast<int>(instance.getInitIndex());
    labelText->setText(textResource.getText(PAGE_INIT_CONFIRM,"labelText").at(nTextIndex));

    if(instance.getInitIndex() == INIT_FACTORY_A || instance.getInitIndex() == INIT_BLUETOOTH_A || instance.getInitIndex() == INIT_CALI_A)
    {
        customButtonOK->setLongWidth(true);
        customButtonCancel->hide();
    }
    else
    {
        customButtonOK->setLongWidth(false);
        customButtonCancel->show();
    }
}

void PageInitConfirm::pageShow()
{
    update();
}

void PageInitConfirm::pageHide()
{

}

void PageInitConfirm::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        switch (instance.getInitIndex()) {
        case INIT_FACTORY_Q:
            instance.setInitIndex(INIT_FACTORY_A);
            update();
            break;
        case INIT_FACTORY_A:
#if DEVICE == true
            instance.guiApi.glucoseInitFactory();
#endif
            break;
        case INIT_CALI_Q:
            instance.setInitIndex(INIT_CALI_A);
#if DEVICE == true
            instance.guiApi.glucoseCaliClearUserInfo();
#else
            gapiCaliUserInfo_t emptyCaliUserInfo;
            instance.caliUserInfo = emptyCaliUserInfo;
#endif
            update();
            break;
        case INIT_CALI_A:
            break;
        case INIT_BLUETOOTH_Q:
            instance.setInitIndex(INIT_BLUETOOTH_A);
            break;
        case INIT_BLUETOOTH_A:
            break;
        case INIT_MAX:
            break;
        }
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev) && customButtonCancel->isVisible())
    {
        emit signalShowPageNum(PAGE_INIT);
    }
}


