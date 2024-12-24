#ifndef PAGEDATETIME_H
#define PAGEDATETIME_H

#include "page.h"
#include "Component/componentspinnerdate.h"

class PageDateTime : public Page
{
    Q_OBJECT
public:
    PageDateTime(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageDateTime";

    ComponentSpinnerDate *comDateYear;

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
