#include "custombuttonlanguage.h"

CustomButtonLanguage::CustomButtonLanguage(QWidget *parent) : CustomButton(parent)
{
    this->setGeometry(0,390,640,90);
    init();
}

void CustomButtonLanguage::init()
{
    labelButtonLang = new QLabel(this);
    labelButtonLang->setGeometry(0,0,this->width(),this->height());
    labelButtonLang->setAlignment(Qt::AlignCenter);
    labelButtonLang->setStyleSheet("background-color: #077bdd; color: #ffffff;");

    update();
}

void CustomButtonLanguage::update()
{
    nSelectIndex = instance.getDeviceLanguage();
    QString strLang = textResource.getText(CUSTOM_BUTTON,"labelButtonLang").at(nSelectIndex);
    labelButtonLang->setFont(textResource.getFont(CUSTOM_BUTTON,"labelButtonLang"));
    labelButtonLang->setText("Language Setting : "+strLang);
}

void CustomButtonLanguage::updateLanguage()
{
    nSelectIndex = (nSelectIndex + 1 + nTotal) % nTotal;

    instance.setDeviceLanguage(nSelectIndex);
    instance.langData.used = nSelectIndex;

#if DEVICE
    qDebug()<<"set instance.langData.used: "<<instance.langData.used;
    instance.guiApi.glucoseSetLangData(&instance.langData);
#endif

    update();

    emit signalUpdateLanguage();
}
