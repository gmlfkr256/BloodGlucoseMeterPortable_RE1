#include "custombuttoncancel.h"

CustomButtonCancel::CustomButtonCancel(QWidget *parent) : CustomButton(parent)
{
    this->setGeometry(0,390,320,90);
    init();
}

void CustomButtonCancel::init()
{
    labelButtonCancel = new QLabel(this);
    labelButtonCancel->setGeometry(this->geometry());

    update();
}

void CustomButtonCancel::update()
{
    labelButtonCancel->setFont(textResource.getFont(CUSTOM_BUTTON,"labelButtonCancel"));
    labelButtonCancel->setText(textResource.getText(CUSTOM_BUTTON,"labelButtonCancel").at(0));

    switch (instance.getDeviceColor())
    {
    case COLOR_DEFAULT:
        labelButtonCancel->setStyleSheet("background-color: #ffffff; color: #ffffff;");
        break;
    case COLOR_BLUE:
        break;
    case COLOR_RED:
        break;
    }

    int x, width;

    if(bIsLong)
        x = 0, width = 640;
    else
        x = 320, width = 320;

    this->setGeometry(x,390,width,90);
    labelButtonCancel->setGeometry(this->geometry());
}

void CustomButtonCancel::setLongWidth(bool bIsLong)
{
    this->bIsLong = bIsLong;
    update();
}
