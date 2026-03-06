#include "custombuttonback.h"

CustomButtonBack::CustomButtonBack(QWidget *parent) : CustomButton(parent)
{
    this->setGeometry(0,390,320,90);
    init();
}

void CustomButtonBack::init()
{
    labelButtonBack = new QLabel(this);
    labelButtonBack->setGeometry(0,0,this->width(),this->height());
    labelButtonBack->setAlignment(Qt::AlignCenter);

    update();
}

void CustomButtonBack::update()
{
    labelButtonBack->setFont(textResource.getFont(CUSTOM_BUTTON,"labelButtonBack"));
    labelButtonBack->setText(textResource.getText(CUSTOM_BUTTON,"labelButtonBack").at(0));

    if(this->bIsEnable)
    {
        labelButtonBack->setStyleSheet("background-color: #212121; color: #ffffff;");
    }
    else
    {
        labelButtonBack->setStyleSheet("background-color: #cdcdcd; color: #000000;");
    }

    int width = bIsLong ? 640 : 320;

    this->setGeometry(0,390,width,90);
    labelButtonBack->setGeometry(0,0,this->width(),this->height());
}

void CustomButtonBack::setLongWidth(bool bIsLong)
{
    this->bIsLong = bIsLong;
    update();
}

void CustomButtonBack::setEnable()
{
    this->bIsEnable = true;
}

void CustomButtonBack::setDisable()
{
    this->bIsEnable = false;
}

bool CustomButtonBack::getEnable()
{
    return this->bIsEnable;
}
