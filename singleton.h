#ifndef SINGLETON_H
#define SINGLETON_H

#include <GlobalMain.h>

#define GLUCOSE_LOW_PLUS 5
#define GLUCOSE_HIGH_MINUS -30

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
    SC,
    TC,
    ES,
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
    PAGE_PASSWORD_CONFIRM,
    PAGE_HOME,
    PAGE_SELECT,
    PAGE_MENU,
    PAGE_CALI_CHECK,
    PAGE_CALI_GAIN_CONFIRM,
    PAGE_GRAPH,
    PAGE_CALI_GAIN_RESULT,
    PAGE_CALI_SELECT,
    PAGE_CALI_SELECT_INFO,
    PAGE_CALI_CONFIRM,
    PAGE_CALI_VALUE,
    PAGE_CALI_RESULT,
    PAGE_CALI_RESULT_MULTI,
    PAGE_RESULT,
    PAGE_INIT,
    PAGE_INIT_CONFIRM,
    PAGE_THRESHOLD,
    PAGE_THRESHOLD_VALUE,
    PAGE_SOUND,
    PAGE_SLEEP,
    PAGE_DATETIME,
    PAGE_UPGRADE,
    PAGE_UPGRADE_CONFIRM,
    PAGE_DEVICEINFO,
    PAGE_USERINFO,
    PAGE_BATPOPUP,
    PAGE_REVERSE,
    PAGE_TRANS,
    PAGE_HISTORY,
    PAGE_HISTORY_RESULT,
    PAGE_DEBUG,
    PAGE_DEBUG_SYS,
    PAGE_DEBUG_USB,

    //PAGE_COLOR,

    CUSTOM_BUTTON,
    CUSTOM_COMPONENT,
    CUSTOM_COMPONENT_DATE,
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

typedef enum
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

Q_ENUMS(PasswordStrStatus)

typedef enum
{
    WAKE_UP = 0,
    BREAKFAST_BEFORE,
    BREAKFAST_AFTER,
    LUNCH_BEFROE,
    LUNCH_AFTER,
    DINNER_BEFORE,
    DINNER_AFTER,
    BED_TIME
} TimeStatus;

Q_ENUMS(TimeStatus);

typedef enum
{
    BLOOD_NORMAL = 0,
    BLOOD_CAUTION_LOW,
    BLOOD_CAUTION_HIGH,
    BLOOD_WARNING_LOW,
    BLOOD_WARNING_HIGH
} BloodSugarLevel;

Q_ENUMS(BloodSuarLevel);

typedef enum
{
    GRAPH_GAIN = 0,
    GRAPH_CALI,
    GRAPH_MEASURE,
    GRAPH_MAX
} GraphMode;

Q_ENUMS(GraphMode);

typedef enum
{
    CALI_0 = 0,
    CALI_1,
    CALI_2,
    CALI_3,
    CALI_4,
    CALI_MAX
} CaliSelIndex;

Q_ENUMS(CaliSelIndex);

typedef enum
{
    CALI_ORDER_0 = 0,
    CALI_ORDER_1,
    CALI_ORDER_2,
    CALI_ORDER_MAX
} CaliSelOrder;

Q_ENUMS(CaliSelOrder);

typedef enum
{
    INIT_FACTORY_Q,
    INIT_FACTORY_A,
    INIT_BLUETOOTH_Q,
    INIT_BLUETOOTH_A,
    INIT_CALI_Q,
    INIT_CALI_A,
    INIT_MAX
} InitIndex;

Q_ENUMS(InitIndex);

typedef enum
{
    THRESHOLD_LOW,
    THRESHOLD_HIGH,
    THRESHOLD_MAX
} ThresholdIndex;

Q_ENUMS(ThresholdIndex);

typedef enum
{
    SLEEP_30S,
    SLEEP_1M,
    SLEEP_3M,
    SLEEP_5M,
    SLEEP_10M,
    SLEEP_NONE
} SleepIndex;

Q_ENUMS(SleepIndex)

typedef enum
{
    VERSION_FW,
    VERSION_HW,
    VERSION_SW,
    VERSION_BLE,
    VERSION_SERIAL
} VersionIndex;

Q_ENUMS(VersionIndex)

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
    QString fontJP;
    QString fontTC;
    QString fontSC;

    int thresholdLow;
    int thresholdHigh;
    const int nThresholdLimitLowMin = 53;
    const int nThresholdLimitLowMax = 69;
    const int nThresholdLimitHighMin = 170;
    const int nThresholdLimitHighMax = 400;
    gapiSysUserInfo_t sysUserInfo[USER_MAX];
    gapiCaliUserInfo_t caliUserInfo;
    gapiDispData_t dispData;
    gapiLangData_t langData;
    gapiSysProcAct_t sysProcAct;
    gapiSysProcMonInfo_t sysProcMonInfo;
    gapiCaliSetGlucose_t caliSetGlucose;
    gapiHistValue_t histValue;
    gapiSpkData_t spkData;
    gapiGlucoseLimit_t glucoseLimit;
    gapiHistInfo_t hisInfo[91];

    gapiSysOprData_t sysData;

    int caliIndexCount = 0;
    int nSleepTimeCount = 0;
    bool isComMenuCheck = false;
    bool isBatZero = true;
    bool isBatCharging = false;

    bool isTouchCtrl = false;
    int nTouchTime = 100;

    int nHisInfoSelectedIndex = 0;
    bool bIsHistorySelect = false;

    bool bIsDetachCtrlBat = false;

    PageNum currentPage = PAGE_MAX;

    void init();

    void pixLoad(QLabel* label,bool bIsLanguage = false,const QString &strDir="",const QString &strPng="");
    DeviceColor getDeviceColor();
    void setDeviceColor(unsigned int nColor);
    DeviceLanguage getDeviceLanguage();
    void setDeviceLanguage(unsigned int nLanguage);

    bool getProcCheck();
    void setProcCheck(bool used);

    UserNum getUserNumber();
    void setUserNumber(int nUserNumber);

    //PagePasswordStatus
    PasswordStatus getPasswordStatus();
    void setPasswordStatus(PasswordStatus passwordStatus);
    PasswordStatus getPasswordStatusPrev();
    void setPasswordStatusPrev(PasswordStatus passwordStatus);
    void updateSysUserInfo();
    void setPasswordChange(QString strPasswordChange);
    QString getPasswordChage();
    void setUserPasswordChange();

    //PagePasswordStrStatus
    PasswordStrStatus getPasswordStrStatus();
    void setPasswordStrStatus(PasswordStrStatus passwordStrStatus);

    //UserLogin
    void actUserLogin(int i);
    QString getStrNowUserPassword();

    //PageHome


    //PageSelect
    void setTimeStatus(TimeStatus timeStatus);
    TimeStatus getTimeStatus();

    //CaliCompleteCheck
    void updateCaliUserInfo();
    void setCaliGainCompleteCheck(bool caliGainCompleteCheck = false);
    bool getCaliGainCompleteCheck();
    bool getGainCompleteCheck();
    bool getCaliCompleteCheck();
    bool getCaliIndexCompleteCheck(int nCaliSelectIndex);
    bool getCaliValueCompleteCheck();

    //PageGraph
    void setGraphMode(GraphMode graphMode);
    GraphMode getGraphMode();

    //PageCaliSelect
    void setCaliSelectIndex(CaliSelIndex caliSelectIndex);
    CaliSelIndex getCaliSelectIndex();

    //PageCaliResultMulti
    void setCaliSelectOrder(CaliSelOrder caliSelectOrder);
    CaliSelOrder getCaliSelectOrder();
    void setCaliIndexCheck(bool bConfirm);
    bool getCaliIndexCheck();

    //PageCaliValue
    void setCaliValue(int nValue);

    //PageInitConfirm
    void setInitIndex(InitIndex initIndex);
    InitIndex getInitIndex();

    //PageThreshold
    void setThresholdIndex(ThresholdIndex thresholdIndex);
    ThresholdIndex getThresholdIndex();

    //PageThresholdValue
    void setThresholdValue(ThresholdIndex thresholdIndex, int nValue);

    //PageUpgrade
    void getDeviceVersion();
    QString getDeviceVersion(VersionIndex versionIndex);

    //public
    bool touchCheck(const QRect &rect, QMouseEvent* ev);
    int pixelToPoint(int pixelSize);

    void getHistory(int day);
    void getHistoryAll();

    QString getTextColorGlucoseValue(int glucoseValue,bool bInBlack = false);
    QString getBgColorGlucoseValue(int glucoseValue);
    QString getColorGlucoseValue(const int &glucoseValue);
    BloodSugarLevel getBloodSugarLevel(int glucoseValue);

    void setPageNumPrev(PageNum pageNumPrev);
    PageNum getPageNumPrev();

private:
    //Singleton() = default;
    explicit Singleton(QObject* parent = nullptr) : QObject(parent){init();};
    ~Singleton() = default;

    QString strImgRoot = ":/Image";
    QString strImgPathColor = "/Default";
    QString strImgPathLan = "/KR";

    static const QHash<unsigned int, QPair<QString, DeviceLanguage>> hashLanguage;

    PageNum pageNumPrev = PAGE_MAX;

    bool procCheck = false;

    //PagePassword
    UserNum nUserNumber = USER_MAX;
    PasswordStatus passwordStatus = PASSWORD_LOGIN;
    PasswordStatus passwordStatusPrev = PASSWORD_MAX;
    QString strPasswordChange;

    //PagePasswordConfirm
    PasswordStrStatus passwordStrSatus = PASSWORD_STR_LOGIN_SUCCESS;

    //PageSelect
    TimeStatus timeStatus = WAKE_UP;

    //PageGraph
    GraphMode graphMode = GRAPH_MAX;

    //PageCaliSelect
    CaliSelIndex caliSelectIndex = CALI_0;

    //PageCaliResultMulti
    CaliSelOrder caliSelectOrder = CALI_ORDER_0;
    bool bCaliIndexCheck = false;

    //PageInitConfirm
    InitIndex initIndex = INIT_FACTORY_A;

    //PageThreshold
    ThresholdIndex thresHoldIndex = THRESHOLD_LOW;

    //PageUpgrade
    char chFWVer[128],chHWVer[128],chBleName[128],chSerialNumber[128];
    QString strFWVer = "2.3;2.1;1.2.1";
    QString strHWVer = "4.0";//"test2";
    QString strSWVer = "2.3;2.1;1.2.1";//test3";
    QString strBleName = "HAPPYZONE-007AB0";//"test4";
    QString strSerialNumber = "PGM900-2105-0000004";//"text5";
};

#endif // SINGLETON_H
