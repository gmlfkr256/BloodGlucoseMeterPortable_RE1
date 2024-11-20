#include "pagecaliresult.h"

PageCaliResult::PageCaliResult(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageCaliResult::init()
{
    labelTextValue = new QLabel(this);
    labelTextValue->setAlignment(Qt::AlignCenter);
    labelTextTemp = new QLabel(this);
    labelTextTemp->setAlignment(Qt::AlignCenter);
    labelTextHeart = new QLabel(this);
    labelTextHeart->setAlignment(Qt::AlignCenter);

    comMeasureResult = new ComponentMeasureResult(this,QRect(0,280,640,100));
    update();
}

void PageCaliResult::update()
{
    comMeasureResult->update();
    comMeasureResult->setTextResult(instance.sysProcMonInfo.err_code);
}

void PageCaliResult::mousePressEvent(QMouseEvent *ev)
{

}

void PageCaliResult::pageShow()
{

}

void PageCaliResult::pageHide()
{

}
