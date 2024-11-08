#include "pagepassword.h"

PagePassword::PagePassword(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PagePassword::init()
{
    setBgTopHide();

    labelTitle = new QLabel(this);
    labelTitle->setGeometry(0,30,640,50);
    labelTitle->setAlignment(Qt::AlignCenter);
    labelTitle->setStyleSheet("color: #000000");
    labelTitleSub = new QLabel(this);
    labelTitleSub->setGeometry(0,84,640,40);
    labelTitleSub->setAlignment(Qt::AlignCenter);
    labelTitleSub->setStyleSheet("color: #808080");

    for(int i=0; i<10; i++)
    {
        labelButtonNum[i] = new QLabel(this);
        labelButtonNum[i]->setStyleSheet("background-color: #ffffff; border: 1px solid #ebebeb;");
        labelButtonNum[i]->setFont(textResource.getFont(PAGE_PASSWORD,"labelButtonNum"));
        labelButtonNum[i]->setAlignment(Qt::AlignCenter);
        labelButtonNum[i]->setText(QString::number(i));

        if(i<5)
        {
            labelButtonNum[i]->setGeometry(i*128,240,128,120);
        }
        else
        {
            labelButtonNum[i]->setGeometry((i-5)*128,360,128,120);
        }
    }

    labelPasswordBg = new QLabel(this);
    labelPasswordBg->setGeometry(116,133,303,85);

    for(int i=0; i<4; i++)
    {
        labelPasswordNum[i] = new QLabel(this);
        labelPasswordNum[i]->setGeometry(150+(i*42),163,26,26);
        labelPasswordNum[i]->hide();
    }

    labelButtonOK = new QLabel(this);
    labelButtonOK->setGeometry(427,133,98,85);

    labelButtonOKText = new QLabel(this);
    labelButtonOKText->setGeometry(labelButtonOK->geometry());
    labelButtonOKText->setStyleSheet("color: #ffffff;");
    labelButtonOKText->setAlignment(Qt::AlignCenter);

    labelButtonCancel = new QLabel(this);
    labelButtonCancel->setGeometry(336,152,67,47);

    update();
}

void PagePassword::update()
{
    labelTitle->setFont(textResource.getFont(PAGE_PASSWORD,"labelTitle"));
    labelTitle->setText(textResource.getText(PAGE_PASSWORD,"labelTitle").at(0));
    labelTitleSub->setFont(textResource.getFont(PAGE_PASSWORD,"labelTitleSub"));
    labelTitleSub->setText(textResource.getText(PAGE_PASSWORD,"labelTitleSub").at(0));

    QPixmap pixmap = instance.pixLoad(false,strDirPath,"/passwordNumBg.png");
    labelPasswordBg->setPixmap(pixmap.copy());

    pixmap = instance.pixLoad(false,strDirPath,"/buttonOK.png");
    labelButtonOK->setPixmap(pixmap.copy());

    labelButtonOKText->setFont(textResource.getFont(PAGE_PASSWORD,"labelButtonOKText"));
    labelButtonOKText->setText(textResource.getText(PAGE_PASSWORD,"labelButtonOKText").at(0));

    pixmap = instance.pixLoad(false,strDirPath,"/buttonCancel.png");
    labelButtonCancel->setPixmap(pixmap.copy());

    pixmap = instance.pixLoad(false,strDirPath,"/circlePassword.png");
    for(QLabel *label : labelPasswordNum)
    {
        label->setPixmap(pixmap.copy());
    }
}

void PagePassword::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(labelButtonCancel->geometry(),ev))
    {
        strPasswordNum.chop(1);
    }

    for(int i=0; i<10; i++)
    {
        if(instance.touchCheck(labelButtonNum[i]->geometry(),ev))
        {
            if(strPasswordNum.size()<4)
            {
                strPasswordNum.append(i);
            }
            labelButtonNum[i]->setStyleSheet("background-color: #077bdd; color: #ffffff; border: 1px solid #ebebeb;");
            nCheckButtonNum = i;
        }
    }

    updatePasswordNum();
}

void PagePassword::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);

    if(nCheckButtonNum != -1)
    {
        labelButtonNum[nCheckButtonNum]->setStyleSheet("background-color: #ffffff; color: #000000; border: 1px solid #ebebeb;");
        nCheckButtonNum = -1;
    }
}

void PagePassword::updatePasswordNum()
{
    QPixmap pixmapNull;
    QPixmap pixmap = instance.pixLoad(false,strDirPath,"/circelPassword.png");

    for(int i=0; i<4; i++)
    {
        if(i<strPasswordNum.size())
        {
            if(i== strPasswordNum.size()-1)
            {
                labelPasswordNum[i]->setPixmap(pixmapNull);
                labelPasswordNum[i]->setText(strPasswordNum.at(i));
            }
            else
            {
                labelPasswordNum[i]->setPixmap(pixmap);
                labelPasswordNum[i]->setText("");
            }

            labelPasswordNum[i]->show();
        }
        else
        {
            labelPasswordNum[i]->hide();
        }
    }
}
void PagePassword::pageShow()
{
    strPasswordNum.clear();
}

void PagePassword::pageHide()
{

}
