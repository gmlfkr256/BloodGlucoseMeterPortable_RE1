#include "pagegarph.h"

PageGarph::PageGarph(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageGarph::init()
{
    setBgTopHide();

    labelProgressValue = new QLabel(this);
    labelProgressValue->setAlignment(Qt::AlignCenter);

    labelProgressPercent = new QLabel(this);
    labelProgressPercent->setAlignment(Qt::AlignCenter);

    labelProgressText = new QLabel(this);
    labelProgressText->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);


    labelProgressBarBg = new QLabel(this);
    labelProgressBarBg->setGeometry(20,95,600,30);
    labelProgressBar = new QLabel(this);
    labelProgressBar->setGeometry(20,95,600,30);

    labelAdcText = new QLabel(this);
    labelAdcText->setGeometry(20,125,130,45);

    labelAdcRect = new QLabel(this);
    labelAdcRect->setGeometry(labelAdcText->geometry().x()+12,labelAdcText->geometry().y()+18,10,10);

    timerPainter = new QTimer(this);

    connect(timerPainter,&QTimer::timeout,this,&PageGarph::updatePainter);

    labelPainter = new QLabel(this);
    labelPainter->setGeometry(20,170,600,200);

    painter = new QPainter();

    pixPainter = QPixmap(600,200);
    pixPainter.fill(Qt::transparent);

    customButtonCancel = new CustomButtonCancel(this);
    customButtonCancel->setLongWidth(true);

    labelLoading = new QLabel(this);
    labelLoading->setGeometry(20,170,600,200);
    labelLoading->setAlignment(Qt::AlignCenter);
    labelLoading->hide();

    for(int i=0; i<3; i++)
    {
        labelCircle[i] = new QLabel(this);
        labelCircle[i]->setGeometry(288+(i*(15+10)),228,15,15);
        labelCircle[i]->hide();
    }

    update();
}

void PageGarph::update()
{
    customButtonCancel->update();

    labelProgressText->setFont(textResource.getFont(PAGE_GRAPH,"labelProgressText"));
    labelProgressText->setStyleSheet("color:#808080;");
    labelProgressText->setGeometry(99,43,250,45);
    labelProgressText->setText(textResource.getText(PAGE_GRAPH,"labelProgressText").at(0));

    labelProgressValue->setFont(textResource.getFont(PAGE_GRAPH,"labelProgressValue"));
    labelProgressValue->setStyleSheet("color:#000000;");
    labelProgressValue->setGeometry(20,20,36,75);
    labelProgressValue->setText("");

    labelProgressPercent->setFont(textResource.getFont(PAGE_GRAPH,"labelProgressPercent"));
    labelProgressPercent->setStyleSheet("color:#000000;");
    labelProgressPercent->setGeometry(56,43,38,45);
    labelProgressPercent->setText("%");

    labelProgressBarBg->setStyleSheet("background-color: #f2f2f2; border-radius: 15px;");
    labelProgressBar->setStyleSheet(
                "QLabel {"
                "    border-radius: 15px;"
                "    background-color: transparent;"  // 투명 배경 설정
                "    background-image: url(:/Image/Default/Public/ImageGraph/progressBar.png);"
                "    background-repeat: no-repeat;"
                "    background-position: center;"
                "}"
                );

    labelProgressBar->setGeometry(20,95,30,30);

    labelAdcText->setFont(textResource.getFont(PAGE_GRAPH,"labelAdcText"));
    labelAdcText->setText(textResource.getText(PAGE_GRAPH,"labelAdcText").at(0));
    labelAdcText->setStyleSheet("color: #808080; padding-left: 27px;");

    instance.pixLoad(labelAdcRect,false,strDirPath,"/circleAdc.png");

    pen1.setWidth(2);
    pen1.setStyle(Qt::DashLine);
    pen1.setBrush(QColor("#c5c5c5"));

    pen2.setWidth(3);
    pen2.setStyle(Qt::SolidLine);
    pen2.setBrush(QColor("#737476"));

    pen3.setWidth(3);
    pen3.setStyle(Qt::SolidLine);
    pen3.setJoinStyle(Qt::RoundJoin);
    pen3.setCapStyle(Qt::RoundCap);
    pen3.setBrush(QColor("#077bdd"));

    labelLoading->setFont(textResource.getFont(PAGE_GRAPH,"labelLoading"));
    strLoading = textResource.getText(PAGE_GRAPH,"labelLoading").at(0);
    labelLoading->setText(strLoading);
    labelLoading->setStyleSheet("background-color: rgba(0,0,0,200); color: white; padding-top: 50px;");

    for(int i=0; i<3; i++)
    {
        instance.pixLoad(labelCircle[i],false,strDirPath,"/circleLoading"+QString::number(i)+".png");
    }
}

void PageGarph::updatePainter()
{
#if DEVICE
    instance.guiApi.glucoseMonGetRawData(&instance.sysProcMonInfo);

    if(instance.sysProcMonInfo.valid == 1)
    {
        nProgressValue = instance.sysProcMonInfo.progress;
    }
#else
    nProgressValue++;

    if(nProgressValue>=100)
    {
        nProgressValue = 100;
        instance.sysProcMonInfo.completed = 1;
    }

    instance.sysProcMonInfo.adc_raw = QRandomGenerator::global()->bounded(1000,2501);
#endif

    if(nProgressValue < 10)
    {
        labelProgressValue->setGeometry(20,20,36,75);
        labelProgressPercent->setGeometry(56,43,38,45);
        labelProgressText->setGeometry(99,43,250,45);
    }
    else if(nProgressValue < 100)
    {
        labelProgressValue->setGeometry(20,20,75,75);
        labelProgressPercent->setGeometry(95,43,38,45);
        labelProgressText->setGeometry(138,43,250,45);
    }
    else
    {
        labelProgressValue->setGeometry(20,20,103,75);
        labelProgressPercent->setGeometry(123,43,38,45);
        labelProgressText->setGeometry(166,43,250,45);
    }

    if(nProgressValue <= 100)
    {
        //qDebug()<<"nPorgressValue: "<<nProgressValue;
        labelProgressValue->setText(QString::number(nProgressValue));
        if(nProgressValue>5)
        {
            labelProgressBar->setGeometry(20,95,nProgressValue*6,30);
        }

        if(nProgressValue == 100)
            repaint();
    }

    if(instance.sysProcMonInfo.completed == 1)
    {
        bIsProcessSuccess = true;
        instance.sysProcAct.act = GAPI_ACT_STOP;
#if DEVICE
        instance.guiApi.glucoseSysProcAct(&instance.sysProcAct);

        if(instance.getGraphMode() == GRAPH_CALI)
        {
            instance.updateCaliUserInfo();
        }

#else
        if(instance.getGraphMode() == GRAPH_CALI)
        {
            instance.caliUserInfo.val[instance.getCaliSelectIndex()].adc[instance.getCaliSelectOrder()] = instance.sysProcMonInfo.adc_raw;
            instance.caliUserInfo.val[instance.getCaliSelectIndex()].temp[instance.getCaliSelectOrder()] = QRandomGenerator::global()->bounded(2500,4100);
            instance.caliUserInfo.val[instance.getCaliSelectIndex()].hr[instance.getCaliSelectOrder()] = QRandomGenerator::global()->bounded(6000,20100);

            int nValCount = 0;
            for(int i=0; i<3; i++)
            {
                if(instance.caliUserInfo.val[instance.getCaliSelectIndex()].adc[i]!=0)
                    nValCount++;
            }

            if(nValCount==3)
                instance.caliUserInfo.val[instance.getCaliSelectIndex()].valid = 1;
        }
        else if(instance.getGraphMode() == GRAPH_MEASURE)
        {
            instance.sysProcMonInfo.adc_raw = QRandomGenerator::global()->bounded(500);
        }
#endif
        pageHide();
    }
    else
    {
        if(nProgressValue == -1)
        {
            bIsProcessSuccess = false;
            pageHide();
        }
    }

    for(int i=0; i<49; i++)
    {
        nGraphPointY[i] = nGraphPointY[i+1];
    }

    int nValue = instance.sysProcMonInfo.adc_raw;

    labelAdcText->setText(textResource.getText(PAGE_GRAPH,"labelAdcText").at(0)+QString::number(nValue));

    if(instance.sysProcMonInfo.valid == 1)
    {
        nGraphPointY[49] = 200 - (200*nValue)/3300;
    }

    labelPainter->setPixmap(pixPainter);

    if(nProgressValue>=95)
    {
        if(!labelLoading->isVisible())
        {
            labelLoading->show();
            for(int i=0; i<3; i++)
                labelCircle[i]->show();
        }
        else
        {
            nCount++;
            if(nCount==1)
            {
                nCurrentIndex = (nCurrentIndex+1)%3;
                for(int i=0; i<3; i++)
                {
                    int x = 288 + ((nCurrentIndex-i+3)%3)*(15+10);
                    labelCircle[i]->move(x,228);
                }
                nCount=0;
            }
        }
    }
}

void PageGarph::paintEvent(QPaintEvent *ev)
{
    Q_UNUSED(ev);

    if (!painter->begin(&pixPainter)) {
        qWarning() << "QPainter::begin failed. Check pixPainter initialization.";
        return;
    }

    painter->setRenderHint(QPainter::Antialiasing,true);

    painter->setBrush(QColor("#f2f2f2"));
    painter->drawRect(-1,-1,labelPainter->width()+2,labelPainter->height()+2);

    painter->setPen(pen1);

    for(int i=1; i<4; i++)
    {
        painter->drawLine(0,50*i,600,50*i);
    }

    painter->setPen(pen3);

    int x,y,x1,y1;

    x = 5;
    y = nGraphPointY[0];
    x1 = 5;

    for(int i = 1; i<50; i++)
    {
        x1 = x+12;
        y1 = nGraphPointY[i];

        painter->drawLine(x,y,x1,y1);

        x=x1;
        y=y1;
    }

    painter->end();
}

void PageGarph::mousePressEvent(QMouseEvent *ev)
{
    if(!instance.isTouchCtrl)
        return;

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        instance.isTouchCtrl = false;
#if DEVICE
        instance.sysProcAct.act = GAPI_ACT_STOP;
        instance.guiApi.glucoseSysProcAct(&instance.sysProcAct);
#endif
        pageHide();
    }
}

void PageGarph::pageShow()
{
    instance.sysProcAct = {};

    instance.sysProcAct.act = GAPI_ACT_START;
    instance.sysProcAct.user = instance.getUserNumber();

    switch(instance.getGraphMode())
    {
    case GRAPH_GAIN:
        qDebug()<<"pageGraph GraphMode: GRAPH_GAIN";
        instance.sysProcAct.proc = GAPI_PROC_ACT_GAIN;
        break;
    case GRAPH_CALI:
        qDebug()<<"pageGraph GraphMode: GRAPH_CALI";

        for(int i=0; i<3; i++)
        {
            if(instance.caliUserInfo.val[instance.getCaliSelectIndex()].adc[i] == 0)
            {
                instance.setCaliSelectOrder(static_cast<CaliSelOrder>(i));
                break;
            }
        }

        instance.sysProcAct.proc = GAPI_PROC_ACT_CALIBRATION;
        instance.sysProcAct.idx = instance.getCaliSelectIndex();
        instance.sysProcAct.cali_order = instance.getCaliSelectOrder();
        break;
    case GRAPH_MEASURE:
        qDebug()<<"pageGraph GraphMode: GRAPH_MEASURE";
        instance.sysProcAct.proc = GAPI_PROC_ACT_MEASURE;
        instance.sysProcAct.idx = instance.getTimeStatus();
        break;
    case GRAPH_MAX:
        qDebug()<<"pageGraph GraphMode: GRAPH_MAX";
        instance.sysProcAct.proc = GAPI_PROC_ACT_MAX;
        break;
    }

#if DEVICE
    instance.guiApi.glucoseSpeakerOut(GAPI_SPK_MEASURE_START);
    instance.guiApi.glucoseSysProcAct(&instance.sysProcAct);
#endif



    instance.setProcCheck(true);

    switch(instance.getGraphMode())
    {
    case GRAPH_GAIN:
        qDebug()<<"GraphMode: gain";
        break;
    case GRAPH_CALI:
        qDebug()<<"GraphMode: cali";
        break;
    case GRAPH_MEASURE:
        qDebug()<<"GraphMode: measure";
        break;
    case GRAPH_MAX:
        qDebug()<<"GraphMode: max";
        break;
    }

#if DEVICE
    timerPainter->start(100);
#else
    timerPainter->start(100);
    QDateTime dateTimeLocal = QDateTime::currentDateTime();

    instance.sysProcMonInfo.hour = dateTimeLocal.time().hour();
    instance.sysProcMonInfo.min = dateTimeLocal.time().minute();
#endif

    update();
    QTimer::singleShot(instance.nTouchTime,this,[this](){instance.isTouchCtrl = true;});
}

void PageGarph::pageHide()
{
    instance.isTouchCtrl = false;

    if(bIsProcessSuccess)
    {
#if DEVICE
        instance.guiApi.glucoseSpeakerOut(GAPI_SPK_MEASURE_COMPLETED);
#else
        if(instance.getGraphMode() == GRAPH_GAIN)
            instance.caliUserInfo.led_sense = 1;
#endif
        switch (instance.getGraphMode()) {
        case GRAPH_GAIN:
            emit signalShowPageNum(PAGE_CALI_GAIN_RESULT);
            break;
        case GRAPH_CALI:
            emit signalShowPageNum(PAGE_CALI_RESULT);
            break;
        case GRAPH_MEASURE:
            emit signalShowPageNum(PAGE_RESULT);
            break;
        case GRAPH_MAX:
            break;
        }
    }
    else
    {
        switch (instance.getGraphMode()) {
        case GRAPH_GAIN:
            emit signalShowPageNum(PAGE_CALI_GAIN_CONFIRM);
            break;
        case GRAPH_CALI:
            emit signalShowPageNum(PAGE_CALI_CONFIRM);
            break;
        case GRAPH_MEASURE:
            emit signalShowPageNum(PAGE_SELECT);
            break;
        case GRAPH_MAX:
            break;
        }
    }

    labelProgressBar->setGeometry(20,95,30,30);
    bIsProcessSuccess = false;
    timerPainter->stop();
    instance.setProcCheck(false);
    labelLoading->hide();
    for(int i=0; i<3; i++)
        labelCircle[i]->hide();
    nProgressValue = 0;
    instance.sysProcMonInfo.completed = 0;
    labelPainter->setPixmap(QPixmap());
    labelAdcText->setText(textResource.getText(PAGE_GRAPH,"labelAdcText").at(0));
    labelProgressValue->setGeometry(20,20,36,75);
    labelProgressValue->setText("0");
    labelProgressPercent->setGeometry(56,43,38,45);
    labelProgressText->setGeometry(99,43,178,45);

    QPixmap pixNull;
    labelPainter->setPixmap(pixNull);

    for(int &nGraphPointY : nGraphPointY)
    {
        nGraphPointY = 200;
    }

    repaint();
}
