#ifndef CUSTOMBUTTONREBOOT_H
#define CUSTOMBUTTONREBOOT_H

#include "custombutton.h"

class CustomButtonReboot : public CustomButton
{
    Q_OBJECT
public:
    CustomButtonReboot(QWidget *parent);
    QLabel *labelButtonReboot;

    void update() override;

private:
    void init();
};

#endif // CUSTOMBUTTONREBOOT_H
