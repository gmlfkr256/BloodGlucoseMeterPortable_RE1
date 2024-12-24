#include "componentspinnerdate.h"

ComponentSpinnerDate::ComponentSpinnerDate(QWidget *parent, DateStatus dateStatus) : CustomComponent(parent)
{
    init();
}

void ComponentSpinnerDate::init()
{
    vBoxLayout = new QVBoxLayout(this);

    labelTextTop = new QLabel(this);
    labelTextTop->setFixedHeight(30);
    labelTextValue = new QLabel(this);
    labelTextValue->setFixedHeight(30);
    labelTextBottom = new QLabel(this);
    labelTextBottom->setFixedHeight(30);

    vBoxLayout->addWidget(labelTextTop);
    vBoxLayout->addWidget(labelTextValue);
    vBoxLayout->addWidget(labelTextBottom);

    update();
}

void ComponentSpinnerDate::update()
{
    labelTextValue->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
    labelTextValue->setText("2024");
}

void ComponentSpinnerDate::pageShow()
{

}

void ComponentSpinnerDate::pageHide()
{

}

void ComponentSpinnerDate::mousePressEvent(QMouseEvent *ev)
{

}

