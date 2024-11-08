#ifndef SINGLETON_H
#define SINGLETON_H

#include <GlobalMain.h>

typedef enum
{
    COLOR_DEFAULT = 0,
    COLOR_BLUE,
    COLOR_RED
} DeviceColor;

Q_ENUMS(DeviceColor)

typedef enum
{
    KR = 0,
    EN,
    JP,
    CN_GAN,
    CN_BUN
} DeviceLanguage;

Q_ENUMS(DeviceLanguage)

typedef enum
{
    USER1 = 0,
    USER2,
    ROOT
} UserNum;

Q_ENUMS(UserNum)

typedef enum
{
    PAGE_HOME = 0,
    PAGE_SELECT,
    PAGE_MAX
} PageNum;

Q_ENUMS(PageNum)

class Singleton : public QObject
{
    Q_OBJECT

public:
    static Singleton& getInstance();

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    GuiApi guiApi;
    DeviceLanguage deviceLanguage;
    DeviceColor deviceColor;
    QString fontSuit;

    int thresholdLow;
    int thresholdHigh;
    gapiHistInfo_t dayInfo;

    void init();

    QPixmap pixLoad(bool bIsLanguage = false,const QString &strDir="",const QString &strPng="");
    DeviceColor getDeviceColor();
    void setDeviceColor(unsigned int nColor);
    DeviceLanguage getDeviceLanguage();
    void setDeviceLanguage(unsigned int nLanguage);

    bool getProcCheck();
    void setProcCheck(bool used);

    UserNum getUserNumber();
    void setUserNumber(int nUserNumber);

    bool touchCheck(const QRect &rect, QMouseEvent* ev);
    int pixelToPoint(int pixelSize);

    QStringList getString(PageNum pageNum,QString textName);

private:
    //Singleton() = default;
    explicit Singleton(QObject* parent = nullptr) : QObject(parent){};
    ~Singleton() = default;

    QString strImgLoot = ":/Image";
    QString strImgPathColor = "/Default";
    QString strImgPathLan = "/KR";

    bool procCheck = false;
    UserNum nUserNumber = USER1;

    static const QHash<unsigned int, QPair<QString, DeviceLanguage>> hashLanguage;
};

#endif // SINGLETON_H
