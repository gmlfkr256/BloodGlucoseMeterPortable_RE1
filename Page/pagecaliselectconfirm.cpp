#include "pagecaliselectconfirm.h"

PageCaliSelectConfirm::PageCaliSelectConfirm(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageCaliSelectConfirm::init()
{
    labelText = new QLabel(this);
    labelText->setGeometry(50,100,540,280);
    labelText->setAlignment(Qt::AlignCenter);

    customButtonOK = new CustomButtonOK(this);
    customButtonOK->setLongWidth(true);

    update();
}

void PageCaliSelectConfirm::update()
{
    customButtonOK->update();

    labelText->setFont(textResource.getFont(PAGE_CALI_SELECT_CONFIRM,"labelText"));
    labelText->setText(textResource.getText(PAGE_CALI_SELECT_CONFIRM,"labelText").at(0));
}

void PageCaliSelectConfirm::pageShow()
{
    update();
}

void PageCaliSelectConfirm::pageHide()
{
    emit signalShowPageNum(PAGE_CALI_SELECT);
}

void PageCaliSelectConfirm::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        pageHide();
    }
}
