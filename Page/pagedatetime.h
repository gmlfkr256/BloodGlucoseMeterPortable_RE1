#ifndef PAGEDATETIME_H
#define PAGEDATETIME_H

#include "page.h"

#include <QDateTimeEdit>

class PageDateTime : public Page
{
    Q_OBJECT
public:
    PageDateTime(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageDateTime";

    QLabel *labelLayout;
    QDateTimeEdit *dateTimeEdit;
    QVBoxLayout *layout;

    CustomButtonSave *customButtonSave;
    CustomButtonCancel *customButtonCancel;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:
    void signalShowPageNum(PageNum pageNum);
};

#endif // PAGEDATETIME_H
