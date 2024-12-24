#include "componentspinnerdate.h"

ComponentSpinnerDate::ComponentSpinnerDate(QWidget *parent, DateStatus dateStatus) : CustomComponent(parent)
{
    init();
}

void ComponentSpinnerDate::init()
{
    vBoxLayout = new QVBoxLayout(this);

    labelTextTop = new QLabel(this);
    labelTextTop->setFixedHeight(90);
    labelTextTop->setAlignment(Qt::AlignCenter);
    labelTextValue = new QLabel(this);
    labelTextValue->setFixedHeight(90);
    labelTextValue->setAlignment(Qt::AlignCenter);
    labelTextBottom = new QLabel(this);
    labelTextBottom->setFixedHeight(90);
    labelTextBottom->setAlignment(Qt::AlignCenter);

    vBoxLayout->addWidget(labelTextTop);
    vBoxLayout->addWidget(labelTextValue);
    vBoxLayout->addWidget(labelTextBottom);

    update();
}

void ComponentSpinnerDate::update()
{
    labelTextTop->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
    labelTextTop->setText("2023");

    labelTextValue->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
    labelTextValue->setText("2024");

    labelTextBottom->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
    labelTextBottom->setText("2025");
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

