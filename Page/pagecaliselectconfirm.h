#ifndef PAGECALISELECTCONFIRM_H
#define PAGECALISELECTCONFIRM_H

#include "page.h"

class PageCaliSelectConfirm : public Page
{
    Q_OBJECT
public:
    PageCaliSelectConfirm(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QLabel* labelText;

    CustomButtonOK* customButtonOK;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
};

#endif // PAGECALISELECTCONFIRM_H
