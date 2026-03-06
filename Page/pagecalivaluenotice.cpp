#include "pagecalivaluenotice.h"

PageCaliValueNotice::PageCaliValueNotice(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageCaliValueNotice::init()
{
    labelText = new QLabel(this);
    labelText->setGeometry(0,73,640,317);
    labelText->setAlignment(Qt::AlignCenter);

    customButtonOK = new CustomButtonOK(this);
    customButtonOK->setLongWidth(true);

    update();
}

void PageCaliValueNotice::update()
{
    customButtonOK->update();

    QString strValueRange = "( "+QString::number(GAPI_CALI_GLUCOSE_SYS_MIN)+" ~ "+QString::number(GAPI_CALI_GLUCOSE_SYS_MAX)+" )";

    labelText->setFont(textResource.getFont(PAGE_CALI_VALUE_NOTICE,"labelText"));
    labelText->setText(textResource.getText(PAGE_CALI_VALUE_NOTICE,"labelText").at(0)+"\n"+strValueRange);
}

void PageCaliValueNotice::pageShow()
{
    update();
}

void PageCaliValueNotice::pageHide()
{
    emit signalShowPageNum(PAGE_CALI_VALUE);
}

void PageCaliValueNotice::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        pageHide();
    }
}
