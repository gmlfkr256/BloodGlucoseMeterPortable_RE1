#include "Loadfont.h"

LoadFont::LoadFont()
{

}

void LoadFont::Load()
{
    int fontId = QFontDatabase::addApplicationFont(":/Font/SUIT-ttf/SUIT-Regular.ttf");
    instance.fontSuit = QFontDatabase::applicationFontFamilies(fontId).at(0);
}
