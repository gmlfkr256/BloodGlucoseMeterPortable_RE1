#ifndef CUSTOMBUTTONOK_H
#define CUSTOMBUTTONOK_H

#include "custombutton.h"

class CustomButtonOK : public CustomButton
{
    Q_OBJECT
public:
    CustomButtonOK(QWidget *parent);
    QLabel *labelButtonOk;

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

#endif // CUSTOMBUTTONOK_H
