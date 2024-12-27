#ifndef CUSTOMBUTTONUPGRADE_H
#define CUSTOMBUTTONUPGRADE_H

#include "custombutton.h"

class CustomButtonUpgrade : public CustomButton
{
    Q_OBJECT
public:
    CustomButtonUpgrade(QWidget *parent);
    QLabel *labelButtonUpgrade;

    void update() override;

private:
    void init();
};

#endif // CUSTOMBUTTONUPGRADE_H
