#include "custombuttonsave.h"

CustomButtonSave::CustomButtonSave(QWidget *parent) : CustomButton(parent)
{
    this->setGeometry(320,390,320,90);
    init();
}

void CustomButtonSave::init()
{
    labelButtonSave = new QLabel(this);
    labelButtonSave->setGeometry(0,0,this->width(),this->height());
    labelButtonSave->setAlignment(Qt::AlignCenter);

    update();
}

void CustomButtonSave::update()
{
    labelButtonSave->setFont(textResource.getFont(CUSTOM_BUTTON,"labelButtonSave"));
    labelButtonSave->setText(textResource.getText(CUSTOM_BUTTON,"labelButtonSave").at(0));

    switch (instance.getDeviceColor())
    {
    case COLOR_DEFAULT:
        labelButtonSave->setStyleSheet("background-color: #077bdd; color: #ffffff;");
        break;
    case COLOR_BLUE:
        break;
    case COLOR_RED:
        break;
    }
}
