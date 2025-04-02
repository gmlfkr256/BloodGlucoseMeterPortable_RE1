#ifndef COMPONENTPASSWORDKEYBOARD_H
#define COMPONENTPASSWORDKEYBOARD_H

#include "customcomponent.h"

class ComponentPasswordKeyboard : public CustomComponent
{
    Q_OBJECT
public:
    ComponentPasswordKeyboard(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;

    QString strDirPath = "/ImageComponentPasswordKeyBoard";

    QLabel *labelFunction[3];
    QLabel *labelButton[10];

    void update() override;
    void pageShow() override;
    void pageHide() override;
private:
    void init();
signals:
};

#endif // COMPONENTPASSWORDKEYBOARD_H
