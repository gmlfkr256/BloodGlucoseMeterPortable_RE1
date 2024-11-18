#include "pagegarph.h"

PageGarph::PageGarph(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageGarph::init()
{
    setBgTopHide();

    labelGraph = new QLabel(this);
    labelProgressText = new QLabel(this);
    labelProgressText->setGeometry(115,25,200,35);
    labelProgressText->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    labelProgressText->setStyleSheet("color: #6c6c6c;");

    labelProgressValue = new QLabel(this);
    labelProgressValue->setGeometry(20,20,70,50);
    labelProgressValue->setAlignment(Qt::AlignLeft);
    labelProgressValue->setStyleSheet("color: #000000;");

    labelProgressPercent = new QLabel(this);
    labelProgressPercent->setGeometry(85,25,30,30);
    labelProgressPercent->setStyleSheet("color: #000000;");
    labelProgressPercent->setAlignment(Qt::AlignLeft);

    customButtonCancel = new CustomButtonCancel(this);
    customButtonCancel->setLongWidth(true);
}

void PageGarph::update()
{
    customButtonCancel->update();

    labelProgressText->setFont(textResource.getFont(PAGE_GRAPH,"labelProgressText"));
    labelProgressText->setText(textResource.getText(PAGE_GRAPH,"labelProgressText").at(0));
    labelProgressValue->setFont(textResource.getFont(PAGE_GRAPH,"labelProgressValue"));
    labelProgressValue->setText("0%");
}

void PageGarph::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        emit signalShowPageNum(PAGE_CALI_GAIN_CONFIRM);
    }
}

void PageGarph::pageShow()
{

}

void PageGarph::pageHide()
{

}
