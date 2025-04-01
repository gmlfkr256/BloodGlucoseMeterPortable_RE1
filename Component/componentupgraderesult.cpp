#include "componentupgraderesult.h"

ComponentUpgradeResult::ComponentUpgradeResult() : CustomComponent(nullptr)
{

}

ComponentUpgradeResult::ComponentUpgradeResult(QWidget *parent) : CustomComponent(parent)
{
    init();
}

void ComponentUpgradeResult::init()
{

}

void ComponentUpgradeResult::update()
{

}

void ComponentUpgradeResult::setTextResult(QLabel *label, unsigned char errCode)
{
    int nGetTextNum;

    switch (static_cast<gapiUpgradeErrCode_e>(errCode))
    {
    case GAPI_UPGRADE_ECODE_NORMAL:
        nGetTextNum = 0;
        break;
    case GAPI_UPGRADE_ECODE_FAILURE:
        nGetTextNum = 1;
        break;
    case GAPI_UPGRADE_ECODE_NOT_UPFILE:
        nGetTextNum = 2;
        break;
    case GAPI_UPGRADE_ECODE_INVALID_FILE:
        nGetTextNum = 3;
        break;
    case GAPI_UPGRADE_ECODE_NO_FILE:
        nGetTextNum = 4;
        break;
    case GAPI_UPGRADE_ECODE_MAX:
        nGetTextNum = 5;
        break;
    default:
        nGetTextNum = 6;
        qDebug()<<"upgrade errCode fail";
        break;
    }

    if(label != nullptr)
    {
        label->setAlignment(Qt::AlignCenter);
        label->setFont(textResource.getFont(CUSTOM_COMPONENT,"labelTextUpgrade"));
        label->setStyleSheet("color: #000000;");
        label->setText(textResource.getText(CUSTOM_COMPONENT,"labelTextUpgrade").at(nGetTextNum));
    }
}

void ComponentUpgradeResult::pageShow()
{

}

void ComponentUpgradeResult::pageHide()
{

}

