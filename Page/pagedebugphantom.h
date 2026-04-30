#ifndef PAGEDEBUGPHANTOM_H
#define PAGEDEBUGPHANTOM_H

#include "page.h"

class PageDebugPhantom : public Page
{
    Q_OBJECT
public:
    PageDebugPhantom(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;

    QLabel *labelBg;
    QLabel *labelTitle;
    QLabel *labelPhantomText;
    QLabel *labelPhantomButton;
    CustomButtonSave *customButtonSave;
    CustomButtonCancel *customButtonCancel;

    bool bPhantomState = false;

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();

signals:
};

#endif // PAGEDEBUGPHANTOM_H
