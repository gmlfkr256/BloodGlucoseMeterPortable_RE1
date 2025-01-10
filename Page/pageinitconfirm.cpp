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
#else
            QCoreApplication::exit(0);
#endif
            break;
        case INIT_CALI_Q:
            instance.setInitIndex(INIT_CALI_A);
#if DEVICE == true
            instance.guiApi.glucoseCaliClearUserInfo();
#else
            /*
            typedef struct gapiCaliUserInfo_T {
                unsigned char user;
                unsigned char led_sense;
                unsigned char completed;
                unsigned char revd;
                unsigned int glucose_val[GAPI_CALI_INDEX_MAX];
                gapiCaliUserIdxValue_t val[GAPI_CALI_INDEX_MAX];
            } __attribute__((__packed__)) gapiCaliUserInfo_t;
            */
            instance.caliUserInfo.led_sense = 0;
            instance.caliUserInfo.completed = 0;
            for(int i=0; i<GAPI_CALI_INDEX_MAX; i++)
            {
                instance.caliUserInfo.glucose_val[i] = 0;
                instance.caliUserInfo.val[i].valid = 0;
                for(int j=0; j<GAPI_CALI_ORDER_MAX; j++)
                {
                    instance.caliUserInfo.val[i].hr[j] = 0;
                    instance.caliUserInfo.val[i].adc[j] = 0;
                    instance.caliUserInfo.val[i].temp[j] = 0;
                }
            }
#endif
            update();
            break;
        case INIT_CALI_A:
            emit signalShowPageNum(PAGE_INIT);
            break;
        case INIT_BLUETOOTH_Q:
            instance.setInitIndex(INIT_BLUETOOTH_A);
            update();
            break;
        case INIT_BLUETOOTH_A:
            emit signalShowPageNum(PAGE_INIT);
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


