#include "singleton.h"

// 정적 멤버 초기화
const QHash<unsigned int, QPair<QString, DeviceLanguage>> Singleton::hashLanguage = {
    { static_cast<unsigned int>(DeviceLanguage::KR), { "/KR", DeviceLanguage::KR } },
    { static_cast<unsigned int>(DeviceLanguage::EN), { "/EN", DeviceLanguage::EN } },
    { static_cast<unsigned int>(DeviceLanguage::JP), { "/JP", DeviceLanguage::JP } },
    { static_cast<unsigned int>(DeviceLanguage::CN_GAN), { "/CN_GAN", DeviceLanguage::CN_GAN } },
    { static_cast<unsigned int>(DeviceLanguage::CN_BUN), { "/CN_BUN", DeviceLanguage::CN_BUN } }
};

void Singleton::init()
{

#if DEVCIE
    updateSysUserInfo();
#else
    thresholdLow = 69;
    thresholdHigh = 170;

    histInfo.val[0].valid_flag = 1;
    histInfo.val[0].value = 99;
    histInfo.val[0].hour = 9;
    histInfo.val[0].min = 10;

    for(int i=0; i<USER_MAX; i++)
    {
        QString password = QString::number(i+1).repeated(4);
        qstrncpy(sysUserInfo[i].passwd,password.toUtf8().constData(),sizeof (sysUserInfo[i].passwd));
        qDebug()<<sysUserInfo[i].passwd;
    }

    langData.used = EN;
    setDeviceLanguage(langData.used);

    dispData.color = COLOR_DEFAULT;
    setDeviceColor(dispData.color);

    //caliUserInfo
#endif
}

Singleton& Singleton::getInstance()
{
    static Singleton instance;
    return instance;
}

QPixmap Singleton::pixLoad(bool bIsLanguage, const QString &strDir, const QString &strPng)
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

    QString strImgPath = strImgLoot+ strImgPathColor + strLan + strDir + strPng;
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

        strImgPathSub = strImgLoot+"/Default"+strLan+strDir+strPng;
        if(!pixmap.load(strImgPathSub,Q_NULLPTR))
        {
            if(!strImgPathSub.contains("/Public"))
            {
                strImgPathSub = strImgLoot+strImgPathColor+"/KR"+strDir+strPng;
                if(!pixmap.load(strImgPathSub,Q_NULLPTR))
                {
                    strImgPathSub = strImgLoot+"/Default/KR"+strDir+strPng;
                    if(!pixmap.load(strImgPathSub,Q_NULLPTR))
                    {
                        qDebug()<<"strImgPathSub Image Empty: "<<strImgPathSub;
                    }
                }
            }
        }
    }

    return pixmap;
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
    for(int i=0; i<USER_MAX; i++)
    {
        if(guiApi.glucoseGetUserInfo(i,&sysUserInfo[i]) == GAPI_SUCCESS)
            qDebug()<<"sysUserInfo["+QString::number(i)+"] update Success";
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
    guiApi.glucoseSetUserPassword(nUserNumber,strPasswordChange.toUtf8().data());
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
void Singleton::actUserLogin(int i)
{
#if DEVICE
    guiApi.glucoseActUserLogin(i); 
    guiApi.glucoseCaliGetUserInfo(&caliUserInfo);
    guiApi.glucoseGetDispData(&dispData); 
    guiApi.glucoseGetLangData(&langData);
#else
    setSleepTime(dispData.ts_timeout);
    setUserNumber(i);
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
bool Singleton::getCaliGainCompleteCheck()
{
    if(caliUserInfo.led_sense !=0 && caliUserInfo.completed != 0)
        return true;

    return false;
}

//PageSleep
void Singleton::setSleepTime(int nSleepTime)
{
    this->nSleepTime = nSleepTime;
}

int Singleton::getSleepTime()
{
    return this->nSleepTime;
}

bool Singleton::touchCheck(const QRect &rect, QMouseEvent* ev)
{
    return rect.contains(ev->pos());
}

int Singleton::pixelToPoint(int pixelSize)
{
    float dpi = QApplication::primaryScreen()->logicalDotsPerInch();

    return static_cast<int>((pixelSize*72.0)/dpi);
}

QString Singleton::getTextColorGlucoseValue(int glucoseValue)
{
    QString strColor = "color: #666666;";

    switch (getDeviceColor())
    {
    case COLOR_DEFAULT:
        if(glucoseValue<=thresholdLow || glucoseValue>=thresholdHigh)
        {
            strColor = "color: #f2b29;";
        }
        else if(glucoseValue<=thresholdLow+GLUCOSE_LOW_PLUS || glucoseValue>=thresholdHigh+GLUCOSE_HIGH_MINUS)
        {
            strColor = "color: #ff6f00;";
        }
        else
        {
            strColor = "color: #000000;";
        }
        break;
    case COLOR_BLUE:
        break;
    case COLOR_RED:
        break;
    }

    return strColor;
}


