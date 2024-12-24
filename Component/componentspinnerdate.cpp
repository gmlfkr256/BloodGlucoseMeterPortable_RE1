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
    labelTextTop->hide();
    labelTextBottom->hide();

    labelTextTop->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelTextSub"));
    labelTextTop->setStyleSheet("color: #808080; padding-top: 14px;");
    labelTextValue->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelText"));
    if(isSelect)
    {
        labelTextValue->setStyleSheet("color: #077bdd;");
        labelTextTop->show();
        labelTextBottom->show();
    }
    else
    {
        labelTextValue->setStyleSheet("color: #000000;");
    }

    labelTextBottom->setFont(textResource.getFont(CUSTOM_COMPONENT_DATE,"labelTextSub"));
    labelTextBottom->setStyleSheet("color: #808080; padding-bottom: 14px;");

    QString strValue,strValueTop,strValueBottom;
    bool isCheckYear = false;

    if(dateStatus == DATE_YEAR)
        isCheckYear = true;

    strValueTop = QString("%1").arg(nValue + 1, isCheckYear ? 4 : 2, 10, QChar('0'));
    strValue = QString("%1").arg(nValue, isCheckYear ? 4 : 2, 10, QChar('0'));
    strValueBottom = QString("%1").arg(nValue - 1, isCheckYear ? 4 : 2, 10, QChar('0'));

    labelTextTop->setText(strValueTop);
    labelTextValue->setText(strValue);
    labelTextBottom->setText(strValueBottom);
}

void ComponentSpinnerDate::setValue(int nValue)
{
    this->nValue = nValue;
    update();
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

