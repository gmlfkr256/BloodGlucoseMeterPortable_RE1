#include "pageuserchecknotice.h"

PageUserCheckNotice::PageUserCheckNotice(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageUserCheckNotice::init()
{
    labelText = new QLabel(this);
    labelText->setGeometry(0,153,640,52);
    labelText->setAlignment(Qt::AlignCenter);

    labelCaliDay = new QLabel(this);
    labelCaliDay->setGeometry(0,243,640,52);
    labelCaliDay->setAlignment(Qt::AlignCenter);

    customButtonOK = new CustomButtonOK(this);
    customButtonOK->setLongWidth(true);

    update();
}

void PageUserCheckNotice::update()
{
    customButtonOK->update();

    labelText->setFont(textResource.getFont(PAGE_USER_CHECK_NOTICE,"labelText"));

    if(nSelect<0)
        nSelect = 0;
    else if(nSelect>GAPI_CALI_UTYPE_DIABETES)
        nSelect = GAPI_CALI_UTYPE_DIABETES;

    labelText->setText(textResource.getText(PAGE_USER_CHECK_NOTICE,"labelText").at(nSelect));

    labelCaliDay->setFont(textResource.getFont(PAGE_USER_CHECK_NOTICE,"labelCaliDay"));

    QString str;
    str = textResource.getText(PAGE_USER_CHECK_NOTICE,"labelCaliDay").at(0);
    gapiCaliRegisteredDate_t regiDate;
    instance.guiApi.glucoseCaliGetRegiDate(&regiDate);

    QDate date(regiDate.year,regiDate.mon,regiDate.day);
    str+= date.toString("yyyy.MM.dd");

    labelCaliDay->setText(str);
}

void PageUserCheckNotice::pageShow()
{
    nSelect = instance.getNumUserCheck();
    update();
}

void PageUserCheckNotice::pageHide()
{
    //emit signalShowPageNum(PAGE_CALI_SELECT);
    emit signalShowPageNum(PAGE_CALI_SELECT_RE);
}

void PageUserCheckNotice::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        pageHide();
    }
}
