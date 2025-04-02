#include "componentpasswordkeyboard.h"

ComponentPasswordKeyboard::ComponentPasswordKeyboard(QWidget *parent) : CustomComponent(parent)
{
    this->setGeometry(0,240,640,240);
    init();
}

void ComponentPasswordKeyboard::init()
{
    for(int i=0; i<3; i++)
    {
        labelFunction[i] = new QLabel(this);
        labelFunction[i]->setStyleSheet("background-color: #ffffff; border: 1px solid #ebebeb;");

        labelFunction[i]->setGeometry(i*213,0,213,80);
    }

    for(int i=0; i<10; i++)
    {
        labelButton[i] = new QLabel(this);
        labelButton[i]->setStyleSheet("background-color: #ffffff; border: 1px solid #ebebeb;");

        if(i<5)
        {
            labelButton[i]->setGeometry(i*128,80,128,80);
        }
        else
        {
            labelButton[i]->setGeometry((i-5)*128,160,128,80);
        }
    }

    update();
}

void ComponentPasswordKeyboard::update()
{
    if(!keyBoardIndex.mapKey.contains(nFunctionNum))
    {
        qDebug()<<"Invalid nFunctionNum: "<<nFunctionNum;
        return;
    }

    for(int i=0; i<10; i++)
    {
        labelButton[i]->setText(keyBoardIndex.mapKey[nFunctionNum][i]);
    }
}

void ComponentPasswordKeyboard::pageShow()
{
    update();
}

void ComponentPasswordKeyboard::pageHide()
{

}

void ComponentPasswordKeyboard::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
}

void ComponentPasswordKeyboard::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
}
