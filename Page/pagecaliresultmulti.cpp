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
        labelButton[i]->setGeometry(80+(i*165),141,150,180);

        labelTextAdc[i] = new QLabel(this);
        labelTextAdc[i]->setGeometry(labelButton[i]->geometry().x(),labelButton[i]->geometry().y()+10,labelButton[i]->width(),45);
        labelTextAdc[i]->setAlignment(Qt::AlignCenter);

        labelTextTemp[i] = new QLabel(this);
        labelTextTemp[i]->setGeometry(labelButton[i]->geometry().x(),labelButton[i]->geometry().y()+68,labelButton[i]->width(),45);
        labelTextTemp[i]->setAlignment(Qt::AlignCenter);

        labelTextHeart[i] = new QLabel(this);
        labelTextHeart[i]->setGeometry(labelButton[i]->geometry().x(),labelButton[i]->geometry().y()+126,labelButton[i]->width(),45);
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
    customButtonOk->update();
    customButtonCancel->update();
    customButtonMeasure->update();
    customButtonMeasureRe->update();


#if DEVICE
    instance.updateCaliUserInfo();
#else
    int nValiedCheckCount = 0;
    for(int i=0; i<3; i++)
    {
        if(instance.caliUserInfo.val[instance.getCaliSelectIndex()].adc[i] != 0)
            nValiedCheckCount++;
    }

    if(nValiedCheckCount == 3)
        instance.caliUserInfo.val[instance.getCaliSelectIndex()].valid = 1;

    qDebug()<<"valid: "+QString::number(instance.caliUserInfo.val[instance.getCaliSelectIndex()].valid);
#endif

    customButtonOk->hide();
    customButtonCancel->hide();
    customButtonMeasure->hide();
    customButtonMeasureRe->hide();

    if(instance.getCaliIndexCompleteCheck(instance.getCaliSelectIndex()))
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
        if(instance.caliUserInfo.val[instance.getCaliSelectIndex()].adc[i] != 0)
            instance.pixLoad(labelButton[i],false,strDirPath,"/validCheck.png");//instance.pixLoad(labelButton[i],false,strDirPath,"/validBg.png");
        else
            instance.pixLoad(labelButton[i],false,strDirPath,"/buttonBg.png");

        labelTextAdc[i]->setText("");
        labelTextTemp[i]->setText("");
        labelTextHeart[i]->setText("");

        if(instance.caliUserInfo.val[static_cast<int>(instance.getCaliSelectIndex())].adc[i] != 0)
        {
            //labelTextAdc[i]->setText(QString::number(instance.caliUserInfo.val[instance.getCaliSelectIndex()].adc[i]));
            //labelTextTemp[i]->setText(QString::number(instance.caliUserInfo.val[instance.getCaliSelectIndex()].temp[i]));
            //labelTextHeart[i]->setText(QString::number(instance.caliUserInfo.val[instance.getCaliSelectIndex()].hr[i]));
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
            break;
        }
    }
}

void PageCaliResultMulti::mousePressEvent(QMouseEvent *ev)
{
    if(!instance.isTouchCtrl)
        return;

    if(customButtonOk->isVisible() && instance.touchCheck(customButtonOk->geometry(),ev))
    {
        qDebug()<<"multi ok";
        if(instance.getCaliIndexCompleteCheck(instance.getCaliSelectIndex()))
        {
            emit signalShowPageNum(PAGE_CALI_SELECT);
        }
        else
        {
            //instance.setGraphMode(GRAPH_CALI);
            //emit signalShowPageNum(PAGE_GRAPH);
            pageHide();
        }
    }

    if(customButtonCancel->isVisible() && instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        qDebug()<<"multi cancel";
        emit signalShowPageNum(PAGE_CALI_SELECT);
    }

    if(customButtonMeasure->isVisible() && instance.touchCheck(customButtonMeasure->geometry(),ev))
    {
        qDebug()<<"multi measure";
        pageHide();
    }

    if(customButtonMeasureRe->isVisible() && instance.touchCheck(customButtonMeasureRe->geometry(),ev))
    {
        qDebug()<<"multi reMeasure";
        //pageHide();
        emit signalShowPageNum(PAGE_CALI_RESULT_MULTI_CONFIRM);
    }
}

void PageCaliResultMulti::pageShow()
{
    update();
    QTimer::singleShot(100,this,[this](){instance.isTouchCtrl = true;});
}

void PageCaliResultMulti::pageHide()
{
    instance.isTouchCtrl = false;
    instance.setGraphMode(GRAPH_CALI);
    emit signalShowPageNum(PAGE_GRAPH);
}
