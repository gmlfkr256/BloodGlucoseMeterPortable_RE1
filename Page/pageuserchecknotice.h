#ifndef PAGEUSERCHECKNOTICE_H
#define PAGEUSERCHECKNOTICE_H

#include "page.h"

class PageUserCheckNotice : public Page
{
    Q_OBJECT
public:
    PageUserCheckNotice(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageUserCheckNotice";

    QLabel *labelText;
    QLabel *labelCaliDay;

    CustomButtonOK *customButtonOK;

    int nSelect = 0;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
};

#endif // PAGEUSERCHECKNOTICE_H
