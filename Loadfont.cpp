#include "Loadfont.h"

LoadFont::LoadFont()
{

}

void LoadFont::Load()
{
    /*
    int fontId = QFontDatabase::addApplicationFont(":/font/Suit/SUIT-Regular.ttf");
    instance.fontSuit = QFontDatabase::applicationFontFamilies(fontId).at(0);

    fontId = QFontDatabase::addApplicationFont(":/font/JP/NotoSansJP-Regular.ttf");
    instance.fontJP = QFontDatabase::applicationFontFamilies(fontId).at(0);

    fontId = QFontDatabase::addApplicationFont(":/font/SC/NotoSansSC-Regular.ttf");
    instance.fontSC = QFontDatabase::applicationFontFamilies(fontId).at(0);

    fontId = QFontDatabase::addApplicationFont(":/font/TC/NotoSansTC-Regular.ttf");
    instance.fontTC = QFontDatabase::applicationFontFamilies(fontId).at(0);
    */
    // 실행 파일 경로 얻기
    QString executablePath = QCoreApplication::applicationDirPath();
    QString fontPath = QDir(executablePath).filePath("font"); // "font" 디렉토리 경로

    // SUIT-Regular.ttf 로드
    QString suitFont = QDir(fontPath).filePath("Suit/SUIT-Regular.ttf");
    int fontId = QFontDatabase::addApplicationFont(suitFont);
    if (fontId != -1) {
        instance.fontSuit = QFontDatabase::applicationFontFamilies(fontId).at(0);
        qDebug()<<"Loaded fontSuit: "<<instance.fontSuit;
    } else {
        qWarning() << "Failed to load font:" << suitFont;
    }

    // NotoSansJP-Regular.ttf 로드
    QString jpFont = QDir(fontPath).filePath("JP/NotoSansJP-Regular.ttf");
    fontId = QFontDatabase::addApplicationFont(jpFont);
    if (fontId != -1) {
        instance.fontJP = QFontDatabase::applicationFontFamilies(fontId).at(0);
        qDebug()<<"Loaded fontJP: "<<instance.fontJP;
    } else {
        qWarning() << "Failed to load font:" << jpFont;
    }

    // NotoSansSC-Regular.ttf 로드
    QString scFont = QDir(fontPath).filePath("SC/NotoSansSC-Regular.ttf");
    fontId = QFontDatabase::addApplicationFont(scFont);
    if (fontId != -1) {
        instance.fontSC = QFontDatabase::applicationFontFamilies(fontId).at(0);
        qDebug()<<"Loaded fontSC: "<<instance.fontSC;
    } else {
        qWarning() << "Failed to load font:" << scFont;
    }

    // NotoSansTC-Regular.ttf 로드
    QString tcFont = QDir(fontPath).filePath("TC/NotoSansTC-Regular.ttf");
    fontId = QFontDatabase::addApplicationFont(tcFont);
    if (fontId != -1) {
        instance.fontTC = QFontDatabase::applicationFontFamilies(fontId).at(0);
        qDebug()<<"Loaded fontTC: "<<instance.fontTC;
    } else {
        qWarning() << "Failed to load font:" << tcFont;
    }

    QFontDatabase fontDb;
    QStringList families = fontDb.families();
    if (!families.isEmpty()) {
        qDebug() << "Available font families:";
        for (const QString &family : families) {
            qDebug() << family;
        }
    } else {
        qDebug() << "No font families available.";
    }
}
