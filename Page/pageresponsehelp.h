#ifndef PAGERESPONSEHELP_H
#define PAGERESPONSEHELP_H

#include "page.h"

class PageResponseHelp : public Page
{
    Q_OBJECT
public:
    PageResponseHelp(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageHelpResponse";

    QLabel *labelText;

    QLabel *labelArrowTop;
    QLabel *labelArrowDown;

    QLabel *labelNumCurrent;
    QLabel *labelNumBar;
    QLabel *labelNumAll;

    QLabel *labelTouchTop;
    QLabel *labelTouchDown;

    CustomButtonBack *customButtonBack;

    void update() override;
    void pageShow() override;
    void pageHide() override;

private:

    void init();
    void textDown();
    void textUp();

signals:
};

#endif // PAGERESPONSEHELP_H
