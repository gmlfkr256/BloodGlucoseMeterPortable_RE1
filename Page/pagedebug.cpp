#include "pagedebug.h"

PageDebug::PageDebug(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    this->setStyleSheet("background-color: black;");
    init();
}

void PageDebug::init()
{
    font = QFont(instance.fontSuit,36,QFont::Bold);

    labelTitle = new QLabel(this);
    labelTitle->setGeometry(0,20,640,50);
    labelTitle->setStyleSheet("color: white;");
    labelTitle->setAlignment(Qt::AlignCenter);
    labelTitle->setFont(font);
    labelTitle->setText("Debug");

    labelButtonCancel = new QLabel(this);
    labelButtonCancel->setGeometry(540,0,80,80);
    labelButtonCancel->setAlignment(Qt::AlignCenter);
    labelButtonCancel->setStyleSheet("color: white;");
    labelButtonCancel->setFont(font);
    labelButtonCancel->setText("X");

    for (int i = 0; i < 12; i++)
    {
        labelDebugMenu[i] = new QLabel(this);

        int x = 20 + (i % 4) * 153; // 각 열의 x 좌표 (20, 173, 326, 479)
        int y = 95 + (i / 4) * 115; // 각 행의 y 좌표 (95, 210, 325)

        labelDebugMenu[i]->setGeometry(x, y, 140, 100);

        labelDebugMenu[i]->setText(QString("Label %1").arg(i + 1));
        labelDebugMenu[i]->setStyleSheet("border: 1px solid black; background-color: gray; color: white;");
        labelDebugMenu[i]->setFont(font);

        pageNum[i] = PAGE_MAX;
    }

    pageNum[0] = PAGE_DEBUG_SYS;
    labelDebugMenu[0]->setText("SYS");

    pageNum[1] = PAGE_DEBUG_USB;
    labelDebugMenu[1]->setText("USB");

    update();
}

void PageDebug::update()
{

}

void PageDebug::pageShow()
{
    update();
}

void PageDebug::pageHide()
{

}

void PageDebug::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(labelButtonCancel->geometry(),ev))
    {
        emit signalShowPageNum(PAGE_MENU);
    }

    for(int i=0; i<12; i++)
    {
        if(instance.touchCheck(labelDebugMenu[i]->geometry(),ev))
        {
            if(pageNum[i] != PAGE_MAX)
                emit signalShowPageNum(pageNum[i]);
        }
    }
}


