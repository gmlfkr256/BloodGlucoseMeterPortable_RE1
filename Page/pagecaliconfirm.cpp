#include "pagecaliconfirm.h"

PageCaliConfirm::PageCaliConfirm(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageCaliConfirm::init()
{
    labelText = new QLabel(this);
    labelText->setGeometry(0,73,640,317);
    labelText->setAlignment(Qt::AlignCenter);

    customButtonMeasure = new CustomButtonMeasure(this);
    customButtonInput = new CustomButtonInput(this);

    update();
}

void PageCaliConfirm::update()
{
    customButtonMeasure->update();
    customButtonInput->update();

    labelText->setFont(textResource.getFont(PAGE_CALI_CONFIRM,"labelText"));
    labelText->setText(textResource.getText(PAGE_CALI_CONFIRM,"labelText").at(0));

    labelText->setStyleSheet("color: #000000");
}

void PageCaliConfirm::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonMeasure->geometry(),ev))
    {

    }

    if(instance.touchCheck(customButtonInput->geometry(),ev))
    {

    }
}

void PageCaliConfirm::pageShow()
{

}

void PageCaliConfirm::pageHide()
{

}


