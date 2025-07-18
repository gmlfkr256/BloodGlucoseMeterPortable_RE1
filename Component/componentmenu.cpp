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

    instance.pixLoad(labelMenu,false,strDirPath,pngPath);
}

void ComponentMenu::mousePressEvent(QMouseEvent* ev)
{
    if(instance.currentPage==PAGE_HISTORY_RESULT)
        return;

    if(instance.touchCheck(this->rect(),ev))
    {
        instance.isComMenuCheck = true;
        emit signalShowPageNum(PAGE_MENU);
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
