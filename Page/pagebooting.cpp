#include "pagebooting.h"

PageBooting::PageBooting(QRect windowRect) : currentFrame(0)
{
    splashScreenBooting.setGeometry(windowRect);
    //splashScreenBooting.setWindowFlags(splashScreenBooting.windowFlags() | Qt::WindowStaysOnTopHint);
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
    /*
    splashScreenBooting.show();
    QTimer* timerImg = new QTimer(this);
    connect(timerImg, &QTimer::timeout,this,&PageBooting::updateImage);
    timerImg->start(50);
    */
}

/*
PageBooting::~PageBooting()
{
    disconnect();
    splashScreenBooting.close();
    splashScreenBooting.deleteLater();
}
*/

/*
void PageBooting::updateImage()
{
    if(currentFrame>=20)
    {
        QTimer* sendTimer = qobject_cast<QTimer*>(sender());
        if(sendTimer)
        {
            sendTimer->stop();
        }
        splashScreenBooting.hide();
        emit signalFinished();
        return;
    }

    //QString strImgPath = QString(":/Image/Default/Public/ImageBooting/Happyzone 01_000%01.png").arg(QString::number(currentFrame).rightJustified(2,'0'));
    QString strPng = QString("/Happyzone 01_000%01.png").arg(QString::number(currentFrame).rightJustified(2,'0'));
    pixBooting = Singleton::getInstance().pixLoad(false,strDirPath,strPng);
    splashScreenBooting.setPixmap(pixBooting.copy());

    currentFrame++;
}
*/

QPoint PageBooting::getBootingPoint()
{
    QPoint point;
    point.setX(splashScreenBooting.geometry().x());
    point.setY(splashScreenBooting.geometry().y());

    return point;
}
