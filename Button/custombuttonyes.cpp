#include "custombuttonyes.h"

CustomButtonYes::CustomButtonYes(QWidget *parent) : CustomButton(parent)
{
    this->setGeometry(320,390,320,90);
    init();
}

void CustomButtonYes::init()
{
    labelButtonYes = new QLabel(this);
    labelButtonYes->setGeometry(0,0,this->width(),this->height());
    labelButtonYes->setAlignment(Qt::AlignCenter);
    labelButtonYes->setStyleSheet("background-color: #077bdd; color: #ffffff;");

    update();
}

void CustomButtonYes::update()
{
    labelButtonYes->setFont(textResource.getFont(CUSTOM_BUTTON,"labelButtonYes"));
    labelButtonYes->setText(textResource.getText(CUSTOM_BUTTON,"labelButtonYes").at(0));

    int x = bIsLong ? 0 : 320;
    int width = bIsLong ? 640 : 320;

    this->setGeometry(x,390,width,90);
    labelButtonYes->setGeometry(0,0,this->width(),this->height());
}

void CustomButtonYes::setLongWidth(bool bIsLong)
{
    this->bIsLong = bIsLong;
    update();
}
