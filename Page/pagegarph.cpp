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
    labelProgressText->setGeometry(200,0,190,90);
    labelProgressText->setAlignment(Qt::AlignLeft | Qt::AlignBottom);
    labelProgressText->setStyleSheet("color: #6c6c6c; padding-bottom: 1px;");

    labelProgressValue = new QLabel(this);
    labelProgressValue->setGeometry(10,0,160,90);
    labelProgressValue->setAlignment(Qt::AlignRight | Qt::AlignBottom);
    labelProgressValue->setStyleSheet("color: #000000;");

    labelProgressPercent = new QLabel(this);
    labelProgressPercent->setGeometry(140,0,40,90);
    labelProgressPercent->setStyleSheet("color: #000000;");
    labelProgressPercent->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

    customButtonCancel = new CustomButtonCancel(this);
    customButtonCancel->setLongWidth(true);
}

void PageGarph::update()
{
    customButtonCancel->update();

    labelProgressText->setFont(textResource.getFont(PAGE_GRAPH,"labelProgressText"));
    labelProgressText->setText(textResource.getText(PAGE_GRAPH,"labelProgressText").at(0));
    labelProgressValue->setFont(textResource.getFont(PAGE_GRAPH,"labelProgressValue"));
    labelProgressValue->setText("999");
    labelProgressPercent->setFont(textResource.getFont(PAGE_GRAPH,"labelProgressPercent"));
    labelProgressPercent->setText("%");
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
