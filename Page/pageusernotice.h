#ifndef PAGEUSERNOTICE_H
#define PAGEUSERNOTICE_H

#include "page.h"

class PageUserNotice : public Page
{
    Q_OBJECT
public:
    PageUserNotice(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageUserNotice";

    QLabel *labelText;

    CustomButtonOK *customButtonOK;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
};

#endif // PAGEUSERNOTICE_H
