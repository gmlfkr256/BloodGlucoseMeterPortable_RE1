#include "pagedebugphantom.h"

PageDebugPhantom::PageDebugPhantom(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    this->setStyleSheet("background-color: black;");
    init();
}

void PageDebugPhantom::init()
{
    labelBg = new QLabel(this);
    labelBg->setGeometry(0,0,640,480);
    labelBg->setStyleSheet("background-color: black;");

    QFont font = QFont(instance.fontSuit,32,QFont::Bold);

    labelTitle = new QLabel(this);
    labelTitle->setGeometry(0,20,640,50);
    labelTitle->setStyleSheet("color: white;");
    labelTitle->setFont(font);
    labelTitle->setAlignment(Qt::AlignCenter);
    labelTitle->setText("PHANTOM");

    labelPhantomText = new QLabel(this);
    labelPhantomText->setGeometry(50,200,250,50);
    labelPhantomText->setStyleSheet("color: white;");
    labelPhantomText->setFont(font);
    labelPhantomText->setAlignment(Qt::AlignCenter);
    labelPhantomText->setText("Phantom: ");

    labelPhantomButton = new QLabel(this);
    labelPhantomButton->setGeometry(350,100,250,250);
    labelPhantomButton->setFont(font);
    labelPhantomButton->setAlignment(Qt::AlignCenter);
    labelPhantomButton->setStyleSheet("background-color: blue; color: white;");

    customButtonSave = new CustomButtonSave(this);
    customButtonCancel = new CustomButtonCancel(this);

    update();
}

void PageDebugPhantom::update()
{
    if(bPhantomState)
    {
        labelPhantomButton->setText("ON");
        labelPhantomButton->setStyleSheet("background-color: red; color: white;");
    }
    else
    {
        labelPhantomButton->setText("OFF");
        labelPhantomButton->setStyleSheet("background-color: white; color: black;");
    }
}

void PageDebugPhantom::pageShow()
{
    bPhantomState = instance.bIsPhantomTest;
    update();
}

void PageDebugPhantom::pageHide()
{
    emit signalShowPageNum(PAGE_DEBUG);
}

void PageDebugPhantom::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonSave->geometry(),ev))
    {
        instance.bIsPhantomTest = bPhantomState;
#if DEVICE
        // TODO: phantom API
#endif
        pageHide();
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        pageHide();
    }

    if(instance.touchCheck(labelPhantomButton->geometry(),ev))
    {
        bPhantomState = !bPhantomState;
        update();
    }
}
