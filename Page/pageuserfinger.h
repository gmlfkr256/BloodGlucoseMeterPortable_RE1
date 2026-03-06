#ifndef PAGEUSERFINGER_H
#define PAGEUSERFINGER_H

#include "page.h"

class PageUserFinger : public Page
{
    Q_OBJECT
public:
    PageUserFinger(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageUserFinger";

    QLabel *labelTitle;
    QLabel *labelImage;

    QTimer *timer;

    //CustomButtonOK *customButtonOK;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
};

#endif // PAGEUSERFINGER_H
