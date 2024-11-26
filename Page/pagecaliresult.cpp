#include "pagecaliresult.h"

PageCaliResult::PageCaliResult(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PageCaliResult::init()
{
    labelTextAdc = new QLabel(this);
    labelTextAdc->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    labelTextAdc->setGeometry(250,143,200,45);

    labelTextTemp = new QLabel(this);
    labelTextTemp->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    labelTextAdc->setGeometry(250,143+45,200,45);

    labelTextHeart = new QLabel(this);
    labelTextHeart->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    labelTextHeart->setGeometry(250,143+90,200,45);

    labelTextResult = new QLabel(this);
    labelTextResult->setAlignment(Qt::AlignCenter);
    labelTextResult->setGeometry(0,315,640,45);

    labelTextAdc->setStyleSheet("background-color: red;");
    labelTextTemp->setStyleSheet("background-color: blue");
    labelTextHeart->setStyleSheet("background-color: green;");

    customButtonOK = new CustomButtonOK(this);
    customButtonOK->setLongWidth(true);
    update();
}

void PageCaliResult::update()
{

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

    ComponentMeasureResult componentMeasureResult;
    componentMeasureResult.setTextResult(labelTextResult,instance.sysProcMonInfo.err_code);
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
    update();
}

void PageCaliResult::pageHide()
{

}
