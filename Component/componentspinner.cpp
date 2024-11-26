#include "componentspinner.h"

ComponentSpinner::ComponentSpinner(QWidget *parent ,QRect rect) : CustomComponent(parent)
{
    this->setGeometry(rect);
    init();
}

void ComponentSpinner::init()
{
    labelSpinnerBg = new QLabel(this);
    labelSpinnerBg->setGeometry(this->geometry());

    vBoxLayoutSpinner = new QVBoxLayout(this);

    labelButtonTop = new QLabel(this);
    vBoxLayoutSpinner->addWidget(labelButtonTop);
    labelButtonTop->setFixedHeight(static_cast<int>(this->height()/3));

    labelTextValue = new QLabel(this);
    labelTextValue->setAlignment(Qt::AlignCenter);
    vBoxLayoutSpinner->addWidget(labelTextValue);
    labelTextValue->setFixedHeight(static_cast<int>(this->height()/3));
    labelTextValue->setText("0");

    labelButtonBottom = new QLabel(this);
    vBoxLayoutSpinner->addWidget(labelButtonBottom);
    labelButtonBottom->setFixedHeight(static_cast<int>(this->height()/3));

    update();
}

void ComponentSpinner::update()
{
    labelSpinnerBg->setStyleSheet("background-color: #f3f3f3; border-radius: 15px;");

    labelTextValue->setFont(QFont(instance.fontSuit,instance.pixelToPoint(48),QFont::Bold));

    labelButtonTop->setFont(QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));
    labelButtonTop->setAlignment(Qt::AlignCenter);
    //labelButtonTop->setText("▲");
    labelButtonTop->setText("+");
    labelButtonTop->setStyleSheet("color: #52d0ba;");
    labelButtonBottom->setFont(QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));
    labelButtonBottom->setAlignment(Qt::AlignCenter);
    //labelButtonBottom->setText("▼");
    labelButtonBottom->setText("-");
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
