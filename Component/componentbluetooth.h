#ifndef COMPONENTBLUETOOTH_H
#define COMPONENTBLUETOOTH_H

#include "customcomponent.h"

class ComponentBluetooth : public CustomComponent
{
    Q_OBJECT
public:
    ComponentBluetooth(QWidget *parent);
    void mousePressEvent(QMouseEvent *ev) override;
private:
    QLabel *labelBluetoothButton;

    gapiBleAct_t bleAct;
    gapiBleStat_t bleStat;

    QString strDirPath = "/ImageComBluetooth";
    void init();
public slots:
    void update() override;
    void pageShow() override;
    void pageHide() override;
};

#endif // COMPONENTBLUETOOTH_H
