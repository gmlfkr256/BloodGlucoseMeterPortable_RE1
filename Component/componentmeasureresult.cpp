#include "componentmeasureresult.h"

ComponentMeasureResult::ComponentMeasureResult() : CustomComponent(nullptr)
{

}

ComponentMeasureResult::ComponentMeasureResult(QWidget *parent) : CustomComponent(parent)
{
    init();
}


void ComponentMeasureResult::init()
{
    update();
}

void ComponentMeasureResult::update()
{

}

void ComponentMeasureResult::setTextResult(QLabel *label,unsigned char errCode)
{
    int nGetTextNum;
    /*
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
    */
    switch(static_cast<gapiProcErrCode_e>(errCode))
    {
    case GAPI_PROC_ECODE_NORMAL:
        nGetTextNum = 0;
        break;
    case GAPI_PROC_ECODE_NO_FINGER:
        nGetTextNum = 1;
        break;
    case GAPI_PROC_ECODE_SENSOR_FAIL:
        nGetTextNum = 2;
        break;
    case GAPI_PROC_ECODE_LED_FAIL:
        nGetTextNum = 3;
        break;
    case GAPI_PROC_ECODE_ANALYSIS_FAIL:
        nGetTextNum = 4;
        break;
    case GAPI_PROC_ECODE_DATA_ERROR:
        nGetTextNum = 5;
        break;
    case GAPI_PROC_ECODE_CHARGING:
        nGetTextNum = 6;
        break;
    case GAPI_PROC_ECODE_MAX:
        nGetTextNum = 7;
        break;
    default:
        nGetTextNum = 8;
        qDebug()<<"measureResult errCode fail";
    }

    if(label != nullptr)
    {
        label->setAlignment(Qt::AlignCenter);
        label->setFont(textResource.getFont(CUSTOM_COMPONENT,"labelTextResult"));
        label->setStyleSheet("color: #000000;");
        label->setText(textResource.getText(CUSTOM_COMPONENT,"labelTextResult").at(nGetTextNum));
    }

#if DEVICE
    setResultSpk(errCode);
#endif
}

void ComponentMeasureResult::setResultSpk(unsigned char errCode)
{
    qDebug()<<"setResultSpk";
    if(instance.bIsStart)
        return;

    if(static_cast<gapiProcErrCode_e>(errCode) == GAPI_PROC_ECODE_NORMAL)
    {
        instance.guiApi.glucoseSpeakerOut(GAPI_SPK_MEASURE_COMPLETED);
    }
    else
    {
        instance.guiApi.glucoseSpeakerOut(GAPI_SPK_MEASURE_FAIL);
    }
}

void ComponentMeasureResult::pageShow()
{

}

void ComponentMeasureResult::pageHide()
{

}
