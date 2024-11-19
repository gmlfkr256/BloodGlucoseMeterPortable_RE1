#include "custombuttoninput.h"

CustomButtonInput::CustomButtonInput(QWidget *parent) : CustomButton(parent)
{
    this->setGeometry(0,390,320,90);
    init();
}

void CustomButtonInput::init()
{
    labelButtonInput  = new QLabel(this);
    labelButtonInput->setGeometry(0,0,this->width(),this->height());
    labelButtonInput->setAlignment(Qt::AlignCenter);

    update();
}

void CustomButtonInput::update()
{
    labelButtonInput->setFont(textResource.getFont(CUSTOM_BUTTON,"labelButtonInput"));
    labelButtonInput->setText(textResource.getText(CUSTOM_BUTTON,"labelButtonInput").at(0));

    switch (instance.getDeviceColor())
    {
    case COLOR_DEFAULT:
        labelButtonInput->setStyleSheet("background-color: #212121; color: #ffffff;");
        break;
    case COLOR_BLUE:
        break;
    case COLOR_RED:
        break;
    }
}
