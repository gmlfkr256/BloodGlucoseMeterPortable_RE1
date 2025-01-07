#include "pagetrans.h"

PageTrans::PageTrans(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageTrans::init()
{
    labelWindow = new QLabel(this);
    labelWindow->setGeometry(0,73,640,317);
    labelWindow->setStyleSheet("background-color: gray;");

    for(int i=0; i<3; i++)
    {
        labelButton[i] = new QLabel(labelWindow);
        labelButton[i]->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    }

    labelButton[0]->setGeometry(40,-9,520,105);
    labelButton[1]->setGeometry(40,106,520,105);
    labelButton[2]->setGeometry(40,221,520,105);

    labelArrowTop = new QLabel(this);
    labelArrowTop->setGeometry(565,83,70,70);
    labelArrowDown = new QLabel(this);
    labelArrowDown->setGeometry(565,310,70,70);

    labelButtonCheck = new QLabel(this);
    labelButtonCheck->setGeometry(495,214,35,35);

    labelButtonGradientTop = new QLabel(this);
    labelButtonGradientTop->setGeometry(40,73,520,96);
    labelButtonGradientDown = new QLabel(this);
    labelButtonGradientDown->setGeometry(40,294,520,96);

    customButtonOK = new CustomButtonOK(this);
    customButtonCancel = new CustomButtonCancel(this);

    update();
}

void PageTrans::update()
{
    /*
    labelButton[0]->setStyleSheet("background-color: white; border-radius: 15px; border: solid 3px #eeeeee; padding-left: 30px;");
    labelButton[1]->setStyleSheet("background-color: white; border-radius: 15px; border: solid 3px #077bdd; padding-left: 30px;");
    labelButton[2]->setStyleSheet("background-color: white; border-radius: 15px; border: solid 3px #eeeeee; padding-left: 30px;");
    */
    labelButton[0]->setStyleSheet("background-color: white; border-radius: 15px; border: 3px solid #eeeeee; padding-left: 30px;");
    labelButton[1]->setStyleSheet("background-color: white; border-radius: 15px; border: 3px solid #077bdd; padding-left: 30px;");
    labelButton[2]->setStyleSheet("background-color: white; border-radius: 15px; border: 3px solid #eeeeee; padding-left: 30px;");


    instance.pixLoad(labelArrowTop,false,strDirPath,"/arrowTop.png");
    instance.pixLoad(labelArrowDown,false,strDirPath,"/arrowDown.png");

    instance.pixLoad(labelButtonCheck,false,strDirPath,"/check.png");

    instance.pixLoad(labelButtonGradientTop,false,strDirPath,"/gradientTop.png");
    instance.pixLoad(labelButtonGradientDown,false,strDirPath,"/gradientDown.png");
}

void PageTrans::pageShow()
{
    update();
}

void PageTrans::pageHide()
{
    emit signalShowPageNum(PAGE_MENU);
}

void PageTrans::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        pageHide();
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        pageHide();
    }
}


