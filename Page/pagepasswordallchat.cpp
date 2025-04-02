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

    labelButtonHide = new QLabel(this);
    labelButtonHide->setText("V");
    labelButtonHide->setStyleSheet("background-color:red; color: white;");
    //labelButtonHide->setGeometry()

    labelPasswordBg = new QLabel(this);
    //labelPasswordBg->setGeometry(116,133,303,85);
    labelPasswordBg->setGeometry(10,133,410,85);
    labelPasswordBg->setFont(textResource.getFont(PAGE_PASSWORD,"labelButtonNum"));
    //labelPasswordBg->setText("123456789012");
    QFont font = labelPasswordBg->font();
    font.setPointSize(instance.pixelToPoint(30));
    labelPasswordBg->setFont(font);
    labelPasswordBg->setText("@@@@@@@@@@@@");
    labelPasswordBg->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    labelPasswordBg->setStyleSheet("color: black; border: 1px solid black; border-radius:5px;");

    labelButtonOK = new QLabel(this);
    labelButtonOK->setGeometry(427,133,98,85);
    labelButtonOKText = new QLabel(this);
    labelButtonOKText->setGeometry(labelButtonOK->geometry());
    labelButtonOKText->setAlignment(Qt::AlignCenter);

    labelButtonDel = new QLabel(this);
    labelButtonDel->setGeometry(336,152,67,47);

    labelButtonCancel = new QLabel(this);
    labelButtonCancel->setGeometry(560,26,50,50);

    labelButtonCancelText = new QLabel(this);
    labelButtonCancelText->setGeometry(labelButtonCancel->geometry());
    labelButtonCancelText->setAlignment(Qt::AlignCenter);

    comKeyboard = new ComponentPasswordKeyboard(this);

    initConnect();

    update();
}

void PagePasswordAllChat::initConnect()
{
    connect(comKeyboard,&ComponentPasswordKeyboard::signalKeyClick,this,&PagePasswordAllChat::updatePassword);
}

void PagePasswordAllChat::updatePassword(QString strKey)
{
    labelPasswordBg->setText(strKey);
}

void PagePasswordAllChat::update()
{
    labelTitle->setFont(textResource.getFont(PAGE_PASSWORD,"labelTitle"));
    labelTitle->setText(textResource.getText(PAGE_PASSWORD,"labelTitle").at(instance.getPasswordStatus()));
    labelTitleSub->setFont(textResource.getFont(PAGE_PASSWORD,"labelTitleSub"));
    labelTitleSub->setText(textResource.getText(PAGE_PASSWORD,"labelTitleSub").at(instance.getPasswordStatus()));

    //instance.pixLoad(labelPasswordBg,false,strDirPath,"/passwordNumBg.png");

    instance.pixLoad(labelButtonOK,false,strDirPath,"/buttonOK.png");

    labelButtonOKText->setStyleSheet("color: #ffffff;");
    labelButtonOKText->setFont(textResource.getFont(PAGE_PASSWORD,"labelButtonOKText"));
    labelButtonOKText->setText(textResource.getText(PAGE_PASSWORD,"labelButtonOKText").at(0));

    instance.pixLoad(labelButtonCancel,false,strDirPath,"/buttonCancel.png");

    instance.pixLoad(labelButtonDel,false,strDirPath,"/buttonDelete.png");



    if(instance.getPasswordStatus() != PASSWORD_LOGIN)
    {
        labelButtonCancel->show();
    }
    else
    {
        labelButtonCancel->hide();
    }
}

void PagePasswordAllChat::pageShow()
{

}

void PagePasswordAllChat::pageHide()
{

}

void PagePasswordAllChat::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
}


