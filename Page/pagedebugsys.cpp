#include "pagedebugsys.h"

PageDebugSys::PageDebugSys(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    this->setStyleSheet("backgrounr-color: black;");
    init();
}

void PageDebugSys::init()
{
    labelBg = new QLabel(this);
    labelBg->setGeometry(0,0,640,480);
    labelBg->setStyleSheet("background-color: black;");

    QFont font = QFont(instance.fontSuit,36,QFont::Bold);
    labelTitle = new QLabel(this);
    labelTitle->setGeometry(0,20,640,50);
    labelTitle->setStyleSheet("color: white;");
    labelTitle->setFont(font);
    labelTitle->setAlignment(Qt::AlignCenter);
    labelTitle->setText("Sys");

    labelModeText = new QLabel(this);
    labelModeText->setGeometry(50,200,250,50);
    labelModeText->setStyleSheet("color: white;");
    labelModeText->setFont(font);
    labelModeText->setAlignment(Qt::AlignCenter);
    labelModeText->setText("Sys Mode: ");

    labelModeButton = new QLabel(this);
    labelModeButton->setGeometry(350,100,250,250);
    labelModeButton->setFont(font);
    labelModeButton->setAlignment(Qt::AlignCenter);
    labelModeButton->setStyleSheet("background-color: blue; color: white;");

    customButtonSave = new CustomButtonSave(this);
    customButtonCancel = new CustomButtonCancel(this);

    update();
}

void PageDebugSys::update()
{
#if DEVICE
    if(instance.guiApi.glucoseGetSysOprData(&instance.sysData) == GAPI_SUCCESS)
    {
        if(instance.sysData.opr_mode == 0)
        {
            labelModeButton->setText("Normal");
            labelModeButton->setStyleSheet("background-color: white; color: black;");
        }
        else if(instance.sysData.opr_mode == 1)
        {
            labelModeButton->setText("Test");
            labelModeButton->setStyleSheet("background-color: red; color: white;");
        }
    }
    else
    {
        labelModeButton->setText("SysData Get Fail");
    }
#else
    labelModeButton->setText("Not Device");
#endif

}

void PageDebugSys::pageShow()
{
    update();
}

void PageDebugSys::pageHide()
{
    emit signalShowPageNum(PAGE_DEBUG);
}

void PageDebugSys::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonSave->geometry(),ev))
    {
#if DEVICE
        instance.guiApi.glucoseSetSysOprData(&instance.sysData);
#endif
        pageHide();
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        pageHide();
    }

    if(instance.touchCheck(labelModeButton->geometry(),ev))
    {
        if(instance.sysData.opr_mode == 0)
            instance.sysData.opr_mode = 1;
        else if(instance.sysData.opr_mode == 1)
            instance.sysData.opr_mode = 0;

        update();
    }
}
