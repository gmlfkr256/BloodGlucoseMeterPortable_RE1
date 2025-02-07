#include "singleton.h"

// 정적 멤버 초기화
const QHash<unsigned int, QPair<QString, DeviceLanguage>> Singleton::hashLanguage = {
    { static_cast<unsigned int>(DeviceLanguage::KR), { "/KR", DeviceLanguage::KR } },
    { static_cast<unsigned int>(DeviceLanguage::EN), { "/EN", DeviceLanguage::EN } },
    { static_cast<unsigned int>(DeviceLanguage::JP), { "/JP", DeviceLanguage::JP } },
    { static_cast<unsigned int>(DeviceLanguage::SC), { "/SC", DeviceLanguage::SC } },
    { static_cast<unsigned int>(DeviceLanguage::TC), { "/TC", DeviceLanguage::TC } },
    { static_cast<unsigned int>(DeviceLanguage::ES), { "/ES", DeviceLanguage::ES } },
};

void Singleton::init()
{

#if DEVICE
    //updateSysUserInfo();
#else

    langData.used = KR;
    setDeviceLanguage(langData.used);

    thresholdLow = 69;
    thresholdHigh = 170;

    hisInfo[0].date = 20250205;//QDate::currentDate().toString("yyyyMMdd").toInt();

    /*
    hisInfo[0].val[0].valid_flag = 1;
    hisInfo[0].val[0].value = 69;
    hisInfo[0].val[0].hour = 7;
    hisInfo[0].val[0].min = 13;

    hisInfo[0].val[1].valid_flag = 1;
    hisInfo[0].val[1].value = 74;
    hisInfo[0].val[1].hour = 11;
    hisInfo[0].val[1].min = 9;

    hisInfo[0].val[2].valid_flag = 1;
    hisInfo[0].val[2].value = 220;
    hisInfo[0].val[2].hour = 12;
    hisInfo[0].val[2].min = 0;

    hisInfo[0].val[3].valid_flag = 1;
    hisInfo[0].val[3].value = 100;
    hisInfo[0].val[3].hour = 15;
    hisInfo[0].val[3].min = 20;

    hisInfo[0].val[4].valid_flag = 1;
    hisInfo[0].val[4].value = 250;
    hisInfo[0].val[4].hour = 19;
    hisInfo[0].val[4].min = 59;
    */



    QDate currentDate = QDate::currentDate();

    for (int dayIndex = 1; dayIndex <= 90; ++dayIndex) // 0: 오늘, 1~90: 과거
    {
        // 날짜 설정
        QDate targetDate = currentDate.addDays(-dayIndex);
        hisInfo[dayIndex].date = targetDate.toString("yyyyMMdd").toInt();

        int lastHour = 0; // 시간을 순차적으로 증가시키기 위한 변수

        for (int valIndex = 0; valIndex < 8; ++valIndex) // val 0 ~ 7
        {
            // valid_flag 랜덤 생성 (0 또는 1)
            hisInfo[dayIndex].val[valIndex].valid_flag = (QRandomGenerator::global()->bounded(8) == 0) ? 1 : 0; // 0 또는 1

            if (hisInfo[dayIndex].val[valIndex].valid_flag == 1)
            {
                // value는 60 ~ 250 범위의 랜덤 값
                hisInfo[dayIndex].val[valIndex].value = QRandomGenerator::global()->bounded(60, 251);

                // 시간은 이전 시간 이후로 랜덤하게 증가
                int hourIncrement = QRandomGenerator::global()->bounded(1, 4); // 1 ~ 3시간 증가
                lastHour += hourIncrement;

                // 시간과 분 설정
                if (lastHour >= 24) // 24시간을 초과하면 마지막 시간으로 고정
                {
                    lastHour = 23;
                    hisInfo[dayIndex].val[valIndex].hour = lastHour;
                    hisInfo[dayIndex].val[valIndex].min = 59;
                }
                else
                {
                    hisInfo[dayIndex].val[valIndex].hour = lastHour;
                    hisInfo[dayIndex].val[valIndex].min = QRandomGenerator::global()->bounded(60); // 0 ~ 59
                }
            }
            else
            {
                // valid_flag가 0일 경우 기본값으로 초기화
                hisInfo[dayIndex].val[valIndex].value = 0;
                hisInfo[dayIndex].val[valIndex].hour = 0;
                hisInfo[dayIndex].val[valIndex].min = 0;
            }
        }
    }

    for(int i=0; i<USER_MAX; i++)
    {
        QString password = QString::number(i+1).repeated(4);
        qstrncpy(sysUserInfo[i].passwd,password.toUtf8().constData(),sizeof (sysUserInfo[i].passwd));
        qDebug()<<sysUserInfo[i].passwd;
    }



    dispData.color = COLOR_DEFAULT;
    setDeviceColor(dispData.color);
    dispData.ts_timeout = 0;

    sysProcAct.act = GAPI_ACT_START;
    sysProcAct.proc = GAPI_PROC_ACT_GAIN;
    sysProcAct.user = static_cast<int>(nUserNumber);

    sysProcMonInfo.valid = 1;
    sysProcMonInfo.err_code = GAPI_PROC_ECODE_NORMAL;

    setCaliGainCompleteCheck(true);

    spkData.vol = 50;
    spkData.used = 1;
#endif
}

Singleton& Singleton::getInstance()
{
    static Singleton instance;
    return instance;
}

void Singleton::pixLoad(QLabel *label,bool bIsLanguage, const QString &strDir, const QString &strPng)
{
    QPixmap pixmap;
    QString strLan;
    if(bIsLanguage == false)
    {
        strLan = "/Public";
    }
    else
    {
        strLan = strImgPathLan;
    }

    QString strImgPath = strImgRoot+ strImgPathColor + strLan + strDir + strPng;
    QString strImgPathSub;

    if(!pixmap.load(strImgPath,Q_NULLPTR))
    {
        qDebug()<<"empty: "<<strImgPath;

#if IMAGE_FILE_CHECK
        QFile file(QCoreApplication::applicationDirPath()+"/ImageCheck.txt");

        if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            QTextStream stream(&file);
            stream << strImgPath << "\n";
            file.close();
        }
#endif

        strImgPathSub = strImgRoot+"/Default"+strLan+strDir+strPng;
        if(!pixmap.load(strImgPathSub,Q_NULLPTR))
        {
            if(!strImgPathSub.contains("/Public"))
            {
                strImgPathSub = strImgRoot+strImgPathColor+"/KR"+strDir+strPng;
                if(!pixmap.load(strImgPathSub,Q_NULLPTR))
                {
                    strImgPathSub = strImgRoot+"/Default/KR"+strDir+strPng;
                    if(!pixmap.load(strImgPathSub,Q_NULLPTR))
                    {
                        qDebug()<<"strImgPathSub Image Empty: "<<strImgPathSub;
                    }
                }
            }
        }
    }

    label->setPixmap(pixmap.copy());
}

DeviceColor Singleton::getDeviceColor()
{
    return deviceColor;
}

void Singleton::setDeviceColor(unsigned int nColor)
{
    switch (nColor)
    {
    case COLOR_DEFAULT:
        strImgPathColor = "/Default";
        break;
    case COLOR_BLUE:
        strImgPathColor = "/Blue";
        break;
    case COLOR_RED:
        strImgPathColor = "/Red";
        break;
    }

    deviceColor = static_cast<DeviceColor>(nColor);
}

DeviceLanguage Singleton::getDeviceLanguage()
{
    return deviceLanguage;
}

void Singleton::setDeviceLanguage(unsigned int nLanguage)
{
    /*
    switch (nLanguage)
    {
    case DeviceLanguage::KR:
        strImgPathLan = "/KR";
        deviceLanguage = DeviceLanguage::KR;
        break;
    case DeviceLanguage::EN:
        strImgPathLan = "/EN";
        deviceLanguage = DeviceLanguage::EN;
        break;
    case DeviceLanguage::JP:
        strImgPathLan = "/JP";
        deviceLanguage = JP;
        break;
    case DeviceLanguage::CN_GAN:
        strImgPathLan = "/CN_GAN";
        break;
    case DeviceLanguage::CN_BUN:
        strImgPathLan = "/CN_BUN";
        break;
    }
   */
    if (hashLanguage.contains(nLanguage))
    {
        auto pair = hashLanguage.value(nLanguage);
        strImgPathLan = pair.first;
        deviceLanguage = pair.second;
        qDebug() << "Language set to:" << strImgPathLan;
    }
    else
    {
        qWarning() << "Invalid language code";
    }
}

UserNum Singleton::getUserNumber()
{
    return nUserNumber;
}

void Singleton::setUserNumber(int nUserNumber)
{
    if(nUserNumber>= USER_1 && nUserNumber<= USER_MAX)
        this->nUserNumber = static_cast<UserNum> (nUserNumber);
    else
    {
        qWarning()<<"Invalid user Number: "<<nUserNumber;
        this->nUserNumber = USER_1;
    }
}

bool Singleton::getProcCheck()
{
    return procCheck;
}

void Singleton::setProcCheck(bool used)
{
    procCheck = used;
}

//PagePasswordStatus
PasswordStatus Singleton::getPasswordStatus()
{
    return passwordStatus;
}

void Singleton::setPasswordStatus(PasswordStatus passwordStatus)
{
    this->passwordStatus = passwordStatus;
}

PasswordStatus Singleton::getPasswordStatusPrev()
{
    return passwordStatusPrev;
}

void Singleton::setPasswordStatusPrev(PasswordStatus passwordStatus)
{
    this->passwordStatusPrev = passwordStatus;
}

void Singleton::updateSysUserInfo()
{
    for(int i=0; i<static_cast<int>(USER_MAX); i++)
    {
#if DEVICE
        if(guiApi.glucoseGetUserInfo(i,&sysUserInfo[i]) == GAPI_SUCCESS)
            qDebug()<<"sysUserInfo["+QString::number(i)+"] update Success";
#endif
    }
}

QString Singleton::getPasswordChage()
{
    return this->strPasswordChange;
}

void Singleton::setPasswordChange(QString strPasswordChange)
{
    this->strPasswordChange = strPasswordChange;
}

void Singleton::setUserPasswordChange()
{
#if DEVICE
    guiApi.glucoseSetUserPassword(nUserNumber,strPasswordChange.toUtf8().data());
#else
    sysUserInfo[getUserNumber()].passwd[15] = {0};

    strncpy(sysUserInfo[getUserNumber()].passwd,strPasswordChange.toUtf8().data(),sizeof (sysUserInfo[getUserNumber()].passwd)-1);
#endif

}

//PagePasswordStrStatus
PasswordStrStatus Singleton::getPasswordStrStatus()
{
    return passwordStrSatus;
}

void Singleton::setPasswordStrStatus(PasswordStrStatus passwordStrStatus)
{
    this->passwordStrSatus = passwordStrStatus;
}


//UserLogin
void Singleton::
actUserLogin(int i)
{
    setUserNumber(i);
#if DEVICE
    guiApi.glucoseActUserLogin(i);
    guiApi.glucoseCaliGetUserInfo(&caliUserInfo);
    guiApi.glucoseGetDispData(&dispData);
    qDebug()<<"dispData.ts_timeout: "<<dispData.ts_timeout;
    guiApi.glucoseGetLangData(&langData);
    setDeviceLanguage(langData.used);
    guiApi.glucoseGetGlucoseLimit(&glucoseLimit);
    thresholdLow = glucoseLimit.low;
    thresholdHigh = glucoseLimit.high;
#else
    setDeviceLanguage(langData.used);
#endif
}

QString Singleton::getStrNowUserPassword()
{
    return sysUserInfo[nUserNumber].passwd;
}

//PageSelect
void Singleton::setTimeStatus(TimeStatus timeStatus)
{
    this->timeStatus = timeStatus;
}

TimeStatus Singleton::getTimeStatus()
{
    return this->timeStatus;
}

//CaliGainCompleteCheck

void Singleton::updateCaliUserInfo()
{
    if(nUserNumber!=USER_MAX)
        guiApi.glucoseCaliGetUserInfo(&caliUserInfo);
}

void Singleton::setCaliGainCompleteCheck(bool caliGainCompleteCheck)
{
    if(caliGainCompleteCheck == true)
    {
        caliUserInfo.led_sense = true;
        caliUserInfo.completed = true;
    }
    else
    {
        caliUserInfo.led_sense = false;
        caliUserInfo.completed = false;
    }
}

bool Singleton::getCaliGainCompleteCheck()
{
#if DEVICE
    updateCaliUserInfo();
#endif
    //qDebug()<<"led_sense: "<<caliUserInfo.led_sense<<", completed: "<<caliUserInfo.completed;

    if(getGainCompleteCheck() && getCaliCompleteCheck())
        return true;

    return false;
}

bool Singleton::getGainCompleteCheck()
{
#if DEVICE
    updateCaliUserInfo();
#endif
    return caliUserInfo.led_sense;
}

bool Singleton::getCaliCompleteCheck()
{

#if DEVICE
    updateCaliUserInfo();
#else
    int nCaliIndexCount = 0;

    for(int i=0; i<5; i++)
    {
        if(getCaliIndexCompleteCheck(i))
            nCaliIndexCount++;
    }

    if(nCaliIndexCount == 5 && getCaliValueCompleteCheck())
        caliUserInfo.completed = 1;
#endif

    return caliUserInfo.completed;
}

bool Singleton::getCaliIndexCompleteCheck(int nCaliSelectIndex)
{
#if DEVICE
    updateCaliUserInfo();
#endif
    return caliUserInfo.val[nCaliSelectIndex].valid;
}

bool Singleton::getCaliValueCompleteCheck()
{
#if DEVICE
    updateCaliUserInfo();
#endif
    int nValueCount = 0;
    for(int i=0; i<5; i++)
    {
        if(caliUserInfo.glucose_val[i] != 0)
            nValueCount++;
    }

    if(nValueCount == 5)
        return true;
    else
        return false;
}

//PageGraph
void Singleton::setGraphMode(GraphMode graphMode)
{
    this->graphMode = graphMode;

    sysProcAct.act = GAPI_ACT_START;

    switch (this->graphMode)
    {
    case GRAPH_GAIN:
        sysProcAct.proc = GAPI_PROC_ACT_GAIN;
        break;
    case GRAPH_CALI:
        sysProcAct.proc = GAPI_PROC_ACT_CALIBRATION;
        break;
    case GRAPH_MEASURE:
        sysProcAct.proc = GAPI_PROC_ACT_MEASURE;
        break;
    case GRAPH_MAX:
        break;
    }
    sysProcAct.user = nUserNumber;
}

GraphMode Singleton::getGraphMode()
{
    return graphMode;
}

//PageCaliSelect
void Singleton::setCaliSelectIndex(CaliSelIndex caliSelectNum)
{
    this->caliSelectIndex = caliSelectNum;
}

CaliSelIndex Singleton::getCaliSelectIndex()
{
    return caliSelectIndex;
}

//PageCaliResultMulti
void Singleton::setCaliSelectOrder(CaliSelOrder caliSelectOrder)
{
    this->caliSelectOrder = caliSelectOrder;
}

CaliSelOrder Singleton::getCaliSelectOrder()
{
    return caliSelectOrder;
}

void Singleton::setCaliIndexCheck(bool bConfirm)
{
    this->bCaliIndexCheck = bConfirm;
}

bool Singleton::getCaliIndexCheck()
{
    return bCaliIndexCheck;
}

//PageCaliValue

void Singleton::setCaliValue(int nValue)
{
    caliSetGlucose.user = getUserNumber();
    caliSetGlucose.idx= getCaliSelectIndex();
    caliSetGlucose.glucose = nValue;


#if DEVICE
    guiApi.glucoseCaliSetGlucoseValue(&caliSetGlucose);
#else
    caliUserInfo.glucose_val[getCaliSelectIndex()] = nValue;
#endif
}

//PageInitConfirm
void Singleton::setInitIndex(InitIndex initIndex)
{
    this->initIndex = initIndex;
}

InitIndex Singleton::getInitIndex()
{
    return this->initIndex;
}

//PageThreshold
void Singleton::setThresholdIndex(ThresholdIndex thresholdIndex)
{
    this->thresHoldIndex = thresholdIndex;
}

ThresholdIndex Singleton::getThresholdIndex()
{
    return thresHoldIndex;
}

//PageThreshold
void Singleton::setThresholdValue(ThresholdIndex thresholdIndex, int nValue)
{
    if(thresholdIndex == THRESHOLD_LOW)
        thresholdLow = nValue;
    else if(thresholdIndex == THRESHOLD_HIGH)
        thresholdHigh = nValue;
    else
        qDebug()<<"set thresholdvalue fail";

    //gapiGlucoseLimit_t glucoseLimit;
    glucoseLimit.low = thresholdLow;
    glucoseLimit.high = thresholdHigh;

#if DEVICE
    guiApi.glucoseSetGlucoseLimit(&glucoseLimit);
#endif
}

//PageUpagrde
void Singleton::getDeviceVersion()
{
#if DEVICE
    if(guiApi.getFwVersion(chFWVer,chBleName,chHWVer,chSerialNumber) == GAPI_SUCCESS)
    {
        strFWVer = chFWVer;
        strHWVer = chHWVer;
        strSWVer = chFWVer;
        strBleName = chBleName;
        strSerialNumber = chSerialNumber;
        //qDebug()<<"DeviceVersion get Success";
    }
#endif
}

QString Singleton::getDeviceVersion(VersionIndex versionIndex)
{
    getDeviceVersion();

    switch (versionIndex)
    {
    case VERSION_FW:
        return strFWVer;
        break;
    case VERSION_HW:
        return strHWVer;
        break;
    case VERSION_SW:
        return strSWVer;
        break;
    case VERSION_BLE:
        return strBleName;
        break;
    case VERSION_SERIAL:
        return strSerialNumber;
        break;
    default:
        qDebug()<<"getDeviceVersion Fail";
        return QString();
        break;
    }
}
//public
bool Singleton::touchCheck(const QRect &rect, QMouseEvent* ev)
{
    return rect.contains(ev->pos());
}

int Singleton::pixelToPoint(int pixelSize)
{
    float dpi = QApplication::primaryScreen()->logicalDotsPerInch();

    return static_cast<int>((pixelSize*72.0)/dpi);
}

void Singleton::getHistory(int day)
{
#if DEVICE
    //guiApi.getHistory(day,&histInfo);
    guiApi.getHistory(day,&hisInfo[day]);
#else
    Q_UNUSED(day);
#endif
}

void Singleton::getHistoryAll()
{
#if DEVICE
    guiApi.getHistoryAll(hisInfo);
#endif
}

QString Singleton::getTextColorGlucoseValue(int glucoseValue, bool bIsBlack)
{
    QString strColorText = "color:";
    QString strColor = getColorGlucoseValue(glucoseValue);

    strColorText += strColor+";";

    if(bIsBlack && strColor=="#52d0ba")
        strColorText = "color: #000000;";

    //qDebug()<<"getTextColorGluocseValue: "<<strColorText;
    return strColorText;
}

QString Singleton::getBgColorGlucoseValue(int glucoseValue)
{
    QString strColorBg = "background-color:";
    QString strColor = getColorGlucoseValue(glucoseValue);

    strColorBg += strColor+";";

    //qDebug()<<"getBgColorGlucoseValue: "<<strColorBg;
    return strColorBg;
}

QString Singleton::getColorGlucoseValue(const int &glucoseValue)
{
    QString strColor = "#666666";

    switch (getDeviceColor())
    {
    case COLOR_DEFAULT:
        if(glucoseValue<=thresholdLow || glucoseValue>=thresholdHigh)
        {
            strColor = "#f70000";
        }
        else if(glucoseValue<=thresholdLow+GLUCOSE_LOW_PLUS || glucoseValue>=thresholdHigh+GLUCOSE_HIGH_MINUS)
        {
            strColor = "#ffb200";
        }
        else
        {
            strColor = "#52d0ba";
        }
        break;
    case COLOR_BLUE:
        break;
    case COLOR_RED:
        break;
    }

    return strColor;
}

BloodSugarLevel Singleton::getBloodSugarLevel(int glucoseValue)
{
    if(glucoseValue<=thresholdLow)
        return BLOOD_WARNING_LOW;
    else if(glucoseValue>=thresholdHigh)
        return BLOOD_WARNING_HIGH;
    else if(glucoseValue<=thresholdLow+GLUCOSE_LOW_PLUS)
        return BLOOD_CAUTION_LOW;
    else if(glucoseValue>=thresholdHigh+GLUCOSE_HIGH_MINUS)
        return BLOOD_CAUTION_HIGH;
    else
        return BLOOD_NORMAL;
}

void Singleton::setPageNumPrev(PageNum pageNumPrev)
{
    this->pageNumPrev = pageNumPrev;
}

PageNum Singleton::getPageNumPrev()
{
    return pageNumPrev;
}



