#include "pagemenu.h"

PageMenu::PageMenu(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageMenu::init()
{
    for(int i=0; i<6; i++)
    {
        labelButton[i] = new QLabel(this);
        if(i<3)
            labelButton[i]->setGeometry(81+i*163,91,151,179);
        else
            labelButton[i]->setGeometry(81+(i-3)*163,282,151,179);
    }

    labelArrowLeft = new QLabel(this);
    labelArrowLeft->setGeometry(10,256,44,44);
    labelArrowLeftTouch = new QLabel(this);
    labelArrowLeftTouch->setGeometry(0,73,70,407);

    labelArrowRight = new QLabel(this);
    labelArrowRight->setGeometry(587,256,44,44);
    labelArrowRightTouch = new QLabel(this);
    labelArrowRightTouch->setGeometry(570,73,70,407);

    update();
}

void PageMenu::update()
{
    QString pngPath;
    QPixmap pixmap;

    pngPath = "/buttonArrowLeft.png";
    instance.pixLoad(labelArrowLeft,false,strDirPath,pngPath);

    pngPath = "/buttonArrowRight.png";
    instance.pixLoad(labelArrowRight,false,strDirPath,pngPath);
}

void PageMenu::mousePressEvent(QMouseEvent *ev)
{

}

void PageMenu::pageShow()
{

}

void PageMenu::pageHide()
{

}
