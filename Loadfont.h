#ifndef LOADFONT_H
#define LOADFONT_H

#include "singleton.h"
#include <QFontDatabase>

class LoadFont
{
public:
    Singleton &instance = Singleton::getInstance();
    LoadFont();
    void Load();
};

#endif // LOADFONT_H
