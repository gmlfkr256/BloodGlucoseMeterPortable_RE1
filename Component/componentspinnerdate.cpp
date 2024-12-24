#include "componentspinnerdate.h"

ComponentSpinnerDate::ComponentSpinnerDate(QWidget *parent, DateStatus dateStatus) : CustomComponent(parent)
{
    this->dateStatus = dateStatus;
    init();
}

void ComponentSpinnerDate::init()
{
    vBoxLayout = new QVBoxLayout(this);
    vBoxLayout->setContentsMargins(0,0,0,0);
    vBoxLayout->setSpacing(0);

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
    labelTextValue->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
    labelTextBottom->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));

    switch (dateStatus) {
    case DATE_YEAR:
        labelTextTop->setText("2023");
        labelTextValue->setText("2024");
        labelTextBottom->setText("2025");
        break;
    case DATE_MONTH:
        labelTextTop->setText("11");
        labelTextValue->setText("12");
        labelTextBottom->setText("1");
        break;
    case DATE_DAY:
        labelTextTop->setText("23");
        labelTextValue->setText("24");
        labelTextBottom->setText("25");
        break;
    case DATE_HOUR:
        labelTextTop->setText("09");
        labelTextValue->setText("10");
        labelTextBottom->setText("11");
        break;
    case DATE_MIN:
        labelTextTop->setText("00");
        labelTextValue->setText("01");
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

