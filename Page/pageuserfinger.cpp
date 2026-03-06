#include "pageuserfinger.h"

PageUserFinger::PageUserFinger(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageUserFinger::init()
{
    labelTitle = new QLabel(this);
    labelTitle->setGeometry(0,121,640,52);
    labelTitle->setAlignment(Qt::AlignCenter);

    labelImage = new QLabel(this);
    labelImage->setGeometry(86,194,514,286);

    //customButtonOK = new CustomButtonOK(this);
    //customButtonOK->setLongWidth(true);

    timer = new QTimer(this);

    connect(timer,&QTimer::timeout,this,&PageUserFinger::pageHide);
    update();
}

void PageUserFinger::update()
{
    //customButtonOK->update();

    labelTitle->setFont(textResource.getFont(PAGE_USER_FINGER,"labelTitle"));
    labelTitle->setText(textResource.getText(PAGE_USER_FINGER,"labelTitle").at(0));

    instance.pixLoad(labelImage,false,strDirPath,"/finger.png");
}

void PageUserFinger::pageShow()
{
    timer->start(5000);
    update();
}

void PageUserFinger::pageHide()
{
    timer->stop();
    //emit signalShowPageNum(PAGE_CALI_CHECK);
    emit signalShowPageNum(PAGE_USER_CAUTIONS);
}

void PageUserFinger::mousePressEvent(QMouseEvent *ev)
{
    //if(instance.touchCheck(customButtonOK->geometry(),ev))
    if(instance.touchCheck(QRect(0,0,640,480),ev))
    {
        pageHide();
    }
}
