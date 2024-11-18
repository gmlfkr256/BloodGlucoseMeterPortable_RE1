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

    labelPainter = new QLabel(this);
    labelPainter->setGeometry(0,160,640,220);

    customButtonCancel = new CustomButtonCancel(this);
    customButtonCancel->setLongWidth(true);

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
    labelProgressBar->setFixedWidth(40);

    labelAdcText->setFont(textResource.getFont(PAGE_GRAPH,"labelAdcText"));
    labelAdcText->setText(textResource.getText(PAGE_GRAPH,"labelAdcText").at(0)+"9999");
    labelAdcText->setStyleSheet("color: #6c6c6c; border: 1px solid #333333; border-radius: 5px; padding-left: 25px;");

    labelAdcRect->setStyleSheet("background-color: #52d0ba;");
}

void PageGarph::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        emit signalShowPageNum(PAGE_CALI_GAIN_CONFIRM);
    }
}

void PageGarph::pageShow()
{

}

void PageGarph::pageHide()
{

}
