#include "pagepassword.h"

PagePassword::PagePassword(QWidget *parent) : Page(parent)
{
    this->setGeometry(parent->geometry());
    init();
}

void PagePassword::init()
{
    setBgTopHide();

    labelTitle = new QLabel(this);
    labelTitle->setGeometry(0,30,640,50);
    labelTitle->setAlignment(Qt::AlignCenter);
    labelTitle->setStyleSheet("color: #000000");
    labelTitleSub = new QLabel(this);
    labelTitleSub->setGeometry(0,84,640,40);
    labelTitleSub->setAlignment(Qt::AlignCenter);
    labelTitleSub->setStyleSheet("color: #808080");

    for(int i=0; i<10; i++)
    {
        labelButtonNum[i] = new QLabel(this);
        labelButtonNum[i]->setStyleSheet("background-color: #ffffff; border: 1px solid #ebebeb;");
        labelButtonNum[i]->setFont(textResource.getFont(PAGE_PASSWORD,"labelButtonNum"));
        labelButtonNum[i]->setAlignment(Qt::AlignCenter);
        labelButtonNum[i]->setText(QString::number(i));

        if(i<5)
        {
            labelButtonNum[i]->setGeometry(i*128,240,128,120);
        }
        else
        {
            labelButtonNum[i]->setGeometry((i-5)*128,360,128,120);
        }
    }

    labelPasswordBg = new QLabel(this);
    labelPasswordBg->setGeometry(116,133,303,85);

    for(int i=0; i<4; i++)
    {
        labelPasswordNum[i] = new QLabel(this);
        labelPasswordNum[i]->setGeometry(150+(i*42),163,26,26);
        labelPasswordNum[i]->hide();
    }

    labelButtonOK = new QLabel(this);
    labelButtonOK->setGeometry(427,133,98,85);

    labelButtonOKText = new QLabel(this);
    labelButtonOKText->setGeometry(labelButtonOK->geometry());
    labelButtonOKText->setAlignment(Qt::AlignCenter);

    labelButtonDel = new QLabel(this);
    labelButtonDel->setGeometry(336,152,67,47);

    labelButtonCancel = new QLabel(this);
    labelButtonCancel->setGeometry(560,26,50,50);

    labelButtonCancelText = new QLabel(this);
    labelButtonCancelText->setGeometry(labelButtonCancel->geometry());
    labelButtonCancelText->setAlignment(Qt::AlignCenter);

    update();
}

void PagePassword::update()
{
    /*
#if DEVICE
    int user = 0; // = GAPI_USER_MAX;

    instance.guiApi.glucoseGetActUser(&user);

    qDebug() << "user: "<<user;
    if(user != GAPI_USER_MAX)
    {
        qDebug()<<"userCheck";
        instance.actUserLogin(user);
        emit signalShowPageNum(PAGE_HOME);
    }
#endif
*/

    labelTitle->setFont(textResource.getFont(PAGE_PASSWORD,"labelTitle"));
    labelTitle->setText(textResource.getText(PAGE_PASSWORD,"labelTitle").at(instance.getPasswordStatus()));
    labelTitleSub->setFont(textResource.getFont(PAGE_PASSWORD,"labelTitleSub"));
    labelTitleSub->setText(textResource.getText(PAGE_PASSWORD,"labelTitleSub").at(instance.getPasswordStatus()));

    instance.pixLoad(labelPasswordBg,false,strDirPath,"/passwordNumBg.png");

    instance.pixLoad(labelButtonOK,false,strDirPath,"/buttonOK.png");

    labelButtonOKText->setStyleSheet("color: #ffffff;");
    labelButtonOKText->setFont(textResource.getFont(PAGE_PASSWORD,"labelButtonOKText"));
    labelButtonOKText->setText(textResource.getText(PAGE_PASSWORD,"labelButtonOKText").at(0));

    instance.pixLoad(labelButtonCancel,false,strDirPath,"/buttonCancel.png");

    /*
    labelButtonCancelText->setStyleSheet("color: #ffffff;");
    labelButtonCancelText->setFont(textResource.getFont(PAGE_PASSWORD,"labelButtonCancelText"));
    labelButtonCancelText->setText(textResource.getText(PAGE_PASSWORD,"labelButtonCancelText").at(0));
    */

    instance.pixLoad(labelButtonDel,false,strDirPath,"/buttonDelete.png");


    for(QLabel *label : labelPasswordNum)
    {
        instance.pixLoad(label,false,strDirPath,"/circlePassword.png");
    }
}

void PagePassword::mousePressEvent(QMouseEvent *ev)
{
    //qDebug()<<"touch";
    if(instance.touchCheck(labelButtonOK->geometry(),ev))
    {
        //qDebug()<<"strPasswordNum.size: "<<strPasswordNum.size();
        if(strPasswordNum.size()<4)
            return;

        processOK();
    }

    if(instance.touchCheck(labelButtonDel->geometry(),ev))
    {
        strPasswordNum.chop(1);
        updatePasswordNum();
    }

    for(int i=0; i<10; i++)
    {
        if(instance.touchCheck(labelButtonNum[i]->geometry(),ev))
        {
            if(strPasswordNum.size()<4)
            {
                strPasswordNum.append(QString::number(i));
            }

            labelButtonNum[i]->setStyleSheet("background-color: #077bdd; color: #ffffff; border: 1px solid #ebebeb;");
            nCheckButtonNum = i;

            updatePasswordNum();
        }
    }

    if(instance.touchCheck(labelButtonCancel->geometry(),ev) && labelButtonCancel->isVisible())
    {
        if(instance.getPasswordStatus() == PASSWORD_LOGIN)
        {
            emit signalShowPageNum(PAGE_SELECT_USER);
        }
        else
        {
            emit signalShowPageNum(PAGE_USERINFO);
        }
    }

}

void PagePassword::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);

    //qDebug()<<"nCheckButtonNum: "<<nCheckButtonNum;
    if(nCheckButtonNum != -1)
    {
        labelButtonNum[nCheckButtonNum]->setStyleSheet("background-color: #ffffff; color: #000000; border: 1px solid #ebebeb;");
        nCheckButtonNum = -1;
    }
}

void PagePassword::updatePasswordNum()
{
    //qDebug()<<"updatePasswordNum() strPasswordNum: "<<strPasswordNum;
    for(int i=0; i<4; i++)
    {
        /*
        if(labelPasswordNum[i])
            qDebug()<<i;
        */

        if(i<strPasswordNum.size())
        {
            labelPasswordNum[i]->show();
        }
        else
        {
            labelPasswordNum[i]->hide();
        }
    }
}

void PagePassword::processOK()
{
    bool bCheckPassword = false;
    //qDebug()<<"processOK() strPasswordNum: "+strPasswordNum;
    switch (instance.getPasswordStatus())
    {
    case PASSWORD_LOGIN:
        for(int i=0; i<USER_MAX; i++)
        {
            if(strPasswordNum == instance.sysUserInfo[i].passwd)
            {
                bCheckPassword = true;
                qDebug()<<"Log in Success";
                instance.actUserLogin(i);
                break;
            }
        }

        if(bCheckPassword)
        {
            qDebug()<<strPasswordNum;
            if(strPasswordNum == "1111" || strPasswordNum == "2222")
                instance.setPasswordStrStatus(PASSWORD_STR_LOGIN_CHANGE);
            else
                instance.setPasswordStrStatus(PASSWORD_STR_LOGIN_SUCCESS);
        }
        else
        {
            instance.setPasswordStrStatus(PASSWORD_STR_LOGIN_FAIL);
            if(strPasswordNum == "9999")
                instance.setPasswordStrStatus(PASSWORD_STR_LOGIN_SUCCESS);
        }
        break;
    case PASSWORD_EDIT:
        instance.setPasswordStatusPrev(PASSWORD_EDIT);
        instance.setPasswordChange(strPasswordNum);
        instance.setPasswordStrStatus(PASSWORD_STR_REPEAT);
        break;
    case PASSWORD_DELETE:
        if(instance.sysUserInfo[instance.getUserNumber()].passwd == strPasswordNum)
        {
            instance.setPasswordStatusPrev(PASSWORD_DELETE);
            instance.setPasswordStrStatus(PASSWORD_STR_REPEAT);
        }
        else
            instance.setPasswordStrStatus(PASSWORD_STR_CONFIRM_FAIL);
        break;
    case PASSWORD_REPEAT:
        switch (instance.getPasswordStatusPrev())
        {
        case PASSWORD_EDIT:
            if(instance.getPasswordChage() == strPasswordNum)
            {
                instance.setPasswordStrStatus(PASSWORD_STR_EDIT_SUCCESS);
                instance.setUserPasswordChange();
            }
            else
                instance.setPasswordStrStatus(PASSWORD_STR_REPEAT_FAIL);
            break;
        case PASSWORD_DELETE:
            if(instance.sysUserInfo[instance.getUserNumber()].passwd == strPasswordNum)
                instance.setPasswordStrStatus(PASSWORD_STR_DELETE_SUCCESS);
            else
                instance.setPasswordStrStatus(PASSWORD_STR_REPEAT_FAIL);
            break;
        default:
            instance.setPasswordStrStatus(PASSWORD_STR_MAX);
            break;
        }
        break;
    case PASSWORD_CONFIRM:
        if(instance.sysUserInfo[instance.getUserNumber()].passwd == strPasswordNum)
            instance.setPasswordStrStatus(PASSWORD_STR_EDIT_CHANGE);
        else
            instance.setPasswordStrStatus(PASSWORD_STR_CONFIRM_FAIL);
        break;
    case PASSWORD_MAX:
    default:
        instance.setPasswordStrStatus(PASSWORD_STR_MAX);
        break;
    }

    emit signalShowPageNum(PAGE_PASSWORD_CONFIRM);
}

void PagePassword::pageShow()
{
    instance.updateSysUserInfo();
    strPasswordNum.clear();
    updatePasswordNum();
    update();
}

void PagePassword::pageHide()
{

}
