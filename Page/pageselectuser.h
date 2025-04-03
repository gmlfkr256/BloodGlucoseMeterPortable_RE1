#ifndef PAGESELECTUSER_H
#define PAGESELECTUSER_H

#include "page.h"

class PageSelectUser : public Page
{
    Q_OBJECT
public:
    PageSelectUser(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageSelectUser";

    QLabel *labelTitle;
    QLabel *labelUser[USER_MAX];

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
