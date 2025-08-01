#ifndef COMPONENTMENU_H
#define COMPONENTMENU_H

#include "customcomponent.h"

class ComponentMenu : public CustomComponent
{
    Q_OBJECT
public:
    ComponentMenu(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
private:
    QLabel *labelMenu;
    QString strDirPath = "/ImageComMenu";

    void init();
public slots:
    void update() override;
    void pageShow() override;
    void pageHide() override;

signals:
    void signalShowPageNum(PageNum pageNum);
};

#endif // COMPONENTMENU_H
