#include "pagecaliresultmulti.h"

PageCaliResultMulti::PageCaliResultMulti(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageCaliResultMulti::init()
{
    for(int i=0; i<3; i++)
    {
        labelButton[i] = new QLabel(this);
        labelButton[i]->setGeometry(10+(i*210),130,200,225);
        labelTextAdc[i] = new QLabel(this);
        labelTextAdc[i]->setGeometry(labelButton[i]->geometry().x(),labelButton[i]->geometry().y()+11,labelButton[i]->width(),68);
        labelTextTemp[i] = new QLabel(this);
        labelTextTemp[i]->setGeometry(labelButton[i]->geometry().x(),labelButton[i]->geometry().y()+11+68,labelButton[i]->width(),68);
        labelTextHeart[i] = new QLabel(this);
        labelTextHeart[i]->setGeometry(labelButton[i]->geometry().x(),labelButton[i]->geometry().y()+11+68+68,labelButton[i]->width(),68);
    }

    customButtonOk = new CustomButtonOK(this);
    customButtonCancel = new CustomButtonCancel(this);
    customButtonMeasure = new CustomButtonMeasure(this);
    customButtonMeasure->setLeftButton(true);
    customButtonMeasureRe = new CustomButtonMeasureRe(this);

    update();
}

void PageCaliResultMulti::update()
{
    customButtonOk->hide();
    customButtonCancel->hide();
    customButtonMeasure->hide();
    customButtonMeasureRe->hide();

    if(instance.getCaliIndexConfirm())
    {
        if(instance.caliIndexCount > 2)
        {
            customButtonOk->show();
        }
        else
        {
            customButtonMeasure->show();
        }

        customButtonCancel->show();
    }
    else
    {
        customButtonOk->show();
        customButtonMeasureRe->show();
    }

    for(int i=0; i<3; i++)
    {
        instance.pixLoad(labelButton[i],false,strDirPath,"/buttonBg.png");
    }
}

void PageCaliResultMulti::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOk->geometry(),ev))
    {
        emit signalShowPageNum(PAGE_CALI_SELECT);
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        emit signalShowPageNum(PAGE_CALI_SELECT);
    }

    if(instance.touchCheck(customButtonMeasure->geometry(),ev))
    {
        emit signalShowPageNum(PAGE_GRAPH);
    }

    if(instance.touchCheck(customButtonMeasureRe->geometry(),ev))
    {
        emit signalShowPageNum(PAGE_GRAPH);
    }
}

void PageCaliResultMulti::pageShow()
{

}

void PageCaliResultMulti::pageHide()
{

}
