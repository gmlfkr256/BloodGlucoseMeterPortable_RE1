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

    QString strValue,strValueTop,strValueBottom;

    switch (dateStatus) {
    case DATE_YEAR:
        nValue = 2024;
        break;
    case DATE_MONTH:
        nValue = 12;
        break;
    case DATE_DAY:
        nValue = 24;
        break;
    case DATE_HOUR:
        nValue = 10;
        break;
    case DATE_MIN:
        nValue = 1;
        break;
    }

    strValueTop = QString::number(nValue+1);
    strValue = QString::number(nValue);
    strValueBottom = QString::number(nValue-1);

    labelTextTop->setText(strValueTop);
    labelTextValue->setText(strValue);
    labelTextBottom->setText(strValueBottom);
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

