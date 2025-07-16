#include "pagecaliresultmultiConfirm.h"

PageCaliResultMultiConfirm::PageCaliResultMultiConfirm(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageCaliResultMultiConfirm::init()
{
    labelText = new QLabel(this);
    labelText->setGeometry(50,100,540,280);
    labelText->setAlignment(Qt::AlignCenter);

    customButtonOK = new CustomButtonOK(this);
    customButtonCancel = new CustomButtonCancel(this);


    update();
}

void PageCaliResultMultiConfirm::update()
{
    customButtonOK->update();
    customButtonCancel->update();

    labelText->setFont(textResource.getFont(PAGE_CALI_RESULT_MULTI_CONFIRM,"labelText"));
    labelText->setText(textResource.getText(PAGE_CALI_RESULT_MULTI_CONFIRM,"labelText").at(0));
}

void PageCaliResultMultiConfirm::pageShow()
{
    update();
}

void PageCaliResultMultiConfirm::pageHide()
{
    emit signalShowPageNum(PAGE_CALI_RESULT_MULTI);
}

void PageCaliResultMultiConfirm::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        gapiCaliUserSpecData_t caliUserInfoClear;
        caliUserInfoClear.user = instance.getUserNumber();
        caliUserInfoClear.idx = instance.getCaliSelectIndex();
        instance.guiApi.glucoseCaliClearUserSpecInfo(&caliUserInfoClear);

#if DEVICE == false
        instance.clearCaliUserInfo(instance.getCaliSelectIndex());
#endif

        instance.isTouchCtrl = false;
        instance.setGraphMode(GRAPH_CALI);
        emit signalShowPageNum(PAGE_GRAPH);
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        pageHide();
    }
}
