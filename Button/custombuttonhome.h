#ifndef CUSTOMBUTTONHOME_H
#define CUSTOMBUTTONHOME_H

#include "custombutton.h"

class CustomButtonHome : public CustomButton
{
    Q_OBJECT
public:
    CustomButtonHome(QWidget *parent);
    QLabel *labelButtonHome;

    void update() override;

private:
    void init();
};
#endif // CUSTOMBUTTONHOME_H
