#include "componentspinner.h"

ComponentSpinner::ComponentSpinner(QWidget *parent ,QRect rect) : CustomComponent(parent)
{
    this->setGeometry(rect);
    init();
}

void ComponentSpinner::init()
{
    labelSpinnerBg = new QLabel(this);
    labelSpinnerBg->setGeometry(0,0,this->width(),this->height());

    vBoxLayoutSpinner = new QVBoxLayout(this);

    labelButtonTop = new QLabel(this);
    vBoxLayoutSpinner->addWidget(labelButtonTop);
    labelButtonTop->setFixedHeight(55);

    labelTextValue = new QLabel(this);
    labelTextValue->setAlignment(Qt::AlignCenter);
    vBoxLayoutSpinner->addWidget(labelTextValue);
    //labelTextValue->setFixedHeight(static_cast<int>(this->height()/3));
    labelTextValue->setText("0");

    labelButtonBottom = new QLabel(this);
    vBoxLayoutSpinner->addWidget(labelButtonBottom);
    labelButtonBottom->setFixedHeight(55);

    labelButtonTopArrow = new QLabel(labelButtonTop);
    labelButtonTopArrow->setFixedSize(30,14);
    labelButtonBottomArrow = new QLabel(labelButtonBottom);
    labelButtonBottomArrow->setFixedSize(30,14);

    update();
}

void ComponentSpinner::update()
{
    labelSpinnerBg->setStyleSheet("background-color: #f3f3f3; border-radius: 15px;");

    labelTextValue->setFont(QFont(instance.fontSuit,instance.pixelToPoint(81),QFont::Bold));

    labelButtonTop->setStyleSheet("background-color: #ffffff; border-radius: 10px;");
    labelButtonBottom->setStyleSheet("background-color: #ffffff; border-radius: 10px;");

    instance.pixLoad(labelButtonTopArrow,false,strDirPath,"/imgArrowTop.png");
    instance.pixLoad(labelButtonBottomArrow,false,strDirPath,"/imgArrowBottom.png");

    labelButtonTopArrow->setGeometry((labelButtonTop->width()-30)/2,(labelButtonTop->height()-14)/2,30,14);
    labelButtonBottomArrow->setGeometry((labelButtonBottom->width()-30)/2,(labelButtonBottom->height()-14)/2,30,14);

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
