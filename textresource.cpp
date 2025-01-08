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


    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonOK",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonOK",QStringList{"확인"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel",QStringList{"취소"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonHome",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonHome",QStringList{"홈"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart",QStringList{"측정시작"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasure",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasure",QStringList{"측정"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonInput",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonInput",QStringList{"입력"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe",QStringList{"재측정"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonSave",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonSave",QStringList{"저장"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonUpgrade",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonUpgrade",QStringList{"소프트웨어 업그레이드"});

    //CUSTOM_COMPONENT
    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextValue",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextResult",QFont(instance.fontSuit,instance.pixelToPoint(36)));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextResult",QStringList{
                                               "측정을 성공하였습니다",     // 0
                                               "측정시간이 초과되었습니다", // 1
                                               "NULL_PTR",                // 2
                                               "COUNT_ZERO",              // 3
                                               "MALLOC_FAIL",             // 4
                                               "NONE_GREADE",             // 5
                                               "PARAM_FAIL",              // 6
                                               "RESULT_FAIL",             // 7
                                               "ECODE_MAX"
                                           });

    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(50)));
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelTextSelect",QFont(instance.fontSuit,instance.pixelToPoint(50),QFont::Bold));
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelTextSub",QFont(instance.fontSuit,instance.pixelToPoint(40)));


    //PAGE_PASSWORD
    fontData[Lan][PAGE_PASSWORD].insert("labelButtonNum",QFont(instance.fontSuit,instance.pixelToPoint(44),QFont::Bold));

    fontData[Lan][PAGE_PASSWORD].insert("labelTitle",QFont(instance.fontSuit,instance.pixelToPoint(40),QFont::Bold));
    textData[Lan][PAGE_PASSWORD].insert("labelTitle",QStringList{"로그인을 하세요","비밀번호 변경","사용자 삭제","비밀번호 확인","비밀번호 재확인","PASSWORD_MAX"});

    fontData[Lan][PAGE_PASSWORD].insert("labelTitleSub",QFont(instance.fontSuit,instance.pixelToPoint(30)));
    textData[Lan][PAGE_PASSWORD].insert("labelTitleSub",QStringList{
                                            "비밀번호 4자리를 눌러주세요",
                                            "변경할 번호 4자리를 눌러주세요",
                                            "비밀번호 4자리를 눌러주세요",
                                            "확인을 위해 4자리를 눌러주세요",
                                            "재확인을 위해 4자리를 눌러주세요",
                                            "PASSWORD_MAX"
                                        });

    fontData[Lan][PAGE_PASSWORD].insert("labelButtonOKText",QFont(instance.fontSuit,instance.pixelToPoint(29)));
    textData[Lan][PAGE_PASSWORD].insert("labelButtonOKText",QStringList{"확인"});

    fontData[Lan][PAGE_PASSWORD].insert("labelButtonCancelText",QFont(instance.fontSuit,instance.pixelToPoint(29)));
    textData[Lan][PAGE_PASSWORD].insert("labelButtonCancelText",QStringList{"취소"});

    //PAGE_PASSWORD_CONFIRM
    fontData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTitle",QFont(instance.fontSuit,instance.pixelToPoint(40),QFont::Bold));
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
                                                    "PASSWORD_STR_MAX" //PASSWORD_STR_MAX
                                                });
    fontData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
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
                                                    "비밀번호 변경이 완료되었습니다\n다시 로그인해주시기 바랍니다", //PASSWORD_STR_EDIT_SUCCESS,
                                                    "사용자 정보를 삭제하시겠습니까?", //PASSWORD_STR_DELETE,
                                                    "사용자 정보를 삭제할 경우\n 비밀번호와 설정이 초기화 됩니다", //PASSWORD_STR_DELETE_CONFIRM,
                                                    "사용자 정보가 삭제되었습니다\n설정 초기화를 위해 재부팅이 진행됩니다", //PASSWORD_STR_DELETE_SUCCESS,
                                                    "로그아웃을 진행합니까?\n로그아웃시 다시 로그인해주시기 바랍니다", //PASSWORD_STR_LOGOUT,
                                                    "PASSWORD_STR_MAX" //PASSWORD_STR_MAX
                                                });

    //PAGE_HOME
    fontData[Lan][PAGE_HOME].insert("labelTextStatus",QFont(instance.fontSuit,instance.pixelToPoint(33),QFont::Bold));
    textData[Lan][PAGE_HOME].insert("labelTextStatus",QStringList{"기상","조식 전","조식 후","중식 전","중식 후","석식 전","석식 후","취침"});

    fontData[Lan][PAGE_HOME].insert("labelButtonText",QFont(instance.fontSuit,instance.pixelToPoint(62),QFont::ExtraBold));

    //PAGE_SELECT
    fontData[Lan][PAGE_SELECT].insert("labelTextStatus",QFont(instance.fontSuit,instance.pixelToPoint(42),QFont::ExtraBold));
    fontData[Lan][PAGE_SELECT].insert("labelTextStatusSub",QFont(instance.fontSuit,instance.pixelToPoint(24)));
    textData[Lan][PAGE_SELECT].insert("labelTextStatusSub",QStringList{"측정을 시작해 주세요"});

    fontData[Lan][PAGE_SELECT].insert("labelTextStatusValue",QFont(instance.fontSuit,instance.pixelToPoint(40),QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextGlucoseValue",QFont(instance.fontSuit,instance.pixelToPoint(130),QFont::ExtraBold));
    fontData[Lan][PAGE_SELECT].insert("labelTextMgdl",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::ExtraBold));
    fontData[Lan][PAGE_SELECT].insert("labelTextResult",QFont(instance.fontSuit,instance.pixelToPoint(36)));
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

    fontData[Lan][PAGE_SELECT].insert("labelTextTime",QFont(instance.fontSuit,instance.pixelToPoint(21)));
    textData[Lan][PAGE_SELECT].insert("labelTextTime",QStringList{"측정 시각"});

    fontData[Lan][PAGE_SELECT].insert("labelTextIcon",QFont(instance.fontSuit,instance.pixelToPoint(23),QFont::Bold));
    textData[Lan][PAGE_SELECT].insert("labelTextIcon",QStringList{"정상","저혈당","고혈당","저혈당","고혈당"});
    //PAGE_MENU
    fontData[Lan][PAGE_MENU].insert("labelButtonText",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));
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
    fontData[Lan][PAGE_CALI_CHECK].insert("labelTextCheck",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_CALI_CHECK].insert("labelTextCheck",QStringList{
                                              "혈당 보정 단계입니다\n손가락을 삽입구에 넣어주세요",
                                              "혈당 보정 완료입니다\n재진행하시겠습니까?"
                                          });

    //PAGE_CALI_GAIN_CONFIRM
    fontData[Lan][PAGE_CALI_GAIN_CONFIRM].insert("labelTextGainConfirm",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_CALI_GAIN_CONFIRM].insert("labelTextGainConfirm",QStringList{
                                                     "LED 감도 조절 단계입니다\n손가락을 움직이지 말아주세요",
                                                     "LED 감도 조절이 끝났습니다\n다음 측정 단계로 넘어가세요"
                                                 });


    //Page_GRAPH
    fontData[Lan][PAGE_GRAPH].insert("labelProgressText",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_GRAPH].insert("labelProgressText",QStringList{"Completed"});
    fontData[Lan][PAGE_GRAPH].insert("labelProgressValue",QFont(instance.fontSuit,instance.pixelToPoint(60),QFont::Bold));
    fontData[Lan][PAGE_GRAPH].insert("labelProgressPercent",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_GRAPH].insert("labelAdcText",QFont(instance.fontSuit,instance.pixelToPoint(20)));
    textData[Lan][PAGE_GRAPH].insert("labelAdcText",QStringList{"A:"});
    fontData[Lan][PAGE_GRAPH].insert("labelLoading",QFont(instance.fontSuit,instance.pixelToPoint(48),QFont::Bold));
    textData[Lan][PAGE_GRAPH].insert("labelLoading",QStringList{"측정 분석 중입니다"});

    //PAGE_CALI_GAIN_RESULT
    fontData[Lan][PAGE_CALI_GAIN_RESULT].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_CALI_GAIN_RESULT].insert("labelText",QStringList{
                                                    "LED 감도 조절이 끝났습니다\n다음 측정 단계로 넘어가세요",
                                                    "LED 감도 조절에 실패했습니다\n다시 측정해주세요"
                                                });
    //PAGE_CALI_SELECT
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectText",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT].insert("labelSelectText",QStringList{
                                               "공복",
                                               "식후"
                                           });

    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextAdc",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextValue",QFont(instance.fontSuit,instance.pixelToPoint(36)));

    //PAGE_CALI_SELECT_INFO
    fontData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText",QStringList{
                                                    "공복 8시간 이상\n경과되었습니까?",
                                                    "식후 1시간 이상\n경과되었습니까?",
                                                    "식후 1시간 30분 이상\n경과되었습니까?",
                                                    "식후 2시간 이상\n경과되었습니까?"
                                                });

    //PAGE_CALI_CONFIRM
    fontData[Lan][PAGE_CALI_CONFIRM].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_CALI_CONFIRM].insert("labelText",QStringList{"혈당값 입력 또는 측정을\n하시겠습니까?"});

    //PAGE_CALI_RESULT
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextAdc",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextTemp",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextHeart",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));

    //PAGE_CALI_RESULT_MULTI
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextAdc",QFont(instance.fontSuit,instance.pixelToPoint(34),QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextTemp",QFont(instance.fontSuit,instance.pixelToPoint(34)));
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextHeart",QFont(instance.fontSuit,instance.pixelToPoint(34)));

    //PAGE_RESULT
    fontData[Lan][PAGE_RESULT].insert("labelTextGlucoseValue",QFont(instance.fontSuit,instance.pixelToPoint(103),QFont::ExtraBold));

    fontData[Lan][PAGE_RESULT].insert("labelTextMgdl",QFont(instance.fontSuit,instance.pixelToPoint(27)));
    textData[Lan][PAGE_RESULT].insert("labelTextMgdl",QStringList{"mg/dL"});

    fontData[Lan][PAGE_RESULT].insert("labelTextTime",QFont(instance.fontSuit,instance.pixelToPoint(21),QFont::Bold));
    textData[Lan][PAGE_RESULT].insert("labelTextTime",QStringList{"측정 시각"});

    fontData[Lan][PAGE_RESULT].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(36)));

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

    fontData[Lan][PAGE_RESULT].insert("labelProgressBarTooltip",QFont(instance.fontSuit,instance.pixelToPoint(16),QFont::Bold));
    textData[Lan][PAGE_RESULT].insert("labelProgressBarTooltip",QStringList{
                                          "정상",
                                          "주의",
                                          "경고",
                                          "에러"
                                      });

    //PAGE_INIT
    fontData[Lan][PAGE_INIT].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(36)));
    textData[Lan][PAGE_INIT].insert("labelText",QStringList{
                                        "전체 초기화",
                                        "블루투스 초기화",
                                        "혈당보정 초기화"
                                    });

    //PAGE_INIT_CONFIRM
    fontData[Lan][PAGE_INIT_CONFIRM].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_INIT_CONFIRM].insert("labelText",QStringList{
                                                "전체 시스템 정보가 초기화됩니다\n초기화를 진행하시겠습니까?",
                                                "시스템 초기화 진행 후\n시스템이 재시작합니다",
                                                "블루투스\n\n유저 정보가 초기화됩니다\n스마트 폰과의 연결이 해제됩니다\n초기화를 진행하시겠습니까?",
                                                "블루투스\n\n유저 정보가 초기화되었습니다",
                                                "혈당 보정이 초기화됩니다\n혈당 보정을 초기화하시겠습니까?",
                                                "혈당 보정이 초기화되었습니다"
                                            });

    //PAGE_TRHESHOLD
    fontData[Lan][PAGE_THRESHOLD].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(36)));
    textData[Lan][PAGE_THRESHOLD].insert("labelText",QStringList{
                                             "저혈당",
                                             "고혈당"
                                         });
    fontData[Lan][PAGE_THRESHOLD].insert("labelButton",QFont(instance.fontSuit,instance.pixelToPoint(22)));
    textData[Lan][PAGE_THRESHOLD].insert("labelButton",QStringList{"설정"});

    fontData[Lan][PAGE_THRESHOLD].insert("labelValue",QFont(instance.fontSuit,instance.pixelToPoint(48),QFont::Bold));

    //PAGE_SOUND
    fontData[Lan][PAGE_SOUND].insert("labelVolume",QFont(instance.fontSuit,instance.pixelToPoint(110),QFont::Bold));

    //PAGE_SLEEP
    fontData[Lan][PAGE_SLEEP].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(42),QFont::Bold));
    textData[Lan][PAGE_SLEEP].insert("labelText",QStringList{
                                         "30초",
                                         "1분",
                                         "3분",
                                         "5분",
                                         "10분",
                                         "없음"
                                     });
    //PAGE_UPGRADE
    fontData[Lan][PAGE_UPGRADE].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(42),QFont::Bold));
    textData[Lan][PAGE_UPGRADE].insert("labelText",QStringList{"현재 버전"});

    fontData[Lan][PAGE_UPGRADE].insert("labelTextVersion",QFont(instance.fontSuit,instance.pixelToPoint(55)));

    //PAGE_UPGRADE_CONFIRM
    fontData[Lan][PAGE_UPGRADE_CONFIRM].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(42),QFont::Bold));
    textData[Lan][PAGE_UPGRADE_CONFIRM].insert("labelText",QStringList{
                                                   "1. 장치와 PC연결\n"
                                                   "2. 장치에 bin 파일 복사\n"
                                                   "3. 복사 완료 후 장치 재부팅"
                                               });
    //PAGE_DEVICEINFO
    fontData[Lan][PAGE_DEVICEINFO].insert("labelTitle",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_DEVICEINFO].insert("labelTitle",QStringList{
                                              "BLE",
                                              "H/W ver",
                                              "S/W ver",
                                              "Serial"
                                          });

    fontData[Lan][PAGE_DEVICEINFO].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(30)));

    //PAGE_USERINFO
    fontData[Lan][PAGE_USERINFO].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(36)));
    textData[Lan][PAGE_USERINFO].insert("labelText",QStringList{
                                            "비밀번호 수정",
                                            "사용자 정보 삭제",
                                            "로그아웃"
                                        });

    //PAGE_BATPOPUP
    fontData[Lan][PAGE_BATPOPUP].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(42),QFont::Bold));
    textData[Lan][PAGE_BATPOPUP].insert("labelText",QStringList{
                                            "배터리 부족",
                                            "배터리 매우 부족"
                                        });
    fontData[Lan][PAGE_BATPOPUP].insert("labelTextSub",QFont(instance.fontSuit,instance.pixelToPoint(36)));
    textData[Lan][PAGE_BATPOPUP].insert("labelTextSub",QStringList{
                                            "충전기를 연결하세요",
                                            "시스템을 종료합니다"
                                        });

    //PAGE_REVERSE
    fontData[Lan][PAGE_REVERSE].insert("labelTextButton",QFont(instance.fontSuit,instance.pixelToPoint(36)));
    textData[Lan][PAGE_REVERSE].insert("labelTextButton",QStringList{
                                           "왼손",
                                           "오른손"
                                       });
    fontData[Lan][PAGE_REVERSE].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(36)));
    textData[Lan][PAGE_REVERSE].insert("labelText",QStringList{
                                           "화면전환 설정 후 재부팅 됩니다"
                                       });

    //====================================================================================================================================
    //EN
    Lan = EN;

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
    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonOK",QFont(instance.fontSuit,instance.pixelToPoint(35),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonOK",QStringList{"OK"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel",QFont(instance.fontSuit,instance.pixelToPoint(35),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel",QStringList{"Cancel"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonHome",QFont(instance.fontSuit,instance.pixelToPoint(35),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonHome",QStringList{"Home"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart",QFont(instance.fontSuit,instance.pixelToPoint(35),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart",QStringList{"Start"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasure",QFont(instance.fontSuit,instance.pixelToPoint(35),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasure",QStringList{"Measure"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonInput",QFont(instance.fontSuit,instance.pixelToPoint(35),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonInput",QStringList{"Input"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe",QStringList{"Remeasure"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonSave",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonSave",QStringList{"Save"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonUpgrade",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonUpgrade",QStringList{"Software Upgrade"});

    //CUSTOM_COMPONENT
    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextValue",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextResult",QFont(instance.fontSuit,instance.pixelToPoint(36)));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextResult",QStringList{
                                               "Successful",     // 0
                                               "Timeout", // 1
                                               "NULL_PTR",                // 2
                                               "COUNT_ZERO",              // 3
                                               "MALLOC_FAIL",             // 4
                                               "NONE_GREADE",             // 5
                                               "PARAM_FAIL",              // 6
                                               "RESULT_FAIL",             // 7
                                               "ECODE_MAX"
                                           });

    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(50)));
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelTextSelect",QFont(instance.fontSuit,instance.pixelToPoint(50),QFont::Bold));
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelTextSub",QFont(instance.fontSuit,instance.pixelToPoint(40)));

    //PAGE_PASSWORD
    fontData[Lan][PAGE_PASSWORD].insert("labelButtonNum",QFont(instance.fontSuit,instance.pixelToPoint(44),QFont::Bold));

    fontData[Lan][PAGE_PASSWORD].insert("labelTitle",QFont(instance.fontSuit,instance.pixelToPoint(40),QFont::Bold));
    textData[Lan][PAGE_PASSWORD].insert("labelTitle",QStringList{"Please log in","Edit Password","Delete User","Password Confirmation","Password Re-confirmation","PASSWORD_MAX"});

    fontData[Lan][PAGE_PASSWORD].insert("labelTitleSub",QFont(instance.fontSuit,instance.pixelToPoint(30)));
    textData[Lan][PAGE_PASSWORD].insert("labelTitleSub", QStringList{
                                            "Please enter your 4-digit password",
                                            "Please enter the 4 digits to modify",
                                            "Please enter your 4-digit password again",
                                            "Please confirm by entering 4 digits",
                                            "Please re-enter the 4 digits to verify",
                                            "PASSWORD_MAX"
                                        });

    fontData[Lan][PAGE_PASSWORD].insert("labelButtonOKText",QFont(instance.fontSuit,instance.pixelToPoint(29)));
    textData[Lan][PAGE_PASSWORD].insert("labelButtonOKText",QStringList{"OK"});

    fontData[Lan][PAGE_PASSWORD].insert("labelButtonCancelText",QFont(instance.fontSuit,instance.pixelToPoint(29)));
    textData[Lan][PAGE_PASSWORD].insert("labelButtonCancelText",QStringList{"X"});

    //PAGE_PASSWORD_CONFIRM
    fontData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTitle",QFont(instance.fontSuit,instance.pixelToPoint(40),QFont::Bold));
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
                                                    "PASSWORD_STR_MAX" //PASSWORD_STR_MAX
                                                });
    fontData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
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
    fontData[Lan][PAGE_HOME].insert("labelTextStatus",QFont(instance.fontSuit,instance.pixelToPoint(26),QFont::Bold));
    textData[Lan][PAGE_HOME].insert("labelTextStatus",QStringList{
                                        "Wake\nUp","Before\nBreakfast","After\nBreakfast","Before\nLunch","After\nLunch","Before\nDinner","After\nDinner","Bed\nTime"});

    fontData[Lan][PAGE_HOME].insert("labelButtonText",QFont(instance.fontSuit,instance.pixelToPoint(62),QFont::ExtraBold));

    //PAGE_SELECT
    fontData[Lan][PAGE_SELECT].insert("labelTextStatus", QFont(instance.fontSuit, instance.pixelToPoint(42), QFont::ExtraBold));
    fontData[Lan][PAGE_SELECT].insert("labelTextStatusSub", QFont(instance.fontSuit, instance.pixelToPoint(24)));
    textData[Lan][PAGE_SELECT].insert("labelTextStatusSub", QStringList{"Please start the measurement"});

    fontData[Lan][PAGE_SELECT].insert("labelTextStatusValue",QFont(instance.fontSuit,instance.pixelToPoint(40),QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextGlucoseValue",QFont(instance.fontSuit,instance.pixelToPoint(130),QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextMgdl",QFont(instance.fontSuit,instance.pixelToPoint(34),QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextResult",QFont(instance.fontSuit,instance.pixelToPoint(32)));
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

    fontData[Lan][PAGE_SELECT].insert("labelTextTime",QFont(instance.fontSuit,instance.pixelToPoint(21),QFont::Bold));
    textData[Lan][PAGE_SELECT].insert("labelTextTime",QStringList{"Time"});

    fontData[Lan][PAGE_SELECT].insert("labelTextIcon",QFont(instance.fontSuit,instance.pixelToPoint(23),QFont::Bold));
    textData[Lan][PAGE_SELECT].insert("labelTextIcon",QStringList{"Normal","Low","High","Low","High"});

    //PAGE_MENU
    fontData[Lan][PAGE_MENU].insert("labelButtonText",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][PAGE_MENU].insert("labelButtonText", QStringList{
                                        "Calib\nration",
                                        "Range",
                                        "List",
                                        "Sound",
                                        "Sleep",
                                        "Switch",
                                        "Date",
                                        "Color\nMode",
                                        "Lan\nguage",
                                        "Upgrade",
                                        "Device\nInfo",
                                        "Reset",
                                        "User"
                                    });

    //PAGE_CALI_CHECK
    fontData[Lan][PAGE_CALI_CHECK].insert("labelTextCheck",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][PAGE_CALI_CHECK].insert("labelTextCheck",QStringList{
                                              "Calibration phase\nPlease insert your finger",
                                              "Calibration complete\nDo you want to proceed again?"
                                          });
    //Page_CALI_GAIN_CONFIRM
    fontData[Lan][PAGE_CALI_GAIN_CONFIRM].insert("labelTextGainConfirm",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][PAGE_CALI_GAIN_CONFIRM].insert("labelTextGainConfirm",QStringList{
                                                     "LED sensitivity adjustment step\nPlease do not move your finger",
                                                     "LED sensitivity adjustment\nhas been completed"
                                                 });

    //Page_GRAPH
    fontData[Lan][PAGE_GRAPH].insert("labelProgressText",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_GRAPH].insert("labelProgressText",QStringList{"Completed"});
    fontData[Lan][PAGE_GRAPH].insert("labelProgressValue",QFont(instance.fontSuit,instance.pixelToPoint(60),QFont::Bold));
    fontData[Lan][PAGE_GRAPH].insert("labelProgressPercent",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_GRAPH].insert("labelAdcText",QFont(instance.fontSuit,instance.pixelToPoint(20)));
    textData[Lan][PAGE_GRAPH].insert("labelAdcText",QStringList{"A:"});
    fontData[Lan][PAGE_GRAPH].insert("labelLoading",QFont(instance.fontSuit,instance.pixelToPoint(48),QFont::Bold));
    textData[Lan][PAGE_GRAPH].insert("labelLoading",QStringList{"Analyzing"});

    //Page_CALI_GAIN_RESULT
    fontData[Lan][PAGE_CALI_GAIN_RESULT].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_CALI_GAIN_RESULT].insert("labelText",QStringList{
                                                    "LED sensitivity adjustment is complete\nProceed to the next measurement step",
                                                    "LED sensitivity adjustment failed.\nPlease measure again"
                                                });
    //PAGE_CALI_SELECT
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectText",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT].insert("labelSelectText",QStringList{
                                               "Empty\nstomach",
                                               "After meal"
                                           });

    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextAdc",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextValue",QFont(instance.fontSuit,instance.pixelToPoint(36)));


    //PAGE_CALI_SELECT_INFO
    fontData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText",QStringList{
                                                    "Has it been more than 8 hours\n since your last meal?",
                                                    "Has it been more than 1 hour\n since your last meal?",
                                                    "Has it been more than 1 hour\n and 30 minutes since \nyour last meal?",
                                                    "Has it been more than 2 hours\n  since your last meal?"
                                                });

    //PAGE_CALI_CONFIRM
    fontData[Lan][PAGE_CALI_CONFIRM].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_CALI_CONFIRM].insert("labelText",QStringList{"Select input or measure"});

    //PAGE_CALI_RESULT
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextAdc",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextTemp",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextHeart",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));

    //PAGE_CALI_RESULT_MULTI
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextAdc",QFont(instance.fontSuit,instance.pixelToPoint(34),QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextTemp",QFont(instance.fontSuit,instance.pixelToPoint(34)));
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextHeart",QFont(instance.fontSuit,instance.pixelToPoint(34)));

    //PAGE_RESULT
     fontData[Lan][PAGE_RESULT].insert("labelTextGlucoseValue",QFont(instance.fontSuit,instance.pixelToPoint(103),QFont::ExtraBold));

    fontData[Lan][PAGE_RESULT].insert("labelTextMgdl",QFont(instance.fontSuit,instance.pixelToPoint(27)));
    textData[Lan][PAGE_RESULT].insert("labelTextMgdl",QStringList{"mg/dL"});

    fontData[Lan][PAGE_RESULT].insert("labelTextTime",QFont(instance.fontSuit,instance.pixelToPoint(21),QFont::Bold));
    textData[Lan][PAGE_RESULT].insert("labelTextTime",QStringList{"Time"});

    fontData[Lan][PAGE_RESULT].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(36)));

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
    fontData[Lan][PAGE_RESULT].insert("labelProgressBarTooltip",QFont(instance.fontSuit,instance.pixelToPoint(16),QFont::Bold));
    textData[Lan][PAGE_RESULT].insert("labelProgressBarTooltip",QStringList{
                                          "Normal",
                                          "Caution",
                                          "Warning",
                                          "Error"
                                      });
    //PAGE_INIT
    fontData[Lan][PAGE_INIT].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(36)));
    textData[Lan][PAGE_INIT].insert("labelText",QStringList{
                                        "Factory reset",
                                        "Bluetooth reset",
                                        "Blood sugar calibration reset"
                                    });

    //PAGE_INIT_CONFIRM
    fontData[Lan][PAGE_INIT_CONFIRM].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_INIT_CONFIRM].insert("labelText",QStringList{
                                                "The entire system\ninformation will be reset.\nDo you want to proceed\nwith factory reset?",
                                                "After system initialization,\nthe system will restart",
                                                "Bluetooth user information\nwill be initialized.\nThe connection with the\nsmartphone is disconnected.\nWould you like to reset\nBluetooth?",
                                                "Bluetooth user information\nhas been reset",
                                                "Blood sugar correction\nwill be reset\nDo you want to reset\nblood sugar correction?",
                                                "Blood sugar correction\nhas been reset"
                                            });

    //PAGE_TRHESHOLD
    fontData[Lan][PAGE_THRESHOLD].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(36)));
    textData[Lan][PAGE_THRESHOLD].insert("labelText",QStringList{
                                             "Low Blood Sugar",
                                             "High Blood Suger"
                                         });
    fontData[Lan][PAGE_THRESHOLD].insert("labelButton",QFont(instance.fontSuit,instance.pixelToPoint(22)));
    textData[Lan][PAGE_THRESHOLD].insert("labelButton",QStringList{"Set"});

    fontData[Lan][PAGE_THRESHOLD].insert("labelValue",QFont(instance.fontSuit,instance.pixelToPoint(48),QFont::Bold));

    //PAGE_SOUND
    fontData[Lan][PAGE_SOUND].insert("labelVolume",QFont(instance.fontSuit,instance.pixelToPoint(110),QFont::Bold));

    //PAGE_SLEEP
    fontData[Lan][PAGE_SLEEP].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(42),QFont::Bold));
    textData[Lan][PAGE_SLEEP].insert("labelText",QStringList{
                                         "30sec",
                                         "1min",
                                         "3min",
                                         "5min",
                                         "10min",
                                         "None"
                                     });

    //PAGE_UPGRADE
    fontData[Lan][PAGE_UPGRADE].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(42),QFont::Bold));
    textData[Lan][PAGE_UPGRADE].insert("labelText",QStringList{"Version"});

    fontData[Lan][PAGE_UPGRADE].insert("labelTextVersion",QFont(instance.fontSuit,instance.pixelToPoint(55)));

    //PAGE_UPGRADE_CONFIRM
    fontData[Lan][PAGE_UPGRADE_CONFIRM].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(42),QFont::Bold));
    textData[Lan][PAGE_UPGRADE_CONFIRM].insert("labelText",QStringList{
                                                   "1. Connect the device to PC\n"
                                                   "2. Copy bin file to the device\n"
                                                   "3. Restart the device after\ncopying is complete"
                                               });

    //PAGE_DEVICEINFO
    fontData[Lan][PAGE_DEVICEINFO].insert("labelTitle",QFont(instance.fontSuit,instance.pixelToPoint(36),QFont::Bold));
    textData[Lan][PAGE_DEVICEINFO].insert("labelTitle",QStringList{
                                              "BLE",
                                              "H/W ver",
                                              "S/W ver",
                                              "Serial"
                                          });

    fontData[Lan][PAGE_DEVICEINFO].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(30)));

    //PAGE_USERINFO
    fontData[Lan][PAGE_USERINFO].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(36)));
    textData[Lan][PAGE_USERINFO].insert("labelText",QStringList{
                                            "Change password",
                                            "Delete user data",
                                            "Log out"
                                        });

    //PAGE_BATPOPUP
    fontData[Lan][PAGE_BATPOPUP].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(42),QFont::Bold));
    textData[Lan][PAGE_BATPOPUP].insert("labelText",QStringList{
                                            "Low Battery",
                                            "Please connect it to the charger"
                                        });
    fontData[Lan][PAGE_BATPOPUP].insert("labelTextSub",QFont(instance.fontSuit,instance.pixelToPoint(36)));
    textData[Lan][PAGE_BATPOPUP].insert("labelTextSub",QStringList{
                                            "Battery very low",
                                            "The system is shutting down"
                                        });

    //PAGE_REVERSE
    fontData[Lan][PAGE_REVERSE].insert("labelTextButton",QFont(instance.fontSuit,instance.pixelToPoint(36)));
    textData[Lan][PAGE_REVERSE].insert("labelTextButton",QStringList{
                                           "Left",
                                           "Right"
                                       });
    fontData[Lan][PAGE_REVERSE].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(36)));
    textData[Lan][PAGE_REVERSE].insert("labelText",QStringList{
                                           "Reset will be proceeded"
                                       });


    //=====================================================================================================================================
    //JP
    Lan = EN;

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
    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonOK", QFont(instance.fontSuit, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonOK", QStringList{"確認"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel", QFont(instance.fontSuit, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel", QStringList{"キャンセル"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonHome", QFont(instance.fontSuit, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonHome", QStringList{"ホーム"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart", QFont(instance.fontSuit, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart", QStringList{"開始"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasure", QFont(instance.fontSuit, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasure", QStringList{"測定"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonInput", QFont(instance.fontSuit, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonInput", QStringList{"入力"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe", QFont(instance.fontSuit, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe", QStringList{"再測定"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonSave", QFont(instance.fontSuit, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonSave", QStringList{"保存"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonUpgrade", QFont(instance.fontSuit, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonUpgrade", QStringList{"ソフトウェア更新"});

    //CUSTOM_COMPONENT
    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextValue", QFont(instance.fontSuit, instance.pixelToPoint(30), QFont::Bold));

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextResult", QFont(instance.fontSuit, instance.pixelToPoint(36)));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextResult", QStringList{
        "成功しました",       // 0: Successful
        "タイムアウト",       // 1: Timeout
        "NULL_PTR",         // 2
        "COUNT_ZERO",       // 3
        "MALLOC_FAIL",      // 4
        "NONE_GRADE",       // 5
        "PARAM_FAIL",       // 6
        "RESULT_FAIL",      // 7
        "ECODE_MAX"         // 8
    });

    //CUSTOM_COMPONENT_DATE
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(50)));
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelTextSelect", QFont(instance.fontSuit, instance.pixelToPoint(50), QFont::Bold));
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelTextSub", QFont(instance.fontSuit, instance.pixelToPoint(40)));

    //PAGE_PASSWORD
    fontData[Lan][PAGE_PASSWORD].insert("labelButtonNum", QFont(instance.fontSuit, instance.pixelToPoint(44), QFont::Bold));

    fontData[Lan][PAGE_PASSWORD].insert("labelTitle", QFont(instance.fontSuit, instance.pixelToPoint(40), QFont::Bold));
    textData[Lan][PAGE_PASSWORD].insert("labelTitle", QStringList{
        "ログインしてください",         // Please log in
        "パスワードを変更する",         // Edit Password
        "ユーザーを削除する",          // Delete User
        "パスワード確認",             // Password Confirmation
        "再確認",                   // Password Re-confirmation
        "PASSWORD_MAX"
    });

    fontData[Lan][PAGE_PASSWORD].insert("labelTitleSub", QFont(instance.fontSuit, instance.pixelToPoint(30)));
    textData[Lan][PAGE_PASSWORD].insert("labelTitleSub", QStringList{
        "4桁のパスワードを入力してください",             // Please enter your 4-digit password
        "変更する4桁の番号を入力してください",          // Please enter the 4 digits to modify
        "もう一度4桁のパスワードを入力してください",    // Please enter your 4-digit password again
        "確認のため4桁を入力してください",             // Please confirm by entering 4 digits
        "確認のためもう一度4桁を入力してください",      // Please re-enter the 4 digits to verify
        "PASSWORD_MAX"
    });

    fontData[Lan][PAGE_PASSWORD].insert("labelButtonOKText", QFont(instance.fontSuit, instance.pixelToPoint(29)));
    textData[Lan][PAGE_PASSWORD].insert("labelButtonOKText", QStringList{"確認"}); // OK

    fontData[Lan][PAGE_PASSWORD].insert("labelButtonCancelText", QFont(instance.fontSuit, instance.pixelToPoint(29)));
    textData[Lan][PAGE_PASSWORD].insert("labelButtonCancelText", QStringList{"キャンセル"}); // Cancel

    //PAGE_PASSWORD_CONFIRM
    fontData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTitle", QFont(instance.fontSuit, instance.pixelToPoint(40), QFont::Bold));
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
        "PASSWORD_STR_MAX" // PASSWORD_STR_MAX
    });

    fontData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelText", QStringList{
        "ログイン成功",                              // PASSWORD_STR_LOGIN_SUCCESS
        "ログイン失敗",                              // PASSWORD_STR_LOGIN_FAIL
        "パスワードを変更してください",                // PASSWORD_STR_LOGIN_CHANGE
        "本人確認のために\nパスワードを入力してください", // PASSWORD_STR_CONFIRM
        "パスワードが一致しません",                   // PASSWORD_STR_CONFIRM_FAIL
        "正確な確認のために\nもう一度パスワードを入力してください", // PASSWORD_STR_REPEAT
        "入力されたパスワードが\n以前のパスワードと一致しません",   // PASSWORD_STR_REPEAT_FAIL
        "パスワードを変更しますか？",                // PASSWORD_STR_EDIT
        "本人確認のために\nパスワードを入力してください", // PASSWORD_STR_EDIT_CONFIRM
        "新しいパスワードを入力してください",          // PASSWORD_STR_EDIT_CHANGE
        "パスワード変更が完了しました\n再度ログインしてください",   // PASSWORD_STR_EDIT_SUCCESS
        "ユーザー情報を削除しますか？",              // PASSWORD_STR_DELETE
        "ユーザー情報を削除すると\nパスワードと設定がリセットされます", // PASSWORD_STR_DELETE_CONFIRM
        "ユーザー情報が削除されました\n設定をリセットするため再起動します", // PASSWORD_STR_DELETE_SUCCESS
        "ログアウトしますか？\n再度ログインしてください",             // PASSWORD_STR_LOGOUT
        "PASSWORD_STR_MAX"                             // PASSWORD_STR_MAX
    });

    //PAGE_HOME
    fontData[Lan][PAGE_HOME].insert("labelTextStatus", QFont(instance.fontSuit, instance.pixelToPoint(26), QFont::Bold));
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

    fontData[Lan][PAGE_HOME].insert("labelButtonText", QFont(instance.fontSuit, instance.pixelToPoint(62), QFont::ExtraBold));

    //PAGE_SELECT
    fontData[Lan][PAGE_SELECT].insert("labelTextStatus", QFont(instance.fontSuit, instance.pixelToPoint(42), QFont::ExtraBold));
    fontData[Lan][PAGE_SELECT].insert("labelTextStatusSub", QFont(instance.fontSuit, instance.pixelToPoint(24)));
    textData[Lan][PAGE_SELECT].insert("labelTextStatusSub", QStringList{"測定を開始してください"}); // Please start the measurement

    fontData[Lan][PAGE_SELECT].insert("labelTextStatusValue", QFont(instance.fontSuit, instance.pixelToPoint(40), QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextGlucoseValue", QFont(instance.fontSuit, instance.pixelToPoint(130), QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextMgdl", QFont(instance.fontSuit, instance.pixelToPoint(34), QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextResult", QFont(instance.fontSuit, instance.pixelToPoint(32)));
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

    fontData[Lan][PAGE_SELECT].insert("labelTextTime", QFont(instance.fontSuit, instance.pixelToPoint(21), QFont::Bold));
    textData[Lan][PAGE_SELECT].insert("labelTextTime", QStringList{"時間"}); // Time

    fontData[Lan][PAGE_SELECT].insert("labelTextIcon", QFont(instance.fontSuit, instance.pixelToPoint(23), QFont::Bold));
    textData[Lan][PAGE_SELECT].insert("labelTextIcon", QStringList{
        "正常",       // Normal
        "低",         // Low
        "高",         // High
        "低",         // Low
        "高"          // High
    });

    //PAGE_MENU
    fontData[Lan][PAGE_MENU].insert("labelButtonText", QFont(instance.fontSuit, instance.pixelToPoint(30), QFont::Bold));
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
        "アップグレード", // Upgrade
        "デバイス情報",  // Device Info
        "リセット",      // Reset
        "ユーザー"       // User
    });

    //PAGE_CALI_CHECK
    fontData[Lan][PAGE_CALI_CHECK].insert("labelTextCheck", QFont(instance.fontSuit, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][PAGE_CALI_CHECK].insert("labelTextCheck", QStringList{
        "補正フェーズです\n指を挿入してください",          // Calibration phase, Please insert your finger
        "補正完了です\n再実行しますか？"                // Calibration complete, Do you want to proceed again?
    });

    //PAGE_CALI_GAIN_CONFIRM
    fontData[Lan][PAGE_CALI_GAIN_CONFIRM].insert("labelTextGainConfirm", QFont(instance.fontSuit, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][PAGE_CALI_GAIN_CONFIRM].insert("labelTextGainConfirm", QStringList{
        "LED感度調整段階です\n指を動かさないでください",    // LED sensitivity adjustment step, Please do not move your finger
        "LED感度調整が完了しました"                      // LED sensitivity adjustment has been completed
    });

    //PAGE_GRAPH
    fontData[Lan][PAGE_GRAPH].insert("labelProgressText", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][PAGE_GRAPH].insert("labelProgressText", QStringList{"完了"}); // Completed

    fontData[Lan][PAGE_GRAPH].insert("labelProgressValue", QFont(instance.fontSuit, instance.pixelToPoint(60), QFont::Bold));
    fontData[Lan][PAGE_GRAPH].insert("labelProgressPercent", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));

    fontData[Lan][PAGE_GRAPH].insert("labelAdcText", QFont(instance.fontSuit, instance.pixelToPoint(20)));
    textData[Lan][PAGE_GRAPH].insert("labelAdcText", QStringList{"A:"});

    fontData[Lan][PAGE_GRAPH].insert("labelLoading", QFont(instance.fontSuit, instance.pixelToPoint(48), QFont::Bold));
    textData[Lan][PAGE_GRAPH].insert("labelLoading", QStringList{"解析中"}); // Analyzing

    //Page_CALI_GAIN_RESULT
    fontData[Lan][PAGE_CALI_GAIN_RESULT].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][PAGE_CALI_GAIN_RESULT].insert("labelText", QStringList{
        "LED感度調整が完了しました\n次の測定ステップに進んでください", // LED sensitivity adjustment is complete, Proceed to the next measurement step
        "LED感度調整に失敗しました\n再度測定してください"          // LED sensitivity adjustment failed, Please measure again
    });

    //PAGE_CALI_SELECT
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectText", QFont(instance.fontSuit, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT].insert("labelSelectText", QStringList{
        "空腹",       // Empty stomach
        "食後"        // After meal
    });

    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextAdc", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextValue", QFont(instance.fontSuit, instance.pixelToPoint(36)));

    //PAGE_CALI_SELECT_INFO
    fontData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText", QStringList{
        "最後の食事から8時間以上経過しましたか？",            // Has it been more than 8 hours since your last meal?
        "最後の食事から1時間以上経過しましたか？",            // Has it been more than 1 hour since your last meal?
        "最後の食事から1時間30分以上経過しましたか？",        // Has it been more than 1 hour and 30 minutes since your last meal?
        "最後の食事から2時間以上経過しましたか？"            // Has it been more than 2 hours since your last meal?
    });

    //PAGE_CALI_CONFIRM
    fontData[Lan][PAGE_CALI_CONFIRM].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][PAGE_CALI_CONFIRM].insert("labelText", QStringList{"入力または測定を選択してください"}); // Select input or measure

    //PAGE_CALI_RESULT
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextAdc", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextTemp", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextHeart", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));

    //PAGE_CALI_RESULT_MULTI
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextAdc", QFont(instance.fontSuit, instance.pixelToPoint(34), QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextTemp", QFont(instance.fontSuit, instance.pixelToPoint(34)));
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextHeart", QFont(instance.fontSuit, instance.pixelToPoint(34)));

    //PAGE_RESULT
    fontData[Lan][PAGE_RESULT].insert("labelTextGlucoseValue", QFont(instance.fontSuit, instance.pixelToPoint(103), QFont::ExtraBold));

    fontData[Lan][PAGE_RESULT].insert("labelTextMgdl", QFont(instance.fontSuit, instance.pixelToPoint(27)));
    textData[Lan][PAGE_RESULT].insert("labelTextMgdl", QStringList{"mg/dL"}); // mg/dL

    fontData[Lan][PAGE_RESULT].insert("labelTextTime", QFont(instance.fontSuit, instance.pixelToPoint(21), QFont::Bold));
    textData[Lan][PAGE_RESULT].insert("labelTextTime", QStringList{"時間"}); // Time

    fontData[Lan][PAGE_RESULT].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(36)));

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

    fontData[Lan][PAGE_RESULT].insert("labelProgressBarTooltip", QFont(instance.fontSuit, instance.pixelToPoint(16), QFont::Bold));
    textData[Lan][PAGE_RESULT].insert("labelProgressBarTooltip", QStringList{
        "正常",       // Normal
        "注意",       // Caution
        "警告",       // Warning
        "エラー"      // Error
    });

    //PAGE_INIT
    fontData[Lan][PAGE_INIT].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(36)));
    textData[Lan][PAGE_INIT].insert("labelText", QStringList{
        "工場出荷状態にリセット", // Factory reset
        "Bluetoothをリセット",    // Bluetooth reset
        "血糖補正をリセット"      // Blood sugar calibration reset
    });

    //PAGE_INIT_CONFIRM
    fontData[Lan][PAGE_INIT_CONFIRM].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][PAGE_INIT_CONFIRM].insert("labelText", QStringList{
        "システム全体の情報が\nリセットされます。\n工場出荷状態に\nリセットしますか？", // The entire system information will be reset. Do you want to proceed with factory reset?
        "システムの初期化後、\nシステムが再起動します",          // After system initialization, the system will restart
        "Bluetoothのユーザー情報が初期化されます。\nスマートフォンとの接続が切断されます。\nBluetoothをリセットしますか？", // Bluetooth user information will be initialized. The connection with the smartphone is disconnected. Would you like to reset Bluetooth?
        "Bluetoothのユーザー情報が初期化されました",          // Bluetooth user information has been reset
        "血糖補正がリセットされます\n血糖補正をリセットしますか？", // Blood sugar correction will be reset. Do you want to reset blood sugar correction?
        "血糖補正がリセットされました"                     // Blood sugar correction has been reset
    });

    //PAGE_THRESHOLD
    fontData[Lan][PAGE_THRESHOLD].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(36)));
    textData[Lan][PAGE_THRESHOLD].insert("labelText", QStringList{
        "低血糖",  // Low Blood Sugar
        "高血糖"   // High Blood Sugar
    });

    fontData[Lan][PAGE_THRESHOLD].insert("labelButton", QFont(instance.fontSuit, instance.pixelToPoint(22)));
    textData[Lan][PAGE_THRESHOLD].insert("labelButton", QStringList{"設定"}); // Set

    fontData[Lan][PAGE_THRESHOLD].insert("labelValue", QFont(instance.fontSuit, instance.pixelToPoint(48), QFont::Bold));

    //PAGE_SOUND
    fontData[Lan][PAGE_SOUND].insert("labelVolume", QFont(instance.fontSuit, instance.pixelToPoint(110), QFont::Bold));

    //PAGE_SLEEP
    fontData[Lan][PAGE_SLEEP].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][PAGE_SLEEP].insert("labelText", QStringList{
        "30秒",    // 30sec
        "1分",     // 1min
        "3分",     // 3min
        "5分",     // 5min
        "10分",    // 10min
        "なし"      // None
    });

    //PAGE_UPGRADE
    fontData[Lan][PAGE_UPGRADE].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][PAGE_UPGRADE].insert("labelText", QStringList{"バージョン"}); // Version

    fontData[Lan][PAGE_UPGRADE].insert("labelTextVersion", QFont(instance.fontSuit, instance.pixelToPoint(55)));

    //PAGE_UPGRADE_CONFIRM
    fontData[Lan][PAGE_UPGRADE_CONFIRM].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][PAGE_UPGRADE_CONFIRM].insert("labelText", QStringList{
        "1. デバイスをPCに接続\n"
        "2. binファイルをデバイスにコピー\n"
        "3. コピー完了後、\nデバイスを再起動"
    }); // 1. Connect the device to PC, 2. Copy bin file to the device, 3. Restart the device after copying is complete

    //PAGE_DEVICEINFO
    fontData[Lan][PAGE_DEVICEINFO].insert("labelTitle", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][PAGE_DEVICEINFO].insert("labelTitle", QStringList{
        "BLE",          // BLE
        "H/W バージョン", // H/W ver
        "S/W バージョン", // S/W ver
        "シリアル"       // Serial
    });

    fontData[Lan][PAGE_DEVICEINFO].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(30)));

    //PAGE_USERINFO
    fontData[Lan][PAGE_USERINFO].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(36)));
    textData[Lan][PAGE_USERINFO].insert("labelText", QStringList{
        "パスワードを変更する",   // Change password
        "ユーザーデータを削除する", // Delete user data
        "ログアウト"             // Log out
    });

    //PAGE_BATPOPUP
    fontData[Lan][PAGE_BATPOPUP].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][PAGE_BATPOPUP].insert("labelText", QStringList{
        "バッテリー残量が少ない",           // Low Battery
        "充電器を接続してください"         // Please connect it to the charger
    });

    fontData[Lan][PAGE_BATPOPUP].insert("labelTextSub", QFont(instance.fontSuit, instance.pixelToPoint(36)));
    textData[Lan][PAGE_BATPOPUP].insert("labelTextSub", QStringList{
        "バッテリー残量が非常に少ない",       // Battery very low
        "システムをシャットダウンしています" // The system is shutting down
    });

    //PAGE_REVERSE
    fontData[Lan][PAGE_REVERSE].insert("labelTextButton", QFont(instance.fontSuit, instance.pixelToPoint(36)));
    textData[Lan][PAGE_REVERSE].insert("labelTextButton", QStringList{
        "左",   // Left
        "右"    // Right
    });

    fontData[Lan][PAGE_REVERSE].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(36)));
    textData[Lan][PAGE_REVERSE].insert("labelText", QStringList{
        "リセットが進行します" // Reset will be proceeded
    });

    //SC
    Lan = SC;

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
    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonOK", QFont(instance.fontSuit, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonOK", QStringList{"确认"}); // OK

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel", QFont(instance.fontSuit, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonCancel", QStringList{"取消"}); // Cancel

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonHome", QFont(instance.fontSuit, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonHome", QStringList{"主页"}); // Home

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart", QFont(instance.fontSuit, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureStart", QStringList{"开始"}); // Start

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasure", QFont(instance.fontSuit, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasure", QStringList{"测量"}); // Measure

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonInput", QFont(instance.fontSuit, instance.pixelToPoint(35), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonInput", QStringList{"输入"}); // Input

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe", QFont(instance.fontSuit, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe", QStringList{"重新测量"}); // Remeasure

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonSave", QFont(instance.fontSuit, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonSave", QStringList{"保存"}); // Save

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonUpgrade", QFont(instance.fontSuit, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonUpgrade", QStringList{"软件升级"}); // Software Upgrade

    //CUSTOM_COMPONENT
    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextValue", QFont(instance.fontSuit, instance.pixelToPoint(30), QFont::Bold));

    fontData[Lan][CUSTOM_COMPONENT].insert("labelTextResult", QFont(instance.fontSuit, instance.pixelToPoint(36)));
    textData[Lan][CUSTOM_COMPONENT].insert("labelTextResult", QStringList{
        "成功",       // Successful
        "超时",       // Timeout
        "NULL_PTR",  // NULL_PTR
        "COUNT_ZERO",// COUNT_ZERO
        "MALLOC_FAIL",// MALLOC_FAIL
        "NONE_GRADE",// NONE_GRADE
        "PARAM_FAIL",// PARAM_FAIL
        "RESULT_FAIL",// RESULT_FAIL
        "ECODE_MAX"  // ECODE_MAX
    });

    //CUSTOM_COMPONENT_DATE
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(50)));
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelTextSelect", QFont(instance.fontSuit, instance.pixelToPoint(50), QFont::Bold));
    fontData[Lan][CUSTOM_COMPONENT_DATE].insert("labelTextSub", QFont(instance.fontSuit, instance.pixelToPoint(40)));

    //PAGE_PASSWORD
    fontData[Lan][PAGE_PASSWORD].insert("labelButtonNum", QFont(instance.fontSuit, instance.pixelToPoint(44), QFont::Bold));

    fontData[Lan][PAGE_PASSWORD].insert("labelTitle", QFont(instance.fontSuit, instance.pixelToPoint(40), QFont::Bold));
    textData[Lan][PAGE_PASSWORD].insert("labelTitle", QStringList{
        "请登录",           // Please log in
        "编辑密码",         // Edit Password
        "删除用户",         // Delete User
        "密码确认",         // Password Confirmation
        "密码再次确认",     // Password Re-confirmation
        "PASSWORD_MAX"
    });

    fontData[Lan][PAGE_PASSWORD].insert("labelTitleSub", QFont(instance.fontSuit, instance.pixelToPoint(30)));
    textData[Lan][PAGE_PASSWORD].insert("labelTitleSub", QStringList{
        "请输入您的4位数字密码",                 // Please enter your 4-digit password
        "请输入要修改的4位数字",               // Please enter the 4 digits to modify
        "请再次输入您的4位数字密码",           // Please enter your 4-digit password again
        "请输入4位数字以确认",                 // Please confirm by entering 4 digits
        "请再次输入4位数字以验证",             // Please re-enter the 4 digits to verify
        "PASSWORD_MAX"
    });

    fontData[Lan][PAGE_PASSWORD].insert("labelButtonOKText", QFont(instance.fontSuit, instance.pixelToPoint(29)));
    textData[Lan][PAGE_PASSWORD].insert("labelButtonOKText", QStringList{"确认"}); // OK

    fontData[Lan][PAGE_PASSWORD].insert("labelButtonCancelText", QFont(instance.fontSuit, instance.pixelToPoint(29)));
    textData[Lan][PAGE_PASSWORD].insert("labelButtonCancelText", QStringList{"取消"}); // Cancel

    //PAGE_PASSWORD_CONFIRM
    fontData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelTitle", QFont(instance.fontSuit, instance.pixelToPoint(40), QFont::Bold));
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
        "PASSWORD_STR_MAX"   // PASSWORD_STR_MAX
    });

    fontData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][PAGE_PASSWORD_CONFIRM].insert("labelText", QStringList{
        "登录成功",                               // PASSWORD_STR_LOGIN_SUCCESS
        "登录失败",                               // PASSWORD_STR_LOGIN_FAIL
        "请更改您的密码",                         // PASSWORD_STR_LOGIN_CHANGE
        "请输入密码以验证身份",                   // PASSWORD_STR_CONFIRM
        "密码不匹配",                             // PASSWORD_STR_CONFIRM_FAIL
        "请再次输入您的密码以确认",               // PASSWORD_STR_REPEAT
        "输入的密码与之前的密码不匹配",           // PASSWORD_STR_REPEAT_FAIL
        "是否要更改您的密码？",                   // PASSWORD_STR_EDIT
        "请输入密码以确认身份",                   // PASSWORD_STR_EDIT_CONFIRM
        "请输入新密码",                           // PASSWORD_STR_EDIT_CHANGE
        "密码更改完成，请重新登录",               // PASSWORD_STR_EDIT_SUCCESS
        "是否删除用户信息？",                     // PASSWORD_STR_DELETE
        "删除用户信息将重置密码和设置",           // PASSWORD_STR_DELETE_CONFIRM
        "用户信息已删除，系统将重启以重置设置",   // PASSWORD_STR_DELETE_SUCCESS
        "正在退出登录，请重新登录",               // PASSWORD_STR_LOGOUT
        "PASSWORD_STR_MAX"
    });

    //PAGE_HOME
    fontData[Lan][PAGE_HOME].insert("labelTextStatus", QFont(instance.fontSuit, instance.pixelToPoint(26), QFont::Bold));
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

    fontData[Lan][PAGE_HOME].insert("labelButtonText", QFont(instance.fontSuit, instance.pixelToPoint(62), QFont::ExtraBold));

    //PAGE_SELECT
    fontData[Lan][PAGE_SELECT].insert("labelTextStatus", QFont(instance.fontSuit, instance.pixelToPoint(42), QFont::ExtraBold));
    fontData[Lan][PAGE_SELECT].insert("labelTextStatusSub", QFont(instance.fontSuit, instance.pixelToPoint(24)));
    textData[Lan][PAGE_SELECT].insert("labelTextStatusSub", QStringList{"请开始测量"}); // Please start the measurement

    fontData[Lan][PAGE_SELECT].insert("labelTextStatusValue", QFont(instance.fontSuit, instance.pixelToPoint(40), QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextGlucoseValue", QFont(instance.fontSuit, instance.pixelToPoint(130), QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextMgdl", QFont(instance.fontSuit, instance.pixelToPoint(34), QFont::Bold));
    fontData[Lan][PAGE_SELECT].insert("labelTextResult", QFont(instance.fontSuit, instance.pixelToPoint(32)));
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

    fontData[Lan][PAGE_SELECT].insert("labelTextTime", QFont(instance.fontSuit, instance.pixelToPoint(21), QFont::Bold));
    textData[Lan][PAGE_SELECT].insert("labelTextTime", QStringList{"时间"}); // Time

    fontData[Lan][PAGE_SELECT].insert("labelTextIcon", QFont(instance.fontSuit, instance.pixelToPoint(23), QFont::Bold));
    textData[Lan][PAGE_SELECT].insert("labelTextIcon", QStringList{
        "正常",       // Normal
        "低",         // Low
        "高",         // High
        "低",         // Low
        "高"          // High
    });

    //PAGE_MENU
    fontData[Lan][PAGE_MENU].insert("labelButtonText", QFont(instance.fontSuit, instance.pixelToPoint(30), QFont::Bold));
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
    fontData[Lan][PAGE_CALI_CHECK].insert("labelTextCheck", QFont(instance.fontSuit, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][PAGE_CALI_CHECK].insert("labelTextCheck", QStringList{
        "校准阶段\n请插入手指",     // Calibration phase, Please insert your finger
        "校准完成\n是否重新执行？" // Calibration complete, Do you want to proceed again?
    });

    //PAGE_CALI_GAIN_CONFIRM
    fontData[Lan][PAGE_CALI_GAIN_CONFIRM].insert("labelTextGainConfirm", QFont(instance.fontSuit, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][PAGE_CALI_GAIN_CONFIRM].insert("labelTextGainConfirm", QStringList{
        "LED灵敏度调整阶段\n请勿移动手指", // LED sensitivity adjustment step, Please do not move your finger
        "LED灵敏度调整已完成"         // LED sensitivity adjustment has been completed
    });

    //PAGE_GRAPH
    fontData[Lan][PAGE_GRAPH].insert("labelProgressText", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][PAGE_GRAPH].insert("labelProgressText", QStringList{"完成"}); // Completed

    fontData[Lan][PAGE_GRAPH].insert("labelProgressValue", QFont(instance.fontSuit, instance.pixelToPoint(60), QFont::Bold));
    fontData[Lan][PAGE_GRAPH].insert("labelProgressPercent", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));

    fontData[Lan][PAGE_GRAPH].insert("labelAdcText", QFont(instance.fontSuit, instance.pixelToPoint(20)));
    textData[Lan][PAGE_GRAPH].insert("labelAdcText", QStringList{"A:"});

    fontData[Lan][PAGE_GRAPH].insert("labelLoading", QFont(instance.fontSuit, instance.pixelToPoint(48), QFont::Bold));
    textData[Lan][PAGE_GRAPH].insert("labelLoading", QStringList{"分析中"}); // Analyzing

    //Page_CALI_GAIN_RESULT
    fontData[Lan][PAGE_CALI_GAIN_RESULT].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][PAGE_CALI_GAIN_RESULT].insert("labelText", QStringList{
        "LED灵敏度调整已完成\n请进行下一步测量", // LED sensitivity adjustment is complete, Proceed to the next measurement step
        "LED灵敏度调整失败\n请重新测量"       // LED sensitivity adjustment failed, Please measure again
    });

    //PAGE_CALI_SELECT
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectText", QFont(instance.fontSuit, instance.pixelToPoint(30), QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT].insert("labelSelectText", QStringList{
        "空腹",       // Empty stomach
        "餐后"        // After meal
    });

    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextAdc", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));
    fontData[Lan][PAGE_CALI_SELECT].insert("labelSelectTextValue", QFont(instance.fontSuit, instance.pixelToPoint(36)));

    //PAGE_CALI_SELECT_INFO
    fontData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][PAGE_CALI_SELECT_INFO].insert("labelSelectInfoText", QStringList{
        "距离上次进餐是否已超过8小时？",         // Has it been more than 8 hours since your last meal?
        "距离上次进餐是否已超过1小时？",         // Has it been more than 1 hour since your last meal?
        "距离上次进餐是否已超过1小时30分钟？",   // Has it been more than 1 hour and 30 minutes since your last meal?
        "距离上次进餐是否已超过2小时？"          // Has it been more than 2 hours since your last meal?
    });

    //PAGE_CALI_CONFIRM
    fontData[Lan][PAGE_CALI_CONFIRM].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][PAGE_CALI_CONFIRM].insert("labelText", QStringList{"选择输入或测量"}); // Select input or measure

    //PAGE_CALI_RESULT
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextAdc", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextTemp", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT].insert("labelTextHeart", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));

    //PAGE_CALI_RESULT_MULTI
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextAdc", QFont(instance.fontSuit, instance.pixelToPoint(34), QFont::Bold));
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextTemp", QFont(instance.fontSuit, instance.pixelToPoint(34)));
    fontData[Lan][PAGE_CALI_RESULT_MULTI].insert("labelTextHeart", QFont(instance.fontSuit, instance.pixelToPoint(34)));

    //PAGE_RESULT
    fontData[Lan][PAGE_RESULT].insert("labelTextGlucoseValue", QFont(instance.fontSuit, instance.pixelToPoint(103), QFont::ExtraBold));

    fontData[Lan][PAGE_RESULT].insert("labelTextMgdl", QFont(instance.fontSuit, instance.pixelToPoint(27)));
    textData[Lan][PAGE_RESULT].insert("labelTextMgdl", QStringList{"mg/dL"}); // mg/dL (단위는 변환 없이 사용)

    fontData[Lan][PAGE_RESULT].insert("labelTextTime", QFont(instance.fontSuit, instance.pixelToPoint(21), QFont::Bold));
    textData[Lan][PAGE_RESULT].insert("labelTextTime", QStringList{"时间"}); // Time

    fontData[Lan][PAGE_RESULT].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(36)));

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

    fontData[Lan][PAGE_RESULT].insert("labelProgressBarTooltip", QFont(instance.fontSuit, instance.pixelToPoint(16), QFont::Bold));
    textData[Lan][PAGE_RESULT].insert("labelProgressBarTooltip", QStringList{
        "正常",       // Normal
        "注意",       // Caution
        "警告",       // Warning
        "错误"        // Error
    });

    //PAGE_INIT
    fontData[Lan][PAGE_INIT].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(36)));
    textData[Lan][PAGE_INIT].insert("labelText", QStringList{
        "恢复出厂设置",   // Factory reset
        "重置蓝牙",       // Bluetooth reset
        "血糖校准重置"    // Blood sugar calibration reset
    });

    //PAGE_INIT_CONFIRM
    fontData[Lan][PAGE_INIT_CONFIRM].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][PAGE_INIT_CONFIRM].insert("labelText", QStringList{
        "系统的所有信息将会被重置。\n是否继续进行出厂设置？",   // The entire system information will be reset. Do you want to proceed with factory reset?
        "系统初始化后将会重新启动",                 // After system initialization, the system will restart
        "蓝牙用户信息将会初始化。\n与智能手机的连接将被断开。\n是否重置蓝牙？", // Bluetooth user information will be initialized. The connection with the smartphone is disconnected. Would you like to reset Bluetooth?
        "蓝牙用户信息已被初始化",                 // Bluetooth user information has been reset
        "血糖校正将被重置。\n是否重置血糖校正？", // Blood sugar correction will be reset. Do you want to reset blood sugar correction?
        "血糖校正已被重置"                       // Blood sugar correction has been reset
    });

    //PAGE_THRESHOLD
    fontData[Lan][PAGE_THRESHOLD].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(36)));
    textData[Lan][PAGE_THRESHOLD].insert("labelText", QStringList{
        "低血糖",    // Low Blood Sugar
        "高血糖"     // High Blood Sugar
    });

    fontData[Lan][PAGE_THRESHOLD].insert("labelButton", QFont(instance.fontSuit, instance.pixelToPoint(22)));
    textData[Lan][PAGE_THRESHOLD].insert("labelButton", QStringList{"设置"}); // Set

    fontData[Lan][PAGE_THRESHOLD].insert("labelValue", QFont(instance.fontSuit, instance.pixelToPoint(48), QFont::Bold));

    //PAGE_SOUND
    fontData[Lan][PAGE_SOUND].insert("labelVolume", QFont(instance.fontSuit, instance.pixelToPoint(110), QFont::Bold));

    //PAGE_SLEEP
    fontData[Lan][PAGE_SLEEP].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][PAGE_SLEEP].insert("labelText", QStringList{
        "30秒",    // 30sec
        "1分钟",   // 1min
        "3分钟",   // 3min
        "5分钟",   // 5min
        "10分钟",  // 10min
        "无"       // None
    });

    //PAGE_UPGRADE
    fontData[Lan][PAGE_UPGRADE].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][PAGE_UPGRADE].insert("labelText", QStringList{"版本"}); // Version

    fontData[Lan][PAGE_UPGRADE].insert("labelTextVersion", QFont(instance.fontSuit, instance.pixelToPoint(55)));

    //PAGE_UPGRADE_CONFIRM
    fontData[Lan][PAGE_UPGRADE_CONFIRM].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][PAGE_UPGRADE_CONFIRM].insert("labelText", QStringList{
        "1. 将设备连接到电脑\n"
        "2. 将bin文件复制到设备\n"
        "3. 文件复制完成后重启设备" // 1. Connect the device to PC, 2. Copy bin file to the device, 3. Restart the device after copying is complete
    });

    //PAGE_DEVICEINFO
    fontData[Lan][PAGE_DEVICEINFO].insert("labelTitle", QFont(instance.fontSuit, instance.pixelToPoint(36), QFont::Bold));
    textData[Lan][PAGE_DEVICEINFO].insert("labelTitle", QStringList{
        "蓝牙",      // BLE
        "硬件版本",  // H/W ver
        "软件版本",  // S/W ver
        "序列号"     // Serial
    });

    fontData[Lan][PAGE_DEVICEINFO].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(30)));

    //PAGE_USERINFO
    fontData[Lan][PAGE_USERINFO].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(36)));
    textData[Lan][PAGE_USERINFO].insert("labelText", QStringList{
        "修改密码",     // Change password
        "删除用户数据", // Delete user data
        "注销登录"      // Log out
    });

    //PAGE_BATPOPUP
    fontData[Lan][PAGE_BATPOPUP].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(42), QFont::Bold));
    textData[Lan][PAGE_BATPOPUP].insert("labelText", QStringList{
        "电量不足",             // Low Battery
        "请连接充电器"          // Please connect it to the charger
    });

    fontData[Lan][PAGE_BATPOPUP].insert("labelTextSub", QFont(instance.fontSuit, instance.pixelToPoint(36)));
    textData[Lan][PAGE_BATPOPUP].insert("labelTextSub", QStringList{
        "电量非常低",          // Battery very low
        "系统正在关闭"         // The system is shutting down
    });

    //PAGE_REVERSE
    fontData[Lan][PAGE_REVERSE].insert("labelTextButton", QFont(instance.fontSuit, instance.pixelToPoint(36)));
    textData[Lan][PAGE_REVERSE].insert("labelTextButton", QStringList{
        "左手",  // Left
        "右手"   // Right
    });

    fontData[Lan][PAGE_REVERSE].insert("labelText", QFont(instance.fontSuit, instance.pixelToPoint(36)));
    textData[Lan][PAGE_REVERSE].insert("labelText", QStringList{
        "重启后设置将被重置" // Reset will be proceeded
    });

    //TC
    //ES
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
