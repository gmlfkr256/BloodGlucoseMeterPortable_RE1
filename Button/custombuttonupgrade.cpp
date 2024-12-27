#include "custombuttonupgrade.h"

CustomButtonUpgrade::CustomButtonUpgrade(QWidget *parent) : CustomButton(parent)
{
    this->setGeometry(0,390,640,90);
    init();
}

void CustomButtonUpgrade::init()
{
    labelButtonUpgrade = new QLabel(this);
    labelButtonUpgrade->setGeometry(0,0,this->width(),this->height());
    labelButtonUpgrade->setAlignment(Qt::AlignCenter);

    update();
}

void CustomButtonUpgrade::update()
{
    labelButtonUpgrade->setFont(textResource.getFont(CUSTOM_BUTTON,"labelButtonUpgrade"));
    labelButtonUpgrade->setText(textResource.getText(CUSTOM_BUTTON,"labelButtonUpgrade").at(0));

    labelButtonUpgrade->setStyleSheet("background-color: #077bdd; color: #ffffff;");
}
