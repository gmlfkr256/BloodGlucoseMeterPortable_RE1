#include "custombuttonreboot.h"

CustomButtonReboot::CustomButtonReboot(QWidget *parent) : CustomButton(parent)
{
    this->setGeometry(320,390,320,90);
    init();
}

void CustomButtonReboot::init()
{
    labelButtonReboot = new QLabel(this);
    labelButtonReboot->setGeometry(0,0,this->width(),this->height());
    labelButtonReboot->setAlignment(Qt::AlignCenter);

    update();
}

void CustomButtonReboot::update()
{
    labelButtonReboot->setFont(textResource.getFont(CUSTOM_BUTTON,"labelButtonReboot"));
    labelButtonReboot->setText(textResource.getText(CUSTOM_BUTTON,"labelButtonReboot").at(0));

    labelButtonReboot->setStyleSheet("background-color: #077bdd; color: #ffffff;");
}
