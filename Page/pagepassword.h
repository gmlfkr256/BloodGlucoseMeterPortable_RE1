#ifndef PAGEPASSWORD_H
#define PAGEPASSWORD_H

#include "page.h"

class PagePassword : public Page
{
    Q_OBJECT
public:
    PagePassword(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;

    QLabel* labelTitle;
    QLabel* labelTitleSub;
    QLabel* labelPasswordBg;
    QLabel* labelPasswordNum[4];
    QString strPasswordNum;
    int nCheckButtonNum = -1;
    QLabel* labelButtonNum[10];

    QLabel* labelButtonOK;
    QLabel* labelButtonOKText;
    QLabel* labelButtonCancel;

    QString strDirPath = "/ImagePassword";
    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
    void updatePasswordNum();
    void processOK();
signals:
    void signalUserTrans();
    void signalPassword();
};

#endif // PAGEPASSWORD_H
