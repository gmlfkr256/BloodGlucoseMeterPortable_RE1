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
    deviceLanguage = KR;

#if DEVICE == false
    thresholdLow = 69;
    thresholdHigh = 170;

    dayInfo.val[0].valid_flag = 1;
    dayInfo.val[0].value = 99;
    dayInfo.val[0].hour = 9;
    dayInfo.val[0].min = 10;
#endif

}

Singleton& Singleton::getInstance()
{
    static Singleton instance;
    instance.init();
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
    if(nUserNumber>= USER1 && nUserNumber<=ROOT)
        this->nUserNumber = static_cast<UserNum> (nUserNumber);
    else
    {
        qWarning()<<"Invalid user Number: "<<nUserNumber;
        this->nUserNumber = USER1;
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

bool Singleton::touchCheck(const QRect &rect, QMouseEvent* ev)
{
    return rect.contains(ev->pos());
}

int Singleton::pixelToPoint(int pixelSize)
{
    float dpi = QApplication::primaryScreen()->logicalDotsPerInch();

    return static_cast<int>((pixelSize*72.0)/dpi);
}

QStringList Singleton::getString(PageNum pageNum, QString textName)
{
    QStringList listStr;
    switch (deviceLanguage)
    {
    case KR:
        switch (pageNum)
        {
        case PAGE_HOME:
            if(textName.contains("title"))
            {
                listStr = QStringList{"기상","조식 전","조식 후","중식 전","중식 후","석식 전","석식 후","취침"};
            }
            break;
        case PAGE_SELECT:
            break;
        case PAGE_MAX:
            break;
        }
        break;
    case EN:
        switch (pageNum)
        {
        case PAGE_HOME:
            if(textName.contains("title"))
            {
                listStr = QStringList{"Wake\nUp","Before\nBreakfast","After\nBreakfast","Before\nLunch","After\nLunch","Before\nDinner","After\nDinner","Bed\nTime"};
            }
            break;
        case PAGE_SELECT:
            break;
        case PAGE_MAX:
            break;
        }
        break;
    case JP:
        break;
    case CN_GAN:
        break;
    case CN_BUN:
        break;
    default:
        return listStr<<"EMPTY";
        break;
    }

    return listStr;
}

