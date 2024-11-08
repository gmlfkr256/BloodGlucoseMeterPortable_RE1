#ifndef PAGEBOOTING_H
#define PAGEBOOTING_H

#include <singleton.h>

class PageBooting : public QObject
{
    Q_OBJECT
public:
    PageBooting(QRect windowRect);
    QPoint getBootingPoint();
private:
    QSplashScreen splashScreenBooting;
    QPixmap pixBooting;
    QString strDirPath = "/ImageBooting";
    int currentFrame;
    void updateImage();

signals:
    void signalFinished();
};

#endif // PAGEBOOTING_H
