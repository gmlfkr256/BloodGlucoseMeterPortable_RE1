#include "pagebloodchecknotice.h"

PageBloodCheckNotice::PageBloodCheckNotice(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageBloodCheckNotice::init()
{
    labelText = new QLabel(this);
    labelText->setGeometry(0,73,640,317);
    labelText->setAlignment(Qt::AlignCenter);

    customButtonOK = new CustomButtonOK(this);
    customButtonOK->setLongWidth(true);

    update();
}

void PageBloodCheckNotice::update()
{
    customButtonOK->update();

    labelText->setFont(textResource.getFont(PAGE_BLOOD_CHECK_NOTICE,"labelText"));
    labelText->setText(textResource.getText(PAGE_BLOOD_CHECK_NOTICE,"labelText").at(0));
}

void PageBloodCheckNotice::pageShow()
{
    update();
}

void PageBloodCheckNotice::pageHide()
{
    //emit signalShowPageNum(PAGE_CALI_SELECT);
    instance.setIsMeasure(true);
    instance.isTouchCtrl = false;
    instance.setGraphMode(GRAPH_MEASURE);
    emit signalShowPageNum(PAGE_GRAPH);
}

void PageBloodCheckNotice::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
       pageHide();
    }
}
