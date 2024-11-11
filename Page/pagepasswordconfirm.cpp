#include "pagepasswordconfirm.h"

PagePasswordConfirm::PagePasswordConfirm(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PagePasswordConfirm::init()
{
    setBgTopHide();

    labelText = new QLabel(this);
    labelText->setGeometry(0,100,640,280);
    labelText->setAlignment(Qt::AlignCenter);

    customButtonOK = new CustomButtonOK(this);
    customButtonCancel = new CustomButtonCancel(this);

    update();
}

void PagePasswordConfirm::update()
{
    switch (instance.getPasswordStrStatus())
    {
    case PASSWORD_STR_LOGIN_SUCCESS:
    case PASSWORD_STR_LOGIN_CHANGE:
    case PASSWORD_STR_LOGIN_FAIL:
    case PASSWORD_STR_CONFIRM_FAIL:
    case PASSWORD_STR_REPEAT:
    case PASSWORD_STR_REPEAT_FAIL:
    case PASSWORD_STR_EDIT_CHANGE:
    case PASSWORD_STR_EDIT_SUCCESS:
    case PASSWORD_STR_DELETE_SUCCESS:
        customButtonCancel->hide();
        customButtonOK->setLongWidth(true);
        break;
    case PASSWORD_STR_CONFIRM:
    case PASSWORD_STR_EDIT:
    case PASSWORD_STR_EDIT_CONFIRM:
    case PASSWORD_STR_DELETE:
    case PASSWORD_STR_DELETE_CONFIRM:
        customButtonCancel->show();
        customButtonOK->setLongWidth(false);

        break;
    case PASSWORD_STR_LOGOUT:
        qDebug()<<"PagePasswordConfirm LOGOUT";
        break;
    case PASSWORD_STR_MAX:
        qDebug()<<"PagePasswordConfirm MAX";
        break;
    }

    switch (instance.getDeviceColor())
    {
    case COLOR_DEFAULT:
        labelText->setStyleSheet("color: #000000; ");
        break;
    case COLOR_BLUE:
        break;
    case COLOR_RED:
        break;
    }

    labelText->setFont(textResource.getFont(PAGE_PASSWORD_CONFIRM,"labelText"));
    labelText->setText(textResource.getText(PAGE_PASSWORD_CONFIRM,"labelText").at(instance.getPasswordStrStatus()));
}

void PagePasswordConfirm::pageShow()
{

}

void PagePasswordConfirm::pageHide()
{

}
