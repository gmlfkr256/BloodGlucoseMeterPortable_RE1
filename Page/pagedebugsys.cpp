#include "pagedebugsys.h"

PageDebugSys::PageDebugSys(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    this->setStyleSheet("background-color: black;");
    init();
}

void PageDebugSys::init()
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
    labelTitle->setText("Sys");

    labelModeText = new QLabel(this);
    labelModeText->setGeometry(50,200,250,50);
    labelModeText->setStyleSheet("color: white;");
    labelModeText->setFont(font);
    labelModeText->setAlignment(Qt::AlignCenter);
    labelModeText->setText("Sys Mode: ");

    //hrkim 20261029 모드별 버튼 3개를 오른쪽에 세로로 — 처음엔 모두 흰 바탕·검은 글자 (XW-0478)
    QStringList listModeName = {"Normal","Test","Self"};
    for(int i=0; i<3; i++)
    {
        labelModeButton[i] = new QLabel(this);
        labelModeButton[i]->setGeometry(350,90+i*100,250,80);
        labelModeButton[i]->setFont(font);
        labelModeButton[i]->setAlignment(Qt::AlignCenter);
        labelModeButton[i]->setText(listModeName.at(i));
        labelModeButton[i]->setStyleSheet("background-color: white; color: black;");
    }

    customButtonSave = new CustomButtonSave(this);
    customButtonCancel = new CustomButtonCancel(this);

    update();
}

void PageDebugSys::update()
{
#if DEVICE
    //hrkim 20261029 겟한(또는 누른) 모드만 빨강 바탕·흰 글자, 나머지는 흰 바탕·검은 글자로 되돌림 (XW-0478)
    for(int i=0; i<3; i++)
    {
        if(bIsGetSysData && instance.sysData.opr_mode == (unsigned int)i)
            labelModeButton[i]->setStyleSheet("background-color: red; color: white;");
        else
            labelModeButton[i]->setStyleSheet("background-color: white; color: black;");
    }
#else
    labelModeText->setText("Not Device");
#endif

}

void PageDebugSys::pageShow()
{
    if(instance.guiApi.glucoseGetSysOprData(&instance.sysData) == GAPI_SUCCESS)
    {
        bIsGetSysData = true;
        labelModeText->setText("Sys Mode: ");
    }
    else
    {
        bIsGetSysData = false;
        labelModeText->setText("SYS Fail");    //hrkim 20261029 버튼이 3개라 실패 표시는 왼쪽 글자로 (XW-0478)
    }
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
        if(bIsGetSysData)   //hrkim 20261029 겟 실패면 모르는 값을 SET 하지 않음 (XW-0478)
            instance.guiApi.glucoseSetSysOprData(&instance.sysData);
#endif
        pageHide();
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        pageHide();
    }

    //hrkim 20261029 회전식 → 누른 버튼의 모드로 바로 선택 (인덱스 = opr_mode), 겟 실패면 고르지 않음 (XW-0478)
    for(int i=0; i<3; i++)
    {
        if(bIsGetSysData && instance.touchCheck(labelModeButton[i]->geometry(),ev))
        {
            instance.sysData.opr_mode = i;
            update();
        }
    }
}
