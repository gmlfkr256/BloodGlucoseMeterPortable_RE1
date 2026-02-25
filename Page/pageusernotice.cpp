#include "pageusernotice.h"

PageUserNotice::PageUserNotice(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageUserNotice::init()
{
    labelText = new QLabel(this);
    labelText->setGeometry(0,73,640,317);
    labelText->setAlignment(Qt::AlignCenter);

    customButtonOK = new CustomButtonOK(this);
    customButtonOK->setLongWidth(true);

    update();
}

void PageUserNotice::update()
{
    customButtonOK->update();

    labelText->setFont(textResource.getFont(PAGE_USER_NOTICE,"labelText"));
    labelText->setText(textResource.getText(PAGE_USER_NOTICE,"labelText").at(0));
}

void PageUserNotice::pageShow()
{
    if(instance.getNumUserCheck()!=GAPI_CALI_UTYPE_NONE)
    {
        emit signalShowPageNum(PAGE_CALI_CHECK);
        return;
    }

    update();
}

void PageUserNotice::pageHide()
{
    emit signalShowPageNum(PAGE_USER_CHECK);
}

void PageUserNotice::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        pageHide();
    }
}
