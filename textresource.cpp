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

    //CUSTOM_COMPONENT
    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextValue",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextResult",QFont(currentFont,instance.pixelToPoint(42),QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextResult",QStringList{
                                               "측정에 성공하였습니다",     // 0
                                               "손가락을 인식하지 못했습니다\n다시 측정해 주세요", // 1
                                               "기기에 문제가 발생했습니다\n고객센터로 문의해 주세요",                // 2
                                               "기기에 문제가 발생했습니다\n고객센터로 문의해 주세요",              // 3
                                               "측정 결과를 분석할 수 없습니다\n다시 측정해 주세요",             // 4
                                               "측정된 데이터에 오류가 있습니다\n다시 측정해 주세요",             // 5
                                               "측정에 실패했습니다\n고객센터로 문의해 주세요",              // 6
                                               "오류. 측정에 실패했습니다\n고객센터로 문의해 주세요"             // 7
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

    fontData[Lan][PAGE_SELECT_USER].insert("labelUserText",QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][PAGE_SELECT_USER].insert("labelUserText",QStringList{"사용자 1","사용자 2"});

    //PAGE_PASSWORD_ALLCHAT
    fontData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelButtonNum",QFont(currentFont,instance.pixelToPoint(44)));

    fontData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitle",QFont(currentFont,instance.pixelToPoint(40),QFont::Bold));
    textData[Lan][PAGE_PASSWORD_ALLCHAT].insert("labelTitle",QStringList{"로그인을 하세요","비밀번호 변경","사용자 삭제","비밀번호 확인","비밀번호 재확인","비밀번호 초기화","PASSWORD_MAX"});

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
                                                    "사용자 정보 삭제", //PASSWORD_STR_DELETE,
                                                    "사용자 정보 삭제", //PASSWORD_STR_DELETE_CONFIRM,
                                                    "사용자 정보 삭제", //PASSWORD_STR_DELETE_SUCCESS,
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
                                                    "사용자 정보를 삭제하시겠습니까?", //PASSWORD_STR_DELETE,
                                                    "사용자 정보를 삭제할 경우\n 비밀번호와 설정이 초기화 됩니다", //PASSWORD_STR_DELETE_CONFIRM,
                                                    "사용자 정보가 삭제되었습니다\n설정 초기화를 위해 재부팅이 진행됩니다", //PASSWORD_STR_DELETE_SUCCESS,
                                                    "로그아웃을 진행합니까?\n로그아웃시 다시 로그인해주시기 바랍니다", //PASSWORD_STR_LOGOUT,
                                                    "비밀번호를 초기화하시겠습니까?", //PASSWORD_STR_INIT,
                                                    "비밀번호를 초기화할 경우\n 비밀번호가 초기 설정 상태가 됩니다", //PASSWORD_STR_INIT_CONFIRM,
                                                    "비밀번호가 초기화되었습니다", //PASSWORD_STR_INIT_SUCCESS,가
                                                    "PASSWORD_STR_MAX" //PASSWORD_STR_MAX
                                                });

    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTextError",QStringList{
                                                    "비밀번호가 설정되었습니다", // GAPI_PASSWD_ECODE_NORMAL
                                                    "비밀번호는 8~12 자리여야 합니다", // GAPI_PAS다SWD_ECODE_RANGE_LEN
                                                    "비밀번호에는 숫자가 포함되어야 합니다", // GAPI_PASSWD_ECODE_NO_NUMBER
                                                    "영문자(A-Z)가 포함되어야 합니다", // GAPI_PASSWD_ECODE_NO_ALPHABET
                                                    "기호(.,?! 등)가 포함되어야 합니다", // GAPI_PASSWD_ECODE_NO_SPECTAL
                                                    "비밀번호가 일치하지 않습니다", // GAPI_PASSWD_ECODE_NO_MATCH
                                                    "알 수 없는 오류입니다", // GAPI_PASSWD_ECODE_MAX
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
                                        "유저정보"});

    //PAGE_CALI_CEHCK
    fontData[Lan][PAGE_CALI_CHECK].insert("labelTextCheck",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_CHECK].insert("labelTextCheck",QStringList{
                                              "혈당 보정 단계입니다\n손가락을 삽입구에 넣어주세요",
                                              "혈당 보정 완료입니다\n재진행하시겠습니까?"
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
                                                    "공복 8시간 이상\n경과되었습니까?",
                                                    "식후 1시간 이상\n경과되었습니까?",
                                                    "식후 1시간 30분 이상\n경과되었습니까?",
                                                    "식후 2시간 이상\n경과되었습니까?"
                                                });

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
                                                "혈당 보정이 초기화됩니다\n혈당 보정을 초기화하시겠습니까?",
                                                "혈당 보정이 초기화되었습니다"
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
                                            "사용자 정보 삭제",
                                            "로그아웃"
                                        });

    //PAGE_BATPOPUP
    fontData[Lan][PAGE_BATPOPUP].insert("labelText",QFont(currentFont,instance.pixelToPoint(42),QFont::Bold));
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

    //CUSTOM_COMPONENT
    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextValue",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextResult",QFont(currentFont,instance.pixelToPoint(36)));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextResult", QStringList{
                                               "Measurement was successful.",     // 0
                                               "Finger not detected.\nPlease try measuring again.", // 1
                                               "A problem occurred with the device.\nPlease contact customer support.", // 2
                                               "A problem occurred with the device.\nPlease contact customer support.", // 3
                                               "Unable to analyze the measurement result.\nPlease try again.", // 4
                                               "There is an error in the measured data.\nPlease try again.", // 5
                                               "Measurement failed.\nPlease contact customer support.", // 6
                                               "Error. Measurement failed.\nPlease contact customer support." // 7
                                           });

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QFont(currentFont, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QStringList{
                                               "Upgrade completed successfully.", // 0
                                               "Upgrade failed.\nPlease contact customer support.", // 1
                                               "Upgrade file not found.\nPlease check the file again.", // 2
                                               "There is a problem with the upgrade file.\nPlease try again with a new file.", // 3
                                               "This is not a valid upgrade file.\nPlease check if the file is correct.", // 4
                                               "Upgrade failed.\nPlease contact customer support." // 5
                                           });

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
                                                    "Delete User",
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
                                                    "Delete Info", //PASSWORD_STR_DELETE,
                                                    "Delete Info", //PASSWORD_STR_DELETE_CONFIRM,
                                                    "Delete Info", //PASSWORD_STR_DELETE_SUCCESS,
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
                                                    "The entered password does not match\nthe previous password",
                                                    "Would you like to change\nyour password?",
                                                    "Please enter your password\nfor verification",
                                                    "Please enter a new password\n\nMin. 8 characters, including number,\nletter, and symbol like .,?!",
                                                    "Password changed\nPlease log in again",
                                                    "Do you want to delete\nuser information?",
                                                    "Deleting user information will reset\nthe password and settings",
                                                    "User information deleted\nThe system will reboot to reset settings",
                                                    "Logging out\nPlease log in again",
                                                    "Do you want to reset\nyour password?",
                                                    "Resetting will restore the password\nto its default value",
                                                    "Password has been reset",
                                                    "PASSWORD_STR_MAX"
                                                });

    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTextError", QStringList{
                                                    "Password has been set",                                      // GAPI_PASSWD_ECODE_NORMAL
                                                    "Password must be\n8 to 12 characters long",                   // GAPI_PASSWD_ECODE_RANGE_LEN
                                                    "Password must include\nat least one number",                  // GAPI_PASSWD_ECODE_NO_NUMBER
                                                    "Password must include\nat least one letter (A-Z)",            // GAPI_PASSWD_ECODE_NO_ALPHABET
                                                    "Password must include\nat least one symbol (e.g. .,?!)",      // GAPI_PASSWD_ECODE_NO_SPECTAL
                                                    "Passwords do not match",                                     // GAPI_PASSWD_ECODE_NO_MATCH
                                                    "An unknown error has occurred",                              // GAPI_PASSWD_ECODE_MAX
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
                                        "User"
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
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectText",QFont(currentFont,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT].insert("labelSelectText",QStringList{
                                               "Empty\nstomach",
                                               "After meal"
                                           });

    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextAdc",QFont(currentFont,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextValue",QFont(currentFont,instance.pixelToPoint(36)));


    //PAGE_CALI_SELECT_INFO
    fontData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText",QFont(currentFont,instance.pixelToPoint(nTextSize),QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText",QStringList{
                                                    "Has it been more than 8 hours\n since your last meal?",
                                                    "Has it been more than 1 hour\n since your last meal?",
                                                    "Has it been more than 1 hour\n and 30 minutes since \nyour last meal?",
                                                    "Has it been more than 2 hours\n  since your last meal?"
                                                });

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
                                                "The entire system\ninformation will be reset.\nDo you want to proceed\nwith factory reset?",
                                                "After system initialization,\nthe system will restart",
                                                "Bluetooth user information\nwill be initialized.\nThe connection with the\nsmartphone is disconnected.\nWould you like to reset\nBluetooth?",
                                                "Bluetooth user information\nhas been reset",
                                                "Blood sugar correction\nwill be reset\nDo you want to reset\nblood sugar correction?",
                                                "Blood sugar correction\nhas been reset"
                                            });


    fontData[Lan][PAGE_THRESHOLD].insert("labelText",QFont(currentFont,instance.pixelToPoint(36)));
    textData[Lan][PAGE_THRESHOLD].insert("labelText",QStringList{
                                             "Low Blood Sugar",
                                             "High Blood Suger"
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
                                            "Delete user data",
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

    //CUSTOM_COMPONENT
    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextValue", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextResult", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextResult", QStringList{
                                               "測定に成功しました。",     // 0
                                               "指を認識できませんでした。\nもう一度測定してください。", // 1
                                               "デバイスに問題が発生しました。\nカスタマーサポートにお問い合わせください。", // 2
                                               "デバイスに問題が発生しました。\nカスタマーサポートにお問い合わせください。", // 3
                                               "測定結果を解析できませんでした。\nもう一度測定してください。", // 4
                                               "測定データにエラーがあります。\nもう一度測定してください。", // 5
                                               "測定に失敗しました。\nカスタマーサポートにお問い合わせください。", // 6
                                               "エラー測定に失敗しました。\nカスタマーサポートにお問い合わせください。" // 7
                                           });

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QStringList{
                                               "アップグレードに成功しました。", // 0
                                               "アップグレードに失敗しました。\nカスタマーサポートにお問い合わせください。", // 1
                                               "アップグレードファイルが見つかりません。\nファイルを再確認してください。", // 2
                                               "アップグレードファイルに問題があります。\n新しいファイルで再試行してください。", // 3
                                               "アップグレード用のファイルではありません。\n正しいファイルか確認してください。", // 4
                                               "アップグレードに失敗しました。\nカスタマーサポートにお問い合わせください。" // 5
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
                                                    "ユーザー削除",
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
                                                    "情報削除", // PASSWORD_STR_DELETE
                                                    "情報削除", // PASSWORD_STR_DELETE_CONFIRM
                                                    "情報削除", // PASSWORD_STR_DELETE_SUCCESS
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
                                                    "ユーザー情報を削除しますか？",
                                                    "ユーザー情報を削除すると\nパスワードと設定がリセットされます",
                                                    "ユーザー情報が削除されました\n設定リセットのため、システムを再起動します",
                                                    "ログアウトしますか？\nログアウト後は再度ログインしてください",
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
                                        "ユーザー"       // User
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
                                                    "最後の食事から8時間以上\n経過しましたか？",            // Has it been more than 8 hours since your last meal?
                                                    "最後の食事から1時間以上\n経過しましたか？",            // Has it been more than 1 hour since your last meal?
                                                    "最後の食事から1時間30分以上\n経過しましたか？",        // Has it been more than 1 hour and 30 minutes since your last meal?
                                                    "最後の食事から2時間以上\n経過しましたか？"            // Has it been more than 2 hours since your last meal?
                                                });

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
                                                "システム全体の情報が\nリセットされます。\n工場出荷状態に\nリセットしますか？", // The entire system information will be reset. Do you want to proceed with factory reset?
                                                "システムの初期化後、\nシステムが再起動します",          // After system initialization, the system will restart
                                                "Bluetoothのユーザー情報が\n初期化されます。\nスマートフォンとの接続が\n切断されます。\nBluetoothをリセットしますか？", // Bluetooth user information will be initialized. The connection with the smartphone is disconnected. Would you like to reset Bluetooth?
                                                "Bluetoothのユーザー情報が\n初期化されました",          // Bluetooth user information has been reset
                                                "血糖補正がリセットされます\n血糖補正を\nリセットしますか？", // Blood sugar correction will be reset. Do you want to reset blood sugar correction?
                                                "血糖補正がリセットされました"                     // Blood sugar correction has been reset
                                            });


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
                                            "ユーザーデータを削除する", // Delete user data
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

    //CUSTOM_COMPONENT
    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextValue", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextResult", QFont(currentFont, instance.pixelToPoint(42)));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextResult", QStringList{
                                               "测量成功。",     // 0
                                               "未检测到手指。\n请重新测量。", // 1
                                               "设备出现问题。\n请联系客服。", // 2
                                               "设备出现问题。\n请联系客服。", // 3
                                               "无法分析测量结果。\n请重新测量。", // 4
                                               "测量数据有误。\n请重新测量。", // 5
                                               "测量失败。\n请联系客服。", // 6
                                               "错误测量失败。\n请联系客服。" // 7
                                           });

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QFont(currentFont, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QStringList{
                                               "升级成功。", // 0
                                               "升级失败。\n请联系客服。", // 1
                                               "未找到升级文件。\n请重新检查文件。", // 2
                                               "升级文件有问题。\n请使用新文件重试。", // 3
                                               "此文件不是有效的升级文件。\n请确认文件是否正确。", // 4
                                               "升级失败。\n请联系客服。" // 5
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
                                                    "删除用户",
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
                                                    "删除信息",          // PASSWORD_STR_DELETE
                                                    "删除信息确认",      // PASSWORD_STR_DELETE_CONFIRM
                                                    "信息删除成功",      // PASSWORD_STR_DELETE_SUCCESS
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
                                                    "是否删除用户信息？",
                                                    "删除用户信息将重置密码和设置",
                                                    "用户信息已删除。\n系统将重新启动以重置设置",
                                                    "正在退出登录，请重新登录",
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
                                        "用户"        // User
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
                                                    "距离上次进餐是否已超过8小时？",         // Has it been more than 8 hours since your last meal?
                                                    "距离上次进餐是否已超过1小时？",         // Has it been more than 1 hour since your last meal?
                                                    "距离上次进餐是否已超过1小时30分钟？",   // Has it been more than 1 hour and 30 minutes since your last meal?
                                                    "距离上次进餐是否已超过2小时？"          // Has it been more than 2 hours since your last meal?
                                                });

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
                                                "系统的所有信息将会被重置。\n是否继续进行出厂设置？",   // The entire system information will be reset. Do you want to proceed with factory reset?
                                                "系统初始化后将会重新启动",                 // After system initialization, the system will restart
                                                "蓝牙用户信息将会初始化。\n与智能手机的连接将被断开。\n是否重置蓝牙？", // Bluetooth user information will be initialized. The connection with the smartphone is disconnected. Would you like to reset Bluetooth?
                                                "蓝牙用户信息已被初始化",                 // Bluetooth user information has been reset
                                                "血糖校正将被重置。\n是否重置血糖校正？", // Blood sugar correction will be reset. Do you want to reset blood sugar correction?
                                                "血糖校正已被重置"                       // Blood sugar correction has been reset
                                            });


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
                                            "删除用户数据", // Delete user data
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

    //CUSTOM_COMPONENT
    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextValue", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextResult", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextResult", QStringList{
                                               "測量成功。",     // 0
                                               "未偵測到手指。\n請重新測量。", // 1
                                               "設備發生問題。\n請聯繫客服。", // 2
                                               "設備發生問題。\n請聯繫客服。", // 3
                                               "無法分析測量結果。\n請重新測量。", // 4
                                               "測量數據有誤。\n請重新測量。", // 5
                                               "測量失敗。\n請聯繫客服。", // 6
                                               "錯誤測量失敗。\n請聯繫客服。" // 7
                                           });

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QFont(currentFont, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QStringList{
                                               "升級成功。", // 0
                                               "升級失敗。\n請聯繫客服。", // 1
                                               "找不到升級檔案。\n請重新檢查檔案。", // 2
                                               "升級檔案有問題。\n請使用新檔案重試。", // 3
                                               "此檔案不是有效的升級檔案。\n請確認是否正確。", // 4
                                               "升級失敗。\n請聯繫客服。" // 5
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
                                                    "刪除使用者",
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
                                                    "刪除信息",       // Delete Info
                                                    "刪除信息",       // Delete Info (PASSWORD_STR_DELETE_CONFIRM)
                                                    "刪除信息",       // Delete Info (PASSWORD_STR_DELETE_SUCCESS)
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
                                                    "是否刪除使用者資訊？",
                                                    "刪除使用者資訊將重置密碼和設定",
                                                    "使用者資訊已刪除。\n系統將重新啟動以重置設定",
                                                    "正在登出，請重新登入",
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
                                        "用戶"            // User
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
                                                    "距離上次進餐是否已超過8小時？",           // Has it been more than 8 hours since your last meal?
                                                    "距離上次進餐是否已超過1小時？",           // Has it been more than 1 hour since your last meal?
                                                    "距離上次進餐是否已超過1小時30分鐘？",    // Has it been more than 1 hour and 30 minutes since your last meal?
                                                    "距離上次進餐是否已超過2小時？"            // Has it been more than 2 hours since your last meal?
                                                });

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
                                                "整個系統資訊將被重置。\n是否繼續執行出廠重置？", // The entire system information will be reset. Do you want to proceed with factory reset?
                                                "系統初始化後，\n系統將重新啟動",            // After system initialization, the system will restart
                                                "藍牙用戶資訊將被初始化。\n與智能手機的連接將被斷開。\n是否重置藍牙？", // Bluetooth user information will be initialized. The connection with the smartphone is disconnected. Would you like to reset Bluetooth?
                                                "藍牙用戶資訊已被重置",                      // Bluetooth user information has been reset
                                                "血糖校正將被重置。\n是否重置血糖校正？",      // Blood sugar correction will be reset. Do you want to reset blood sugar correction?
                                                "血糖校正已被重置"                           // Blood sugar correction has been reset
                                            });


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
                                            "刪除用戶數據", // Delete user data
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

    //CUSTOM_COMPONENT
    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextValue", QFont(currentFont, instance.pixelToPoint(30), QFont::Bold));

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextResult", QFont(currentFont, instance.pixelToPoint(36)));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextResult", QStringList{
                                               "Medición exitosa.",     // 0
                                               "No se detectó el dedo.\nInténtelo de nuevo.", // 1
                                               "Error del dispositivo.\nContacte soporte.", // 2
                                               "Error del dispositivo.\nContacte soporte.", // 3
                                               "No se pudo analizar.\nInténtelo de nuevo.", // 4
                                               "Error en los datos.\nInténtelo de nuevo.", // 5
                                               "Fallo en la medición.\nContacte soporte.", // 6
                                               "Error al medir.\nContacte soporte." // 7
                                           });

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QFont(currentFont, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextUpgrade", QStringList{
                                               "Actualización completada.", // 0
                                               "Falló la actualización.\nContacte soporte.", // 1
                                               "Archivo no encontrado.\nRevise el archivo.", // 2
                                               "Archivo con errores.\nUse uno nuevo.", // 3
                                               "Archivo inválido.\nVerifique si es correcto.", // 4
                                               "Falló la actualización.\nContacte soporte." // 5
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
                                                    "Eliminar usuario",
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
                                                    "Eliminar información",                 // Delete Info
                                                    "Eliminar información",                 // Delete Info
                                                    "Eliminar información",                 // Delete Info
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
                                                    "¿Desea eliminar la información del usuario?",                                     // 사용자 정보를 삭제하시겠습니까?
                                                    "Eliminar la información del usuario\nrestablecerá la contraseña\ny la configuración", // 사용자 정보를 삭제할 경우 비밀번호와 설정이 초기화 됩니다
                                                    "Información del usuario eliminada\nEl sistema se reiniciará\npara restablecer la configuración", // 사용자 정보가 삭제되었습니다
                                                    "Cerrando sesión\nPor favor vuelva a iniciar sesión",                              // 로그아웃을 진행합니까? (→ 원문과 조금 어색함)
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
                                        "Cali\nbración",
                                        "Rango",
                                        "Lista",
                                        "Sonido",
                                        "Dormir",
                                        "Cambio",
                                        "Fecha",
                                        "Modo de\ncolor",
                                        "Idioma",
                                        "Actualizar",
                                        "Info de\ndispositivo",
                                        "Restablecer",
                                        "Usuario"
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
                                                    "El ajuste de sensibilidad del LED falló.\nPor favor, mida nuevamente"
                                                });

    //PAGE_CALI_SELECT
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectText", QFont(currentFont, instance.pixelToPoint(18), QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT].insert("labelSelectText", QStringList{
                                               "En ayunas", "Después de comer"
                                           });

    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextAdc", QFont(currentFont, instance.pixelToPoint(36), QFont::Bold));
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextValue", QFont(currentFont, instance.pixelToPoint(36)));

    //PAGE_CALI_SELECT_INFO
    fontData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText", QFont(currentFont, instance.pixelToPoint(nTextSize), QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText", QStringList{
                                                    "¿Han pasado más de 8 horas\ndesde tu última comida?",
                                                    "¿Ha pasado más de 1 hora\ndesde tu última comida?",
                                                    "¿Ha pasado más de 1 hora y 30 minutos\ndesde tu última comida?",
                                                    "¿Han pasado más de 2 horas\ndesde tu última comida?"
                                                });

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
                                                "se restablecerá.\n\n"
                                                "¿Desea proceder con el\n"
                                                "restablecimiento de fábrica?",

                                                "Después de la inicialización\n"
                                                "del sistema,\n"
                                                "el sistema se reiniciará.",

                                                "La información del usuario de\n"
                                                "Bluetooth se inicializará.\n\n"
                                                "La conexión con el\n"
                                                "smartphone se desconectará.\n\n"
                                                "¿Desea restablecer Bluetooth?",

                                                "La información del usuario de\n"
                                                "Bluetooth ha sido restablecida.",

                                                "La corrección de azúcar\n"
                                                "se restablecerá.\n\n"
                                                "¿Desea restablecer la\n"
                                                "corrección de azúcar?",

                                                "La corrección de azúcar\n"
                                                "ha sido restablecida."
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
                                            "Eliminar datos de usuario",
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
