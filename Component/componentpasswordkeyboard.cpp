#include "componentpasswordkeyboard.h"

ComponentPasswordKeyboard::ComponentPasswordKeyboard(QWidget *parent) : CustomComponent(parent)
{
    this->setGeometry(0,240,640,240);
    init();
}

void ComponentPasswordKeyboard::init()
{
    for(int i=0; i<5; i++)
    {
        labelFunction[i] = new QLabel(this);
        labelFunction[i]->setStyleSheet("background-color: #E0F7FA; border: 1px solid #888888;");
        labelFunction[i]->setFont(textResource.getFont(PAGE_PASSWORD,"labelButtonNum"));
        labelFunction[i]->setAlignment(Qt::AlignCenter);

        //labelFunction[i]->setGeometry(i*128,0,128,80);
        labelFunction[i]->setGeometry(i*106,0,106,80);
    }

    labelFunction[0]->setText("0·9");
    labelFunction[1]->setText("a A");
    labelFunction[2]->setText("k K");
    labelFunction[3]->setText("u U");
    labelFunction[4]->setText("! - :");


    for(int i=0; i<10; i++)
    {
        labelButton[i] = new QLabel(this);
        labelButton[i]->setStyleSheet("background-color: #ffffff; border: 1px solid #ebebeb;");
        labelButton[i]->setFont(textResource.getFont(PAGE_PASSWORD,"labelButtonNum"));
        labelButton[i]->setAlignment(Qt::AlignCenter);

        if(i<5)
        {
            //labelButton[i]->setGeometry(i*128,80,128,80);
            labelButton[i]->setGeometry(i*106,80,106,80);
        }
        else
        {
            //labelButton[i]->setGeometry((i-5)*128,160,128,80);
            labelButton[i]->setGeometry((i-5)*106,160,106,80);
        }
    }

    QList<QLabel*> labelList;

    labelButtonDel = new QLabel(this);
    labelButtonDel->setGeometry(530,0,110,80);
    labelButtonDel->setText("Del");
    labelList.append(labelButtonDel);
    labelButtonShowHide = new QLabel(this);
    labelButtonShowHide->setGeometry(530,80,110,80);
    labelButtonShowHide->setText("Eye");
    labelList.append(labelButtonShowHide);
    labelButtonOK = new QLabel(this);
    labelButtonOK->setGeometry(530,160,110,80);
    labelButtonOK->setText("OK");
    labelList.append(labelButtonOK);

    for(QLabel *label : labelList)
    {
        label->setFont(textResource.getFont(PAGE_PASSWORD,"labelButtonNum"));
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet("background-color: #177bdd; border: 1px solid #888888;");
    }

    keyBoardIndex = new KeyBoardIndex(this);

    update();
}

void ComponentPasswordKeyboard::update()
{

    if(!keyBoardIndex->mapKey.contains(nFunctionNum))
    {
        qDebug()<<"Invalid nFunctionNum: "<<nFunctionNum;
        return;
    }

    for(int i=0; i<10; i++)
    {
        labelButton[i]->setText(keyBoardIndex->mapKey[nFunctionNum].at(i));
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
    if(instance.touchCheck(labelFunction[0]->geometry(),ev))
    {
        nFunctionNum = 0;
        update();
    }

    if(instance.touchCheck(labelFunction[1]->geometry(),ev))
    {
        if(nFunctionNum == 4)
            nFunctionNum = 1;
        else
            nFunctionNum = 4;

        update();
    }

    if(instance.touchCheck(labelFunction[2]->geometry(),ev))
    {
        if(nFunctionNum == 5)
            nFunctionNum = 2;
        else
            nFunctionNum = 5;
        update();
    }

    if(instance.touchCheck(labelFunction[3]->geometry(),ev))
    {
        if(nFunctionNum == 6)
            nFunctionNum = 3;
        else
            nFunctionNum = 6;
        update();
    }

    if(instance.touchCheck(labelFunction[4]->geometry(),ev))
    {
        if(nFunctionNum == 7)
            nFunctionNum = 8;
        else if(nFunctionNum == 8)
            nFunctionNum = 9;
        else
            nFunctionNum = 7;
        update();
    }

    if(instance.touchCheck(QRect(0,80,640,160),ev))
    {
        for(int i=0; i<10; i++)
        {
            if(instance.touchCheck(labelButton[i]->geometry(),ev))
            {
                if(strKey.size()<12)
                    strKey += keyBoardIndex->mapKey[nFunctionNum].at(i);

                qDebug()<<strKey;
                emit signalKeyClick(strKey);
            }
        }
    }

    if(instance.touchCheck(labelButtonDel->geometry(),ev))
    {
        deleteLastKey();
    }
}

void ComponentPasswordKeyboard::deleteLastKey()
{
    if(!strKey.isEmpty())
    {
        strKey.chop(1);
        emit signalKeyClick(strKey);
    }
}

void ComponentPasswordKeyboard::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
}
