#include "componentspinnerdate.h"

ComponentSpinnerDate::ComponentSpinnerDate(QWidget *parent, DateStatus dateStatus) : CustomComponent(parent)
{
    this->dateStatus = dateStatus;
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
    switch (dateStatus) {
    case DATE_YEAR:
        labelTextTop->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
        labelTextTop->setText("2023");

        labelTextValue->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
        labelTextValue->setText("2024");

        labelTextBottom->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
        labelTextBottom->setText("2025");
        break;
    case DATE_MONTH:
        labelTextTop->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
        labelTextTop->setText("11");

        labelTextValue->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
        labelTextValue->setText("12");

        labelTextBottom->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
        labelTextBottom->setText("1");
        break;
    case DATE_DAY:
        labelTextTop->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
        labelTextTop->setText("23");

        labelTextValue->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
        labelTextValue->setText("24");

        labelTextBottom->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
        labelTextBottom->setText("25");
        break;
    case DATE_HOUR:
        labelTextTop->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
        labelTextTop->setText("09");

        labelTextValue->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
        labelTextValue->setText("10");

        labelTextBottom->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
        labelTextBottom->setText("11");
        break;
    case DATE_MIN:
        labelTextTop->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
        labelTextTop->setText("00");

        labelTextValue->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
        labelTextValue->setText("01");

        labelTextBottom->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
        labelTextBottom->setText("02");
        break;
    }


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

