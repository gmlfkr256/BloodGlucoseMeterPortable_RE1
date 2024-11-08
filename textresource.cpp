#include "textresource.h"

TextResource& TextResource::getInstance()
{
    static TextResource instance;
    return instance;
}

TextResource::TextResource()
{
    init();
}

void TextResource::init()
{
    //KR
    //PAGE_PASSWORD
    fontData[KR][PAGE_PASSWORD].insert("labelButtonNum",QFont(instance.fontSuit,instance.pixelToPoint(44),QFont::Bold));

    //PAGE_HOME
    fontData[KR][PAGE_HOME].insert("labelButtonTitle",QFont(instance.fontSuit,instance.pixelToPoint(33),QFont::Bold));
    textData[KR][PAGE_HOME].insert("labelButtonTitle",QStringList{"기상","조식 전","조식 후","중식 전","중식 후","석식 전","석식 후","취침"});

    fontData[KR][PAGE_HOME].insert("labelButtonText",QFont(instance.fontSuit,instance.pixelToPoint(62),QFont::ExtraBold));

    //EN
    //PAGE_PASSWORD
    fontData[EN][PAGE_PASSWORD].insert("labelButtonNum",QFont(instance.fontSuit,instance.pixelToPoint(44),QFont::Bold));

    //PAGE_HOME
    fontData[EN][PAGE_HOME].insert("labelButtonTitle",QFont(instance.fontSuit,instance.pixelToPoint(26),QFont::Bold));
    textData[EN][PAGE_HOME].insert("labelButtonTitle",QStringList{"Wake\nUp","Before\nBreakfast","After\nBreakfast","Before\nLunch","After\nLunch","Before\nDinner","After\nDinner","Bed\nTime"});

    fontData[EN][PAGE_HOME].insert("labelButtonText",QFont(instance.fontSuit,instance.pixelToPoint(62),QFont::ExtraBold));
    //JP
    //CN_GAN
    //CN_BUN
}

QStringList TextResource::getText(PageNum page, const QString& textName)
{
    DeviceLanguage lang = instance.getDeviceLanguage();
    if(textData.contains(lang) && textData[lang].contains(page))
    {
        return textData[lang][page].value(textName,QStringList{"EMPTY"});
    }

    qDebug()<<"getText fail";
    return QStringList{"EMPTY"};
}

QFont TextResource::getFont(PageNum page, const QString& textName)
{
    DeviceLanguage lang = instance.getDeviceLanguage();
    if(fontData.contains(lang) && fontData[lang].contains(page))
    {
        return fontData[lang][page].value(textName,QFont("Default",12));
    }

    qDebug()<<"getFont fail";
    return QFont("Default",12);
}
