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

    langData.used = EN;
    setDeviceLanguage(langData.used);

    thresholdLow = 69;
    thresholdHigh = 170;

    histInfo.val[0].valid_flag = 1;
    histInfo.val[0].value = 99;
    histInfo.val[0].hour = 9;
    histInfo.val[0].min = 10;

    histInfo.val[1].valid_flag = 1;
    histInfo.val[1].value = 200;
    histInfo.val[1].hour = 11;
    histInfo.val[1].min = 9;

    histInfo.val[2].valid_flag = 1;
    histInfo.val[2].value = 60;
    histInfo.val[2].hour = 12;
    histInfo.val[2].min = 0;

    histInfo.val[3].valid_flag = 1;
    histInfo.val[3].value = 160;
    histInfo.val[3].hour = 15;
    histInfo.val[3].min = 20;

    histInfo.val[4].valid_flag = 1;
    histInfo.val[4].value = 74;
    histInfo.val[4].hour = 19;
    histInfo.val[4].min = 59;

    for(int i=0; i<USER_MAX; i++)
    {
        QString password = QString::number(i+1).repeated(4);
        qstrncpy(sysUserInfo[i].passwd,password.toUtf8().constData(),sizeof (sysUserInfo[i].passwd));
        qDebug()<<sysUserInfo[i].passwd;
    }



    dispData.color = COLOR_DEFAULT;
    setDeviceColor(dispData.color);

    sysProcAct.act = GAPI_ACT_START;
    sysProcAct.proc = GAPI_PROC_ACT_GAIN;
    sysProcAct.user = static_cast<int>(nUserNumber);

    sysProcMonInfo.valid = 1;
    sysProcMonInfo.err_code = GAPI_PROC_ECODE_NORMAL;

    setCaliGainCompleteCheck(true);
    //caliUserInfo
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

void Singleton::updateCaliUserInfo()
{
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
    qDebug()<<"led_sense: "<<caliUserInfo.led_sense<<", completed: "<<caliUserInfo.completed;

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


//PageSleep
void Singleton::setSleepTime(int nSleepTime)
{
    this->nSleepTime = nSleepTime;
}

int Singleton::getSleepTime()
{
    return this->nSleepTime;
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

QString Singleton::getTextColorGlucoseValue(int glucoseValue, bool bIsBlack)
{
    QString strColor = "color: #666666;";

    switch (getDeviceColor())
    {
    case COLOR_DEFAULT:
        if(glucoseValue<=thresholdLow || glucoseValue>=thresholdHigh)
        {
            strColor = "color: #f70000;";
        }
        else if(glucoseValue<=thresholdLow+GLUCOSE_LOW_PLUS || glucoseValue>=thresholdHigh+GLUCOSE_HIGH_MINUS)
        {
            strColor = "color: #ffb200;";
        }
        else
        {
            if(bIsBlack)
                strColor = "color: #000000;";
            else
                strColor = "color: #52d0ba;";
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



