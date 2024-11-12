#include "custombuttonmeasurestart.h"

CustomButtonMeasureStart::CustomButtonMeasureStart(QWidget *parent) : CustomButton(parent)
{
    this->setGeometry(320,390,320,90);
    init();
}

void CustomButtonMeasureStart::init()
{
    labelButtonMeasureStart = new QLabel(this);
    labelButtonMeasureStart->setGeometry(0,0,this->width(),this->height());
    labelButtonMeasureStart->setAlignment(Qt::AlignCenter);

    update();
}

void CustomButtonMeasureStart::update()
{
    labelButtonMeasureStart->setFont(textResource.getFont(CUSTOM_BUTTON,"labelButtonMeasureStart"));
    labelButtonMeasureStart->setText(textResource.getText(CUSTOM_BUTTON,"labelButtonMeasureStart").at(0));

    switch (instance.getDeviceColor())
    {
    case COLOR_DEFAULT:
        labelButtonMeasureStart->setStyleSheet("background-color: #077bdd; color: #ffffff;");
        break;
    case COLOR_BLUE:
        break;
    case COLOR_RED:
        break;
    }
}
