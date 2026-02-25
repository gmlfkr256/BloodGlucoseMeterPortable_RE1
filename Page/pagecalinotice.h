#ifndef PAGECALINOTICE_H
#define PAGECALINOTICE_H

#include "page.h"

class PageCaliNotice : public Page
{
    Q_OBJECT
public:
    PageCaliNotice(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageCaliNotice";

    QLabel *labelText;

    CustomButtonYes *customButtonYes;
    CustomButtonNo *customButtonNo;

    bool bIsCali = false;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
};

#endif // PAGECALINOTICE_H
