#ifndef PAGEUSERCAUTIONS_H
#define PAGEUSERCAUTIONS_H

#include "page.h"

class PageUserCautions : public Page
{
    Q_OBJECT
public:
    PageUserCautions(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageUserCautions";

    QLabel *labelTitle;
    QLabel *labelText;

    QTimer *timer;

    CustomButtonOK *customButtonOK;

    int nStep = 0;
    int nStepMax = 7;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
};

#endif // PAGEUSERCAUTIONS_H
