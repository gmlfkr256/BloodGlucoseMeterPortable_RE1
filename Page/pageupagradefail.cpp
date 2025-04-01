#include "pageupagradefail.h"

PageUpagradeFail::PageUpagradeFail(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageUpagradeFail::init()
{
    labelText = new QLabel(this);
    labelText->setGeometry(0,73,640,317);

    customButtonOK = new CustomButtonOK(this);
    customButtonOK->setLongWidth(true);

    update();
}

void PageUpagradeFail::update()
{
    customButtonOK->update();

    ComponentUpgradeResult comResult;
    //comResult.setTextResult(labelText,instance.)
}

void PageUpagradeFail::pageShow()
{

}

void PageUpagradeFail::pageHide()
{
    emit signalShowPageNum(PAGE_MENU);
}

void PageUpagradeFail::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        pageHide();
    }
}
