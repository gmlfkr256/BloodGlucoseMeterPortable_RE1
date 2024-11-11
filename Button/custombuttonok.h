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
private:
    void init();
    bool bIsLong = false;
};

#endif // CUSTOMBUTTONOK_H
