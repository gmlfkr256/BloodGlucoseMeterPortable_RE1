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
        labelButtonText[i] = new QLabel(this);
        labelButtonText[i]->setAlignment(Qt::AlignCenter);
        if(i<3)
        {
            labelButton[i]->setGeometry(81+i*163,91,151,179);
        }
        else
        {
            labelButton[i]->setGeometry(81+(i-3)*163,282,151,179);
        }

        // labelButton[i]의 아래에 텍스트 라벨 위치를 설정
        QRect buttonRect = labelButton[i]->geometry();
        labelButtonText[i]->setGeometry(
                    buttonRect.x(),                   // labelButton과 동일한 x 좌표
                    buttonRect.y() + buttonRect.height()-70,
                    buttonRect.width(),               // 버튼과 동일한 너비
                    64                                // 고정된 높이
                    );
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

    for(QLabel *labelButtonText : this->labelButtonText)
    {
        labelButtonText->setFont(textResource.getFont(PAGE_MENU,"labelButtonText"));
        labelButtonText->setStyleSheet("color: #000000;");
    }

    listPageNum.clear();

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

        labelButtonText[0]->setText(textResource.getText(PAGE_MENU,"labelButtonText").at(0));
        labelButtonText[1]->setText(textResource.getText(PAGE_MENU,"labelButtonText").at(1));
        labelButtonText[2]->setText(textResource.getText(PAGE_MENU,"labelButtonText").at(2));
        labelButtonText[3]->setText(textResource.getText(PAGE_MENU,"labelButtonText").at(3));
        labelButtonText[4]->setText(textResource.getText(PAGE_MENU,"labelButtonText").at(4));
        labelButtonText[5]->setText(textResource.getText(PAGE_MENU,"labelButtonText").at(5));

        listPageNum = {
            PAGE_CALI_CHECK,//PAGE_CALIBRATION,
            PAGE_THRESHOLD,
            PAGE_HISTORY,
            PAGE_SOUND,
            PAGE_SLEEP,
            PAGE_REVERSE
        };

        break;
    case MENU_PAGE_1:
        strButtonPathPng[0] = strPathPngDateTime;
        strButtonPathPng[1] = strPathPngTranslation;
        strButtonPathPng[2] = strPathPngUpgrade;
        strButtonPathPng[3] = strPathPngDeviceInfo;
        strButtonPathPng[4] = strPathPngReset;
        strButtonPathPng[5] = strPathPngUser;

        labelButtonText[0]->setText(textResource.getText(PAGE_MENU,"labelButtonText").at(6));
        labelButtonText[1]->setText(textResource.getText(PAGE_MENU,"labelButtonText").at(8));
        labelButtonText[2]->setText(textResource.getText(PAGE_MENU,"labelButtonText").at(9));
        labelButtonText[3]->setText(textResource.getText(PAGE_MENU,"labelButtonText").at(10));
        labelButtonText[4]->setText(textResource.getText(PAGE_MENU,"labelButtonText").at(11));
        labelButtonText[5]->setText(textResource.getText(PAGE_MENU,"labelButtonText").at(12));

        listPageNum = {
            PAGE_DATETIME,
            PAGE_TRANS,
            PAGE_UPGRADE,
            PAGE_DEVICEINFO,
            PAGE_INIT,
            PAGE_USERINFO
        };
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
        else
            selectPage = static_cast<MenuPageIndex>(nSelectPage);

        update();
    }

    if(instance.touchCheck(labelArrowRightTouch->geometry(),ev))
    {
        int nSelectPage = selectPage;
        nSelectPage++;
        if(nSelectPage>MENU_PAGE_1)
            selectPage = MENU_PAGE_0;
        else
            selectPage = static_cast<MenuPageIndex>(nSelectPage);

        update();
    }

    for(int i=0; i<6; i++)
    {
        if(instance.touchCheck(labelButton[i]->geometry(),ev))
        {
            if(i>=0 && i<listPageNum.size())
                emit signalShowPageNum(listPageNum.at(i));
            else
                qDebug()<<"[fail] Invalid listPageNum index: "<<i;
        }
    }
}

void PageMenu::pageShow()
{
    if(instance.isComMenuCheck == true)
    {
        selectPage = MENU_PAGE_0;
        instance.isComMenuCheck = false;
    }

    update();
}

void PageMenu::pageHide()
{

}
