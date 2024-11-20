#include "componentspinner.h"

ComponentSpinner::ComponentSpinner(QWidget *parent) : CustomComponent(parent)
{
    this->setGeometry(100,100,50,150);
    init();
}

void ComponentSpinner::init()
{
    vBoxLayoutSpinner = new QVBoxLayout(this);

    labelButtonTop = new QLabel(this);
    vBoxLayoutSpinner->addWidget(labelButtonTop);
    labelButtonTop->setFixedHeight(50);

    labelTextValue = new QLabel(this);
    labelTextValue->setAlignment(Qt::AlignCenter);
    vBoxLayoutSpinner->addWidget(labelTextValue);
    labelTextValue->setFixedHeight(50);
    labelTextValue->setText("0");

    labelButtonBottom = new QLabel(this);
    vBoxLayoutSpinner->addWidget(labelButtonBottom);
    labelButtonBottom->setFixedHeight(50);

    update();
}

void ComponentSpinner::update()
{
    labelTextValue->setFont(QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));

    labelButtonTop->setFont(QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));
    labelButtonTop->setAlignment(Qt::AlignCenter);
    labelButtonTop->setText("▲");
    labelButtonTop->setStyleSheet("color: #52d0ba;");
    labelButtonBottom->setFont(QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));
    labelButtonBottom->setAlignment(Qt::AlignCenter);
    labelButtonBottom->setText("▼");
    labelButtonBottom->setStyleSheet("color: #52d0ba;");

    updateValue();
}

void ComponentSpinner::updateValue()
{
    if(nValue>9)
        nValue = 0;
    else if(nValue<0)
        nValue = 9;

    labelTextValue->setText(QString::number(nValue));
}

void ComponentSpinner::setValue(int nValue)
{
    this->nValue = nValue;
}

int ComponentSpinner::getValue()
{
    return this->nValue;
}

void ComponentSpinner::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(labelButtonTop->geometry(),ev))
    {
        nValue++;

        updateValue();
    }

    if(instance.touchCheck(labelButtonBottom->geometry(),ev))
    {
        nValue--;

        updateValue();
    }
}

void ComponentSpinner::pageShow()
{

}

void ComponentSpinner::pageHide()
{

}
