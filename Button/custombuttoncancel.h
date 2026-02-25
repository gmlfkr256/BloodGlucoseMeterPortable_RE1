#ifndef CUSTOMBUTTONCANCEL_H
#define CUSTOMBUTTONCANCEL_H

#include "custombutton.h"

class CustomButtonCancel : public CustomButton
{
    Q_OBJECT
public:
    CustomButtonCancel(QWidget *parent);
    QLabel *labelButtonCancel;

    void update() override;

    void setLongWidth(bool bIsLong);
    void setEnable();
    void setDisable();
    bool getEnable();
private:
    void init();
    bool bIsLong = false;
    bool bIsEnable = true;
};

#endif // CUSTOMBUTTONCANCEL_H
