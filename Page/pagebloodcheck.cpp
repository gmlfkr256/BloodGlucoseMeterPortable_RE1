#include "pagebloodcheck.h"

PageBloodCheck::PageBloodCheck(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageBloodCheck::init()
{
    labelText = new QLabel(this);
    labelText->setGeometry(0,73,640,317);
    labelText->setAlignment(Qt::AlignCenter);

    customButtonYes = new CustomButtonYes(this);
    customButtonNo = new CustomButtonNo(this);

    update();
}

void PageBloodCheck::update()
{
    customButtonYes->update();
    customButtonNo->update();

    labelText->setFont(textResource.getFont(PAGE_BLOOD_CHECK,"labelText"));
    labelText->setText(textResource.getText(PAGE_BLOOD_CHECK,"labelText").at(0));
}

void PageBloodCheck::pageShow()
{
    update();
}

void PageBloodCheck::pageHide()
{
    emit signalShowPageNum(PAGE_CALI_VALUE);
}

void PageBloodCheck::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonYes->geometry(),ev))
    {
        qDebug()<<"setIsBlood true";
        instance.setIsBlood(true);
        pageHide();
    }

    if(instance.touchCheck(customButtonNo->geometry(),ev))
    {
        qDebug()<<"setIsBlood false";
        instance.setIsBlood(false);
        pageHide();
    }
}
