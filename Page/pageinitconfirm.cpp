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
}

void PageInitConfirm::pageShow()
{

}

void PageInitConfirm::pageHide()
{

}

void PageInitConfirm::mousePressEvent(QMouseEvent *ev)
{

}


