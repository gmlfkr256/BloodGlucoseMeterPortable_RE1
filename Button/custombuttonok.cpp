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
    labelButtonOk->setAlignment(Qt::AlignCenter);

    update();
}

void CustomButtonOK::update()
{
    labelButtonOk->setFont(textResource.getFont(CUSTOM_BUTTON,"labelButtonOK"));
    labelButtonOk->setText(textResource.getText(CUSTOM_BUTTON,"labelButtonOK").at(0));

    if(this->bIsEnable)
    {
        labelButtonOk->setStyleSheet("background-color: #077bdd; color: #ffffff;");
    }
    else
    {
        labelButtonOk->setStyleSheet("background-color: #cdcdcd; color: #000000;");
    }

    int x = bIsLong ? 0 : 320;
    int width = bIsLong ? 640 : 320;

    this->setGeometry(x,390,width,90);
    labelButtonOk->setGeometry(0,0,this->width(),this->height());

}

void CustomButtonOK::setLongWidth(bool bIsLong)
{
    this->bIsLong = bIsLong;
    update();
}

void CustomButtonOK::setEnable()
{
    this->bIsEnable = true;

}

void CustomButtonOK::setDisable()
{
    this->bIsEnable = false;
}

bool CustomButtonOK::getEnable()
{
    return this->bIsEnable;
}
