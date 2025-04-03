#include "pagepasswordconfirm.h"

PagePasswordConfirm::PagePasswordConfirm(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PagePasswordConfirm::init()
{
    setBgTopHide();

    labelTitle = new QLabel(this);
    labelTitle->setGeometry(0,70,640,75);
    labelTitle->setAlignment(Qt::AlignCenter);
    labelTitle->hide();

    labelText = new QLabel(this);
    //labelText->setGeometry(0,100,640,280);
    labelText->setGeometry(0,0,640,380);
    labelText->setAlignment(Qt::AlignCenter);

    customButtonOK = new CustomButtonOK(this);
    customButtonCancel = new CustomButtonCancel(this);

    update();
}

void PagePasswordConfirm::update()
{
    customButtonOK->update();
    customButtonCancel->update();

    PasswordStrStatus nStrStatus = instance.getPasswordStrStatus();
    switch (nStrStatus)
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

    labelTitle->setFont(textResource.getFont(PAGE_PASSWORD_CONFIRM,"labelTitle"));
    labelTitle->setText(textResource.getText(PAGE_PASSWORD_CONFIRM,"labelTitle").at(nStrStatus));

    labelText->setFont(textResource.getFont(PAGE_PASSWORD_CONFIRM,"labelText"));

#if NEW_PASSWORD
    if(nStrStatus == PASSWORD_STR_LOGIN_FAIL)
    {
        labelText->setText(textResource.getText(PAGE_PASSWORD_CONFIRM,"labelTextError").at(instance.getPasswordErrCode()));
    }
    else
    {
        labelText->setText(textResource.getText(PAGE_PASSWORD_CONFIRM,"labelText").at(nStrStatus));
    }
#else
    labelText->setText(textResource.getText(PAGE_PASSWORD_CONFIRM,"labelText").at(nStrStatus));
#endif
}

void PagePasswordConfirm::mousePressEvent(QMouseEvent *ev)
{
    if(instance.touchCheck(customButtonOK->geometry(),ev) && !customButtonOK->isHidden())
    {
        qDebug()<<"instance.getPasswordStrStatus: "<<instance.getPasswordStrStatus();
        switch (instance.getPasswordStrStatus())
        {
        case PASSWORD_STR_LOGIN_SUCCESS:
#if NEW_PASSWORD
            emit signalShowPageNum(PAGE_SELECT_USER);
#else
            emit signalShowPageNum(PAGE_HOME);
#endif
            break;
        case PASSWORD_STR_LOGIN_FAIL:
            emit signalShowPageNum(PAGE_PASSWORD);
            break;
        case PASSWORD_STR_LOGIN_CHANGE:
            emit signalShowPageNum(PAGE_HOME);
            break;
        case PASSWORD_STR_CONFIRM:
            instance.setPasswordStatus(PASSWORD_CONFIRM);
            emit signalShowPageNum(PAGE_PASSWORD);
            break;
        case PASSWORD_STR_CONFIRM_FAIL:
            instance.setPasswordStatus(PASSWORD_CONFIRM);
            emit signalShowPageNum(PAGE_PASSWORD);
            break;
        case PASSWORD_STR_REPEAT:
            instance.setPasswordStatus(PASSWORD_REPEAT);
            emit signalShowPageNum(PAGE_PASSWORD);
            break;
        case PASSWORD_STR_REPEAT_FAIL:
            instance.setPasswordStatus(PASSWORD_REPEAT);
            emit signalShowPageNum(PAGE_PASSWORD);
            break;
        case PASSWORD_STR_EDIT:
            instance.setPasswordStrStatus(PASSWORD_STR_EDIT_CONFIRM);
            update();
            break;
        case PASSWORD_STR_EDIT_CONFIRM:
            instance.setPasswordStatus(PASSWORD_CONFIRM);
            emit signalShowPageNum(PAGE_PASSWORD);
            break;
        case PASSWORD_STR_EDIT_CHANGE:
            instance.setPasswordStatus(PASSWORD_EDIT);
            emit signalShowPageNum(PAGE_PASSWORD);
            break;
        case PASSWORD_STR_EDIT_SUCCESS:
            instance.setPasswordStatus(PASSWORD_LOGIN);
            emit signalShowPageNum(PAGE_PASSWORD);
            break;
        case PASSWORD_STR_DELETE:
            instance.setPasswordStrStatus(PASSWORD_STR_DELETE_CONFIRM);
            update();
            break;
        case PASSWORD_STR_DELETE_CONFIRM:
            instance.setPasswordStatus(PASSWORD_DELETE);
            emit signalShowPageNum(PAGE_PASSWORD);
            break;
        case PASSWORD_STR_DELETE_SUCCESS:
#if DEVICE
            instance.guiApi.glucoseDelUserInfo(instance.getUserNumber());
#else
            QCoreApplication::exit(0);
#endif
            break;
        case PASSWORD_STR_LOGOUT:
#if DEVICE
            instance.guiApi.glucoseActUserLogout(instance.getUserNumber());

#endif
            instance.setPasswordStatus(PASSWORD_LOGIN);
#if NEW_PASSWORD
            emit signalShowPageNum(PAGE_PASSWORD_ALLCHAT);
#else
            emit signalShowPageNum(PAGE_PASSWORD);
#endif
            break;
        case PASSWORD_STR_MAX:
            break;
        }
    }

    if(instance.touchCheck(customButtonCancel->geometry(),ev) && !customButtonCancel->isHidden())
    {
        qDebug()<<"customButtonCancel";
        emit signalShowPageNum(PAGE_USERINFO);
    }
}

void PagePasswordConfirm::pageShow()
{
    update();
}

void PagePasswordConfirm::pageHide()
{

}
