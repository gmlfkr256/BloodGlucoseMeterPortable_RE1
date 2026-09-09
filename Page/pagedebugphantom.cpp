#include "pagedebugphantom.h"

//hrkim 20260909 팬텀 모드 설정은 PagePhantomMode(팬텀 메뉴)로 이동, 이 페이지는 팬텀 메뉴 노출 토글 전용
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
    labelTitle->setText("PHANTOM MENU");

    labelModeInfo = new QLabel(this);
    labelModeInfo->setGeometry(0,75,640,40);
    labelModeInfo->setStyleSheet("color: gray;");
    labelModeInfo->setFont(QFont(instance.fontSuit,20));
    labelModeInfo->setAlignment(Qt::AlignCenter);

    labelPhantomText = new QLabel(this);
    labelPhantomText->setGeometry(50,200,250,50);
    labelPhantomText->setStyleSheet("color: white;");
    labelPhantomText->setFont(font);
    labelPhantomText->setAlignment(Qt::AlignCenter);
    labelPhantomText->setText("Menu: ");

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
    if(bMenuShow == true)
    {
        labelPhantomButton->setText("SHOW");
        labelPhantomButton->setStyleSheet("background-color: green; color: white;");
    }
    else
    {
        labelPhantomButton->setText("HIDE");
        labelPhantomButton->setStyleSheet("background-color: white; color: black;");
    }

    // 현재 팬텀 모드 상태 표시 (읽기 전용)
    QString strMode = "OFF";
    if(instance.nPhantomMode == GAPI_PHANTOM_MODE_MASS_PRODUCT)
        strMode = "MASS";
    else if(instance.nPhantomMode == GAPI_PHANTOM_MODE_QUALITY)
        strMode = "QUALITY";

    labelModeInfo->setText("Phantom: "+strMode);
}

void PageDebugPhantom::pageShow()
{
    bMenuShow = instance.bPhantomMenuShow;
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
        instance.savePhantomMenuShow(bMenuShow);
        pageHide();
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        pageHide();
    }

    if(instance.touchCheck(labelPhantomButton->geometry(),ev))
    {
        bMenuShow = !bMenuShow;
        update();
    }
}
