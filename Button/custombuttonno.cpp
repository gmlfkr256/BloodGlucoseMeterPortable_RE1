#include "custombuttonno.h"

CustomButtonNo::CustomButtonNo(QWidget *parent) : CustomButton(parent)
{
    this->setGeometry(0,390,320,90);
    init();
}

void CustomButtonNo::init()
{
    labelButtonNo = new QLabel(this);
    labelButtonNo->setGeometry(0,0,this->width(),this->height());
    labelButtonNo->setAlignment(Qt::AlignCenter);
    labelButtonNo->setStyleSheet("background-color: #212121; color: #ffffff;");

    update();
}

void CustomButtonNo::update()
{
    labelButtonNo->setFont(textResource.getFont(CUSTOM_BUTTON,"labelButtonNo"));
    labelButtonNo->setText(textResource.getText(CUSTOM_BUTTON,"labelButtonNo").at(0));

    int width = bIsLong ? 640 : 320;

    this->setGeometry(0,390,width,90);
    labelButtonNo->setGeometry(0,0,this->width(),this->height());
}

void CustomButtonNo::setLongWidth(bool bIsLong)
{
    this->bIsLong = bIsLong;
    update();
}
