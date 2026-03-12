#include "textresource.h"

TextResource& TextResource::getInstance()
{
    static TextResource instance;
    return instance;
}

TextResource::TextResource()
{
    //init();
}

void TextResource::init()
{
    int nTextSize = 0;

    //KR
    //CUSTOM_BUTTON
    DeviceLanguage Lan = KR;
    nTextSize = 36;
    QString currentFont = instance.fontSuit;

    //PAGE_TRANS
    fontData[Lan][PAGE_TRANS].insert("fontSuit",QFont(instance.fontSuit,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_TRANS].insert("fontJP",QFont(instance.fontJP,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_TRANS].insert("fontSC",QFont(instance.fontSC,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_TRANS].insert("fontTC",QFont(instance.fontTC,instance.pixelToPoint(36)));

    textData[Lan][PAGE_TRANS].insert("lang",QStringList{
                                         "한국어",
                                         "ENGLISH",
                                         "日本語",
                                         "繁體中文",
                                         "简体中文",
                                         "ESPAÑOL"
                                     });


    //CUSTOM_BUTTON
    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonOK",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonOK",QStringList{"확인"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel",QStringList{"취소"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonHome",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonHome",QStringList{"홈"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart",QStringList{"측정시작"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasure",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasure",QStringList{"측정"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonInput",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonInput",QStringList{"입력"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe",QStringList{"재측정"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonSave",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonSave",QStringList{"저장"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonUpgrade",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonUpgrade",QStringList{"소프트웨어 업그레이드"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QStringList{"네"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QStringList{"아니오"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QStringList{
                                            "한국어",
                                            "ENGLISH",
                                            "日本語",
                                            "繁體中文",
                                            "简体中文",
                                            "ESPAÑOL"
                                        });

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonBack",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonBack",QStringList{"이전"}); // todo trans

    //CUSTOM_COMPONENT
    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextValue",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextResult",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    //add
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextResult",QStringList{
                                               "측정에 성공하였습니다",     // 0
                                               "손가락을 인식하지 못했습니다\n다시 측정해 주세요", // 1
                                               "기기에 문제가 발생했습니다\n고객센터로 문의해 주세요",                // 2
                                               "기기에 문제가 발생했습니다\n고객센터로 문의해 주세요",              // 3
                                               "측정 결과를 분석할 수 없습니다\n다시 측정해 주세요",             // 4
                                               "측정된 데이터에 오류가 있습니다\n다시 측정해 주세요",             // 5
                                               "충전 중에는 측정하실 수 없습니다\n제거 후 측정해 주세요",    //6
                                               "손가락 표면온도가 낮아\n측정할 수 없습니다",               // 7
                                               "측정에 실패했습니다\n고객센터로 문의해 주세요",              // 8
                                           });

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade",QFont(currentFont,instance.pixelToPoint(42),QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade",QStringList{
                                               "업그레이드에 성공하였습니다", // 0
                                               "업그레이드가 실패했습니다\n고객센터에 문의해 주세요", //1
                                               "업그레이드 파일이 보이지 않습니다\n파일을 다시 확인해 주세요", //2
                                               "업그레이드 파일에 문제가 있습니다\n새 파일로 다시 시도해 주세요", //3
                                               "업그레이드용 파일이 아닙니다\n올바른 파일인지 확인해 주세요", //4
                                               "업그레이드가 실패했습니다\n고객센터에 문의해 주세요" //5
                                           });

    //CUSTOM_COMPONENT_DATE
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelText",QFont(currentFont,instance.pixelToPoint(50)));
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelTextSelect",QFont(currentFont,instance.pixelToPoint(50),QFont::Bold));
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelTextSub",QFont(currentFont,instance.pixelToPoint(40)));


    //PAGE_PASSWORD
    fontData[Lan][PAGE_PASSWORD].insert("labelButtonNum",QFont(currentFont,instance.pixelToPoint(44),QFont::Bold));

    fontData[Lan][PAGE_PASSWORD].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(40),QFont::Bold));
    textData[Lan][PAGE_PASSWORD].insert("labelTitle",QStringList{"로그인을 하세요","비밀번호 변경","사용자 삭제","비밀번호 확인","비밀번호 재확인","PASSWORD_MAX"});

    fontData[Lan][PAGE_PASSWORD].insert("labelTitleSub",QFont(currentFont,instance.pixelToPoint(30)));
    textData[Lan][PAGE_PASSWORD].insert("labelTitleSub",QStringList{
                                            "비밀번호 4자리를 눌러주세요",
                                            "변경할 번호 4자리를 눌러주세요",
                                            "비밀번호 4자리를 눌러주세요",
                                            "확인을 위해 4자리를 눌러주세요",
                                            "재확인을 위해 4자리를 눌러주세요",
                                            "현재 비밀번호를 눌러주세요",
                                            "PASSWORD_MAX"
                                        });

    fontData[Lan][PAGE_PASSWORD].insert("labelButtonOKText",QFont(currentFont,instance.pixelToPoint(29)));
    textData[Lan][PAGE_PASSWORD].insert("labelButtonOKText",QStringList{"확인"});

    fontData[Lan][PAGE_PASSWORD].insert("labelButtonCancelText",QFont(currentFont,instance.pixelToPoint(29)));
    textData[Lan][PAGE_PASSWORD].insert("labelButtonCancelText",QStringList{"취소"});

    //PAGE_SELECT_USER
    fontData[Lan][PAGE_SELECT_USER].insert("labelTitle",QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_SELECT_USER].insert("labelTitle",QStringList{"사용자를 선택해주세요"});

    //fontData[Lan][PAGE_SELECT_USER].insert("labelUserText",QFont(currentFont, instance.pixelToPoint(36)));
    //textData[Lan][PAGE_SELECT_USER].insert("labelUserText",QStringList{"사용자 1","사용자 2"});

    //PAGE_PASSWORD_ALLCHAT
    fontData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelButtonNum",QFont(currentFont,instance.pixelToPoint(44)));

    fontData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(40),QFont::Bold));
    textData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitle",QStringList{"로그인을 하세요","비밀번호 변경","혈당 기록 삭제","비밀번호 확인","비밀번호 재확인","비밀번호 초기화","PASSWORD_MAX"});

    fontData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitleSub",QFont(currentFont,instance.pixelToPoint(30)));
    textData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitleSub",QStringList{
                                                    "비밀번호를 입력해주세요",
                                                    "변경할 비밀번호를 입력해주세요",
                                                    "비밀번호를 입력해주세요",
                                                    "확인을 위해 비밀번호를 입력해주세요",
                                                    "재확인을 위해 비밀번호를 입력해주세요",
                                                    "현재 비밀번호를 입력해주세요",
                                                    "PASSWORD_MAX"
                                                });


    //PAGE_PASSWORD_CONFIRM
    fontData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(40),QFont::Bold));
    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTitle",QStringList{
                                                    "로그인", //PASSWORD_STR_LOGIN_SUCCESS,
                                                    "로그인", //PASSWORD_STR_LOGIN_FAIL,
                                                    "로그인", //PASSWORD_STR_LOGIN_CHANGE,
                                                    "본인 확인", //PASSWORD_STR_CONFIRM,
                                                    "본인 확인", //PASSWORD_STR_CONFIRM_FAIL,
                                                    "비밀번호 확인", //PASSWORD_STR_REPEAT,
                                                    "비밀번호 확인", //PASSWORD_STR_REPEAT_FAIL,
                                                    "비밀번호 변경", //PASSWORD_STR_EDIT,
                                                    "비밀번호 변경", //PASSWORD_STR_EDIT_CONFIRM,
                                                    "비밀번호 변경", //PASSWORD_STR_EDIT_CHANGE,
                                                    "비밀번호 변경", //PASSWORD_STR_EDIT_SUCCESS,
                                                    "혈당 기록 삭제", //PASSWORD_STR_DELETE,
                                                    "혈당 기록 삭제", //PASSWORD_STR_DELETE_CONFIRM,
                                                    "혈당 기록 삭제", //PASSWORD_STR_DELETE_SUCCESS,
                                                    "로그아웃", //PASSWORD_STR_LOGOUT,
                                                    "비밀번호 초기화", //PASSWORD_STR_INIT,
                                                    "비밀번호 초기화", //PASSWORD_STR_INIT_CONFIRM,
                                                    "비밀번호 초기화", //PASSWORD_STR_SUCCESS,
                                                    "PASSWORD_STR_MAX" //PASSWORD_STR_MAX
                                                });
    fontData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelText",QStringList{
                                                    "로그인에 성공했습니다", //PASSWORD_STR_LOGIN_SUCCESS,
                                                    "로그인에 실패했습니다", //PASSWORD_STR_LOGIN_FAIL,
                                                    "비밀번호를 변경해주시기 바랍니다", //PASSWORD_STR_LOGIN_CHANGE,
                                                    "본인 확인을 위해\n 비밀번호를 입력해주세요", //PASSWORD_STR_CONFIRM,
                                                    "비밀번호가 일치하지 않습니다", //PASSWORD_STR_CONFIRM_FAIL,
                                                    "정확한 확인을 위해\n 비밀번호를 한번 더 입력해주세요", //PASSWORD_STR_REPEAT,
                                                    "입력된 비밀번호가\n 이전 비밀번호와 일치하지 않습니다", //PASSWORD_STR_REPEAT_FAIL,
                                                    "비밀번호를 변경하시겠습니까?", //PASSWORD_STR_EDIT,
                                                    "본인 확인을 위해\n 비밀번호를 입력해주세요", //PASSWORD_STR_EDIT_CONFIRM,
                                                    "변경하실 비밀번호를 입력해주세요\n\n 8자이상, 숫자,\n 영문자(A-Z), 기호(.,?! 등)\n\n반드시 포함되어야 합니다", //PASSWORD_STR_EDIT_CHANGE,
                                                    "비밀번호 변경이 완료되었습니다\n다시 로그인해주시기 바랍니다", //PASSWORD_STR_EDIT_SUCCESS,
                                                    "혈당 기록을 삭제하시겠습니까?", //PASSWORD_STR_DELETE,
                                                    "삭제된 혈당 기록은 복구할 수 없습니다", //PASSWORD_STR_DELETE_CONFIRM,
                                                    "혈당 기록이 삭제되었습니다", //PASSWORD_STR_DELETE_SUCCESS,
                                                    "로그아웃을 진행합니다", //PASSWORD_STR_LOGOUT,
                                                    "비밀번호를 초기화하시겠습니까?", //PASSWORD_STR_INIT,
                                                    "비밀번호를 초기화할 경우\n 비밀번호가 초기 설정 상태가 됩니다", //PASSWORD_STR_INIT_CONFIRM,
                                                    "비밀번호가 초기화되었습니다", //PASSWORD_STR_INIT_SUCCESS,가
                                                    "PASSWORD_STR_MAX" //PASSWORD_STR_MAX
                                                });

    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTextError",QStringList{
                                                    "비밀번호가 설정되었습니다", // PASSWORD_ECODE_NORMAL
                                                    "비밀번호는 8~12 자리여야 합니다", // PASSWORD_ECODE_RANGE_LEN
                                                    "숫자가 포함되어야 합니다", // PASSWORD_ECODE_NO_NUMBER
                                                    "영문자(A-Z)가 포함되어야 합니다", // PASSWORD_ECODE_NO_ALPHABET
                                                    "기호(.,?! 등)가 포함되어야 합니다", // PASSWORD_ECODE_NO_SPECTAL
                                                    "비밀번호가 일치하지 않습니다", // PASSWORD_ECODE_NO_MATCH
                                                    "허용하지 않는 비밀번호입니다", // PASSWORD_ECODE_ERROR
                                                    "알 수 없는 오류입니다", // PASSWORD_ECODE_MAX
                                                });

    //PAGE_HOME
    fontData[Lan][PAGE_HOME].insert("labelTextStatus",QFont(currentFont,instance.pixelToPoint(33),QFont::Bold));
    textData[Lan][PAGE_HOME].insert("labelTextStatus",QStringList{"기상","조식 전","조식 후","중식 전","중식 후","석식 전","석식 후","취침"});

    fontData[Lan][PAGE_HOME].insert("labelButtonText",QFont(currentFont,instance.pixelToPoint(62),QFont::ExtraBold));

    //PAGE_SELECT
    fontData[Lan][PAGE_SELECT].insert("labelTextStatus",QFont(currentFont,instance.pixelToPoint(42),QFont::ExtraBold));
    textData[Lan][PAGE_SELECT].insert("labelTextStatus",QStringList{"기상","조식 전","조식 후","중식 전","중식 후","석식 전","석식 후","취침"});
    fontData[Lan][PAGE_SELECT].insert("labelTextStatusSub",QFont(currentFont,instance.pixelToPoint(24)));
    textData[Lan][PAGE_SELECT].insert("labelTextStatusSub",QStringList{"측정을 시작해 주세요"});

    fontData[Lan][PAGE_SELECT].insert("labelTextStatusValue",QFont(currentFont,instance.pixelToPoint(40),QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextGlucoseValue",QFont(currentFont,instance.pixelToPoint(130),QFont::ExtraBold));
    fontData[Lan][PAGE_SELECT].insert("labelTextMgdl",QFont(currentFont,instance.pixelToPoint(30),QFont::ExtraBold));
    fontData[Lan][PAGE_SELECT].insert("labelTextResult",QFont(currentFont,instance.pixelToPoint(36)));
    textData[Lan][PAGE_SELECT].insert("labelTextResult",QStringList{
                                          "정상 혈당",
                                          "저혈당 주의",
                                          "고혈당 주의",
                                          "저혈당 경고",
                                          "고혈당 경고"
                                      });
    textData[Lan][PAGE_SELECT].insert("labelTextResultSub",QStringList{
                                          "입니다"
                                      });

    fontData[Lan][PAGE_SELECT].insert("labelTextTime",QFont(currentFont,instance.pixelToPoint(21)));
    textData[Lan][PAGE_SELECT].insert("labelTextTime",QStringList{"측정 시각"});

    fontData[Lan][PAGE_SELECT].insert("labelTextIcon",QFont(currentFont,instance.pixelToPoint(23),QFont::Bold));
    textData[Lan][PAGE_SELECT].insert("labelTextIcon",QStringList{"정상","저혈당","고혈당","저혈당","고혈당"});

    //PAGE_MENU
    fontData[Lan][PAGE_MENU].insert("labelButtonText",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][PAGE_MENU].insert("labelButtonText",QStringList{
                                        "혈당보정",
                                        "혈당범위",
                                        "혈당기록",
                                        "음량",
                                        "대기모드",
                                        "화면전환",
                                        "날짜시간",
                                        "색상모드",
                                        "언어",
                                        "업그레이드",
                                        "기기정보",
                                        "초기화",
                                        "유저정보",
                                        "제품설명", // todo trans
                                        "FAQ",
                                        "문제해결",
                                    });

    //PAGE_CALI_CEHCK
    fontData[Lan][PAGE_CALI_CHECK].insert("labelTextCheck",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_CHECK].insert("labelTextCheck",QStringList{
                                              "혈당보정 단계입니다\n손가락을 삽입구에 넣어주세요",
                                              "혈당보정 완료입니다\n재진행하시겠습니까?"
                                          });

    //PAGE_CALI_GAIN_CONFIRM
    fontData[Lan][PAGE_CALI_GAIN_CONFIRM].insert("labelTextGainConfirm",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_GAIN_CONFIRM].insert("labelTextGainConfirm",QStringList{
                                                     "LED 감도 조절 단계입니다\n손가락을 움직이지 말아주세요",
                                                     "LED 감도 조절이 끝났습니다\n다음 측정 단계로 넘어가세요"
                                                 });


    //Page_GRAPH
    fontData[Lan][PAGE_GRAPH].insert("labelProgressText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_GRAPH].insert("labelProgressText",QStringList{"completed"});
    fontData[Lan][PAGE_GRAPH].insert("labelProgressValue",QFont(currentFont,instance.pixelToPoint(60),QFont::Bold));
    fontData[Lan][PAGE_GRAPH].insert("labelProgressPercent",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_GRAPH].insert("labelAdcText",QFont(currentFont,instance.pixelToPoint(20)));
    textData[Lan][PAGE_GRAPH].insert("labelAdcText",QStringList{"A:"});
    fontData[Lan][PAGE_GRAPH].insert("labelLoading",QFont(currentFont,instance.pixelToPoint(48),QFont::Bold));
    textData[Lan][PAGE_GRAPH].insert("labelLoading",QStringList{"측정 분석 중입니다"});

    //PAGE_CALI_GAIN_RESULT
    fontData[Lan][PAGE_CALI_GAIN_RESULT].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_GAIN_RESULT].insert("labelText",QStringList{
                                                    "LED 감도 조절이 끝났습니다\n다음 측정 단계로 넘어가세요",
                                                    "LED 감도 조절에 실패했습니다\n다시 측정해주세요"
                                                });
    //PAGE_CALI_SELECT
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectText",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT].insert("labelSelectText",QStringList{
                                               "공복",
                                               "식후"
                                           });

    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextAdc",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextValue",QFont(currentFont,instance.pixelToPoint(36)));

    //PAGE_CALI_SELECT_INFO
    fontData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText",QStringList{
                                                    "공복 8시간 이상 경과되었습니까?\n30분 간격으로 2회 측정합니다(01)", //"공복 8시간 이상\n경과되었습니까?"
                                                    "공복 8시간 이상 경과되었습니까?\n30분 간격으로 2회 측정합니다(02)",
                                                    "식후 1시간 이상\n경과되었습니까?",
                                                    "식후 1시간 30분 이상\n경과되었습니까?",
                                                    "식후 2시간 이상\n경과되었습니까?"
                                                });

    //PAGE_CALI_SELECT_CONFIRM
    fontData[Lan][PAGE_CALI_SELECT_CONFIRM].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_CONFIRM].insert("labelText",QStringList{"순서대로 혈당보정을 진행해주세요"});

    //PAGE_CALI_CONFIRM
    fontData[Lan][PAGE_CALI_CONFIRM].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_CONFIRM].insert("labelText",QStringList{"혈당값 입력 또는 측정을\n하시겠습니까?"});

    //PAGE_CALI_RESULT
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextAdc",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextTemp",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextHeart",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));

    //PAGE_CALI_RESULT_MULTI
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextAdc",QFont(currentFont,instance.pixelToPoint(34),QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextTemp",QFont(currentFont,instance.pixelToPoint(34)));
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextHeart",QFont(currentFont,instance.pixelToPoint(34)));

    //PAGE_CALI_RESULT_MULTI_CONFIRM
    fontData[Lan][PAGE_CALI_RESULT_MULTI_CONFIRM].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_RESULT_MULTI_CONFIRM].insert("labelText",QStringList{"선택한 혈당값을 삭제하고\n재측정하시겠습니까?"});

    //PAGE_RESULT
    fontData[Lan][PAGE_RESULT].insert("labelTextGlucoseValue",QFont(currentFont,instance.pixelToPoint(103),QFont::ExtraBold));

    fontData[Lan][PAGE_RESULT].insert("labelTextMgdl",QFont(currentFont,instance.pixelToPoint(27)));
    textData[Lan][PAGE_RESULT].insert("labelTextMgdl",QStringList{"mg/dL"});

    fontData[Lan][PAGE_RESULT].insert("labelTextTime",QFont(currentFont,instance.pixelToPoint(21),QFont::Bold));
    textData[Lan][PAGE_RESULT].insert("labelTextTime",QStringList{"측정 시각"});

    fontData[Lan][PAGE_RESULT].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));

    textData[Lan][PAGE_RESULT].insert("indexResult",QStringList{
                                          "정상 혈당",
                                          "저혈당 주의",
                                          "고혈당 주의",
                                          "저혈당 경고",
                                          "고혈당 경고"
                                      });
    textData[Lan][PAGE_RESULT].insert("indexResultSub",QStringList{
                                          "입니다"
                                      });

    fontData[Lan][PAGE_RESULT].insert("labelProgressBarTooltip",QFont(currentFont,instance.pixelToPoint(16),QFont::Bold));
    textData[Lan][PAGE_RESULT].insert("labelProgressBarTooltip",QStringList{
                                          "정상",
                                          "주의",
                                          "경고",
                                          "에러"
                                      });

    //PAGE_INIT
    fontData[Lan][PAGE_INIT].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    textData[Lan][PAGE_INIT].insert("labelText",QStringList{
                                        "전체 초기화",
                                        "블루투스 초기화",
                                        "혈당보정 초기화"
                                    });

    //PAGE_INIT_CONFIRM
    fontData[Lan][PAGE_INIT_CONFIRM].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_INIT_CONFIRM].insert("labelText",QStringList{
                                                "전체 시스템 정보가 초기화됩니다\n초기화를 진행하시겠습니까?",
                                                "시스템 초기화 진행 후\n시스템이 재시작합니다",
                                                "블루투스가 초기화됩니다\n스마트 폰과의 연결이 해제됩니다\n초기화를 진행하시겠습니까?",
                                                "블루투스 정보가 초기화되었습니다",
                                                "혈당보정이 초기화됩니다\n혈당보정을 초기화하시겠습니까?",
                                                "혈당보정이 초기화되었습니다"
                                            });


    fontData[Lan][PAGE_THRESHOLD].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    textData[Lan][PAGE_THRESHOLD].insert("labelText",QStringList{
                                             "저혈당",
                                             "고혈당"
                                         });

    fontData[Lan][PAGE_THRESHOLD].insert("labelButton",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][PAGE_THRESHOLD].insert("labelButton",QStringList{"설정"});

    fontData[Lan][PAGE_THRESHOLD].insert("labelValue",QFont(currentFont,instance.pixelToPoint(48),QFont::Bold));

    fontData[Lan][PAGE_THRESHOLD].insert("labelValueRange",QFont(currentFont,instance.pixelToPoint(26)));
    textData[Lan][PAGE_THRESHOLD].insert("labelValueRange",QStringList{
                                             "이하",
                                             "이상"
                                         });

    //PAGE_SOUND
    fontData[Lan][PAGE_SOUND].insert("labelVolume",QFont(currentFont,instance.pixelToPoint(110),QFont::Bold));

    //PAGE_SLEEP
    fontData[Lan][PAGE_SLEEP].insert("labelText",QFont(currentFont,instance.pixelToPoint(42),QFont::Bold));
    textData[Lan][PAGE_SLEEP].insert("labelText",QStringList{
                                         "30초",
                                         "1분",
                                         "3분",
                                         "5분",
                                         "10분",
                                         "없음"
                                     });
    //PAGE_UPGRADE
    fontData[Lan][PAGE_UPGRADE].insert("labelText",QFont(currentFont,instance.pixelToPoint(42),QFont::Bold));
    textData[Lan][PAGE_UPGRADE].insert("labelText",QStringList{"현재 버전"});

    fontData[Lan][PAGE_UPGRADE].insert("labelTextVersion",QFont(currentFont,instance.pixelToPoint(55)));

    //PAGE_UPGRADE_CONFIRM
    fontData[Lan][PAGE_UPGRADE_CONFIRM].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_UPGRADE_CONFIRM].insert("labelText",QStringList{
                                                   "1. 장치와 PC연결\n"
                                                   "2. 장치에 bin 파일 복사\n"
                                                   "3. 복사 완료 후 장치 재부팅"
                                               });
    //PAGE_DEVICEINFO
    fontData[Lan][PAGE_DEVICEINFO].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_DEVICEINFO].insert("labelTitle",QStringList{
                                              "BLE",
                                              "H/W ver",
                                              "S/W ver",
                                              "Serial"
                                          });

    fontData[Lan][PAGE_DEVICEINFO].insert("labelText",QFont(currentFont,instance.pixelToPoint(30)));

    //PAGE_USERINFO
    fontData[Lan][PAGE_USERINFO].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    textData[Lan][PAGE_USERINFO].insert("labelText",QStringList{
                                            "비밀번호 변경",
                                            "비밀번호 초기화",
                                            "혈당 기록 삭제",
                                            "로그아웃"
                                        });

    //PAGE_BATPOPUP
    fontData[Lan][PAGE_BATPOPUP].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_BATPOPUP].insert("labelText",QStringList{
                                            "배터리 부족",
                                            "배터리 매우 부족"
                                        });
    fontData[Lan][PAGE_BATPOPUP].insert("labelTextSub",QFont(currentFont,instance.pixelToPoint(nTextSize)));
    textData[Lan][PAGE_BATPOPUP].insert("labelTextSub",QStringList{
                                            "충전기를 연결하세요",
                                            "시스템을 종료합니다"
                                        });

    //PAGE_REVERSE
    fontData[Lan][PAGE_REVERSE].insert("labelTextButton",QFont(currentFont,instance.pixelToPoint(36)));
    textData[Lan][PAGE_REVERSE].insert("labelTextButton",QStringList{
                                           "왼손",
                                           "오른손"
                                       });
    fontData[Lan][PAGE_REVERSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize)));
    textData[Lan][PAGE_REVERSE].insert("labelText",QStringList{
                                           "화면전환 설정 후 재시작 됩니다"
                                       });


    //PAGE_HISTORY
    fontData[Lan][PAGE_HISTORY].insert("labelButton",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][PAGE_HISTORY].insert("labelButton",QStringList{
                                           "+ 7일 후",
                                           "오늘",
                                           "- 7일 전"
                                       });

    //**************//

    //PAGE_ELAPSED_NOTICE_POPUP
    fontData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("labelTitle",QStringList{
                                                        "혈당보정 유효기간"
                                                    });

    fontData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));

    textData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("elapsedText",QStringList{
                                                        "1일 후 만료",
                                                        "2일 후 만료",
                                                        "3일 후 만료",
                                                        "4일 후 만료",
                                                        "5일 후 만료",
                                                        "6일 후 만료",
                                                        "7일 후 만료",
                                                        "8일 후 만료",
                                                        "9일 후 만료",
                                                        "10일 후 만료",
                                                        "11일 후 만료",
                                                        "12일 후 만료",
                                                        "13일 후 만료",
                                                        "14일 후 만료",
                                                        "15일 후 만료"
                                                    });

    textData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("warningText",QStringList{
                                                        "만료(측정불가)"
                                                    });

    //PAGE_BLOOD_CHECK
    fontData[Lan][PAGE_BLOOD_CHECK].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_BLOOD_CHECK].insert("labelText",QStringList{
                                               "전문의료기관 혈당값입니까?"
                                           });

    //PAGE_BLOOD_NOTICE_POPUP
    fontData[Lan][PAGE_BLOOD_NOTICE_POPUP].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_BLOOD_NOTICE_POPUP].insert("labelText",QStringList{
                                                      "측정 범위를 벗어났습니다"
                                                  });

    //PAGE_USER_CHECK
    fontData[Lan][PAGE_USER_CHECK].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK].insert("labelText",QStringList{
                                              "당뇨 전단계",
                                              "비당뇨",
                                              "당뇨"
                                          });
    fontData[Lan][PAGE_USER_CHECK].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK].insert("labelTitle",QStringList{
                                              "사용자 유형 선택"
                                          });

    //PAGE_BLOOD_CHECK_NOTICE //unused
    fontData[Lan][PAGE_BLOOD_CHECK_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_BLOOD_CHECK_NOTICE].insert("labelText",QStringList{
                                                      "정맥혈에 대한 정보가 없습니다\n정맥혈 정보를 입력해주시기 바랍니다"
                                                  });

    //PAGE_CALI_VALUE_NOTICE //unused
    fontData[Lan][PAGE_CALI_VALUE_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_VALUE_NOTICE].insert("labelText",QStringList{
                                                     "범위를 벗어났습니다\n범위 안의 값을 입력해주세요"
                                                 });

    //PAGE_USER_NOTICE
    fontData[Lan][PAGE_USER_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_NOTICE].insert("labelText",QStringList{
                                               "본 제품은 약물을 투여하지 않는\n\n 당뇨 전단계 환자용 의료기기 입니다"
                                           });

    //PAGE_USER_FINGER
    fontData[Lan][PAGE_USER_FINGER].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_FINGER].insert("labelTitle",QStringList{
                                               "손가락 권장 둘레"
                                           });

    //PAGE_CALI_NOTICE
    fontData[Lan][PAGE_CALI_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_NOTICE].insert("labelText",QStringList{
                                               "재보정을 진행하시겠습니까?"
                                           });

    //PAGE_USER_CHECK_NOTICE
    fontData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelText",QStringList{
                                                     "사용대상자 : 없음",
                                                     "사용대상자 : 비당뇨",
                                                     "사용대상자 : 당뇨 전단계",
                                                     "사용대상자 : 당뇨",
                                                 });

    fontData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelCaliDay",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelCaliDay",QStringList{
                                                     "보정 완료일 : "
                                                 });

    //PAGE_USER_CAUTIONS
    fontData[Lan][PAGE_USER_CAUTIONS].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CAUTIONS].insert("labelTitle",QStringList{
                                                 "해피존 유의사항"
                                             });

    fontData[Lan][PAGE_USER_CAUTIONS].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CAUTIONS].insert("labelText",QStringList{
                                                 "1. 일정한 호흡 유지",
                                                 "2. 측정 중 말을 삼가, 움직임 금지",
                                                 "3. 손가락에 힘/압력 금지",
                                                 "4. 손가락에 물기와 이물질X",
                                                 "5. 손가락 표면온도 26°C 이상 유지",
                                                 "6. 손가락을 측정부에 밀착, 수평 유지",
                                                 "7. 반드시 충전기를 분리해서 사용",
                                                 "8. 사용장소 온도확인(20~30°C 이내)",
                                             });

    //PAGE_CALI_SELECT_RE
    fontData[Lan][PAGE_CALI_SELECT_RE].insert("labelText",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_RE].insert("labelText",QStringList{
                                                  "예시",
                                                  "공복 01",
                                                  "공복 02",
                                                  "식후 01",
                                                  "식후 02",
                                                  "식후 03",
                                              });

    fontData[Lan][PAGE_CALI_SELECT_RE].insert("labelTextValue",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));

    //PAGE_HELP_INDEX
    fontData[Lan][PAGE_HELP_INDEX].insert("labelText",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_HELP_INDEX].insert("labelText",QStringList{
                                              "사용 대상", // 0
                                              "제품 안내", // 1
                                              "사용 목적", // 2
                                              "측정 전 주의사항", // 3
                                              "사용 전 전문의\n상담 대상", // 4
                                              "제품 주요\n기능 안내", // 5
                                              "블루투스\n지원 범위", // 6
                                          });

    //PAGE_HELP
    fontData[Lan][PAGE_HELP].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_HELP].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_HELP].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_HELP].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    // 카테고리 0: 제품설명 및 사용목적
    textData[Lan][PAGE_HELP].insert("labelTextHelp0",QStringList{
                                        "사용 대상은 누구인가요?", // 0-0
                                        "제품의 주요 기능은 무엇인가요?", // 0-1
                                        "제품의 사용목적과 주의할 점은 무엇인가요?", // 0-2
                                    });
    // 카테고리 1: 측정 주의사항
    textData[Lan][PAGE_HELP].insert("labelTextHelp1",QStringList{
                                        "정확한 측정을 위해 측정 시 지켜야 할 사항은 무엇인가요?", // 1-0
                                    });
    // 카테고리 2: 측정제한 및 상담대상
    textData[Lan][PAGE_HELP].insert("labelTextHelp2",QStringList{
                                        "측정값이 부정확할 수 있어 전문 의료인 상담이 필요한 경우는 언제인가요?", // 2-0
                                    });
    // 카테고리 3: 알림기능
    textData[Lan][PAGE_HELP].insert("labelTextHelp3",QStringList{
                                        "제품에 알림 기능이 있나요?", // 3-0
                                    });

    //PAGE_HELP_RESPONSE
    fontData[Lan][PAGE_HELP_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_HELP_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_HELP_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    // Help 0: 사용 대상
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp0",QStringList{
                                                 "사용 대상은 만 19세 이상의\n당뇨병 전단계인 성인 남녀입니다.",
                                             });
    // Help 1: 제품 안내
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp1",QStringList{
                                                 "해피존 기기에서 혈당 수치를 측정할 수 있고 앱(APP)과 연동하여 혈당 수치 자료를 날짜별,"
                                                 "@기간별로 확인하여 혈당 수치를 관리하고 모니터링 할 수 있는 제품입니다.",
                                             });
    // Help 2: 사용 목적서
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp2",QStringList{
                                                 "만 19세 이상 약물치료를 하지 않는 당뇨병 전단계 환자의 혈당 관리(모니터링)를 위해 사용되는 의료기기이며,"
                                                 "@당뇨병 진단 및 치료, 인슐린 투여 등 의료적 결정의 목적으로는 사용할 수 없습니다.",
                                             });
    // Help 3: 측정 전 주의사항
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp3",QStringList{
                                                 "측정 전 손을 깨끗이 씻고 물기를 제거해주세요.\n측정 중에는 움직임과 강한 손가락 압박을 피해주세요."
                                                 "@* 기타 측정에 영향을 줄 수 있는 사용설명서 내용을 반드시 참고해주세요.",
                                             });
    // Help 4: 사용 전 전문의 상담대상
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp4",QStringList{
                                                 "만 19세 미만인 경우\n",
                                                 "광 조사 부위에 피부질환, 상처,\n 다한증, 파킨슨병 등 손 떨림이 있는 경우,"
                                                 "@중증 저혈당, 당뇨병 케톤산증, 간질, 실신 등\n부신 질환 병력이 있는 경우,"
                                                 "@혈액투석 또는\n복막투석 중인 경우,\n임산부 및 수유부인 경우",
                                             });
    // Help 5: 제품 주요기능 안내
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp5",QStringList{
                                                 "* 고혈당/저혈당 상태 알림\n"
                                                 "* 혈당보정 유효기간 알림\n"
                                                 "* 혈당 재보정 알림",
                                                 "혈당보정일로부터 90일 경과 시 혈당보정 유효기간 알림이 발생합니다.",
                                                 "만료 15일전부터 혈당 재보정 알림이 발생합니다.",
                                             });
    // Help 6: 블루투스 지원 범위
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp6",QStringList{
                                                 "해피존 APP 전용 블루투스 기능이며, 다른 기기와는 호환되지 않습니다.",
                                             });

    //PAGE_FAQ_INDEX
    fontData[Lan][PAGE_FAQ_INDEX].insert("labelText",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_FAQ_INDEX].insert("labelText",QStringList{
                                             "혈당보정", // 0
                                             "혈당 측정", // 1
                                             "제품 관리", // 2
                                             "휴대/이동", // 3
                                             "혈당기록", // 4
                                             //"정품인증/비밀번호 찾기", // 5
                                             "사용대상/인원", // 5
                                             "A/S", // 6
                                             "비밀번호", // 7
                                         });

    //PAGE_FAQ
    fontData[Lan][PAGE_FAQ].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_FAQ].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_FAQ].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_FAQ].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    // 카테고리 0: 혈당보정
    textData[Lan][PAGE_FAQ].insert("labelTextFaq0",QStringList{
                                       "'혈당보정(Calibration)'은 무엇인가요?", // 0-0
                                       "혈당보정은 꼭 해야 하나요?", // 0-1
                                       "혈당보정은 언제 하나요?", // 0-2
                                       "혈당보정 주기는 어떻게 되나요?", // 0-3
                                       "혈당보정 초기화 시 이전 측정 기록도 삭제되나요?", // 0-4
                                   });
    // 카테고리 1: 혈당측정
    textData[Lan][PAGE_FAQ].insert("labelTextFaq1",QStringList{
                                       "올바른 측정 자세는 무엇인가요?", // 1-0
                                       "손가락 위치는 어떻게 하나요?", // 1-1
                                       "매번 같은 손가락으로만 측정해야 하나요?", // 1-2
                                       "측정에 적합한 장소는 어디인가요?", // 1-3
                                       "젖은 손으로 측정해도 되나요?", // 1-4
                                       "하루에 몇 번 측정 하나요?", // 1-5
                                       "측정 소요 시간은 얼마나 걸리나요?", // 1-6
                                       "측정 중 취소할 수 있나요?", // 1-7
                                       "측정이 시작되지 않아요.", // 1-8
                                       "측정 실패가 자주 발생해요.", // 1-9
                                       "측정 시 손가락의 올바른 위치는?", // 1-10
                                       "혈당 측정 범위는 어떻게 되나요?", // 1-11
                                   });
    // 카테고리 2: 기기 관리
    textData[Lan][PAGE_FAQ].insert("labelTextFaq2",QStringList{
                                       "배터리 완충 시간을 알려주세요", // 2-0
                                       "배터리 사용 시간을 알려주세요", // 2-1
                                       "충전 중 사용해도 되나요?", // 2-2
                                       "방수가 되나요?", // 2-3
                                       "제품은 어떻게 관리해야 하나요?", // 2-4
                                       "보관 시 주의해야 할 장소가 있나요?", // 2-5
                                       "손가락 삽입구 커버는 꼭 닫아야 하나요?", // 2-6
                                   });
    // 카테고리 3: 휴대/이동
    textData[Lan][PAGE_FAQ].insert("labelTextFaq3",QStringList{
                                       "휴대용으로 사용 가능한가요?", // 3-0
                                       "항공기 기내 반입 가능한가요?", // 3-1
                                       "항공기 위탁 수하물로 보낼 수 있나요?", // 3-2
                                   });
    // 카테고리 4: 혈당기록
    textData[Lan][PAGE_FAQ].insert("labelTextFaq4",QStringList{
                                       "혈당 측정 결과는 어디서 보나요?", // 4-0
                                       "혈당 기록은 얼마 동안 저장되나요?", // 4-1
                                   });
    // 카테고리 5: 사용대상/인원
    textData[Lan][PAGE_FAQ].insert("labelTextFaq5",QStringList{
                                       "누구나 사용 가능한가요?", // 5-0
                                       "제품 1대로 몇 명이 사용하나요?", // 5-1
                                   });
    // 카테고리 6: A/S
    textData[Lan][PAGE_FAQ].insert("labelTextFaq6",QStringList{
                                       "제품의 A/S 기간은 어떻게 되나요?", // 6-0
                                       "원하시는 답변을 찾지 못하셨나요?", // 6-1
                                   });

    // 카테고리 7: 비밀번호
    textData[Lan][PAGE_FAQ].insert("labelTextFaq7",QStringList{
                                      "비밀번호는 어떻게 변경하나요?", // 7-0

                                   });

    //PAGE_FAQ_RESPONSE
    fontData[Lan][PAGE_FAQ_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_FAQ_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_FAQ_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    // FAQ 카테고리 0: 혈당보정
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-0",QStringList{
                                                "실제 혈당값과 제품 사이의 오차를 줄이기 위해 침습 장비와 연계하여 혈당 수치로 산출하고 조정하는 일련의 과정입니다.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-1",QStringList{
                                                "네. 사용자 마다 측정 부위의 구조와 외부 환경에 따른 빛의 투과율이 다르기 때문에 정확한 혈당 측정값을 산출하기 위한 개인별 혈당보정이 꼭 필요합니다.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-2",QStringList{
                                                "처음 사용하기 전에 혈당보정을 수행해야 합니다. 이후에는 혈당보정일로부터 90일 이내에 반드시 재보정해야 합니다."
                                                "@혈당보정 만료일 기준 15일 전부터 알림을 통해 재보정 시점을 안내드립니다.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-3",QStringList{
                                                "측정 부위 및 환경의 변화로 인한 오차 보정을 위해 혈당보정일로부터 90일 이내에 반드시 재보정을 해야 합니다."
                                                "@혈당보정일로부터 90일이 경과하면 혈당보정 유효기간만료 알림이 발생하며 재보정을 완료하기 전까지 혈당 측정이 제한됩니다.@"
                                                "혈당보정 초기화 후 재보정을 수행하면 혈당 측정이 다시 가능합니다.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-4",QStringList{
                                                "아니오. 혈당보정을 초기화 해도 기록되었던 혈당 기록은 제품에서 최대 90일까지 저장됩니다."
                                                "\n앱에서는 최대 12개월 까지 저장됩니다.",
                                            });
    // FAQ 카테고리 1: 혈당측정
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-0",QStringList{
                                                "앉은 자세에서 테이블에 팔꿈치를 올리고 수평을 맞추세요."
                                                "\n손가락 힘을 빼고 삽입구 끝까지 넣어 제품 내부 바닥에 밀착하세요.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-1",QStringList{
                                                "손가락 지문이 바닥면과 닿게 하면서 밀어넣으세요.\n손 끝이 딱 걸리면 힘을 빼고 자세를 고정하세요.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-2",QStringList{
                                                "정확한 측정을 위해 같은 손가락으로 측정하는 것을 권장합니다.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-3",QStringList{
                                                "실내온도 20~30°C의 직사광선과 바람, 습기, 진동 등 제품에 영향을 줄 수 있는 요소가 없는 곳에서 측정하세요.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-4",QStringList{
                                                "아니오. 젖은 손으로 측정할 경우 제품 고장의 원인이 될 수 있습니다.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-5",QStringList{
                                                "혈당은 식사/활동에 따라 변동되므로 기상 후 1회, 식사 전후 각 1회, 취침 전 1회 측정을 권장합니다.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-6",QStringList{
                                                "측정 시작 후 1분 이내에 측정 결과가 나옵니다.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-7",QStringList{
                                                "측정 중 '취소' 버튼을 누르면 중단됩니다.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-8",QStringList{
                                                "혈당보정 유효기간(90일) 만료 시 측정이 불가하니, 혈당보정을 진행하세요.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-9",QStringList{
                                                "측정 환경을 확인 후 다시 시도해 주세요.\n"
                                                "측정 환경은 다음과 같습니다."
                                                "@측정 중 기침, 재채기, 대화, 움직임 금지\n"
                                                "손가락의 힘을 빼고 바닥에 수평으로 밀착"
                                                "@손가락 표면 온도 26°C 이상 유지\n"
                                                "손가락의 물기 및 이물질 제거"
                                                "@* 사용설명서\n[ 에러 메시지 및 해결 방법 ]을\n참고하세요.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-10",QStringList{
                                                "손가락 지문이 바닥면과 닿게 하면서 밀어넣으세요.\n손 끝이 딱 걸리면 힘을 빼고 자세를 고정하세요.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-11",QStringList{
                                                "70~350mg/dL\n\n"
                                                "본 제품의 혈당 측정 범위는 최소 70 이상에서 최대 350 이하까지 측정이 가능합니다.",
                                            });
    // FAQ 카테고리 2: 기기 관리
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-0",QStringList{
                                                "본 제품의 완충까지 총 소요되는 시간은 약 3시간 45분 입니다.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-1",QStringList{
                                                "완충 시 하루 8회 측정 기준 최대 29일 사용 가능합니다.\n배터리 상태에 따라 상이할 수 있습니다.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-2",QStringList{
                                                "반드시 충전기를 분리한 상태에서 사용하세요.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-3",QStringList{
                                                "아니오. 본 제품에는 방수 기능이 없으므로 젖은 손으로 조작하지 마세요. 제품에 액체가 닿았을 경우 즉시 닦아내고, 정상 작동 여부를 확인하세요.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-4",QStringList{
                                                "부드러운 천으로 닦은 후 건조시켜 사용하세요. 세정제 또는 알코올, 화학물질의 사용을 금합니다.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-5",QStringList{
                                                "습기가 많은 환경(욕실, 주방 등)과 60°C 이상의 고온(밀폐된 차량, 직사광선 노출 등) 환경은 피해주세요.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-6",QStringList{
                                                "네, 사용하지 않을 때는 반드시 닫아 케이스에 보관하세요."
                                                "@먼지나, 금속 또는 뾰족한 물체가 내부에 들어가 발생하는 제품 손상이나 쇼트(Short) 사고를 방지할 수 있습니다.",
                                            });
    // FAQ 카테고리 3: 휴대/이동
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq3-0",QStringList{
                                                "네, 측정에 적합한 실내 환경에서는 충전하여 휴대할 수 있습니다. 다만 외부 충격으로 인한 오작동, 고장이 생길 수 있으니"
                                                "@제품에 충격이 없도록 휴대용 케이스에 넣어 휴대하시기 바랍니다.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq3-1",QStringList{
                                                "본 제품의 리튬 이온 폴리머 배터리(약 4.4Wh)는 항공 안전 기준(100Wh 이하)을 충족하여 기내 반입이 가능합니다."
                                                "@[ 배터리 스펙 ]\n"
                                                "전압: 3.7V\n"
                                                "용량: 1200mAh\n"
                                                "총량: 4.44Wh",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq3-2",QStringList{
                                                "본 제품은 리튬 이온 폴리머 배터리(약 4.4Wh)입니다.\n항공사 및 국가별 규정이 상이할 수 있으므로, 탑승 전 이용 항공사에 확인하시기 바랍니다."
                                                "@[ 배터리 스펙 ]\n"
                                                "전압: 3.7V\n"
                                                "용량: 1200maAh\n"
                                                "총량: 4.44Wh"
                                            });
    // FAQ 카테고리 4: 혈당기록
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq4-0",QStringList{
                                                "제품 내 '설정 메뉴' -'혈당기록' 아이콘을 누르거나, 블루투스로 스마트폰과 연결한 후 앱(App)에서 확인해주세요."
                                                "@당일 측정한 기록은 홈 화면에 자동으로 보입니다.\n과거 혈당 기록은 설정의 혈당기록 아이콘을 눌러 확인하세요.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq4-1",QStringList{
                                                "본 제품은 측정된 혈당 기록을 최대 90일까지 저장하고 있습니다.\n"
                                                "90일이 경과한 기록은 자동으로 삭제됩니다.",
                                            });
    // FAQ 카테고리 5: 사용대상/인원
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq5-0",QStringList{
                                                "만 19세 이상 약물치료를 하지 않는 당뇨병 전단계 환자를 대상으로 하는 의료기기이며, 당뇨병 진단 및 치료, 인슐린 투여 등 의료적 결정은 전문 의료인과 상의하세요.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq5-1",QStringList{
                                                "본 제품은 1대로 최대 2명까지 사용할 수 있습니다.",
                                            });
    // FAQ 카테고리 6: A/S
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq6-0",QStringList{
                                                "본 제품은 구매일로부터 최대 2년 까지 보증됩니다.\n단, 개인 사유에 의한 파손 및 고장은 보장되지 않습니다.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq6-1",QStringList{
                                                "고객상담실로 문의해 주시기 바랍니다."
                                            });
    // FAQ 카테고리 7: 비밀번호
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq7-0",QStringList{
                                               "상단 바 '메뉴' - '유저정보' - '비밀번호 변경'을 통해 안내에 따라 비밀번호를 변경해 주세요.", // 7-0
                                            });

    //PAGE_ERROR_HELP_INDEX
    fontData[Lan][PAGE_ERROR_HELP_INDEX].insert("labelText",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_ERROR_HELP_INDEX].insert("labelText",QStringList{
                                                    "혈당 측정", // 0
                                                    "제품 관리", // 1
                                                    "블루투스", // 2
                                                    "혈당 기록", // 3
                                                    //"미분류", // 4
                                                });

    //PAGE_ERROR_HELP
    fontData[Lan][PAGE_ERROR_HELP].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    // 카테고리 0: 혈당측정
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp0",QStringList{
                                              "측정이 시작되지 않아요", // 0-0
                                              "측정 실패가 자주 발생해요", // 0-1
                                              "'손가락을 인식하지 못했습니다' 라는 메시지가 표시돼요", // 0-2
                                              "'손가락 표면 온도가 낮아 측정할 수 없습니다' 라는 메시지가 표시돼요", // 0-3
                                              "'측정 데이터에 오류가 있습니다' 라는 메시지가 표시돼요", // 0-4
                                              "다음 단계로 넘어가지 않아요", // 0-5
                                              "'측정 결과를 분석할 수 없습니다' 라는 메시지가 표시돼요", // 0-6
                                              "혈당 수치가 정상이라고 생각되는데 경고가 표시돼요", // 0-7
                                          });
    // 카테고리 1: 기기 관리
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp1",QStringList{
                                              "버튼을 눌러도 작동이 되지 않아요", // 1-0
                                              "전원 부팅 후 초기 화면으로 진입하지 않아요", // 1-1
                                              "'업그레이드 파일이 보이지 않습니다' 라는 메시지가 표시돼요", // 1-2
                                              "'업그레이드 파일에 문제가 있습니다' 라는 메시지가 표시돼요", // 1-3
                                              "'업그레이드 파일이 아닙니다' 라는 메시지가 표시돼요", // 1-4
                                              "업그레이드 중 전원이 꺼졌어요", // 1-5
                                              "화면이 멈추거나 너무 느려요", // 1-6
                                              "무슨 오류인지 모르겠어요", // 1-7
                                              "화면이 터치 되지 않아요", // 1-8
                                              "충전이 되지 않아요", // 1-9
                                          });
    // 카테고리 2: 블루투스
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp2",QStringList{
                                              "앱 연동이 안되요", // 2-0
                                              "제품의 측정 수치와 앱의 측정 수치가 달라요", // 2-1
                                          });
    // 카테고리 3: 혈당기록
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp3",QStringList{
                                              "혈당보정을 초기화하여 사용하면 이전 혈당측정 기록은 다 지워지나요?", // 3-0
                                              "삭제한 혈당 기록은 복구할 수 있나요?", // 3-1
                                          });
    //// 카테고리 4: 미분류 (주석처리)
    //textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp4",QStringList{
    //                                          "제품인증은 어떻게 하나요?", // 4-0
    //                                          "비밀번호 (분실/오류/재설정) 문의", // 4-1
    //                                      });

    //PAGE_ERROR_RESPONSE
    fontData[Lan][PAGE_ERROR_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_ERROR_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_ERROR_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    // ErrorHelp 카테고리 0: 혈당측정
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-0",QStringList{
                                                  "혈당보정 유효기간(90일) 만료 시 측정이 불가하니, 혈당보정을 진행하세요.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-1",QStringList{
                                                  "측정 환경을 확인 후 다시 시도해 주세요.\n"
                                                  "측정 환경은 다음과 같습니다."
                                                  "@측정 중 기침, 재채기, 대화, 움직임 금지\n"
                                                  "손가락의 힘을 빼고 바닥에 수평으로 밀착"
                                                  "@손가락 표면 온도 26°C 이상 유지\n"
                                                  "손가락의 물기 및 이물질 제거"
                                                  "@* 사용설명서\n[ 에러 메시지 및 해결 방법 ]을\n참고하세요.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-2",QStringList{
                                                  "손가락이 올바르게 삽입되었는지 확인 후 다시 측정해 주세요."
                                                  "@손가락 지문이 바닥면과 닿게 하면서 밀어넣으세요.\n손 끝이 딱 걸리면 힘을 빼고 자세를 고정하세요.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-3",QStringList{
                                                  "손가락을 충분히 따뜻하게 한 후 다시 측정해 주세요.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-4",QStringList{
                                                  "대화, 손떨림, 재채기를 피하고 일정 시간 안정을 취한 후 다시 측정해 주세요.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-5",QStringList{
                                                  "측정이 되지 않았을 수 있습니다. 다시 측정해주세요. 그래도 문제가 지속된다면 전원버튼을 껐다 켜주세요.",
                                                  "외부환경(낮은 온도나 주변에 고온의 물체)에 노출되었다면 오작동 될 수 있습니다. 실내온도 20~30°C에서 다시 사용해보세요.",
                                                  "온도, 습도, 물기에 노출된게 아니라면 고객상담실로 고장접수 해주세요.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-6",QStringList{
                                                  "손가락 측정 위치와 측정 환경을 확인한 후 다시 측정해 주세요.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-7",QStringList{
                                                  "혈당범위 아이콘을 눌러 혈당 상태 알림 범위를 조정해 주세요.",
                                              });
    // ErrorHelp 카테고리 1: 기기 관리
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-0",QStringList{
                                                  "전원을 껐다 다시켜보세요.\n",
                                                  "배터리가 충분한지 확인하세요.\n",
                                                  "충전기를 꽂은 상태로는 측정이 되지 않습니다.@",
                                                  "물이 닿거나 습도가 높은곳에 보관 했었다면 고장의 원인이 될 수 있습니다. 제품 상태를 확인하세요.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-1",QStringList{
                                                  "충전 케이블 및 어댑터 연결 상태를 확인한 후 충전해 주세요.\n충전이 완료된 후 전원을 다시 켰을 때 부팅이 완료되면 정상 사용이 가능합니다.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-2",QStringList{
                                                  "업그레이드 파일을 다시 확인해 주세요. 동일한 현상이 발생한다면 고객상담실로 문의해 주세요.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-3",QStringList{
                                                  "업그레이드 파일을 다시 다운로드 받아 새 파일로 다시 시도해 주세요. 동일한 현상이 발생한다면 고객상담실로 문의해 주세요.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-4",QStringList{
                                                  "올바른 파일이 맞는지 확인 후 다시 시도해 주세요. 동일한 현상이 발생한다면 고객상담실로 문의해 주세요.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-5",QStringList{
                                                  "충전 후 다시 업그레이드를 진행해 주세요. 동일한 현상이 발생한다면 고객상담실로 문의해 주세요.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-6",QStringList{
                                                  "핀을 사용하여 리셋 버튼을 눌러 주세요. 리셋 버튼을 누른 후 시스템이 재부팅 되면 정상 사용이 가능합니다.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-7",QStringList{
                                                  "재부팅 후 동일한 오류가 발생하는지 확인해 주세요. 동일한 현상이 발생한다면 고객상담실로 문의해 주세요.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-8",QStringList{
                                                  "재부팅 시도 후 정상작동을 확인하시고, 동일한 현상이 발생한다면 고객상담실로 문의해 주세요.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-9",QStringList{
                                                  "충전 케이블 및 어댑터 연결 상태를 확인해 주세요.\n",
                                                  "사용 중인 충전 어댑터의 출력 사양이 제품 권장 사양과 일치하는지 확인해 주세요.@",
                                                  "동일한 현상이 발생한다면 고객상담실로 문의해 주세요.",
                                              });
    // ErrorHelp 카테고리 2: 블루투스
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp2-0",QStringList{
                                                  "제품 화면 상단 바 '블루투스' 아이콘을 터치하여 활성화 시킵니다. 그리고 스마트폰을 제품과 1M 이내로 가까이 두고"
                                                  "@스마트폰에서 블루투스를 검색하여 해피존 제품을 찾아 연동해주세요.",
                                                  "@문제가 지속될 경우 본 제품의 전원을 껐다 켜서 다시 실행해주세요.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp2-1",QStringList{
                                                  "날짜와 측정항목을 확인해주세요.\n",
                                                  "문제가 지속되면 일시적인 오류일 수 있으니 제품과 앱을 껐다가 다시 켜서 재연동해 주세요.",
                                              });
    // ErrorHelp 카테고리 3: 혈당기록
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp3-0",QStringList{
                                                  "아니오. 혈당보정을 초기화 해도 기록되었던 혈당 기록은 제품에서 최대 90일까지 저장됩니다.\n앱에서는 최대 12개월까지 저장됩니다.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp3-1",QStringList{
                                                  "아니요. 복구가 불가능하므로 혈당 기록 삭제 시 주의하세요.",
                                              });
    //// ErrorHelp 카테고리 4: 미분류 (주석처리)
    //textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp4-0",QStringList{
    //                                              "제품 시리얼 번호를 앱에 등록해주세요   ---->  확인",
    //                                          });
    //textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp4-1",QStringList{
    //                                              "개발팀 확인 중",
    //                                          });

    //====================================================================================================================================
    //EN
    Lan = EN;
    nTextSize = 30;
    currentFont = instance.fontSuit;

    //PAGE_TRANS
    fontData[Lan][PAGE_TRANS].insert("fontSuit",QFont(instance.fontSuit,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_TRANS].insert("fontJP",QFont(instance.fontJP,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_TRANS].insert("fontSC",QFont(instance.fontSC,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_TRANS].insert("fontTC",QFont(instance.fontTC,instance.pixelToPoint(36)));

    textData[Lan][PAGE_TRANS].insert("lang",QStringList{
                                         "한국어",
                                         "ENGLISH",
                                         "日本語",
                                         "繁體中文",
                                         "简体中文",
                                         "ESPAÑOL"
                                     });

    //CUSTOM_BUTTON
    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonOK",QFont(currentFont,instance.pixelToPoint(35),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonOK",QStringList{"OK"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel",QFont(currentFont,instance.pixelToPoint(35),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel",QStringList{"Cancel"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonHome",QFont(currentFont,instance.pixelToPoint(35),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonHome",QStringList{"Home"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart",QFont(currentFont,instance.pixelToPoint(35),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart",QStringList{"Start"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasure",QFont(currentFont,instance.pixelToPoint(35),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasure",QStringList{"Measure"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonInput",QFont(currentFont,instance.pixelToPoint(35),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonInput",QStringList{"Input"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe",QStringList{"Remeasure"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonSave",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonSave",QStringList{"Save"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonUpgrade",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonUpgrade",QStringList{"Software Upgrade"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QStringList{"Yes"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QStringList{"No"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QStringList{
                                            "한국어",
                                            "ENGLISH",
                                            "日本語",
                                            "繁體中文",
                                            "简体中文",
                                            "ESPAÑOL"
                                        });

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonBack",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonBack",QStringList{"Back"});

    //CUSTOM_COMPONENT
    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextValue",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextResult",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextResult", QStringList{
                                               "Measurement successful",                                 // 0
                                               "Finger not detected.\nTry again",                         // 1
                                               "Device error.\nContact support",                          // 2
                                               "Device error.\nContact support",                          // 3
                                               "Analysis failed.\nTry again",                             // 4
                                               "Invalid data.\nTry again",                                // 5
                                               "Cannot measure while charging.\nUnplug and retry",        // 6
                                               "Finger too cold,\nCannot measure",                        // 7
                                               "Measurement failed.\nContact support",                    // 8
                                           });

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QFont(currentFont, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QStringList{
                                               "Upgrade completed successfully", // 0
                                               "Upgrade failed.\nPlease contact customer support", // 1
                                               "Upgrade file not found.\nPlease check the file again", // 2
                                               "There is a problem with the upgrade file.\nPlease try again with a new file", // 3
                                               "This is not a valid upgrade file.\nPlease check if the file is correct", // 4
                                               "Upgrade failed.\nPlease contact customer support" // 5
                                           });

    //CUSTOM_COMPONENT_DATE
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelText",QFont(currentFont,instance.pixelToPoint(50)));
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelTextSelect",QFont(currentFont,instance.pixelToPoint(50),QFont::Bold));
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelTextSub",QFont(currentFont,instance.pixelToPoint(40)));

    //PAGE_PASSWORD
    fontData[Lan][PAGE_PASSWORD].insert("labelButtonNum",QFont(currentFont,instance.pixelToPoint(44),QFont::Bold));

    fontData[Lan][PAGE_PASSWORD].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(40),QFont::Bold));
    textData[Lan][PAGE_PASSWORD].insert("labelTitle",QStringList{"Please log in","Edit Password","Delete User","Password Confirmation","Password Re-confirmation","PASSWORD_MAX"});

    fontData[Lan][PAGE_PASSWORD].insert("labelTitleSub",QFont(currentFont,instance.pixelToPoint(30)));
    textData[Lan][PAGE_PASSWORD].insert("labelTitleSub", QStringList{
                                            "Please enter your 4-digit password",
                                            "Please enter the 4 digits to modify",
                                            "Please enter your 4-digit password again",
                                            "Please confirm by entering 4 digits",
                                            "Please re-enter the 4 digits to verify",
                                            "Please enter your current password",
                                            "PASSWORD_MAX"
                                        });

    fontData[Lan][PAGE_PASSWORD].insert("labelButtonOKText",QFont(currentFont,instance.pixelToPoint(29)));
    textData[Lan][PAGE_PASSWORD].insert("labelButtonOKText",QStringList{"OK"});

    fontData[Lan][PAGE_PASSWORD].insert("labelButtonCancelText",QFont(currentFont,instance.pixelToPoint(29)));
    textData[Lan][PAGE_PASSWORD].insert("labelButtonCancelText",QStringList{"X"});

    //PAGE_SELECT_USER
    fontData[Lan][PAGE_SELECT_USER].insert("labelTitle", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_SELECT_USER].insert("labelTitle", QStringList{"Please select a user"});

    fontData[Lan][PAGE_SELECT_USER].insert("labelUserText", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_SELECT_USER].insert("labelUserText", QStringList{"User 1", "User 2"});

    //PAGE_PASSWORD_ALLCHAT
    fontData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelButtonNum", QFont(currentFont, instance.pixelToPoint(44)));

    fontData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitle", QFont(currentFont, instance.pixelToPoint(40), QFont::Bold));
    textData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitle", QStringList{
                                                    "Please log in",
                                                    "Change Password",
                                                    "Delete Record",
                                                    "Password Confirmation",
                                                    "Password Re-confirmation",
                                                    "Password Reset",
                                                    "PASSWORD_MAX"
                                                });

    fontData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitleSub", QFont(currentFont, instance.pixelToPoint(30)));
    textData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitleSub", QStringList{
                                                    "Please enter your password",
                                                    "Please enter the new password",
                                                    "Please enter your password",
                                                    "Please enter your password for confirmation",
                                                    "Please re-enter your password",
                                                    "Please enter your current password",
                                                    "PASSWORD_MAX"
                                                });

    //PAGE_PASSWORD_CONFIRM
    fontData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(40),QFont::Bold));
    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTitle",QStringList{
                                                    "Login", //PASSWORD_STR_LOGIN_SUCCESS,
                                                    "Login", //PASSWORD_STR_LOGIN_FAIL,
                                                    "Login", //PASSWORD_STR_LOGIN_CHANGE,
                                                    "Id Check", //PASSWORD_STR_CONFIRM,
                                                    "Id Check", //PASSWORD_STR_CONFIRM_FAIL,
                                                    "PW Check", //PASSWORD_STR_REPEAT,
                                                    "PW Check", //PASSWORD_STR_REPEAT_FAIL,
                                                    "PW Change", //PASSWORD_STR_EDIT,
                                                    "PW Change", //PASSWORD_STR_EDIT_CONFIRM,
                                                    "PW Change", //PASSWORD_STR_EDIT_CHANGE,
                                                    "PW Change", //PASSWORD_STR_EDIT_SUCCESS,
                                                    "Delete Record", //PASSWORD_STR_DELETE,
                                                    "Delete Record", //PASSWORD_STR_DELETE_CONFIRM,
                                                    "Delete Record", //PASSWORD_STR_DELETE_SUCCESS,
                                                    "Logout", //PASSWORD_STR_LOGOUT,
                                                    "Reset Password", //PASSWORD_STR_INIT,
                                                    "Reset Password", //PASSWORD_STR_INIT_CONFIRM,
                                                    "Reset Password", //PASSWORD_STR_INIT
                                                    "PASSWORD_STR_MAX" //PASSWORD_STR_MAX
                                                });
    fontData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelText",QStringList{
                                                    "Login successful",
                                                    "Login failed",
                                                    "Please change your password",
                                                    "Please enter your password\nfor verification",
                                                    "Passwords do not match",
                                                    "Please enter your password again\nfor accuracy",
                                                    "The entered password\ndoes not match\nthe previous password",
                                                    "Would you like to change\nyour password?",
                                                    "Please enter your password\nfor verification",
                                                    "Please enter a new password\n\nMin. 8 characters, including number,\nletter, and symbol like .,?!",
                                                    "Password changed\nPlease log in again",
                                                    "Do you want to delete\nthe blood glucose record?", // PASSWORD_STR_DELETE
                                                    "Deleted data cannot be recovered", // PASSWORD_STR_DELETE_CONFIRM
                                                    "Blood glucose record deleted", // PASSWORD_STR_DELETE_SUCCESS
                                                    "You will be logged out",
                                                    "Do you want to reset\nyour password?",
                                                    "Resetting will restore the password\nto its default value",
                                                    "Password has been reset",
                                                    "PASSWORD_STR_MAX"
                                                });

    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTextError", QStringList{
                                                    "Password has been set",                                      // PASSWORD_ECODE_NORMAL
                                                    "Password must be\n8 to 12 characters long",                   // PASSWORD_ECODE_RANGE_LEN
                                                    "Password must include\nat least one number",                  // PASSWORD_ECODE_NO_NUMBER
                                                    "Password must include\nat least one letter (A-Z)",            // PASSWORD_ECODE_NO_ALPHABET
                                                    "Password must include\nat least one symbol (e.g. .,?!)",      // PASSWORD_ECODE_NO_SPECTAL
                                                    "Passwords do not match",                                     // PASSWORD_ECODE_NO_MATCH
                                                    "password is not allowed",                                    // PASSWORD_ECODE_ERROR
                                                    "An unknown error has occurred",                              // PASSWORD_ECODE_MAX
                                                });


    //PAGE_HOME
    fontData[Lan][PAGE_HOME].insert("labelTextStatus",QFont(currentFont,instance.pixelToPoint(26),QFont::Bold));
    textData[Lan][PAGE_HOME].insert("labelTextStatus",QStringList{
                                        "Wake\nUp","Before\nBreakfast","After\nBreakfast","Before\nLunch","After\nLunch","Before\nDinner","After\nDinner","Bed\nTime"});

    fontData[Lan][PAGE_HOME].insert("labelButtonText",QFont(currentFont,instance.pixelToPoint(62),QFont::ExtraBold));

    //PAGE_SELECT
    fontData[Lan][PAGE_SELECT].insert("labelTextStatus", QFont(currentFont, instance.pixelToPoint(42), QFont::ExtraBold));
    textData[Lan][PAGE_SELECT].insert("labelTextStatus",QStringList{
                                          "Wake Up","Before Breakfast","After Breakfast","Before Lunch","After Lunch","Before Dinner","After Dinner","Bed Time"});

    fontData[Lan][PAGE_SELECT].insert("labelTextStatusSub", QFont(currentFont, instance.pixelToPoint(24)));
    textData[Lan][PAGE_SELECT].insert("labelTextStatusSub", QStringList{"Please start the measurement"});

    fontData[Lan][PAGE_SELECT].insert("labelTextStatusValue",QFont(currentFont,instance.pixelToPoint(40),QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextGlucoseValue",QFont(currentFont,instance.pixelToPoint(130),QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextMgdl",QFont(currentFont,instance.pixelToPoint(34),QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextResult",QFont(currentFont,instance.pixelToPoint(32)));
    textData[Lan][PAGE_SELECT].insert("labelTextResult", QStringList{
                                          "Normal",
                                          "Caution",
                                          "Caution",
                                          "Warning",
                                          "Warning"
                                      });
    textData[Lan][PAGE_SELECT].insert("labelTextResultSub",QStringList{
                                          "Blood Sugar",
                                          "Low Blood Sugar",
                                          "High Blood Sugar",
                                          "Low Blood Sugar",
                                          "High Blood Sugar"
                                      });

    fontData[Lan][PAGE_SELECT].insert("labelTextTime",QFont(currentFont,instance.pixelToPoint(21),QFont::Bold));
    textData[Lan][PAGE_SELECT].insert("labelTextTime",QStringList{"Time"});

    fontData[Lan][PAGE_SELECT].insert("labelTextIcon",QFont(currentFont,instance.pixelToPoint(23),QFont::Bold));
    textData[Lan][PAGE_SELECT].insert("labelTextIcon",QStringList{"Normal","Low","High","Low","High"});

    //PAGE_MENU
    fontData[Lan][PAGE_MENU].insert("labelButtonText",QFont(currentFont,instance.pixelToPoint(25),QFont::Bold));
    textData[Lan][PAGE_MENU].insert("labelButtonText", QStringList{
                                        "Calib\nration",
                                        "Range",
                                        "List",
                                        "Sound",
                                        "Sleep",
                                        "Switch",
                                        "Date",
                                        "Color\nMode",
                                        "Language",
                                        "Upgrade",
                                        "Device\nInfo",
                                        "Reset",
                                        "User",
                                        "Help",
                                        "FAQ",
                                        "Error\nHelp",
                                    });

    //PAGE_CALI_CHECK
    fontData[Lan][PAGE_CALI_CHECK].insert("labelTextCheck",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_CHECK].insert("labelTextCheck",QStringList{
                                              "Calibration phase\nPlease insert your finger",
                                              "Calibration complete\nDo you want to proceed again?"
                                          });
    //Page_CALI_GAIN_CONFIRM
    fontData[Lan][PAGE_CALI_GAIN_CONFIRM].insert("labelTextGainConfirm",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_GAIN_CONFIRM].insert("labelTextGainConfirm",QStringList{
                                                     "LED sensitivity adjustment step\nPlease do not move your finger",
                                                     "LED sensitivity adjustment\nhas been completed"
                                                 });

    //Page_GRAPH
    fontData[Lan][PAGE_GRAPH].insert("labelProgressText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_GRAPH].insert("labelProgressText",QStringList{"Completed"});
    fontData[Lan][PAGE_GRAPH].insert("labelProgressValue",QFont(currentFont,instance.pixelToPoint(60),QFont::Bold));
    fontData[Lan][PAGE_GRAPH].insert("labelProgressPercent",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_GRAPH].insert("labelAdcText",QFont(currentFont,instance.pixelToPoint(20)));
    textData[Lan][PAGE_GRAPH].insert("labelAdcText",QStringList{"A:"});
    fontData[Lan][PAGE_GRAPH].insert("labelLoading",QFont(currentFont,instance.pixelToPoint(48),QFont::Bold));
    textData[Lan][PAGE_GRAPH].insert("labelLoading",QStringList{"Being analyzed"});

    //Page_CALI_GAIN_RESULT
    fontData[Lan][PAGE_CALI_GAIN_RESULT].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_GAIN_RESULT].insert("labelText",QStringList{
                                                    "LED sensitivity adjustment is complete\nProceed to the next measurement step",
                                                    "LED sensitivity adjustment failed.\nPlease measure again"
                                                });
    //PAGE_CALI_SELECT
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectText",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT].insert("labelSelectText",QStringList{
                                               "Empty\nstomach",
                                               "After\nmeal"
                                           });

    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextAdc",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextValue",QFont(currentFont,instance.pixelToPoint(36)));


    //PAGE_CALI_SELECT_INFO
    fontData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText",QStringList{
                                                    "Has at least 8 hours passed since fasting?\n Measure twice at 30-minute intervals (01)",//"Has it been more than 8 hours\n since your last meal?",
                                                    "Has at least 8 hours passed since fasting?\n Measure twice at 30-minute intervals (02)",
                                                    "Has it been more than 1 hour\n since your last meal?",
                                                    "Has it been more than\n1 hour and 30 minutes\nsince your last meal?",
                                                    "Has it been more than 2 hours\n  since your last meal?"
                                                });

    //PAGE_CALI_SEELCT_CONFIRM
    fontData[Lan][PAGE_CALI_SELECT_CONFIRM].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_CONFIRM].insert("labelText",QStringList{"Please proceed with the\nblood glucose calibration in order"});

    //PAGE_CALI_CONFIRM
    fontData[Lan][PAGE_CALI_CONFIRM].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_CONFIRM].insert("labelText",QStringList{"Select input or measure"});

    //PAGE_CALI_RESULT
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextAdc",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextTemp",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextHeart",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));

    //PAGE_CALI_RESULT_MULTI
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextAdc",QFont(currentFont,instance.pixelToPoint(34),QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextTemp",QFont(currentFont,instance.pixelToPoint(34)));
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextHeart",QFont(currentFont,instance.pixelToPoint(34)));

    //PAGE_CALI_RESULT_MULTI_CONFIRM
    fontData[Lan][PAGE_CALI_RESULT_MULTI_CONFIRM].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_RESULT_MULTI_CONFIRM].insert("labelText",QStringList{"Delete selected\nvalue and remeasure?"});

    //PAGE_RESULT
    fontData[Lan][PAGE_RESULT].insert("labelTextGlucoseValue",QFont(currentFont,instance.pixelToPoint(103),QFont::ExtraBold));

    fontData[Lan][PAGE_RESULT].insert("labelTextMgdl",QFont(currentFont,instance.pixelToPoint(27)));
    textData[Lan][PAGE_RESULT].insert("labelTextMgdl",QStringList{"mg/dL"});

    fontData[Lan][PAGE_RESULT].insert("labelTextTime",QFont(currentFont,instance.pixelToPoint(21),QFont::Bold));
    textData[Lan][PAGE_RESULT].insert("labelTextTime",QStringList{"Time"});

    fontData[Lan][PAGE_RESULT].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));

    textData[Lan][PAGE_RESULT].insert("indexResult",QStringList{
                                          "Normal",
                                          "Caution",
                                          "Caution",
                                          "Warning",
                                          "Warning"
                                      });
    textData[Lan][PAGE_RESULT].insert("indexResultSub",QStringList{
                                          "Blood Sugar",
                                          "Low Blood Sugar",
                                          "High Blood Sugar",
                                          "Low Blood Sugar",
                                          "High Blood Sugar"
                                      });
    fontData[Lan][PAGE_RESULT].insert("labelProgressBarTooltip",QFont(currentFont,instance.pixelToPoint(16),QFont::Bold));
    textData[Lan][PAGE_RESULT].insert("labelProgressBarTooltip",QStringList{
                                          "Normal",
                                          "Caution",
                                          "Warning",
                                          "Error"
                                      });
    //PAGE_INIT
    fontData[Lan][PAGE_INIT].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    textData[Lan][PAGE_INIT].insert("labelText",QStringList{
                                        "Factory reset",
                                        "Bluetooth reset",
                                        "Blood sugar calibration reset"
                                    });

    //PAGE_INIT_CONFIRM
    fontData[Lan][PAGE_INIT_CONFIRM].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_INIT_CONFIRM].insert("labelText",QStringList{
                                                "The entire system information\n will be reset.\nDo you want to proceed\nwith factory reset?",
                                                "After system initialization,\nthe system will restart",
                                                "Bluetooth user information\nwill be initialized.\nThe connection with the\nsmartphone is disconnected.\nWould you like to reset\nBluetooth?",
                                                "Bluetooth user information\nhas been reset",
                                                "Blood sugar correction\nwill be reset\nDo you want to reset\nblood sugar correction?",
                                                "Blood sugar correction\nhas been reset"
                                            });

    //PAGE_THRESHOLD
    fontData[Lan][PAGE_THRESHOLD].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    textData[Lan][PAGE_THRESHOLD].insert("labelText",QStringList{
                                             "Low Blood Sugar",
                                             "High Blood Sugar"
                                         });
    fontData[Lan][PAGE_THRESHOLD].insert("labelButton",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][PAGE_THRESHOLD].insert("labelButton",QStringList{"Set"});

    fontData[Lan][PAGE_THRESHOLD].insert("labelValue",QFont(currentFont,instance.pixelToPoint(48),QFont::Bold));

    fontData[Lan][PAGE_THRESHOLD].insert("labelValueRange",QFont(currentFont,instance.pixelToPoint(26)));
    textData[Lan][PAGE_THRESHOLD].insert("labelValueRange",QStringList{
                                             "under",
                                             "above"
                                         });

    //PAGE_SOUND
    fontData[Lan][PAGE_SOUND].insert("labelVolume",QFont(currentFont,instance.pixelToPoint(110),QFont::Bold));

    //PAGE_SLEEP
    fontData[Lan][PAGE_SLEEP].insert("labelText",QFont(currentFont,instance.pixelToPoint(42),QFont::Bold));
    textData[Lan][PAGE_SLEEP].insert("labelText",QStringList{
                                         "30sec",
                                         "1min",
                                         "3min",
                                         "5min",
                                         "10min",
                                         "None"
                                     });

    //PAGE_UPGRADE
    fontData[Lan][PAGE_UPGRADE].insert("labelText",QFont(currentFont,instance.pixelToPoint(42),QFont::Bold));
    textData[Lan][PAGE_UPGRADE].insert("labelText",QStringList{"Version"});

    fontData[Lan][PAGE_UPGRADE].insert("labelTextVersion",QFont(currentFont,instance.pixelToPoint(55)));

    //PAGE_UPGRADE_CONFIRM
    fontData[Lan][PAGE_UPGRADE_CONFIRM].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_UPGRADE_CONFIRM].insert("labelText",QStringList{
                                                   "1. Connect the device to PC\n"
                                                   "2. Copy bin file to the device\n"
                                                   "3. Restart the device after copying\n   is complete"
                                               });

    //PAGE_DEVICEINFO
    fontData[Lan][PAGE_DEVICEINFO].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_DEVICEINFO].insert("labelTitle",QStringList{
                                              "BLE",
                                              "H/W ver",
                                              "S/W ver",
                                              "Serial"
                                          });

    fontData[Lan][PAGE_DEVICEINFO].insert("labelText",QFont(currentFont,instance.pixelToPoint(30)));

    //PAGE_USERINFO
    fontData[Lan][PAGE_USERINFO].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    textData[Lan][PAGE_USERINFO].insert("labelText",QStringList{
                                            "Change password",
                                            "Reset password",
                                            "Delete Blood Sugar Record",
                                            "Log out"
                                        });

    //PAGE_BATPOPUP
    fontData[Lan][PAGE_BATPOPUP].insert("labelText",QFont(currentFont,instance.pixelToPoint(42),QFont::Bold));
    textData[Lan][PAGE_BATPOPUP].insert("labelText",QStringList{
                                            "Low Battery",
                                            "Please connect it to the charger"
                                        });
    fontData[Lan][PAGE_BATPOPUP].insert("labelTextSub",QFont(currentFont,instance.pixelToPoint(nTextSize)));
    textData[Lan][PAGE_BATPOPUP].insert("labelTextSub",QStringList{
                                            "Battery very low",
                                            "The system is shutting down"
                                        });

    //PAGE_REVERSE
    fontData[Lan][PAGE_REVERSE].insert("labelTextButton",QFont(currentFont,instance.pixelToPoint(36)));
    textData[Lan][PAGE_REVERSE].insert("labelTextButton",QStringList{
                                           "Left",
                                           "Right"
                                       });
    fontData[Lan][PAGE_REVERSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize)));
    textData[Lan][PAGE_REVERSE].insert("labelText",QStringList{
                                           "Reset will proceeded"
                                       });

    //PAGE_HISTORY
    fontData[Lan][PAGE_HISTORY].insert("labelButton",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][PAGE_HISTORY].insert("labelButton",QStringList{
                                           "+ 7days",
                                           "Today",
                                           "- 7days"
                                       });

    //PAGE_ELAPSED_NOTICE_POPUP
    fontData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("labelTitle",QStringList{
                                                        "Calibration Validity"
                                                    });

    fontData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));

    textData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("elapsedText",QStringList{
                                                        "Expires in 1 day",
                                                        "Expires in 2 days",
                                                        "Expires in 3 days",
                                                        "Expires in 4 days",
                                                        "Expires in 5 days",
                                                        "Expires in 6 days",
                                                        "Expires in 7 days",
                                                        "Expires in 8 days",
                                                        "Expires in 9 days",
                                                        "Expires in 10 days",
                                                        "Expires in 11 days",
                                                        "Expires in 12 days",
                                                        "Expires in 13 days",
                                                        "Expires in 14 days",
                                                        "Expires in 15 days"
                                                    });

    textData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("warningText",QStringList{
                                                        "Expired (Unavailable)"
                                                    });

    //PAGE_BLOOD_CHECK
    fontData[Lan][PAGE_BLOOD_CHECK].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_BLOOD_CHECK].insert("labelText",QStringList{
                                               "hospital-measured value?"
                                           });

    //PAGE_BLOOD_NOTICE_POPUP
    fontData[Lan][PAGE_BLOOD_NOTICE_POPUP].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_BLOOD_NOTICE_POPUP].insert("labelText",QStringList{
                                                      "Out of measurement range"
                                                  });

    //PAGE_USER_CHECK
    fontData[Lan][PAGE_USER_CHECK].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK].insert("labelText",QStringList{
                                              "Prediabetes",
                                              "Non-diabetic",
                                              "Diabetes"
                                          });
    fontData[Lan][PAGE_USER_CHECK].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK].insert("labelTitle",QStringList{
                                              "Select User Type"
                                          });

    //PAGE_BLOOD_CHECK_NOTICE //unused
    fontData[Lan][PAGE_BLOOD_CHECK_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_BLOOD_CHECK_NOTICE].insert("labelText",QStringList{
                                                      "No venous blood data available.\nPlease enter venous blood information."
                                                  });

    //PAGE_CALI_VALUE_NOTICE //unused
    fontData[Lan][PAGE_CALI_VALUE_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_VALUE_NOTICE].insert("labelText",QStringList{
                                                     "Value out of 70–350 range.\nPlease enter a valid value."
                                                 });

    //PAGE_USER_NOTICE
    fontData[Lan][PAGE_USER_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_NOTICE].insert("labelText",QStringList{
                                               "This device is intended\nfor prediabetic patients\nwho are not using medication."
                                           });

    //PAGE_USER_FINGER
    fontData[Lan][PAGE_USER_FINGER].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_FINGER].insert("labelTitle",QStringList{
                                               "Recommended finger circumference"
                                           });

    //PAGE_CALI_NOTICE
    fontData[Lan][PAGE_CALI_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_NOTICE].insert("labelText",QStringList{
                                               "Proceed with recalibration?"
                                           });

    //PAGE_USER_CHECK_NOTICE
    fontData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelText",QStringList{
                                                     "User Type: None",
                                                     "User Type: Non-diabetic",
                                                     "User Type: Prediabetes",
                                                     "User Type: Diabetes"
                                                 });

    fontData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelCaliDay",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelCaliDay",QStringList{
                                                     "Calibration Date: "
                                                 });

    //PAGE_USER_CAUTIONS
    fontData[Lan][PAGE_USER_CAUTIONS].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CAUTIONS].insert("labelTitle",QStringList{
                                                 "HappyZone Precautions"
                                             });

    fontData[Lan][PAGE_USER_CAUTIONS].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CAUTIONS].insert("labelText",QStringList{
                                                 "1. Maintain steady breathing",
                                                 "2. Refrain from speaking and\nremain still during measurement",
                                                 "3. Do not apply force or pressure\nto the finger",
                                                 "4. Ensure the finger is dry and\nfree of foreign substances",
                                                 "5. Keep finger surface temperature\nat or above 26°C",
                                                 "6. Place the finger firmly on the sensor\n and keep it level",
                                                 "7. Disconnect the charger before use",
                                                 "8. Check ambient temperature (15–35°C)",
                                             });

    //PAGE_CALI_SELECT_RE
    fontData[Lan][PAGE_CALI_SELECT_RE].insert("labelText",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_RE].insert("labelText",QStringList{
                                                  "Example",
                                                  "Fasting\n01",
                                                  "Fasting\n02",
                                                  "Post\nmeal 01",
                                                  "Post\nmeal 02",
                                                  "Post\nmeal 03",
                                              });

    fontData[Lan][PAGE_CALI_SELECT_RE].insert("labelTextValue",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));

    //PAGE_HELP_INDEX
    fontData[Lan][PAGE_HELP_INDEX].insert("labelText",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_HELP_INDEX].insert("labelText",QStringList{
                                              "Target Users", // 0
                                              "Product Info", // 1
                                              "Purpose of Use", // 2
                                              "Pre-Measurement\nPrecautions", // 3
                                              "Consult a Doctor\nBefore Use", // 4
                                              "Key Features", // 5
                                              "Bluetooth\nSupport", // 6
                                          });

    //PAGE_HELP
    fontData[Lan][PAGE_HELP].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_HELP].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(26),QFont::Bold));
    fontData[Lan][PAGE_HELP].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_HELP].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    // Category 0: Target Users
    textData[Lan][PAGE_HELP].insert("labelTextHelp0",QStringList{
                                        "Can anyone use it?", // 0-0
                                        "What is this product?", // 0-1
                                        "What are the advantages of this product?", // 0-2
                                    });
    // Category 1: Product Info
    textData[Lan][PAGE_HELP].insert("labelTextHelp1",QStringList{
                                        "What functions does it provide?", // 1-0
                                    });
    // Category 2: Purpose of Use
    textData[Lan][PAGE_HELP].insert("labelTextHelp2",QStringList{
                                        "What is this product used for?", // 2-0
                                    });
    // Category 3: Pre-Measurement Precautions
    textData[Lan][PAGE_HELP].insert("labelTextHelp3",QStringList{
                                        "Are there precautions before measurement?", // 3-0
                                    });

    //PAGE_HELP_RESPONSE
    fontData[Lan][PAGE_HELP_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_HELP_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_HELP_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    // Help 0: Target Users
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp0",QStringList{
                                                 "Can be used by pre-diabetic patients not on drug treatment"
                                                 "@This product is designed for adults aged 19-74",
                                             });
    // Help 1: Product Info
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp1",QStringList{
                                                 "You can measure blood glucose levels with the Happyzone device and link it with the APP"
                                                 "@to check blood glucose data by date and period to manage and monitor your levels.",
                                             });
    // Help 2: Purpose of Use
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp2",QStringList{
                                                 "This is a medical device used for blood glucose management (monitoring) of pre-diabetic patients aged 19 and older not on drug treatment,"
                                                 "@and cannot be used for medical decisions such as diabetes diagnosis, treatment, or insulin administration.",
                                             });
    // Help 3: Pre-Measurement Precautions
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp3",QStringList{
                                                 "Wash your hands thoroughly and remove moisture before measurement.\nAvoid moving or applying strong pressure to your fingers during measurement."
                                                 "@* Please refer to the user manual for other factors that may affect measurement.",
                                             });
    // Help 4: Consult a Doctor Before Use
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp4",QStringList{
                                                 "Under 19 years of age\n",
                                                 "Skin diseases or wounds in areas exposed to light,\nhand tremors such as hyperhidrosis, Parkinson's disease,"
                                                 "@History of severe hypoglycemia, diabetic ketoacidosis, epilepsy, syncope,\nadrenal disease,"
                                                 "@Undergoing hemodialysis or\nperitoneal dialysis,\npregnant or breastfeeding",
                                             });
    // Help 5: Key Features
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp5",QStringList{
                                                 "* High/Low blood glucose alerts\n"
                                                 "* Blood glucose calibration expiry alerts\n"
                                                 "* Blood glucose re-calibration alerts",
                                                 "When 90 days have passed from the calibration date, a calibration expiry alert occurs.",
                                                 "Re-calibration alerts begin 15 days before expiration.",
                                             });
    // Help 6: Bluetooth Support
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp6",QStringList{
                                                 "This is an exclusive Bluetooth feature for the Happyzone APP and is not compatible with other devices.",
                                             });

    //PAGE_FAQ_INDEX
    fontData[Lan][PAGE_FAQ_INDEX].insert("labelText",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_FAQ_INDEX].insert("labelText",QStringList{
                                             "Blood Glucose\nCalibration", // 0
                                             "Blood Glucose\nMeasurement", // 1
                                             "Device Care", // 2
                                             "Portability\n& Travel", // 3
                                             "Blood Glucose\nRecords", // 4
                                             "Users", // 5
                                             "A/S", // 6
                                             "Password", // 7
                                         });

    //PAGE_FAQ
    fontData[Lan][PAGE_FAQ].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_FAQ].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(26),QFont::Bold));
    fontData[Lan][PAGE_FAQ].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_FAQ].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    // Category 0: Blood Glucose Calibration
    textData[Lan][PAGE_FAQ].insert("labelTextFaq0",QStringList{
                                       "Why is blood glucose calibration necessary?", // 0-0
                                       "What happens if I don't do blood glucose calibration?", // 0-1
                                       "Can I measure after the blood glucose calibration deadline?", // 0-2
                                       "Why does blood glucose calibration need to be done every 90 days?", // 0-3
                                   });
    // Category 1: Blood Glucose Measurement
    textData[Lan][PAGE_FAQ].insert("labelTextFaq1",QStringList{
                                       "Is there a blood glucose measurement range?", // 1-0
                                       "What to do if the value is suddenly high or low?", // 1-1
                                       "What to do if measurement fails?", // 1-2
                                       "Can I measure with a different finger?", // 1-3
                                       "What to do if the finger position is incorrect?", // 1-4
                                       "Does incorrect measurement posture affect results?", // 1-5
                                       "Does it matter if the measurement time is incorrect?", // 1-6
                                       "Does low or high temperature affect results?", // 1-7
                                       "Can I measure with wet hands?", // 1-8
                                       "Can I measure immediately after exercise?", // 1-9
                                       "Is it okay for direct sunlight to enter the product?", // 1-10
                                       "What is the optical transmission method?", // 1-11
                                   });
    // Category 2: Device Care
    textData[Lan][PAGE_FAQ].insert("labelTextFaq2",QStringList{
                                       "Can it be used while charging?", // 2-0
                                       "How long does a full charge take?", // 2-1
                                       "What to do if battery performance seems degraded?", // 2-2
                                       "Can it be wiped with water?", // 2-3
                                       "Can it be wiped with cleaners, alcohol, acetone, etc.?", // 2-4
                                   });
    // Category 3: Portability & Travel
    textData[Lan][PAGE_FAQ].insert("labelTextFaq3",QStringList{
                                       "Can it be used portably?", // 3-0
                                       "Should the portable storage case be used?", // 3-1
                                       "Is carry-on allowed on aircraft?", // 3-2
                                       "Can it be sent as checked baggage?", // 3-3
                                   });
    // Category 4: Blood Glucose Records
    textData[Lan][PAGE_FAQ].insert("labelTextFaq4",QStringList{
                                       "Where can I check blood glucose results?", // 4-0
                                   });
    // Category 5: Users
    textData[Lan][PAGE_FAQ].insert("labelTextFaq5",QStringList{
                                       "Can pregnant women use it?", // 5-0
                                       "Can diabetic patients use it?", // 5-1
                                       "Can dialysis patients use it?", // 5-2
                                       "Can it be used if there is a wound on the measurement area?", // 5-3
                                       "Can multiple people use it together?", // 5-4
                                       "Can it be used without a smartphone?", // 5-5
                                   });
    // Category 6: A/S
    textData[Lan][PAGE_FAQ].insert("labelTextFaq6",QStringList{
                                       "What is the A/S period?", // 6-0
                                   });
    // Category 7: Password
    textData[Lan][PAGE_FAQ].insert("labelTextFaq7",QStringList{
                                       "How do I change my password?", // 7-0
                                   });

    //PAGE_FAQ_RESPONSE
    fontData[Lan][PAGE_FAQ_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_FAQ_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_FAQ_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    // FAQ Category 0: Blood Glucose Calibration
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-0",QStringList{
                                                "Because individual characteristics differ, it is necessary to adjust the product's characteristics to each person",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-1",QStringList{
                                                "You cannot measure without blood glucose calibration",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-2",QStringList{
                                                "Measurement is not possible after the deadline, so please perform blood glucose calibration again",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-3",QStringList{
                                                "Calibration must be performed again every 90 days for accurate measurement",
                                            });
    // FAQ Category 1: Blood Glucose Measurement
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-0",QStringList{
                                                "Measurement is possible in the range of 70~350 mg/dL",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-1",QStringList{
                                                "Check the correct usage environment and measurement posture, then re-measure",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-2",QStringList{
                                                "If measurement fails, a notification window appears with the reason for failure"
                                                "@Check the measurement failure problem in the troubleshooting menu",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-3",QStringList{
                                                "For accurate measurement, it is recommended to measure with the finger on which calibration was performed",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-4",QStringList{
                                                "Accurate measurement is not possible"
                                                "@For accurate measurement, relax and place your finger so the center lightly covers the sensor window edge",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-5",QStringList{
                                                "If the measurement posture is incorrect, measurement may not be accurate"
                                                "@Please measure in the correct posture for accurate measurement",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-6",QStringList{
                                                "It does not affect measurement results"
                                                "@However, if you plan to use it as blood glucose management data, it is recommended to measure at the appropriate time",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-7",QStringList{
                                                "If the temperature is too low or high, measurement values may not be accurate",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-8",QStringList{
                                                "Do not measure with wet hands"
                                                "@It may cause product malfunction",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-9",QStringList{
                                                "Do not measure immediately after exercise"
                                                "@Measure after breathing and heart rate have stabilized",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-10",QStringList{
                                                "Accurate measurement is not possible"
                                                "@For accurate measurement, please measure indoors without direct sunlight",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-11",QStringList{
                                                "It measures blood glucose by analyzing light passing through the finger",
                                            });
    // FAQ Category 2: Device Care
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-0",QStringList{
                                                "Please make sure to disconnect the charger before use",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-1",QStringList{
                                                "Full charge takes approximately 3 hours and 45 minutes",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-2",QStringList{
                                                "Contact the A/S center for inspection and replacement if necessary",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-3",QStringList{
                                                "Do not wipe with water"
                                                "@It may cause product malfunction",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-4",QStringList{
                                                "Do not wipe with cleaners, alcohol, acetone, etc."
                                                "@It may cause product malfunction",
                                            });
    // FAQ Category 3: Portability & Travel
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq3-0",QStringList{
                                                "Yes, you can carry and use it"
                                                "@Please use it in an indoor environment suitable for measurement",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq3-1",QStringList{
                                                "External shock may cause malfunction, so please carry it in the portable storage case",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq3-2",QStringList{
                                                "Can be carried and used in aircraft cabins"
                                                "@Cannot be sent as checked baggage",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq3-3",QStringList{
                                                "Cannot be sent as checked baggage"
                                                "@This product contains a lithium-ion polymer battery and cannot be sent as checked baggage due to safety regulations"
                                                "@It must be carried as carry-on luggage",
                                            });
    // FAQ Category 4: Blood Glucose Records
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq4-0",QStringList{
                                                "Today's records can be checked on the home screen"
                                                "@Check past blood glucose records in the blood glucose record menu",
                                            });
    // FAQ Category 5: Users
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq5-0",QStringList{
                                                "Measurement results may not be accurate"
                                                "@Please consult a medical professional",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq5-1",QStringList{
                                                "Measurement results may not be accurate"
                                                "@Please consult a medical professional",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq5-2",QStringList{
                                                "Measurement results may not be accurate"
                                                "@Please consult a medical professional",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq5-3",QStringList{
                                                "Measurement results may not be accurate"
                                                "@Please consult a medical professional",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq5-4",QStringList{
                                                "Up to 2 people can use it simultaneously",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq5-5",QStringList{
                                                "The product can be used independently",
                                            });
    // FAQ Category 6: A/S
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq6-0",QStringList{
                                                "The official A/S period is 24 months after product purchase",
                                            });
    // FAQ Category 7: Password
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq7-0",QStringList{
                                                "Go to the top bar 'Menu' - 'User Info' - 'Change Password' and follow the instructions to change your password.",
                                            });

    //PAGE_ERROR_HELP_INDEX
    fontData[Lan][PAGE_ERROR_HELP_INDEX].insert("labelText",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_ERROR_HELP_INDEX].insert("labelText",QStringList{
                                                    "Blood Glucose\nMeasurement", // 0
                                                    "Device Care", // 1
                                                    "Bluetooth", // 2
                                                    "Blood Glucose\nRecords", // 3
                                                });

    //PAGE_ERROR_HELP
    fontData[Lan][PAGE_ERROR_HELP].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(26),QFont::Bold));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    // Category 0: Blood Glucose Measurement
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp0",QStringList{
                                              "Measurement failure occurs frequently", // 0-0
                                              "It says the finger was not recognized", // 0-1
                                              "It says the finger surface temperature is low", // 0-2
                                              "It says there is an error in the measurement data", // 0-3
                                              "It says the measurement results cannot be analyzed", // 0-4
                                              "Can I cancel during measurement?", // 0-5
                                              "Blood glucose level is different from usual", // 0-6
                                              "I think blood glucose is normal but a warning is displayed", // 0-7
                                              "It says blood glucose calibration has expired", // 0-8
                                          });
    // Category 1: Device Care
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp1",QStringList{
                                              "Charging is not working", // 1-0
                                              "What to do when a low battery notification appears?", // 1-1
                                              "Battery low notification appeared and the product turned off", // 1-2
                                              "After booting, it doesn't enter the initial screen", // 1-3
                                              "It says the upgrade file is not visible", // 1-4
                                              "It says there is a problem with the upgrade file", // 1-5
                                              "It says it is not an upgrade file", // 1-6
                                              "The power turned off during upgrade", // 1-7
                                              "Screen is frozen or too slow", // 1-8
                                              "I don't know what error this is", // 1-9
                                              "A problem has occurred with the device", // 1-10
                                              "What to do if the problem is not resolved?", // 1-11
                                              "What additional consumables are there when using the product?", // 1-12
                                          });
    // Category 2: Bluetooth
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp2",QStringList{
                                              "App won't sync", // 2-0
                                              "Product and app measurement values differ", // 2-1
                                          });
    // Category 3: Blood Glucose Records
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp3",QStringList{
                                              "Are previous records deleted when resetting blood glucose calibration?", // 3-0
                                              "Can deleted blood glucose records be recovered?", // 3-1
                                          });

    //PAGE_ERROR_RESPONSE
    fontData[Lan][PAGE_ERROR_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_ERROR_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_ERROR_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    // ErrorHelp Category 0: Blood Glucose Measurement
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-0",QStringList{
                                                  "Please check the following measurement environment and re-measure"
                                                  "@Do not cough, sneeze, or talk and do not move during measurement"
                                                  "@Relax your finger and place it flat against the surface"
                                                  "@Maintain finger surface temperature above 26°C(79°F)"
                                                  "@Remove moisture and foreign substances from your finger",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-1",QStringList{
                                                  "Please check if the finger is inserted correctly and re-measure"
                                                  "@For accurate measurement, relax and place your finger so the center lightly covers the sensor window edge",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-2",QStringList{
                                                  "Please warm your finger sufficiently and re-measure",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-3",QStringList{
                                                  "Occurs when measurement data is incomplete or unanalyzable values are detected"
                                                  "@Avoid hand tremors, sneezing, and talking",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-4",QStringList{
                                                  "Occurs when the deviation of measured blood glucose values exceeds the range"
                                                  "@Please check the finger measurement position and environment, then re-measure",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-5",QStringList{
                                                  "Pressing the 'Cancel' button during measurement will stop it",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-6",QStringList{
                                                  "Check the measurement environment and re-measure"
                                                  "@If the measurement environment has no effect, check the following"
                                                  "@Check if there are symptoms of hypoglycemia or hyperglycemia"
                                                  "@If you suspect it is consistently inaccurate, consult a medical professional",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-7",QStringList{
                                                  "Please check and adjust the normal range in the blood glucose range menu",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-8",QStringList{
                                                  "Measurement is not possible when the blood glucose calibration validity period (90 days) expires"
                                                  "@Please perform blood glucose calibration",
                                              });
    // ErrorHelp Category 1: Device Care
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-0",QStringList{
                                                  "Please check if it is a rated battery charger"
                                                  "@If charging is not possible even with a rated battery charger, please contact the A/S center",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-1",QStringList{
                                                  "Please charge using the charger",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-2",QStringList{
                                                  "When the battery is 5% or below, the product will shut down after 5 seconds to protect the system"
                                                  "@Please charge using the charger",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-3",QStringList{
                                                  "Charge the battery using a rated battery charger"
                                                  "@After charging is complete, normal use is possible when booting completes after turning on the power again",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-4",QStringList{
                                                  "Please check the upgrade file again",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-5",QStringList{
                                                  "Please download the upgrade file again and try again",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-6",QStringList{
                                                  "Please check if the file is correct and try again",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-7",QStringList{
                                                  "Please try again after charging"
                                                  "@If the same phenomenon occurs after charging, please contact the A/S center",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-8",QStringList{
                                                  "Please press the reset button using a pin"
                                                  "@If the same phenomenon occurs after charging, please contact the A/S center",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-9",QStringList{
                                                  "First restart the product and check if the same error occurs"
                                                  "@Or upgrade the product's software version to the latest version"
                                                  "@If the same phenomenon occurs, please contact the A/S center",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-10",QStringList{
                                                  "This is a case where a problem has occurred with the product"
                                                  "@Please try restarting and updating"
                                                  "@If the same phenomenon occurs, please contact the A/S center",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-11",QStringList{
                                                  "Please contact the A/S center",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-12",QStringList{
                                                  "There are no additional consumables",
                                              });
    // ErrorHelp Category 2: Bluetooth
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp2-0",QStringList{
                                                  "Touch the 'Bluetooth' icon on the top bar of the product screen to activate it. Then keep your smartphone within 1M of the product"
                                                  "@and search for Bluetooth on your smartphone to find and link the Happyzone product."
                                                  "@If the problem persists, try turning the product off and on again.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp2-1",QStringList{
                                                  "Check the date and measurement item.\n"
                                                  "If the problem persists, it may be a temporary error, so try turning off and restarting both the product and app.",
                                              });
    // ErrorHelp Category 3: Blood Glucose Records
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp3-0",QStringList{
                                                  "Records are not deleted even after initialization",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp3-1",QStringList{
                                                  "Cannot be recovered"
                                                  "@Please be careful when deleting blood glucose records",
                                              });

    fontData[Lan][PAGE_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_RESPONSE].insert("labelPageNum",QFont(currentFont,instance.pixelToPoint(28)));


    //=====================================================================================================================================
    //JP
    Lan = JP;
    nTextSize = 30;
    currentFont = instance.fontJP;

    //PAGE_TRANS
    fontData[Lan][PAGE_TRANS].insert("fontSuit",QFont(instance.fontSuit,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_TRANS].insert("fontJP",QFont(instance.fontJP,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_TRANS].insert("fontSC",QFont(instance.fontSC,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_TRANS].insert("fontTC",QFont(instance.fontTC,instance.pixelToPoint(36)));

    textData[Lan][PAGE_TRANS].insert("lang",QStringList{
                                         "한국어",
                                         "ENGLISH",
                                         "日本語",
                                         "繁體中文",
                                         "简体中文",
                                         "ESPAÑOL"
                                     });
    //CUSTOM_BUTTON
    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonOK", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonOK", QStringList{"確認"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel", QStringList{"キャンセル"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonHome", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonHome", QStringList{"ホーム"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart", QStringList{"開始"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasure", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasure", QStringList{"測定"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonInput", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonInput", QStringList{"入力"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe", QStringList{"再測定"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonSave", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonSave", QStringList{"保存"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonUpgrade", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonUpgrade", QStringList{"ソフトウェア更新"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QStringList{"はい"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QStringList{"いいえ"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QStringList{
                                            "한국어",
                                            "ENGLISH",
                                            "日本語",
                                            "繁體中文",
                                            "简体中文",
                                            "ESPAÑOL"
                                        });

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonBack", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonBack", QStringList{"戻る"});

    //CUSTOM_COMPONENT
    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextValue", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextResult", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextResult", QStringList{
                                               "測定に成功しました",                         // 0
                                               "指を検出できませんでした。\n再度測定してください", // 1
                                               "デバイスエラーです。\nサポートへお問い合わせください", // 2
                                               "デバイスエラーです。\nサポートへお問い合わせください", // 3
                                               "解析に失敗しました。\n再度測定してください",         // 4
                                               "データエラーです。\n再度測定してください",           // 5
                                               "充電中は測定できません。\n充電を外して再度お試しください", // 6
                                               "指が冷たすぎます。\n測定できません。",               // 7
                                               "測定に失敗しました。\nサポートへお問い合わせください"  // 8
                                           });

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QStringList{
                                               "アップグレードに成功しました", // 0
                                               "アップグレードに失敗しました。\nカスタマーサポートにお問い合わせください", // 1
                                               "アップグレードファイルが見つかりません。\nファイルを再確認してください", // 2
                                               "アップグレードファイルに問題があります。\n新しいファイルで再試行してください", // 3
                                               "アップグレード用のファイルではありません。\n正しいファイルか確認してください", // 4
                                               "アップグレードに失敗しました。\nカスタマーサポートにお問い合わせください" // 5
                                           });


    //CUSTOM_COMPONENT_DATE
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelText", QFont(currentFont, instance.pixelToPoint(50)));
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelTextSelect", QFont(currentFont, instance.pixelToPoint(50), QFont::Bold));
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelTextSub", QFont(currentFont, instance.pixelToPoint(40)));

    //PAGE_PASSWORD
    fontData[Lan][PAGE_PASSWORD].insert("labelButtonNum", QFont(currentFont, instance.pixelToPoint(44), QFont::Bold));

    fontData[Lan][PAGE_PASSWORD].insert("labelTitle", QFont(currentFont, instance.pixelToPoint(40), QFont::Bold));
    textData[Lan][PAGE_PASSWORD].insert("labelTitle", QStringList{
                                            "ログインしてください",         // Please log in
                                            "パスワードを変更する",         // Edit Password
                                            "ユーザーを削除する",          // Delete User
                                            "パスワード確認",             // Password Confirmation
                                            "再確認",                   // Password Re-confirmation
                                            "PASSWORD_MAX"
                                        });

    fontData[Lan][PAGE_PASSWORD].insert("labelTitleSub", QFont(currentFont, instance.pixelToPoint(30)));
    textData[Lan][PAGE_PASSWORD].insert("labelTitleSub", QStringList{
                                            "4桁のパスワードを入力してください",             // Please enter your 4-digit password
                                            "変更する4桁の番号を入力してください",          // Please enter the 4 digits to modify
                                            "もう一度4桁のパスワードを入力してください",    // Please enter your 4-digit password again
                                            "確認のため4桁を入力してください",             // Please confirm by entering 4 digits
                                            "確認のためもう一度4桁を入力してください",      // Please re-enter the 4 digits to verify
                                            "現在のパスワードを入力してください",
                                            "PASSWORD_MAX"
                                        });

    fontData[Lan][PAGE_PASSWORD].insert("labelButtonOKText", QFont(currentFont, instance.pixelToPoint(29)));
    textData[Lan][PAGE_PASSWORD].insert("labelButtonOKText", QStringList{"確認"}); // OK

    fontData[Lan][PAGE_PASSWORD].insert("labelButtonCancelText", QFont(currentFont, instance.pixelToPoint(29)));
    textData[Lan][PAGE_PASSWORD].insert("labelButtonCancelText", QStringList{"戻る"}); // Cancel

    //PAGE_SELECT_USER
    fontData[Lan][PAGE_SELECT_USER].insert("labelTitle", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_SELECT_USER].insert("labelTitle", QStringList{"ユーザーを選択してください"});

    fontData[Lan][PAGE_SELECT_USER].insert("labelUserText", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_SELECT_USER].insert("labelUserText", QStringList{"ユーザー1", "ユーザー2"});

    //PAGE_PASSWORD_ALLCHAT
    fontData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelButtonNum", QFont(currentFont, instance.pixelToPoint(44)));

    fontData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitle", QFont(currentFont, instance.pixelToPoint(40), QFont::Bold));
    textData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitle", QStringList{
                                                    "ログインしてください",
                                                    "パスワードの変更",
                                                    "記録を削除",
                                                    "パスワード確認",
                                                    "パスワード再確認",
                                                    "パスワード初期化",
                                                    "PASSWORD_MAX"
                                                });

    fontData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitleSub", QFont(currentFont, instance.pixelToPoint(30)));
    textData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitleSub", QStringList{
                                                    "パスワードを入力してください",
                                                    "新しいパスワードを入力してください",
                                                    "パスワードを入力してください",
                                                    "確認のためにパスワードを入力してください",
                                                    "再確認のためにパスワードを入力してください",
                                                    "現在のパスワードを入力してください",
                                                    "PASSWORD_MAX"
                                                });

    //PAGE_PASSWORD_CONFIRM
    fontData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTitle", QFont(currentFont, instance.pixelToPoint(40), QFont::Bold));
    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTitle", QStringList{
                                                    "ログイン", // PASSWORD_STR_LOGIN_SUCCESS
                                                    "ログイン", // PASSWORD_STR_LOGIN_FAIL
                                                    "ログイン", // PASSWORD_STR_LOGIN_CHANGE
                                                    "本人確認", // PASSWORD_STR_CONFIRM
                                                    "本人確認", // PASSWORD_STR_CONFIRM_FAIL
                                                    "PW確認",  // PASSWORD_STR_REPEAT
                                                    "PW確認",  // PASSWORD_STR_REPEAT_FAIL
                                                    "PW変更",  // PASSWORD_STR_EDIT
                                                    "PW変更",  // PASSWORD_STR_EDIT_CONFIRM
                                                    "PW変更",  // PASSWORD_STR_EDIT_CHANGE
                                                    "PW変更",  // PASSWORD_STR_EDIT_SUCCESS
                                                    "血糖記録を削除",//"記録を削除", // PASSWORD_STR_DELETE
                                                    "血糖記録を削除",//"記録を削除", // PASSWORD_STR_
                                                    "血糖記録を削除",//"記録を削除", // PASSWORD_STR_DELETE_SUCCESS
                                                    "ログアウト", // PASSWORD_STR_LOGOUT
                                                    "パスワード初期化",     // PASSWORD_STR_INIT
                                                    "パスワード初期化",     // PASSWORD_STR_INIT_CONFIRM
                                                    "パスワード初期化",     // PASSWORD_STR_SUCCESS
                                                    "PASSWORD_STR_MAX" // PASSWORD_STR_MAX
                                                });

    fontData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelText", QStringList{
                                                    "ログイン成功",
                                                    "ログイン失敗",
                                                    "パスワードを変更してください",
                                                    "本人確認のために\nパスワードを入力してください",
                                                    "パスワードが一致しません",
                                                    "もう一度パスワードを\n入力してください",
                                                    "入力されたパスワードが以前のパスワードと\n一致しません",
                                                    "パスワードを変更しますか？",
                                                    "本人確認のために\nパスワードを入力してください",
                                                    "新しいパスワードを入力してください\n\n8文字以上で、数字、英字、記号（例：.,?!）を含めてください",
                                                    "パスワード変更が完了しました\n再度ログインしてください",
                                                    "血糖記録を削除しますか？", // PASSWORD_STR_DELETE
                                                    "削除された記録は\n復元できません", // PASSWORD_STR_DELETE_CONFIRM
                                                    "血糖記録が削除されました", // PASSWORD_STR_DELETE_SUCCESS
                                                    "ログアウトを開始します",
                                                    "パスワードを初期化しますか？",
                                                    "初期化すると、パスワードは\n初期設定に戻ります",
                                                    "パスワードが初期化されました",
                                                    "PASSWORD_STR_MAX"                          // PASSWORD_STR_MAX
                                                });

    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTextError", QStringList{
                                                    "パスワードが設定されました",
                                                    "パスワードは\n8〜12文字である必要があります",
                                                    "パスワードには\n数字を1つ以上含めてください",
                                                    "パスワードには\n英字（A〜Z）を1つ以上含めてください",
                                                    "パスワードには\n記号（例：.,?!）を1つ以上含めてください",
                                                    "パスワードが一致しません",
                                                    "このパスワードは使用できません",
                                                    "不明なエラーが発生しました",
                                                });

    //PAGE_HOME
    fontData[Lan][PAGE_HOME].insert("labelTextStatus", QFont(currentFont, instance.pixelToPoint(26), QFont::Bold));
    textData[Lan][PAGE_HOME].insert("labelTextStatus", QStringList{
                                        "起床",            // Wake Up
                                        "朝食前",          // Before Breakfast
                                        "朝食後",          // After Breakfast
                                        "昼食前",          // Before Lunch
                                        "昼食後",          // After Lunch
                                        "夕食前",          // Before Dinner
                                        "夕食後",          // After Dinner
                                        "就寝"             // Bed Time
                                    });

    fontData[Lan][PAGE_HOME].insert("labelButtonText", QFont(currentFont, instance.pixelToPoint(62), QFont::ExtraBold));

    //PAGE_SELECT
    fontData[Lan][PAGE_SELECT].insert("labelTextStatus", QFont(currentFont, instance.pixelToPoint(42), QFont::ExtraBold));
    textData[Lan][PAGE_SELECT].insert("labelTextStatus", QStringList{
                                          "起床",            // Wake Up
                                          "朝食前",          // Before Breakfast
                                          "朝食後",          // After Breakfast
                                          "昼食前",          // Before Lunch
                                          "昼食後",          // After Lunch
                                          "夕食前",          // Before Dinner
                                          "夕食後",          // After Dinner
                                          "就寝"             // Bed Time
                                      });
    fontData[Lan][PAGE_SELECT].insert("labelTextStatusSub", QFont(currentFont, instance.pixelToPoint(24)));
    textData[Lan][PAGE_SELECT].insert("labelTextStatusSub", QStringList{"測定を開始してください"}); // Please start the measurement

    fontData[Lan][PAGE_SELECT].insert("labelTextStatusValue", QFont(currentFont, instance.pixelToPoint(40), QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextGlucoseValue", QFont(currentFont, instance.pixelToPoint(130), QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextMgdl", QFont(currentFont, instance.pixelToPoint(34), QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextResult", QFont(currentFont, instance.pixelToPoint(32)));
    textData[Lan][PAGE_SELECT].insert("labelTextResult", QStringList{
                                          "正常",       // Normal
                                          "注意",       // Caution
                                          "注意",       // Caution
                                          "警告",       // Warning
                                          "警告"        // Warning
                                      });
    textData[Lan][PAGE_SELECT].insert("labelTextResultSub", QStringList{
                                          "血糖値",     // Blood Sugar
                                          "低血糖",     // Low Blood Sugar
                                          "高血糖",     // High Blood Sugar
                                          "低血糖",     // Low Blood Sugar
                                          "高血糖"      // High Blood Sugar
                                      });

    fontData[Lan][PAGE_SELECT].insert("labelTextTime", QFont(currentFont, instance.pixelToPoint(21), QFont::Bold));
    textData[Lan][PAGE_SELECT].insert("labelTextTime", QStringList{"時間"}); // Time

    fontData[Lan][PAGE_SELECT].insert("labelTextIcon", QFont(currentFont, instance.pixelToPoint(23), QFont::Bold));
    textData[Lan][PAGE_SELECT].insert("labelTextIcon", QStringList{
                                          "正常",       // Normal
                                          "低",         // Low
                                          "高",         // High
                                          "低",         // Low
                                          "高"          // High
                                      });

    //PAGE_MENU
    fontData[Lan][PAGE_MENU].insert("labelButtonText", QFont(currentFont, instance.pixelToPoint(25), QFont::Bold));
    textData[Lan][PAGE_MENU].insert("labelButtonText", QStringList{
                                        "補正",          // Calibration
                                        "範囲",          // Range
                                        "リスト",        // List
                                        "サウンド",      // Sound
                                        "スリープ",      // Sleep
                                        "スイッチ",      // Switch
                                        "日付",          // Date
                                        "カラーモード",  // Color Mode
                                        "言語",          // Language
                                        "アップ\nグレード", // Upgrade
                                        "デバイス\n情報",  // Device Info
                                        "リセット",      // Reset
                                        "ユーザー",       // User
                                        "ヘルプ",        // help
                                        "よくある質問",   // faq
                                        "エラー案内",     // error gide
                                    });

    //PAGE_CALI_CHECK
    fontData[Lan][PAGE_CALI_CHECK].insert("labelTextCheck", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_CHECK].insert("labelTextCheck", QStringList{
                                              "補正フェーズです\n指を挿入してください",          // Calibration phase, Please insert your finger
                                              "補正完了です\n再実行しますか？"                // Calibration complete, Do you want to proceed again?
                                          });

    //PAGE_CALI_GAIN_CONFIRM
    fontData[Lan][PAGE_CALI_GAIN_CONFIRM].insert("labelTextGainConfirm", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_GAIN_CONFIRM].insert("labelTextGainConfirm", QStringList{
                                                     "LED感度調整段階です\n指を動かさないでください",    // LED sensitivity adjustment step, Please do not move your finger
                                                     "LED感度調整が完了しました"                      // LED sensitivity adjustment has been completed
                                                 });

    //PAGE_GRAPH
    fontData[Lan][PAGE_GRAPH].insert("labelProgressText", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][PAGE_GRAPH].insert("labelProgressText", QStringList{"完了"}); // Completed

    fontData[Lan][PAGE_GRAPH].insert("labelProgressValue", QFont(currentFont, instance.pixelToPoint(60), QFont::Bold));
    fontData[Lan][PAGE_GRAPH].insert("labelProgressPercent", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));

    fontData[Lan][PAGE_GRAPH].insert("labelAdcText", QFont(currentFont, instance.pixelToPoint(20)));
    textData[Lan][PAGE_GRAPH].insert("labelAdcText", QStringList{"A:"});

    fontData[Lan][PAGE_GRAPH].insert("labelLoading", QFont(currentFont, instance.pixelToPoint(48), QFont::Bold));
    textData[Lan][PAGE_GRAPH].insert("labelLoading", QStringList{"解析中"}); // Analyzing

    //Page_CALI_GAIN_RESULT
    fontData[Lan][PAGE_CALI_GAIN_RESULT].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_GAIN_RESULT].insert("labelText", QStringList{
                                                    "LED感度調整が完了しました\n次の測定ステップに進んでください", // LED sensitivity adjustment is complete, Proceed to the next measurement step
                                                    "LED感度調整に失敗しました\n再度測定してください"          // LED sensitivity adjustment failed, Please measure again
                                                });

    //PAGE_CALI_SELECT
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectText", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT].insert("labelSelectText", QStringList{
                                               "空腹",       // Empty stomach
                                               "食後"        // After meal
                                           });

    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextAdc", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextValue", QFont(currentFont, instance.pixelToPoint(36)));

    //PAGE_CALI_SELECT_INFO
    fontData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText", QStringList{
                                                    "空腹時間が8時間以上経過していますか？\n30分間隔で2回測定します（01）",//"最後の食事から8時間以上\n経過しましたか？",            // Has it been more than 8 hours since your last meal?
                                                    "空腹時間が8時間以上経過していますか？\n30分間隔で2回測定します（02）",
                                                    "最後の食事から1時間以上\n経過しましたか？",            // Has it been more than 1 hour since your last meal?
                                                    "最後の食事から1時間30分以上\n経過しましたか？",        // Has it been more than 1 hour and 30 minutes since your last meal?
                                                    "最後の食事から2時間以上\n経過しましたか？"            // Has it been more than 2 hours since your last meal?
                                                });

    //PAGE_CALI_SEELCT_CONFIRM
    fontData[Lan][PAGE_CALI_SELECT_CONFIRM].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_CONFIRM].insert("labelText",QStringList{"順番に\n血糖値の補正を進めてください"});

    //PAGE_CALI_CONFIRM
    fontData[Lan][PAGE_CALI_CONFIRM].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_CONFIRM].insert("labelText", QStringList{"入力または測定を選択してください"}); // Select input or measure

    //PAGE_CALI_RESULT
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextAdc", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextTemp", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextHeart", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));

    //PAGE_CALI_RESULT_MULTI
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextAdc", QFont(currentFont, instance.pixelToPoint(34), QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextTemp", QFont(currentFont, instance.pixelToPoint(34)));
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextHeart", QFont(currentFont, instance.pixelToPoint(34)));

    //PAGE_CALI_RESULT_MULTI_CONFIRM
    fontData[Lan][PAGE_CALI_RESULT_MULTI_CONFIRM].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_RESULT_MULTI_CONFIRM].insert("labelText",QStringList{"選択した血糖値を削除して\n再測定しますか？"});


    //PAGE_RESULT
    fontData[Lan][PAGE_RESULT].insert("labelTextGlucoseValue", QFont(currentFont, instance.pixelToPoint(103), QFont::ExtraBold));

    fontData[Lan][PAGE_RESULT].insert("labelTextMgdl", QFont(currentFont, instance.pixelToPoint(27)));
    textData[Lan][PAGE_RESULT].insert("labelTextMgdl", QStringList{"mg/dL"}); // mg/dL

    fontData[Lan][PAGE_RESULT].insert("labelTextTime", QFont(currentFont, instance.pixelToPoint(21), QFont::Bold));
    textData[Lan][PAGE_RESULT].insert("labelTextTime", QStringList{"時間"}); // Time

    fontData[Lan][PAGE_RESULT].insert("labelText", QFont(currentFont, instance.pixelToPoint(36)));

    textData[Lan][PAGE_RESULT].insert("indexResult", QStringList{
                                          "正常",       // Normal
                                          "注意",       // Caution
                                          "注意",       // Caution
                                          "警告",       // Warning
                                          "警告"        // Warning
                                      });
    textData[Lan][PAGE_RESULT].insert("indexResultSub", QStringList{
                                          "血糖値",     // Blood Sugar
                                          "低血糖",     // Low Blood Sugar
                                          "高血糖",     // High Blood Sugar
                                          "低血糖",     // Low Blood Sugar
                                          "高血糖"      // High Blood Sugar
                                      });

    fontData[Lan][PAGE_RESULT].insert("labelProgressBarTooltip", QFont(currentFont, instance.pixelToPoint(16), QFont::Bold));
    textData[Lan][PAGE_RESULT].insert("labelProgressBarTooltip", QStringList{
                                          "正常",       // Normal
                                          "注意",       // Caution
                                          "警告",       // Warning
                                          "エラー"      // Error
                                      });

    //PAGE_INIT
    fontData[Lan][PAGE_INIT].insert("labelText", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_INIT].insert("labelText", QStringList{
                                        "工場出荷状態にリセット", // Factory reset
                                        "Bluetoothをリセット",    // Bluetooth reset
                                        "血糖補正をリセット"      // Blood sugar calibration reset
                                    });

    //PAGE_INIT_CONFIRM
    fontData[Lan][PAGE_INIT_CONFIRM].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_INIT_CONFIRM].insert("labelText", QStringList{
                                                "システム全体の情報が\nリセットされます\n工場出荷状態に\nリセットしますか？", // The entire system information will be reset. Do you want to proceed with factory reset?
                                                "システムの初期化後、\nシステムが再起動します",          // After system initialization, the system will restart
                                                "Bluetoothのユーザー情報が\n初期化されます\nスマートフォンとの接続が\n切断されます\nBluetoothをリセットしますか？", // Bluetooth user information will be initialized. The connection with the smartphone is disconnected. Would you like to reset Bluetooth?
                                                "Bluetoothのユーザー情報が\n初期化されました",          // Bluetooth user information has been reset
                                                "血糖補正がリセットされます\n血糖補正を\nリセットしますか？", // Blood sugar correction will be reset. Do you want to reset blood sugar correction?
                                                "血糖補正がリセットされました"                     // Blood sugar correction has been reset
                                            });

    //PAGE_THRESHOLD
    fontData[Lan][PAGE_THRESHOLD].insert("labelText", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_THRESHOLD].insert("labelText", QStringList{
                                             "低血糖",  // Low Blood Sugar
                                             "高血糖"   // High Blood Sugar
                                         });

    fontData[Lan][PAGE_THRESHOLD].insert("labelButton", QFont(currentFont, instance.pixelToPoint(22),QFont::Bold));
    textData[Lan][PAGE_THRESHOLD].insert("labelButton", QStringList{"設定"}); // Set

    fontData[Lan][PAGE_THRESHOLD].insert("labelValue", QFont(currentFont, instance.pixelToPoint(48), QFont::Bold));

    fontData[Lan][PAGE_THRESHOLD].insert("labelValueRange",QFont(currentFont,instance.pixelToPoint(26)));
    textData[Lan][PAGE_THRESHOLD].insert("labelValueRange",QStringList{
                                             "以下",
                                             "以上"
                                         });

    //PAGE_SOUND
    fontData[Lan][PAGE_SOUND].insert("labelVolume", QFont(currentFont, instance.pixelToPoint(110), QFont::Bold));

    //PAGE_SLEEP
    fontData[Lan][PAGE_SLEEP].insert("labelText", QFont(currentFont, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][PAGE_SLEEP].insert("labelText", QStringList{
                                         "30秒",    // 30sec
                                         "1分",     // 1min
                                         "3分",     // 3min
                                         "5分",     // 5min
                                         "10分",    // 10min
                                         "なし"      // None
                                     });

    //PAGE_UPGRADE
    fontData[Lan][PAGE_UPGRADE].insert("labelText", QFont(currentFont, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][PAGE_UPGRADE].insert("labelText", QStringList{"バージョン"}); // Version

    fontData[Lan][PAGE_UPGRADE].insert("labelTextVersion", QFont(currentFont, instance.pixelToPoint(55)));

    //PAGE_UPGRADE_CONFIRM
    fontData[Lan][PAGE_UPGRADE_CONFIRM].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_UPGRADE_CONFIRM].insert("labelText", QStringList{
                                                   "1. デバイスをPCに接続\n"
                                                   "2. binファイルをデバイスにコピー\n"
                                                   "3. コピー完了後、デバイスを再起動"
                                               }); // 1. Connect the device to PC, 2. Copy bin file to the device, 3. Restart the device after copying is complete

    //PAGE_DEVICEINFO
    fontData[Lan][PAGE_DEVICEINFO].insert("labelTitle", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][PAGE_DEVICEINFO].insert("labelTitle", QStringList{
                                              "BLE",          // BLE
                                              "H/W バージョン", // H/W ver
                                              "S/W バージョン", // S/W ver
                                              "シリアル"       // Serial
                                          });

    fontData[Lan][PAGE_DEVICEINFO].insert("labelText", QFont(currentFont, instance.pixelToPoint(30)));

    //PAGE_USERINFO
    fontData[Lan][PAGE_USERINFO].insert("labelText", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_USERINFO].insert("labelText", QStringList{
                                            "パスワードを変更する",   // Change password
                                            "パスワードをリセット", // reset password
                                            "血糖記録を削除", // Delete user data
                                            "ログアウト"             // Log out
                                        });

    //PAGE_BATPOPUP
    fontData[Lan][PAGE_BATPOPUP].insert("labelText", QFont(currentFont, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][PAGE_BATPOPUP].insert("labelText", QStringList{
                                            "バッテリー残量が少ない",           // Low Battery
                                            "充電器を接続してください"         // Please connect it to the charger
                                        });

    fontData[Lan][PAGE_BATPOPUP].insert("labelTextSub", QFont(currentFont, instance.pixelToPoint(nTextSize)));
    textData[Lan][PAGE_BATPOPUP].insert("labelTextSub", QStringList{
                                            "バッテリー残量が非常に少ない",       // Battery very low
                                            "システムをシャットダウンしています" // The system is shutting down
                                        });

    //PAGE_REVERSE
    fontData[Lan][PAGE_REVERSE].insert("labelTextButton", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_REVERSE].insert("labelTextButton", QStringList{
                                           "左",   // Left
                                           "右"    // Right
                                       });

    fontData[Lan][PAGE_REVERSE].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize)));
    textData[Lan][PAGE_REVERSE].insert("labelText", QStringList{
                                           "リセットが開始されます" // Reset will be proceeded
                                       });

    //PAGE_HISTORY
    fontData[Lan][PAGE_HISTORY].insert("labelButton",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][PAGE_HISTORY].insert("labelButton",QStringList{
                                           "+ 7日後",
                                           "今日",
                                           "- 7日前"
                                       });

    //PAGE_ELAPSED_NOTICE_POPUP
    fontData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("labelTitle",QStringList{
                                                        "血糖補正 有効期限"
                                                    });

    fontData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));

    textData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("elapsedText",QStringList{
                                                        "1日後に期限切れ",
                                                        "2日後に期限切れ",
                                                        "3日後に期限切れ",
                                                        "4日後に期限切れ",
                                                        "5日後に期限切れ",
                                                        "6日後に期限切れ",
                                                        "7日後に期限切れ",
                                                        "8日後に期限切れ",
                                                        "9日後に期限切れ",
                                                        "10日後に期限切れ",
                                                        "11日後に期限切れ",
                                                        "12日後に期限切れ",
                                                        "13日後に期限切れ",
                                                        "14日後に期限切れ",
                                                        "15日後に期限切れ"
                                                    });

    textData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("warningText",QStringList{
                                                        "期限切れ（測定不可）"
                                                    });

    //PAGE_BLOOD_CHECK
    fontData[Lan][PAGE_BLOOD_CHECK].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_BLOOD_CHECK].insert("labelText",QStringList{
                                               "医療機関で測定した値ですか？"
                                           });

    //PAGE_BLOOD_NOTICE_POPUP
    fontData[Lan][PAGE_BLOOD_NOTICE_POPUP].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_BLOOD_NOTICE_POPUP].insert("labelText",QStringList{
                                                      "測定範囲を超えています"
                                                  });

    //PAGE_USER_CHECK
    fontData[Lan][PAGE_USER_CHECK].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK].insert("labelText",QStringList{
                                              "前糖尿病",
                                              "非糖尿病",
                                              "糖尿病"
                                          });
    fontData[Lan][PAGE_USER_CHECK].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK].insert("labelTitle",QStringList{
                                              "ユーザータイプの選択"
                                          });

    //PAGE_BLOOD_CHECK_NOTICE //unused
    fontData[Lan][PAGE_BLOOD_CHECK_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_BLOOD_CHECK_NOTICE].insert("labelText",QStringList{
                                                      "静脈血の情報がありません。\n入力してください。"
                                                  });

    //PAGE_CALI_VALUE_NOTICE //unused
    fontData[Lan][PAGE_CALI_VALUE_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_VALUE_NOTICE].insert("labelText",QStringList{
                                                     "70〜350の範囲外です。\n有効な値を入力してください。"
                                                 });

    //PAGE_USER_NOTICE
    fontData[Lan][PAGE_USER_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_NOTICE].insert("labelText",QStringList{
                                               "本製品は、薬物を使用していない\n前糖尿病患者向けの医療機器です"
                                           });

    //PAGE_USER_FINGER
    fontData[Lan][PAGE_USER_FINGER].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_FINGER].insert("labelTitle",QStringList{
                                               "指の推奨周囲"
                                           });

    //PAGE_CALI_NOTICE
    fontData[Lan][PAGE_CALI_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_NOTICE].insert("labelText",QStringList{
                                               "再補正を行いますか？"
                                           });

    //PAGE_USER_CHECK_NOTICE
    fontData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelText",QStringList{
                                                     "対象ユーザー：なし",
                                                     "対象ユーザー：非糖尿病",
                                                     "対象ユーザー：前糖尿病",
                                                     "対象ユーザー：糖尿病"
                                                 });

    fontData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelCaliDay",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelCaliDay",QStringList{
                                                     "校正完了日："
                                                 });

    //PAGE_USER_CAUTIONS
    fontData[Lan][PAGE_USER_CAUTIONS].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CAUTIONS].insert("labelTitle",QStringList{
                                                 "ハッピーゾーン ご使用上の注意"
                                             });

    fontData[Lan][PAGE_USER_CAUTIONS].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CAUTIONS].insert("labelText",QStringList{
                                                 "1. 一定の呼吸を維持してください",
                                                 "2. 測定中は会話を控え、動かないでください",
                                                 "3. 指に力や圧力をかけないでください",
                                                 "4. 指に水分や異物が付着していないことを\n確認してください",
                                                 "5. 指の表面温度を26℃以上に\n保ってください",
                                                 "6. 指を測定部に密着させ、\n水平を保ってください",
                                                 "7. 必ず充電器を外して使用してください",
                                                 "8. 使用環境の温度を確認してください\n（15～35℃)",
                                             });

    //PAGE_CALI_SELECT_RE
    fontData[Lan][PAGE_CALI_SELECT_RE].insert("labelText",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_RE].insert("labelText",QStringList{
                                                  "例",
                                                  "空腹 01",
                                                  "空腹 02",
                                                  "食後 01",
                                                  "食後 02",
                                                  "食後 03",
                                              });

    fontData[Lan][PAGE_CALI_SELECT_RE].insert("labelTextValue",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));

    //PAGE_HELP
    fontData[Lan][PAGE_HELP].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_HELP].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_HELP].insert("labelText",QStringList{
                                        "この製品は何ですか？", // 0
                                        "この製品はどのような用途に使用しますか？", // 1
                                        "この製品の利点は何ですか？", // 2
                                        "誰でも使用できますか？", // 3
                                        "どのような機能を提供しますか？", // 4
                                        "どのような状況で使用すると良いですか？", // 5
                                        "測定は簡単ですか？", // 6
                                        "測定前に準備ステップがありますか？", // 7
                                        "血糖補正とは何ですか？", // 8
                                        "血糖補正は必ず行う必要がありますか？", // 9
                                        "血糖補正には周期がありますか？", // 10
                                        "測定前に注意事項がありますか？", // 11
                                        "測定中に注意事項がありますか？", // 12
                                        "専門医への相談は必要ですか？", // 13
                                        "測定はどのように進みますか？", // 14
                                        "測定過程は自動ですか？", // 15
                                        "測定時間はどれくらいかかりますか？", // 16
                                        "結果はどのように表示されますか？", // 17
                                        "結果は何を意味しますか？", // 18
                                        "結果の色は調整できますか？", // 19
                                        "結果をどのように活用すればよいですか？", // 20
                                        "測定記録は保存されますか？", // 21
                                        "測定結果は正確ですか？", // 22
                                        "測定環境の影響はありますか？", // 23
                                        "保管はどのようにすればよいですか？", // 24
                                        "防水機能はありますか？", // 25
                                        "この製品の限界は何ですか？", // 26
                                        "この製品は診断用ですか？", // 27
                                        "電源はどのように供給されますか？", // 28
                                        "製品の使用時間はどのくらいですか？", // 29
                                        "充電はどのようにしますか？", // 30
                                    });
    fontData[Lan][PAGE_HELP].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_HELP].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));

    //PAGE_FAQ
    fontData[Lan][PAGE_FAQ].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_FAQ].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_FAQ].insert("labelText",QStringList{
                                       "血糖測定の範囲はありますか？", // 0
                                       "血糖結果はどこで確認できますか？", // 1
                                       "値が急に高い、または低い場合はどうすればよいですか？", // 2
                                       "血糖補正はなぜ必要ですか？", // 3
                                       "血糖補正をしないとどうなりますか？", // 4
                                       "血糖補正の期限が過ぎたら測定できますか？", // 5
                                       "血糖補正はなぜ90日ごとに行う必要がありますか？", // 6
                                       "測定に失敗した場合はどうすればよいですか？", // 7
                                       "別の指で測定しても大丈夫ですか？", // 8
                                       "指の位置が合っていない場合はどうすればよいですか？", // 9
                                       "測定姿勢が正しくない場合、影響がありますか？", // 10
                                       "測定時間が合っていなくても大丈夫ですか？", // 11
                                       "温度が低い、または高い場合に影響はありますか？", // 12
                                       "濡れた手で測定しても大丈夫ですか？", // 13
                                       "運動直後に測定しても大丈夫ですか？", // 14
                                       "製品内部に直射日光が入っても大丈夫ですか？", // 15
                                       "妊婦でも使用できますか？", // 16
                                       "糖尿病患者でも使用できますか？", // 17
                                       "透析患者でも使用できますか？", // 18
                                       "測定部位に傷があっても使用できますか？", // 19
                                       "複数人で一緒に使用しても大丈夫ですか？", // 20
                                       "スマートフォンなしで使用できますか？", // 21
                                       "充電中に使用しても大丈夫ですか？", // 22
                                       "バッテリーの完充電時間はどのくらいかかりますか？", // 23
                                       "バッテリー性能が低下しているようであればどうすればよいですか？", // 24
                                       "水で拭いても大丈夫ですか？", // 25
                                       "洗浄剤、アルコール、アセトンなどで拭いても大丈夫ですか？", // 26
                                       "携帯用として使用できますか？", // 27
                                       "携帯用収納ケースは使用しなければなりませんか？", // 28
                                       "航空機への機内持ち込みは可能ですか？", // 29
                                       "受託手荷物として送ることができますか？", // 30
                                       "光学透過方式とは何ですか？", // 31
                                       "A/S期間はどのくらいですか？", // 32
                                   });
    fontData[Lan][PAGE_FAQ].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_FAQ].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));

    //PAGE_ERROR_HELP
    fontData[Lan][PAGE_ERROR_HELP].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_ERROR_HELP].insert("labelText",QStringList{
                                              "測定失敗がよく発生します", // 0
                                              "指を認識しなかったと表示されます", // 1
                                              "指の表面温度が低いと表示されます", // 2
                                              "測定データにエラーがあると表示されます", // 3
                                              "測定結果を分析できないと表示されます", // 4
                                              "測定中にキャンセルできますか？", // 5
                                              "血糖値がいつもと違います", // 6
                                              "血糖値が正常だと思うのに警告が表示されます", // 7
                                              "血糖補正の有効期限が切れたと表示されます", // 8
                                              "血糖補正を初期化すると以前の記録は削除されますか？", // 9
                                              "削除した血糖記録は復元できますか？", // 10
                                              "充電できません", // 11
                                              "電池残量不足の通知が出たらどうすればよいですか？", // 12
                                              "電池残量不足の通知が出て、製品がオフになりました", // 13
                                              "電源ブート後、初期画面に入りません", // 14
                                              "アップグレードファイルが見えないと表示されます", // 15
                                              "アップグレードファイルに問題があると表示されます", // 16
                                              "アップグレード用のファイルではないと表示されます", // 17
                                              "アップグレード中に電源が切れました", // 18
                                              "画面がフリーズしたり、とても遅くなっています", // 19
                                              "どんなエラーなのかわかりません", // 20
                                              "デバイスに問題が発生しました", // 21
                                              "問題が解決しない場合はどうすればよいですか？", // 22
                                              "製品使用時に追加の消耗品はありますか？", // 23
                                          });
    fontData[Lan][PAGE_ERROR_HELP].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));

    //PAGE_RESPONSE
    fontData[Lan][PAGE_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_RESPONSE].insert("labelTextHelp",QStringList{
                                            "光学システムを使用して血糖を測定する製品です", // 0
                                            "体内の血糖を測定するために使用します", // 1
                                            "非侵襲的な測定方式で痛みなく測定できることが利点です", // 2
                                            "薬物治療を受けていない糖尿病予備群の患者が使用できます"
                                            "@この製品は19〜74歳の成人を基準に設計されています", // 3
                                            "血糖測定、血糖記録の保存および閲覧機能を提供します", // 4
                                            "日常的な血糖変化の確認用途に活用することをお勧めします", // 5
                                            "測定は簡単です"
                                            "@案内に従って測定を進めてください", // 6
                                            "測定前に血糖補正作業が必要です"
                                            "@案内に従って補正作業を進めてください", // 7
                                            "実際の血糖値と製品の間の誤差を減らすための補正作業を指します", // 8
                                            "はい。測定前に必ず行うように定められています", // 9
                                            "血糖補正は補正完了日から90日以内に必ず実施してください"
                                            "@実施されない場合、測定できません", // 10
                                            "測定前に手をきれいに洗い、水分を取り除いてください"
                                            "@製品から充電器を取り外してください", // 11
                                            "測定中に動いたり、指に強い圧力をかけることは避けてください"
                                            "@咳やくしゃみなどで指が動いた場合は再測定してください", // 12
                                            "次の状況では測定値が不正確になる可能性があるため、専門医への相談が必要です"
                                            "@19歳未満または75歳以上の場合"
                                            "@光が当たる部位に皮膚疾患や傷がある場合"
                                            "@多汗症、パーキンソン病などの手の震えがある場合"
                                            "@重症低血糖、糖尿病性ケトアシドーシス、てんかん、失神、副腎疾患の既往歴がある場合"
                                            "@血液透析、腹膜透析中の場合"
                                            "@妊婦および授乳婦", // 13
                                            "ホーム画面で測定時間帯を選択後、案内に従って進めてください", // 14
                                            "測定開始ボタンを押すと、完了まで自動的に進みます", // 15
                                            "測定時間は1分以内に完了します", // 16
                                            "結果は測定完了時に血糖値が数字で表示されます", // 17
                                            "色に応じて以下の意味があります"
                                            "@緑は正常です"
                                            "@オレンジは注意です"
                                            "@赤は警告です", // 18
                                            "血糖範囲メニューから正常色の範囲を調整できます", // 19
                                            "血糖管理中の参考用としてご活用ください"
                                            "@表示される値は参考情報です"
                                            "@医学的判断が必要な場合は専門医にご相談ください", // 20
                                            "測定記録は最大90日分が機器に保存されます"
                                            "@90日以降の記録は自動削除されます", // 21
                                            "使用環境条件によって異なる場合があります"
                                            "@使用案内に従ってご使用ください", // 22
                                            "はい。次のような環境は避けてください"
                                            "@強い直射日光がある場所は避けてください"
                                            "@風が強く吹く場所は避けてください"
                                            "@湿気のある環境は避けてください"
                                            "@振動のある環境は避けてください"
                                            "@室内温度が低すぎたり高すぎる場所は避けてください\n*適正温度: 10〜35℃ (50〜95℉)", // 23
                                            "電源を切り、指挿入口カバーで塞いだ後、収納ケースに保管してください", // 24
                                            "防水機能はありません", // 25
                                            "この製品は日常的な状態確認のための機器です"
                                            "@医療的診断を目的としていません", // 26
                                            "この製品は参考用の情報を提供します"
                                            "@医療的診断や治療の決定に代わることはできません"
                                            "@糖尿病の診断・治療、インスリン投与などの医療行為が必要な場合は必ず専門医にご相談ください", // 27
                                            "リチウムイオンポリマーバッテリーにより電力が供給されます", // 28
                                            "満充電時、待機モードの状態で最大約29日間使用できます", // 29
                                            "5V DC / 2A〜2.4A規格に合ったUSB Cタイプの充電器を使用して充電します", // 30
                                        });
    textData[Lan][PAGE_RESPONSE].insert("labelTextFaq",QStringList{
                                            "70〜350 mg/dLの範囲で測定が可能です", // 0
                                            "当日の記録はホーム画面で確認できます"
                                            "@過去の血糖記録は血糖記録メニューでご確認ください", // 1
                                            "正しい使用環境と測定姿勢を確認後、再測定してください", // 2
                                            "個人の特性が異なるため、製品の特性を個人に合わせる作業が必要です", // 3
                                            "血糖補正を行わないと測定できません", // 4
                                            "期限が過ぎると測定が不可能になりますので、血糖補正を再度行ってください", // 5
                                            "正確な測定のために90日ごとに補正を再度行う必要があります", // 6
                                            "測定に失敗した場合、失敗の理由についての通知ウィンドウが表示されます"
                                            "@測定失敗の問題はトラブルシューティングメニューでご確認ください", // 7
                                            "正確な測定のために、補正を行った指で測定することをお勧めします", // 8
                                            "正確な測定になりません"
                                            "@正確な測定のために、指の中央がセンサー窓の端を軽く覆うように力を抜いて置いてください", // 9
                                            "測定姿勢が正しくない場合、測定が正確でない可能性があります"
                                            "@正確な測定のために正しい姿勢で測定してください", // 10
                                            "測定結果には影響しません"
                                            "@ただし、血糖管理用のデータとして活用する予定の場合は、該当時間に合わせて測定することをお勧めします", // 11
                                            "温度が低すぎたり高すぎる場合、測定値が正確でない可能性があります", // 12
                                            "濡れた手で測定してはいけません"
                                            "@製品の故障原因となる可能性があります", // 13
                                            "運動直後に測定してはいけません"
                                            "@呼吸と心拍数が安定した後に測定してください", // 14
                                            "正確な測定になりません"
                                            "@正確な測定のために直射日光のない室内で測定してください", // 15
                                            "測定結果が正確でない可能性があります"
                                            "@専門医にご相談ください", // 16
                                            "測定結果が正確でない可能性があります"
                                            "@専門医にご相談ください", // 17
                                            "測定結果が正確でない可能性があります"
                                            "@専門医にご相談ください", // 18
                                            "測定結果が正確でない可能性があります"
                                            "@専門医にご相談ください", // 19
                                            "最大2名まで同時に使用できます", // 20
                                            "製品単独で使用できます", // 21
                                            "必ず充電器を取り外した後にご使用ください", // 22
                                            "満充電時間は約3時間45分かかります", // 23
                                            "A/Sセンターにお問い合わせいただき、点検後必要に応じて交換します", // 24
                                            "水で拭いてはいけません"
                                            "@製品の故障原因となる可能性があります", // 25
                                            "洗浄剤、アルコール、アセトンなどで拭いてはいけません"
                                            "@製品の故障原因となる可能性があります", // 26
                                            "はい、携帯してご使用ください"
                                            "@測定に適した室内環境でご使用ください", // 27
                                            "外部衝撃により誤作動、故障が発生する可能性がありますので、携帯用収納ケースに入れて携帯してください", // 28
                                            "航空機内で携帯および使用できます"
                                            "@手荷物としての発送はできません", // 29
                                            "手荷物としての発送はできません"
                                            "@本製品はリチウムイオンポリマーバッテリーを内蔵した製品で、安全規定上、受託手荷物としては送ることができません"
                                            "@必ず機内持ち込み手荷物として携帯してください", // 30
                                            "指を通過した光を分析して血糖を測定する方式です", // 31
                                            "公式A/S期間は製品購入後24ヶ月です", // 32
                                        });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp",QStringList{
                                                  "次の測定環境を確認後、再測定してください"
                                                  "@測定中に咳、くしゃみ、会話をせず、動かないでください"
                                                  "@指の力を抜いて水平に密着させてください"
                                                  "@指の表面温度を26℃(79℉)以上に保ってください"
                                                  "@指の水分や異物を取り除いてください", // 0
                                                  "指が正しく挿入されているか確認後、再測定してください"
                                                  "@正確な測定のために、指の中央がセンサー窓の端を軽く覆うように力を抜いて置いてください", // 1
                                                  "指を十分に温めた後、再測定してください", // 2
                                                  "測定データが不完全または分析できない値が検出されたときに発生します"
                                                  "@手の震え、くしゃみ、会話を避けてください", // 3
                                                  "測定された血糖値の偏差が範囲を超えたときに発生します"
                                                  "@指の測定位置と測定環境を確認後、再測定してください", // 4
                                                  "測定中に「キャンセル」ボタンを押すと中断されます", // 5
                                                  "測定環境を確認後、再測定してください"
                                                  "@測定環境に影響がない場合は以下の内容をご確認ください"
                                                  "@低血糖または高血糖の症状があるか確認してください"
                                                  "@継続的に不正確だと疑われる場合は専門医にご相談ください", // 6
                                                  "血糖範囲メニューで正常範囲を確認し、調整してください", // 7
                                                  "血糖補正有効期限(90日)満了時に測定が不可能です"
                                                  "@血糖補正を行ってください", // 8
                                                  "初期化しても記録は削除されません", // 9
                                                  "復元できません"
                                                  "血糖記録削除時にご注意ください", // 10
                                                  "定格バッテリー充電器かどうかご確認ください"
                                                  "@定格バッテリー充電器を使用しても充電できない場合はA/Sセンターへお問い合わせください", // 11
                                                  "充電器を使用して充電してください", // 12
                                                  "バッテリーが5%以下の場合、システム保護のために5秒後に製品がシャットダウンします"
                                                  "@充電器を使用して充電してください", // 13
                                                  "定格バッテリー充電器を使用してバッテリーを充電してください"
                                                  "@充電完了後、電源を入れ直してブートが完了すれば正常使用が可能です", // 14
                                                  "アップグレードファイルを再度ご確認ください", // 15
                                                  "アップグレードファイルを再ダウンロードしてから再試行してください", // 16
                                                  "ファイルが正しいファイルかどうか確認後、再試行してください", // 17
                                                  "充電後に再試行してください"
                                                  "@充電後も同じ現象が発生する場合はA/Sセンターへお問い合わせください", // 18
                                                  "ピンを使用してリセットボタンを押してください"
                                                  "@充電後も同じ現象が発生する場合はA/Sセンターへお問い合わせください", // 19
                                                  "まず製品を再起動後、同じエラーが発生するか確認してください"
                                                  "@または製品のソフトウェアバージョンを最新バージョンにアップグレードしてください"
                                                  "@同じ現象が発生する場合はA/Sセンターへお問い合わせください", // 20
                                                  "その他製品に問題が発生した場合です"
                                                  "@再起動およびアップデートをお試しください"
                                                  "@同じ現象が発生する場合はA/Sセンターへお問い合わせください", // 21
                                                  "A/Sセンターへお問い合わせください", // 22
                                                  "追加の消耗品はありません", // 23
                                              });
    fontData[Lan][PAGE_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_RESPONSE].insert("labelPageNum",QFont(currentFont,instance.pixelToPoint(28)));

    //=====================================================================================================================================
    //SC
    Lan = SC;
    nTextSize = 36;
    currentFont = instance.fontSC;

    //PAGE_TRANS
    fontData[Lan][PAGE_TRANS].insert("fontSuit",QFont(instance.fontSuit,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_TRANS].insert("fontJP",QFont(instance.fontJP,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_TRANS].insert("fontSC",QFont(instance.fontSC,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_TRANS].insert("fontTC",QFont(instance.fontTC,instance.pixelToPoint(36)));

    textData[Lan][PAGE_TRANS].insert("lang",QStringList{
                                         "한국어",
                                         "ENGLISH",
                                         "日本語",
                                         "繁體中文",
                                         "简体中文",
                                         "ESPAÑOL"
                                     });

    //CUSTOM_BUTTON
    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonOK", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonOK", QStringList{"确认"}); // OK

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel", QStringList{"取消"}); // Cancel

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonHome", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonHome", QStringList{"主页"}); // Home

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart", QStringList{"开始"}); // Start

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasure", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasure", QStringList{"测量"}); // Measure

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonInput", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonInput", QStringList{"输入"}); // Input

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe", QStringList{"重新测量"}); // Remeasure

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonSave", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonSave", QStringList{"保存"}); // Save

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonUpgrade", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonUpgrade", QStringList{"软件升级"}); // Software Upgrade

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QStringList{"是"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QStringList{"否"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QStringList{
                                            "한국어",
                                            "ENGLISH",
                                            "日本語",
                                            "繁體中文",
                                            "简体中文",
                                            "ESPAÑOL"
                                        });

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonBack", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonBack", QStringList{"返回"});

    //CUSTOM_COMPONENT
    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextValue", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextResult", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextResult", QStringList{
                                               "测量成功",                         // 0
                                               "未检测到手指\n请重新测量",           // 1
                                               "设备错误\n请联系客服",               // 2
                                               "设备错误\n请联系客服",               // 3
                                               "分析失败\n请重新测量",               // 4
                                               "数据错误\n请重新测量",               // 5
                                               "充电中无法测量\n请拔掉充电器后再试",    // 6
                                               "因手指温度过低，\n无法测量",           // 7
                                               "测量失败\n请联系客服"                // 8
                                           });

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QFont(currentFont, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QStringList{
                                               "升级成功", // 0
                                               "升级失败\n请联系客服", // 1
                                               "未找到升级文件\n请重新检查文件", // 2
                                               "升级文件有问题\n请使用新文件重试", // 3
                                               "此文件不是有效的升级文件\n请确认文件是否正确", // 4
                                               "升级失败\n请联系客服" // 5
                                           });

    //CUSTOM_COMPONENT_DATE
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelText", QFont(currentFont, instance.pixelToPoint(50)));
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelTextSelect", QFont(currentFont, instance.pixelToPoint(50), QFont::Bold));
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelTextSub", QFont(currentFont, instance.pixelToPoint(40)));

    //PAGE_PASSWORD
    fontData[Lan][PAGE_PASSWORD].insert("labelButtonNum", QFont(currentFont, instance.pixelToPoint(44), QFont::Bold));

    fontData[Lan][PAGE_PASSWORD].insert("labelTitle", QFont(currentFont, instance.pixelToPoint(40), QFont::Bold));
    textData[Lan][PAGE_PASSWORD].insert("labelTitle", QStringList{
                                            "请登录",           // Please log in
                                            "编辑密码",         // Edit Password
                                            "删除用户",         // Delete User
                                            "密码确认",         // Password Confirmation
                                            "密码再次确认",     // Password Re-confirmation
                                            "PASSWORD_MAX"
                                        });

    fontData[Lan][PAGE_PASSWORD].insert("labelTitleSub", QFont(currentFont, instance.pixelToPoint(30)));
    textData[Lan][PAGE_PASSWORD].insert("labelTitleSub", QStringList{
                                            "请输入您的4位数字密码",                 // Please enter your 4-digit password
                                            "请输入要修改的4位数字",               // Please enter the 4 digits to modify
                                            "请再次输入您的4位数字密码",           // Please enter your 4-digit password again
                                            "请输入4位数字以确认",                 // Please confirm by entering 4 digits
                                            "请再次输入4位数字以验证",             // Please re-enter the 4 digits to verify
                                            "请输入您的当前密码",
                                            "PASSWORD_MAX"
                                        });

    fontData[Lan][PAGE_PASSWORD].insert("labelButtonOKText", QFont(currentFont, instance.pixelToPoint(29)));
    textData[Lan][PAGE_PASSWORD].insert("labelButtonOKText", QStringList{"确认"}); // OK

    fontData[Lan][PAGE_PASSWORD].insert("labelButtonCancelText", QFont(currentFont, instance.pixelToPoint(29)));
    textData[Lan][PAGE_PASSWORD].insert("labelButtonCancelText", QStringList{"取消"}); // Cancel

    //PAGE_SELECT_USER
    fontData[Lan][PAGE_SELECT_USER].insert("labelTitle", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_SELECT_USER].insert("labelTitle", QStringList{"请选择用户"});

    fontData[Lan][PAGE_SELECT_USER].insert("labelUserText", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_SELECT_USER].insert("labelUserText", QStringList{"用户1", "用户2"});

    //PAGE_PASSWORD_ALLCHAT
    fontData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelButtonNum", QFont(currentFont, instance.pixelToPoint(44)));

    fontData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitle", QFont(currentFont, instance.pixelToPoint(40), QFont::Bold));
    textData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitle", QStringList{
                                                    "请登录",
                                                    "更改密码",
                                                    "删除血糖记录", //"删除用户",
                                                    "确认密码",
                                                    "再次确认密码",
                                                    "重置密码",
                                                    "PASSWORD_MAX"
                                                });

    fontData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitleSub", QFont(currentFont, instance.pixelToPoint(30)));
    textData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitleSub", QStringList{
                                                    "请输入密码",
                                                    "请输入新的密码",
                                                    "请输入密码",
                                                    "请输入确认密码",
                                                    "请再次输入密码",
                                                    "请输入当前密码",
                                                    "PASSWORD_MAX"
                                                });

    //PAGE_PASSWORD_CONFIRM
    fontData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTitle", QFont(currentFont, instance.pixelToPoint(40), QFont::Bold));
    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTitle", QStringList{
                                                    "登录",              // PASSWORD_STR_LOGIN_SUCCESS
                                                    "登录",              // PASSWORD_STR_LOGIN_FAIL
                                                    "登录",              // PASSWORD_STR_LOGIN_CHANGE
                                                    "身份验证",          // PASSWORD_STR_CONFIRM
                                                    "身份验证失败",      // PASSWORD_STR_CONFIRM_FAIL
                                                    "密码检查",          // PASSWORD_STR_REPEAT
                                                    "密码检查失败",      // PASSWORD_STR_REPEAT_FAIL
                                                    "密码更改",          // PASSWORD_STR_EDIT
                                                    "密码更改确认",      // PASSWORD_STR_EDIT_CONFIRM
                                                    "密码更改中",        // PASSWORD_STR_EDIT_CHANGE
                                                    "密码更改完成",      // PASSWORD_STR_EDIT_SUCCESS
                                                    "删除血糖记录",          // [CONFIRM - DELETE]
                                                    "删除血糖记录确认",      // [CONFIRM - DELETE_CONFIRM]
                                                    "血糖记录删除成功",      // [CONFIRM - DELETE_SUCCESS]
                                                    "退出登录",          // PASSWORD_STR_LOGOUT
                                                    "重置密码",    // PASSWORD_STR_INIT
                                                    "重置密码",    // PASSWORD_STR_INIT_CONFIRM
                                                    "重置密码",    // PASSWORD_STR_SUCCESS
                                                    "PASSWORD_STR_MAX"   // PASSWORD_STR_MAX
                                                });

    fontData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelText", QStringList{
                                                    "登录成功",
                                                    "登录失败",
                                                    "请更改您的密码",
                                                    "请输入密码以验证身份",
                                                    "密码不匹配",
                                                    "请再次输入您的密码以确认",
                                                    "输入的密码与之前的密码不匹配",
                                                    "是否要更改您的密码？",
                                                    "请输入密码以确认身份",
                                                    "请输入新密码\n\n至少包含8个字符、数字、字母和符号（例如：.,?!）",
                                                    "密码更改完成，请重新登录",
                                                    "是否删除血糖记录？", // PASSWORD_STR_DELETE
                                                    "删除后将无法恢复记录", // PASSWORD_STR_DELETE_CONFIRM
                                                    "血糖记录已删除", // PASSWORD_STR_DELETE_SUCCESS
                                                    "正在注销",
                                                    "是否要重置密码？",
                                                    "重置后密码将恢复为\n默认设置",
                                                    "密码已重置",
                                                    "PASSWORD_STR_MAX"
                                                });

    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTextError", QStringList{
                                                    "密码已设置",
                                                    "密码长度必须为\n8到12个字符",
                                                    "密码必须包含\n至少一个数字",
                                                    "密码必须包含\n至少一个字母（A-Z）",
                                                    "密码必须包含\n至少一个符号（例如：.,?!）",
                                                    "两次输入的密码不一致",
                                                    "此密碼不被允許使用",
                                                    "发生未知错误",
                                                });

    //PAGE_HOME
    fontData[Lan][PAGE_HOME].insert("labelTextStatus", QFont(currentFont, instance.pixelToPoint(26), QFont::Bold));
    textData[Lan][PAGE_HOME].insert("labelTextStatus", QStringList{
                                        "起床",            // Wake Up
                                        "早餐前",          // Before Breakfast
                                        "早餐后",          // After Breakfast
                                        "午餐前",          // Before Lunch
                                        "午餐后",          // After Lunch
                                        "晚餐前",          // Before Dinner
                                        "晚餐后",          // After Dinner
                                        "就寝"             // Bed Time
                                    });

    fontData[Lan][PAGE_HOME].insert("labelButtonText", QFont(currentFont, instance.pixelToPoint(62), QFont::ExtraBold));

    //PAGE_SELECT
    fontData[Lan][PAGE_SELECT].insert("labelTextStatus", QFont(currentFont, instance.pixelToPoint(42), QFont::ExtraBold));
    textData[Lan][PAGE_SELECT].insert("labelTextStatus", QStringList{
                                          "起床",            // Wake Up
                                          "早餐前",          // Before Breakfast
                                          "早餐后",          // After Breakfast
                                          "午餐前",          // Before Lunch
                                          "午餐后",          // After Lunch
                                          "晚餐前",          // Before Dinner
                                          "晚餐后",          // After Dinner
                                          "就寝"             // Bed Time
                                      });
    fontData[Lan][PAGE_SELECT].insert("labelTextStatusSub", QFont(currentFont, instance.pixelToPoint(24)));
    textData[Lan][PAGE_SELECT].insert("labelTextStatusSub", QStringList{"请开始测量"}); // Please start the measurement

    fontData[Lan][PAGE_SELECT].insert("labelTextStatusValue", QFont(currentFont, instance.pixelToPoint(40), QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextGlucoseValue", QFont(currentFont, instance.pixelToPoint(130), QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextMgdl", QFont(currentFont, instance.pixelToPoint(34), QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextResult", QFont(currentFont, instance.pixelToPoint(32)));
    textData[Lan][PAGE_SELECT].insert("labelTextResult", QStringList{
                                          "正常",       // Normal
                                          "注意",       // Caution
                                          "注意",       // Caution
                                          "警告",       // Warning
                                          "警告"        // Warning
                                      });
    textData[Lan][PAGE_SELECT].insert("labelTextResultSub", QStringList{
                                          "血糖",       // Blood Sugar
                                          "低血糖",     // Low Blood Sugar
                                          "高血糖",     // High Blood Sugar
                                          "低血糖",     // Low Blood Sugar
                                          "高血糖"      // High Blood Sugar
                                      });

    fontData[Lan][PAGE_SELECT].insert("labelTextTime", QFont(currentFont, instance.pixelToPoint(21), QFont::Bold));
    textData[Lan][PAGE_SELECT].insert("labelTextTime", QStringList{"时间"}); // Time

    fontData[Lan][PAGE_SELECT].insert("labelTextIcon", QFont(currentFont, instance.pixelToPoint(23), QFont::Bold));
    textData[Lan][PAGE_SELECT].insert("labelTextIcon", QStringList{
                                          "正常",       // Normal
                                          "低",         // Low
                                          "高",         // High
                                          "低",         // Low
                                          "高"          // High
                                      });

    //PAGE_MENU
    fontData[Lan][PAGE_MENU].insert("labelButtonText", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][PAGE_MENU].insert("labelButtonText", QStringList{
                                        "校准",       // Calibration
                                        "范围",       // Range
                                        "列表",       // List
                                        "声音",       // Sound
                                        "睡眠",       // Sleep
                                        "切换",       // Switch
                                        "日期",       // Date
                                        "颜色模式",   // Color Mode
                                        "语言",       // Language
                                        "升级",       // Upgrade
                                        "设备信息",   // Device Info
                                        "重置",       // Reset
                                        "用户",        // User
                                        "帮助",        // help
                                        "常见问题",     // faq
                                        "错误说明",     // error help
                                    });

    //PAGE_CALI_CHECK
    fontData[Lan][PAGE_CALI_CHECK].insert("labelTextCheck", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_CHECK].insert("labelTextCheck", QStringList{
                                              "校准阶段\n请插入手指",     // Calibration phase, Please insert your finger
                                              "校准完成\n是否重新执行？" // Calibration complete, Do you want to proceed again?
                                          });

    //PAGE_CALI_GAIN_CONFIRM
    fontData[Lan][PAGE_CALI_GAIN_CONFIRM].insert("labelTextGainConfirm", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_GAIN_CONFIRM].insert("labelTextGainConfirm", QStringList{
                                                     "LED灵敏度调整阶段\n请勿移动手指", // LED sensitivity adjustment step, Please do not move your finger
                                                     "LED灵敏度调整已完成"         // LED sensitivity adjustment has been completed
                                                 });

    //PAGE_GRAPH
    fontData[Lan][PAGE_GRAPH].insert("labelProgressText", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][PAGE_GRAPH].insert("labelProgressText", QStringList{"完成"}); // Completed

    fontData[Lan][PAGE_GRAPH].insert("labelProgressValue", QFont(currentFont, instance.pixelToPoint(60), QFont::Bold));
    fontData[Lan][PAGE_GRAPH].insert("labelProgressPercent", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));

    fontData[Lan][PAGE_GRAPH].insert("labelAdcText", QFont(currentFont, instance.pixelToPoint(20)));
    textData[Lan][PAGE_GRAPH].insert("labelAdcText", QStringList{"A:"});

    fontData[Lan][PAGE_GRAPH].insert("labelLoading", QFont(currentFont, instance.pixelToPoint(48), QFont::Bold));
    textData[Lan][PAGE_GRAPH].insert("labelLoading", QStringList{"分析中"}); // Analyzing

    //Page_CALI_GAIN_RESULT
    fontData[Lan][PAGE_CALI_GAIN_RESULT].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_GAIN_RESULT].insert("labelText", QStringList{
                                                    "LED灵敏度调整已完成\n请进行下一步测量", // LED sensitivity adjustment is complete, Proceed to the next measurement step
                                                    "LED灵敏度调整失败\n请重新测量"       // LED sensitivity adjustment failed, Please measure again
                                                });

    //PAGE_CALI_SELECT
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectText", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT].insert("labelSelectText", QStringList{
                                               "空腹",       // Empty stomach
                                               "餐后"        // After meal
                                           });

    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextAdc", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextValue", QFont(currentFont, instance.pixelToPoint(36)));

    //PAGE_CALI_SELECT_INFO
    fontData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText", QStringList{
                                                    "空腹时间是否已超过8小时？\n每隔30分钟测量2次（01）",//"距离上次进餐是否已超过8小时？",         // Has it been more than 8 hours since your last meal?
                                                    "空腹时间是否已超过8小时？\n每隔30分钟测量2次（02）",
                                                    "距离上次进餐是否已超过1小时？",         // Has it been more than 1 hour since your last meal?
                                                    "距离上次进餐是否已超过1小时30分钟？",   // Has it been more than 1 hour and 30 minutes since your last meal?
                                                    "距离上次进餐是否已超过2小时？"          // Has it been more than 2 hours since your last meal?
                                                });

    //PAGE_CALI_SEELCT_CONFIRM
    fontData[Lan][PAGE_CALI_SELECT_CONFIRM].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_CONFIRM].insert("labelText",QStringList{"请按顺序进行血糖校准"});

    //PAGE_CALI_CONFIRM
    fontData[Lan][PAGE_CALI_CONFIRM].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_CONFIRM].insert("labelText", QStringList{"选择输入或测量"}); // Select input or measure

    //PAGE_CALI_RESULT
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextAdc", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextTemp", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextHeart", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));

    //PAGE_CALI_RESULT_MULTI
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextAdc", QFont(currentFont, instance.pixelToPoint(34), QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextTemp", QFont(currentFont, instance.pixelToPoint(34)));
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextHeart", QFont(currentFont, instance.pixelToPoint(34)));

    //PAGE_CALI_RESULT_MULTI_CONFIRM
    fontData[Lan][PAGE_CALI_RESULT_MULTI_CONFIRM].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_RESULT_MULTI_CONFIRM].insert("labelText",QStringList{"是否要删除所选血糖值\n并重新测量？"});

    //PAGE_RESULT
    fontData[Lan][PAGE_RESULT].insert("labelTextGlucoseValue", QFont(currentFont, instance.pixelToPoint(103), QFont::ExtraBold));

    fontData[Lan][PAGE_RESULT].insert("labelTextMgdl", QFont(currentFont, instance.pixelToPoint(27)));
    textData[Lan][PAGE_RESULT].insert("labelTextMgdl", QStringList{"mg/dL"}); // mg/dL (단위는 변환 없이 사용)

    fontData[Lan][PAGE_RESULT].insert("labelTextTime", QFont(currentFont, instance.pixelToPoint(21), QFont::Bold));
    textData[Lan][PAGE_RESULT].insert("labelTextTime", QStringList{"时间"}); // Time

    fontData[Lan][PAGE_RESULT].insert("labelText", QFont(currentFont, instance.pixelToPoint(36)));

    textData[Lan][PAGE_RESULT].insert("indexResult", QStringList{
                                          "正常",       // Normal
                                          "注意",       // Caution
                                          "注意",       // Caution
                                          "警告",       // Warning
                                          "警告"        // Warning
                                      });
    textData[Lan][PAGE_RESULT].insert("indexResultSub", QStringList{
                                          "血糖值",     // Blood Sugar
                                          "低血糖",     // Low Blood Sugar
                                          "高血糖",     // High Blood Sugar
                                          "低血糖",     // Low Blood Sugar
                                          "高血糖"      // High Blood Sugar
                                      });

    fontData[Lan][PAGE_RESULT].insert("labelProgressBarTooltip", QFont(currentFont, instance.pixelToPoint(16), QFont::Bold));
    textData[Lan][PAGE_RESULT].insert("labelProgressBarTooltip", QStringList{
                                          "正常",       // Normal
                                          "注意",       // Caution
                                          "警告",       // Warning
                                          "错误"        // Error
                                      });

    //PAGE_INIT
    fontData[Lan][PAGE_INIT].insert("labelText", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_INIT].insert("labelText", QStringList{
                                        "恢复出厂设置",   // Factory reset
                                        "重置蓝牙",       // Bluetooth reset
                                        "血糖校准重置"    // Blood sugar calibration reset
                                    });

    //PAGE_INIT_CONFIRM
    fontData[Lan][PAGE_INIT_CONFIRM].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_INIT_CONFIRM].insert("labelText", QStringList{
                                                "系统的所有信息将会被重置\n是否继续进行出厂设置？",   // The entire system information will be reset. Do you want to proceed with factory reset?
                                                "系统初始化后将会重新启动",                 // After system initialization, the system will restart
                                                "蓝牙用户信息将会初始化\n与智能手机的连接将被断开\n是否重置蓝牙？", // Bluetooth user information will be initialized. The connection with the smartphone is disconnected. Would you like to reset Bluetooth?
                                                "蓝牙用户信息已被初始化",                 // Bluetooth user information has been reset
                                                "血糖校正将被重置\n是否重置血糖校正？", // Blood sugar correction will be reset. Do you want to reset blood sugar correction?
                                                "血糖校正已被重置"                       // Blood sugar correction has been reset
                                            });

    //PAGE_THRESHOLD
    fontData[Lan][PAGE_THRESHOLD].insert("labelText", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_THRESHOLD].insert("labelText", QStringList{
                                             "低血糖",    // Low Blood Sugar
                                             "高血糖"     // High Blood Sugar
                                         });

    fontData[Lan][PAGE_THRESHOLD].insert("labelButton", QFont(currentFont, instance.pixelToPoint(22),QFont::Bold));
    textData[Lan][PAGE_THRESHOLD].insert("labelButton", QStringList{"设置"}); // Set

    fontData[Lan][PAGE_THRESHOLD].insert("labelValue", QFont(currentFont, instance.pixelToPoint(48), QFont::Bold));

    fontData[Lan][PAGE_THRESHOLD].insert("labelValueRange",QFont(currentFont,instance.pixelToPoint(26)));
    textData[Lan][PAGE_THRESHOLD].insert("labelValueRange",QStringList{
                                             "以下",
                                             "以上"
                                         });

    //PAGE_SOUND
    fontData[Lan][PAGE_SOUND].insert("labelVolume", QFont(currentFont, instance.pixelToPoint(110), QFont::Bold));

    //PAGE_SLEEP
    fontData[Lan][PAGE_SLEEP].insert("labelText", QFont(currentFont, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][PAGE_SLEEP].insert("labelText", QStringList{
                                         "30秒",    // 30sec
                                         "1分钟",   // 1min
                                         "3分钟",   // 3min
                                         "5分钟",   // 5min
                                         "10分钟",  // 10min
                                         "无"       // None
                                     });

    //PAGE_UPGRADE
    fontData[Lan][PAGE_UPGRADE].insert("labelText", QFont(currentFont, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][PAGE_UPGRADE].insert("labelText", QStringList{"版本"}); // Version

    fontData[Lan][PAGE_UPGRADE].insert("labelTextVersion", QFont(currentFont, instance.pixelToPoint(55)));

    //PAGE_UPGRADE_CONFIRM
    fontData[Lan][PAGE_UPGRADE_CONFIRM].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_UPGRADE_CONFIRM].insert("labelText", QStringList{
                                                   "1. 将设备连接到电脑\n"
                                                   "2. 将bin文件复制到设备\n"
                                                   "3. 文件复制完成后重启设备" // 1. Connect the device to PC, 2. Copy bin file to the device, 3. Restart the device after copying is complete
                                               });

    //PAGE_DEVICEINFO
    fontData[Lan][PAGE_DEVICEINFO].insert("labelTitle", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][PAGE_DEVICEINFO].insert("labelTitle", QStringList{
                                              "蓝牙",      // BLE
                                              "硬件版本",  // H/W ver
                                              "软件版本",  // S/W ver
                                              "序列号"     // Serial
                                          });

    fontData[Lan][PAGE_DEVICEINFO].insert("labelText", QFont(currentFont, instance.pixelToPoint(30)));

    //PAGE_USERINFO
    fontData[Lan][PAGE_USERINFO].insert("labelText", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_USERINFO].insert("labelText", QStringList{
                                            "修改密码",     // Change password
                                            "重置密码", // reset password
                                            "删除血糖记录", // Delete user data
                                            "注销登录"      // Log out
                                        });

    //PAGE_BATPOPUP
    fontData[Lan][PAGE_BATPOPUP].insert("labelText", QFont(currentFont, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][PAGE_BATPOPUP].insert("labelText", QStringList{
                                            "电量不足",             // Low Battery
                                            "请连接充电器"          // Please connect it to the charger
                                        });

    fontData[Lan][PAGE_BATPOPUP].insert("labelTextSub", QFont(currentFont, instance.pixelToPoint(nTextSize)));
    textData[Lan][PAGE_BATPOPUP].insert("labelTextSub", QStringList{
                                            "电量非常低",          // Battery very low
                                            "系统正在关闭"         // The system is shutting down
                                        });

    //PAGE_REVERSE
    fontData[Lan][PAGE_REVERSE].insert("labelTextButton", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_REVERSE].insert("labelTextButton", QStringList{
                                           "左手",  // Left
                                           "右手"   // Right
                                       });

    fontData[Lan][PAGE_REVERSE].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize)));
    textData[Lan][PAGE_REVERSE].insert("labelText", QStringList{
                                           "重启后将进行设置" // Reset will be proceeded
                                       });

    //PAGE_HISTORY
    fontData[Lan][PAGE_HISTORY].insert("labelButton",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][PAGE_HISTORY].insert("labelButton", QStringList{
                                           "+ 7天后",
                                           "今天",
                                           "- 7天前"
                                       });

    //PAGE_ELAPSED_NOTICE_POPUP
    fontData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("labelTitle",QStringList{
                                                        "校准有效期"
                                                    });

    fontData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));

    textData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("elapsedText",QStringList{
                                                        "1天后过期",
                                                        "2天后过期",
                                                        "3天后过期",
                                                        "4天后过期",
                                                        "5天后过期",
                                                        "6天后过期",
                                                        "7天后过期",
                                                        "8天后过期",
                                                        "9天后过期",
                                                        "10天后过期",
                                                        "11天后过期",
                                                        "12天后过期",
                                                        "13天后过期",
                                                        "14天后过期",
                                                        "15天后过期"
                                                    });

    textData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("warningText",QStringList{
                                                        "已过期（无法测量）"
                                                    });

    //PAGE_BLOOD_CHECK
    fontData[Lan][PAGE_BLOOD_CHECK].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_BLOOD_CHECK].insert("labelText",QStringList{
                                               "这是医疗机构测量的值吗？"
                                           });

    //PAGE_BLOOD_NOTICE_POPUP
    fontData[Lan][PAGE_BLOOD_NOTICE_POPUP].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_BLOOD_NOTICE_POPUP].insert("labelText",QStringList{
                                                      "超出测量范围"
                                                  });

    //PAGE_USER_CHECK
    fontData[Lan][PAGE_USER_CHECK].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK].insert("labelText",QStringList{
                                              "糖前期",
                                              "非糖尿病",
                                              "糖尿病"
                                          });
    fontData[Lan][PAGE_USER_CHECK].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK].insert("labelTitle",QStringList{
                                              "选择用户类型"
                                          });

    //PAGE_BLOOD_CHECK_NOTICE //unused
    fontData[Lan][PAGE_BLOOD_CHECK_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_BLOOD_CHECK_NOTICE].insert("labelText",QStringList{
                                                      "没有静脉血信息。\n请填写静脉血数据。"
                                                  });

    //PAGE_CALI_VALUE_NOTICE //unused
    fontData[Lan][PAGE_CALI_VALUE_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_VALUE_NOTICE].insert("labelText",QStringList{
                                                     "超出70〜350范围。\n请输入有效值。"
                                                 });

    //PAGE_USER_NOTICE
    fontData[Lan][PAGE_USER_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_NOTICE].insert("labelText",QStringList{
                                               "本产品适用于未使用药物的\n糖前期患者。"
                                           });

    //PAGE_USER_FINGER
    fontData[Lan][PAGE_USER_FINGER].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_FINGER].insert("labelTitle",QStringList{
                                               "推荐手指周长"
                                           });

    //PAGE_CALI_NOTICE
    fontData[Lan][PAGE_CALI_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_NOTICE].insert("labelText",QStringList{
                                               "要重新校准吗？"
                                           });

    //PAGE_USER_CHECK_NOTICE
    fontData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelText",QStringList{
                                                     "适用用户：无",
                                                     "适用用户：非糖尿病",
                                                     "适用用户：糖前期",
                                                     "适用用户：糖尿病"
                                                 });

    fontData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelCaliDay",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelCaliDay",QStringList{
                                                     "校准完成日期："
                                                 });

    //PAGE_USER_CAUTIONS
    fontData[Lan][PAGE_USER_CAUTIONS].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CAUTIONS].insert("labelTitle",QStringList{
                                                 "HappyZone 注意事项"
                                             });

    fontData[Lan][PAGE_USER_CAUTIONS].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CAUTIONS].insert("labelText",QStringList{
                                                 "1. 保持平稳呼吸",
                                                 "2. 测量过程中请勿说话或移动",
                                                 "3. 请勿对手指施加力量或压力",
                                                 "4. 请确保手指干燥且无异物",
                                                 "5. 请保持手指表面温度在26℃以上",
                                                 "6. 将手指紧贴测量部位并保持水平",
                                                 "7. 使用前请务必断开充电器",
                                                 "8. 请确认使用环境温度 (15–35℃)",
                                             });

    //PAGE_CALI_SELECT_RE
    fontData[Lan][PAGE_CALI_SELECT_RE].insert("labelText",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_RE].insert("labelText",QStringList{
                                                  "示例",
                                                  "空腹 01",
                                                  "空腹 02",
                                                  "餐后 01",
                                                  "餐后 02",
                                                  "餐后 03",
                                              });

    fontData[Lan][PAGE_CALI_SELECT_RE].insert("labelTextValue",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));

    //PAGE_HELP
    fontData[Lan][PAGE_HELP].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_HELP].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_HELP].insert("labelText",QStringList{
                                        "这个产品是什么？", // 0
                                        "这个产品有什么用途？", // 1
                                        "这个产品的优点是什么？", // 2
                                        "任何人都可以使用吗？", // 3
                                        "提供哪些功能？", // 4
                                        "什么情况下适合使用？", // 5
                                        "测量简单吗？", // 6
                                        "测量前有准备步骤吗？", // 7
                                        "什么是血糖校准？", // 8
                                        "血糖校准是必须的吗？", // 9
                                        "血糖校准有周期吗？", // 10
                                        "测量前有注意事项吗？", // 11
                                        "测量过程中有注意事项吗？", // 12
                                        "需要咨询专业医疗人员吗？", // 13
                                        "测量是如何进行的？", // 14
                                        "测量过程是自动的吗？", // 15
                                        "测量需要多长时间？", // 16
                                        "结果如何显示？", // 17
                                        "结果意味着什么？", // 18
                                        "可以调整结果颜色吗？", // 19
                                        "如何利用结果？", // 20
                                        "测量记录会保存吗？", // 21
                                        "测量结果准确吗？", // 22
                                        "测量环境有影响吗？", // 23
                                        "如何保管？", // 24
                                        "防水吗？", // 25
                                        "这个产品的局限性是什么？", // 26
                                        "这个产品用于诊断吗？", // 27
                                        "如何供电？", // 28
                                        "产品使用时间是多少？", // 29
                                        "如何充电？", // 30
                                    });
    fontData[Lan][PAGE_HELP].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_HELP].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));

    //PAGE_FAQ
    fontData[Lan][PAGE_FAQ].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_FAQ].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_FAQ].insert("labelText",QStringList{
                                       "血糖测量有范围吗？", // 0
                                       "在哪里查看血糖结果？", // 1
                                       "值突然偏高或偏低怎么办？", // 2
                                       "为什么需要血糖校准？", // 3
                                       "不进行血糖校准会怎样？", // 4
                                       "血糖校准期限过了还能测量吗？", // 5
                                       "为什么每90天要进行一次血糖校准？", // 6
                                       "测量失败怎么办？", // 7
                                       "可以用其他手指测量吗？", // 8
                                       "手指位置不对怎么办？", // 9
                                       "测量姿势不正确会有影响吗？", // 10
                                       "测量时间不对也可以吗？", // 11
                                       "温度过低或过高会有影响吗？", // 12
                                       "可以用湿手测量吗？", // 13
                                       "运动后立即测量可以吗？", // 14
                                       "产品内部可以有直射阳光吗？", // 15
                                       "孕妇也可以使用吗？", // 16
                                       "糖尿病患者也可以使用吗？", // 17
                                       "透析患者也可以使用吗？", // 18
                                       "测量部位有伤口也可以使用吗？", // 19
                                       "多人可以一起使用吗？", // 20
                                       "没有智能手机也可以使用吗？", // 21
                                       "充电时可以使用吗？", // 22
                                       "电池完全充电需要多长时间？", // 23
                                       "电池性能下降了怎么办？", // 24
                                       "可以用水擦拭吗？", // 25
                                       "可以用清洁剂、酒精、丙酮等擦拭吗？", // 26
                                       "可以便携使用吗？", // 27
                                       "需要使用便携收纳盒吗？", // 28
                                       "可以随身带上飞机吗？", // 29
                                       "可以作为托运行李发送吗？", // 30
                                       "光学传输方式是什么？", // 31
                                       "A/S期限是多少？", // 32
                                   });
    fontData[Lan][PAGE_FAQ].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_FAQ].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));

    //PAGE_ERROR_HELP
    fontData[Lan][PAGE_ERROR_HELP].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_ERROR_HELP].insert("labelText",QStringList{
                                              "经常发生测量失败", // 0
                                              "提示无法识别手指", // 1
                                              "提示手指表面温度低", // 2
                                              "提示测量数据有误", // 3
                                              "提示无法分析测量结果", // 4
                                              "测量过程中可以取消吗？", // 5
                                              "血糖值与平时不同", // 6
                                              "我认为血糖正常但显示警告", // 7
                                              "提示血糖校准有效期已过", // 8
                                              "重置血糖校准会删除以前的记录吗？", // 9
                                              "删除的血糖记录可以恢复吗？", // 10
                                              "无法充电", // 11
                                              "出现电量不足通知怎么办？", // 12
                                              "出现电量不足通知后产品关机了", // 13
                                              "开机后无法进入初始画面", // 14
                                              "提示找不到升级文件", // 15
                                              "提示升级文件有问题", // 16
                                              "提示不是升级文件", // 17
                                              "升级过程中断电了", // 18
                                              "画面卡住或非常慢", // 19
                                              "不知道是什么错误", // 20
                                              "设备出现问题了", // 21
                                              "问题无法解决怎么办？", // 22
                                              "使用产品时有哪些额外耗材？", // 23
                                          });
    fontData[Lan][PAGE_ERROR_HELP].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));

    //PAGE_RESPONSE
    fontData[Lan][PAGE_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_RESPONSE].insert("labelTextHelp",QStringList{
                                            "本产品使用光学系统测量血糖", // 0
                                            "用于测量体内血糖", // 1
                                            "采用非侵入式测量方式，无痛测量是其优点", // 2
                                            "未接受药物治疗的糖尿病前期患者可以使用"
                                            "@本产品按照19至74岁成人标准设计", // 3
                                            "提供血糖测量、血糖记录保存及查看功能", // 4
                                            "建议用于日常血糖变化的确认", // 5
                                            "测量很简单"
                                            "@请按照指引进行测量", // 6
                                            "测量前需要进行血糖校准"
                                            "@请按照指引进行校准", // 7
                                            "指减少实际血糖值与产品之间误差的校准工作", // 8
                                            "是的，测量前必须进行", // 9
                                            "血糖校准必须在校准完成之日起90天内进行"
                                            "@如未进行，将无法测量", // 10
                                            "测量前请清洁双手并去除水分"
                                            "@请从产品上拔下充电器", // 11
                                            "请避免在测量过程中移动或对手指施加强压"
                                            "@如因咳嗽或打喷嚏导致手指移动，请重新测量", // 12
                                            "在以下情况下测量值可能不准确，需要咨询专业医疗人员"
                                            "@未满19岁或75岁以上"
                                            "@受光照部位有皮肤病或伤口"
                                            "@患有多汗症、帕金森病等手部颤抖症状"
                                            "@有严重低血糖、糖尿病酮症酸中毒、癫痫、晕厥、肾上腺疾病病史"
                                            "@正在进行血液透析或腹膜透析"
                                            "@孕妇及哺乳期妇女", // 13
                                            "在主屏幕选择测量时间段后，请按照指引进行", // 14
                                            "按下开始测量按钮后将自动进行直至完成", // 15
                                            "测量时间在1分钟内完成", // 16
                                            "结果在测量完成时以数字显示血糖值", // 17
                                            "颜色含义如下"
                                            "@绿色表示正常"
                                            "@橙色表示注意"
                                            "@红色表示警告", // 18
                                            "可通过血糖范围菜单调整正常颜色范围", // 19
                                            "请在血糖管理时作为参考"
                                            "@显示的数值仅供参考"
                                            "@如需医学判断，请咨询专业医疗人员", // 20
                                            "测量记录最多可在设备中保存90天"
                                            "@90天后的记录将自动删除", // 21
                                            "可能因使用环境条件而有所不同"
                                            "@请按照使用指南使用", // 22
                                            "是的，请避免以下环境"
                                            "@避免阳光直射强烈的地方"
                                            "@避免风大的地方"
                                            "@避免潮湿的环境"
                                            "@避免有振动的环境"
                                            "@避免室内温度过低或过高的地方\n*适宜温度: 10～35℃ (50～95℉)", // 23
                                            "关闭电源，用手指插入口盖封好后，请存放在收纳盒中", // 24
                                            "不防水", // 25
                                            "本产品是用于日常状态确认的设备"
                                            "@不以医疗诊断为目的", // 26
                                            "本产品提供参考用途的信息"
                                            "@不能替代医疗诊断或治疗决定"
                                            "@如需糖尿病诊断及治疗、胰岛素注射等医疗行为，请务必咨询专业医疗人员", // 27
                                            "通过锂离子聚合物电池供电", // 28
                                            "完全充电后，在待机模式下最长可使用约29天", // 29
                                            "使用符合5V DC / 2A～2.4A标准的USB C型充电器充电", // 30
                                        });
    textData[Lan][PAGE_RESPONSE].insert("labelTextFaq",QStringList{
                                            "可在70～350 mg/dL范围内测量", // 0
                                            "当天记录可在主屏幕查看"
                                            "@过去血糖记录请在血糖记录菜单中查看", // 1
                                            "请确认正确的使用环境和测量姿势后重新测量", // 2
                                            "由于个人特征不同，需要将产品特性调整到个人", // 3
                                            "不进行血糖校准将无法测量", // 4
                                            "超过期限将无法测量，请重新进行血糖校准", // 5
                                            "为确保准确测量，每90天需要重新进行校准", // 6
                                            "测量失败时，会弹出显示失败原因的通知窗口"
                                            "@请在故障排除菜单中查看测量失败问题", // 7
                                            "为确保准确测量，建议使用进行了校准的手指进行测量", // 8
                                            "无法准确测量"
                                            "@为确保准确测量，请放松手指，使手指中央轻轻盖住传感器窗口末端", // 9
                                            "测量姿势不正确可能导致测量不准确"
                                            "@请以正确姿势进行测量以确保准确性", // 10
                                            "不会影响测量结果"
                                            "@但如果计划将其用作血糖管理数据，建议在相应时间进行测量", // 11
                                            "温度过低或过高时，测量值可能不准确", // 12
                                            "请勿用湿手测量"
                                            "@可能导致产品故障", // 13
                                            "请勿在运动后立即测量"
                                            "@请在呼吸和心率稳定后测量", // 14
                                            "无法准确测量"
                                            "@为确保准确测量，请在没有阳光直射的室内测量", // 15
                                            "测量结果可能不准确"
                                            "@请咨询专业医疗人员", // 16
                                            "测量结果可能不准确"
                                            "@请咨询专业医疗人员", // 17
                                            "测量结果可能不准确"
                                            "@请咨询专业医疗人员", // 18
                                            "测量结果可能不准确"
                                            "@请咨询专业医疗人员", // 19
                                            "最多支持2名用户同时使用", // 20
                                            "产品可单独使用", // 21
                                            "请务必拔下充电器后使用", // 22
                                            "完全充电约需3小时45分钟", // 23
                                            "请联系A/S中心检查，必要时更换", // 24
                                            "请勿用水擦拭"
                                            "@可能导致产品故障", // 25
                                            "请勿用清洁剂、酒精、丙酮等擦拭"
                                            "@可能导致产品故障", // 26
                                            "是的，请携带使用"
                                            "@请在适合测量的室内环境中使用", // 27
                                            "外部冲击可能导致误操作或故障，请放入便携收纳盒中携带", // 28
                                            "可在飞机客舱内携带和使用"
                                            "@无法作为行李托运", // 29
                                            "无法作为行李托运"
                                            "@本产品内置锂离子聚合物电池，根据安全规定不能作为托运行李发送"
                                            "@请务必作为随身行李携带", // 30
                                            "通过分析穿过手指的光来测量血糖", // 31
                                            "官方A/S期限为购买产品后24个月", // 32
                                        });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp",QStringList{
                                                  "请确认以下测量环境后重新测量"
                                                  "@测量过程中请勿咳嗽、打喷嚏、说话，不要移动"
                                                  "@放松手指，水平贴紧"
                                                  "@请保持手指表面温度26℃(79℉)以上"
                                                  "@请去除手指的水分和异物", // 0
                                                  "请确认手指是否正确插入后重新测量"
                                                  "@为确保准确测量，请放松手指，使手指中央轻轻盖住传感器窗口末端", // 1
                                                  "请充分温暖手指后重新测量", // 2
                                                  "当测量数据不完整或检测到无法分析的值时发生"
                                                  "@请避免手抖、打喷嚏、说话", // 3
                                                  "当测量血糖值的偏差超过范围时发生"
                                                  "@请确认手指测量位置和测量环境后重新测量", // 4
                                                  "测量中按下\"取消\"按钮将停止测量", // 5
                                                  "请确认测量环境后重新测量"
                                                  "@如果测量环境没有影响，请确认以下内容"
                                                  "@请确认是否有低血糖或高血糖症状"
                                                  "@如果持续怀疑不准确，请咨询专业医疗人员", // 6
                                                  "请在血糖范围菜单中确认并调整正常范围", // 7
                                                  "血糖校准有效期（90天）到期时无法测量"
                                                  "@请进行血糖校准", // 8
                                                  "即使初始化，记录也不会被删除", // 9
                                                  "无法恢复"
                                                  "删除血糖记录时请注意", // 10
                                                  "请确认是否为额定电池充电器"
                                                  "@使用额定电池充电器仍无法充电时，请联系A/S中心", // 11
                                                  "请使用充电器充电", // 12
                                                  "电池低于5%时，为保护系统，产品将在5秒后关机"
                                                  "@请使用充电器充电", // 13
                                                  "请使用额定电池充电器为电池充电"
                                                  "@充电完成后重新开机，启动完成后即可正常使用", // 14
                                                  "请重新确认升级文件", // 15
                                                  "请重新下载升级文件后再试", // 16
                                                  "请确认文件是否正确后再试", // 17
                                                  "请充电后再试"
                                                  "@充电后仍发生相同现象时，请联系A/S中心", // 18
                                                  "请使用针按下重置按钮"
                                                  "@充电后仍发生相同现象时，请联系A/S中心", // 19
                                                  "请先重新启动产品，确认是否发生相同错误"
                                                  "@或将产品软件版本升级到最新版本"
                                                  "@如发生相同现象，请联系A/S中心", // 20
                                                  "其他产品发生问题的情况"
                                                  "@请尝试重新启动和更新"
                                                  "@如发生相同现象，请联系A/S中心", // 21
                                                  "请联系A/S中心", // 22
                                                  "没有额外消耗品", // 23
                                              });
    fontData[Lan][PAGE_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_RESPONSE].insert("labelPageNum",QFont(currentFont,instance.pixelToPoint(28)));

    //=====================================================================================================================================
    //TC
    Lan = TC;
    nTextSize = 36;
    currentFont = instance.fontTC;

    //PAGE_TRANS
    fontData[Lan][PAGE_TRANS].insert("fontSuit",QFont(instance.fontSuit,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_TRANS].insert("fontJP",QFont(instance.fontJP,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_TRANS].insert("fontSC",QFont(instance.fontSC,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_TRANS].insert("fontTC",QFont(instance.fontTC,instance.pixelToPoint(36)));

    textData[Lan][PAGE_TRANS].insert("lang",QStringList{
                                         "한국어",
                                         "ENGLISH",
                                         "日本語",
                                         "繁體中文",
                                         "简体中文",
                                         "ESPAÑOL"
                                     });

    //CUSTOM_BUTTON
    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonOK", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonOK", QStringList{"確認"}); // OK

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel", QStringList{"取消"}); // Cancel

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonHome", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonHome", QStringList{"主頁"}); // Home

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart", QStringList{"開始"}); // Start

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasure", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasure", QStringList{"測量"}); // Measure

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonInput", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonInput", QStringList{"輸入"}); // Input

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe", QStringList{"重新測量"}); // Remeasure

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonSave", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonSave", QStringList{"保存"}); // Save

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonUpgrade", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonUpgrade", QStringList{"軟體升級"}); // Software Upgrade

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QStringList{"是"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QStringList{"否"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QStringList{
                                            "한국어",
                                            "ENGLISH",
                                            "日本語",
                                            "繁體中文",
                                            "简体中文",
                                            "ESPAÑOL"
                                        });

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonBack", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonBack", QStringList{"返回"});

    //CUSTOM_COMPONENT
    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextValue", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextResult", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextResult", QStringList{
                                               "測量成功",                            // 0
                                               "未偵測到手指\n請重新測量",               // 1
                                               "設備錯誤\n請聯繫客服",                   // 2
                                               "設備錯誤\n請聯繫客服",                   // 3
                                               "分析失敗\n請重新測量",                   // 4
                                               "數據錯誤\n請重新測量",                   // 5
                                               "充電中無法測量\n請拔除充電器後再試",       // 6
                                               "因手指溫度過低，\n無法測量",               // 7
                                               "測量失敗\n請聯繫客服"                    // 8
                                           });

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QFont(currentFont, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QStringList{
                                               "升級成功", // 0
                                               "升級失敗\n請聯繫客服", // 1
                                               "找不到升級檔案\n請重新檢查檔案", // 2
                                               "升級檔案有問題\n請使用新檔案重試", // 3
                                               "此檔案不是有效的升級檔案\n請確認是否正確", // 4
                                               "升級失敗\n請聯繫客服" // 5
                                           });


    //CUSTOM_COMPONENT_DATE
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelText", QFont(currentFont, instance.pixelToPoint(50)));
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelTextSelect", QFont(currentFont, instance.pixelToPoint(50), QFont::Bold));
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelTextSub", QFont(currentFont, instance.pixelToPoint(40)));

    //PAGE_PASSWORD
    fontData[Lan][PAGE_PASSWORD].insert("labelButtonNum", QFont(currentFont, instance.pixelToPoint(44), QFont::Bold));

    fontData[Lan][PAGE_PASSWORD].insert("labelTitle", QFont(currentFont, instance.pixelToPoint(40), QFont::Bold));
    textData[Lan][PAGE_PASSWORD].insert("labelTitle", QStringList{
                                            "請登入",        // Please log in
                                            "修改密碼",      // Edit Password
                                            "刪除用戶",      // Delete User
                                            "密碼確認",      // Password Confirmation
                                            "密碼重新確認",  // Password Re-confirmation
                                            "PASSWORD_MAX"
                                        });

    fontData[Lan][PAGE_PASSWORD].insert("labelTitleSub", QFont(currentFont, instance.pixelToPoint(30)));
    textData[Lan][PAGE_PASSWORD].insert("labelTitleSub", QStringList{
                                            "請輸入您的4位數密碼",   // Please enter your 4-digit password
                                            "請輸入要修改的4位數字", // Please enter the 4 digits to modify
                                            "請再次輸入您的4位數密碼", // Please enter your 4-digit password again
                                            "請輸入4位數密碼以確認",   // Please confirm by entering 4 digits
                                            "請重新輸入4位數密碼以驗證", // Please re-enter the 4 digits to verify
                                            "請輸入您的目前密碼",
                                            "PASSWORD_MAX"
                                        });

    fontData[Lan][PAGE_PASSWORD].insert("labelButtonOKText", QFont(currentFont, instance.pixelToPoint(29)));
    textData[Lan][PAGE_PASSWORD].insert("labelButtonOKText", QStringList{"確認"}); // OK

    fontData[Lan][PAGE_PASSWORD].insert("labelButtonCancelText", QFont(currentFont, instance.pixelToPoint(29)));
    textData[Lan][PAGE_PASSWORD].insert("labelButtonCancelText", QStringList{"取消"}); // Cancel

    //PAGE_SELECT_USER
    fontData[Lan][PAGE_SELECT_USER].insert("labelTitle", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_SELECT_USER].insert("labelTitle", QStringList{"請選擇使用者"});

    fontData[Lan][PAGE_SELECT_USER].insert("labelUserText", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_SELECT_USER].insert("labelUserText", QStringList{"使用者1", "使用者2"});

    //PAGE_PASSWORD_ALLCHAT
    fontData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelButtonNum", QFont(currentFont, instance.pixelToPoint(44)));

    fontData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitle", QFont(currentFont, instance.pixelToPoint(40), QFont::Bold));
    textData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitle", QStringList{
                                                    "請登入",
                                                    "變更密碼",
                                                    "刪除血糖記錄", //"刪除使用者",
                                                    "確認密碼",
                                                    "再次確認密碼",
                                                    "重設密碼",
                                                    "PASSWORD_MAX"
                                                });

    fontData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitleSub", QFont(currentFont, instance.pixelToPoint(30)));
    textData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitleSub", QStringList{
                                                    "請輸入密碼",
                                                    "請輸入新密碼",
                                                    "請輸入密碼",
                                                    "請輸入確認密碼",
                                                    "請再次輸入密碼",
                                                    "請輸入目前的密碼",
                                                    "PASSWORD_MAX"
                                                });

    //PAGE_PASSWORD_CONFIRM
    fontData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTitle", QFont(currentFont, instance.pixelToPoint(40), QFont::Bold));
    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTitle", QStringList{
                                                    "登入",          // Login (PASSWORD_STR_LOGIN_SUCCESS)
                                                    "登入",          // Login (PASSWORD_STR_LOGIN_FAIL)
                                                    "登入",          // Login (PASSWORD_STR_LOGIN_CHANGE)
                                                    "身份驗證",       // Id Check
                                                    "身份驗證",       // Id Check (PASSWORD_STR_CONFIRM_FAIL)
                                                    "密碼驗證",       // PW Check
                                                    "密碼驗證",       // PW Check (PASSWORD_STR_REPEAT_FAIL)
                                                    "修改密碼",       // PW Change
                                                    "修改密碼",       // PW Change (PASSWORD_STR_EDIT_CONFIRM)
                                                    "修改密碼",       // PW Change (PASSWORD_STR_EDIT_CHANGE)
                                                    "修改密碼",       // PW Change (PASSWORD_STR_EDIT_SUCCESS)
                                                    "刪除血糖記錄",          // PASSWORD_STR_DELETE
                                                    "刪除血糖記錄確認",      // PASSWORD_STR_DELETE_CONFIRM
                                                    "血糖記錄刪除完成",      // PASSWORD_STR_DELETE_SUCCESS
                                                    "登出",          // Logout
                                                    "重設密碼",    // PASSWORD_STR_INIT
                                                    "重設密碼",    // PASSWORD_STR_INIT_CONFIRM
                                                    "重設密碼",    // PASSWORD_STR_SUCCESS
                                                    "PASSWORD_STR_MAX"
                                                });

    fontData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelText", QStringList{
                                                    "登入成功",
                                                    "登入失敗",
                                                    "請修改您的密碼",
                                                    "請輸入密碼以進行驗證",
                                                    "密碼不一致",
                                                    "請再次輸入您的密碼以確認",
                                                    "輸入的密碼與之前的密碼不一致",
                                                    "是否修改您的密碼？",
                                                    "請輸入密碼以進行驗證",
                                                    "請輸入新密碼\n\n至少包含8個字元、數字、字母和符號（例如：.,?!）",
                                                    "密碼修改完成，請重新登入",
                                                    "是否刪除血糖記錄？", // PASSWORD_STR_DELETE
                                                    "刪除後將無法恢復記錄", // PASSWORD_STR_DELETE_CONFIRM
                                                    "血糖記錄已刪除", // PASSWORD_STR_DELETE_SUCCESS
                                                    "正在登出",
                                                    "您要重設密碼嗎？",
                                                    "重設後，密碼將恢復為\n預設值",
                                                    "密碼已重設",
                                                    "PASSWORD_STR_MAX"
                                                });

    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTextError", QStringList{
                                                    "密碼已設定",
                                                    "密碼長度必須為\n8到12個字元",
                                                    "密碼必須包含\n至少一個數字",
                                                    "密碼必須包含\n至少一個字母（A-Z）",
                                                    "密碼必須包含\n至少一個符號（例如：.,?!）",
                                                    "兩次輸入的密碼不一致",
                                                    "此密码不被允许使用",
                                                    "發生未知錯誤",
                                                });

    //PAGE_HOME
    fontData[Lan][PAGE_HOME].insert("labelTextStatus", QFont(currentFont, instance.pixelToPoint(26), QFont::Bold));
    textData[Lan][PAGE_HOME].insert("labelTextStatus", QStringList{
                                        "起床",           // Wake Up
                                        "早餐前",         // Before Breakfast
                                        "早餐後",         // After Breakfast
                                        "午餐前",         // Before Lunch
                                        "午餐後",         // After Lunch
                                        "晚餐前",         // Before Dinner
                                        "晚餐後",         // After Dinner
                                        "就寢"           // Bed Time
                                    });

    fontData[Lan][PAGE_HOME].insert("labelButtonText", QFont(currentFont, instance.pixelToPoint(62), QFont::ExtraBold));

    //PAGE_SELECT
    fontData[Lan][PAGE_SELECT].insert("labelTextStatus", QFont(currentFont, instance.pixelToPoint(42), QFont::ExtraBold));
    textData[Lan][PAGE_SELECT].insert("labelTextStatus", QStringList{
                                          "起床",           // Wake Up
                                          "早餐前",         // Before Breakfast
                                          "早餐後",         // After Breakfast
                                          "午餐前",         // Before Lunch
                                          "午餐後",         // After Lunch
                                          "晚餐前",         // Before Dinner
                                          "晚餐後",         // After Dinner
                                          "就寢"           // Bed Time
                                      });
    fontData[Lan][PAGE_SELECT].insert("labelTextStatusSub", QFont(currentFont, instance.pixelToPoint(24)));
    textData[Lan][PAGE_SELECT].insert("labelTextStatusSub", QStringList{"請開始測量"}); // Please start the measurement

    fontData[Lan][PAGE_SELECT].insert("labelTextStatusValue", QFont(currentFont, instance.pixelToPoint(40), QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextGlucoseValue", QFont(currentFont, instance.pixelToPoint(130), QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextMgdl", QFont(currentFont, instance.pixelToPoint(34), QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextResult", QFont(currentFont, instance.pixelToPoint(32)));
    textData[Lan][PAGE_SELECT].insert("labelTextResult", QStringList{
                                          "正常",           // Normal
                                          "注意",           // Caution
                                          "注意",           // Caution
                                          "警告",           // Warning
                                          "警告"            // Warning
                                      });

    textData[Lan][PAGE_SELECT].insert("labelTextResultSub", QStringList{
                                          "血糖值",         // Blood Sugar
                                          "低血糖",         // Low Blood Sugar
                                          "高血糖",         // High Blood Sugar
                                          "低血糖",         // Low Blood Sugar
                                          "高血糖"          // High Blood Sugar
                                      });

    fontData[Lan][PAGE_SELECT].insert("labelTextTime", QFont(currentFont, instance.pixelToPoint(21), QFont::Bold));
    textData[Lan][PAGE_SELECT].insert("labelTextTime", QStringList{"時間"}); // Time

    fontData[Lan][PAGE_SELECT].insert("labelTextIcon", QFont(currentFont, instance.pixelToPoint(23), QFont::Bold));
    textData[Lan][PAGE_SELECT].insert("labelTextIcon", QStringList{"正常", "低", "高", "低", "高"}); // Normal, Low, High

    //PAGE_MENU
    fontData[Lan][PAGE_MENU].insert("labelButtonText", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][PAGE_MENU].insert("labelButtonText", QStringList{
                                        "校準",           // Calibration
                                        "範圍",           // Range
                                        "列表",           // List
                                        "音量",           // Sound
                                        "休眠",           // Sleep
                                        "切換",           // Switch
                                        "日期",           // Date
                                        "顏色模式",       // Color Mode
                                        "語言",           // Language
                                        "升級",           // Upgrade
                                        "設備資訊",       // Device Info
                                        "重置",           // Reset
                                        "用戶",            // User
                                        "說明",           // help
                                        "常見問題",        // faq
                                        "錯誤說明",        // error help
                                    });

    //PAGE_CALI_CHECK
    fontData[Lan][PAGE_CALI_CHECK].insert("labelTextCheck", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_CHECK].insert("labelTextCheck", QStringList{
                                              "校準階段\n請將手指放入裝置", // Calibration phase. Please insert your finger
                                              "校準完成\n是否再次進行？"    // Calibration complete. Do you want to proceed again?
                                          });

    //PAGE_CALI_GAIN_CONFIRM
    fontData[Lan][PAGE_CALI_GAIN_CONFIRM].insert("labelTextGainConfirm", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_GAIN_CONFIRM].insert("labelTextGainConfirm", QStringList{
                                                     "LED感應調整階段\n請勿移動手指", // LED sensitivity adjustment step. Please do not move your finger
                                                     "LED感應調整完成"                // LED sensitivity adjustment has been completed
                                                 });

    //PAGE_GRAPH
    fontData[Lan][PAGE_GRAPH].insert("labelProgressText", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][PAGE_GRAPH].insert("labelProgressText", QStringList{"完成"}); // Completed

    fontData[Lan][PAGE_GRAPH].insert("labelProgressValue", QFont(currentFont, instance.pixelToPoint(60), QFont::Bold));
    fontData[Lan][PAGE_GRAPH].insert("labelProgressPercent", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));

    fontData[Lan][PAGE_GRAPH].insert("labelAdcText", QFont(currentFont, instance.pixelToPoint(20)));
    textData[Lan][PAGE_GRAPH].insert("labelAdcText", QStringList{"A:"});

    fontData[Lan][PAGE_GRAPH].insert("labelLoading", QFont(currentFont, instance.pixelToPoint(48), QFont::Bold));
    textData[Lan][PAGE_GRAPH].insert("labelLoading", QStringList{"分析中"}); // Analyzing

    //Page_CALI_GAIN_RESULT
    fontData[Lan][PAGE_CALI_GAIN_RESULT].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_GAIN_RESULT].insert("labelText", QStringList{
                                                    "LED感應調整完成\n請進入下一步測量", // LED sensitivity adjustment is complete. Proceed to the next measurement step
                                                    "LED感應調整失敗\n請重新測量"        // LED sensitivity adjustment failed. Please measure again
                                                });

    //PAGE_CALI_SELECT
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectText", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT].insert("labelSelectText", QStringList{
                                               "空腹",  // Empty stomach
                                               "飯後"   // After meal
                                           });

    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextAdc", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextValue", QFont(currentFont, instance.pixelToPoint(36)));

    //PAGE_CALI_SELECT_INFO
    fontData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText", QStringList{
                                                    "空腹時間是否已超過8小時？\n每隔30分鐘測量2次（01）",//"距離上次進餐是否已超過8小時？",           // Has it been more than 8 hours since your last meal?
                                                    "空腹時間是否已超過8小時？\n每隔30分鐘測量2次（02）",
                                                    "距離上次進餐是否已超過1小時？",           // Has it been more than 1 hour since your last meal?
                                                    "距離上次進餐是否已超過1小時30分鐘？",    // Has it been more than 1 hour and 30 minutes since your last meal?
                                                    "距離上次進餐是否已超過2小時？"            // Has it been more than 2 hours since your last meal?
                                                });

    //PAGE_CALI_SEELCT_CONFIRM
    fontData[Lan][PAGE_CALI_SELECT_CONFIRM].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_CONFIRM].insert("labelText",QStringList{"請依序進行血糖校正"});

    //PAGE_CALI_CONFIRM
    fontData[Lan][PAGE_CALI_CONFIRM].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_CONFIRM].insert("labelText", QStringList{"選擇輸入或測量"}); // Select input or measure

    //PAGE_CALI_RESULT
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextAdc", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextTemp", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextHeart", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));

    //PAGE_CALI_RESULT_MULTI
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextAdc", QFont(currentFont, instance.pixelToPoint(34), QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextTemp", QFont(currentFont, instance.pixelToPoint(34)));
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextHeart", QFont(currentFont, instance.pixelToPoint(34)));

    //PAGE_CALI_RESULT_MULTI_CONFIRM
    fontData[Lan][PAGE_CALI_RESULT_MULTI_CONFIRM].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_RESULT_MULTI_CONFIRM].insert("labelText",QStringList{"是否要刪除所選血糖值\n並重新測量？"});

    //PAGE_RESULT
    fontData[Lan][PAGE_RESULT].insert("labelTextGlucoseValue", QFont(currentFont, instance.pixelToPoint(103), QFont::ExtraBold));

    fontData[Lan][PAGE_RESULT].insert("labelTextMgdl", QFont(currentFont, instance.pixelToPoint(27)));
    textData[Lan][PAGE_RESULT].insert("labelTextMgdl", QStringList{"mg/dL"}); // 단위는 번역하지 않음

    fontData[Lan][PAGE_RESULT].insert("labelTextTime", QFont(currentFont, instance.pixelToPoint(21), QFont::Bold));
    textData[Lan][PAGE_RESULT].insert("labelTextTime", QStringList{"時間"}); // Time

    fontData[Lan][PAGE_RESULT].insert("labelText", QFont(currentFont, instance.pixelToPoint(36)));

    textData[Lan][PAGE_RESULT].insert("indexResult", QStringList{
                                          "正常",      // Normal
                                          "注意",      // Caution
                                          "注意",      // Caution
                                          "警告",      // Warning
                                          "警告"       // Warning
                                      });

    textData[Lan][PAGE_RESULT].insert("indexResultSub", QStringList{
                                          "血糖值",    // Blood Sugar
                                          "低血糖",    // Low Blood Sugar
                                          "高血糖",    // High Blood Sugar
                                          "低血糖",    // Low Blood Sugar
                                          "高血糖"     // High Blood Sugar
                                      });

    fontData[Lan][PAGE_RESULT].insert("labelProgressBarTooltip", QFont(currentFont, instance.pixelToPoint(16), QFont::Bold));
    textData[Lan][PAGE_RESULT].insert("labelProgressBarTooltip", QStringList{
                                          "正常",      // Normal
                                          "注意",      // Caution
                                          "警告",      // Warning
                                          "錯誤"       // Error
                                      });

    //PAGE_INIT
    fontData[Lan][PAGE_INIT].insert("labelText", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_INIT].insert("labelText", QStringList{
                                        "出廠重置",      // Factory reset
                                        "藍牙重置",      // Bluetooth reset
                                        "血糖校準重置"   // Blood sugar calibration reset
                                    });

    //PAGE_INIT_CONFIRM
    fontData[Lan][PAGE_INIT_CONFIRM].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_INIT_CONFIRM].insert("labelText", QStringList{
                                                "整個系統資訊將被重置\n是否繼續執行出廠重置？", // The entire system information will be reset. Do you want to proceed with factory reset?
                                                "系統初始化後，\n系統將重新啟動",            // After system initialization, the system will restart
                                                "藍牙用戶資訊將被初始化\n與智能手機的連接將被斷開\n是否重置藍牙？", // Bluetooth user information will be initialized. The connection with the smartphone is disconnected. Would you like to reset Bluetooth?
                                                "藍牙用戶資訊已被重置",                      // Bluetooth user information has been reset
                                                "血糖校正將被重置\n是否重置血糖校正？",      // Blood sugar correction will be reset. Do you want to reset blood sugar correction?
                                                "血糖校正已被重置"                           // Blood sugar correction has been reset
                                            });

    //PAGE_THRESHOLD
    fontData[Lan][PAGE_THRESHOLD].insert("labelText", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_THRESHOLD].insert("labelText", QStringList{
                                             "低血糖", // Low Blood Sugar
                                             "高血糖"  // High Blood Sugar
                                         });

    fontData[Lan][PAGE_THRESHOLD].insert("labelButton", QFont(currentFont, instance.pixelToPoint(22),QFont::Bold));
    textData[Lan][PAGE_THRESHOLD].insert("labelButton", QStringList{"設定"}); // Set

    fontData[Lan][PAGE_THRESHOLD].insert("labelValue", QFont(currentFont, instance.pixelToPoint(48), QFont::Bold));

    fontData[Lan][PAGE_THRESHOLD].insert("labelValueRange",QFont(currentFont,instance.pixelToPoint(26)));
    textData[Lan][PAGE_THRESHOLD].insert("labelValueRange",QStringList{
                                             "以下",
                                             "以上"
                                         });

    //PAGE_SOUND
    fontData[Lan][PAGE_SOUND].insert("labelVolume", QFont(currentFont, instance.pixelToPoint(110), QFont::Bold));

    //PAGE_SLEEP
    fontData[Lan][PAGE_SLEEP].insert("labelText", QFont(currentFont, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][PAGE_SLEEP].insert("labelText", QStringList{
                                         "30秒",  // 30sec
                                         "1分鐘", // 1min
                                         "3分鐘", // 3min
                                         "5分鐘", // 5min
                                         "10分鐘", // 10min
                                         "無"     // None
                                     });

    //PAGE_UPGRADE
    fontData[Lan][PAGE_UPGRADE].insert("labelText", QFont(currentFont, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][PAGE_UPGRADE].insert("labelText", QStringList{"版本"}); // Version

    fontData[Lan][PAGE_UPGRADE].insert("labelTextVersion", QFont(currentFont, instance.pixelToPoint(55)));

    //PAGE_UPGRADE_CONFIRM
    fontData[Lan][PAGE_UPGRADE_CONFIRM].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_UPGRADE_CONFIRM].insert("labelText", QStringList{
                                                   "1. 將裝置連接至電腦\n"       // 1. Connect the device to PC
                                                   "2. 將bin檔案複製到裝置\n"    // 2. Copy bin file to the device
                                                   "3. 複製完成後重新啟動裝置"    // 3. Restart the device after copying is complete
                                               });

    //PAGE_DEVICEINFO
    fontData[Lan][PAGE_DEVICEINFO].insert("labelTitle", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][PAGE_DEVICEINFO].insert("labelTitle", QStringList{
                                              "藍牙",       // BLE
                                              "硬體版本",    // H/W ver
                                              "軟體版本",    // S/W ver
                                              "序號"        // Serial
                                          });

    fontData[Lan][PAGE_DEVICEINFO].insert("labelText", QFont(currentFont, instance.pixelToPoint(30)));

    //PAGE_USERINFO
    fontData[Lan][PAGE_USERINFO].insert("labelText", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_USERINFO].insert("labelText", QStringList{
                                            "更改密碼",    // Change password
                                            "重設密碼", // reset password
                                            "刪除血糖記錄", // Delete user data
                                            "登出"         // Log out
                                        });

    //PAGE_BATPOPUP
    fontData[Lan][PAGE_BATPOPUP].insert("labelText", QFont(currentFont, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][PAGE_BATPOPUP].insert("labelText", QStringList{
                                            "電池電量低",         // Low Battery
                                            "請連接充電器"         // Please connect it to the charger
                                        });

    fontData[Lan][PAGE_BATPOPUP].insert("labelTextSub", QFont(currentFont, instance.pixelToPoint(nTextSize)));
    textData[Lan][PAGE_BATPOPUP].insert("labelTextSub", QStringList{
                                            "電池電量極低",         // Battery very low
                                            "系統即將關機"         // The system is shutting down
                                        });

    //PAGE_REVERSE
    fontData[Lan][PAGE_REVERSE].insert("labelTextButton", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_REVERSE].insert("labelTextButton", QStringList{
                                           "左手",     // Left
                                           "右手"      // Right
                                       });

    fontData[Lan][PAGE_REVERSE].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize)));
    textData[Lan][PAGE_REVERSE].insert("labelText", QStringList{
                                           "重启后将继续进行"       // Reset will be proceeded
                                       });


    //PAGE_HISTORY
    fontData[Lan][PAGE_HISTORY].insert("labelButton",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][PAGE_HISTORY].insert("labelButton", QStringList{
                                           "+ 7天後",
                                           "今天",
                                           "- 7天前"
                                       });

    //PAGE_ELAPSED_NOTICE_POPUP
    fontData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("labelTitle",QStringList{
                                                        "校正有效期限"
                                                    });

    fontData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));

    textData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("elapsedText",QStringList{
                                                        "1天後到期",
                                                        "2天後到期",
                                                        "3天後到期",
                                                        "4天後到期",
                                                        "5天後到期",
                                                        "6天後到期",
                                                        "7天後到期",
                                                        "8天後到期",
                                                        "9天後到期",
                                                        "10天後到期",
                                                        "11天後到期",
                                                        "12天後到期",
                                                        "13天後到期",
                                                        "14天後到期",
                                                        "15天後到期"
                                                    });

    textData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("warningText",QStringList{
                                                        "已到期（無法測量）"
                                                    });

    //PAGE_BLOOD_CHECK
    fontData[Lan][PAGE_BLOOD_CHECK].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_BLOOD_CHECK].insert("labelText",QStringList{
                                               "此為醫療機構測量的數值嗎？"
                                           });

    //PAGE_BLOOD_NOTICE_POPUP
    fontData[Lan][PAGE_BLOOD_NOTICE_POPUP].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_BLOOD_NOTICE_POPUP].insert("labelText",QStringList{
                                                      "超出測量範圍"
                                                  });

    //PAGE_USER_CHECK
    fontData[Lan][PAGE_USER_CHECK].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK].insert("labelText",QStringList{
                                              "糖尿病前期",
                                              "非糖尿病",
                                              "糖尿病"
                                          });
    fontData[Lan][PAGE_USER_CHECK].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK].insert("labelTitle",QStringList{
                                              "選擇使用者類型"
                                          });

    //PAGE_BLOOD_CHECK_NOTICE //unused
    fontData[Lan][PAGE_BLOOD_CHECK_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_BLOOD_CHECK_NOTICE].insert("labelText",QStringList{
                                                      "沒有靜脈血資訊。\n請輸入靜脈血資料。"
                                                  });

    //PAGE_CALI_VALUE_NOTICE //unused
    fontData[Lan][PAGE_CALI_VALUE_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_VALUE_NOTICE].insert("labelText",QStringList{
                                                     "超出70〜350範圍。\n請輸入有效數值。"
                                                 });

    //PAGE_USER_NOTICE
    fontData[Lan][PAGE_USER_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_NOTICE].insert("labelText",QStringList{
                                               "本產品適用於未使用藥物的\n糖尿病前期患者。"
                                           });

    //PAGE_USER_FINGER
    fontData[Lan][PAGE_USER_FINGER].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_FINGER].insert("labelTitle",QStringList{
                                               "建議手指周長"
                                           });

    //PAGE_CALI_NOTICE
    fontData[Lan][PAGE_CALI_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_NOTICE].insert("labelText",QStringList{
                                               "要進行重新校正嗎？"
                                           });

    //PAGE_USER_CHECK_NOTICE
    fontData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelText",QStringList{
                                                     "適用對象：無",
                                                     "適用對象：非糖尿病",
                                                     "適用對象：糖尿病前期",
                                                     "適用對象：糖尿病"
                                                 });

    fontData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelCaliDay",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelCaliDay",QStringList{
                                                     "校正完成日期："
                                                 });

    //PAGE_USER_CAUTIONS
    fontData[Lan][PAGE_USER_CAUTIONS].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CAUTIONS].insert("labelTitle",QStringList{
                                                 "HappyZone 注意事項"
                                             });

    fontData[Lan][PAGE_USER_CAUTIONS].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CAUTIONS].insert("labelText",QStringList{
                                                 "1. 保持平穩呼吸",
                                                 "2. 測量過程中請勿說話或移動",
                                                 "3. 請勿對手指施加力量或壓力",
                                                 "4. 請確保手指乾燥且無異物",
                                                 "5. 請保持手指表面溫度在26℃以上",
                                                 "6. 將手指緊貼測量部位並保持水平",
                                                 "7. 使用前請務必拔除充電器",
                                                 "8. 請確認使用環境溫度 (15–35℃)",
                                             });

    //PAGE_CALI_SELECT_RE
    fontData[Lan][PAGE_CALI_SELECT_RE].insert("labelText",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_RE].insert("labelText",QStringList{
                                                  "範例",
                                                  "空腹 01",
                                                  "空腹 02",
                                                  "餐後 01",
                                                  "餐後 02",
                                                  "餐後 03",
                                              });

    fontData[Lan][PAGE_CALI_SELECT_RE].insert("labelTextValue",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));

    //PAGE_HELP
    fontData[Lan][PAGE_HELP].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_HELP].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_HELP].insert("labelText",QStringList{
                                        "這個產品是什麼？", // 0
                                        "這個產品有什麼用途？", // 1
                                        "這個產品的優點是什麼？", // 2
                                        "任何人都可以使用嗎？", // 3
                                        "提供哪些功能？", // 4
                                        "什麼情況下適合使用？", // 5
                                        "測量簡單嗎？", // 6
                                        "測量前有準備步驟嗎？", // 7
                                        "什麼是血糖校準？", // 8
                                        "血糖校準是必須的嗎？", // 9
                                        "血糖校準有周期嗎？", // 10
                                        "測量前有注意事項嗎？", // 11
                                        "測量過程中有注意事項嗎？", // 12
                                        "需要諮詢專業醫療人員嗎？", // 13
                                        "測量是如何進行的？", // 14
                                        "測量過程是自動的嗎？", // 15
                                        "測量需要多長時間？", // 16
                                        "結果如何顯示？", // 17
                                        "結果意味著什麼？", // 18
                                        "可以調整結果顏色嗎？", // 19
                                        "如何利用結果？", // 20
                                        "測量記錄會保存嗎？", // 21
                                        "測量結果準確嗎？", // 22
                                        "測量環境有影響嗎？", // 23
                                        "如何保管？", // 24
                                        "防水嗎？", // 25
                                        "這個產品的局限性是什麼？", // 26
                                        "這個產品用於診斷嗎？", // 27
                                        "如何供電？", // 28
                                        "產品使用時間是多少？", // 29
                                        "如何充電？", // 30
                                    });
    fontData[Lan][PAGE_HELP].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_HELP].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));

    //PAGE_FAQ
    fontData[Lan][PAGE_FAQ].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_FAQ].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_FAQ].insert("labelText",QStringList{
                                       "血糖測量有範圍嗎？", // 0
                                       "在哪裡查看血糖結果？", // 1
                                       "值突然偏高或偏低怎麼辦？", // 2
                                       "為什麼需要血糖校準？", // 3
                                       "不進行血糖校準會怎樣？", // 4
                                       "血糖校準期限過了還能測量嗎？", // 5
                                       "為什麼每90天要進行一次血糖校準？", // 6
                                       "測量失敗怎麼辦？", // 7
                                       "可以用其他手指測量嗎？", // 8
                                       "手指位置不對怎麼辦？", // 9
                                       "測量姿勢不正確會有影響嗎？", // 10
                                       "測量時間不對也可以嗎？", // 11
                                       "溫度過低或過高會有影響嗎？", // 12
                                       "可以用濕手測量嗎？", // 13
                                       "運動後立即測量可以嗎？", // 14
                                       "產品內部可以有直射陽光嗎？", // 15
                                       "孕婦也可以使用嗎？", // 16
                                       "糖尿病患者也可以使用嗎？", // 17
                                       "透析患者也可以使用嗎？", // 18
                                       "測量部位有傷口也可以使用嗎？", // 19
                                       "多人可以一起使用嗎？", // 20
                                       "沒有智慧型手機也可以使用嗎？", // 21
                                       "充電時可以使用嗎？", // 22
                                       "電池完全充電需要多長時間？", // 23
                                       "電池性能下降了怎麼辦？", // 24
                                       "可以用水擦拭嗎？", // 25
                                       "可以用清潔劑、酒精、丙酮等擦拭嗎？", // 26
                                       "可以便攜使用嗎？", // 27
                                       "需要使用便攜收納盒嗎？", // 28
                                       "可以隨身帶上飛機嗎？", // 29
                                       "可以作為託運行李發送嗎？", // 30
                                       "光學傳輸方式是什麼？", // 31
                                       "A/S期限是多少？", // 32
                                   });
    fontData[Lan][PAGE_FAQ].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_FAQ].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));

    //PAGE_ERROR_HELP
    fontData[Lan][PAGE_ERROR_HELP].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_ERROR_HELP].insert("labelText",QStringList{
                                              "經常發生測量失敗", // 0
                                              "提示無法識別手指", // 1
                                              "提示手指表面溫度低", // 2
                                              "提示測量數據有誤", // 3
                                              "提示無法分析測量結果", // 4
                                              "測量過程中可以取消嗎？", // 5
                                              "血糖值與平時不同", // 6
                                              "我認為血糖正常但顯示警告", // 7
                                              "提示血糖校準有效期已過", // 8
                                              "重置血糖校準會刪除以前的記錄嗎？", // 9
                                              "刪除的血糖記錄可以恢復嗎？", // 10
                                              "無法充電", // 11
                                              "出現電量不足通知怎麼辦？", // 12
                                              "出現電量不足通知後產品關機了", // 13
                                              "開機後無法進入初始畫面", // 14
                                              "提示找不到升級文件", // 15
                                              "提示升級文件有問題", // 16
                                              "提示不是升級文件", // 17
                                              "升級過程中斷電了", // 18
                                              "畫面卡住或非常慢", // 19
                                              "不知道是什麼錯誤", // 20
                                              "設備出現問題了", // 21
                                              "問題無法解決怎麼辦？", // 22
                                              "使用產品時有哪些額外耗材？", // 23
                                          });
    fontData[Lan][PAGE_ERROR_HELP].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));

    //PAGE_RESPONSE
    fontData[Lan][PAGE_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_RESPONSE].insert("labelTextHelp",QStringList{
                                            "本產品使用光學系統測量血糖", // 0
                                            "用於測量體內血糖", // 1
                                            "採用非侵入式測量方式，無痛測量是其優點", // 2
                                            "未接受藥物治療的糖尿病前期患者可以使用"
                                            "@本產品按照19至74歲成人標準設計", // 3
                                            "提供血糖測量、血糖記錄保存及查閱功能", // 4
                                            "建議用於日常血糖變化的確認", // 5
                                            "測量很簡單"
                                            "@請按照指引進行測量", // 6
                                            "測量前需要進行血糖校準"
                                            "@請按照指引進行校準", // 7
                                            "指減少實際血糖值與產品之間誤差的校準工作", // 8
                                            "是的，測量前必須進行", // 9
                                            "血糖校準必須在校準完成之日起90天內進行"
                                            "@如未進行，將無法測量", // 10
                                            "測量前請清洗雙手並去除水分"
                                            "@請從產品上拔下充電器", // 11
                                            "請避免在測量過程中移動或對手指施加強壓"
                                            "@如因咳嗽或打噴嚏導致手指移動，請重新測量", // 12
                                            "在以下情況下測量值可能不準確，需要諮詢專業醫療人員"
                                            "@未滿19歲或75歲以上"
                                            "@受光照部位有皮膚病或傷口"
                                            "@患有多汗症、帕金森病等手部顫抖症狀"
                                            "@有嚴重低血糖、糖尿病酮症酸中毒、癲癇、暈厥、腎上腺疾病病史"
                                            "@正在進行血液透析或腹膜透析"
                                            "@孕婦及哺乳期婦女", // 13
                                            "在主畫面選擇測量時間段後，請按照指引進行", // 14
                                            "按下開始測量按鈕後將自動進行直至完成", // 15
                                            "測量時間在1分鐘內完成", // 16
                                            "結果在測量完成時以數字顯示血糖值", // 17
                                            "顏色含義如下"
                                            "@綠色表示正常"
                                            "@橙色表示注意"
                                            "@紅色表示警告", // 18
                                            "可透過血糖範圍選單調整正常顏色範圍", // 19
                                            "請在血糖管理時作為參考"
                                            "@顯示的數值僅供參考"
                                            "@如需醫學判斷，請諮詢專業醫療人員", // 20
                                            "測量記錄最多可在設備中保存90天"
                                            "@90天後的記錄將自動刪除", // 21
                                            "可能因使用環境條件而有所不同"
                                            "@請按照使用指南使用", // 22
                                            "是的，請避免以下環境"
                                            "@避免陽光直射強烈的地方"
                                            "@避免風大的地方"
                                            "@避免潮濕的環境"
                                            "@避免有振動的環境"
                                            "@避免室內溫度過低或過高的地方\n*適宜溫度: 10～35℃ (50～95℉)", // 23
                                            "關閉電源，用手指插入口蓋封好後，請存放在收納盒中", // 24
                                            "不防水", // 25
                                            "本產品是用於日常狀態確認的設備"
                                            "@不以醫療診斷為目的", // 26
                                            "本產品提供參考用途的資訊"
                                            "@不能替代醫療診斷或治療決定"
                                            "@如需糖尿病診斷及治療、胰島素注射等醫療行為，請務必諮詢專業醫療人員", // 27
                                            "透過鋰離子聚合物電池供電", // 28
                                            "完全充電後，在待機模式下最長可使用約29天", // 29
                                            "使用符合5V DC / 2A～2.4A標準的USB C型充電器充電", // 30
                                        });
    textData[Lan][PAGE_RESPONSE].insert("labelTextFaq",QStringList{
                                            "可在70～350 mg/dL範圍內測量", // 0
                                            "當天記錄可在主畫面查看"
                                            "@過去血糖記錄請在血糖記錄選單中查看", // 1
                                            "請確認正確的使用環境和測量姿勢後重新測量", // 2
                                            "由於個人特徵不同，需要將產品特性調整到個人", // 3
                                            "不進行血糖校準將無法測量", // 4
                                            "超過期限將無法測量，請重新進行血糖校準", // 5
                                            "為確保準確測量，每90天需要重新進行校準", // 6
                                            "測量失敗時，會彈出顯示失敗原因的通知視窗"
                                            "@請在故障排除選單中查看測量失敗問題", // 7
                                            "為確保準確測量，建議使用進行了校準的手指進行測量", // 8
                                            "無法準確測量"
                                            "@為確保準確測量，請放鬆手指，使手指中央輕輕蓋住感測器視窗末端", // 9
                                            "測量姿勢不正確可能導致測量不準確"
                                            "@請以正確姿勢進行測量以確保準確性", // 10
                                            "不會影響測量結果"
                                            "@但如果計劃將其用作血糖管理資料，建議在相應時間進行測量", // 11
                                            "溫度過低或過高時，測量值可能不準確", // 12
                                            "請勿用濕手測量"
                                            "@可能導致產品故障", // 13
                                            "請勿在運動後立即測量"
                                            "@請在呼吸和心率穩定後測量", // 14
                                            "無法準確測量"
                                            "@為確保準確測量，請在沒有陽光直射的室內測量", // 15
                                            "測量結果可能不準確"
                                            "@請諮詢專業醫療人員", // 16
                                            "測量結果可能不準確"
                                            "@請諮詢專業醫療人員", // 17
                                            "測量結果可能不準確"
                                            "@請諮詢專業醫療人員", // 18
                                            "測量結果可能不準確"
                                            "@請諮詢專業醫療人員", // 19
                                            "最多支援2名用戶同時使用", // 20
                                            "產品可單獨使用", // 21
                                            "請務必拔下充電器後使用", // 22
                                            "完全充電約需3小時45分鐘", // 23
                                            "請聯繫A/S中心檢查，必要時更換", // 24
                                            "請勿用水擦拭"
                                            "@可能導致產品故障", // 25
                                            "請勿用清潔劑、酒精、丙酮等擦拭"
                                            "@可能導致產品故障", // 26
                                            "是的，請攜帶使用"
                                            "@請在適合測量的室內環境中使用", // 27
                                            "外部衝擊可能導致誤操作或故障，請放入攜帶式收納盒中攜帶", // 28
                                            "可在飛機客艙內攜帶和使用"
                                            "@無法作為行李託運", // 29
                                            "無法作為行李託運"
                                            "@本產品內置鋰離子聚合物電池，根據安全規定不能作為託運行李發送"
                                            "@請務必作為隨身行李攜帶", // 30
                                            "通過分析穿過手指的光來測量血糖", // 31
                                            "官方A/S期限為購買產品後24個月", // 32
                                        });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp",QStringList{
                                                  "請確認以下測量環境後重新測量"
                                                  "@測量過程中請勿咳嗽、打噴嚏、說話，不要移動"
                                                  "@放鬆手指，水平貼緊"
                                                  "@請保持手指表面溫度26℃(79℉)以上"
                                                  "@請去除手指的水分和異物", // 0
                                                  "請確認手指是否正確插入後重新測量"
                                                  "@為確保準確測量，請放鬆手指，使手指中央輕輕蓋住感測器視窗末端", // 1
                                                  "請充分溫暖手指後重新測量", // 2
                                                  "當測量資料不完整或檢測到無法分析的值時發生"
                                                  "@請避免手抖、打噴嚏、說話", // 3
                                                  "當測量血糖值的偏差超過範圍時發生"
                                                  "@請確認手指測量位置和測量環境後重新測量", // 4
                                                  "測量中按下「取消」按鈕將停止測量", // 5
                                                  "請確認測量環境後重新測量"
                                                  "@如果測量環境沒有影響，請確認以下內容"
                                                  "@請確認是否有低血糖或高血糖症狀"
                                                  "@如果持續懷疑不準確，請諮詢專業醫療人員", // 6
                                                  "請在血糖範圍選單中確認並調整正常範圍", // 7
                                                  "血糖校準有效期（90天）到期時無法測量"
                                                  "@請進行血糖校準", // 8
                                                  "即使初始化，記錄也不會被刪除", // 9
                                                  "無法恢復"
                                                  "刪除血糖記錄時請注意", // 10
                                                  "請確認是否為額定電池充電器"
                                                  "@使用額定電池充電器仍無法充電時，請聯繫A/S中心", // 11
                                                  "請使用充電器充電", // 12
                                                  "電池低於5%時，為保護系統，產品將在5秒後關機"
                                                  "@請使用充電器充電", // 13
                                                  "請使用額定電池充電器為電池充電"
                                                  "@充電完成後重新開機，啟動完成後即可正常使用", // 14
                                                  "請重新確認升級文件", // 15
                                                  "請重新下載升級文件後再試", // 16
                                                  "請確認文件是否正確後再試", // 17
                                                  "請充電後再試"
                                                  "@充電後仍發生相同現象時，請聯繫A/S中心", // 18
                                                  "請使用針按下重置按鈕"
                                                  "@充電後仍發生相同現象時，請聯繫A/S中心", // 19
                                                  "請先重新啟動產品，確認是否發生相同錯誤"
                                                  "@或將產品軟體版本升級到最新版本"
                                                  "@如發生相同現象，請聯繫A/S中心", // 20
                                                  "其他產品發生問題的情況"
                                                  "@請嘗試重新啟動和更新"
                                                  "@如發生相同現象，請聯繫A/S中心", // 21
                                                  "請聯繫A/S中心", // 22
                                                  "沒有額外消耗品", // 23
                                              });
    fontData[Lan][PAGE_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_RESPONSE].insert("labelPageNum",QFont(currentFont,instance.pixelToPoint(28)));

    //=====================================================================================================================================
    //ES
    Lan = ES;
    nTextSize = 30;
    currentFont = instance.fontSuit;

    //PAGE_TRANS
    fontData[Lan][PAGE_TRANS].insert("fontSuit",QFont(instance.fontSuit,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_TRANS].insert("fontJP",QFont(instance.fontJP,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_TRANS].insert("fontSC",QFont(instance.fontSC,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_TRANS].insert("fontTC",QFont(instance.fontTC,instance.pixelToPoint(36)));

    textData[Lan][PAGE_TRANS].insert("lang",QStringList{
                                         "한국어",
                                         "ENGLISH",
                                         "日本語",
                                         "繁體中文",
                                         "简体中文",
                                         "ESPAÑOL"
                                     });
    //CUSTOM_BUTTON
    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonOK", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonOK", QStringList{"Aceptar"}); // OK

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel", QStringList{"Cancelar"}); // Cancel

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonHome", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonHome", QStringList{"Inicio"}); // Home

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart", QStringList{"Comenzar"}); // Start

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasure", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasure", QStringList{"Medir"}); // Measure

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonInput", QFont(currentFont, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonInput", QStringList{"Introducir"}); // Input

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe", QStringList{"Repetir medición"}); // Remeasure

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonSave", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonSave", QStringList{"Guardar"}); // Save

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonUpgrade", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonUpgrade", QStringList{"Actualizar software"}); // Software Upgrade

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QStringList{"Sí"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QStringList{"No"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QStringList{
                                            "한국어",
                                            "ENGLISH",
                                            "日本語",
                                            "繁體中文",
                                            "简体中文",
                                            "ESPAÑOL"
                                        });

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonBack", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonBack", QStringList{"Atrás"});

    //CUSTOM_COMPONENT
    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextValue", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextResult", QFont(currentFont, instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextResult", QStringList{
                                               "Medición exitosa",                              // 0
                                               "No se detectó el dedo\nInténtelo de nuevo",     // 1
                                               "Error del dispositivo\nContacte soporte",       // 2
                                               "Error del dispositivo\nContacte soporte",       // 3
                                               "No se pudo analizar\nInténtelo de nuevo",       // 4
                                               "Error en los datos\nInténtelo de nuevo",        // 5
                                               "No se puede medir mientras carga\nDesconéctelo e intente de nuevo", // 6
                                               "El dedo está muy frío.\nNo se puede medir",     // 7
                                               "Fallo en la medición\nContacte soporte"         // 8
                                           });

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QFont(currentFont, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QStringList{
                                               "Actualización completada", // 0
                                               "Falló la actualización\nContacte soporte", // 1
                                               "Archivo no encontrado\nRevise el archivo", // 2
                                               "Archivo con errores\nUse uno nuevo", // 3
                                               "Archivo inválido\nVerifique si es correcto", // 4
                                               "Falló la actualización\nContacte soporte" // 5
                                           });



    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelText", QFont(currentFont, instance.pixelToPoint(50)));
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelTextSelect", QFont(currentFont, instance.pixelToPoint(50), QFont::Bold));
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelTextSub", QFont(currentFont, instance.pixelToPoint(40)));

    //PAGE_PASSWORD
    fontData[Lan][PAGE_PASSWORD].insert("labelButtonNum", QFont(currentFont, instance.pixelToPoint(44), QFont::Bold));

    fontData[Lan][PAGE_PASSWORD].insert("labelTitle", QFont(currentFont, instance.pixelToPoint(40), QFont::Bold));
    textData[Lan][PAGE_PASSWORD].insert("labelTitle", QStringList{
                                            "Por favor inicie sesión",       // Please log in
                                            "Editar contraseña",             // Edit Password
                                            "Eliminar usuario",              // Delete User
                                            "Confirmar contraseña",    // Password Confirmation
                                            "Reingresar contraseña",  // Password Re-confirmation
                                            "CONTRASEÑA_MAX"                 // PASSWORD_MAX
                                        });

    fontData[Lan][PAGE_PASSWORD].insert("labelTitleSub", QFont(currentFont, instance.pixelToPoint(24)));
    textData[Lan][PAGE_PASSWORD].insert("labelTitleSub", QStringList{
                                            "Por favor ingrese su contraseña de 4 dígitos",        // Please enter your 4-digit password
                                            "Por favor ingrese los 4 dígitos para modificar",      // Please enter the 4 digits to modify
                                            "Por favor ingrese nuevamente su contraseña de 4 dígitos", // Please enter your 4-digit password again
                                            "Por favor confirme ingresando 4 dígitos",             // Please confirm by entering 4 digits
                                            "Por favor vuelva a ingresar los 4 dígitos para verificar", // Please re-enter the 4 digits to verify
                                            "Ingrese su contraseña actual",
                                            "CONTRASEÑA_MAX"                                       // PASSWORD_MAX
                                        });

    fontData[Lan][PAGE_PASSWORD].insert("labelButtonOKText", QFont(currentFont, instance.pixelToPoint(20)));
    textData[Lan][PAGE_PASSWORD].insert("labelButtonOKText", QStringList{"Aceptar"}); // OK

    fontData[Lan][PAGE_PASSWORD].insert("labelButtonCancelText", QFont(currentFont, instance.pixelToPoint(20)));
    textData[Lan][PAGE_PASSWORD].insert("labelButtonCancelText", QStringList{"Cancelar"}); // Cancel

    //PAGE_SELECT_USER
    fontData[Lan][PAGE_SELECT_USER].insert("labelTitle", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_SELECT_USER].insert("labelTitle", QStringList{"Seleccione un usuario"});

    fontData[Lan][PAGE_SELECT_USER].insert("labelUserText", QFont(currentFont, instance.pixelToPoint(28)));
    textData[Lan][PAGE_SELECT_USER].insert("labelUserText", QStringList{"Usuario 1", "Usuario 2"});

    //PAGE_PASSWORD_ALLCHAT
    fontData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelButtonNum", QFont(currentFont, instance.pixelToPoint(44)));

    fontData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitle", QFont(currentFont, instance.pixelToPoint(40), QFont::Bold));
    textData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitle", QStringList{
                                                    "Iniciar sesión",
                                                    "Cambiar contraseña",
                                                    "Eliminar glucosa", //"Eliminar usuario",
                                                    "Confirmar contraseña",
                                                    "Reconfirmar contraseña",
                                                    "Restablecer contraseña",
                                                    "PASSWORD_MAX"
                                                });

    fontData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitleSub", QFont(currentFont, instance.pixelToPoint(30)));
    textData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitleSub", QStringList{
                                                    "Ingresar contraseña",
                                                    "Ingresar nueva contraseña",
                                                    "Ingresar contraseña",
                                                    "Contraseña para verificación",
                                                    "Ingresar nuevamente",
                                                    "Contraseña actual",
                                                    "PASSWORD_MAX"
                                                });

    //PAGE_PASSWORD_CONFIRM
    fontData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTitle", QFont(currentFont, instance.pixelToPoint(40), QFont::Bold));
    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTitle", QStringList{
                                                    "Iniciar sesión",                       // Login
                                                    "Iniciar sesión",                       // Login
                                                    "Iniciar sesión",                       // Login
                                                    "Verificación de ID",                   // Id Check
                                                    "Verificación de ID",                   // Id Check
                                                    "Verificación de contraseña",           // PW Check
                                                    "Verificación de contraseña",           // PW Check
                                                    "Cambio de contraseña",                 // PW Change
                                                    "Cambio de contraseña",                 // PW Change
                                                    "Cambio de contraseña",                 // PW Change
                                                    "Cambio de contraseña",                 // PW Change
                                                    "Eliminar glucosa", //"Eliminar información",                 // Delete Info
                                                    "Confirmar eliminación", //"Eliminar información",                 // Delete Info
                                                    "Glucosa eliminada", //"Eliminar información",                 // Delete Info
                                                    "Cerrar sesión",                        // Logout
                                                    "Restablecer contraseña",    // PASSWORD_STR_INIT
                                                    "Restablecer contraseña",    // PASSWORD_STR_INIT_CONFIRM
                                                    "Restablecer contraseña",    // PASSWORD_STR_SUCCESS
                                                    "CONTRASEÑA_STR_MAX"                    // PASSWORD_STR_MAX
                                                });

    fontData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelText", QStringList{
                                                    "Inicio de sesión exitoso",                                                        // 로그인에 성공했습니다
                                                    "Inicio de sesión fallido",                                                        // 로그인에 실패했습니다
                                                    "Por favor cambie su contraseña",                                                  // 비밀번호를 변경해주시기 바랍니다
                                                    "Por favor ingrese su contraseña\npara verificación",                              // 본인 확인을 위해 비밀번호를 입력해주세요
                                                    "Las contraseñas no coinciden",                                                    // 비밀번호가 일치하지 않습니다
                                                    "Por favor ingrese nuevamente su contraseña\npara mayor precisión",                // 정확한 확인을 위해 비밀번호를 한번 더 입력해주세요
                                                    "La contraseña ingresada\nno coincide con la anterior",                            // 입력된 비밀번호가 이전 비밀번호와 일치하지 않습니다
                                                    "¿Le gustaría cambiar su contraseña?",                                             // 비밀번호를 변경하시겠습니까?
                                                    "Por favor ingrese su contraseña\npara verificación",                              // 본인 확인을 위해 비밀번호를 입력해주세요 (중복 → 유지 or 제거 결정)
                                                    "Nueva contraseña\n\nmín. 8 caracteres, número\nletra y símbolo como .,?!",        // 변경하실 비밀번호를 입력해주세요
                                                    "Cambio de contraseña completado\nPor favor vuelva a iniciar sesión",              // 비밀번호 변경이 완료되었습니다
                                                    "¿Desea eliminar el registro de glucosa?", // PASSWORD_STR_DELETE
                                                    "Una vez eliminado,no se puede recuperar", // PASSWORD_STR_DELETE_CONFIRM
                                                    "Registro de glucosa eliminado", // PASSWORD_STR_DELETE_SUCCESS
                                                    "cerrará la sesión",                              // 로그아웃
                                                    "¿Desea restablecer la contraseña?",                                               // 비밀번호를 초기화하시겠습니까?
                                                    "Restablecer la contraseña\nla devolverá a los valores por defecto",               // 비밀번호를 초기화할 경우 비밀번호가 초기 설정 상태가 됩니다
                                                    "La contraseña ha sido restablecida",                                              // 비밀번호가 초기화되었습니다
                                                    "CONTRASEÑA_STR_MAX"                                              // PASSWORD_STR_MAX
                                                });

    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTextError", QStringList{
                                                    "La contraseña ha sido establecida",
                                                    "La contraseña debe tener\nentre 8 y 12 caracteres",
                                                    "La contraseña debe incluir\nal menos un número",
                                                    "La contraseña debe incluir\nal menos una letra (A-Z)",
                                                    "La contraseña debe incluir\nal menos un símbolo (por ejemplo: .,?!)",
                                                    "Las contraseñas no coinciden",
                                                    "Esta contraseña no está permitida"
                                                    "Se ha producido un error desconocido",
                                                });

    //PAGE_HOME
    fontData[Lan][PAGE_HOME].insert("labelTextStatus",QFont(currentFont,instance.pixelToPoint(18),QFont::Bold));
    textData[Lan][PAGE_HOME].insert("labelTextStatus",QStringList{
                                        "Despertar\n", "Antes del\ndesayuno", "Después del\ndesayuno",
                                        "Antes del\nalmuerzo", "Después del\nalmuerzo",
                                        "Antes de la\ncena", "Después de la\ncena", "Hora de\ndormir"
                                    });
    //약어
    /*
    textData[Lan][PAGE_HOME].insert("labelTextStatus", QStringList{
        "Despertar", "A. desayuno", "D. desayuno",
        "A. almuerzo", "D. almuerzo",
        "A. cena", "D. cena", "Hora de dormir"});
        */


    fontData[Lan][PAGE_HOME].insert("labelButtonText",QFont(currentFont,instance.pixelToPoint(62),QFont::ExtraBold));

    //PAGE_SELECT
    fontData[Lan][PAGE_SELECT].insert("labelTextStatus", QFont(currentFont, instance.pixelToPoint(42), QFont::ExtraBold));
    textData[Lan][PAGE_SELECT].insert("labelTextStatus",QStringList{
                                          "Despertar", "Antes del desayuno", "Después del desayuno",
                                          "Antes del almuerzo", "Después del almuerzo",
                                          "Antes de la cena", "Después de la cena", "Hora de dormir"
                                      });

    fontData[Lan][PAGE_SELECT].insert("labelTextStatusSub", QFont(currentFont, instance.pixelToPoint(24)));
    textData[Lan][PAGE_SELECT].insert("labelTextStatusSub", QStringList{"Por favor inicie la medición"});

    fontData[Lan][PAGE_SELECT].insert("labelTextStatusValue",QFont(currentFont,instance.pixelToPoint(40),QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextGlucoseValue",QFont(currentFont,instance.pixelToPoint(130),QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextMgdl",QFont(currentFont,instance.pixelToPoint(34),QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextResult",QFont(currentFont,instance.pixelToPoint(32)));
    textData[Lan][PAGE_SELECT].insert("labelTextResult", QStringList{
                                          "Normal",
                                          "Precaución",
                                          "Precaución",
                                          "Advertencia",
                                          "Advertencia"
                                      });
    textData[Lan][PAGE_SELECT].insert("labelTextResultSub",QStringList{
                                          "Nivel de azúcar",
                                          "Azúcar baja en la sangre",
                                          "Azúcar alta en la sangre",
                                          "Azúcar baja en la sangre",
                                          "Azúcar alta en la sangre"
                                      });

    fontData[Lan][PAGE_SELECT].insert("labelTextTime",QFont(currentFont,instance.pixelToPoint(21),QFont::Bold));
    textData[Lan][PAGE_SELECT].insert("labelTextTime",QStringList{"Hora"});

    fontData[Lan][PAGE_SELECT].insert("labelTextIcon",QFont(currentFont,instance.pixelToPoint(23),QFont::Bold));
    textData[Lan][PAGE_SELECT].insert("labelTextIcon",QStringList{"Normal", "Bajo", "Alto", "Bajo", "Alto"});

    //PAGE_MENU
    fontData[Lan][PAGE_MENU].insert("labelButtonText",QFont(currentFont,instance.pixelToPoint(25),QFont::Bold));
    textData[Lan][PAGE_MENU].insert("labelButtonText", QStringList{
                                        "Cali\nbración",         // calibration
                                        "Rango",                 // range
                                        "Lista",                 // list
                                        "Sonido",                // sound
                                        "Dormir",                // sleep
                                        "Cambio",                // switch
                                        "Fecha",                 //  date
                                        "Modo de\ncolor",        // color mode
                                        "Idioma",                // language
                                        "Actualizar",            // upgrade
                                        "Info de\ndispositivo",  // device info
                                        "Restablecer",           // reset
                                        "Usuario",               // user
                                        "Ayuda",                 // help
                                        "Preguntas\nfrecuentes", // faq
                                        "Guía de\nerrores"       // error help
                                    });

    //PAGE_CALI_CHECK
    fontData[Lan][PAGE_CALI_CHECK].insert("labelTextCheck",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_CHECK].insert("labelTextCheck",QStringList{
                                              "Fase de calibración\nPor favor inserte su dedo",
                                              "Calibración completa\n¿Desea proceder de nuevo?"
                                          });

    //PAGE_CALI_GAIN_CONFIRM
    fontData[Lan][PAGE_CALI_GAIN_CONFIRM].insert("labelTextGainConfirm",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_GAIN_CONFIRM].insert("labelTextGainConfirm",QStringList{
                                                     "Paso de ajuste de sensibilidad LED\nPor favor no mueva su dedo",
                                                     "El ajuste de sensibilidad LED\nse ha completado"
                                                 });

    //Page_GRAPH
    fontData[Lan][PAGE_GRAPH].insert("labelProgressText", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][PAGE_GRAPH].insert("labelProgressText", QStringList{"Completado"});
    fontData[Lan][PAGE_GRAPH].insert("labelProgressValue", QFont(currentFont, instance.pixelToPoint(60), QFont::Bold));
    fontData[Lan][PAGE_GRAPH].insert("labelProgressPercent", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    fontData[Lan][PAGE_GRAPH].insert("labelAdcText", QFont(currentFont, instance.pixelToPoint(20)));
    textData[Lan][PAGE_GRAPH].insert("labelAdcText", QStringList{"A:"});
    fontData[Lan][PAGE_GRAPH].insert("labelLoading", QFont(currentFont, instance.pixelToPoint(48), QFont::Bold));
    textData[Lan][PAGE_GRAPH].insert("labelLoading", QStringList{"Analizando"});

    //Page_CALI_GAIN_RESULT
    fontData[Lan][PAGE_CALI_GAIN_RESULT].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_GAIN_RESULT].insert("labelText", QStringList{
                                                    "El ajuste de sensibilidad del LED está completo\nProceda al siguiente paso de medición",
                                                    "El ajuste de sensibilidad del LED falló\nPor favor, mida nuevamente"
                                                });

    //PAGE_CALI_SELECT
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectText", QFont(currentFont, instance.pixelToPoint(20), QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT].insert("labelSelectText", QStringList{
                                               "En ayunas", "Después\nde comer"
                                           });

    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextAdc", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextValue", QFont(currentFont, instance.pixelToPoint(36)));

    //PAGE_CALI_SELECT_INFO
    fontData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText", QStringList{
                                                    "¿Han pasado al menos 8 horas\ndesde el ayuno?\nSe realizan dos mediciones\ncon intervalos de 30 minutos (01)",//"¿Han pasado más de 8 horas\ndesde tu última comida?",
                                                    "¿Han pasado al menos 8 horas\ndesde el ayuno?\nSe realizan dos mediciones\ncon intervalos de 30 minutos (02)",
                                                    "¿Ha pasado más de 1 hora\ndesde tu última comida?",
                                                    "¿Ha pasado más de 1 hora y 30 minutos\ndesde tu última comida?",
                                                    "¿Han pasado más de 2 horas\ndesde tu última comida?"
                                                });

    //PAGE_CALI_SEELCT_CONFIRM
    fontData[Lan][PAGE_CALI_SELECT_CONFIRM].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_CONFIRM].insert("labelText",QStringList{"Por favor, realice\nla calibración de glucosa en orden"});

    //PAGE_CALI_CONFIRM
    fontData[Lan][PAGE_CALI_CONFIRM].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_CONFIRM].insert("labelText", QStringList{"Seleccione entrada o medida"});

    //PAGE_CALI_RESULT
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextAdc", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextTemp", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextHeart", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));

    //PAGE_CALI_RESULT_MULTI
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextAdc", QFont(currentFont, instance.pixelToPoint(34), QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextTemp", QFont(currentFont, instance.pixelToPoint(34)));
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextHeart", QFont(currentFont, instance.pixelToPoint(34)));

    //PAGE_CALI_RESULT_MULTI_CONFIRM
    fontData[Lan][PAGE_CALI_RESULT_MULTI_CONFIRM].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_RESULT_MULTI_CONFIRM].insert("labelText",QStringList{"¿Eliminar valor\ny volver a medir?"});

    //PAGE_RESULT
    fontData[Lan][PAGE_RESULT].insert("labelTextGlucoseValue", QFont(currentFont, instance.pixelToPoint(103), QFont::ExtraBold));

    fontData[Lan][PAGE_RESULT].insert("labelTextMgdl", QFont(currentFont, instance.pixelToPoint(27)));
    textData[Lan][PAGE_RESULT].insert("labelTextMgdl", QStringList{"mg/dL"});

    fontData[Lan][PAGE_RESULT].insert("labelTextTime", QFont(currentFont, instance.pixelToPoint(21), QFont::Bold));
    textData[Lan][PAGE_RESULT].insert("labelTextTime", QStringList{"Hora"});

    fontData[Lan][PAGE_RESULT].insert("labelText", QFont(currentFont, instance.pixelToPoint(36)));

    textData[Lan][PAGE_RESULT].insert("indexResult", QStringList{
                                          "Normal",
                                          "Precaución",
                                          "Precaución",
                                          "Advertencia",
                                          "Advertencia"
                                      });
    textData[Lan][PAGE_RESULT].insert("indexResultSub", QStringList{
                                          "Nivel de azúcar",
                                          "Bajo nivel de azúcar",
                                          "Alto nivel de azúcar",
                                          "Bajo nivel de azúcar",
                                          "Alto nivel de azúcar"
                                      });
    fontData[Lan][PAGE_RESULT].insert("labelProgressBarTooltip", QFont(currentFont, instance.pixelToPoint(16), QFont::Bold));
    textData[Lan][PAGE_RESULT].insert("labelProgressBarTooltip", QStringList{
                                          "Normal",
                                          "Precaución",
                                          "Advertencia",
                                          "Error"
                                      });

    //PAGE_INIT
    fontData[Lan][PAGE_INIT].insert("labelText", QFont(currentFont, instance.pixelToPoint(30)));
    textData[Lan][PAGE_INIT].insert("labelText", QStringList{
                                        "Restablecimiento de fábrica",
                                        "Restablecimiento de Bluetooth",
                                        "Restablecimiento de calibración de azúcar"
                                    });

    //PAGE_INIT_CONFIRM
    fontData[Lan][PAGE_INIT_CONFIRM].insert("labelText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_INIT_CONFIRM].insert("labelText", QStringList{
                                                "Toda la información del sistema\n"
                                                "se restablecerá\n\n"
                                                "¿Desea proceder con el\n"
                                                "restablecimiento de fábrica?",

                                                "Después de la inicialización\n"
                                                "del sistema,\n"
                                                "el sistema se reiniciará",

                                                "La información del usuario de\n"
                                                "Bluetooth se inicializará\n\n"
                                                "La conexión con el\n"
                                                "smartphone se desconectará\n\n"
                                                "¿Desea restablecer Bluetooth?",

                                                "La información del usuario de\n"
                                                "Bluetooth ha sido restablecida.",

                                                "La corrección de azúcar\n"
                                                "se restablecerá\n\n"
                                                "¿Desea restablecer la\n"
                                                "corrección de azúcar?",

                                                "La corrección de azúcar\n"
                                                "ha sido restablecida"
                                            });


    //PAGE_THRESHOLD
    fontData[Lan][PAGE_THRESHOLD].insert("labelText", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_THRESHOLD].insert("labelText", QStringList{
                                             "Azúcar baja",
                                             "Azúcar alta"
                                         });
    fontData[Lan][PAGE_THRESHOLD].insert("labelButton", QFont(currentFont, instance.pixelToPoint(22),QFont::Bold));
    textData[Lan][PAGE_THRESHOLD].insert("labelButton", QStringList{"Fijar"});

    fontData[Lan][PAGE_THRESHOLD].insert("labelValue",QFont(currentFont,instance.pixelToPoint(48),QFont::Bold));

    fontData[Lan][PAGE_THRESHOLD].insert("labelValueRange",QFont(currentFont,instance.pixelToPoint(26)));
    textData[Lan][PAGE_THRESHOLD].insert("labelValueRange",QStringList{
                                             "Menos de",
                                             "Más de"
                                         });

    //PAGE_SOUND
    fontData[Lan][PAGE_SOUND].insert("labelVolume",QFont(currentFont,instance.pixelToPoint(110),QFont::Bold));

    //PAGE_SLEEP
    fontData[Lan][PAGE_SLEEP].insert("labelText",QFont(currentFont,instance.pixelToPoint(42),QFont::Bold));
    textData[Lan][PAGE_SLEEP].insert("labelText",QStringList{
                                         "30seg",
                                         "1min",
                                         "3min",
                                         "5min",
                                         "10min",
                                         "Ninguno"
                                     });

    //PAGE_UPGRADE
    fontData[Lan][PAGE_UPGRADE].insert("labelText",QFont(currentFont,instance.pixelToPoint(42),QFont::Bold));
    textData[Lan][PAGE_UPGRADE].insert("labelText",QStringList{"Versión"});

    fontData[Lan][PAGE_UPGRADE].insert("labelTextVersion",QFont(currentFont,instance.pixelToPoint(55)));

    //PAGE_UPGRADE_CONFIRM
    fontData[Lan][PAGE_UPGRADE_CONFIRM].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_UPGRADE_CONFIRM].insert("labelText",QStringList{
                                                   "1. Conecte el dispositivo a la PC\n"
                                                   "2. Copie el archivo bin en el dispositivo\n"
                                                   "3. Reinicie el dispositivo después de que\n   la copia esté completa"
                                               });

    //PAGE_DEVICEINFO
    fontData[Lan][PAGE_DEVICEINFO].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_DEVICEINFO].insert("labelTitle",QStringList{
                                              "BLE",
                                              "Versión H/W",
                                              "Versión S/W",
                                              "Serie"
                                          });

    fontData[Lan][PAGE_DEVICEINFO].insert("labelText",QFont(currentFont,instance.pixelToPoint(30)));

    //PAGE_USERINFO
    fontData[Lan][PAGE_USERINFO].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    textData[Lan][PAGE_USERINFO].insert("labelText",QStringList{
                                            "Cambiar contraseña",
                                            "Restablecer la contraseña", // reset password
                                            "Eliminar glucosa registrada",
                                            "Cerrar sesión"
                                        });

    //PAGE_BATPOPUP
    fontData[Lan][PAGE_BATPOPUP].insert("labelText",QFont(currentFont,instance.pixelToPoint(42),QFont::Bold));
    textData[Lan][PAGE_BATPOPUP].insert("labelText",QStringList{
                                            "Batería baja",
                                            "Por favor conéctelo al cargador"
                                        });
    fontData[Lan][PAGE_BATPOPUP].insert("labelTextSub",QFont(currentFont,instance.pixelToPoint(nTextSize)));
    textData[Lan][PAGE_BATPOPUP].insert("labelTextSub",QStringList{
                                            "Batería muy baja",
                                            "El sistema se está apagando"
                                        });

    //PAGE_REVERSE
    fontData[Lan][PAGE_REVERSE].insert("labelTextButton",QFont(currentFont,instance.pixelToPoint(36)));
    textData[Lan][PAGE_REVERSE].insert("labelTextButton",QStringList{
                                           "Izquierda",
                                           "Derecha"
                                       });
    fontData[Lan][PAGE_REVERSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize)));
    textData[Lan][PAGE_REVERSE].insert("labelText",QStringList{
                                           "El reinicio procederá"
                                       });

    //PAGE_HISTORY
    fontData[Lan][PAGE_HISTORY].insert("labelButton",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][PAGE_HISTORY].insert("labelButton", QStringList{
                                           "+7 días",
                                           "Hoy",
                                           "-7 días"
                                       });

    //PAGE_ELAPSED_NOTICE_POPUP
    fontData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("labelTitle",QStringList{
                                                        "Validez de calibración"
                                                    });

    fontData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));

    textData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("elapsedText",QStringList{
                                                        "Expira en 1 día",
                                                        "Expira en 2 días",
                                                        "Expira en 3 días",
                                                        "Expira en 4 días",
                                                        "Expira en 5 días",
                                                        "Expira en 6 días",
                                                        "Expira en 7 días",
                                                        "Expira en 8 días",
                                                        "Expira en 9 días",
                                                        "Expira en 10 días",
                                                        "Expira en 11 días",
                                                        "Expira en 12 días",
                                                        "Expira en 13 días",
                                                        "Expira en 14 días",
                                                        "Expira en 15 días"
                                                    });

    textData[Lan][PAGE_ELAPSED_NOTICE_POPUP].insert("warningText",QStringList{
                                                        "Vencido (sin medición)"
                                                    });

    //PAGE_BLOOD_CHECK
    fontData[Lan][PAGE_BLOOD_CHECK].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_BLOOD_CHECK].insert("labelText",QStringList{
                                               "¿Es un valor medido \nen un centro médico?"
                                           });

    //PAGE_BLOOD_NOTICE_POPUP
    fontData[Lan][PAGE_BLOOD_NOTICE_POPUP].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_BLOOD_NOTICE_POPUP].insert("labelText",QStringList{
                                                      "Fuera del rango de medición"
                                                  });

    //PAGE_USER_CHECK
    fontData[Lan][PAGE_USER_CHECK].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK].insert("labelText",QStringList{
                                              "Prediabetes",
                                              "No diabético",
                                              "Diabetes"
                                          });
    fontData[Lan][PAGE_USER_CHECK].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK].insert("labelTitle",QStringList{
                                              "Seleccione el tipo de usuario"
                                          });

    //PAGE_BLOOD_CHECK_NOTICE //unused
    fontData[Lan][PAGE_BLOOD_CHECK_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_BLOOD_CHECK_NOTICE].insert("labelText",QStringList{
                                                      "No hay datos de sangre venosa.\nIngrese la información."
                                                  });

    //PAGE_CALI_VALUE_NOTICE //unused
    fontData[Lan][PAGE_CALI_VALUE_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_VALUE_NOTICE].insert("labelText",QStringList{
                                                     "Fuera del rango 70–350.\nIngrese un valor válido."
                                                 });

    //PAGE_USER_NOTICE
    fontData[Lan][PAGE_USER_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_NOTICE].insert("labelText",QStringList{
                                               "Este producto es para\n pacientes prediabéticos\nque no usan medicación."
                                           });

    //PAGE_USER_FINGER
    fontData[Lan][PAGE_USER_FINGER].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_FINGER].insert("labelTitle",QStringList{
                                               "Perímetro de dedo recomendado"
                                           });

    //PAGE_CALI_NOTICE
    fontData[Lan][PAGE_CALI_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_NOTICE].insert("labelText",QStringList{
                                               "¿Desea recalibrar?"
                                           });

    //PAGE_USER_CHECK_NOTICE
    fontData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelText",QStringList{
                                                     "Usuario objetivo: Ninguno",
                                                     "Usuario objetivo: No diabético",
                                                     "Usuario objetivo: Prediabetes",
                                                     "Usuario objetivo: Diabetes"
                                                 });

    fontData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelCaliDay",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CHECK_NOTICE].insert("labelCaliDay",QStringList{
                                                     "Fecha de calibración: "
                                                 });

    //PAGE_USER_CAUTIONS
    fontData[Lan][PAGE_USER_CAUTIONS].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CAUTIONS].insert("labelTitle",QStringList{
                                                 "Precauciones de HappyZone"
                                             });

    fontData[Lan][PAGE_USER_CAUTIONS].insert("labelText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_USER_CAUTIONS].insert("labelText",QStringList{
                                                 "1. Mantenga una respiración constante",
                                                 "2. Evite hablar y moverse\ndurante la medición",
                                                 "3. No aplique fuerza ni presión\nen el dedo",
                                                 "4. Asegúrese de que el dedo\nesté seco y limpio",
                                                 "5. Mantenga la temperatura\nsuperficial del dedo en 26 °C o más",
                                                 "6. Coloque el dedo\nfirmemente sobre el sensor\ny manténgalo nivelado",
                                                 "7. Desconecte el cargador antes de usar",
                                                 "8. Verifique la temperatura ambiente\n(15–35 °C)",
                                             });

    //PAGE_CALI_SELECT_RE
    fontData[Lan][PAGE_CALI_SELECT_RE].insert("labelText",QFont(currentFont,instance.pixelToPoint(24),QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_RE].insert("labelText",QStringList{
                                                  "Ejemplo",
                                                  "Ayuno 01",
                                                  "Ayuno 02",
                                                  "Después de\ncomer 01",
                                                  "Después de\ncomer 02",
                                                  "Después de\ncomer 03",
                                              });

    fontData[Lan][PAGE_CALI_SELECT_RE].insert("labelTextValue",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));

    //PAGE_HELP
    fontData[Lan][PAGE_HELP].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_HELP].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(26),QFont::Bold));
    textData[Lan][PAGE_HELP].insert("labelText",QStringList{
                                        "¿Qué es este producto?", // 0
                                        "¿Para qué se usa este producto?", // 1
                                        "¿Cuáles son las ventajas de este producto?", // 2
                                        "¿Puede usarlo cualquier persona?", // 3
                                        "¿Qué funciones proporciona?", // 4
                                        "¿En qué situaciones es bueno usarlo?", // 5
                                        "¿Es sencilla la medición?", // 6
                                        "¿Hay pasos de preparación antes de la medición?", // 7
                                        "¿Qué es la calibración de glucosa en sangre?", // 8
                                        "¿Es obligatoria la calibración de glucosa en sangre?", // 9
                                        "¿Hay un ciclo de calibración?", // 10
                                        "¿Hay precauciones antes de la medición?", // 11
                                        "¿Hay precauciones durante la medición?", // 12
                                        "¿Es necesaria la consulta con un profesional médico?", // 13
                                        "¿Cómo se realiza la medición?", // 14
                                        "¿Es automático el proceso de medición?", // 15
                                        "¿Cuánto tiempo tarda la medición?", // 16
                                        "¿Cómo se muestran los resultados?", // 17
                                        "¿Qué significan los resultados?", // 18
                                        "¿Se pueden ajustar los colores de resultado?", // 19
                                        "¿Cómo se pueden utilizar los resultados?", // 20
                                        "¿Se guardan los registros de medición?", // 21
                                        "¿Son precisos los resultados de la medición?", // 22
                                        "¿Afecta el entorno de medición a los resultados?", // 23
                                        "¿Cómo se debe almacenar?", // 24
                                        "¿Es resistente al agua?", // 25
                                        "¿Cuáles son las limitaciones de este producto?", // 26
                                        "¿Es este producto para diagnóstico?", // 27
                                        "¿Cómo se suministra la energía?", // 28
                                        "¿Cuál es el tiempo de uso del producto?", // 29
                                        "¿Cómo se carga?", // 30
                                    });
    fontData[Lan][PAGE_HELP].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_HELP].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));

    //PAGE_FAQ
    fontData[Lan][PAGE_FAQ].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_FAQ].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(26),QFont::Bold));
    textData[Lan][PAGE_FAQ].insert("labelText",QStringList{
                                       "¿Existe un rango de medición de glucosa en sangre?", // 0
                                       "¿Dónde puedo consultar los resultados de glucosa en sangre?", // 1
                                       "¿Qué hacer si el valor es repentinamente alto o bajo?", // 2
                                       "¿Por qué es necesaria la calibración de glucosa en sangre?", // 3
                                       "¿Qué pasa si no realizo la calibración de glucosa en sangre?", // 4
                                       "¿Puedo medir después de que venza el plazo de calibración?", // 5
                                       "¿Por qué es necesario calibrar la glucosa cada 90 días?", // 6
                                       "¿Qué hacer si falla la medición?", // 7
                                       "¿Puedo medir con un dedo diferente?", // 8
                                       "¿Qué hacer si la posición del dedo es incorrecta?", // 9
                                       "¿Afecta a los resultados una postura de medición incorrecta?", // 10
                                       "¿Importa si el tiempo de medición no es el correcto?", // 11
                                       "¿Afecta la temperatura baja o alta a los resultados?", // 12
                                       "¿Puedo medir con las manos mojadas?", // 13
                                       "¿Puedo medir inmediatamente después del ejercicio?", // 14
                                       "¿Es correcto que entre luz solar directa en el producto?", // 15
                                       "¿Pueden usarlo las mujeres embarazadas?", // 16
                                       "¿Pueden usarlo los pacientes con diabetes?", // 17
                                       "¿Pueden usarlo los pacientes en diálisis?", // 18
                                       "¿Se puede usar aunque haya una herida en el área de medición?", // 19
                                       "¿Pueden varias personas usarlo juntas?", // 20
                                       "¿Se puede usar sin un teléfono inteligente?", // 21
                                       "¿Se puede usar mientras se carga?", // 22
                                       "¿Cuánto tiempo tarda una carga completa de la batería?", // 23
                                       "¿Qué hacer si el rendimiento de la batería parece disminuido?", // 24
                                       "¿Se puede limpiar con agua?", // 25
                                       "¿Se puede limpiar con detergentes, alcohol, acetona, etc.?", // 26
                                       "¿Se puede usar de forma portátil?", // 27
                                       "¿Es necesario usar el estuche de almacenamiento portátil?", // 28
                                       "¿Está permitido el equipaje de mano en aviones?", // 29
                                       "¿Se puede enviar como equipaje facturado?", // 30
                                       "¿Qué es el método de transmisión óptica?", // 31
                                       "¿Cuál es el período de A/S?", // 32
                                   });
    fontData[Lan][PAGE_FAQ].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_FAQ].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));

    //PAGE_ERROR_HELP
    fontData[Lan][PAGE_ERROR_HELP].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(26),QFont::Bold));
    textData[Lan][PAGE_ERROR_HELP].insert("labelText",QStringList{
                                              "La falla de medición ocurre con frecuencia", // 0
                                              "Indica que el dedo no fue reconocido", // 1
                                              "Indica que la temperatura de la superficie del dedo es baja", // 2
                                              "Indica que hay un error en los datos de medición", // 3
                                              "Indica que los resultados de medición no se pueden analizar", // 4
                                              "¿Puedo cancelar durante la medición?", // 5
                                              "El nivel de glucosa en sangre es diferente al habitual", // 6
                                              "Creo que la glucosa es normal pero aparece una advertencia", // 7
                                              "Indica que la calibración de glucosa ha vencido", // 8
                                              "¿Se eliminan los registros anteriores al restablecer la calibración?", // 9
                                              "¿Se pueden recuperar los registros de glucosa eliminados?", // 10
                                              "La carga no funciona", // 11
                                              "¿Qué hacer cuando aparece una notificación de batería baja?", // 12
                                              "Apareció la notificación de batería baja y el producto se apagó", // 13
                                              "Después de encender, no entra en la pantalla inicial", // 14
                                              "Indica que no se puede ver el archivo de actualización", // 15
                                              "Indica que hay un problema con el archivo de actualización", // 16
                                              "Indica que no es un archivo de actualización", // 17
                                              "El dispositivo se apagó durante la actualización", // 18
                                              "La pantalla está congelada o muy lenta", // 19
                                              "No sé qué error es este", // 20
                                              "Se ha producido un problema con el dispositivo", // 21
                                              "¿Qué hacer si el problema no se resuelve?", // 22
                                              "¿Qué consumibles adicionales se necesitan al usar el producto?", // 23
                                          });
    fontData[Lan][PAGE_ERROR_HELP].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));

    //PAGE_RESPONSE
    fontData[Lan][PAGE_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_RESPONSE].insert("labelTextHelp",QStringList{
                                            "Este producto mide la glucosa en sangre utilizando un sistema óptico", // 0
                                            "Se utiliza para medir la glucosa en sangre en el cuerpo", // 1
                                            "La ventaja es que se puede medir sin dolor mediante un método de medición no invasivo", // 2
                                            "Puede ser utilizado por pacientes en etapa de prediabetes que no reciben tratamiento farmacológico"
                                            "@Este producto está diseñado para adultos de 19 a 74 años", // 3
                                            "Proporciona funciones de medición de glucosa en sangre, almacenamiento y visualización de registros", // 4
                                            "Se recomienda utilizarlo para verificar los cambios diarios de glucosa en sangre", // 5
                                            "La medición es sencilla"
                                            "@Siga las instrucciones para realizar la medición", // 6
                                            "Se requiere calibración de glucosa en sangre antes de la medición"
                                            "@Siga las instrucciones para realizar la calibración", // 7
                                            "Se refiere al trabajo de calibración para reducir el error entre los valores reales de glucosa en sangre y el producto", // 8
                                            "Sí. Debe realizarse antes de la medición", // 9
                                            "La calibración de glucosa en sangre debe realizarse dentro de los 90 días a partir de la fecha de finalización"
                                            "@Si no se realiza, no se puede medir", // 10
                                            "Lávese bien las manos y elimine la humedad antes de la medición"
                                            "@Desconecte el cargador del producto", // 11
                                            "Evite moverse o aplicar fuerte presión en el dedo durante la medición"
                                            "@Si el dedo se movió debido a la tos o estornudos, vuelva a medir", // 12
                                            "En las siguientes situaciones los valores pueden ser inexactos, se requiere consulta médica"
                                            "@Menores de 19 años o mayores de 74 años"
                                            "@Enfermedades de la piel o heridas en áreas expuestas a la luz"
                                            "@Temblores en las manos como hiperhidrosis, enfermedad de Parkinson"
                                            "@Historial de hipoglucemia grave, cetoacidosis diabética, epilepsia, síncope, enfermedades suprarrenales"
                                            "@En hemodiálisis o diálisis peritoneal"
                                            "@Mujeres embarazadas o en período de lactancia", // 13
                                            "Seleccione la franja horaria de medición en la pantalla de inicio y siga las instrucciones", // 14
                                            "Al presionar el botón de inicio de medición, el proceso avanzará automáticamente hasta completarse", // 15
                                            "La medición se completa en menos de 1 minuto", // 16
                                            "Los resultados se muestran como números cuando se completa la medición", // 17
                                            "Los colores tienen los siguientes significados"
                                            "@Verde significa normal"
                                            "@Naranja significa precaución"
                                            "@Rojo significa advertencia", // 18
                                            "Puede ajustar el rango de color normal a través del menú de rango de glucosa en sangre", // 19
                                            "Úselo como referencia durante el control de glucosa en sangre"
                                            "@Los valores mostrados son solo información de referencia"
                                            "@Consulte a un profesional médico si se requiere juicio médico", // 20
                                            "Los registros de medición se almacenan en el dispositivo por un máximo de 90 días"
                                            "@Los registros posteriores a los 90 días se eliminan automáticamente", // 21
                                            "Puede variar dependiendo de las condiciones del entorno de uso"
                                            "@Por favor, úselo de acuerdo con las instrucciones de uso", // 22
                                            "Sí. Evite los siguientes entornos"
                                            "@Evite lugares con luz solar directa intensa"
                                            "@Evite lugares con viento fuerte"
                                            "@Evite entornos húmedos"
                                            "@Evite entornos con vibraciones"
                                            "@Evite lugares donde la temperatura interior sea demasiado baja o alta\n*Temperatura óptima: 10~35°C (50~95°F)", // 23
                                            "Apague el dispositivo, cubra la abertura para el dedo y guárdelo en el estuche de almacenamiento", // 24
                                            "No es resistente al agua", // 25
                                            "Este producto es un dispositivo para verificar el estado diario"
                                            "@No está destinado al diagnóstico médico", // 26
                                            "Este producto proporciona información para referencia"
                                            "@No puede reemplazar el diagnóstico médico o las decisiones de tratamiento"
                                            "@Siempre consulte a un profesional médico cuando se requieran acciones médicas como diagnóstico de diabetes, tratamiento o administración de insulina", // 27 long
                                            "La energía se suministra a través de una batería de polímero de iones de litio", // 28
                                            "Cuando está completamente cargado, se puede usar hasta aproximadamente 29 días en modo de espera", // 29
                                            "Se carga utilizando un cargador de tipo USB C que cumpla con el estándar de 5V DC / 2A~2.4A", // 30
                                        });
    textData[Lan][PAGE_RESPONSE].insert("labelTextFaq",QStringList{
                                            "La medición es posible en el rango de 70~350 mg/dL", // 0
                                            "Los registros del día se pueden ver en la pantalla de inicio"
                                            "@Consulte los registros anteriores de glucosa en el menú de registros de glucosa", // 1
                                            "Verifique el entorno de uso correcto y la postura de medición, luego vuelva a medir", // 2
                                            "Debido a que las características individuales son diferentes, es necesario ajustar las características del producto a cada persona", // 3
                                            "No podrá medir sin la calibración de glucosa en sangre", // 4
                                            "Una vez vencido el plazo, no será posible medir, así que realice la calibración nuevamente", // 5
                                            "Se debe realizar la calibración nuevamente cada 90 días para una medición precisa", // 6
                                            "Si la medición falla, aparecerá una ventana de notificación con el motivo del fallo"
                                            "@Verifique el problema de fallo de medición en el menú de solución de problemas", // 7
                                            "Para una medición precisa, se recomienda medir con el dedo en el que se realizó la calibración", // 8
                                            "No se puede medir con precisión"
                                            "@Para una medición precisa, relaje el dedo y colóquelo de manera que el centro cubra suavemente el extremo del sensor", // 9
                                            "Si la postura de medición es incorrecta, la medición puede no ser precisa"
                                            "@Mida en la postura correcta para una medición precisa", // 10
                                            "No afecta los resultados de la medición"
                                            "@Sin embargo, si planea usarlo como datos de control de glucosa, se recomienda medir en el momento apropiado", // 11
                                            "Si la temperatura es demasiado baja o alta, los valores de medición pueden no ser precisos", // 12
                                            "No mida con las manos mojadas"
                                            "@Puede causar mal funcionamiento del producto", // 13
                                            "No mida inmediatamente después del ejercicio"
                                            "@Mida después de que la respiración y la frecuencia cardíaca se hayan estabilizado", // 14
                                            "No se puede medir con precisión"
                                            "@Para una medición precisa, mida en interiores sin luz solar directa", // 15
                                            "Los resultados de la medición pueden no ser precisos"
                                            "@Consulte a un profesional médico", // 16
                                            "Los resultados de la medición pueden no ser precisos"
                                            "@Consulte a un profesional médico", // 17
                                            "Los resultados de la medición pueden no ser precisos"
                                            "@Consulte a un profesional médico", // 18
                                            "Los resultados de la medición pueden no ser precisos"
                                            "@Consulte a un profesional médico", // 19
                                            "Se puede usar simultáneamente por un máximo de 2 personas", // 20
                                            "El producto se puede usar de forma independiente", // 21
                                            "Asegúrese de desconectar el cargador antes de usar", // 22
                                            "El tiempo de carga completa tarda aproximadamente 3 horas y 45 minutos", // 23
                                            "Comuníquese con el centro de A/S para inspección y reemplazo si es necesario", // 24
                                            "No limpie con agua"
                                            "@Puede causar mal funcionamiento del producto", // 25
                                            "No limpie con detergentes, alcohol, acetona, etc."
                                            "@Puede causar mal funcionamiento del producto", // 26
                                            "Sí, puede llevarlo y usarlo"
                                            "@Úselo en un entorno interior adecuado para la medición", // 27
                                            "Los impactos externos pueden causar mal funcionamiento, así que llévelo en el estuche de almacenamiento portátil", // 28
                                            "Se puede llevar y usar en la cabina de un avión"
                                            "@No se puede enviar como equipaje facturado", // 29
                                            "No se puede enviar como equipaje facturado"
                                            "@Este producto contiene una batería de polímero de iones de litio y no se puede enviar como equipaje facturado según las regulaciones de seguridad"
                                            "@Debe llevarse como equipaje de mano", // 30
                                            "Es un método que mide la glucosa en sangre analizando la luz que pasa a través del dedo", // 31
                                            "El período oficial de A/S es de 24 meses después de la compra del producto", // 32
                                        });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp",QStringList{
                                                  "Verifique el siguiente entorno de medición y vuelva a medir"
                                                  "@No tosa, estornude ni hable, y no se mueva durante la medición"
                                                  "@Relaje el dedo y colóquelo horizontalmente en la superficie"
                                                  "@Mantenga la temperatura de la superficie del dedo por encima de 26°C(79°F)"
                                                  "@Elimine la humedad y los cuerpos extraños del dedo", // 0
                                                  "Verifique si el dedo está insertado correctamente y vuelva a medir"
                                                  "@Para una medición precisa, relaje el dedo y colóquelo de manera que el centro cubra suavemente el extremo del sensor", // 1
                                                  "Caliente suficientemente el dedo y vuelva a medir", // 2
                                                  "Ocurre cuando los datos de medición están incompletos o se detectan valores que no se pueden analizar"
                                                  "@Evite los temblores de manos, los estornudos y las conversaciones", // 3
                                                  "Ocurre cuando la desviación de los valores de glucosa medidos excede el rango"
                                                  "@Verifique la posición de medición del dedo y el entorno, luego vuelva a medir", // 4
                                                  "Presionar el botón 'Cancelar' durante la medición la detendrá", // 5
                                                  "Verifique el entorno de medición y vuelva a medir"
                                                  "@Si el entorno de medición no tiene ningún efecto, verifique lo siguiente"
                                                  "@Verifique si hay síntomas de hipoglucemia o hiperglucemia"
                                                  "@Si sospecha que es constantemente inexacto, consulte a un profesional médico", // 6
                                                  "Verifique y ajuste el rango normal en el menú de rango de glucosa en sangre", // 7
                                                  "No es posible medir cuando vence el período de validez de la calibración (90 días)"
                                                  "@Por favor realice la calibración de glucosa en sangre", // 8
                                                  "Los registros no se eliminan incluso después de la inicialización", // 9
                                                  "No se puede recuperar"
                                                  "Tenga cuidado al eliminar registros de glucosa en sangre", // 10
                                                  "Verifique si es un cargador de batería nominal"
                                                  "@Si la carga no es posible incluso con un cargador nominal, comuníquese con el centro de A/S", // 11
                                                  "Por favor, cargue usando el cargador", // 12
                                                  "Cuando la batería está por debajo del 5%, el producto se apagará después de 5 segundos para proteger el sistema"
                                                  "@Por favor, cargue usando el cargador", // 13
                                                  "Cargue la batería usando un cargador de batería nominal"
                                                  "@Después de completar la carga, cuando el arranque se complete al volver a encender, se puede usar normalmente", // 14
                                                  "Por favor verifique el archivo de actualización nuevamente", // 15
                                                  "Descargue el archivo de actualización nuevamente e inténtelo de nuevo", // 16
                                                  "Verifique si el archivo es el correcto e inténtelo de nuevo", // 17
                                                  "Inténtelo de nuevo después de cargar"
                                                  "@Si el mismo fenómeno ocurre después de cargar, comuníquese con el centro de A/S", // 18
                                                  "Use un pin para presionar el botón de reinicio"
                                                  "@Si el mismo fenómeno ocurre después de cargar, comuníquese con el centro de A/S", // 19
                                                  "Primero reinicie el producto y verifique si ocurre el mismo error"
                                                  "@O actualice la versión del software del producto a la última versión"
                                                  "@Si el mismo fenómeno ocurre, comuníquese con el centro de A/S", // 20
                                                  "Este es un caso en el que se ha producido un problema con el producto"
                                                  "@Intente reiniciar y actualizar"
                                                  "@Si el mismo fenómeno ocurre, comuníquese con el centro de A/S", // 21
                                                  "Por favor comuníquese con el centro de A/S", // 22
                                                  "No hay consumibles adicionales", // 23
                                              });
    fontData[Lan][PAGE_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_RESPONSE].insert("labelPageNum",QFont(currentFont,instance.pixelToPoint(28)));

#if FONT_DEBUG
    for(const auto& textName : fontData[KR][PAGE_PASSWORD].keys())
    {
        QFont font = fontData[KR][PAGE_PASSWORD][textName];
        qDebug() <<"TextName: "<< textName << "->" << QFontInfo(font).family();
    }
#endif
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

/*
QFont TextResource::getFont(PageNum page, const QString& textName)
{
    DeviceLanguage lang = instance.getDeviceLanguage();

    if (fontData.contains(lang) && fontData[lang].contains(page))
    {
        if (fontData[lang][page].contains(textName)) {
            return fontData[lang][page].value(textName, QFont("Default", 12));
        } else {
            qDebug() << "getFont fail: TextName not found ->"
                     << "Page:" << page << ", TextName:" << textName;
        }
    }
    else
    {
        qDebug() << "getFont fail: Language or Page not found ->"
                 << "Language:" << lang << ", Page:" << page;
    }

    return QFont("Default", 12);
}
*/

QFont TextResource::getFont(PageNum page, const QString& textName)
{
    DeviceLanguage lang = instance.getDeviceLanguage();

    QFont font("Default", 12); // 기본값

    if (fontData.contains(lang) && fontData[lang].contains(page))
    {
        if (fontData[lang][page].contains(textName)) {
            font = fontData[lang][page].value(textName);
#if FONT_DEBUG
            QFontInfo fontInfo(font);
            qDebug() << "fontInfo: "<< fontInfo.family();
#endif
        } else {
            qDebug() << "getFont fail: TextName not found ->" << "Page:" << page << ", TextName:" << textName;
        }
    }
    else
    {
        qDebug() << "getFont fail: Language or Page not found ->" << "Language:" << lang << ", Page:" << page;
    }

    // 💡 여기서 폰트 렌더링 설정 추가
    font.setHintingPreference(QFont::PreferFullHinting);
    font.setStyleStrategy(QFont::PreferAntialias);
    //font.setStyleStrategy(QFont::NoFontMerging);
    //QFontInfo info(font);
    //qDebug()<<"Actual font family in use: "<<info.family();
    //qDebug()<<"Current QSS: "<< qApp->styleSheet();
    return font;
}

