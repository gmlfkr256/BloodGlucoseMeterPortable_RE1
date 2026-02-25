#ifndef PAGEUSERCHECK_H
#define PAGEUSERCHECK_H

#include "page.h"

class PageUserCheck : public Page
{
    Q_OBJECT
public:
    PageUserCheck(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageUserCheck";

    QLabel *labelTitle;

    //QLabel *labelButton[3];
    //QLabel *labelText[3];
    QLabel *labelButton;
    QLabel *labelText;

    int nSelect = 0;

    CustomButtonOK *customButtonOk;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
    void setUserType(int nSelect);
    int getUserType();
};

#endif // PAGEUSERCHECK_H
