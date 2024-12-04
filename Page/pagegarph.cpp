#include "pagegarph.h"

PageGarph::PageGarph(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageGarph::init()
{
    setBgTopHide();

    labelTop = new QLabel(this);
    //labelTop->setGeometry(20,10,620,60);
    labelTop->setGeometry(20,10,620,75);
    hBoxLayoutGraph = new QHBoxLayout(this);
    hBoxLayoutGraph->setSpacing(0);
    hBoxLayoutGraph->setContentsMargins(0,0,0,0);
    labelTop->setLayout(hBoxLayoutGraph);

    labelProgressValue = new QLabel(this);
    //labelProgressValue->setGeometry(10,0,140,90);
    labelProgressValue->setStyleSheet("background-color: blue;color: #000000;");
    labelProgressValue->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    labelProgressValue->setFixedWidth(95);

    labelProgressPercent = new QLabel(this);
    //labelProgressPercent->setGeometry(160,0,50,90);
    labelProgressPercent->setStyleSheet("background-color: orange; color: #000000;");
    labelProgressPercent->setAlignment(Qt::AlignBottom);

    labelProgressText = new QLabel(this);
    //labelProgressText->setGeometry(200,0,160,90);
    labelProgressText->setAlignment(Qt::AlignBottom);
    //labelProgressText->setStyleSheet("background-color:red; color: #6c6c6c; padding: 1px;");
    labelProgressText->setStyleSheet("background-color:red; color: #6c6c6c;");

    hBoxLayoutGraph->addWidget(labelProgressValue);
    hBoxLayoutGraph->addWidget(labelProgressPercent);
    hBoxLayoutGraph->addWidget(labelProgressText);
    hBoxLayoutGraph->addStretch();

    labelProgressBarBg = new QLabel(this);
    //labelProgressBarBg->setGeometry(20,80,600,20);
    labelProgressBarBg->setGeometry(20,95,600,30);
    labelProgressBar = new QLabel(this);
    //labelProgressBar->setGeometry(20,80,600,20);
    labelProgressBar->setGeometry(20,95,600,30);

    labelAdcText = new QLabel(this);
    //labelAdcText->setGeometry(22,110,130,40);
    labelAdcText->setGeometry(20,125,130,45);

    labelAdcRect = new QLabel(this);
    labelAdcRect->setGeometry(labelAdcText->geometry().x()+12,labelAdcText->geometry().y()+18,10,10);

    timerPainter = new QTimer(this);

    connect(timerPainter,&QTimer::timeout,this,&PageGarph::updatePainter);

    labelPainter = new QLabel(this);
    //labelPainter->setGeometry(0,160,640,220);
    labelPainter->setGeometry(20,170,600,200);

    painter = new QPainter();

    //pixPainter = QPixmap(640,220);
    pixPainter = QPixmap(600,200);
    pixPainter.fill(Qt::transparent);

    customButtonCancel = new CustomButtonCancel(this);
    customButtonCancel->setLongWidth(true);

    labelLoading = new QLabel(this);
    //labelLoading->setGeometry(0,160,640,230);
    labelLoading->setGeometry(20,170,600,200);
    labelLoading->setAlignment(Qt::AlignCenter);
    labelLoading->hide();

    for(int i=0; i<3; i++)
    {
        labelCircle[i] = new QLabel(this);
        labelCircle[i]->setGeometry(288+(i*(15+10)),228,15,15);
    }

    update();
}

void PageGarph::update()
{
    customButtonCancel->update();

    labelProgressText->setFont(textResource.getFont(PAGE_GRAPH,"labelProgressText"));
    labelProgressText->setText(textResource.getText(PAGE_GRAPH,"labelProgressText").at(0));
    labelProgressValue->setFont(textResource.getFont(PAGE_GRAPH,"labelProgressValue"));
    labelProgressValue->setText("");
    labelProgressPercent->setFont(textResource.getFont(PAGE_GRAPH,"labelProgressPercent"));
    labelProgressPercent->setText("%");

    //labelProgressBarBg->setStyleSheet("background-color: #f2f2f2; border-radius:10px;");
    labelProgressBarBg->setStyleSheet("background-color: #f2f2f2; border-radius: 15px;");

    /*
    labelProgressBar->setStyleSheet(
                "QLabel {"
                "    border-radius: 10px;"
                "    background-color: transparent;"  // 투명 배경 설정
                "    background-image: url(:/Image/Default/Public/ImageGraph/progressBar.png);"
                "    background-repeat: no-repeat;"
                "    background-position: center;"
                "}"
                );
                */
    labelProgressBar->setStyleSheet(
                "QLabel {"
                "    border-radius: 15px;"
                "    background-color: transparent;"  // 투명 배경 설정
                "    background-image: url(:/Image/Default/Public/ImageGraph/progressBar.png);"
                "    background-repeat: no-repeat;"
                "    background-position: center;"
                "}"
                );

    //labelProgressBar->setGeometry(20,80,20,20);
    labelProgressBar->setGeometry(20,95,30,30);

    labelAdcText->setFont(textResource.getFont(PAGE_GRAPH,"labelAdcText"));
    labelAdcText->setText(textResource.getText(PAGE_GRAPH,"labelAdcText").at(0)+"9999");
    //labelAdcText->setStyleSheet("color: #6c6c6c; border: 1px solid #333333; border-radius: 5px; padding-left: 25px;");
    labelAdcText->setStyleSheet("color: #808080; padding-left: 27px;");

    //labelAdcRect->setStyleSheet("background-color: #52d0ba;");
    labelAdcRect->setStyleSheet("background-color: #077bdd;");

    pen1.setWidth(2);
    //pen1.setStyle(Qt::SolidLine);
    pen1.setStyle(Qt::DashLine);
    //pen1.setBrush(QColor("#c7c7c7"));
    pen1.setBrush(QColor("#c5c5c5"));

    pen2.setWidth(3);
    pen2.setStyle(Qt::SolidLine);
    pen2.setBrush(QColor("#737476"));

    pen3.setWidth(3);
    pen3.setStyle(Qt::SolidLine);
    pen3.setJoinStyle(Qt::RoundJoin);
    pen3.setCapStyle(Qt::RoundCap);
    //pen3.setBrush(QColor("#52d0ba"));
    pen3.setBrush(QColor("#077bdd"));

    labelLoading->setFont(textResource.getFont(PAGE_GRAPH,"labelLoading"));
    strLoading = textResource.getText(PAGE_GRAPH,"labelLoading").at(0);
    labelLoading->setText(strLoading);
    //labelLoading->setStyleSheet("background-color: #1F2025; color: white; padding-bottom: 30px;");
    labelLoading->setStyleSheet("background-color: rgba(0,0,0,200); color: white; padding-top: 50px;");
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

    if(nProgressValue>99)
    {
        nProgressValue = 100;
        instance.sysProcMonInfo.completed = 1;
    }

    instance.sysProcMonInfo.adc_raw = QRandomGenerator::global()->bounded(1000,2501);
#endif

    if(nProgressValue <= 100)
    {
        //qDebug()<<"nPorgressValue: "<<nProgressValue;
        labelProgressValue->setText(QString::number(nProgressValue));
        if(nProgressValue>3)
        {
            //labelProgressBar->setGeometry(20,80,nProgressValue*6,20);
            labelProgressBar->setGeometry(20,95,nProgressValue*6,30);
        }
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
            labelLoading->show();

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

    //painter->setBrush(QColor("#ffffff"));
    painter->setBrush(QColor("#f2f2f2"));
    painter->drawRect(-1,-1,labelPainter->width()+2,labelPainter->height()+2);

    painter->setPen(pen1);

    /*
    for(int i=1; i<6; i++)
    {
        painter->drawLine(15,33*i,625,33*i);
    }
    */
    for(int i=1; i<4; i++)
    {
        painter->drawLine(0,50*i,600,50*i);
    }

    /*
    painter->setPen(pen2);
    painter->drawLine(15,0,15,203);
    painter->drawLine(15,203,625,203);
    */

    painter->setPen(pen3);

    int x,y,x1,y1;

    x = 20;
    y = nGraphPointY[0];
    x1 = 20;

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
    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
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

    for(int &nGraphPointY : nGraphPointY)
    {
        nGraphPointY = 200;
    }

    instance.setProcCheck(true);

    QPixmap pixNull;
    labelPainter->setPixmap(pixNull);

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
}

void PageGarph::pageHide()
{
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
            break;
        case GRAPH_MAX:
            break;
        }
    }

    //labelProgressBar->setGeometry(20,80,20,20);
    labelProgressBar->setGeometry(20,95,30,30);
    bIsProcessSuccess = false;
    timerPainter->stop();
    instance.setProcCheck(false);
    labelLoading->hide();
    nProgressValue = 0;
    instance.sysProcMonInfo.completed = 0;
    labelPainter->setPixmap(QPixmap());
}
