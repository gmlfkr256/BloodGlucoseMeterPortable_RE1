#include "custombuttonok.h"

CustomButtonOK::CustomButtonOK(QWidget *parent) : CustomButton(parent)
{
    this->setGeometry(320,390,320,90);
    init();
}

void CustomButtonOK::init()
{
    labelButtonOk = new QLabel(this);
    labelButtonOk->setGeometry(0,0,this->width(),this->height());

    update();
}

void CustomButtonOK::update()
{
    labelButtonOk->setFont(textResource.getFont(CUSTOM_BUTTON,"labelButtonOK"));
    labelButtonOk->setText(textResource.getText(CUSTOM_BUTTON,"labelButtonOK").at(0));

    qDebug()<<"customButtonOK";
    switch (instance.getDeviceColor())
    {
    case COLOR_DEFAULT:
        labelButtonOk->setStyleSheet("background-color: #077bdd; color: #ffffff;");
        break;
    case COLOR_BLUE:
        break;
    case COLOR_RED:
        break;
    }

    int x, width;

    if(bIsLong)
    {
        x = 0;
        width = 640;
    }
    else
    {
        x = 320;
        width = 320;
    }

    this->setGeometry(x,390,width,90);
    labelButtonOk->setGeometry(this->geometry());

}

void CustomButtonOK::setLongWidth(bool bIsLong)
{
    this->bIsLong = bIsLong;
    update();
}
