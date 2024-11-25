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
        labelTextAdc[i]->setAlignment(Qt::AlignCenter);

        labelTextTemp[i] = new QLabel(this);
        labelTextTemp[i]->setGeometry(labelButton[i]->geometry().x(),labelButton[i]->geometry().y()+11+68,labelButton[i]->width(),68);
        labelTextTemp[i]->setAlignment(Qt::AlignCenter);

        labelTextHeart[i] = new QLabel(this);
        labelTextHeart[i]->setGeometry(labelButton[i]->geometry().x(),labelButton[i]->geometry().y()+11+68+68,labelButton[i]->width(),68);
        labelTextHeart[i]->setAlignment(Qt::AlignCenter);
    }

    customButtonOk = new CustomButtonOK(this);
    customButtonCancel = new CustomButtonCancel(this);
    customButtonMeasure = new CustomButtonMeasure(this);
    customButtonMeasureRe = new CustomButtonMeasureRe(this);

    update();
}

void PageCaliResultMulti::update()
{
    customButtonOk->hide();
    customButtonCancel->hide();
    customButtonMeasure->hide();
    customButtonMeasureRe->hide();

    if(instance.getCaliIndexCheck())
    {
        customButtonOk->show();
        customButtonMeasureRe->show();
    }
    else
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


    QString strAdc,strTemp,strHeart;
    strAdc = instance.caliUserInfo.val[static_cast<int>(instance.getCaliSelectIndex())].adc[instance.getCaliSelectOrder()];

    for(int i=0; i<3; i++)
    {
        instance.pixLoad(labelButton[i],false,strDirPath,"/buttonBg.png");
        labelTextAdc[i]->setText("");
        labelTextTemp[i]->setText("");
        labelTextHeart[i]->setText("");

        if(instance.caliUserInfo.val[static_cast<int>(instance.getCaliSelectIndex())].adc[i] != 0)
        {
            labelTextAdc[i]->setText(QString::number(instance.caliUserInfo.val[instance.getCaliSelectIndex()].adc[i]));
            labelTextTemp[i]->setText(QString::number(instance.caliUserInfo.val[instance.getCaliSelectIndex()].temp[i]));
            labelTextHeart[i]->setText(QString::number(instance.caliUserInfo.val[instance.getCaliSelectIndex()].hr[i]));
        }

        labelTextAdc[i]->setFont(textResource.getFont(PAGE_CALI_RESULT_MULTI,"labelTextAdc"));
        labelTextTemp[i]->setFont(textResource.getFont(PAGE_CALI_RESULT_MULTI,"labelTextTemp"));
        labelTextHeart[i]->setFont(textResource.getFont(PAGE_CALI_RESULT_MULTI,"labelTextHeart"));
    }

    for(int i=0; i<3; i++)
    {
        if(instance.caliUserInfo.val[instance.getCaliSelectIndex()].adc[i]==0)
        {
            instance.setCaliSelectOrder(static_cast<CaliSelOrder>(i));
        }
    }
}

void PageCaliResultMulti::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOk->geometry(),ev))
    {
        qDebug()<<"multi ok";
        if(instance.getCaliIndexCheck())
        {
            instance.setCaliIndexCheck(false);
            instance.setGraphMode(GRAPH_CALI);
            emit signalShowPageNum(PAGE_GRAPH);
        }
        else
            emit signalShowPageNum(PAGE_CALI_SELECT);
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        qDebug()<<"multi cancel";
        emit signalShowPageNum(PAGE_CALI_SELECT);
    }

    if(instance.touchCheck(customButtonMeasure->geometry(),ev))
    {
        qDebug()<<"multi measure";
        instance.setGraphMode(GRAPH_CALI);
        emit signalShowPageNum(PAGE_GRAPH);
    }

    if(instance.touchCheck(customButtonMeasureRe->geometry(),ev))
    {
        qDebug()<<"multi reMeasure";
        instance.setCaliIndexCheck(false);
        instance.setGraphMode(GRAPH_CALI);
        emit signalShowPageNum(PAGE_GRAPH);
    }
}

void PageCaliResultMulti::pageShow()
{
    update();
}

void PageCaliResultMulti::pageHide()
{

}
