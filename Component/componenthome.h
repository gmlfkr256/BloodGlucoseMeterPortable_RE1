#ifndef COMPONENTHOME_H
#define COMPONENTHOME_H

#include "customcomponent.h"

class ComponentHome : public CustomComponent
{
    Q_OBJECT
public:
    ComponentHome(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
private:
    QLabel *labelHome;

    QString strDirPath = "/ImageComHome";
    void init();
public slots:
    void update() override;
    void pageShow() override;
    void pageHide() override;

signals:
    void singalShowPageHome();
};

#endif // COMPONENTHOME_H
