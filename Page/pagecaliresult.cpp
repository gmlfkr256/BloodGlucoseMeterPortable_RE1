#include "pagecaliresult.h"

PageCaliResult::PageCaliResult(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageCaliResult::init()
{
    labelTextAdc = new QLabel(this);
    labelTextAdc->setAlignment(Qt::AlignCenter);
    labelTextTemp = new QLabel(this);
    labelTextTemp->setAlignment(Qt::AlignCenter);
    labelTextHeart = new QLabel(this);
    labelTextHeart->setAlignment(Qt::AlignCenter);

    comMeasureResult = new ComponentMeasureResult(this,QRect(0,280,640,100));

    customButtonOK = new CustomButtonOK(this);
    customButtonOK->setLongWidth(true);
    update();
}

void PageCaliResult::update()
{
    comMeasureResult->update();
    comMeasureResult->setTextResult(instance.sysProcMonInfo.err_code);

    QString strAdc, strTemp, strHeart;
    strAdc = QString::number(instance.caliUserInfo.val[static_cast<int>(instance.getCaliSelectIndex())].adc[static_cast<int>(instance.getCaliSelectOrder())]);
    strTemp = QString::number(instance.caliUserInfo.val[static_cast<int>(instance.getCaliSelectIndex())].temp[static_cast<int>(instance.getCaliSelectOrder())]);
    strHeart = QString::number(instance.caliUserInfo.val[static_cast<int>(instance.getCaliSelectIndex())].hr[static_cast<int>(instance.getCaliSelectOrder())]);

    labelTextAdc->setFont(textResource.getFont(PAGE_CALI_RESULT,"labelTextAdc"));
    labelTextAdc->setText(textResource.getText(PAGE_CALI_RESULT,"labelTextAdc").at(0)+strAdc);
    labelTextTemp->setFont(textResource.getFont(PAGE_CALI_RESULT,"labelTextTemp"));
    labelTextTemp->setText(textResource.getText(PAGE_CALI_RESULT,"labelTextTemp").at(0)+strTemp);
    labelTextHeart->setFont(textResource.getFont(PAGE_CALI_RESULT,"labelTextHeart"));
    labelTextHeart->setText(textResource.getText(PAGE_CALI_RESULT,"labelTextHeart").at(0)+strHeart);

}

void PageCaliResult::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev))
    {
        emit signalShowPageNum(PAGE_CALI_RESULT_MULTI);
    }
}

void PageCaliResult::pageShow()
{

}

void PageCaliResult::pageHide()
{

}
