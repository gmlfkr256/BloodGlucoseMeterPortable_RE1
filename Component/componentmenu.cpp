#include "componentmenu.h"

ComponentMenu::ComponentMenu(QWidget *parent) : CustomComponent(parent)
{
    this->setGeometry(492,0,64,73);
    init();
}

void ComponentMenu::init()
{
    labelMenu = new QLabel(this);
    labelMenu->setGeometry(14,18,34,36);
    update();
}

void ComponentMenu::update()
{
    QString pngPath = "/menuButton.png";

    QPixmap pixmap = instance.pixLoad(false,strDirPath,pngPath);
    labelMenu->setPixmap(pixmap.copy());
}

void ComponentMenu::mousePressEvent(QMouseEvent* ev)
{
    if(instance.touchCheck(this->rect(),ev))
    {
        emit signalComMenuClick();
    }
}

void ComponentMenu::pageShow()
{
    this->show();
}

void ComponentMenu::pageHide()
{
    this->hide();
}
