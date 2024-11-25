#include "componentmeasureresult.h"

ComponentMeasureResult::ComponentMeasureResult(QWidget *parent, QRect rect) : CustomComponent(parent)
{
    this->setGeometry(rect);
    init();
}

ComponentMeasureResult::ComponentMeasureResult(QWidget *parent) :CustomComponent(parent)
{
    init();
}

void ComponentMeasureResult::init()
{
    labelTextResult = new QLabel(this);
    //labelTextResult->setGeometry(0,0,this->width(),this->height());
    labelTextResult->setGeometry(this->geometry());
    labelTextResult->setAlignment(Qt::AlignCenter);
    update();
    setTextResult(GAPI_PROC_ECODE_MAX);
}

void ComponentMeasureResult::update()
{
    labelTextResult->setFont(textResource.getFont(CUSTOM_COMPONENT,"labelTextResult"));
    labelTextResult->setStyleSheet("color: #000000;");
}

void ComponentMeasureResult::setTextResult(unsigned char errCode)
{
    int nGetTextNum;
    switch (static_cast<gapiProcErrCode_e>(errCode))
    {
    case GAPI_PROC_ECODE_NORMAL:
        nGetTextNum = 0;
        break;
    case GAPI_PROC_ECODE_TIMEOUT:
        nGetTextNum = 1;
        break;
    case GAPI_PROC_ECODE_NULL_PTR:
        nGetTextNum = 2;
        break;
    case GAPI_PROC_ECODE_COUNT_ZERO:
        nGetTextNum = 3;
        break;
    case GAPI_PROC_ECODE_MALLOC_FAIL:
        nGetTextNum = 4;
        break;
    case GAPI_PROC_ECODE_NONE_GRADE:
        nGetTextNum = 5;
        break;
    case GAPI_PROC_ECODE_PARAM_FAIL:
        nGetTextNum = 6;
        break;
    case GAPI_PROC_ECODE_RESULT_FAIL:
        nGetTextNum = 7;
        break;
    case GAPI_PROC_ECODE_MAX:
        nGetTextNum = 8;
        break;
    }

    labelTextResult->setText(textResource.getText(CUSTOM_COMPONENT,"labelTextResult").at(nGetTextNum));
}

void ComponentMeasureResult::setCustomGeomtry(QRect rect)
{
    this->setGeometry(rect);
}

void ComponentMeasureResult::pageShow()
{

}

void ComponentMeasureResult::pageHide()
{

}
