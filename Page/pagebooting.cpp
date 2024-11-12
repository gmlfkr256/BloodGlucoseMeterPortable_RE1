#include "pagebooting.h"

PageBooting::PageBooting(QRect windowRect) : currentFrame(0)
{
    splashScreenBooting.setGeometry(windowRect);
    splashScreenBooting.setWindowFlag(Qt::SplashScreen);
    pixBooting = Singleton::getInstance().pixLoad(false,strDirPath,"/Happyzone 01_00001.png");

    splashScreenBooting.setPixmap(pixBooting.copy());

    splashScreenBooting.show();

    for(int i=0; i<20; i++)
    {
        QString strPng = QString("/Happyzone 01_000%01.png").arg(QString::number(i).rightJustified(2,'0'));
        pixBooting = Singleton::getInstance().pixLoad(false,strDirPath,strPng);
        splashScreenBooting.setPixmap(pixBooting.copy());
        QThread::msleep(50);
    }
}

QPoint PageBooting::getBootingPoint()
{
    QPoint point;
    point.setX(splashScreenBooting.geometry().x());
    point.setY(splashScreenBooting.geometry().y());

    return point;
}
