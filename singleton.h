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
    CN_BUN,
    LAN_MAX
} DeviceLanguage;

Q_ENUMS(DeviceLanguage)

typedef enum
{
    USER_1 = 0,
    USER_2,
    USER_MAX
} UserNum;

Q_ENUMS(UserNum)

typedef enum
{
    PAGE_PASSWORD = 0,
    PAGE_HOME,
    PAGE_SELECT,
    PAGE_MAX
} PageNum;

Q_ENUMS(PageNum)

typedef enum
{
    PASSWORD_LOGIN = 0,
    PASSWORD_EDIT,
    PASSWORD_DELETE,
    PASSWORD_CONFIRM,
    PASSWORD_REPEAT,
    PASSWORD_MAX
} PasswordStatus;

Q_ENUMS(PasswordStatus)

typedef  enum
{
    PASSWORD_STR_LOGIN_SUCCESS = 0,
    PASSWORD_STR_LOGIN_FAIL,
    PASSWORD_STR_LOGIN_CHANGE,
    PASSWORD_STR_CONFIRM,
    PASSWORD_STR_CONFIRM_FAIL,
    PASSWORD_STR_REPEAT,
    PASSWORD_STR_REPEAT_FAIL,
    PASSWORD_STR_EDIT,
    PASSWORD_STR_EDIT_CONFIRM,
    PASSWORD_STR_EDIT_CHANGE,
    PASSWORD_STR_EDIT_SUCCESS,
    PASSWORD_STR_DELETE,
    PASSWORD_STR_DELETE_CONFIRM,
    PASSWORD_STR_DELETE_SUCCESS,
    PASSWORD_STR_LOGOUT,
    PASSWORD_STR_MAX
} PasswordStrStatus;

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
    gapiHistInfo_t histInfo;
    gapiSysUserInfo_t sysUserInfo[USER_MAX];

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

    PasswordStatus getPasswordStatus();
    void setPasswordStatus(PasswordStatus passwordStatus);

    void updateSysUserInfo();

    bool touchCheck(const QRect &rect, QMouseEvent* ev);
    int pixelToPoint(int pixelSize);

private:
    //Singleton() = default;
    explicit Singleton(QObject* parent = nullptr) : QObject(parent){};
    ~Singleton() = default;

    QString strImgLoot = ":/Image";
    QString strImgPathColor = "/Default";
    QString strImgPathLan = "/KR";

    static const QHash<unsigned int, QPair<QString, DeviceLanguage>> hashLanguage;

    bool procCheck = false;

    UserNum nUserNumber = USER_1;
    PasswordStatus passwordStatus = PASSWORD_LOGIN;
};

#endif // SINGLETON_H
