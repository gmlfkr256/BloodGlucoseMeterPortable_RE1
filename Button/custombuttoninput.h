#ifndef CUSTOMBUTTONINPUT_H
#define CUSTOMBUTTONINPUT_H

#include "custombutton.h"

class CustomButtonInput : public CustomButton
{
    Q_OBJECT
public:
    CustomButtonInput(QWidget *parent);
    QLabel *labelButtonInput;

    void update() override;

private:
    void init();
};

#endif // CUSTOMBUTTONINPUT_H
