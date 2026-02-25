#include "pageelapsednoticepopup.h"

PageElapsedNoticePopup::PageElapsedNoticePopup(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageElapsedNoticePopup::init()
{
    labelTitle = new QLabel(this);
    labelTitle->setGeometry(0,158,640,52);
    labelTitle->setAlignment(Qt::AlignCenter);

    labelText = new QLabel(this);
    labelText->setGeometry(0,243,640,52);
    labelText->setAlignment(Qt::AlignCenter);

    customButtonOK = new CustomButtonOK(this);
    customButtonOK->setLongWidth(true);

    update();
}

void PageElapsedNoticePopup::update()
{
    customButtonOK->update();

    labelTitle->setFont(textResource.getFont(PAGE_ELAPSED_NOTICE_POPUP,"labelTitle"));
    labelTitle->setText(textResource.getText(PAGE_ELAPSED_NOTICE_POPUP,"labelTitle").at(0));

    labelText->setFont(textResource.getFont(PAGE_ELAPSED_NOTICE_POPUP,"labelText"));

    int elapsed = instance.getElapsedDay();

    QString strText = "";

    if (elapsed > 90) {
        // 90일 이상 경과 → D-Day 이후
        strText += textResource.getText(PAGE_ELAPSED_NOTICE_POPUP, "warningText").at(0);
        labelText->setStyleSheet("color: #f70000;");
    }
    else if (elapsed >= 76 && elapsed <= 90) {
        // D-15 ~ D-1 구간
        int index = 90 - elapsed; // 0~14
        strText += textResource.getText(PAGE_ELAPSED_NOTICE_POPUP, "elapsedText").at(index);
        labelText->setStyleSheet("color: black;");
    }

    labelText->setText(strText);
}

void PageElapsedNoticePopup::pageShow()
{
    update();
}

void PageElapsedNoticePopup::pageHide()
{
    if(instance.getIsMeasure() && (instance.getElapsedDay()<=90))
    {
        instance.setIsMeasure(false);
        instance.isTouchCtrl = false;
        instance.setGraphMode(GRAPH_MEASURE);
        emit signalShowPageNum(PAGE_GRAPH);
    }
    else
    {
        //emit signalShowPageNum(PAGE_HOME);
        emit signalShowPageNum(PAGE_CALI_NOTICE);
    }
}

void PageElapsedNoticePopup::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        pageHide();
    }
}
