#ifndef PAGEUPAGRADEFAIL_H
#define PAGEUPAGRADEFAIL_H

#include "page.h"
#include "Component/componentupgraderesult.h"

class PageUpagradeFail : public Page
{
    Q_OBJECT
public:
    PageUpagradeFail(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageUpagrdeFail";

    QLabel *labelText;
    CustomButtonOK *customButtonOK;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:

};

#endif // PAGEUPAGRADEFAIL_H
