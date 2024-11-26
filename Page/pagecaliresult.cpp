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
    labelTextAdc->setGeometry(250,143,30,45);

    labelTextAdcColon = new QLabel(this);
    labelTextAdcColon->setAlignment(Qt::AlignCenter);
    labelTextAdcColon->setGeometry(285,143,10,45);

    labelTextAdcValue = new QLabel(this);
    labelTextAdcValue->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    labelTextAdcValue->setGeometry(300,143,110,45);


    labelTextTemp = new QLabel(this);
    labelTextTemp->setAlignment(Qt::AlignCenter);
    labelTextTemp->setGeometry(253,188,24,45);

    labelTextTempColon = new QLabel(this);
    labelTextTempColon->setAlignment(Qt::AlignCenter);
    labelTextTempColon->setGeometry(285,188,10,45);

    labelTextTempValue = new QLabel(this);
    labelTextTempValue->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    labelTextTempValue->setGeometry(300,188,110,45);


    labelTextHeart = new QLabel(this);
    labelTextHeart->setAlignment(Qt::AlignCenter);
    labelTextHeart->setGeometry(252,233,26,45);

    labelTextHeartColon = new QLabel(this);
    labelTextHeartColon->setAlignment(Qt::AlignCenter);
    labelTextHeartColon->setGeometry(285,233,10,45);

    labelTextHeartValue = new QLabel(this);
    labelTextHeartValue->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    labelTextHeartValue->setGeometry(300,233,110,45);


    labelTextResult = new QLabel(this);
    labelTextResult->setAlignment(Qt::AlignCenter);
    labelTextResult->setGeometry(0,315,640,45);

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

    QFont fontLabelTextAdc = textResource.getFont(PAGE_CALI_RESULT,"labelTextAdc");
    labelTextAdc->setFont(fontLabelTextAdc);
    labelTextAdc->setText("A");
    labelTextAdcColon->setFont(fontLabelTextAdc);
    labelTextAdcColon->setText(":");
    labelTextAdcValue->setFont(fontLabelTextAdc);
    labelTextAdcValue->setText(strAdc);

    QFont fontLabelTextTemp = textResource.getFont(PAGE_CALI_RESULT,"labelTextTemp");
    labelTextTemp->setFont(fontLabelTextTemp);
    labelTextTemp->setText("T");
    labelTextTempColon->setFont(fontLabelTextTemp);
    labelTextTempColon->setText(":");
    labelTextTempValue->setFont(fontLabelTextTemp);
    labelTextTempValue->setText(strTemp);

    QFont fontLabelTextHeart = textResource.getFont(PAGE_CALI_RESULT,"labelTextHeart");
    labelTextHeart->setFont(fontLabelTextHeart);
    labelTextHeart->setText("H");
    labelTextHeartColon->setFont(fontLabelTextHeart);
    labelTextHeartColon->setText(":");
    labelTextHeartValue->setFont(fontLabelTextHeart);
    labelTextHeartValue->setText(strHeart);

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
