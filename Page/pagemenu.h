#ifndef PAGEMENU_H
#define PAGEMENU_H

#include "page.h"

class PageMenu : public Page
{
    Q_OBJECT
public:
    PageMenu(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageMenu";

    QLabel *labelButton[6];
    QLabel *labelArrowLeft;
    QLabel *labelArrowLeftTouch;
    QLabel *labelArrowRight;
    QLabel *labelArrowRightTouch;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:

};

#endif // PAGEMENU_H
