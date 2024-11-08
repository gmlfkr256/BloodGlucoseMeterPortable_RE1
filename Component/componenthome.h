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
    Singleton &instance = Singleton::getInstance();
    QLabel *labelHome;

    QString strDirPath = "/ImageComHome";
    void init();
public slots:
    void update() override;
    void pageShow() override;
    void pageHide() override;

signals:
    void singalComHomeClick();
};

#endif // COMPONENTHOME_H
