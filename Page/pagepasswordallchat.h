#ifndef PAGEPASSWORDALLCHAT_H
#define PAGEPASSWORDALLCHAT_H

#include "page.h"
#include "Component/componentpasswordkeyboard.h"

class PagePasswordAllChat : public Page
{
    Q_OBJECT
public:
    PagePasswordAllChat(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImagePasswordAllChat";

    QLabel *labelTitle;
    QLabel *labelTitleSub;
    QLabel *labelPasswordBg;
    QLabel *labelPasswordNum[4];
    QString strPasswordNum;
    int nCheckButtonNum = -1;
    QLabel *labelButtonNum[10];

    QLabel *labelButtonShowHide;

    ComponentPasswordKeyboard *comKeyboard;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
    void initConnect();

public slots:
    void updatePassword(QString strKey);
    void checkLogin();

signals:
    void signalPasswordDel();
    void signalPasswordShowHide();
};

#endif // PAGEPASSWORDALLCHAT_H
