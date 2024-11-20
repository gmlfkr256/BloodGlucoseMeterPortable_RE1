#include "custombuttonmeasurere.h"

CustomButtonMeasureRe::CustomButtonMeasureRe(QWidget *parent) : CustomButton(parent)
{
    this->setGeometry(0,390,320,90);
    init();
}

void CustomButtonMeasureRe::init()
{
    labelButtonMeasureRe = new QLabel(this);
    labelButtonMeasureRe->setGeometry(0,0,this->width(),this->height());
    labelButtonMeasureRe->setAlignment(Qt::AlignCenter);
    labelButtonMeasureRe->setStyleSheet("background-color: #212121; color: #ffffff;");
    update();
}

void CustomButtonMeasureRe::update()
{
    labelButtonMeasureRe->setFont(textResource.getFont(CUSTOM_BUTTON,"labelButtonMeasureRe"));
    labelButtonMeasureRe->setText(textResource.getText(CUSTOM_BUTTON,"labelButtonMeasureRe").at(0));
}
