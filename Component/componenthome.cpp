#include "componenthome.h"

ComponentHome::ComponentHome(QWidget *parent) : CustomComponent(parent)
{
    this->setGeometry(372,0,70,80);
    init();
}

void ComponentHome::init()
{
    labelHome = new QLabel(this);
    labelHome->setGeometry(14,15,40,40);

    update();
}

void ComponentHome::update()
{
    QString pngPath;

    QHash<UserNum,QString> userPngPaths
    {
        {USER_1, "/homeButton1.png"},
        {USER_2, "/homeButton2.png"},
        {USER_MAX, "/homeButton0.png"}
    };

    pngPath = userPngPaths.value(instance.getUserNumber(),"/homeButton1.png");

    //qDebug()<<pngPath;
    instance.pixLoad(labelHome,false,strDirPath,pngPath);
}

void ComponentHome::mousePressEvent(QMouseEvent *ev)
{
    if(instance.currentPage==PAGE_HISTORY_RESULT)
        return;

    if(instance.touchCheck(this->rect(),ev))
    {
        emit singalShowPageNum(PAGE_HOME);
    }
}

void ComponentHome::pageShow()
{
    this->show();
}

void ComponentHome::pageHide()
{
    this->hide();
}
