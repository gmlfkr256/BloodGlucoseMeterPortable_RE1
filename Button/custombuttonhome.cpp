#include "custombuttonhome.h"

CustomButtonHome::CustomButtonHome(QWidget *parent) : CustomButton(parent)
{
    this->setGeometry(0,390,320,90);
    init();
}

void CustomButtonHome::init()
{
    labelButtonHome = new QLabel(this);
    labelButtonHome->setGeometry(0,0,this->width(),this->height());
    labelButtonHome->setAlignment(Qt::AlignCenter);

    update();
}

void CustomButtonHome::update()
{
    labelButtonHome->setFont(textResource.getFont(CUSTOM_BUTTON,"labelButtonCancel"));
    labelButtonHome->setText(textResource.getText(CUSTOM_BUTTON,"labelButtonHome").at(0));

    switch (instance.getDeviceColor())
    {
    case COLOR_DEFAULT:
        labelButtonHome->setStyleSheet("background-color: #212121; color: #ffffff;");
        break;
    case COLOR_BLUE:
        break;
    case COLOR_RED:
        break;
    }
}
