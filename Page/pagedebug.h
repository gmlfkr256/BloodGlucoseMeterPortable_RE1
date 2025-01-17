#ifndef PAGEDEBUG_H
#define PAGEDEBUG_H

#include "page.h"

class PageDebug : public Page
{
    Q_OBJECT
public:
    PageDebug(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageDebug";

    QFont font;
    QLabel *labelTitle;
    QLabel *labelButtonCancel;
    QLabel *labelDebugMenu[12];
    PageNum pageNum[12];

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

};

#endif // PAGEDEBUG_H
