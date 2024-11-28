#ifndef CUSTOMBUTTONSAVE_H
#define CUSTOMBUTTONSAVE_H

#include "custombutton.h"

class CustomButtonSave : public CustomButton
{
    Q_OBJECT
public:
    CustomButtonSave(QWidget *parent);
    QLabel *labelButtonSave;

    void update() override;
private:
    void init();
};

#endif // CUSTOMBUTTONSAVE_H
