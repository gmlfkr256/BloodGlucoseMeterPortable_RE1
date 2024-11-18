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
    labelTop->setGeometry(20,10,620,80);
    hBoxLayoutGraph = new QHBoxLayout(this);
    hBoxLayoutGraph->setSpacing(0);
    hBoxLayoutGraph->setContentsMargins(0,0,0,0);
    labelTop->setLayout(hBoxLayoutGraph);

    labelProgressValue = new QLabel(this);
    //labelProgressValue->setGeometry(10,0,140,90);
    labelProgressValue->setStyleSheet("background-color: blue;color: #000000;");
    labelProgressValue->setAlignment(Qt::AlignBottom);
    labelProgressValue->setFixedWidth(140);

    labelProgressPercent = new QLabel(this);
    //labelProgressPercent->setGeometry(160,0,50,90);
    labelProgressPercent->setStyleSheet("background-color: orange; color: #000000;");
    labelProgressPercent->setAlignment(Qt::AlignBottom);

    labelProgressText = new QLabel(this);
    //labelProgressText->setGeometry(200,0,160,90);
    labelProgressText->setAlignment(Qt::AlignBottom);
    labelProgressText->setStyleSheet("background-color:red; color: #6c6c6c; padding: 1px;");

    hBoxLayoutGraph->addWidget(labelProgressValue);
    hBoxLayoutGraph->addWidget(labelProgressPercent);
    hBoxLayoutGraph->addWidget(labelProgressText);
    hBoxLayoutGraph->addStretch();

    labelProgressBarBg = new QLabel(this);
    labelProgressBarBg->setGeometry(20,100,600,20);
    labelProgressBar = new QLabel(this);
    labelProgressBar->setGeometry(20,100,600,20);

    labelAdcText = new QLabel(this);
    labelAdcText->setGeometry(22,130,130,40);

    labelAdcRect = new QLabel(this);
    labelAdcRect->setGeometry(labelAdcText->geometry().x()+15,labelAdcText->geometry().y()+15,10,10);

    timerPainter = new QTimer(this);

    connect(timerPainter,&QTimer::timeout,this,&PageGarph::updatePainter);

    labelPainter = new QLabel(this);
    labelPainter->setGeometry(0,160,640,220);

    painter = new QPainter(this);

    customButtonCancel = new CustomButtonCancel(this);
    customButtonCancel->setLongWidth(true);

    labelLoading = new QLabel(this);
    labelLoading->setGeometry(0,160,640,220);
    labelLoading->setAlignment(Qt::AlignCenter);
    labelLoading->hide();

    update();
}

void PageGarph::update()
{
    customButtonCancel->update();

    labelProgressText->setFont(textResource.getFont(PAGE_GRAPH,"labelProgressText"));
    labelProgressText->setText(textResource.getText(PAGE_GRAPH,"labelProgressText").at(0));
    labelProgressValue->setFont(textResource.getFont(PAGE_GRAPH,"labelProgressValue"));
    labelProgressValue->setText("999");
    labelProgressPercent->setFont(textResource.getFont(PAGE_GRAPH,"labelProgressPercent"));
    labelProgressPercent->setText("%");

    labelProgressBarBg->setStyleSheet("background-color: #f2f2f2; border-radius:10px;");
    labelProgressBar->setStyleSheet(
                "QLabel {"
                "    border-radius: 10px;"
                "    background-color: transparent;"  // 투명 배경 설정
                "    background-image: url(:/Image/Default/Public/ImageGraph/progressBar.png);"
                "    background-repeat: no-repeat;"
                "    background-position: center;"
                "}"
                );
    labelProgressBar->setFixedWidth(20);

    labelAdcText->setFont(textResource.getFont(PAGE_GRAPH,"labelAdcText"));
    labelAdcText->setText(textResource.getText(PAGE_GRAPH,"labelAdcText").at(0)+"9999");
    labelAdcText->setStyleSheet("color: #6c6c6c; border: 1px solid #333333; border-radius: 5px; padding-left: 25px;");

    labelAdcRect->setStyleSheet("background-color: #52d0ba;");

    pen1.setWidth(2);
    pen1.setStyle(Qt::SolidLine);
    pen1.setBrush(QColor("#737476"));

    pen2.setWidth(3);
    pen2.setStyle(Qt::SolidLine);
    pen2.setBrush(QColor("#c7c7c7"));

    pen3.setWidth(3);
    pen3.setStyle(Qt::SolidLine);
    pen3.setJoinStyle(Qt::RoundJoin);
    pen3.setCapStyle(Qt::RoundCap);

    labelLoading->setFont(textResource.getFont(PAGE_GRAPH,"labelLoading"));
    labelLoading->setText(textResource.getText(PAGE_GRAPH,"labelLoading").at(0));
}

void PageGarph::updatePainter()
{
#if DEVICE
    instance.guiApi.glucoseMonGetRawData(&instance.sysProcMonInfo);
#else
    nProgressValue++;

    if(nProgressValue>99)
    {
        instance.sysProcMonInfo.completed = 1;
    }
#endif

    if(instance.sysProcMonInfo.valid == 1)
    {
        nProgressValue = instance.sysProcMonInfo.progress;
    }

    if(instance.sysProcMonInfo.completed != 1)
    {
        if(nProgressValue == -1)
        {
            bIsProcessSuccess = false;
            pageHide();
        }

        if(nProgressValue>99)
            nProgressValue = 100;

        labelProgressValue->setText(QString::number(nProgressValue));
        labelProgressBar->setGeometry(20,76,nProgressValue*6,20);
    }
    else
    {
        bIsProcessSuccess = true;
        labelProgressValue->setText(QString::number(nProgressValue));

#if DEVICE
        instance.sysProcAct.act = GAPI_ACT_STOP;
        instance.guiApi.glucoseSysProcAct(&instance.sysProcAct);
#endif

        pageHide();
    }

    for(int i=0; i<49; i++)
    {
        nGraphPointY[i] = nGraphPointY[i+1];
    }

    for(int i=0; i<49; i++)
    {
        nGraphPointY[i] = nGraphPointY[i+1];
    }

#if DEVICE == false
    instance.sysProcMonInfo.adc_raw = QRandomGenerator::global()->bounded(2501);
#endif

    int nValue = instance.sysProcMonInfo.adc_raw;

    labelAdcText->setText(textResource.getText(PAGE_GRAPH,"labelAdcText").at(0)+QString::number(nValue));

    if(instance.sysProcMonInfo.valid == 1)
    {
        nGraphPointY[49] = 200 - (200*nValue)/3300;
    }

    labelPainter->setPixmap(pixPainter);

    if(nProgressValue>=95)
    {
        labelLoading->show();

        labelLoading->setText(textResource.getText(PAGE_GRAPH,"labelLoading").at(0)+QString(nDotCount/2,'.'));

        nDotCount++;
        if(nDotCount >12)
            nDotCount =1;
    }
}

void PageGarph::paintEvent(QPaintEvent *ev)
{
    Q_UNUSED(ev);

    painter->begin(&pixPainter);
    painter->setRenderHint(QPainter::Antialiasing,true);
    painter->setPen(pen1);

    for(int i=1; i<6; i++)
    {
        painter->drawLine(15,33*i,625,33*i);
    }

    painter->setPen(pen2);
    painter->drawLine(15,0,15,203);
    painter->drawLine(15,203,625,203);

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
        instance.sysProcAct.act = GAPI_ACT_STOP;
        instance.guiApi.glucoseSysProcAct(&instance.sysProcAct);
        emit signalShowPageNum(PAGE_CALI_GAIN_CONFIRM);
        pageHide();
    }
}

void PageGarph::pageShow()
{
#if DEVICE
    instance.guiApi.glucoseSpeakerOut(GAPI_SPK_MEASURE_START);
    instance.guiApi.glucoseSysProcAct(&instance.sysProcAct);
#endif

    timerPainter->start(100);

    for(int nPointY : nGraphPointY)
    {
        nPointY = 200;
    }

    instance.setProcCheck(true);
}

void PageGarph::pageHide()
{
    if(bIsProcessSuccess)
    {
#if DEVICE
        instance.guiApi.glucoseSpeakerOut(GAPI_SPK_MEASURE_COMPLETED);
#endif

    }
    else
    {
        labelProgressBar->setFixedWidth(20);
    }

    bIsProcessSuccess = false;
    timerPainter->stop();
    instance.setProcCheck(false);
    labelLoading->hide();
    nProgressValue = 0;
    nDotCount = 0;
}
