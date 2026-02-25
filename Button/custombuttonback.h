#ifndef CUSTOMBUTTONBACK_H
#define CUSTOMBUTTONBACK_H

#include "custombutton.h"

class CustomButtonBack : public CustomButton
{
    Q_OBJECT
public:
    CustomButtonBack(QWidget *parent);
    QLabel *labelButtonBack;

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

#endif // CUSTOMBUTTONBACK_H
