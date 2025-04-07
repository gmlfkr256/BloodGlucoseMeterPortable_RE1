#include "componentpasswordkeyboard.h"

ComponentPasswordKeyboard::ComponentPasswordKeyboard(QWidget *parent) : CustomComponent(parent)
{
    this->setGeometry(0,240,640,240);
    init();
}

void ComponentPasswordKeyboard::init()
{
    for(int i=0; i<5; i++)
    {
        labelFunction[i] = new QLabel(this);
        labelFunction[i]->setStyleSheet("background-color: #E0F7FA; border: 1px solid #888888;");
        labelFunction[i]->setFont(textResource.getFont(PAGE_PASSWORD,"labelButtonNum"));
        labelFunction[i]->setAlignment(Qt::AlignCenter);

        //labelFunction[i]->setGeometry(i*128,0,128,80);
        labelFunction[i]->setGeometry(i*106,0,106,80);
    }

    labelFunction[0]->setText("0·9");
    labelFunction[1]->setText("a A");
    labelFunction[2]->setText("k K");
    labelFunction[3]->setText("u U");
    labelFunction[4]->setText("! - :");


    for(int i=0; i<10; i++)
    {
        labelButton[i] = new QLabel(this);
        labelButton[i]->setStyleSheet("background-color: #ffffff; border: 1px solid #ebebeb;");
        labelButton[i]->setFont(textResource.getFont(PAGE_PASSWORD,"labelButtonNum"));
        labelButton[i]->setAlignment(Qt::AlignCenter);

        if(i<5)
        {
            //labelButton[i]->setGeometry(i*128,80,128,80);
            labelButton[i]->setGeometry(i*106,80,106,80);
        }
        else
        {
            //labelButton[i]->setGeometry((i-5)*128,160,128,80);
            labelButton[i]->setGeometry((i-5)*106,160,106,80);
        }
    }

    QList<QLabel*> labelList;

    labelButtonDel = new QLabel(this);
    labelButtonDel->setGeometry(530,0,110,80);
    labelButtonDel->setText("<<");
    labelList.append(labelButtonDel);
    labelButtonCancel = new QLabel(this);
    labelButtonCancel->setGeometry(530,80,110,80);
    labelList.append(labelButtonCancel);
    labelButtonOK = new QLabel(this);
    labelButtonOK->setGeometry(530,160,110,80);
    labelButtonOK->setText("▶");
    labelList.append(labelButtonOK);

    for(QLabel *label : labelList)
    {
        label->setFont(textResource.getFont(PAGE_PASSWORD,"labelButtonNum"));
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet("background-color: #177bdd; border: 1px solid #888888;");
    }

    keyBoardIndex = new KeyBoardIndex(this);

    update();
}

void ComponentPasswordKeyboard::update()
{

    if(!keyBoardIndex->mapKey.contains(nFunctionNum))
    {
        qDebug()<<"Invalid nFunctionNum: "<<nFunctionNum;
        return;
    }

    for(int i=0; i<10; i++)
    {
        labelButton[i]->setText(keyBoardIndex->mapKey[nFunctionNum].at(i));
    }

    if(instance.getPasswordStatus() != PASSWORD_LOGIN)
    {
        labelButtonCancel->setText("◀");
    }
    else
    {
        labelButtonCancel->setText("");
    }
}

void ComponentPasswordKeyboard::pageShow()
{
    strKey = "";
    update();
}

void ComponentPasswordKeyboard::pageHide()
{

}

void ComponentPasswordKeyboard::mousePressEvent(QMouseEvent *ev)
{
    for(int i=0; i<5; i++)
    {
        if(instance.touchCheck(labelFunction[i]->geometry(),ev))
        {
            setFunctionNumBytButton(i);
        }
    }

    if(instance.touchCheck(QRect(0,80,640,160),ev))
    {
        for(int i=0; i<10; i++)
        {
            if(instance.touchCheck(labelButton[i]->geometry(),ev))
            {
                if(strKey.size()<12)
                    strKey += keyBoardIndex->mapKey[nFunctionNum].at(i);

                qDebug()<<strKey;
                emit signalKeyClick(getDisplayText());
            }
        }
    }

    if(instance.touchCheck(labelButtonDel->geometry(),ev))
    {
        deleteLastKey();
    }

    if(instance.touchCheck(labelButtonCancel->geometry(),ev) && !labelButtonCancel->isHidden())
    {
        emit signalCancel();
    }

    if(instance.touchCheck(labelButtonOK->geometry(),ev))
    {
        processOK();
    }
}

void ComponentPasswordKeyboard::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
}

void ComponentPasswordKeyboard::deleteLastKey()
{
    if(!strKey.isEmpty())
    {
        strKey.chop(1);
        emit signalKeyClick(getDisplayText());
    }
}

QString ComponentPasswordKeyboard::getDisplayText()
{
    if(bIsShowAll)
        return strKey;

    if(strKey.isEmpty())
        return QString();

    QString strMasked(strKey.size()-1, QChar('*'));
    strMasked += strKey.right(1);
    return strMasked;
}

void ComponentPasswordKeyboard::setFunctionNumBytButton(int nIndex)
{
    switch (nIndex)
    {
    case 0:
        nFunctionNum = 0;
        break;
    case 1:
        nFunctionNum = (nFunctionNum == 4) ? 1 : 4;
        break;
    case 2:
        nFunctionNum = (nFunctionNum == 5) ? 2 : 5;
        break;
    case 3:
        nFunctionNum = (nFunctionNum == 6) ? 3 : 6;
        break;
    case 4:
        if (nFunctionNum == 7)
            nFunctionNum = 8;
        else if (nFunctionNum == 8)
            nFunctionNum = 9;
        else
            nFunctionNum = 7;
        break;
    }

    update();
}

void ComponentPasswordKeyboard::processOK()
{

    int nErrCode = PASSWORD_ECODE_NORMAL;

    switch (instance.getPasswordStatus())
    {
    case PASSWORD_LOGIN:
        qDebug()<<"keyboard: login";
#if DEVICE
        bool bIsCheckPassword = false;
        if(strKey == instance.sysUserInfo[instance.getUserNumber()].passwd)
        {
            bIsCheckPassword = true;
        }

        if(bIsCheckPassword)
        {
            if(strKey == "1111" || strKey == "2222")
                instance.setPasswordStrStatus(PASSWORD_STR_LOGIN_CHANGE);
            else
                instance.setPasswordStrStatus(PASSWORD_STR_LOGIN_SUCCESS);
        }
        else
        {
            instance.setPasswordStrStatus(PASSWORD_STR_LOGIN_FAIL);
            if(strKey == "9999")
                instance.setPasswordStrStatus(PASSWORD_STR_LOGIN_SUCCESS);
        }
#else
        // 테스트 환경 시나리오별 강제 분기
        if(strKey == instance.sysUserInfo[instance.getUserNumber()].passwd) {
            nErrCode = PASSWORD_ECODE_NORMAL;
            instance.setPasswordStrStatus(PASSWORD_STR_LOGIN_SUCCESS);
        }
        else if(strKey == "00") {
            nErrCode = PASSWORD_ECODE_SHORT_LEN;
            instance.setPasswordStrStatus(PASSWORD_STR_LOGIN_FAIL);
        }
        else if(strKey == "11") {
            nErrCode = PASSWORD_ECODE_NO_NUMBER;
            instance.setPasswordStrStatus(PASSWORD_STR_LOGIN_FAIL);
        }
        else if(strKey == "22") {
            nErrCode = PASSWORD_ECODE_NO_ALPHABET;
            instance.setPasswordStrStatus(PASSWORD_STR_LOGIN_FAIL);
        }
        else if(strKey == "33") {
            nErrCode = PASSWORD_ECODE_NO_SPECIAL;
            instance.setPasswordStrStatus(PASSWORD_STR_LOGIN_FAIL);
        }
        else {
            nErrCode = PASSWORD_ECODE_MAX;
            instance.setPasswordStrStatus(PASSWORD_STR_LOGIN_FAIL);
        }
#endif
        break;

    case PASSWORD_EDIT:
        instance.setPasswordStatusPrev(PASSWORD_EDIT);
        instance.setPasswordChange(strKey);
        instance.setPasswordStrStatus(PASSWORD_STR_REPEAT);
        break;

    case PASSWORD_DELETE:
        if(instance.getStrNowUserPassword() == strKey)
        {
            instance.setPasswordStatusPrev(PASSWORD_DELETE);
            instance.setPasswordStrStatus(PASSWORD_STR_REPEAT);
        }
        else
        {
            instance.setPasswordStrStatus(PASSWORD_STR_CONFIRM_FAIL);
        }
        break;

    case PASSWORD_REPEAT:
        switch (instance.getPasswordStatusPrev())
        {
        case PASSWORD_EDIT:
            if(instance.getPasswordChage() == strKey)
            {
                instance.setPasswordStrStatus(PASSWORD_STR_EDIT_SUCCESS);
                instance.setUserPasswordChange();
            }
            else
            {
                instance.setPasswordStrStatus(PASSWORD_STR_REPEAT_FAIL);
            }
            break;

        case PASSWORD_DELETE:
            if(instance.sysUserInfo[instance.getUserNumber()].passwd == strKey)
                instance.setPasswordStrStatus(PASSWORD_STR_DELETE_SUCCESS);
            else
                instance.setPasswordStrStatus(PASSWORD_STR_REPEAT_FAIL);
            break;
        case PASSWORD_INIT:
            if(instance.getStrNowUserPassword() == strKey)
                instance.setPasswordStrStatus(PASSWORD_STR_INIT_SUCCESS);
            else
                instance.setPasswordStrStatus(PASSWORD_STR_REPEAT_FAIL);
            break;
        default:
            instance.setPasswordStrStatus(PASSWORD_STR_MAX);
            break;
        }
        break;

    case PASSWORD_CONFIRM:
        if(instance.sysUserInfo[instance.getUserNumber()].passwd == strKey)
            instance.setPasswordStrStatus(PASSWORD_STR_EDIT_CHANGE);
        else
            instance.setPasswordStrStatus(PASSWORD_STR_CONFIRM_FAIL);
        break;

    case PASSWORD_INIT:
        if(instance.getStrNowUserPassword() == strKey)
        {
            instance.setPasswordStatusPrev(PASSWORD_INIT);
            instance.setPasswordStrStatus(PASSWORD_STR_REPEAT);
        }
        else
        {
            instance.setPasswordStrStatus(PASSWORD_STR_CONFIRM_FAIL);
        }
        break;
    case PASSWORD_MAX:
        instance.setPasswordStrStatus(PASSWORD_STR_MAX);
        break;

    default:
        qDebug() << "keyboard check instance.getPasswordStatus range over";
        break;
    }

    emit signalCheckLogin();
}

void ComponentPasswordKeyboard::clearKey()
{
    strKey.clear();
    emit signalKeyClick(getDisplayText());
}

void ComponentPasswordKeyboard::functionShowHide()
{
    bIsShowAll = !bIsShowAll;
    emit signalKeyClick(getDisplayText());
}
