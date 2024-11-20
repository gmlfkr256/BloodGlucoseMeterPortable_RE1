#include "custombuttonmeasure.h"

CustomButtonMeasure::CustomButtonMeasure(QWidget *parent) : CustomButton(parent)
{
    this->setGeometry(320,390,320,90);
    init();
}

void CustomButtonMeasure::init()
{
    labelButtonMeasure = new QLabel(this);
    labelButtonMeasure->setGeometry(0,0,this->width(),this->height());
    labelButtonMeasure->setAlignment(Qt::AlignCenter);
    labelButtonMeasure->setStyleSheet("background-color: #077bdd; color: #ffffff;");
    update();
}

void CustomButtonMeasure::update()
{
    labelButtonMeasure->setFont(textResource.getFont(CUSTOM_BUTTON,"labelButtonMeasure"));
    labelButtonMeasure->setText(textResource.getText(CUSTOM_BUTTON,"labelButtonMeasure").at(0));

    /*
    switch(instance.getDeviceColor())
    {
    case COLOR_DEFAULT:
        labelButtonMeasure->setStyleSheet("background-color: #077bdd; color: #ffffff;");
        break;
    case COLOR_BLUE:
        break;
    case COLOR_RED:
        break;
    }*/
}

void CustomButtonMeasure::setLeftButton(bool bIsLeft)
{
    if(bIsLeft)
    {
        this->setGeometry(0,390,320,90);
        labelButtonMeasure->setStyleSheet("background-color: #212121; color: #ffffff;");
    }
    else
    {
        this->setGeometry(320,390,320,90);
        labelButtonMeasure->setStyleSheet("background-color: #077bdd; color: #ffffff;");
    }
}
