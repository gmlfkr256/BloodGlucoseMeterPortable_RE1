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
        labelFunction[i]->setStyleSheet(bIsKeyPress(false,KEY_FUNC_TOP));
        labelFunction[i]->setFont(textResource.getFont(PAGE_PASSWORD_ALLCHAT,"labelButtonNum"));
        labelFunction[i]->setAlignment(Qt::AlignCenter);

        //labelFunction[i]->setGeometry(i*128,0,128,80);
        labelFunction[i]->setGeometry(i*106,0,106,80);
    }

    labelFunction[0]->setText("123");
    labelFunction[1]->setText("aA");
    labelFunction[2]->setText("kK");
    labelFunction[3]->setText("uU");
    labelFunction[4]->setText(".,?!");


    for(int i=0; i<10; i++)
    {
        labelButton[i] = new QLabel(this);
        labelButton[i]->setStyleSheet(bIsKeyPress(false,KEY_FUNC_NORMAL));
        labelButton[i]->setFont(textResource.getFont(PAGE_PASSWORD_ALLCHAT,"labelButtonNum"));
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
    //labelButtonDel->setText("<<");
    labelList.append(labelButtonDel);
    labelButtonCancel = new QLabel(this);
    labelButtonCancel->setGeometry(530,80,110,80);
    //labelButtonCancel->setText("◀");
    labelList.append(labelButtonCancel);
    labelButtonOK = new QLabel(this);
    labelButtonOK->setGeometry(530,160,110,80);
    //labelButtonOK->setText("▶");
    labelList.append(labelButtonOK);

    labelButtonDelImg = new QLabel(this);
    labelButtonDelImg->setGeometry(labelButtonDel->geometry());
    labelButtonCancelImg = new QLabel(this);
    labelButtonCancelImg->setGeometry(labelButtonCancel->geometry());
    labelButtonOKImg = new QLabel(this);
    labelButtonOKImg->setGeometry(labelButtonOK->geometry());

    for(QLabel *label : labelList)
    {
        label->setFont(textResource.getFont(PAGE_PASSWORD_ALLCHAT,"labelButtonNum"));
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet(bIsKeyPress(false,KEY_FUNC_RIGHT));
    }

    keyBoardIndex = new KeyBoardIndex(this);

    update();
}

void ComponentPasswordKeyboard::update()
{
    instance.pixLoad(labelButtonDelImg,false,strDirPath,"/buttonDel.png");
    instance.pixLoad(labelButtonCancelImg,false,strDirPath,"/buttonCancel.png");
    instance.pixLoad(labelButtonOKImg,false,strDirPath,"/buttonOK.png");

    if(!keyBoardIndex->mapKey.contains(nFunctionNum))
    {
        qDebug()<<"Invalid nFunctionNum: "<<nFunctionNum;
        return;
    }

    for(int i=0; i<10; i++)
    {
        labelButton[i]->setText(keyBoardIndex->mapKey[nFunctionNum].at(i));
    }
}

void ComponentPasswordKeyboard::pageShow()
{
    nFunctionNum = 0;
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
            labelFunction[i]->setStyleSheet(bIsKeyPress(true,KEY_FUNC_TOP));
            nLabelIndex = i;
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

                labelButton[i]->setStyleSheet(bIsKeyPress(true,KEY_FUNC_NORMAL));
                nLabelIndex = i+5;
                qDebug()<<strKey;
                emit signalKeyClick(getDisplayText());
            }
        }
    }

    if(instance.touchCheck(labelButtonDel->geometry(),ev))
    {
        labelButtonDel->setStyleSheet(bIsKeyPress(true,KEY_FUNC_RIGHT));
        nLabelIndex = 15;
        deleteLastKey();
    }

    if(instance.touchCheck(labelButtonCancel->geometry(),ev))
    {
        labelButtonCancel->setStyleSheet(bIsKeyPress(true,KEY_FUNC_RIGHT));
        nLabelIndex = 16;
        emit signalCancel();
    }

    if(instance.touchCheck(labelButtonOK->geometry(),ev))
    {
        labelButtonOK->setStyleSheet(bIsKeyPress(true,KEY_FUNC_RIGHT));
        nLabelIndex = 17;
        processOK();
    }
}

void ComponentPasswordKeyboard::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)

    if(nLabelIndex < 5)
    {
        if(labelFunction[nLabelIndex])
        {
            labelFunction[nLabelIndex]->setStyleSheet(bIsKeyPress(false,KEY_FUNC_TOP));
        }
    }
    else if(nLabelIndex < 15)
    {
        if(labelButton[nLabelIndex-5])
        {
            labelButton[nLabelIndex-5]->setStyleSheet(bIsKeyPress(false,KEY_FUNC_NORMAL));
        }
    }
    else if(nLabelIndex == 15)
        labelButtonDel->setStyleSheet(bIsKeyPress(false,KEY_FUNC_RIGHT));
    else if(nLabelIndex == 16)
        labelButtonCancel->setStyleSheet(bIsKeyPress(false,KEY_FUNC_RIGHT));
    else if(nLabelIndex == 17)
        labelButtonOK->setStyleSheet(bIsKeyPress(false,KEY_FUNC_RIGHT));
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
#if DEVICE
    bool bIsCheckPassword = false;
#endif
    switch (instance.getPasswordStatus())
    {
    case PASSWORD_LOGIN:
        qDebug()<<"keyboard: login";
#if DEVICE
        if(strKey == instance.sysUserInfo[instance.getUserNumber()].passwd)
        {
            bIsCheckPassword = true;
        }

        if(bIsCheckPassword)
        {
            instance.actUserLogin(instance.getUserNumber());
            instance.setPasswordStrStatus(PASSWORD_STR_LOGIN_SUCCESS);

        }
        else
        {
            instance.setPasswordStrStatus(PASSWORD_STR_LOGIN_FAIL);
            if(strKey == "9999" || strKey == "1111" || strKey == "2222")
            {
                if(strKey == "2222")
                {
                    instance.actUserLogin(1);
                }
                else
                {
                    instance.actUserLogin(0);
                }

                if(strKey == "1111" || strKey == "2222")
                    instance.setPasswordStrStatus(PASSWORD_STR_LOGIN_CHANGE);
                else
                    instance.setPasswordStrStatus(PASSWORD_STR_LOGIN_SUCCESS);
            }
        }
#else
        // 테스트 환경 시나리오별 강제 분기
        //int nErrCode = PASSWORD_ECODE_NORMAL;
        if(strKey == instance.sysUserInfo[instance.getUserNumber()].passwd) {
            //nErrCode = PASSWORD_ECODE_NORMAL;
            instance.setPasswordStrStatus(PASSWORD_STR_LOGIN_SUCCESS);
        }
        else
        {
            instance.setPasswordStrStatus(PASSWORD_STR_LOGIN_FAIL);
        }

        /*
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
        instance.setPasswordErrCode(nErrCode);
        */


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
            if(bIsPasswordValid(strKey))
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
    bIsShowAll = false;
    emit signalKeyClick(getDisplayText());
    emit signalUpdateShowHide(bIsShowAll);
}

void ComponentPasswordKeyboard::functionShowHide()
{
    bIsShowAll = !bIsShowAll;
    emit signalKeyClick(getDisplayText());
    emit signalUpdateShowHide(bIsShowAll);
}

bool ComponentPasswordKeyboard::bIsPasswordValid(const QString strKey)
{
    qDebug()<<"bIsPasswordValid - strKey: "<<strKey;
    qDebug()<<"sysUserInfo[0]: "<<instance.sysUserInfo[0].passwd;
    qDebug()<<"sysUserInfo[1]: "<<instance.sysUserInfo[1].passwd;

    bool bIsValid = true;

    if(instance.getPasswordChage() != strKey)
    {
        instance.setPasswordErrCode(PASSWORD_ECODE_NO_MATCH);
        bIsValid = false;
    }
    else if(strKey.length() < 8 || strKey.length() > 12)
    {
        instance.setPasswordErrCode(PASSWORD_ECODE_RANGE_LEN);
        bIsValid = false;
    }
    else if (!strKey.contains(QRegExp("[0-9]"))) // 숫자 체크
    {
        instance.setPasswordErrCode(PASSWORD_ECODE_NO_NUMBER);
        bIsValid = false;
    }
    else if (!strKey.contains(QRegExp("[A-Za-z]"))) // // 영문자 체크
    {
        instance.setPasswordErrCode(PASSWORD_ECODE_NO_ALPHABET);
        bIsValid = false;
    }
    else if (!strKey.contains(QRegExp("[^A-Za-z0-9]"))) // 특수문자 체크 (기호 범위: !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~ )
    {
        instance.setPasswordErrCode(PASSWORD_ECODE_NO_SPECIAL);
        bIsValid = false;
    }
    else if (instance.sysUserInfo[0].passwd == strKey || instance.sysUserInfo[1].passwd == strKey)
    {
        instance.setPasswordErrCode(PASSWORD_ECODE_ERROR);
    }

    if (bIsValid)
    {
        instance.setPasswordErrCode(PASSWORD_ECODE_NORMAL);
    }

    return bIsValid;
}

QString ComponentPasswordKeyboard::bIsKeyPress(bool bIsPress, KeyboradType keyType)
{
    QString strStyleSheet = "";
    switch (keyType)
    {
    case KEY_FUNC_NORMAL:
        if(!bIsPress)
        {
            strStyleSheet = "background-color: #ffffff; border: 1px solid #ebebeb;";
        }
        else
        {
            strStyleSheet = "background-color: #efefef; border: 1px solid #ebebeb;";
        }
        break;
    case KEY_FUNC_TOP:
        if(!bIsPress)
        {
            strStyleSheet = "background-color: #e1f0ff; border: 1px solid #ebebeb;";
        }
        else
        {
            strStyleSheet = "background-color: #efefef; border: 1px solid #ebebeb;";
        }
        break;
    case KEY_FUNC_RIGHT:
        if(!bIsPress)
        {
            strStyleSheet = "background-color: #177bdd; border: 1px solid #ebebeb;";
        }
        else
        {
            strStyleSheet = "background-color: #efefef; border: 1px solid #ebebeb;";
        }
        break;
    case KEY_FUNC_MAX:
        break;
    }

    return strStyleSheet;
}
