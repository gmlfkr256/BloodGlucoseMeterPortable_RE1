#include "pageupgrade.h"

PageUpgrade::PageUpgrade(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageUpgrade::init()
{
    labelText = new QLabel(this);
    labelText->setGeometry(0,158,640,52);
    labelText->setAlignment(Qt::AlignCenter);

    labelTextVersion = new QLabel(this);
    labelTextVersion->setGeometry(0,235,640,68);
    labelTextVersion->setAlignment(Qt::AlignCenter);

    customButtonUpgrade = new CustomButtonUpgrade(this);

    update();
}

void PageUpgrade::update()
{
    customButtonUpgrade->update();

    labelText->setFont(textResource.getFont(PAGE_UPGRADE,"labelText"));
    labelText->setText(textResource.getText(PAGE_UPGRADE,"labelText").at(0));

    labelTextVersion->setFont(textResource.getFont(PAGE_UPGRADE,"labelTextVersion"));
    labelTextVersion->setText(instance.getDeviceVersion(VERSION_FW));
}

void PageUpgrade::pageShow()
{
    update();
}

void PageUpgrade::pageHide()
{

}

void PageUpgrade::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonUpgrade->geometry(),ev))
    {
        emit signalShowPageNum(PAGE_UPGRADE_CONFIRM);
    }
}
