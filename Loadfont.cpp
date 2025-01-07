#include "Loadfont.h"

LoadFont::LoadFont()
{

}

void LoadFont::Load()
{
    int fontId = QFontDatabase::addApplicationFont(":/Font/Suit/SUIT-Regular.ttf");
    instance.fontSuit = QFontDatabase::applicationFontFamilies(fontId).at(0);

    fontId = QFontDatabase::addApplicationFont(":/Font/JP/NotoSansJP-Regular.ttf");
    instance.fontJP = QFontDatabase::applicationFontFamilies(fontId).at(0);

    fontId = QFontDatabase::addApplicationFont(":/Font/SC/NotoSansSC-Regular.ttf");
    instance.fontSC = QFontDatabase::applicationFontFamilies(fontId).at(0);

    fontId = QFontDatabase::addApplicationFont(":/Font/TC/NotoSansTC-Regular.ttf");
    instance.fontTC = QFontDatabase::applicationFontFamilies(fontId).at(0);
}
