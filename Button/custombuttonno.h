#ifndef CUSTOMBUTTONNO_H
#define CUSTOMBUTTONNO_H

#include "custombutton.h"

class CustomButtonNo : public CustomButton
{
    Q_OBJECT
public:
    CustomButtonNo(QWidget *parent);
    QLabel *labelButtonNo;

    void update() override;

    void setLongWidth(bool bIsLong);
private:
    void init();
    bool bIsLong = false;
};

#endif // CUSTOMBUTTONNO_H
