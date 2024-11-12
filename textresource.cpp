#include "textresource.h"

TextResource& TextResource::getInstance()
{
    static TextResource instance;
    return instance;
}

TextResource::TextResource()
{
    init();
}

void TextResource::init()
{
    //KR
    //CUSTOM_BUTTON
    DeviceLanguage Lan = KR;
    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonOK",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Medium));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonOK",QStringList{"확인"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Medium));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel",QStringList{"취소"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonHome",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Medium));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonHome",QStringList{"홈"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Medium));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart",QStringList{"측정시작"});

    //PAGE_PASSWORD
    fontData[Lan][PAGE_PASSWORD].insert("labelButtonNum",QFont(instance.fontSuit,instance.pixelToPoint(44),QFont::Medium));

    textData[Lan][PAGE_PASSWORD].insert("labelTitle",QStringList{"로그인을 하세요","비밀번호 수정","사용자 삭제","비밀번호 확인","비밀번호 재확인","PASSWORD_MAX"});
    fontData[Lan][PAGE_PASSWORD].insert("labelTitle",QFont(instance.fontSuit,instance.pixelToPoint(40),QFont::Bold));

    textData[Lan][PAGE_PASSWORD].insert("labelTitleSub",QStringList{
                                            "비밀번호 4자리를 눌러주세요",
                                            "수정할 번호 4자리를 눌러주세요",
                                            "확인을 위해 4자리를 눌러주세요",
                                            "재확인을 위해 4자리를 눌러주세요",
                                            "PASSWORD_MAX"
                                        });
    fontData[Lan][PAGE_PASSWORD].insert("labelTitleSub",QFont(instance.fontSuit,instance.pixelToPoint(30)));

    textData[Lan][PAGE_PASSWORD].insert("labelButtonOKText",QStringList{"확인"});
    fontData[Lan][PAGE_PASSWORD].insert("labelButtonOKText",QFont(instance.fontSuit,instance.pixelToPoint(48)));

    //PAGE_PASSWORD_CONFIRM
    fontData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(30)));
    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelText",QStringList{
                                                    "로그인에 성공했습니다", //PASSWORD_STR_LOGIN_SUCCESS,
                                                    "로그인에 실패했습니다", //PASSWORD_STR_LOGIN_FAIL,
                                                    "비밀번호를 변경해주시기 바랍니다", //PASSWORD_STR_LOGIN_CHANGE,
                                                    "본인 확인을 위해\n 비밀번호를 입력해주세요", //PASSWORD_STR_CONFIRM,
                                                    "비밀번호가 일치하지 않습니다", //PASSWORD_STR_CONFIRM_FAIL,
                                                    "정확한 확일은 위해\n 비밀번호를 한번 더 입력해주세요", //PASSWORD_STR_REPEAT,
                                                    "입력된 비밀번호가\n 이전 비밀번호와 일치하지 않습니다", //PASSWORD_STR_REPEAT_FAIL,
                                                    "비밀번호를 변경하시겠습니까?", //PASSWORD_STR_EDIT,
                                                    "본인 확인을 위해\n 비밀번호를 입력해주세요", //PASSWORD_STR_EDIT_CONFIRM,
                                                    "변경하실 비밀번호를 입력해주세요", //PASSWORD_STR_EDIT_CHANGE,
                                                    "비밀번호 변경이 완료되었습니다\n재로그인해주시기 바랍니다", //PASSWORD_STR_EDIT_SUCCESS,
                                                    "사용자 정보를 삭제하시겠습니까?", //PASSWORD_STR_DELETE,
                                                    "사용자 정보를 삭제할 경우\n 비밀번호와 설정이 초기화 됩니다", //PASSWORD_STR_DELETE_CONFIRM,
                                                    "사용자 정보가 삭제되었습니다\n설정 초기화를 위해\n 재부팅이 진행됩니다", //PASSWORD_STR_DELETE_SUCCESS,
                                                    "로그아웃을 진행합니다\n재로그인해주시기 바랍니다", //PASSWORD_STR_LOGOUT,
                                                    "PASSWORD_STR_MAX" //PASSWORD_STR_MAX
                                                });

    //PAGE_HOME
    fontData[Lan][PAGE_HOME].insert("labelButtonTitle",QFont(instance.fontSuit,instance.pixelToPoint(33),QFont::Bold));
    textData[Lan][PAGE_HOME].insert("labelButtonTitle",QStringList{"기상","조식 전","조식 후","중식 전","중식 후","석식 전","석식 후","취침"});

    fontData[Lan][PAGE_HOME].insert("labelButtonText",QFont(instance.fontSuit,instance.pixelToPoint(62),QFont::ExtraBold));

    //PAGE_SELECT
    fontData[Lan][PAGE_SELECT].insert("labelTextStatus",QFont(instance.fontSuit,instance.pixelToPoint(42),QFont::ExtraBold));
    textData[Lan][PAGE_SELECT].insert("labelTextStatus",QStringList{"기상","조식 전","조식 후","중식 전","중식 후","석식 전","석식 후","취침"});

    fontData[Lan][PAGE_SELECT].insert("labelTextStatusSub",QFont(instance.fontSuit,instance.pixelToPoint(24)));
    textData[Lan][PAGE_SELECT].insert("labelTextStatusSub",QStringList{"측정을 시작해 주세요"});

    fontData[Lan][PAGE_SELECT].insert("labelTextGlucoseValue",QFont(instance.fontSuit,instance.pixelToPoint(131),QFont::Black));

    //====================================================================================================================================
    //EN
    Lan = EN;
    //CUSTOM_BUTTON
    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonOK",QFont(instance.fontSuit,instance.pixelToPoint(35),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonOK",QStringList{"OK"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel",QFont(instance.fontSuit,instance.pixelToPoint(35),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonCacnel",QStringList{"Cancel"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonHome",QFont(instance.fontSuit,instance.pixelToPoint(35),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonHome",QStringList{"Home"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart",QFont(instance.fontSuit,instance.pixelToPoint(35),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart",QStringList{"Start"});

    //PAGE_PASSWORD
    fontData[Lan][PAGE_PASSWORD].insert("labelButtonNum",QFont(instance.fontSuit,instance.pixelToPoint(44),QFont::Bold));

    textData[Lan][PAGE_PASSWORD].insert("labelTitle",QStringList{"Please log in","Edit Password","Delete User","Password Confirmation","Password Re-confirmation","PASSWORD_MAX"});
    fontData[Lan][PAGE_PASSWORD].insert("labelTitle",QFont(instance.fontSuit,instance.pixelToPoint(40),QFont::Bold));

    textData[Lan][PAGE_PASSWORD].insert("labelTitleSub", QStringList{
                                            "Please enter your 4-digit password",
                                            "Please enter the 4 digits to modify",
                                            "Please confirm by entering 4 digits",
                                            "Please re-enter the 4 digits to verify",
                                            "PASSWORD_MAX"
                                        });
    fontData[Lan][PAGE_PASSWORD].insert("labelTitleSub",QFont(instance.fontSuit,instance.pixelToPoint(30)));

    textData[Lan][PAGE_PASSWORD].insert("labelButtonOKText",QStringList{"OK"});
    fontData[Lan][PAGE_PASSWORD].insert("labelButtonOKText",QFont(instance.fontSuit,instance.pixelToPoint(48)));

    //PAGE_PASSWORD_CONFIRM
    fontData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(30)));
    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelText",QStringList{
                                                    "Login successful",                              // PASSWORD_STR_LOGIN_SUCCESS
                                                    "Login failed",                                  // PASSWORD_STR_LOGIN_FAIL
                                                    "Please change your password",                   // PASSWORD_STR_LOGIN_CHANGE
                                                    "Please enter your password\n for verification", // PASSWORD_STR_CONFIRM
                                                    "Passwords do not match",                        // PASSWORD_STR_CONFIRM_FAIL
                                                    "Please enter your password\n again for accuracy", // PASSWORD_STR_REPEAT
                                                    "The entered password\n does not match the \nprevious password", // PASSWORD_STR_REPEAT_FAIL
                                                    "Would you like \nto change your password?",     // PASSWORD_STR_EDIT
                                                    "Please enter your password\n for verification", // PASSWORD_STR_EDIT_CONFIRM
                                                    "Please enter the new password",                 // PASSWORD_STR_EDIT_CHANGE
                                                    "Password change completed\nPlease re-login",    // PASSWORD_STR_EDIT_SUCCESS
                                                    "Do you want to\n delete user information?",     // PASSWORD_STR_DELETE
                                                    "Deleting user information\n will reset the password\n and settings", // PASSWORD_STR_DELETE_CONFIRM
                                                    "User information deleted\nThe system will reboot\n to reset settings", // PASSWORD_STR_DELETE_SUCCESS
                                                    "Logging out\nPlease re-login",                  // PASSWORD_STR_LOGOUT
                                                    "PASSWORD_STR_MAX"                                      // PASSWORD_STR_MAX
                                                });

    //PAGE_HOME
    fontData[Lan][PAGE_HOME].insert("labelButtonTitle",QFont(instance.fontSuit,instance.pixelToPoint(26),QFont::Bold));
    textData[Lan][PAGE_HOME].insert("labelButtonTitle",QStringList{"Wake\nUp","Before\nBreakfast","After\nBreakfast","Before\nLunch","After\nLunch","Before\nDinner","After\nDinner","Bed\nTime"});

    fontData[Lan][PAGE_HOME].insert("labelButtonText",QFont(instance.fontSuit,instance.pixelToPoint(62),QFont::ExtraBold));

    //PAGE_SELECT
    fontData[Lan][PAGE_SELECT].insert("labelTextStatus", QFont(instance.fontSuit, instance.pixelToPoint(42), QFont::ExtraBold));
    textData[Lan][PAGE_SELECT].insert("labelTextStatus", QStringList{"Wake Up", "Before Breakfast", "After Breakfast", "Before Lunch", "After Lunch", "Before Dinner", "After Dinner", "Sleep"});

    fontData[Lan][PAGE_SELECT].insert("labelTextStatusSub", QFont(instance.fontSuit, instance.pixelToPoint(24)));
    textData[Lan][PAGE_SELECT].insert("labelTextStatusSub", QStringList{"Please start the measurement"});

    fontData[Lan][PAGE_SELECT].insert("labelTextGlucoseValue",QFont(instance.fontSuit,instance.pixelToPoint(131),QFont::Black));
    //=====================================================================================================================================
    //JP
    //CN_GAN
    //CN_BUN
}

QStringList TextResource::getText(PageNum page, const QString& textName)
{
    DeviceLanguage lang = instance.getDeviceLanguage();
    if(textData.contains(lang) && textData[lang].contains(page))
    {
        return textData[lang][page].value(textName,QStringList{"EMPTY"});
    }

    qDebug()<<"getText fail: "<<textName;
    return QStringList{"EMPTY"};
}

QFont TextResource::getFont(PageNum page, const QString& textName)
{
    DeviceLanguage lang = instance.getDeviceLanguage();
    if(fontData.contains(lang) && fontData[lang].contains(page))
    {
        return fontData[lang][page].value(textName,QFont("Default",12));
    }

    qDebug()<<"getFont fail";
    return QFont("Default",12);
}
