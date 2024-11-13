#include "custombuttoncancel.h"

CustomButtonCancel::CustomButtonCancel(QWidget *parent) : CustomButton(parent)
{
    this->setGeometry(0,390,320,90);
    init();
}

void CustomButtonCancel::init()
{
    labelButtonCancel = new QLabel(this);
    labelButtonCancel->setGeometry(0,0,this->width(),this->height());
    labelButtonCancel->setAlignment(Qt::AlignCenter);

    update();
}

void CustomButtonCancel::update()
{
    labelButtonCancel->setFont(textResource.getFont(CUSTOM_BUTTON,"labelButtonCancel"));
    labelButtonCancel->setText(textResource.getText(CUSTOM_BUTTON,"labelButtonCancel").at(0));

    switch (instance.getDeviceColor())
    {
    case COLOR_DEFAULT:
        labelButtonCancel->setStyleSheet("background-color: #212121; color: #ffffff;");
        break;
    case COLOR_BLUE:
        break;
    case COLOR_RED:
        break;
    }

    //int x = bIsLong ? 0 : 320;
    int width = bIsLong ? 640 : 320;

    this->setGeometry(0,390,width,90);
    labelButtonCancel->setGeometry(0,0,this->width(),this->height());
}

void CustomButtonCancel::setLongWidth(bool bIsLong)
{
    this->bIsLong = bIsLong;
    update();
}
