#include "pagephantommode.h"

PagePhantomMode::PagePhantomMode(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    this->setStyleSheet("background-color: black;");
    init();
}

void PagePhantomMode::init()
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

void PagePhantomMode::update()
{
    if(nPhantomMode == GAPI_PHANTOM_MODE_MASS_PRODUCT)
    {
        labelPhantomButton->setText("MASS");
        labelPhantomButton->setStyleSheet("background-color: red; color: white;");
    }
    else if(nPhantomMode == GAPI_PHANTOM_MODE_QUALITY)
    {
        labelPhantomButton->setText("QUALITY");
        labelPhantomButton->setStyleSheet("background-color: green; color: white;");
    }
    else
    {
        labelPhantomButton->setText("OFF");
        labelPhantomButton->setStyleSheet("background-color: white; color: black;");
    }
}

void PagePhantomMode::pageShow()
{
    nPhantomMode = instance.nPhantomMode;
    update();
}

void PagePhantomMode::pageHide()
{
    emit signalShowPageNum(PAGE_MENU);
}

void PagePhantomMode::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonSave->geometry(),ev))
    {
        //hrkim 20260909 MASS/QUALITY → OFF 저장 = 테스트 종료: 팬텀 메뉴 숨김 (히든 토글로만 재노출)
        bool bTestEnd = (instance.nPhantomMode != GAPI_PHANTOM_MODE_NORMAL
                         && nPhantomMode == GAPI_PHANTOM_MODE_NORMAL);

        instance.nPhantomMode = nPhantomMode;
#if DEVICE
        instance.guiApi.glucoseSetPhantomUsage(nPhantomMode);
        instance.getCaliGainCompleteCheck();
#endif
        if(bTestEnd)
            instance.savePhantomMenuShow(false);

        pageHide();
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        pageHide();
    }

    if(instance.touchCheck(labelPhantomButton->geometry(),ev))
    {
        nPhantomMode = (nPhantomMode + 1) % GAPI_PHANTOM_MODE_END;
        update();
    }
}
