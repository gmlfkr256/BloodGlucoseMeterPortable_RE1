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

    strPathPngSound = "/menuButtonSound.png";
    strPathPngDateTime = "/menuButtonDateTime.png";
    strPathPngReverse = "/menuButtonReverse.png";
    strPathPngHistory = "/menuButtonHistory.png";
    strPathPngSleep = "/menuButtonSleep.png";
    strPathPngTranslation = "/menuButtonTranslation.png";
    strPathPngUpgrade = "/menuButtonUpgrade.png";
    strPathPngColor = "/menuButtonColor.png";
    strPathPngCalibration = "/menuButtonCalibration.png";
    strPathPngDeviceInfo = "/menuButtonDeviceInfo.png";
    strPathPngDebug = "/menuButtonDebug.png";
    strPathPngThreshold = "/menuButtonThreshold.png";
    strPathPngReset = "/menuButtonReset.png";
    strPathPngUser = "/menuButtonUser.png";

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

    //strPathPngColor
    switch(selectPage)
    {
    case MENU_PAGE_0:
        strButtonPathPng[0] = strPathPngCalibration;
        strButtonPathPng[1] = strPathPngThreshold;
        strButtonPathPng[2] = strPathPngHistory;
        strButtonPathPng[3] = strPathPngSound;
        strButtonPathPng[4] = strPathPngSleep;
        strButtonPathPng[5] = strPathPngReverse;
        break;
    case MENU_PAGE_1:
        strButtonPathPng[0] = strPathPngDateTime;
        strButtonPathPng[1] = strPathPngTranslation;
        strButtonPathPng[2] = strPathPngUpgrade;
        strButtonPathPng[3] = strPathPngDeviceInfo;
        strButtonPathPng[4] = strPathPngReset;
        strButtonPathPng[5] = strPathPngUser;
        break;
    case MENU_PAGE_MAX:
        break;
    }

    for(int i=0; i<6; i++)
    {
        if(!strButtonPathPng[i].isEmpty())
        {
            instance.pixLoad(labelButton[i],false,strDirPath,strButtonPathPng[i]);
        }
        else
        {
            qDebug()<<"MENU_PAGE_NUM: "+QString::number(selectPage)+"strButtonPath["+QString::number(i)+"] isEmpty";
        }
    }
}

void PageMenu::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(labelArrowLeftTouch->geometry(),ev))
    {
        int nSelectPage = selectPage;
        nSelectPage--;
        if(nSelectPage<MENU_PAGE_0)
            selectPage = MENU_PAGE_1;

        update();
    }

    if(instance.touchCheck(labelArrowRightTouch->geometry(),ev))
    {
        int nSelectPage = selectPage;
        nSelectPage++;
        if(nSelectPage>MENU_PAGE_1)
            selectPage = MENU_PAGE_0;

        update();
    }
}

void PageMenu::pageShow()
{

}

void PageMenu::pageHide()
{

}
