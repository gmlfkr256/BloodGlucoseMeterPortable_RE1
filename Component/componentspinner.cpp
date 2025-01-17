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
    vBoxLayoutSpinner->setContentsMargins(10,10,10,10);
    vBoxLayoutSpinner->setSpacing(0);

    labelButtonTop = new QLabel(this);

    labelButtonTop->setFixedHeight(55);

    labelTextValue = new QLabel(this);
    labelTextValue->setAlignment(Qt::AlignCenter);
    labelTextValue->setText("0");

    labelButtonBottom = new QLabel(this);
    labelButtonBottom->setFixedHeight(55);

    labelButtonTopArrow = new QLabel(labelButtonTop);
    labelButtonBottomArrow = new QLabel(labelButtonBottom);

    vBoxLayoutSpinner->addWidget(labelButtonTop);
    vBoxLayoutSpinner->addWidget(labelTextValue);
    vBoxLayoutSpinner->addWidget(labelButtonBottom);

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

    //qDebug()<<"labelButtonTop Width; "<<labelButtonTop->width()<<", height: "<<labelButtonTop->height();
    labelButtonTopArrow->setGeometry(this->width()/2-25,(labelButtonTop->height()-14)/2,30,14);
    labelButtonBottomArrow->setGeometry(this->width()/2-25,(labelButtonTop->height()-14)/2,30,14);

    resizeEvent(nullptr);

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
    updateValue();
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
        emit signalSetValue();
    }

    if(instance.touchCheck(labelButtonBottom->geometry(),ev))
    {
        nValue--;

        updateValue();
        emit signalSetValue();
    }
}

void ComponentSpinner::pageShow()
{

}

void ComponentSpinner::pageHide()
{

}
