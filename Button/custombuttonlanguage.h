#ifndef CUSTOMBUTTONLANGUAGE_H
#define CUSTOMBUTTONLANGUAGE_H

#include "custombutton.h"

class CustomButtonLanguage : public CustomButton
{
    Q_OBJECT
public:
    CustomButtonLanguage(QWidget *parent);
    QLabel *labelButtonLang;

    int nTotal = LAN_MAX;
    int nSelectIndex = 0;

    void update() override;

private:
    void init();

public slots:
    void updateLanguage();

signals:
    void signalUpdateLanguage();
};

#endif // CUSTOMBUTTONLANGUAGE_H
