#ifndef PAGECALIVALUENOTICE_H
#define PAGECALIVALUENOTICE_H

#include "page.h"

class PageCaliValueNotice : public Page
{
    Q_OBJECT
public:
    PageCaliValueNotice(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    QString strDirPath = "/ImageCaliValueNotice";

    QLabel *labelText;

    CustomButtonOK* customButtonOK;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
};

#endif // PAGECALIVALUENOTICE_H
