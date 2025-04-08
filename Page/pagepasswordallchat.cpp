#include "pagepasswordallchat.h"

PagePasswordAllChat::PagePasswordAllChat(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PagePasswordAllChat::init()
{
    setBgTopHide();

    labelTitle = new QLabel(this);
    labelTitle->setGeometry(0,30,640,50);
    labelTitle->setAlignment(Qt::AlignCenter);
    labelTitle->setStyleSheet("color: #000000;");
    labelTitleSub = new QLabel(this);
    labelTitleSub->setGeometry(0,84,640,40);
    labelTitleSub->setAlignment(Qt::AlignCenter);
    labelTitleSub->setStyleSheet("color: #808080");

    labelPasswordBg = new QLabel(this);
    labelPasswordBg->setGeometry(40,133,560,85);
    labelPasswordBg->setFont(textResource.getFont(PAGE_PASSWORD_ALLCHAT,"labelButtonNum"));
    QFont font = labelPasswordBg->font();
    font.setPointSize(instance.pixelToPoint(40));
    labelPasswordBg->setFont(font);
    //labelPasswordBg->setText("@@@@@@@@@@@@");
    labelPasswordBg->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    labelPasswordBg->setStyleSheet("color: black; border: 1px solid black; border-radius:5px; padding-left: 10px;");

    labelButtonShowHide = new QLabel(this);
    labelButtonShowHide->setGeometry(515,133,85,85);
    //labelButtonShowHide->setStyleSheet("color: black;");
    //labelButtonShowHide->setAlignment(Qt::AlignCenter);
    //labelButtonShowHide->setText("✓");
    //labelButtonShowHide->setFont(textResource.getFont(PAGE_PASSWORD_ALLCHAT,"labelButtonNum"));

    comKeyboard = new ComponentPasswordKeyboard(this);

    initConnect();

    update();
    updateShowHide();
}

void PagePasswordAllChat::initConnect()
{
    connect(comKeyboard,&ComponentPasswordKeyboard::signalKeyClick,this,&PagePasswordAllChat::updatePassword);
    connect(this,&PagePasswordAllChat::signalPasswordDel,comKeyboard,&ComponentPasswordKeyboard::deleteLastKey);
    connect(comKeyboard,&ComponentPasswordKeyboard::signalCheckLogin,this,&PagePasswordAllChat::checkLogin);
    connect(this,&PagePasswordAllChat::signalPasswordShowHide,comKeyboard,&ComponentPasswordKeyboard::functionShowHide);
    connect(comKeyboard,&ComponentPasswordKeyboard::signalCancel,this,&PagePasswordAllChat::pageHide);
}

void PagePasswordAllChat::updatePassword(QString strKey)
{
    labelPasswordBg->setText(strKey);
}

void PagePasswordAllChat::update()
{
    labelTitle->setFont(textResource.getFont(PAGE_PASSWORD_ALLCHAT,"labelTitle"));
    labelTitle->setText(textResource.getText(PAGE_PASSWORD_ALLCHAT,"labelTitle").at(instance.getPasswordStatus()));
    labelTitleSub->setFont(textResource.getFont(PAGE_PASSWORD_ALLCHAT,"labelTitleSub"));
    labelTitleSub->setText(textResource.getText(PAGE_PASSWORD_ALLCHAT,"labelTitleSub").at(instance.getPasswordStatus()));
}

void PagePasswordAllChat::pageShow()
{
    comKeyboard->clearKey();
    updatePassword("");
    update();
}

void PagePasswordAllChat::pageHide()
{
    PageNum pageNum = PAGE_MAX;

    if(instance.getPasswordStatus() == PASSWORD_LOGIN)
    {
        pageNum = PAGE_SELECT_USER;
    }
    else
    {
        pageNum = PAGE_USERINFO;
    }

    emit signalShowPageNum(pageNum);
}

void PagePasswordAllChat::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(labelButtonShowHide->geometry(),ev))
    {
        emit signalPasswordShowHide();

    }
}

void PagePasswordAllChat::checkLogin()
{
    emit signalShowPageNum(PAGE_PASSWORD_CONFIRM);
}

void PagePasswordAllChat::updateShowHide(bool bIsShow)
{
    if(bIsShow)
    {
        instance.pixLoad(labelButtonShowHide,false,strDirPath,"/buttonShow.png");
    }
    else
    {
        instance.pixLoad(labelButtonShowHide,false,strDirPath,"/buttonHide.png");
    }
}

