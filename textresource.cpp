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
    DeviceLanguage Lan = ko;
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
                                         "简体中文",
                                         "繁體中文",
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

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonReboot",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonReboot",QStringList{"재부팅"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QStringList{"네"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QStringList{"아니오"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QStringList{
                                            "한국어",
                                            "ENGLISH",
                                            "日本語",
                                            "简体中文",
                                            "繁體中文",
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
                                               "기기에 문제가 발생했습니다\n고객상담실로 문의해 주세요",                // 2
                                               "기기에 문제가 발생했습니다\n고객상담실로 문의해 주세요",              // 3
                                               "측정 결과를 분석할 수 없습니다\n다시 측정해 주세요",             // 4
                                               "측정된 데이터에 오류가 있습니다\n다시 측정해 주세요",             // 5
                                               "충전 중에는 측정하실 수 없습니다\n제거 후 측정해 주세요",    //6
                                               "손가락 표면온도가 낮아\n측정할 수 없습니다",               // 7
                                               "측정에 실패했습니다\n고객상담실로 문의해 주세요",              // 8
                                           });

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade",QFont(currentFont,instance.pixelToPoint(42),QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade",QStringList{
                                               "업그레이드에 성공하였습니다", // 0
                                               "업그레이드가 실패했습니다\n고객상담실에 문의해 주세요", //1
                                               "업그레이드 파일이 보이지 않습니다\n파일을 다시 확인해 주세요", //2
                                               "업그레이드 파일에 문제가 있습니다\n새 파일로 다시 시도해 주세요", //3
                                               "업그레이드용 파일이 아닙니다\n올바른 파일인지 확인해 주세요", //4
                                               "업그레이드가 실패했습니다\n고객상담실에 문의해 주세요" //5
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
                                                 "만 19세 미만인 경우,\n"
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
                                                "@혈당보정일로부터 90일이 경과하면 혈당보정 유효기간만료 알림이 발생하며 재보정을 완료하기 전까지 혈당 측정이 제한됩니다."
                                                "@혈당보정 초기화 후 재보정을 수행하면 혈당 측정이 다시 가능합니다.",
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
                                                "@항공사 및 국가별 규정이 상이할 수 있으므로, 탑승 전 이용 항공사에 확인하시기 바랍니다."
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
                                              "앱 연동이 안돼요", // 2-0
                                              "제품의 측정 수치와 앱의 측정 수치가 달라요", // 2-1
                                          });
    // 카테고리 3: 혈당기록
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp3",QStringList{
                                              "혈당보정 초기화 시 이전 측정 기록도 삭제되나요?", // 3-0
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
                                                  "전원을 껐다 다시켜보세요.\n"
                                                  "배터리가 충분한지 확인하세요.\n"
                                                  "충전기를 꽂은 상태로는 측정이 되지 않습니다.",
                                                  "@물이 닿거나 습도가 높은곳에 보관 했었다면 고장의 원인이 될 수 있습니다. 제품 상태를 확인하세요.",
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
                                                  "충전 케이블 및 어댑터 연결 상태를 확인해 주세요.\n"
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
                                                  "날짜와 측정항목을 확인해주세요.\n"
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

    //PAGE_RESPONSE
    fontData[Lan][PAGE_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_RESPONSE].insert("labelPageNum",QFont(currentFont,instance.pixelToPoint(28)));

    //====================================================================================================================================
    //EN
    Lan = en;
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
                                         "简体中文",
                                         "繁體中文",
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

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonReboot",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonReboot",QStringList{"Reboot"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QStringList{"Yes"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QStringList{"No"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QStringList{
                                            "한국어",
                                            "ENGLISH",
                                            "日本語",
                                            "简体中文",
                                            "繁體中文",
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
                                               "Device error.\nContact customer service",                          // 2
                                               "Device error.\nContact customer service",                          // 3
                                               "Analysis failed.\nTry again",                             // 4
                                               "Invalid data.\nTry again",                                // 5
                                               "Cannot measure while charging.\nUnplug and retry",        // 6
                                               "Finger too cold,\nCannot measure",                        // 7
                                               "Measurement failed.\nContact customer service",                    // 8
                                           });

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QFont(currentFont, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QStringList{
                                               "Upgrade completed successfully", // 0
                                               "Upgrade failed.\nPlease contact customer service", // 1
                                               "Upgrade file not found.\nPlease check the file again", // 2
                                               "There is a problem with the upgrade file.\nPlease try again with a new file", // 3
                                               "This is not a valid upgrade file.\nPlease check if the file is correct", // 4
                                               "Upgrade failed.\nPlease contact customer service" // 5
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
                                                 "5. Keep finger surface temperature\nat or above 26°C (79°F)",
                                                 "6. Place the finger firmly on the sensor\n and keep it level",
                                                 "7. Disconnect the charger before use",
                                                 "8. Check ambient temperature (15–35°C / 59–95°F)",
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
    // Category 0: Product Description & Purpose
    textData[Lan][PAGE_HELP].insert("labelTextHelp0",QStringList{
                                        "Who are the target users?", // 0-0
                                        "What are the main features of the product?", // 0-1
                                        "What is the purpose of the product and what should I be cautious about?", // 0-2
                                    });
    // Category 1: Measurement Precautions
    textData[Lan][PAGE_HELP].insert("labelTextHelp1",QStringList{
                                        "What should I observe for accurate measurement?", // 1-0
                                    });
    // Category 2: Measurement Limitations & Consultation
    textData[Lan][PAGE_HELP].insert("labelTextHelp2",QStringList{
                                        "When should I consult a medical professional because measurement values may be inaccurate?", // 2-0
                                    });
    // Category 3: Alert Functions
    textData[Lan][PAGE_HELP].insert("labelTextHelp3",QStringList{
                                        "Does the product have alert functions?", // 3-0
                                    });

    //PAGE_HELP_RESPONSE
    fontData[Lan][PAGE_HELP_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_HELP_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_HELP_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(32),QFont::Bold));
    // Help 0: Target Users
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp0",QStringList{
                                                 "The target users are adult males and females aged 19 and older who are in the pre-diabetic stage.",
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
                                                 "Under 19 years of age,\n"
                                                 "Skin diseases or wounds in light-exposed areas,\n hand tremors such as hyperhidrosis or Parkinson's disease,"
                                                 "@Severe hypoglycemia, diabetic ketoacidosis, epilepsy, syncope,\nor history of adrenal disease,"
                                                 "@Undergoing hemodialysis or\nperitoneal dialysis,\npregnant or breastfeeding",
                                             });
    // Help 5: Key Features
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp5",QStringList{
                                                 "* High/low blood glucose alerts\n"
                                                 "* Calibration expiry alerts\n"
                                                 "* Blood glucose re-calibration alerts",
                                                 "A calibration expiry alert occurs when 90 days have passed from the calibration date.",
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
    fontData[Lan][PAGE_FAQ].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_FAQ].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_FAQ].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    // Category 0: Blood Glucose Calibration
    textData[Lan][PAGE_FAQ].insert("labelTextFaq0",QStringList{
                                       "What is 'Blood Glucose Calibration'?", // 0-0
                                       "Is blood glucose calibration mandatory?", // 0-1
                                       "When should blood glucose calibration be done?", // 0-2
                                       "How often should blood glucose calibration be done?", // 0-3
                                       "Are previous measurement records deleted when calibration is reset?", // 0-4
                                   });
    // Category 1: Blood Glucose Measurement
    textData[Lan][PAGE_FAQ].insert("labelTextFaq1",QStringList{
                                       "What is the correct measurement posture?", // 1-0
                                       "How should I position my finger?", // 1-1
                                       "Do I have to measure with the same finger every time?", // 1-2
                                       "Where is a suitable place for measurement?", // 1-3
                                       "Can I measure with wet hands?", // 1-4
                                       "How many times a day should I measure?", // 1-5
                                       "How long does a measurement take?", // 1-6
                                       "Can I cancel during measurement?", // 1-7
                                       "Measurement won't start.", // 1-8
                                       "Measurement failure occurs frequently.", // 1-9
                                       "What is the correct finger position for measurement?", // 1-10
                                       "What is the blood glucose measurement range?", // 1-11
                                   });
    // Category 2: Device Care
    textData[Lan][PAGE_FAQ].insert("labelTextFaq2",QStringList{
                                       "How long does a full charge take?", // 2-0
                                       "How long does the battery last?", // 2-1
                                       "Can it be used while charging?", // 2-2
                                       "Is it waterproof?", // 2-3
                                       "How should I care for the product?", // 2-4
                                       "Are there places to avoid when storing?", // 2-5
                                       "Should the finger insertion port cover be closed?", // 2-6
                                   });
    // Category 3: Portability & Travel
    textData[Lan][PAGE_FAQ].insert("labelTextFaq3",QStringList{
                                       "Can it be used as a portable device?", // 3-0
                                       "Can it be carried on an aircraft?", // 3-1
                                       "Can it be sent as checked baggage on an aircraft?", // 3-2
                                   });
    // Category 4: Blood Glucose Records
    textData[Lan][PAGE_FAQ].insert("labelTextFaq4",QStringList{
                                       "Where can I view blood glucose measurement results?", // 4-0
                                       "How long are blood glucose records stored?", // 4-1
                                   });
    // Category 5: Target Users / Number of Users
    textData[Lan][PAGE_FAQ].insert("labelTextFaq5",QStringList{
                                       "Can anyone use it?", // 5-0
                                       "How many people can use one device?", // 5-1
                                   });
    // Category 6: A/S
    textData[Lan][PAGE_FAQ].insert("labelTextFaq6",QStringList{
                                       "What is the A/S warranty period?", // 6-0
                                       "Couldn't find the answer you were looking for?", // 6-1
                                   });
    // Category 7: Password
    textData[Lan][PAGE_FAQ].insert("labelTextFaq7",QStringList{
                                       "How do I change my password?", // 7-0
                                   });

    //PAGE_FAQ_RESPONSE
    fontData[Lan][PAGE_FAQ_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_FAQ_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_FAQ_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(32),QFont::Bold));
    // FAQ Category 0: Blood Glucose Calibration
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-0",QStringList{
                                                "It is a process of calculating and adjusting blood glucose values by linking with an invasive device"
                                                "@to reduce the error between actual blood glucose values and the product.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-1",QStringList{
                                                "Yes. Since each user has different light transmittance depending on the structure of the measurement area and external environment,"
                                                "@individual blood glucose calibration is essential for accurate blood glucose measurement values.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-2",QStringList{
                                                "Blood glucose calibration must be performed before first use. After that, re-calibration must be done within 90 days from the calibration date."
                                                "@You will be notified of the re-calibration timing through alerts starting 15 days before the calibration expiration date.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-3",QStringList{
                                                "Re-calibration must be done within 90 days from the calibration date to correct errors due to changes in the measurement area and environment."
                                                "@When 90 days have passed from the calibration date, a calibration expiry alert occurs and blood glucose measurement is restricted until re-calibration is completed."
                                                "@Blood glucose measurement becomes available again after performing re-calibration following calibration reset.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-4",QStringList{
                                                "No. Even if blood glucose calibration is reset, the recorded blood glucose records are stored on the product for up to 90 days."
                                                "@Records are stored on the app for up to 12 months.",
                                            });
    // FAQ Category 1: Blood Glucose Measurement
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-0",QStringList{
                                                "Sit down and place your elbow on a table, keeping it level."
                                                "@Relax your finger and insert it fully to the end of the insertion port, pressing it flat against the bottom surface inside.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-1",QStringList{
                                                "Push your finger in with the fingerprint side touching the bottom surface.\nWhen your fingertip catches, relax and hold your position.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-2",QStringList{
                                                "It is recommended to measure with the same finger for accurate measurement.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-3",QStringList{
                                                "Measure in an indoor environment at 20-30°C (68-86°F), free from direct sunlight, wind, humidity, vibration, and other factors that may affect the product.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-4",QStringList{
                                                "No. Measuring with wet hands may cause product malfunction.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-5",QStringList{
                                                "Since blood glucose fluctuates with meals and activities, it is recommended to measure once after waking, once before and after each meal, and once before bedtime.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-6",QStringList{
                                                "Measurement results appear within 1 minute after starting measurement.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-7",QStringList{
                                                "Press the 'Cancel' button during measurement to stop it.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-8",QStringList{
                                                "Measurement is not possible when the blood glucose calibration validity period (90 days) has expired. Please perform blood glucose calibration.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-9",QStringList{
                                                "Please check the measurement environment and try again.\n"
                                                "The measurement environment is as follows."
                                                "@No coughing, sneezing, talking, or moving during measurement\n"
                                                "Relax your finger and press it flat against the surface"
                                                "@Maintain finger surface temperature above 26°C (79°F)\n"
                                                "Remove moisture and foreign substances from finger"
                                                "@* Please refer to the user manual\n[Error Messages & Solutions]",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-10",QStringList{
                                                "Push your finger in with the fingerprint side touching the bottom surface.\nWhen your fingertip catches, relax and hold your position.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-11",QStringList{
                                                "70-350mg/dL\n\n"
                                                "This product can measure blood glucose levels from a minimum of 70 to a maximum of 350.",
                                            });
    // FAQ Category 2: Device Care
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-0",QStringList{
                                                "The total time required for a full charge of this product is approximately 3 hours and 45 minutes.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-1",QStringList{
                                                "When fully charged, it can be used for up to 29 days based on 8 measurements per day.\nBattery life may vary depending on battery condition.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-2",QStringList{
                                                "Please make sure to disconnect the charger before use.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-3",QStringList{
                                                "No. This product does not have waterproof features, so do not operate it with wet hands."
                                                "@If liquid comes in contact with the product, wipe it off immediately and check for normal operation.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-4",QStringList{
                                                "Wipe with a soft cloth and let it dry before use. Do not use detergents, alcohol, or chemical substances.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-5",QStringList{
                                                "Avoid humid environments (bathrooms, kitchens, etc.) and high-temperature environments above 60°C (140°F)\n(sealed vehicles, direct sunlight exposure, etc.).",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-6",QStringList{
                                                "Yes, always close the cover and store it in the case when not in use."
                                                "@This can prevent product damage or short circuit accidents caused by dust, metal, or sharp objects entering the interior.",
                                            });
    // FAQ Category 3: Portability & Travel
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq3-0",QStringList{
                                                "Yes, it can be charged and carried for use in indoor environments suitable for measurement. However, external impacts may cause malfunction or damage, so"
                                                "@please carry it in the portable case to prevent impacts to the product.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq3-1",QStringList{
                                                "This product's lithium-ion polymer battery (approximately 4.4Wh) meets aviation safety standards (100Wh or less) and can be carried on board."
                                                "@Regulations may vary by airline and country, so please check with your airline before boarding."
                                                "@[ Battery Specs ]\n"
                                                "Voltage: 3.7V\n"
                                                "Capacity: 1200mAh\n"
                                                "Total: 4.44Wh",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq3-2",QStringList{
                                                "This product has a lithium-ion polymer battery (approximately 4.4Wh)."
                                                "@Regulations may vary by airline and country, so please check with your airline before boarding."
                                                "@[ Battery Specs ]\n"
                                                "Voltage: 3.7V\n"
                                                "Capacity: 1200mAh\n"
                                                "Total: 4.44Wh"
                                            });
    // FAQ Category 4: Blood Glucose Records
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq4-0",QStringList{
                                                "Press the 'Blood Glucose Records' icon in the 'Settings Menu' on the product,"
                                                "@or connect to your smartphone via Bluetooth and check in the App."
                                                "@Today's measurement records are automatically displayed on the home screen."
                                                "@Check past blood glucose records by pressing the blood glucose records icon in settings.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq4-1",QStringList{
                                                "This product stores measured blood glucose records for up to 90 days.\n"
                                                "Records older than 90 days are automatically deleted.",
                                            });
    // FAQ Category 5: Target Users / Number of Users
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq5-0",QStringList{
                                                "This is a medical device intended for pre-diabetic patients aged 19 and older not on drug treatment."
                                                "@For medical decisions such as diabetes diagnosis, treatment, or insulin administration, please consult a medical professional.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq5-1",QStringList{
                                                "This product can be used by up to 2 people with one device.",
                                            });
    // FAQ Category 6: A/S
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq6-0",QStringList{
                                                "This product is warranted for up to 2 years from the date of purchase.\nHowever, damage or malfunction due to personal reasons is not covered.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq6-1",QStringList{
                                                "Please contact our customer service center."
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
    fontData[Lan][PAGE_ERROR_HELP].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    // Category 0: Blood Glucose Measurement
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp0",QStringList{
                                              "Measurement won't start", // 0-0
                                              "Measurement failure occurs frequently", // 0-1
                                              "'Finger was not recognized' message appears", // 0-2
                                              "'Finger surface temperature is too low to measure' message appears", // 0-3
                                              "'Measurement data has an error' message appears", // 0-4
                                              "It won't proceed to the next step", // 0-5
                                              "'Measurement results cannot be analyzed' message appears", // 0-6
                                              "Blood glucose seems normal but a warning is displayed", // 0-7
                                          });
    // Category 1: Device Care
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp1",QStringList{
                                              "Buttons are not working", // 1-0
                                              "After booting, it doesn't enter the initial screen", // 1-1
                                              "'Upgrade file is not visible' message appears", // 1-2
                                              "'Upgrade file has a problem' message appears", // 1-3
                                              "'This is not an upgrade file' message appears", // 1-4
                                              "Power turned off during upgrade", // 1-5
                                              "Screen is frozen or too slow", // 1-6
                                              "I don't know what error this is", // 1-7
                                              "Screen is not responding to touch", // 1-8
                                              "Charging is not working", // 1-9
                                          });
    // Category 2: Bluetooth
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp2",QStringList{
                                              "App won't sync", // 2-0
                                              "Product and app measurement values differ", // 2-1
                                          });
    // Category 3: Blood Glucose Records
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp3",QStringList{
                                              "Are previous measurement records deleted when calibration is reset?", // 3-0
                                              "Can deleted blood glucose records be recovered?", // 3-1
                                          });

    //PAGE_ERROR_RESPONSE
    fontData[Lan][PAGE_ERROR_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_ERROR_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_ERROR_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(32),QFont::Bold));
    // ErrorHelp Category 0: Blood Glucose Measurement
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-0",QStringList{
                                                  "Measurement is not possible when the blood glucose calibration validity period (90 days) has expired. Please perform blood glucose calibration.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-1",QStringList{
                                                  "Please check the measurement environment and try again.\n"
                                                  "The measurement environment is as follows."
                                                  "@No coughing, sneezing, talking, or moving during measurement\n"
                                                  "Relax your finger and press it flat against the surface"
                                                  "@Maintain finger surface temperature above 26°C (79°F)\n"
                                                  "Remove moisture and foreign substances from finger"
                                                  "@* Please refer to the user manual\n[Error Messages & Solutions]",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-2",QStringList{
                                                  "Please check if your finger is inserted correctly and measure again."
                                                  "@Push your finger in with the fingerprint side touching the bottom surface.\nWhen your fingertip catches, relax and hold your position.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-3",QStringList{
                                                  "Please warm your finger sufficiently and measure again.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-4",QStringList{
                                                  "Avoid talking, hand tremors, and sneezing, and rest for a while before measuring again.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-5",QStringList{
                                                  "The measurement may not have been completed. Please measure again. If the problem persists, try turning the power button off and on.",
                                                  "If the product was exposed to external environments (low temperature or nearby high-temperature objects), it may malfunction."
                                                  "@Try using it again at an indoor temperature of 20-30°C (68-86°F).",
                                                  "If it was not exposed to temperature, humidity, or moisture, please contact customer service for repair.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-6",QStringList{
                                                  "Please check the finger measurement position and measurement environment, then measure again.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-7",QStringList{
                                                  "Press the blood glucose range icon to adjust the blood glucose status alert range.",
                                              });
    // ErrorHelp Category 1: Device Care
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-0",QStringList{
                                                  "Try turning the power off and on again.\n"
                                                  "Check if the battery is sufficient.\n"
                                                  "Measurement cannot be done while the charger is connected.",
                                                  "@If the product was exposed to water or stored in a highly humid environment, it may be a cause of malfunction. Please check the product condition.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-1",QStringList{
                                                  "Check the charging cable and adapter connection, then charge.\nAfter charging is complete, normal use is possible when the device finishes booting after turning the power on again.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-2",QStringList{
                                                  "Please check the upgrade file again. If the same issue occurs, please contact customer service.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-3",QStringList{
                                                  "Please download the upgrade file again and try with the new file. If the same issue occurs, please contact customer service.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-4",QStringList{
                                                  "Please verify if the file is correct and try again. If the same issue occurs, please contact customer service.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-5",QStringList{
                                                  "Please charge the device and try the upgrade again. If the same issue occurs, please contact customer service.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-6",QStringList{
                                                  "Please press the reset button using a pin. After pressing the reset button, normal use is possible once the system reboots.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-7",QStringList{
                                                  "Please check if the same error occurs after rebooting. If the same issue occurs, please contact customer service.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-8",QStringList{
                                                  "Please try rebooting and check for normal operation. If the same issue occurs, please contact customer service.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-9",QStringList{
                                                  "Please check the charging cable and adapter connection.\n"
                                                  "Please verify that the output specifications of your charging adapter match the product's recommended specifications.@",
                                                  "If the same issue occurs, please contact customer service.",
                                              });
    // ErrorHelp Category 2: Bluetooth
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp2-0",QStringList{
                                                  "Touch the 'Bluetooth' icon on the top bar of the product screen to activate it. Then keep your smartphone within 1M of the product"
                                                  "@and search for Bluetooth on your smartphone to find and link the Happyzone product."
                                                  "@If the problem persists, try turning the product off and on again.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp2-1",QStringList{
                                                  "Please check the date and measurement item.\n"
                                                  "If the problem persists, it may be a temporary error. Try turning off and restarting both the product and app.",
                                              });
    // ErrorHelp Category 3: Blood Glucose Records
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp3-0",QStringList{
                                                  "No. Even if blood glucose calibration is reset, the recorded blood glucose records are stored on the product for up to 90 days.\nRecords are stored on the app for up to 12 months.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp3-1",QStringList{
                                                  "No. Recovery is not possible, so please be careful when deleting blood glucose records.",
                                              });

    fontData[Lan][PAGE_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(32),QFont::Bold));
    fontData[Lan][PAGE_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_RESPONSE].insert("labelPageNum",QFont(currentFont,instance.pixelToPoint(28)));


    //=====================================================================================================================================
    //JP
    Lan = ja;
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
                                         "简体中文",
                                         "繁體中文",
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

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonReboot",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonReboot",QStringList{"再起動"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QStringList{"はい"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QStringList{"いいえ"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QStringList{
                                            "한국어",
                                            "ENGLISH",
                                            "日本語",
                                            "简体中文",
                                            "繁體中文",
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
                                               "デバイスエラーです。\nカスタマーサービスセンターへお問い合わせください", // 2
                                               "デバイスエラーです。\nカスタマーサービスセンターへお問い合わせください", // 3
                                               "解析に失敗しました。\n再度測定してください",         // 4
                                               "データエラーです。\n再度測定してください",           // 5
                                               "充電中は測定できません。\n充電を外して再度お試しください", // 6
                                               "指が冷たすぎます。\n測定できません。",               // 7
                                               "測定に失敗しました。\nカスタマーサービスセンターへお問い合わせください"  // 8
                                           });

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QStringList{
                                               "アップグレードに成功しました", // 0
                                               "アップグレードに失敗しました。\nカスタマーサービスセンターにお問い合わせください", // 1
                                               "アップグレードファイルが見つかりません。\nファイルを再確認してください", // 2
                                               "アップグレードファイルに問題があります。\n新しいファイルで再試行してください", // 3
                                               "アップグレード用のファイルではありません。\n正しいファイルか確認してください", // 4
                                               "アップグレードに失敗しました。\nカスタマーサービスセンターにお問い合わせください" // 5
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

    //PAGE_HELP_INDEX
    fontData[Lan][PAGE_HELP_INDEX].insert("labelText",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_HELP_INDEX].insert("labelText",QStringList{
                                              "使用対象", // 0
                                              "製品案内", // 1
                                              "使用目的", // 2
                                              "測定前の\n注意事項", // 3
                                              "使用前に専門医に\n相談すべき方", // 4
                                              "主要機能\nのご案内", // 5
                                              "ブルートゥース\n対応範囲", // 6
                                          });

    //PAGE_HELP
    fontData[Lan][PAGE_HELP].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_HELP].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_HELP].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_HELP].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    // カテゴリ 0: 製品説明および使用目的
    textData[Lan][PAGE_HELP].insert("labelTextHelp0",QStringList{
                                        "使用対象は誰ですか？", // 0-0
                                        "製品の主要機能は何ですか？", // 0-1
                                        "製品の使用目的と注意点は何ですか？", // 0-2
                                    });
    // カテゴリ 1: 測定注意事項
    textData[Lan][PAGE_HELP].insert("labelTextHelp1",QStringList{
                                        "正確な測定のために測定時に守るべきことは何ですか？", // 1-0
                                    });
    // カテゴリ 2: 測定制限および相談対象
    textData[Lan][PAGE_HELP].insert("labelTextHelp2",QStringList{
                                        "測定値が不正確な場合があり、専門医への相談が必要な場合はいつですか？", // 2-0
                                    });
    // カテゴリ 3: アラート機能
    textData[Lan][PAGE_HELP].insert("labelTextHelp3",QStringList{
                                        "製品にアラート機能はありますか？", // 3-0
                                    });

    //PAGE_HELP_RESPONSE
    fontData[Lan][PAGE_HELP_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_HELP_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_HELP_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    // Help 0: 使用対象
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp0",QStringList{
                                                 "使用対象は満19歳以上の\n糖尿病予備群の成人男女です。",
                                             });
    // Help 1: 製品案内
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp1",QStringList{
                                                 "ハッピーゾーン機器で血糖値を測定でき、アプリ(APP)と連動して血糖値データを日付別、"
                                                 "@期間別に確認して血糖値を管理・モニタリングできる製品です。",
                                             });
    // Help 2: 使用目的
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp2",QStringList{
                                                 "満19歳以上の薬物治療を受けていない糖尿病予備群の患者の血糖管理（モニタリング）のための医療機器であり、"
                                                 "@糖尿病の診断・治療、インスリン投与などの医療的判断には使用できません。",
                                             });
    // Help 3: 測定前の注意事項
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp3",QStringList{
                                                 "測定前に手をきれいに洗い、水分を取り除いてください。\n測定中は動きや強い指の圧迫を避けてください。"
                                                 "@* その他測定に影響を与える可能性がある使用説明書の内容を必ず参考にしてください。",
                                             });
    // Help 4: 使用前に専門医に相談すべき方
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp4",QStringList{
                                                 "満19歳未満の場合、\n"
                                                 "光照射部位の皮膚疾患・傷、\n 多汗症、パーキンソン病などの手の震えがある場合、"
                                                 "@重症低血糖、糖尿病ケトアシドーシス、てんかん、失神など\n副腎疾患の既往歴がある場合、"
                                                 "@血液透析または\n腹膜透析中の場合、\n妊婦および授乳婦の場合",
                                             });
    // Help 5: 主要機能のご案内
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp5",QStringList{
                                                 "* 高血糖/低血糖状態アラート\n"
                                                 "* 血糖補正有効期限アラート\n"
                                                 "* 血糖再補正アラート",
                                                 "血糖補正日から90日経過時に血糖補正有効期限アラートが発生します。",
                                                 "期限の15日前から血糖再補正アラートが発生します。",
                                             });
    // Help 6: ブルートゥース対応範囲
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp6",QStringList{
                                                 "ハッピーゾーンAPP専用のBluetooth機能であり、他のデバイスとは互換性がありません。",
                                             });

    //PAGE_FAQ_INDEX
    fontData[Lan][PAGE_FAQ_INDEX].insert("labelText",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_FAQ_INDEX].insert("labelText",QStringList{
                                             "血糖補正", // 0
                                             "血糖測定", // 1
                                             "製品管理", // 2
                                             "携帯/移動", // 3
                                             "血糖記録", // 4
                                             "使用対象/人数", // 5
                                             "A/S", // 6
                                             "パスワード", // 7
                                         });

    //PAGE_FAQ
    fontData[Lan][PAGE_FAQ].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_FAQ].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_FAQ].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_FAQ].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    // カテゴリ 0: 血糖補正
    textData[Lan][PAGE_FAQ].insert("labelTextFaq0",QStringList{
                                       "「血糖補正（Calibration）」とは何ですか？", // 0-0
                                       "血糖補正は必ず行う必要がありますか？", // 0-1
                                       "血糖補正はいつ行いますか？", // 0-2
                                       "血糖補正の周期はどのくらいですか？", // 0-3
                                       "血糖補正を初期化すると以前の測定記録も削除されますか？", // 0-4
                                   });
    // カテゴリ 1: 血糖測定
    textData[Lan][PAGE_FAQ].insert("labelTextFaq1",QStringList{
                                       "正しい測定姿勢は何ですか？", // 1-0
                                       "指の位置はどのようにしますか？", // 1-1
                                       "毎回同じ指で測定しなければなりませんか？", // 1-2
                                       "測定に適した場所はどこですか？", // 1-3
                                       "濡れた手で測定しても大丈夫ですか？", // 1-4
                                       "1日に何回測定しますか？", // 1-5
                                       "測定にかかる時間はどのくらいですか？", // 1-6
                                       "測定中にキャンセルできますか？", // 1-7
                                       "測定が開始されません。", // 1-8
                                       "測定失敗がよく発生します。", // 1-9
                                       "測定時の指の正しい位置は？", // 1-10
                                       "血糖測定範囲はどのくらいですか？", // 1-11
                                   });
    // カテゴリ 2: 機器管理
    textData[Lan][PAGE_FAQ].insert("labelTextFaq2",QStringList{
                                       "バッテリー完充電時間を教えてください", // 2-0
                                       "バッテリー使用時間を教えてください", // 2-1
                                       "充電中に使用しても大丈夫ですか？", // 2-2
                                       "防水ですか？", // 2-3
                                       "製品はどのように管理すればよいですか？", // 2-4
                                       "保管時に注意すべき場所はありますか？", // 2-5
                                       "指挿入口のカバーは必ず閉めなければなりませんか？", // 2-6
                                   });
    // カテゴリ 3: 携帯/移動
    textData[Lan][PAGE_FAQ].insert("labelTextFaq3",QStringList{
                                       "携帯用として使用できますか？", // 3-0
                                       "航空機への機内持ち込みは可能ですか？", // 3-1
                                       "航空機の受託手荷物として送ることができますか？", // 3-2
                                   });
    // カテゴリ 4: 血糖記録
    textData[Lan][PAGE_FAQ].insert("labelTextFaq4",QStringList{
                                       "血糖測定結果はどこで見ますか？", // 4-0
                                       "血糖記録はどのくらいの期間保存されますか？", // 4-1
                                   });
    // カテゴリ 5: 使用対象/人数
    textData[Lan][PAGE_FAQ].insert("labelTextFaq5",QStringList{
                                       "誰でも使用できますか？", // 5-0
                                       "製品1台で何人まで使用できますか？", // 5-1
                                   });
    // カテゴリ 6: A/S
    textData[Lan][PAGE_FAQ].insert("labelTextFaq6",QStringList{
                                       "製品のA/S期間はどのくらいですか？", // 6-0
                                       "ご希望の回答が見つかりませんでしたか？", // 6-1
                                   });
    // カテゴリ 7: パスワード
    textData[Lan][PAGE_FAQ].insert("labelTextFaq7",QStringList{
                                       "パスワードはどのように変更しますか？", // 7-0
                                   });

    //PAGE_FAQ_RESPONSE
    fontData[Lan][PAGE_FAQ_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_FAQ_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_FAQ_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    // FAQ カテゴリ 0: 血糖補正
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-0",QStringList{
                                                "実際の血糖値と製品の間の誤差を減らすために、侵襲式機器と連携して血糖値を算出・調整する一連の過程です。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-1",QStringList{
                                                "はい。ユーザーごとに測定部位の構造と外部環境による光の透過率が異なるため、正確な血糖測定値を算出するための個人別血糖補正が必ず必要です。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-2",QStringList{
                                                "初めて使用する前に血糖補正を行う必要があります。その後は血糖補正日から90日以内に必ず再補正してください。"
                                                "@血糖補正期限の15日前からアラートで再補正時期をお知らせします。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-3",QStringList{
                                                "測定部位および環境の変化による誤差補正のため、血糖補正日から90日以内に必ず再補正を行ってください。"
                                                "@血糖補正日から90日が経過すると血糖補正有効期限アラートが発生し、再補正を完了するまで血糖測定が制限されます。"
                                                "@血糖補正初期化後に再補正を行うと、血糖測定が再び可能になります。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-4",QStringList{
                                                "いいえ。血糖補正を初期化しても記録された血糖記録は製品に最大90日まで保存されます。"
                                                "\nアプリでは最大12ヶ月まで保存されます。",
                                            });
    // FAQ カテゴリ 1: 血糖測定
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-0",QStringList{
                                                "座った姿勢でテーブルに肘を置き、水平にしてください。"
                                                "\n指の力を抜いて挿入口の奥まで入れ、製品内部の底面に密着させてください。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-1",QStringList{
                                                "指紋が底面に触れるように押し入れてください。\n指先が引っかかったら力を抜いて姿勢を固定してください。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-2",QStringList{
                                                "正確な測定のために、同じ指で測定することをお勧めします。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-3",QStringList{
                                                "室温20〜30°Cの直射日光、風、湿気、振動など製品に影響を与える要素のない場所で測定してください。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-4",QStringList{
                                                "いいえ。濡れた手で測定すると製品の故障の原因になる可能性があります。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-5",QStringList{
                                                "血糖は食事・活動によって変動するため、起床後1回、食前食後各1回、就寝前1回の測定をお勧めします。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-6",QStringList{
                                                "測定開始後1分以内に測定結果が出ます。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-7",QStringList{
                                                "測定中に「キャンセル」ボタンを押すと中断されます。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-8",QStringList{
                                                "血糖補正有効期限(90日)満了時に測定ができませんので、血糖補正を行ってください。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-9",QStringList{
                                                "測定環境を確認後、再度お試しください。\n"
                                                "測定環境は以下の通りです。"
                                                "@測定中の咳、くしゃみ、会話、動きの禁止\n"
                                                "指の力を抜いて水平に底面へ密着"
                                                "@指の表面温度26°C以上を維持\n"
                                                "指の水分および異物を除去"
                                                "@* 使用説明書の\n[ エラーメッセージおよび解決方法 ]を\nご参考ください。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-10",QStringList{
                                                "指紋が底面に触れるように押し入れてください。\n指先が引っかかったら力を抜いて姿勢を固定してください。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-11",QStringList{
                                                "70〜350mg/dL\n\n"
                                                "本製品の血糖測定範囲は最小70以上から最大350以下まで測定が可能です。",
                                            });
    // FAQ カテゴリ 2: 機器管理
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-0",QStringList{
                                                "本製品の完充電までの合計所要時間は約3時間45分です。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-1",QStringList{
                                                "完充電時、1日8回測定基準で最大29日間使用可能です。\nバッテリーの状態により異なる場合があります。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-2",QStringList{
                                                "必ず充電器を取り外した状態でご使用ください。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-3",QStringList{
                                                "いいえ。本製品には防水機能がありませんので、濡れた手で操作しないでください。製品に液体がかかった場合は直ちに拭き取り、正常動作を確認してください。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-4",QStringList{
                                                "柔らかい布で拭いた後、乾燥させてからご使用ください。洗浄剤、アルコール、化学物質の使用は禁止します。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-5",QStringList{
                                                "湿気の多い環境（浴室、キッチンなど）および60°C以上の高温（密閉された車両、直射日光暴露など）環境は避けてください。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-6",QStringList{
                                                "はい、使用しない時は必ず閉じてケースに保管してください。"
                                                "@ほこりや金属または尖った物体が内部に入ることによる製品の損傷やショート事故を防ぐことができます。",
                                            });
    // FAQ カテゴリ 3: 携帯/移動
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq3-0",QStringList{
                                                "はい、測定に適した室内環境では充電して携帯できます。ただし、外部衝撃による誤作動、故障が発生する可能性がありますので"
                                                "@製品に衝撃がないよう携帯用ケースに入れて携帯してください。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq3-1",QStringList{
                                                "本製品のリチウムイオンポリマーバッテリー（約4.4Wh）は航空安全基準（100Wh以下）を満たしており、機内持ち込みが可能です。"
                                                "@航空会社および国別の規定が異なる場合がありますので、搭乗前にご利用の航空会社にご確認ください。"
                                                "@[ バッテリースペック ]\n"
                                                "電圧: 3.7V\n"
                                                "容量: 1200mAh\n"
                                                "総量: 4.44Wh",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq3-2",QStringList{
                                                "本製品はリチウムイオンポリマーバッテリー（約4.4Wh）です。\n航空会社および国別の規定が異なる場合がありますので、搭乗前にご利用の航空会社にご確認ください。"
                                                "@[ バッテリースペック ]\n"
                                                "電圧: 3.7V\n"
                                                "容量: 1200mAh\n"
                                                "総量: 4.44Wh"
                                            });
    // FAQ カテゴリ 4: 血糖記録
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq4-0",QStringList{
                                                "製品内の「設定メニュー」-「血糖記録」アイコンを押すか、Bluetoothでスマートフォンと接続後、アプリ(App)でご確認ください。"
                                                "@当日測定した記録はホーム画面に自動的に表示されます。\n過去の血糖記録は設定の血糖記録アイコンを押して確認してください。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq4-1",QStringList{
                                                "本製品は測定された血糖記録を最大90日まで保存しています。\n"
                                                "90日が経過した記録は自動的に削除されます。",
                                            });
    // FAQ カテゴリ 5: 使用対象/人数
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq5-0",QStringList{
                                                "満19歳以上の薬物治療を受けていない糖尿病予備群の患者を対象とする医療機器であり、糖尿病の診断・治療、インスリン投与などの医療的判断は専門医にご相談ください。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq5-1",QStringList{
                                                "本製品は1台で最大2名まで使用できます。",
                                            });
    // FAQ カテゴリ 6: A/S
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq6-0",QStringList{
                                                "本製品は購入日から最大2年間保証されます。\nただし、個人の事由による破損および故障は保証されません。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq6-1",QStringList{
                                                "カスタマーサービスセンターへお問い合わせください。"
                                            });
    // FAQ カテゴリ 7: パスワード
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq7-0",QStringList{
                                                "上部バーの「メニュー」-「ユーザー情報」-「パスワード変更」から案内に従ってパスワードを変更してください。",
                                            });

    //PAGE_ERROR_HELP_INDEX
    fontData[Lan][PAGE_ERROR_HELP_INDEX].insert("labelText",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_ERROR_HELP_INDEX].insert("labelText",QStringList{
                                                    "血糖測定", // 0
                                                    "製品管理", // 1
                                                    "ブルートゥース", // 2
                                                    "血糖記録", // 3
                                                });

    //PAGE_ERROR_HELP
    fontData[Lan][PAGE_ERROR_HELP].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    // カテゴリ 0: 血糖測定
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp0",QStringList{
                                              "測定が開始されません", // 0-0
                                              "測定失敗がよく発生します", // 0-1
                                              "「指を認識できませんでした」というメッセージが表示されます", // 0-2
                                              "「指の表面温度が低く測定できません」というメッセージが表示されます", // 0-3
                                              "「測定データにエラーがあります」というメッセージが表示されます", // 0-4
                                              "次のステップに進みません", // 0-5
                                              "「測定結果を分析できません」というメッセージが表示されます", // 0-6
                                              "血糖値が正常だと思うのに警告が表示されます", // 0-7
                                          });
    // カテゴリ 1: 機器管理
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp1",QStringList{
                                              "ボタンを押しても動作しません", // 1-0
                                              "電源ブート後、初期画面に入りません", // 1-1
                                              "「アップグレードファイルが見えません」というメッセージが表示されます", // 1-2
                                              "「アップグレードファイルに問題があります」というメッセージが表示されます", // 1-3
                                              "「アップグレードファイルではありません」というメッセージが表示されます", // 1-4
                                              "アップグレード中に電源が切れました", // 1-5
                                              "画面がフリーズしたり、とても遅いです", // 1-6
                                              "どんなエラーなのかわかりません", // 1-7
                                              "画面がタッチできません", // 1-8
                                              "充電できません", // 1-9
                                          });
    // カテゴリ 2: ブルートゥース
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp2",QStringList{
                                              "アプリ連動ができません", // 2-0
                                              "製品の測定値とアプリの測定値が異なります", // 2-1
                                          });
    // カテゴリ 3: 血糖記録
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp3",QStringList{
                                              "血糖補正を初期化すると以前の測定記録も削除されますか？", // 3-0
                                              "削除した血糖記録は復元できますか？", // 3-1
                                          });

    //PAGE_ERROR_RESPONSE
    fontData[Lan][PAGE_ERROR_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_ERROR_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_ERROR_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    // ErrorHelp カテゴリ 0: 血糖測定
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-0",QStringList{
                                                  "血糖補正有効期限(90日)満了時に測定ができませんので、血糖補正を行ってください。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-1",QStringList{
                                                  "測定環境を確認後、再度お試しください。\n"
                                                  "測定環境は以下の通りです。"
                                                  "@測定中の咳、くしゃみ、会話、動きの禁止\n"
                                                  "指の力を抜いて水平に底面へ密着"
                                                  "@指の表面温度26°C以上を維持\n"
                                                  "指の水分および異物を除去"
                                                  "@* 使用説明書の\n[ エラーメッセージおよび解決方法 ]を\nご参考ください。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-2",QStringList{
                                                  "指が正しく挿入されているか確認後、再度測定してください。"
                                                  "@指紋が底面に触れるように押し入れてください。\n指先が引っかかったら力を抜いて姿勢を固定してください。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-3",QStringList{
                                                  "指を十分に温めた後、再度測定してください。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-4",QStringList{
                                                  "会話、手の震え、くしゃみを避けて、一定時間安定をとってから再度測定してください。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-5",QStringList{
                                                  "測定ができなかった可能性があります。再度測定してください。それでも問題が続く場合は電源ボタンを切って入れ直してください。",
                                                  "外部環境（低温や周囲の高温物体）に露出していた場合、誤作動する可能性があります。室温20〜30°Cで再度使用してみてください。",
                                                  "温度、湿度、水分に露出したのでなければ、カスタマーサービスセンターへ故障受付をしてください。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-6",QStringList{
                                                  "指の測定位置と測定環境を確認後、再度測定してください。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-7",QStringList{
                                                  "血糖範囲アイコンを押して血糖状態アラート範囲を調整してください。",
                                              });
    // ErrorHelp カテゴリ 1: 機器管理
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-0",QStringList{
                                                  "電源を切って再度入れてみてください。\n"
                                                  "バッテリーが十分かどうか確認してください。\n"
                                                  "充電器を接続した状態では測定できません。",
                                                  "@水がかかったり湿度の高い場所に保管していた場合、故障の原因になる可能性があります。製品の状態を確認してください。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-1",QStringList{
                                                  "充電ケーブルとアダプターの接続状態を確認後、充電してください。\n充電が完了した後、電源を入れ直してブートが完了すると正常使用が可能です。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-2",QStringList{
                                                  "アップグレードファイルを再度ご確認ください。同じ現象が発生する場合はカスタマーサービスセンターへお問い合わせください。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-3",QStringList{
                                                  "アップグレードファイルを再ダウンロードして新しいファイルで再度お試しください。同じ現象が発生する場合はカスタマーサービスセンターへお問い合わせください。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-4",QStringList{
                                                  "正しいファイルかどうか確認後、再度お試しください。同じ現象が発生する場合はカスタマーサービスセンターへお問い合わせください。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-5",QStringList{
                                                  "充電後、再度アップグレードを行ってください。同じ現象が発生する場合はカスタマーサービスセンターへお問い合わせください。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-6",QStringList{
                                                  "ピンを使用してリセットボタンを押してください。リセットボタンを押した後、システムが再起動されると正常使用が可能です。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-7",QStringList{
                                                  "再起動後、同じエラーが発生するか確認してください。同じ現象が発生する場合はカスタマーサービスセンターへお問い合わせください。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-8",QStringList{
                                                  "再起動をお試し後、正常動作を確認してください。同じ現象が発生する場合はカスタマーサービスセンターへお問い合わせください。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-9",QStringList{
                                                  "充電ケーブルとアダプターの接続状態を確認してください。\n"
                                                  "使用中の充電アダプターの出力仕様が製品の推奨仕様と一致するか確認してください。@",
                                                  "同じ現象が発生する場合はカスタマーサービスセンターへお問い合わせください。",
                                              });
    // ErrorHelp カテゴリ 2: ブルートゥース
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp2-0",QStringList{
                                                  "製品画面上部バーの「ブルートゥース」アイコンをタッチして有効にします。スマートフォンを製品から1M以内に近づけて"
                                                  "@スマートフォンでブルートゥースを検索してハッピーゾーン製品を見つけて連動してください。"
                                                  "@問題が続く場合は本製品の電源を切って再度入れてください。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp2-1",QStringList{
                                                  "日付と測定項目を確認してください。\n"
                                                  "問題が続く場合は一時的なエラーの可能性がありますので、製品とアプリを切ってから再度起動して再連動してください。",
                                              });
    // ErrorHelp カテゴリ 3: 血糖記録
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp3-0",QStringList{
                                                  "いいえ。血糖補正を初期化しても記録された血糖記録は製品に最大90日まで保存されます。\nアプリでは最大12ヶ月まで保存されます。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp3-1",QStringList{
                                                  "いいえ。復元ができませんので、血糖記録削除時にご注意ください。",
                                              });

    fontData[Lan][PAGE_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_RESPONSE].insert("labelPageNum",QFont(currentFont,instance.pixelToPoint(28)));

    //=====================================================================================================================================
    //SC
    Lan = zh_CN;
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
                                         "简体中文",
                                         "繁體中文",
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

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonReboot",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonReboot",QStringList{"重启"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QStringList{"是"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QStringList{"否"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QStringList{
                                            "한국어",
                                            "ENGLISH",
                                            "日本語",
                                            "简体中文",
                                            "繁體中文",
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
                                               "设备错误\n请联系客服中心",               // 2
                                               "设备错误\n请联系客服中心",               // 3
                                               "分析失败\n请重新测量",               // 4
                                               "数据错误\n请重新测量",               // 5
                                               "充电中无法测量\n请拔掉充电器后再试",    // 6
                                               "因手指温度过低，\n无法测量",           // 7
                                               "测量失败\n请联系客服中心"                // 8
                                           });

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QFont(currentFont, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QStringList{
                                               "升级成功", // 0
                                               "升级失败\n请联系客服中心", // 1
                                               "未找到升级文件\n请重新检查文件", // 2
                                               "升级文件有问题\n请使用新文件重试", // 3
                                               "此文件不是有效的升级文件\n请确认文件是否正确", // 4
                                               "升级失败\n请联系客服中心" // 5
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

    //PAGE_HELP_INDEX
    fontData[Lan][PAGE_HELP_INDEX].insert("labelText",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_HELP_INDEX].insert("labelText",QStringList{
                                              "使用对象", // 0
                                              "产品介绍", // 1
                                              "使用目的", // 2
                                              "测量前\n注意事项", // 3
                                              "使用前需咨询\n专业医生的情况", // 4
                                              "主要功能\n介绍", // 5
                                              "蓝牙\n支持范围", // 6
                                          });

    //PAGE_HELP
    fontData[Lan][PAGE_HELP].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_HELP].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_HELP].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_HELP].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    // 类别 0: 产品说明及使用目的
    textData[Lan][PAGE_HELP].insert("labelTextHelp0",QStringList{
                                        "使用对象是谁？", // 0-0
                                        "产品的主要功能是什么？", // 0-1
                                        "产品的使用目的和注意事项是什么？", // 0-2
                                    });
    // 类别 1: 测量注意事项
    textData[Lan][PAGE_HELP].insert("labelTextHelp1",QStringList{
                                        "为确保准确测量，测量时需要遵守什么？", // 1-0
                                    });
    // 类别 2: 测量限制及咨询对象
    textData[Lan][PAGE_HELP].insert("labelTextHelp2",QStringList{
                                        "什么情况下测量值可能不准确，需要咨询专业医疗人员？", // 2-0
                                    });
    // 类别 3: 提醒功能
    textData[Lan][PAGE_HELP].insert("labelTextHelp3",QStringList{
                                        "产品有提醒功能吗？", // 3-0
                                    });

    //PAGE_HELP_RESPONSE
    fontData[Lan][PAGE_HELP_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_HELP_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_HELP_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    // Help 0: 使用对象
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp0",QStringList{
                                                 "使用对象为年满19岁以上的\n糖尿病前期成年男女。",
                                             });
    // Help 1: 产品介绍
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp1",QStringList{
                                                 "可以使用Happyzone设备测量血糖值，并与APP联动，"
                                                 "@按日期和期间查看血糖数据，管理和监测血糖水平的产品。",
                                             });
    // Help 2: 使用目的
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp2",QStringList{
                                                 "本产品是用于年满19岁以上未接受药物治疗的糖尿病前期患者血糖管理（监测）的医疗设备，"
                                                 "@不能用于糖尿病诊断及治疗、胰岛素注射等医疗决定。",
                                             });
    // Help 3: 测量前注意事项
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp3",QStringList{
                                                 "测量前请清洗双手并去除水分。\n测量过程中请避免移动和对手指施加强压。"
                                                 "@* 请务必参考使用说明书中可能影响测量的其他内容。",
                                             });
    // Help 4: 使用前需咨询专业医生的情况
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp4",QStringList{
                                                 "未满19岁的情况，\n"
                                                 "受光照部位有皮肤病或伤口，\n 患有多汗症、帕金森病等手部颤抖的情况，"
                                                 "@有严重低血糖、糖尿病酮症酸中毒、癫痫、晕厥等\n肾上腺疾病病史的情况，"
                                                 "@正在进行血液透析或\n腹膜透析的情况，\n孕妇及哺乳期妇女的情况",
                                             });
    // Help 5: 主要功能介绍
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp5",QStringList{
                                                 "* 高血糖/低血糖状态提醒\n"
                                                 "* 血糖校准有效期提醒\n"
                                                 "* 血糖重新校准提醒",
                                                 "从血糖校准日起经过90天时会发生血糖校准有效期提醒。",
                                                 "到期前15天开始发生血糖重新校准提醒。",
                                             });
    // Help 6: 蓝牙支持范围
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp6",QStringList{
                                                 "这是Happyzone APP专用的蓝牙功能，与其他设备不兼容。",
                                             });

    //PAGE_FAQ_INDEX
    fontData[Lan][PAGE_FAQ_INDEX].insert("labelText",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_FAQ_INDEX].insert("labelText",QStringList{
                                             "血糖校准", // 0
                                             "血糖测量", // 1
                                             "产品管理", // 2
                                             "便携/出行", // 3
                                             "血糖记录", // 4
                                             "使用对象/人数", // 5
                                             "A/S", // 6
                                             "密码", // 7
                                         });

    //PAGE_FAQ
    fontData[Lan][PAGE_FAQ].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_FAQ].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_FAQ].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_FAQ].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    // 类别 0: 血糖校准
    textData[Lan][PAGE_FAQ].insert("labelTextFaq0",QStringList{
                                       "'血糖校准(Calibration)'是什么？", // 0-0
                                       "血糖校准一定要做吗？", // 0-1
                                       "血糖校准什么时候做？", // 0-2
                                       "血糖校准周期是多少？", // 0-3
                                       "血糖校准初始化后以前的测量记录也会删除吗？", // 0-4
                                   });
    // 类别 1: 血糖测量
    textData[Lan][PAGE_FAQ].insert("labelTextFaq1",QStringList{
                                       "正确的测量姿势是什么？", // 1-0
                                       "手指位置怎么放？", // 1-1
                                       "每次都要用同一根手指测量吗？", // 1-2
                                       "适合测量的场所在哪里？", // 1-3
                                       "可以用湿手测量吗？", // 1-4
                                       "一天测量几次？", // 1-5
                                       "测量需要多长时间？", // 1-6
                                       "测量中可以取消吗？", // 1-7
                                       "测量无法开始。", // 1-8
                                       "测量失败经常发生。", // 1-9
                                       "测量时手指的正确位置是？", // 1-10
                                       "血糖测量范围是多少？", // 1-11
                                   });
    // 类别 2: 设备管理
    textData[Lan][PAGE_FAQ].insert("labelTextFaq2",QStringList{
                                       "电池充满电需要多长时间？", // 2-0
                                       "电池可以使用多长时间？", // 2-1
                                       "充电中可以使用吗？", // 2-2
                                       "防水吗？", // 2-3
                                       "产品应该怎么保养？", // 2-4
                                       "保管时需要注意的地方有哪些？", // 2-5
                                       "手指插入口的盖子一定要关吗？", // 2-6
                                   });
    // 类别 3: 便携/出行
    textData[Lan][PAGE_FAQ].insert("labelTextFaq3",QStringList{
                                       "可以作为便携设备使用吗？", // 3-0
                                       "可以带上飞机吗？", // 3-1
                                       "可以作为飞机托运行李发送吗？", // 3-2
                                   });
    // 类别 4: 血糖记录
    textData[Lan][PAGE_FAQ].insert("labelTextFaq4",QStringList{
                                       "血糖测量结果在哪里看？", // 4-0
                                       "血糖记录可以保存多长时间？", // 4-1
                                   });
    // 类别 5: 使用对象/人数
    textData[Lan][PAGE_FAQ].insert("labelTextFaq5",QStringList{
                                       "任何人都可以使用吗？", // 5-0
                                       "一台产品几个人可以使用？", // 5-1
                                   });
    // 类别 6: A/S
    textData[Lan][PAGE_FAQ].insert("labelTextFaq6",QStringList{
                                       "产品的A/S保修期是多久？", // 6-0
                                       "没有找到您想要的答案吗？", // 6-1
                                   });
    // 类别 7: 密码
    textData[Lan][PAGE_FAQ].insert("labelTextFaq7",QStringList{
                                       "如何更改密码？", // 7-0
                                   });

    //PAGE_FAQ_RESPONSE
    fontData[Lan][PAGE_FAQ_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_FAQ_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_FAQ_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    // FAQ 类别 0: 血糖校准
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-0",QStringList{
                                                "这是通过与有创设备联动来计算和调整血糖数值，以减少实际血糖值与产品之间误差的一系列过程。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-1",QStringList{
                                                "是的。由于每位用户的测量部位结构和外部环境导致的光透过率不同，为了计算准确的血糖测量值，个人血糖校准是必须的。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-2",QStringList{
                                                "首次使用前必须进行血糖校准。此后必须在血糖校准日起90天内重新校准。"
                                                "@从血糖校准到期日前15天开始通过提醒通知重新校准时间。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-3",QStringList{
                                                "为了校正因测量部位及环境变化导致的误差，必须在血糖校准日起90天内进行重新校准。"
                                                "@血糖校准日起经过90天后会发生血糖校准有效期到期提醒，在完成重新校准前血糖测量将受到限制。"
                                                "@血糖校准初始化后进行重新校准即可重新进行血糖测量。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-4",QStringList{
                                                "不会。即使初始化血糖校准，已记录的血糖记录会在产品中保存最多90天。"
                                                "\n在APP中可保存最多12个月。",
                                            });
    // FAQ 类别 1: 血糖测量
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-0",QStringList{
                                                "坐姿将手肘放在桌子上保持水平。"
                                                "\n手指放松，插入到插入口最深处，紧贴产品内部底面。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-1",QStringList{
                                                "将手指指纹面朝下推入。\n当指尖刚好卡住时放松并固定姿势。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-2",QStringList{
                                                "为确保准确测量，建议使用同一根手指进行测量。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-3",QStringList{
                                                "请在室温20~30°C、没有直射阳光、风、湿气、振动等可能影响产品因素的场所进行测量。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-4",QStringList{
                                                "不可以。用湿手测量可能导致产品故障。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-5",QStringList{
                                                "由于血糖会随饮食和活动波动，建议起床后1次、餐前餐后各1次、睡前1次进行测量。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-6",QStringList{
                                                "测量开始后1分钟内即可得出测量结果。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-7",QStringList{
                                                "测量中按下'取消'按钮即可中断。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-8",QStringList{
                                                "血糖校准有效期(90天)到期后无法测量，请进行血糖校准。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-9",QStringList{
                                                "请确认测量环境后再次尝试。\n"
                                                "测量环境如下。"
                                                "@测量中禁止咳嗽、打喷嚏、说话、移动\n"
                                                "手指放松水平紧贴底面"
                                                "@保持手指表面温度26°C以上\n"
                                                "去除手指上的水分及异物"
                                                "@* 请参考使用说明书\n[ 错误信息及解决方法 ]。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-10",QStringList{
                                                "将手指指纹面朝下推入。\n当指尖刚好卡住时放松并固定姿势。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-11",QStringList{
                                                "70~350mg/dL\n\n"
                                                "本产品的血糖测量范围为最低70以上至最高350以下。",
                                            });
    // FAQ 类别 2: 设备管理
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-0",QStringList{
                                                "本产品完全充电所需总时间约为3小时45分钟。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-1",QStringList{
                                                "完全充电后，按每天8次测量计算，最多可使用29天。\n电池续航时间可能因电池状态而异。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-2",QStringList{
                                                "请务必在拔下充电器的状态下使用。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-3",QStringList{
                                                "不可以。本产品没有防水功能，请勿用湿手操作。如果液体接触到产品，请立即擦干并确认是否正常运行。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-4",QStringList{
                                                "用柔软的布擦拭后晾干使用。禁止使用清洁剂、酒精或化学物质。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-5",QStringList{
                                                "请避免潮湿环境（浴室、厨房等）和60°C以上的高温环境（密闭车辆、直射阳光暴露等）。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-6",QStringList{
                                                "是的，不使用时请务必关闭并存放在保护盒中。"
                                                "@这可以防止灰尘、金属或尖锐物体进入内部造成的产品损坏或短路事故。",
                                            });
    // FAQ 类别 3: 便携/出行
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq3-0",QStringList{
                                                "是的，在适合测量的室内环境中可以充电后携带使用。但外部冲击可能导致误操作或故障，"
                                                "@请将产品放入便携保护盒中携带，以防冲击。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq3-1",QStringList{
                                                "本产品的锂离子聚合物电池（约4.4Wh）符合航空安全标准（100Wh以下），可以随身携带登机。"
                                                "@各航空公司及各国规定可能不同，请在登机前向所乘航空公司确认。"
                                                "@[ 电池规格 ]\n"
                                                "电压: 3.7V\n"
                                                "容量: 1200mAh\n"
                                                "总量: 4.44Wh",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq3-2",QStringList{
                                                "本产品为锂离子聚合物电池（约4.4Wh）。\n各航空公司及各国规定可能不同，请在登机前向所乘航空公司确认。"
                                                "@[ 电池规格 ]\n"
                                                "电压: 3.7V\n"
                                                "容量: 1200mAh\n"
                                                "总量: 4.44Wh"
                                            });
    // FAQ 类别 4: 血糖记录
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq4-0",QStringList{
                                                "请按下产品内'设置菜单' - '血糖记录'图标，或通过蓝牙连接智能手机后在APP中查看。"
                                                "@当天测量的记录会自动显示在主屏幕上。\n过去的血糖记录请按设置中的血糖记录图标查看。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq4-1",QStringList{
                                                "本产品将测量的血糖记录最多保存90天。\n"
                                                "超过90天的记录将自动删除。",
                                            });
    // FAQ 类别 5: 使用对象/人数
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq5-0",QStringList{
                                                "本产品是面向年满19岁以上未接受药物治疗的糖尿病前期患者的医疗设备，糖尿病诊断及治疗、胰岛素注射等医疗决定请咨询专业医疗人员。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq5-1",QStringList{
                                                "本产品一台最多可供2人使用。",
                                            });
    // FAQ 类别 6: A/S
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq6-0",QStringList{
                                                "本产品自购买之日起最多保修2年。\n但因个人原因造成的损坏及故障不在保修范围内。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq6-1",QStringList{
                                                "请联系客服中心咨询。"
                                            });
    // FAQ 类别 7: 密码
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq7-0",QStringList{
                                                "请通过顶部栏'菜单' - '用户信息' - '更改密码'按照指引更改密码。",
                                            });

    //PAGE_ERROR_HELP_INDEX
    fontData[Lan][PAGE_ERROR_HELP_INDEX].insert("labelText",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_ERROR_HELP_INDEX].insert("labelText",QStringList{
                                                    "血糖测量", // 0
                                                    "产品管理", // 1
                                                    "蓝牙", // 2
                                                    "血糖记录", // 3
                                                });

    //PAGE_ERROR_HELP
    fontData[Lan][PAGE_ERROR_HELP].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    // 类别 0: 血糖测量
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp0",QStringList{
                                              "测量无法开始", // 0-0
                                              "测量失败经常发生", // 0-1
                                              "显示'无法识别手指'的消息", // 0-2
                                              "显示'手指表面温度过低无法测量'的消息", // 0-3
                                              "显示'测量数据有误'的消息", // 0-4
                                              "无法进入下一步", // 0-5
                                              "显示'无法分析测量结果'的消息", // 0-6
                                              "血糖值认为正常但显示警告", // 0-7
                                          });
    // 类别 1: 设备管理
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp1",QStringList{
                                              "按按钮也不工作", // 1-0
                                              "开机后无法进入初始画面", // 1-1
                                              "显示'看不到升级文件'的消息", // 1-2
                                              "显示'升级文件有问题'的消息", // 1-3
                                              "显示'不是升级文件'的消息", // 1-4
                                              "升级过程中断电了", // 1-5
                                              "画面卡住或非常慢", // 1-6
                                              "不知道是什么错误", // 1-7
                                              "画面无法触摸", // 1-8
                                              "无法充电", // 1-9
                                          });
    // 类别 2: 蓝牙
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp2",QStringList{
                                              "应用无法同步", // 2-0
                                              "产品测量值与应用测量值不同", // 2-1
                                          });
    // 类别 3: 血糖记录
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp3",QStringList{
                                              "血糖校准初始化后以前的测量记录也会删除吗？", // 3-0
                                              "删除的血糖记录可以恢复吗？", // 3-1
                                          });

    //PAGE_ERROR_RESPONSE
    fontData[Lan][PAGE_ERROR_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_ERROR_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_ERROR_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    // ErrorHelp 类别 0: 血糖测量
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-0",QStringList{
                                                  "血糖校准有效期(90天)到期后无法测量，请进行血糖校准。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-1",QStringList{
                                                  "请确认测量环境后再次尝试。\n"
                                                  "测量环境如下。"
                                                  "@测量中禁止咳嗽、打喷嚏、说话、移动\n"
                                                  "手指放松水平紧贴底面"
                                                  "@保持手指表面温度26°C以上\n"
                                                  "去除手指上的水分及异物"
                                                  "@* 请参考使用说明书\n[ 错误信息及解决方法 ]。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-2",QStringList{
                                                  "请确认手指是否正确插入后再次测量。"
                                                  "@将手指指纹面朝下推入。\n当指尖刚好卡住时放松并固定姿势。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-3",QStringList{
                                                  "请充分温暖手指后再次测量。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-4",QStringList{
                                                  "请避免说话、手抖、打喷嚏，稳定一段时间后再次测量。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-5",QStringList{
                                                  "可能未完成测量。请再次测量。如果问题持续，请关闭电源按钮后重新开启。",
                                                  "如果产品曾暴露在外部环境（低温或附近高温物体）中，可能会发生误操作。请在室温20~30°C下再次使用。",
                                                  "如果不是因为温度、湿度或水分的暴露，请联系客服中心进行故障报修。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-6",QStringList{
                                                  "请确认手指测量位置和测量环境后再次测量。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-7",QStringList{
                                                  "请按血糖范围图标调整血糖状态提醒范围。",
                                              });
    // ErrorHelp 类别 1: 设备管理
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-0",QStringList{
                                                  "请关闭电源后重新开启。\n"
                                                  "请确认电池是否充足。\n"
                                                  "充电器连接状态下无法进行测量。",
                                                  "@如果产品曾接触水或存放在高湿度环境中，可能导致故障。请检查产品状态。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-1",QStringList{
                                                  "请确认充电线和适配器连接状态后进行充电。\n充电完成后重新开机，启动完成后即可正常使用。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-2",QStringList{
                                                  "请重新确认升级文件。如果发生相同现象，请联系客服中心。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-3",QStringList{
                                                  "请重新下载升级文件并用新文件再次尝试。如果发生相同现象，请联系客服中心。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-4",QStringList{
                                                  "请确认是否为正确文件后再次尝试。如果发生相同现象，请联系客服中心。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-5",QStringList{
                                                  "请充电后再次进行升级。如果发生相同现象，请联系客服中心。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-6",QStringList{
                                                  "请使用针按下重置按钮。按下重置按钮后系统重启即可正常使用。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-7",QStringList{
                                                  "请确认重启后是否发生相同错误。如果发生相同现象，请联系客服中心。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-8",QStringList{
                                                  "请尝试重启并确认正常运行。如果发生相同现象，请联系客服中心。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-9",QStringList{
                                                  "请检查充电线和适配器连接状态。\n"
                                                  "请确认您使用的充电适配器的输出规格是否与产品推荐规格一致。@",
                                                  "如果发生相同现象，请联系客服中心。",
                                              });
    // ErrorHelp 类别 2: 蓝牙
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp2-0",QStringList{
                                                  "触摸产品屏幕顶部栏的'蓝牙'图标进行激活。然后将智能手机放在产品1M以内"
                                                  "@在智能手机上搜索蓝牙找到Happyzone产品并进行连接。"
                                                  "@如果问题持续，请关闭本产品电源后重新开启。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp2-1",QStringList{
                                                  "请确认日期和测量项目。\n"
                                                  "如果问题持续，可能是暂时性错误，请关闭产品和应用后重新启动并重新连接。",
                                              });
    // ErrorHelp 类别 3: 血糖记录
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp3-0",QStringList{
                                                  "不会。即使初始化血糖校准，已记录的血糖记录会在产品中保存最多90天。\n在APP中可保存最多12个月。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp3-1",QStringList{
                                                  "不可以。无法恢复，因此删除血糖记录时请注意。",
                                              });

    fontData[Lan][PAGE_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_RESPONSE].insert("labelPageNum",QFont(currentFont,instance.pixelToPoint(28)));

    //=====================================================================================================================================
    //TC
    Lan = zh_TW;
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
                                         "简体中文",
                                         "繁體中文",
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

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonReboot",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonReboot",QStringList{"重新啟動"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QStringList{"是"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QStringList{"否"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QStringList{
                                            "한국어",
                                            "ENGLISH",
                                            "日本語",
                                            "简体中文",
                                            "繁體中文",
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
                                               "設備錯誤\n請聯繫客服中心",                   // 2
                                               "設備錯誤\n請聯繫客服中心",                   // 3
                                               "分析失敗\n請重新測量",                   // 4
                                               "數據錯誤\n請重新測量",                   // 5
                                               "充電中無法測量\n請拔除充電器後再試",       // 6
                                               "因手指溫度過低，\n無法測量",               // 7
                                               "測量失敗\n請聯繫客服中心"                    // 8
                                           });

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QFont(currentFont, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QStringList{
                                               "升級成功", // 0
                                               "升級失敗\n請聯繫客服中心", // 1
                                               "找不到升級檔案\n請重新檢查檔案", // 2
                                               "升級檔案有問題\n請使用新檔案重試", // 3
                                               "此檔案不是有效的升級檔案\n請確認是否正確", // 4
                                               "升級失敗\n請聯繫客服中心" // 5
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

    //PAGE_HELP_INDEX
    fontData[Lan][PAGE_HELP_INDEX].insert("labelText",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_HELP_INDEX].insert("labelText",QStringList{
                                              "使用對象", // 0
                                              "產品介紹", // 1
                                              "使用目的", // 2
                                              "測量前\n注意事項", // 3
                                              "使用前需諮詢\n專業醫生的情況", // 4
                                              "主要功能\n介紹", // 5
                                              "藍牙\n支援範圍", // 6
                                          });

    //PAGE_HELP
    fontData[Lan][PAGE_HELP].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_HELP].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_HELP].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_HELP].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    // 類別 0: 產品說明及使用目的
    textData[Lan][PAGE_HELP].insert("labelTextHelp0",QStringList{
                                        "使用對象是誰？", // 0-0
                                        "產品的主要功能是什麼？", // 0-1
                                        "產品的使用目的和注意事項是什麼？", // 0-2
                                    });
    // 類別 1: 測量注意事項
    textData[Lan][PAGE_HELP].insert("labelTextHelp1",QStringList{
                                        "為確保準確測量，測量時需要遵守什麼？", // 1-0
                                    });
    // 類別 2: 測量限制及諮詢對象
    textData[Lan][PAGE_HELP].insert("labelTextHelp2",QStringList{
                                        "什麼情況下測量值可能不準確，需要諮詢專業醫療人員？", // 2-0
                                    });
    // 類別 3: 提醒功能
    textData[Lan][PAGE_HELP].insert("labelTextHelp3",QStringList{
                                        "產品有提醒功能嗎？", // 3-0
                                    });

    //PAGE_HELP_RESPONSE
    fontData[Lan][PAGE_HELP_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_HELP_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_HELP_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    // Help 0: 使用對象
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp0",QStringList{
                                                 "使用對象為年滿19歲以上的\n糖尿病前期成年男女。",
                                             });
    // Help 1: 產品介紹
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp1",QStringList{
                                                 "可以使用Happyzone設備測量血糖值，並與APP聯動，"
                                                 "@按日期和期間查看血糖數據，管理和監測血糖水平的產品。",
                                             });
    // Help 2: 使用目的
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp2",QStringList{
                                                 "本產品是用於年滿19歲以上未接受藥物治療的糖尿病前期患者血糖管理（監測）的醫療設備，"
                                                 "@不能用於糖尿病診斷及治療、胰島素注射等醫療決定。",
                                             });
    // Help 3: 測量前注意事項
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp3",QStringList{
                                                 "測量前請清洗雙手並去除水分。\n測量過程中請避免移動和對手指施加強壓。"
                                                 "@* 請務必參考使用說明書中可能影響測量的其他內容。",
                                             });
    // Help 4: 使用前需諮詢專業醫生的情況
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp4",QStringList{
                                                 "未滿19歲的情況，\n"
                                                 "受光照部位有皮膚病或傷口，\n 患有多汗症、帕金森病等手部顫抖的情況，"
                                                 "@有嚴重低血糖、糖尿病酮症酸中毒、癲癇、暈厥等\n腎上腺疾病病史的情況，"
                                                 "@正在進行血液透析或\n腹膜透析的情況，\n孕婦及哺乳期婦女的情況",
                                             });
    // Help 5: 主要功能介紹
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp5",QStringList{
                                                 "* 高血糖/低血糖狀態提醒\n"
                                                 "* 血糖校準有效期提醒\n"
                                                 "* 血糖重新校準提醒",
                                                 "從血糖校準日起經過90天時會發生血糖校準有效期提醒。",
                                                 "到期前15天開始發生血糖重新校準提醒。",
                                             });
    // Help 6: 藍牙支援範圍
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp6",QStringList{
                                                 "這是Happyzone APP專用的藍牙功能，與其他設備不相容。",
                                             });

    //PAGE_FAQ_INDEX
    fontData[Lan][PAGE_FAQ_INDEX].insert("labelText",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_FAQ_INDEX].insert("labelText",QStringList{
                                             "血糖校準", // 0
                                             "血糖測量", // 1
                                             "產品管理", // 2
                                             "攜帶/出行", // 3
                                             "血糖記錄", // 4
                                             "使用對象/人數", // 5
                                             "A/S", // 6
                                             "密碼", // 7
                                         });

    //PAGE_FAQ
    fontData[Lan][PAGE_FAQ].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_FAQ].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_FAQ].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_FAQ].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    // 類別 0: 血糖校準
    textData[Lan][PAGE_FAQ].insert("labelTextFaq0",QStringList{
                                       "'血糖校準(Calibration)'是什麼？", // 0-0
                                       "血糖校準一定要做嗎？", // 0-1
                                       "血糖校準什麼時候做？", // 0-2
                                       "血糖校準週期是多少？", // 0-3
                                       "血糖校準初始化後以前的測量記錄也會刪除嗎？", // 0-4
                                   });
    // 類別 1: 血糖測量
    textData[Lan][PAGE_FAQ].insert("labelTextFaq1",QStringList{
                                       "正確的測量姿勢是什麼？", // 1-0
                                       "手指位置怎麼放？", // 1-1
                                       "每次都要用同一根手指測量嗎？", // 1-2
                                       "適合測量的場所在哪裡？", // 1-3
                                       "可以用濕手測量嗎？", // 1-4
                                       "一天測量幾次？", // 1-5
                                       "測量需要多長時間？", // 1-6
                                       "測量中可以取消嗎？", // 1-7
                                       "測量無法開始。", // 1-8
                                       "測量失敗經常發生。", // 1-9
                                       "測量時手指的正確位置是？", // 1-10
                                       "血糖測量範圍是多少？", // 1-11
                                   });
    // 類別 2: 設備管理
    textData[Lan][PAGE_FAQ].insert("labelTextFaq2",QStringList{
                                       "電池充滿電需要多長時間？", // 2-0
                                       "電池可以使用多長時間？", // 2-1
                                       "充電中可以使用嗎？", // 2-2
                                       "防水嗎？", // 2-3
                                       "產品應該怎麼保養？", // 2-4
                                       "保管時需要注意的地方有哪些？", // 2-5
                                       "手指插入口的蓋子一定要關嗎？", // 2-6
                                   });
    // 類別 3: 攜帶/出行
    textData[Lan][PAGE_FAQ].insert("labelTextFaq3",QStringList{
                                       "可以作為攜帶式設備使用嗎？", // 3-0
                                       "可以帶上飛機嗎？", // 3-1
                                       "可以作為飛機託運行李發送嗎？", // 3-2
                                   });
    // 類別 4: 血糖記錄
    textData[Lan][PAGE_FAQ].insert("labelTextFaq4",QStringList{
                                       "血糖測量結果在哪裡看？", // 4-0
                                       "血糖記錄可以保存多長時間？", // 4-1
                                   });
    // 類別 5: 使用對象/人數
    textData[Lan][PAGE_FAQ].insert("labelTextFaq5",QStringList{
                                       "任何人都可以使用嗎？", // 5-0
                                       "一台產品幾個人可以使用？", // 5-1
                                   });
    // 類別 6: A/S
    textData[Lan][PAGE_FAQ].insert("labelTextFaq6",QStringList{
                                       "產品的A/S保固期是多久？", // 6-0
                                       "沒有找到您想要的答案嗎？", // 6-1
                                   });
    // 類別 7: 密碼
    textData[Lan][PAGE_FAQ].insert("labelTextFaq7",QStringList{
                                       "如何更改密碼？", // 7-0
                                   });

    //PAGE_FAQ_RESPONSE
    fontData[Lan][PAGE_FAQ_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_FAQ_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_FAQ_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    // FAQ 類別 0: 血糖校準
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-0",QStringList{
                                                "這是透過與有創設備聯動來計算和調整血糖數值，以減少實際血糖值與產品之間誤差的一系列過程。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-1",QStringList{
                                                "是的。由於每位使用者的測量部位結構和外部環境導致的光透過率不同，為了計算準確的血糖測量值，個人血糖校準是必須的。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-2",QStringList{
                                                "首次使用前必須進行血糖校準。此後必須在血糖校準日起90天內重新校準。"
                                                "@從血糖校準到期日前15天開始透過提醒通知重新校準時間。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-3",QStringList{
                                                "為了校正因測量部位及環境變化導致的誤差，必須在血糖校準日起90天內進行重新校準。"
                                                "@血糖校準日起經過90天後會發生血糖校準有效期到期提醒，在完成重新校準前血糖測量將受到限制。"
                                                "@血糖校準初始化後進行重新校準即可重新進行血糖測量。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-4",QStringList{
                                                "不會。即使初始化血糖校準，已記錄的血糖記錄會在產品中保存最多90天。"
                                                "\n在APP中可保存最多12個月。",
                                            });
    // FAQ 類別 1: 血糖測量
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-0",QStringList{
                                                "坐姿將手肘放在桌子上保持水平。"
                                                "\n手指放鬆，插入到插入口最深處，緊貼產品內部底面。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-1",QStringList{
                                                "將手指指紋面朝下推入。\n當指尖剛好卡住時放鬆並固定姿勢。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-2",QStringList{
                                                "為確保準確測量，建議使用同一根手指進行測量。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-3",QStringList{
                                                "請在室溫20~30°C、沒有直射陽光、風、濕氣、振動等可能影響產品因素的場所進行測量。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-4",QStringList{
                                                "不可以。用濕手測量可能導致產品故障。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-5",QStringList{
                                                "由於血糖會隨飲食和活動波動，建議起床後1次、餐前餐後各1次、睡前1次進行測量。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-6",QStringList{
                                                "測量開始後1分鐘內即可得出測量結果。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-7",QStringList{
                                                "測量中按下'取消'按鈕即可中斷。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-8",QStringList{
                                                "血糖校準有效期(90天)到期後無法測量，請進行血糖校準。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-9",QStringList{
                                                "請確認測量環境後再次嘗試。\n"
                                                "測量環境如下。"
                                                "@測量中禁止咳嗽、打噴嚏、說話、移動\n"
                                                "手指放鬆水平緊貼底面"
                                                "@保持手指表面溫度26°C以上\n"
                                                "去除手指上的水分及異物"
                                                "@* 請參考使用說明書\n[ 錯誤訊息及解決方法 ]。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-10",QStringList{
                                                "將手指指紋面朝下推入。\n當指尖剛好卡住時放鬆並固定姿勢。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-11",QStringList{
                                                "70~350mg/dL\n\n"
                                                "本產品的血糖測量範圍為最低70以上至最高350以下。",
                                            });
    // FAQ 類別 2: 設備管理
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-0",QStringList{
                                                "本產品完全充電所需總時間約為3小時45分鐘。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-1",QStringList{
                                                "完全充電後，按每天8次測量計算，最多可使用29天。\n電池續航時間可能因電池狀態而異。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-2",QStringList{
                                                "請務必在拔下充電器的狀態下使用。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-3",QStringList{
                                                "不可以。本產品沒有防水功能，請勿用濕手操作。如果液體接觸到產品，請立即擦乾並確認是否正常運行。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-4",QStringList{
                                                "用柔軟的布擦拭後晾乾使用。禁止使用清潔劑、酒精或化學物質。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-5",QStringList{
                                                "請避免潮濕環境（浴室、廚房等）和60°C以上的高溫環境（密閉車輛、直射陽光暴露等）。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-6",QStringList{
                                                "是的，不使用時請務必關閉並存放在保護盒中。"
                                                "@這可以防止灰塵、金屬或尖銳物體進入內部造成的產品損壞或短路事故。",
                                            });
    // FAQ 類別 3: 攜帶/出行
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq3-0",QStringList{
                                                "是的，在適合測量的室內環境中可以充電後攜帶使用。但外部衝擊可能導致誤操作或故障，"
                                                "@請將產品放入攜帶式保護盒中攜帶，以防衝擊。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq3-1",QStringList{
                                                "本產品的鋰離子聚合物電池（約4.4Wh）符合航空安全標準（100Wh以下），可以隨身攜帶登機。"
                                                "@各航空公司及各國規定可能不同，請在登機前向所乘航空公司確認。"
                                                "@[ 電池規格 ]\n"
                                                "電壓: 3.7V\n"
                                                "容量: 1200mAh\n"
                                                "總量: 4.44Wh",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq3-2",QStringList{
                                                "本產品為鋰離子聚合物電池（約4.4Wh）。\n各航空公司及各國規定可能不同，請在登機前向所乘航空公司確認。"
                                                "@[ 電池規格 ]\n"
                                                "電壓: 3.7V\n"
                                                "容量: 1200mAh\n"
                                                "總量: 4.44Wh"
                                            });
    // FAQ 類別 4: 血糖記錄
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq4-0",QStringList{
                                                "請按下產品內'設定選單' - '血糖記錄'圖示，或透過藍牙連接智慧型手機後在APP中查看。"
                                                "@當天測量的記錄會自動顯示在主畫面上。\n過去的血糖記錄請按設定中的血糖記錄圖示查看。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq4-1",QStringList{
                                                "本產品將測量的血糖記錄最多保存90天。\n"
                                                "超過90天的記錄將自動刪除。",
                                            });
    // FAQ 類別 5: 使用對象/人數
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq5-0",QStringList{
                                                "本產品是面向年滿19歲以上未接受藥物治療的糖尿病前期患者的醫療設備，糖尿病診斷及治療、胰島素注射等醫療決定請諮詢專業醫療人員。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq5-1",QStringList{
                                                "本產品一台最多可供2人使用。",
                                            });
    // FAQ 類別 6: A/S
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq6-0",QStringList{
                                                "本產品自購買之日起最多保固2年。\n但因個人原因造成的損壞及故障不在保固範圍內。",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq6-1",QStringList{
                                                "請聯繫客服中心諮詢。"
                                            });
    // FAQ 類別 7: 密碼
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq7-0",QStringList{
                                                "請通過頂部欄'選單' - '用戶資訊' - '更改密碼'按照指引更改密碼。",
                                            });

    //PAGE_ERROR_HELP_INDEX
    fontData[Lan][PAGE_ERROR_HELP_INDEX].insert("labelText",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_ERROR_HELP_INDEX].insert("labelText",QStringList{
                                                    "血糖測量", // 0
                                                    "產品管理", // 1
                                                    "藍牙", // 2
                                                    "血糖記錄", // 3
                                                });

    //PAGE_ERROR_HELP
    fontData[Lan][PAGE_ERROR_HELP].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    // 카테고리 0: 血糖測量
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp0",QStringList{
                                              "測量無法開始", // 0-0
                                              "測量經常失敗", // 0-1
                                              "顯示「無法辨識手指」的訊息", // 0-2
                                              "顯示「手指表面溫度過低，無法測量」的訊息", // 0-3
                                              "顯示「測量數據有誤」的訊息", // 0-4
                                              "無法進入下一步", // 0-5
                                              "顯示「無法分析測量結果」的訊息", // 0-6
                                              "血糖數值正常但出現警告", // 0-7
                                          });
    // 카테고리 1: 產品管理
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp1",QStringList{
                                              "按下按鈕但無法運作", // 1-0
                                              "開機後無法進入初始畫面", // 1-1
                                              "顯示「找不到升級檔案」的訊息", // 1-2
                                              "顯示「升級檔案有問題」的訊息", // 1-3
                                              "顯示「不是升級檔案」的訊息", // 1-4
                                              "升級過程中電源關閉了", // 1-5
                                              "畫面卡住或非常慢", // 1-6
                                              "不知道是什麼錯誤", // 1-7
                                              "畫面無法觸控", // 1-8
                                              "無法充電", // 1-9
                                          });
    // 카테고리 2: 藍牙
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp2",QStringList{
                                              "無法與應用程式連動", // 2-0
                                              "產品的測量數值與應用程式的測量數值不同", // 2-1
                                          });
    // 카테고리 3: 血糖記錄
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp3",QStringList{
                                              "血糖校準初始化後以前的測量記錄也會刪除嗎？", // 3-0
                                              "刪除的血糖記錄可以恢復嗎？", // 3-1
                                          });

    //PAGE_ERROR_RESPONSE
    fontData[Lan][PAGE_ERROR_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_ERROR_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_ERROR_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    // ErrorHelp 카테고리 0: 血糖測量
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-0",QStringList{
                                                  "血糖校正有效期限（90天）到期時將無法測量，請進行血糖校正。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-1",QStringList{
                                                  "請確認測量環境後再試。\n"
                                                  "測量環境如下："
                                                  "@測量中禁止咳嗽、打噴嚏、說話及移動\n"
                                                  "手指放鬆，水平緊貼底面"
                                                  "@手指表面溫度維持26°C以上\n"
                                                  "去除手指上的水分及異物"
                                                  "@* 請參考使用說明書\n[ 錯誤訊息及解決方法 ]。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-2",QStringList{
                                                  "請確認手指是否正確插入後再次測量。"
                                                  "@將手指指紋面朝下推入。\n手指尖端恰好卡住後放鬆力量並固定姿勢。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-3",QStringList{
                                                  "請將手指充分溫暖後再次測量。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-4",QStringList{
                                                  "請避免說話、手抖、打噴嚏，安靜一段時間後再次測量。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-5",QStringList{
                                                  "可能未完成測量。請再次測量。如果問題持續，請關閉電源後重新開啟。",
                                                  "如果暴露在外部環境（低溫或附近有高溫物體），可能會發生故障。請在室溫20~30°C的環境下重新使用。",
                                                  "如果不是溫度、濕度或水分導致的問題，請聯繫客服中心報修。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-6",QStringList{
                                                  "請確認手指測量位置及測量環境後再次測量。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-7",QStringList{
                                                  "請點擊血糖範圍圖標，調整血糖狀態提醒範圍。",
                                              });
    // ErrorHelp 카테고리 1: 產品管理
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-0",QStringList{
                                                  "請關閉電源後重新開啟。\n"
                                                  "請確認電池是否充足。\n"
                                                  "連接充電線的狀態下無法進行測量。",
                                                  "@如果曾接觸水或保管在高濕度環境中，可能導致故障。請檢查產品狀態。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-1",QStringList{
                                                  "請確認充電線及轉接器的連接狀態後進行充電。\n充電完成後重新開機，啟動完成即可正常使用。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-2",QStringList{
                                                  "請重新確認升級檔案。如果持續發生相同情況，請聯繫客服中心。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-3",QStringList{
                                                  "請重新下載升級檔案後再試。如果持續發生相同情況，請聯繫客服中心。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-4",QStringList{
                                                  "請確認檔案是否正確後再試。如果持續發生相同情況，請聯繫客服中心。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-5",QStringList{
                                                  "請充電後重新進行升級。如果持續發生相同情況，請聯繫客服中心。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-6",QStringList{
                                                  "請使用針按下重置按鈕。按下重置按鈕後系統重新啟動即可正常使用。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-7",QStringList{
                                                  "請重新啟動後確認是否發生相同錯誤。如果持續發生相同情況，請聯繫客服中心。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-8",QStringList{
                                                  "請嘗試重新啟動後確認是否正常運作。如果持續發生相同情況，請聯繫客服中心。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-9",QStringList{
                                                  "請確認充電線及轉接器的連接狀態。\n"
                                                  "請確認使用中的充電轉接器輸出規格是否與產品建議規格一致。@",
                                                  "如果持續發生相同情況，請聯繫客服中心。",
                                              });
    // ErrorHelp 카테고리 2: 藍牙
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp2-0",QStringList{
                                                  "觸碰產品畫面頂部欄的「藍牙」圖標進行啟動。然後將智慧型手機放在產品1M以內"
                                                  "@在智慧型手機上搜尋藍牙，找到Happyzone產品並進行連動。"
                                                  "@如果問題持續，請關閉本產品電源後重新開啟。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp2-1",QStringList{
                                                  "請確認日期和測量項目。\n"
                                                  "如果問題持續，可能是暫時性錯誤，請關閉產品和應用程式後重新啟動並重新連動。",
                                              });
    // ErrorHelp 카테고리 3: 血糖記錄
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp3-0",QStringList{
                                                  "不會。即使初始化血糖校正，已記錄的血糖記錄仍會在產品中保存最多90天。\n在應用程式中最多保存12個月。",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp3-1",QStringList{
                                                  "不能。無法恢復，刪除血糖記錄時請注意。",
                                              });

    fontData[Lan][PAGE_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_RESPONSE].insert("labelPageNum",QFont(currentFont,instance.pixelToPoint(28)));

    //=====================================================================================================================================
    //ES
    Lan = es;
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
                                         "简体中文",
                                         "繁體中文",
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

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonReboot",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonReboot",QStringList{"Reiniciar"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonYes",QStringList{"Sí"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonNo",QStringList{"No"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonLang",QStringList{
                                            "한국어",
                                            "ENGLISH",
                                            "日本語",
                                            "简体中文",
                                            "繁體中文",
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
                                               "Error del dispositivo\nContacte al centro de atención al cliente",       // 2
                                               "Error del dispositivo\nContacte al centro de atención al cliente",       // 3
                                               "No se pudo analizar\nInténtelo de nuevo",       // 4
                                               "Error en los datos\nInténtelo de nuevo",        // 5
                                               "No se puede medir mientras carga\nDesconéctelo e intente de nuevo", // 6
                                               "El dedo está muy frío.\nNo se puede medir",     // 7
                                               "Fallo en la medición\nContacte al centro de atención al cliente"         // 8
                                           });

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QFont(currentFont, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QStringList{
                                               "Actualización completada", // 0
                                               "Falló la actualización\nContacte al centro de atención al cliente", // 1
                                               "Archivo no encontrado\nRevise el archivo", // 2
                                               "Archivo con errores\nUse uno nuevo", // 3
                                               "Archivo inválido\nVerifique si es correcto", // 4
                                               "Falló la actualización\nContacte al centro de atención al cliente" // 5
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

    //PAGE_HELP_INDEX
    fontData[Lan][PAGE_HELP_INDEX].insert("labelText",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_HELP_INDEX].insert("labelText",QStringList{
                                              "Usuarios\nObjetivo", // 0
                                              "Info del\nProducto", // 1
                                              "Propósito\nde Uso", // 2
                                              "Precauciones\nPre-Medición", // 3
                                              "Consulta\nMédica Previa", // 4
                                              "Funciones\nPrincipales", // 5
                                              "Soporte\nBluetooth", // 6
                                          });

    //PAGE_HELP
    fontData[Lan][PAGE_HELP].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_HELP].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(26),QFont::Bold));
    fontData[Lan][PAGE_HELP].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_HELP].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    // 카테고리 0: Descripción del producto y propósito de uso
    textData[Lan][PAGE_HELP].insert("labelTextHelp0",QStringList{
                                        "¿Quiénes son los usuarios objetivo?", // 0-0
                                        "¿Cuáles son las funciones principales del producto?", // 0-1
                                        "¿Cuál es el propósito de uso y las precauciones?", // 0-2
                                    });
    // 카테고리 1: Precauciones de medición
    textData[Lan][PAGE_HELP].insert("labelTextHelp1",QStringList{
                                        "¿Qué debo tener en cuenta para una medición precisa?", // 1-0
                                    });
    // 카테고리 2: Restricciones de medición y consulta
    textData[Lan][PAGE_HELP].insert("labelTextHelp2",QStringList{
                                        "¿Cuándo debo consultar a un profesional médico por posibles resultados inexactos?", // 2-0
                                    });
    // 카테고리 3: Funciones de alerta
    textData[Lan][PAGE_HELP].insert("labelTextHelp3",QStringList{
                                        "¿El producto tiene funciones de alerta?", // 3-0
                                    });

    //PAGE_HELP_RESPONSE
    fontData[Lan][PAGE_HELP_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_HELP_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_HELP_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    // Help 0: Usuarios Objetivo
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp0",QStringList{
                                                 "Los usuarios objetivo son adultos mayores de 19 años\nen etapa de prediabetes.",
                                             });
    // Help 1: Info del Producto
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp1",QStringList{
                                                 "Puede medir los niveles de glucosa con el dispositivo Happyzone y vincularlo con la APP"
                                                 "@para verificar los datos de glucosa por fecha y período para gestionar y monitorear sus niveles.",
                                             });
    // Help 2: Propósito de Uso
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp2",QStringList{
                                                 "Es un dispositivo médico para la gestión (monitoreo) de glucosa de pacientes prediabéticos mayores de 19 años sin tratamiento farmacológico,"
                                                 "@y no puede utilizarse para decisiones médicas como diagnóstico de diabetes, tratamiento o administración de insulina.",
                                             });
    // Help 3: Precauciones Pre-Medición
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp3",QStringList{
                                                 "Lávese bien las manos y elimine la humedad antes de la medición.\nEvite moverse o aplicar presión fuerte en los dedos durante la medición."
                                                 "@* Consulte el manual de usuario para otros factores que pueden afectar la medición.",
                                             });
    // Help 4: Consulta Médica Previa
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp4",QStringList{
                                                 "Menores de 19 años,\n"
                                                 "Enfermedades de la piel o heridas en áreas expuestas a la luz,\ntemblores en las manos como hiperhidrosis, enfermedad de Parkinson,"
                                                 "@Historial de hipoglucemia grave, cetoacidosis diabética, epilepsia, síncope,\nenfermedades suprarrenales,"
                                                 "@En hemodiálisis o\ndiálisis peritoneal,\nmujeres embarazadas o en período de lactancia",
                                             });
    // Help 5: Funciones Principales
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp5",QStringList{
                                                 "* Alertas de estado de glucosa alta/baja\n"
                                                 "* Alertas de vencimiento de calibración de glucosa\n"
                                                 "* Alertas de recalibración de glucosa",
                                                 "Cuando han pasado 90 días desde la fecha de calibración, se produce una alerta de vencimiento.",
                                                 "Las alertas de recalibración comienzan 15 días antes del vencimiento.",
                                             });
    // Help 6: Soporte Bluetooth
    textData[Lan][PAGE_HELP_RESPONSE].insert("labelTextHelp6",QStringList{
                                                 "Es una función Bluetooth exclusiva para la APP Happyzone y no es compatible con otros dispositivos.",
                                             });

    //PAGE_FAQ_INDEX
    fontData[Lan][PAGE_FAQ_INDEX].insert("labelText",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_FAQ_INDEX].insert("labelText",QStringList{
                                             "Calibración de\nGlucosa", // 0
                                             "Medición de\nGlucosa", // 1
                                             "Cuidado del\nDispositivo", // 2
                                             "Portabilidad\ny Viaje", // 3
                                             "Registros de\nGlucosa", // 4
                                             "Usuarios/\nCapacidad", // 5
                                             "A/S", // 6
                                             "Contraseña", // 7
                                         });

    //PAGE_FAQ
    fontData[Lan][PAGE_FAQ].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_FAQ].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_FAQ].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_FAQ].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    // 카테고리 0: Calibración de Glucosa
    textData[Lan][PAGE_FAQ].insert("labelTextFaq0",QStringList{
                                       "¿Qué es la 'Calibración de Glucosa'?", // 0-0
                                       "¿Es obligatoria la calibración de glucosa?", // 0-1
                                       "¿Cuándo se realiza la calibración de glucosa?", // 0-2
                                       "¿Cuál es el ciclo de calibración de glucosa?", // 0-3
                                       "¿Se eliminan los registros previos al inicializar la calibración?", // 0-4
                                   });
    // 카테고리 1: Medición de Glucosa
    textData[Lan][PAGE_FAQ].insert("labelTextFaq1",QStringList{
                                       "¿Cuál es la postura correcta de medición?", // 1-0
                                       "¿Cómo colocar el dedo?", // 1-1
                                       "¿Debo medir siempre con el mismo dedo?", // 1-2
                                       "¿Cuál es el lugar adecuado para medir?", // 1-3
                                       "¿Puedo medir con las manos mojadas?", // 1-4
                                       "¿Cuántas veces al día debo medir?", // 1-5
                                       "¿Cuánto tiempo tarda la medición?", // 1-6
                                       "¿Puedo cancelar durante la medición?", // 1-7
                                       "La medición no se inicia.", // 1-8
                                       "La medición falla con frecuencia.", // 1-9
                                       "¿Cuál es la posición correcta del dedo?", // 1-10
                                       "¿Cuál es el rango de medición de glucosa?", // 1-11
                                   });
    // 카테고리 2: Cuidado del Dispositivo
    textData[Lan][PAGE_FAQ].insert("labelTextFaq2",QStringList{
                                       "¿Cuánto tiempo tarda la carga completa?", // 2-0
                                       "¿Cuánto dura la batería?", // 2-1
                                       "¿Se puede usar mientras se carga?", // 2-2
                                       "¿Es resistente al agua?", // 2-3
                                       "¿Cómo debo mantener el producto?", // 2-4
                                       "¿Hay lugares que debo evitar para guardar el producto?", // 2-5
                                       "¿Debo cerrar siempre la tapa de inserción del dedo?", // 2-6
                                   });
    // 카테고리 3: Portabilidad y Viaje
    textData[Lan][PAGE_FAQ].insert("labelTextFaq3",QStringList{
                                       "¿Se puede usar de forma portátil?", // 3-0
                                       "¿Se puede llevar en la cabina del avión?", // 3-1
                                       "¿Se puede enviar como equipaje facturado?", // 3-2
                                   });
    // 카테고리 4: Registros de Glucosa
    textData[Lan][PAGE_FAQ].insert("labelTextFaq4",QStringList{
                                       "¿Dónde puedo ver los resultados de glucosa?", // 4-0
                                       "¿Cuánto tiempo se guardan los registros de glucosa?", // 4-1
                                   });
    // 카테고리 5: Usuarios/Capacidad
    textData[Lan][PAGE_FAQ].insert("labelTextFaq5",QStringList{
                                       "¿Cualquier persona puede usarlo?", // 5-0
                                       "¿Cuántas personas pueden usar un solo producto?", // 5-1
                                   });
    // 카테고리 6: A/S
    textData[Lan][PAGE_FAQ].insert("labelTextFaq6",QStringList{
                                       "¿Cuál es el período de A/S del producto?", // 6-0
                                       "¿No encontró la respuesta que buscaba?", // 6-1
                                   });
    // 카테고리 7: Contraseña
    textData[Lan][PAGE_FAQ].insert("labelTextFaq7",QStringList{
                                       "¿Cómo cambio mi contraseña?", // 7-0
                                   });

    //PAGE_FAQ_RESPONSE
    fontData[Lan][PAGE_FAQ_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_FAQ_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_FAQ_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(32),QFont::Bold));
    // FAQ 카테고리 0: Calibración de Glucosa
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-0",QStringList{
                                                "Es un proceso de cálculo y ajuste de los valores de glucosa en relación con equipos invasivos"
                                                "@para reducir el error entre los valores reales y el producto.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-1",QStringList{
                                                "Sí. Dado que la estructura del área de medición y la transmisión de luz varían según las condiciones externas de cada persona,"
                                                "@la calibración individual es esencial para obtener valores precisos.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-2",QStringList{
                                                "Debe realizarse antes del primer uso. Después, debe recalibrarse dentro de los 90 días desde la fecha de calibración."
                                                "@Se le notificará 15 días antes de la fecha de vencimiento de la calibración.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-3",QStringList{
                                                "Para corregir errores por cambios en el área de medición y el entorno, debe recalibrarse dentro de los 90 días."
                                                "@Cuando han pasado 90 días desde la calibración, se produce una alerta de vencimiento y la medición se restringe hasta completar la recalibración."
                                                "@Después de inicializar y recalibrar, la medición vuelve a ser posible.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq0-4",QStringList{
                                                "No. Incluso al inicializar la calibración, los registros de glucosa se almacenan en el producto hasta 90 días."
                                                "\nEn la app se almacenan hasta 12 meses.",
                                            });
    // FAQ 카테고리 1: Medición de Glucosa
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-0",QStringList{
                                                "Sentado, apoye el codo en la mesa y mantenga el nivel horizontal."
                                                "\nRelaje el dedo e insértelo hasta el fondo, pegándolo al interior del producto.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-1",QStringList{
                                                "Empuje el dedo con la huella tocando la superficie inferior.\nCuando la punta del dedo se enganche, relaje la fuerza y fije la postura.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-2",QStringList{
                                                "Para una medición precisa, se recomienda medir con el mismo dedo.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-3",QStringList{
                                                "Mida en un lugar con temperatura interior de 20~30°C, sin luz solar directa, viento, humedad ni vibraciones que puedan afectar al producto.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-4",QStringList{
                                                "No. Medir con las manos mojadas puede causar mal funcionamiento del producto.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-5",QStringList{
                                                "La glucosa varía según las comidas/actividades, se recomienda medir 1 vez al despertar, 1 vez antes y después de cada comida, y 1 vez antes de dormir.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-6",QStringList{
                                                "El resultado de la medición se obtiene en menos de 1 minuto después de iniciar.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-7",QStringList{
                                                "Presionando el botón 'Cancelar' durante la medición se detendrá.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-8",QStringList{
                                                "Cuando la calibración de glucosa ha vencido (90 días), no es posible medir. Realice la calibración de glucosa.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-9",QStringList{
                                                "Verifique el entorno de medición e intente de nuevo.\n"
                                                "Las condiciones de medición son las siguientes:"
                                                "@No tosa, estornude, hable ni se mueva durante la medición\n"
                                                "Relaje el dedo y péguelo horizontalmente a la superficie"
                                                "@Mantenga la temperatura del dedo a 26°C o más\n"
                                                "Elimine la humedad y cuerpos extraños del dedo"
                                                "@* Consulte el manual de usuario\n[Mensajes de error & soluciones]",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-10",QStringList{
                                                "Empuje el dedo con la huella tocando la superficie inferior.\nCuando la punta del dedo se enganche, relaje la fuerza y fije la postura.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq1-11",QStringList{
                                                "70~350mg/dL\n\n"
                                                "El rango de medición de glucosa de este producto es de mínimo 70 a máximo 350.",
                                            });
    // FAQ 카테고리 2: Cuidado del Dispositivo
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-0",QStringList{
                                                "El tiempo total de carga completa es de aproximadamente 3 horas y 45 minutos.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-1",QStringList{
                                                "Con carga completa, se puede usar hasta 29 días con 8 mediciones diarias.\nPuede variar según el estado de la batería.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-2",QStringList{
                                                "Asegúrese de desconectar el cargador antes de usar.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-3",QStringList{
                                                "No. Este producto no es resistente al agua, no lo opere con las manos mojadas. Si el producto se moja, séquelo inmediatamente y verifique su funcionamiento.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-4",QStringList{
                                                "Limpie con un paño suave y déjelo secar. No use detergentes, alcohol ni sustancias químicas.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-5",QStringList{
                                                "Evite ambientes húmedos (baño, cocina, etc.) y temperaturas superiores a 60°C (vehículos cerrados, exposición solar directa, etc.).",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq2-6",QStringList{
                                                "Sí, cuando no lo use, cierre siempre la tapa y guárdelo en su estuche."
                                                "@Esto previene daños o cortocircuitos causados por polvo, objetos metálicos o punzantes que entren al interior.",
                                            });
    // FAQ 카테고리 3: Portabilidad y Viaje
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq3-0",QStringList{
                                                "Sí, puede cargarlo y llevarlo para usarlo en ambientes interiores adecuados para la medición. Sin embargo, los golpes externos pueden causar mal funcionamiento,"
                                                "@así que llévelo en el estuche portátil para protegerlo.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq3-1",QStringList{
                                                "La batería de polímero de iones de litio de este producto (aprox. 4.4Wh) cumple con los estándares de seguridad aérea (menos de 100Wh) y se puede llevar en cabina."
                                                "@Las regulaciones pueden variar según la aerolínea y el país, consulte con su aerolínea antes de viajar."
                                                "@[ Especificaciones de la batería ]\n"
                                                "Voltaje: 3.7V\n"
                                                "Capacidad: 1200mAh\n"
                                                "Total: 4.44Wh",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq3-2",QStringList{
                                                "Este producto tiene una batería de polímero de iones de litio (aprox. 4.4Wh)."
                                                "@Las regulaciones pueden variar según la aerolínea y el país, consulte con su aerolínea antes de viajar."
                                                "@[ Especificaciones de la batería ]\n"
                                                "Voltaje: 3.7V\n"
                                                "Capacidad: 1200mAh\n"
                                                "Total: 4.44Wh",
                                            });
    // FAQ 카테고리 4: Registros de Glucosa
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq4-0",QStringList{
                                                "Presione el icono 'Registros de glucosa' en el menú de configuración del producto,"
                                                "@o conéctese al smartphone por Bluetooth y verifique en la app."
                                                "@Los registros del día se muestran automáticamente en la pantalla de inicio."
                                                "@Para registros anteriores, presione el icono de registros de glucosa en la configuración.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq4-1",QStringList{
                                                "Este producto almacena los registros de glucosa medidos hasta un máximo de 90 días.\n"
                                                "Los registros de más de 90 días se eliminan automáticamente.",
                                            });
    // FAQ 카테고리 5: Usuarios/Capacidad
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq5-0",QStringList{
                                                "Es un dispositivo médico para pacientes prediabéticos mayores de 19 años sin tratamiento farmacológico."
                                                "@Para decisiones médicas como diagnóstico y tratamiento de diabetes o administración de insulina, consulte a un profesional médico.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq5-1",QStringList{
                                                "Este producto puede ser usado por un máximo de 2 personas.",
                                            });
    // FAQ 카테고리 6: A/S
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq6-0",QStringList{
                                                "Este producto está garantizado hasta 2 años desde la fecha de compra.\nSin embargo, no se cubren daños o averías por causas personales.",
                                            });
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq6-1",QStringList{
                                                "Por favor, contacte al centro de atención al cliente.",
                                            });
    // FAQ 카테고리 7: Contraseña
    textData[Lan][PAGE_FAQ_RESPONSE].insert("labelTextFaq7-0",QStringList{
                                                "Vaya a la barra superior 'Menú' - 'Info de usuario' - 'Cambiar contraseña' y siga las instrucciones para cambiar su contraseña.",
                                            });

    //PAGE_ERROR_HELP_INDEX
    fontData[Lan][PAGE_ERROR_HELP_INDEX].insert("labelText",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    textData[Lan][PAGE_ERROR_HELP_INDEX].insert("labelText",QStringList{
                                                    "Medición de\nGlucosa", // 0
                                                    "Cuidado del\nDispositivo", // 1
                                                    "Bluetooth", // 2
                                                    "Registros de\nGlucosa", // 3
                                                });

    //PAGE_ERROR_HELP
    fontData[Lan][PAGE_ERROR_HELP].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelTextBold",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_ERROR_HELP].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    // 카테고리 0: Medición de Glucosa
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp0",QStringList{
                                              "La medición no se inicia", // 0-0
                                              "La medición falla con frecuencia", // 0-1
                                              "Aparece el mensaje 'No se reconoció el dedo'", // 0-2
                                              "Aparece el mensaje 'La temperatura del dedo es demasiado baja'", // 0-3
                                              "Aparece el mensaje 'Error en los datos de medición'", // 0-4
                                              "No avanza al siguiente paso", // 0-5
                                              "Aparece el mensaje 'No se pueden analizar los resultados'", // 0-6
                                              "La glucosa es normal pero aparece una advertencia", // 0-7
                                          });
    // 카테고리 1: Cuidado del Dispositivo
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp1",QStringList{
                                              "Los botones no funcionan al presionarlos", // 1-0
                                              "No entra en la pantalla inicial tras encender", // 1-1
                                              "Aparece el mensaje 'No se encuentra el archivo de actualización'", // 1-2
                                              "Aparece el mensaje 'El archivo de actualización tiene un problema'", // 1-3
                                              "Aparece el mensaje 'No es un archivo de actualización'", // 1-4
                                              "El dispositivo se apagó durante la actualización", // 1-5
                                              "La pantalla está congelada o muy lenta", // 1-6
                                              "No sé qué error es este", // 1-7
                                              "La pantalla no responde al tacto", // 1-8
                                              "No se puede cargar", // 1-9
                                          });
    // 카테고리 2: Bluetooth
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp2",QStringList{
                                              "No se puede vincular con la aplicación", // 2-0
                                              "Los valores del producto y la aplicación son diferentes", // 2-1
                                          });
    // 카테고리 3: Registros de Glucosa
    textData[Lan][PAGE_ERROR_HELP].insert("labelTextErrorHelp3",QStringList{
                                              "¿Se eliminan los registros previos al inicializar la calibración?", // 3-0
                                              "¿Se pueden recuperar los registros de glucosa eliminados?", // 3-1
                                          });

    //PAGE_ERROR_RESPONSE
    fontData[Lan][PAGE_ERROR_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_ERROR_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_ERROR_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(32),QFont::Bold));
    // ErrorHelp 카테고리 0: Medición de Glucosa
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-0",QStringList{
                                                  "Cuando la calibración de glucosa ha vencido (90 días), no es posible medir. Realice la calibración de glucosa.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-1",QStringList{
                                                  "Verifique el entorno de medición e intente de nuevo.\n"
                                                  "Las condiciones de medición son las siguientes:"
                                                  "@No tosa, estornude, hable ni se mueva durante la medición\n"
                                                  "Relaje el dedo y péguelo horizontalmente a la superficie"
                                                  "@Mantenga la temperatura del dedo a 26°C o más\n"
                                                  "Elimine la humedad y cuerpos extraños del dedo"
                                                  "@* Consulte el manual de usuario\n[Mensajes de error & soluciones]",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-2",QStringList{
                                                  "Verifique que el dedo esté correctamente insertado y mida de nuevo."
                                                  "@Empuje el dedo con la huella tocando la superficie inferior.\nCuando la punta se enganche, relaje la fuerza y fije la postura.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-3",QStringList{
                                                  "Caliente suficientemente el dedo y mida de nuevo.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-4",QStringList{
                                                  "Evite hablar, temblar y estornudar, descanse un momento y mida de nuevo.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-5",QStringList{
                                                  "Es posible que la medición no se haya completado. Mida de nuevo. Si el problema persiste, apague y encienda el dispositivo.",
                                                  "Si estuvo expuesto a condiciones externas (baja temperatura u objetos calientes cercanos), puede funcionar mal."
                                                  "@Use a temperatura interior de 20~30°C.",
                                                  "Si no fue por temperatura, humedad o agua, contacte al centro de atención al cliente.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-6",QStringList{
                                                  "Verifique la posición del dedo y el entorno de medición, luego mida de nuevo.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp0-7",QStringList{
                                                  "Presione el icono de rango de glucosa para ajustar el rango de alerta de estado.",
                                              });
    // ErrorHelp 카테고리 1: Cuidado del Dispositivo
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-0",QStringList{
                                                  "Apague y encienda el dispositivo.\n"
                                                  "Verifique que la batería esté suficiente.\n"
                                                  "No se puede medir con el cargador conectado.",
                                                  "@Si estuvo en contacto con agua o en un ambiente húmedo, puede ser causa de avería. Verifique el estado del producto.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-1",QStringList{
                                                  "Verifique la conexión del cable de carga y el adaptador, luego cargue."
                                                  "@Después de cargar, al encender y completar el arranque, se puede usar normalmente.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-2",QStringList{
                                                  "Verifique el archivo de actualización. Si el problema persiste, contacte al centro de atención al cliente.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-3",QStringList{
                                                  "Descargue nuevamente el archivo de actualización e intente con el nuevo archivo. Si el problema persiste, contacte al centro de atención al cliente.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-4",QStringList{
                                                  "Verifique si el archivo es correcto e intente de nuevo. Si el problema persiste, contacte al centro de atención al cliente.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-5",QStringList{
                                                  "Cargue el dispositivo e intente la actualización de nuevo. Si el problema persiste, contacte al centro de atención al cliente.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-6",QStringList{
                                                  "Use un pin para presionar el botón de reinicio. Después de reiniciar el sistema, se puede usar normalmente.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-7",QStringList{
                                                  "Reinicie y verifique si ocurre el mismo error. Si el problema persiste, contacte al centro de atención al cliente.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-8",QStringList{
                                                  "Reinicie y verifique si funciona normalmente. Si el problema persiste, contacte al centro de atención al cliente.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp1-9",QStringList{
                                                  "Verifique la conexión del cable de carga y el adaptador."
                                                  "@Verifique que las especificaciones de salida del adaptador de carga coincidan con las recomendadas del producto.",
                                                  "@Si el problema persiste, contacte al centro de atención al cliente.",
                                              });
    // ErrorHelp 카테고리 2: Bluetooth
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp2-0",QStringList{
                                                  "Toque el icono 'Bluetooth' en la barra superior de la pantalla para activarlo. Luego mantenga su teléfono a menos de 1M del producto"
                                                  "@y busque Bluetooth en su teléfono para encontrar y vincular el producto Happyzone."
                                                  "@Si el problema persiste, apague y encienda el producto nuevamente.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp2-1",QStringList{
                                                  "Verifique la fecha y el elemento de medición.\n"
                                                  "Si el problema persiste, puede ser un error temporal. Apague y reinicie tanto el producto como la aplicación y vuelva a vincularlos.",
                                              });
    // ErrorHelp 카테고리 3: Registros de Glucosa
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp3-0",QStringList{
                                                  "No. Incluso al inicializar la calibración, los registros de glucosa se almacenan en el producto hasta 90 días.\nEn la app se almacenan hasta 12 meses.",
                                              });
    textData[Lan][PAGE_ERROR_RESPONSE].insert("labelTextErrorHelp3-1",QStringList{
                                                  "No. No es posible recuperarlos, tenga cuidado al eliminar registros de glucosa.",
                                              });

    fontData[Lan][PAGE_RESPONSE].insert("labelText",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_RESPONSE].insert("labelNumCurrent",QFont(currentFont,instance.pixelToPoint(28)));
    fontData[Lan][PAGE_RESPONSE].insert("labelNumAll",QFont(currentFont,instance.pixelToPoint(28),QFont::Bold));
    fontData[Lan][PAGE_RESPONSE].insert("labelPageNum",QFont(currentFont,instance.pixelToPoint(28)));

#if FONT_DEBUG
    for(const auto& textName : fontData[ko][PAGE_PASSWORD].keys())
    {
        QFont font = fontData[ko][PAGE_PASSWORD][textName];
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

