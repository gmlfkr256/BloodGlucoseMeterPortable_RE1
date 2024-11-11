#ifndef PAGEBOOTING_H
#define PAGEBOOTING_H

#include <singleton.h>

class PageBooting : public QObject
{
    Q_OBJECT
public:
    PageBooting(QRect windowRect);
    QPoint getBootingPoint();
    QSplashScreen splashScreenBooting;
private:
    QPixmap pixBooting;
    QString strDirPath = "/ImageBooting";
    int currentFrame;
    void updateImage();

signals:
    void signalFinished();
};

#endif // PAGEBOOTING_H
