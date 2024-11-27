#include "pagecaliconfirm.h"

PageCaliConfirm::PageCaliConfirm(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageCaliConfirm::init()
{
    labelText = new QLabel(this);
    labelText->setGeometry(0,73,640,317);
    labelText->setAlignment(Qt::AlignCenter);

    customButtonMeasure = new CustomButtonMeasure(this);
    customButtonInput = new CustomButtonInput(this);

    update();
}

void PageCaliConfirm::update()
{
    customButtonMeasure->update();
    customButtonInput->update();

    labelText->setFont(textResource.getFont(PAGE_CALI_CONFIRM,"labelText"));
    labelText->setText(textResource.getText(PAGE_CALI_CONFIRM,"labelText").at(0));

    labelText->setStyleSheet("color: #000000");
}

void PageCaliConfirm::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonMeasure->geometry(),ev))
    {
        if(instance.getCaliIndexCompleteCheck(instance.getCaliSelectIndex()))
        {
            emit signalShowPageNum(PAGE_CALI_RESULT_MULTI);
        }
        else
        {
            instance.setGraphMode(GRAPH_CALI);
            emit signalShowPageNum(PAGE_GRAPH);
        }
    }

    if(instance.touchCheck(customButtonInput->geometry(),ev))
    {
        emit signalShowPageNum(PAGE_CALI_VALUE);
    }
}

void PageCaliConfirm::pageShow()
{
    update();
}

void PageCaliConfirm::pageHide()
{

}


