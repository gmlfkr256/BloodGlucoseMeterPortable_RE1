#ifndef TEXTRESOURCE_H
#define TEXTRESOURCE_H

#include "singleton.h"

class TextResource
{
public:
    static TextResource &getInstance();

    QStringList getText(PageNum page, const QString& textName);
    QFont getFont(PageNum page, const QString& textName);

private:
    Singleton &instance = Singleton::getInstance();
    TextResource();
    void init();

    QMap<DeviceLanguage, QMap<PageNum, QMap<QString, QStringList>>> textData;
    QMap<DeviceLanguage, QMap<PageNum, QMap<QString, QFont>>> fontData;
};

#endif // TEXTRESOURCE_H
