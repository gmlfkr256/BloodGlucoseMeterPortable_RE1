#ifndef CUSTOMBUTTONYES_H
#define CUSTOMBUTTONYES_H

#include "custombutton.h"

class CustomButtonYes : public CustomButton
{
    Q_OBJECT
public:
    CustomButtonYes(QWidget *parent);
    QLabel *labelButtonYes;

    void update() override;

    void setLongWidth(bool bIsLong);
private:
    void init();
    bool bIsLong = false;
};

#endif // CUSTOMBUTTONYES_H
