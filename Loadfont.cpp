#include "Loadfont.h"

LoadFont::LoadFont()
{

}

void LoadFont::Load()
{
    // 실행 파일 경로 얻기
    QString executablePath = QCoreApplication::applicationDirPath();
    QString fontPath = QDir(executablePath).filePath("font"); // "font" 디렉토리 경로

    // SUIT-Regular.ttf 로드
    QString suitFont = QDir(fontPath).filePath("Suit/SUIT-Regular.ttf");
    //QString font = QDir(fontPath).filePath("KR/NotoSansKR-Regular.ttf");
    int fontId = QFontDatabase::addApplicationFont(suitFont);//font);
    if (fontId != -1) {
        instance.fontSuit = QFontDatabase::applicationFontFamilies(fontId).at(0);
#if FONT_DEBUG
        qDebug()<<"Loaded fontSuit: "<<instance.fontSuit;
#endif
        //QStringList styles = QFontDatabase().styles("Noto Sans KR");
        //qDebug()<<"Noto Sans KR : "<<styles;
    } else {
        qWarning() << "Failed to load font:" << suitFont;
    }

    // NotoSansJP-Regular.ttf 로드
    QString jpFont = QDir(fontPath).filePath("JP/NotoSansJP-Regular.ttf");
    fontId = QFontDatabase::addApplicationFont(jpFont);
    if (fontId != -1) {
        instance.fontJP = QFontDatabase::applicationFontFamilies(fontId).at(0);
#if FONT_DEBUG
        qDebug()<<"Loaded fontJP: "<<instance.fontJP;
#endif
    } else {
        qWarning() << "Failed to load font:" << jpFont;
    }

    // NotoSansSC-Regular.ttf 로드
    QString scFont = QDir(fontPath).filePath("SC/NotoSansSC-Regular.ttf");
    fontId = QFontDatabase::addApplicationFont(scFont);
    if (fontId != -1) {
        instance.fontSC = QFontDatabase::applicationFontFamilies(fontId).at(0);
#if FONT_DEBUG
        qDebug()<<"Loaded fontSC: "<<instance.fontSC;
#endif
    } else {
        qWarning() << "Failed to load font:" << scFont;
    }

    // NotoSansTC-Regular.ttf 로드
    QString tcFont = QDir(fontPath).filePath("TC/NotoSansTC-Regular.ttf");
    fontId = QFontDatabase::addApplicationFont(tcFont);
    if (fontId != -1) {
        instance.fontTC = QFontDatabase::applicationFontFamilies(fontId).at(0);
#if FONT_DEBUG
        qDebug()<<"Loaded fontTC: "<<instance.fontTC;
#endif
    } else {
        qWarning() << "Failed to load font:" << tcFont;
    }

#if FONT_DEBUG
    QStringList families = QFontDatabase().families();

    qDebug()<<"===================================";
    qDebug()<<"familes list";
    for(const QString& name : families)
        qDebug()<< name;
    qDebug()<<"==================================";
#endif
}
