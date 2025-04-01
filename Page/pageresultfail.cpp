#include "pageresultfail.h"

PageResultFail::PageResultFail(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageResultFail::init()
{
    labelText = new QLabel(this);
    labelText->setGeometry(0,73,640,317);

    customButtonOK = new CustomButtonOK(this);
    customButtonOK->setLongWidth(true);

    update();
}

void PageResultFail::update()
{
    customButtonOK->update();

    ComponentMeasureResult comResult;
    comResult.setTextResult(labelText,instance.sysProcMonInfo.err_code);
}

void PageResultFail::pageShow()
{
    update();
}

void PageResultFail::pageHide()
{

}

void PageResultFail::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        emit signalShowPageNum(instance.getPageNumPrev());
    }
}
