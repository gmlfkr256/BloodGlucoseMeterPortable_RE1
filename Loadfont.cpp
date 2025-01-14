#include "Loadfont.h"

LoadFont::LoadFont()
{

}

void LoadFont::Load()
{
    int fontId = QFontDatabase::addApplicationFont(":/font/Suit/SUIT-Regular.ttf");
    instance.fontSuit = QFontDatabase::applicationFontFamilies(fontId).at(0);

    fontId = QFontDatabase::addApplicationFont(":/font/JP/NotoSansJP-Regular.ttf");
    instance.fontJP = QFontDatabase::applicationFontFamilies(fontId).at(0);

    fontId = QFontDatabase::addApplicationFont(":/font/SC/NotoSansSC-Regular.ttf");
    instance.fontSC = QFontDatabase::applicationFontFamilies(fontId).at(0);

    fontId = QFontDatabase::addApplicationFont(":/font/TC/NotoSansTC-Regular.ttf");
    instance.fontTC = QFontDatabase::applicationFontFamilies(fontId).at(0);
}
