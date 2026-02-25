#include "pagecalinotice.h"

PageCaliNotice::PageCaliNotice(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageCaliNotice::init()
{
    labelText = new QLabel(this);
    labelText->setGeometry(0,73,640,317);
    labelText->setAlignment(Qt::AlignCenter);

    customButtonYes = new CustomButtonYes(this);
    customButtonNo = new CustomButtonNo(this);

    update();
}

void PageCaliNotice::update()
{
    customButtonYes->update();
    customButtonNo->update();

    labelText->setFont(textResource.getFont(PAGE_CALI_NOTICE,"labelText"));
    labelText->setText(textResource.getText(PAGE_CALI_NOTICE,"labelText").at(0));
}

void PageCaliNotice::pageShow()
{
    update();
}

void PageCaliNotice::pageHide()
{
    if(bIsCali)
    {
        emit signalShowPageNum(PAGE_INIT);
    }
    else
    {
        emit signalShowPageNum(PAGE_HOME);
    }
}

void PageCaliNotice::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonYes->geometry(),ev))
    {
        bIsCali = true;
        pageHide();
    }

    if(instance.touchCheck(customButtonNo->geometry(),ev))
    {
        bIsCali = false;
        pageHide();
    }
}
