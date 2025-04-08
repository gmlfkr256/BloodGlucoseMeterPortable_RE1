#include "pageselectuser.h"

PageSelectUser::PageSelectUser(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageSelectUser::init()
{
    setBgTopHide();

    labelTitle = new QLabel(this);
    labelTitle->setGeometry(154,325,332,45);
    labelTitle->setAlignment(Qt::AlignCenter);
    labelTitle->setStyleSheet("color: #808080;");

    for(int i=0; i<USER_MAX; i++)
    {
        labelUserImg[i] = new QLabel(this);
        labelUserText[i] = new QLabel(this);
        labelUserText[i]->setAlignment(Qt::AlignCenter);
        labelUserText[i]->setStyleSheet("color:#000000;");

        if(i==0)
        {
            labelUserImg[0]->setGeometry(75,98,245,215);
            labelUserText[0]->setGeometry(140,248,116,45);
        }
        else if(i==1)
        {
            labelUserImg[1]->setGeometry(320,98,245,215);
            labelUserText[1]->setGeometry(382,248,122,45);
        }
    }


    update();
}

void PageSelectUser::update()
{
    labelTitle->setFont(textResource.getFont(PAGE_SELECT_USER,"labelTitle"));
    labelTitle->setText(textResource.getText(PAGE_SELECT_USER,"labelTitle").at(0));

    for(int i=0; i<USER_MAX; i++)
    {
        labelUserText[i]->setFont(textResource.getFont(PAGE_SELECT_USER,"labelUserText"));
        labelUserText[i]->setText(textResource.getText(PAGE_SELECT_USER,"labelUserText").at(i));
        instance.pixLoad(labelUserImg[i],false,strDirPath,"/buttonUser"+QString::number(i)+".png");
    }
}

void PageSelectUser::pageShow()
{
    nLabelNumber = -1;
    update();
}

void PageSelectUser::pageHide()
{

}

void PageSelectUser::mousePressEvent(QMouseEvent *ev)
{
    for(int i=0; i<USER_MAX; i++)
    {
        if(instance.touchCheck(labelUserImg[i]->geometry(),ev))
        {
            //instance.actUserLogin(i);
            instance.setUserNumber(i);
            nLabelNumber = i;
            instance.pixLoad(labelUserImg[i],false,strDirPath,"/buttonUser"+QString::number(i)+"Press.png");
        }
    }
}

void PageSelectUser::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)
    if(nLabelNumber!=-1)
    {
        instance.pixLoad(labelUserImg[nLabelNumber],false,strDirPath,"/buttonUser"+QString::number(nLabelNumber)+".png");
        nLabelNumber = -1;

        if(!bIsOneClick)
        {
            bIsOneClick = true;
            QTimer::singleShot(300,this,[=](){
                emit signalShowPageNum(PAGE_PASSWORD_ALLCHAT);
                bIsOneClick = false;
            });
        }
    }
}
