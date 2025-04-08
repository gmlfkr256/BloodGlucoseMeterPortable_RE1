#ifndef PAGESELECTUSER_H
#define PAGESELECTUSER_H

#include "page.h"

class PageSelectUser : public Page
{
    Q_OBJECT
public:
    PageSelectUser(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageSelectUser";

    QLabel *labelTitle;
    QLabel *labelUserImg[USER_MAX];
    QLabel *labelUserText[USER_MAX];
    int nLabelNumber = -1;
    bool bIsOneClick = false;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

public slots:

private slots:

signals:
};

#endif // PAGESELECTUSER_H
