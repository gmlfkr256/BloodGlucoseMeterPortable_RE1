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

    fontMapping();
    update();
}

void PageTrans::fontMapping()
{
    fontMap[KR] = textResource.getFont(PAGE_TRANS,"fontSuit");
    fontMap[EN] = textResource.getFont(PAGE_TRANS,"fontSuit");
    fontMap[JP] = textResource.getFont(PAGE_TRANS,"fontJP");
    fontMap[SC] = textResource.getFont(PAGE_TRANS,"fontSC");
    fontMap[TC] = textResource.getFont(PAGE_TRANS,"fontTC");
    fontMap[ES] = textResource.getFont(PAGE_TRANS,"fontSuit");
}

void PageTrans::update()
{
    customButtonOK->update();
    customButtonCancel->update();

    labelButton[0]->setStyleSheet("background-color: white; border-radius: 15px; border: 3px solid #eeeeee; padding-left: 30px;");
    labelButton[1]->setStyleSheet("background-color: white; border-radius: 15px; border: 3px solid #077bdd; padding-left: 30px;");
    labelButton[2]->setStyleSheet("background-color: white; border-radius: 15px; border: 3px solid #eeeeee; padding-left: 30px;");

    instance.pixLoad(labelArrowTop,false,strDirPath,"/arrowTop.png");
    instance.pixLoad(labelArrowDown,false,strDirPath,"/arrowDown.png");

    instance.pixLoad(labelButtonCheck,false,strDirPath,"/check.png");

    instance.pixLoad(labelButtonGradientTop,false,strDirPath,"/gradientTop.png");
    instance.pixLoad(labelButtonGradientDown,false,strDirPath,"/gradientDown.png");

    deviceLan = instance.getDeviceLanguage();

    selectedIndex = deviceLan;

    updateButton();
}

void PageTrans::updateButton()
{
    int total = LAN_MAX;
    int indexPrev = (selectedIndex - 1 + total) % total;
    int indexNext = (selectedIndex + 1) % total;

    labelButton[0]->setFont(fontMap.value(indexPrev));
    labelButton[1]->setFont(fontMap.value(selectedIndex));
    labelButton[2]->setFont(fontMap.value(indexNext));

    labelButton[0]->setText(textResource.getText(PAGE_TRANS,"lang").at(indexPrev));
    labelButton[1]->setText(textResource.getText(PAGE_TRANS,"lang").at(selectedIndex));
    labelButton[2]->setText(textResource.getText(PAGE_TRANS,"lang").at(indexNext));
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
    if(instance.touchCheck(labelArrowTop->geometry(),ev))
    {
        int total = LAN_MAX;
        selectedIndex = (selectedIndex - 1 + total) % total; // 순환 감소
        updateButton();
    }

    if(instance.touchCheck(labelArrowDown->geometry(),ev))
    {
        int total = LAN_MAX;
        selectedIndex = (selectedIndex + 1) % total; // 순환 증가
        updateButton();
    }

    if(instance.touchCheck(labelButtonGradientTop->geometry(),ev))
    {
        int total = LAN_MAX;
        selectedIndex = (selectedIndex - 1 + total) % total; // 순환 감소
        updateButton();
    }

    if(instance.touchCheck(labelButtonGradientDown->geometry(),ev))
    {
        int total = LAN_MAX;
        selectedIndex = (selectedIndex + 1) % total; // 순환 증가
        updateButton();
    }

    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        qDebug()<<"selectedIndex: "<<selectedIndex;
        instance.setDeviceLanguage(selectedIndex);
        pageHide();
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev))
    {
        pageHide();
    }
}


