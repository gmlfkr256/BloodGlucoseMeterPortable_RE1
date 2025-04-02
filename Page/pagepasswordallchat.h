#ifndef PAGEPASSWORDALLCHAT_H
#define PAGEPASSWORDALLCHAT_H

#include "page.h"

class PagePasswordAllChat : public Page
{
    Q_OBJECT
public:
    PagePasswordAllChat(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QLabel* labelTitle;
    QLabel* labelTitleSub;
    QLabel* labelPasswordBg;
    QLabel* labelPasswordNum[4];
    QString strPasswordNum;
    int nCheckButtonNum = -1;
    QLabel* labelButtonNum[10];

    QLabel* labelButtonOK;
    QLabel* labelButtonOKText;
    QLabel* labelButtonDel;
    QLabel* labelButtonCancel;
    QLabel* labelButtonCancelText;

    QString strDirPath = "/ImagePasswordAllChat";
    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:

};

#endif // PAGEPASSWORDALLCHAT_H
