#include "pagegarph.h"

PageGarph::PageGarph(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageGarph::init()
{
    setBgTopHide();

    labelGraph = new QLabel(this);

    labelTop = new QLabel(this);
    labelTop->setGeometry(10,10,620,80);
    hBoxLayoutGraph = new QHBoxLayout(this);
    hBoxLayoutGraph->setSpacing(0);
    hBoxLayoutGraph->setContentsMargins(0,0,0,0);
    labelTop->setLayout(hBoxLayoutGraph);

    labelProgressText = new QLabel(this);
    //labelProgressText->setGeometry(200,0,160,90);
    labelProgressText->setAlignment(Qt::AlignBottom);
    labelProgressText->setStyleSheet("background-color:red; color: #6c6c6c;");
    labelProgressText->setFixedWidth(160);


    labelProgressValue = new QLabel(this);
    //labelProgressValue->setGeometry(10,0,140,90);
    labelProgressValue->setStyleSheet("background-color: blue;color: #000000; padding:0px;");
    labelProgressValue->setAlignment(Qt::AlignBottom);
    labelProgressValue->setFixedWidth(140);

    labelProgressPercent = new QLabel(this);
    //labelProgressPercent->setGeometry(160,0,50,90);
    labelProgressPercent->setStyleSheet("background-color: orange; color: #000000;");
    //labelProgressPercent->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

    hBoxLayoutGraph->addWidget(labelProgressValue);
    hBoxLayoutGraph->addWidget(labelProgressPercent);
    hBoxLayoutGraph->addWidget(labelProgressText);
    hBoxLayoutGraph->addStretch();

    customButtonCancel = new CustomButtonCancel(this);
    customButtonCancel->setLongWidth(true);
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
