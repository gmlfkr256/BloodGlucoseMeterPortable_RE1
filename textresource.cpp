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

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasure",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Medium));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasure",QStringList{"측정"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonInput",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Medium));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonInput",QStringList{"입력"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Medium));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe",QStringList{"재측정"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonSave",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Medium));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonSave",QStringList{"저장"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonUpgrade",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Medium));
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
    fontData[Lan][PAGE_PASSWORD].insert("labelButtonNum",QFont(instance.fontSuit,instance.pixelToPoint(44),QFont::Medium));

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
    fontData[Lan][PAGE_UPGRADE_CONFIRM].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(42),QFont::Medium));
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

    //====================================================================================================================================
    //EN
    Lan = EN;
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

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Medium));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe",QStringList{"Remeasure"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonSave",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Medium));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonSave",QStringList{"Save"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Medium));
    textData[Lan][CUSTOM_BUTTON].insert("labelButtonMeasureRe",QStringList{"ReMeasure"});

    fontData[Lan][CUSTOM_BUTTON].insert("labelButtonUpgrade",QFont(instance.fontSuit,instance.pixelToPoint(30),QFont::Medium));
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
    textData[Lan][PAGE_HOME].insert("labelTextStatus",QStringList{"Wake\nUp","Before\nBreakfast","After\nBreakfast","Before\nLunch","After\nLunch","Before\nDinner","After\nDinner","Bed\nTime"});

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
    textData[Lan][PAGE_SELECT].insert("labelTextIcon",QStringList{"Normal","LOW","High","Low","High"});

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
    fontData[Lan][PAGE_RESULT].insert("labelTextMgdl",QFont(instance.fontSuit,instance.pixelToPoint(27)));
    textData[Lan][PAGE_RESULT].insert("labelTextMgdl",QStringList{"mg/dL"});

    fontData[Lan][PAGE_RESULT].insert("labelTextTime",QFont(instance.fontSuit,instance.pixelToPoint(21),QFont::Bold));
    textData[Lan][PAGE_RESULT].insert("labelTextTime",QStringList{"Time"});

    fontData[Lan][PAGE_RESULT].insert("labelTextGlucoseValue",QFont(instance.fontSuit,instance.pixelToPoint(103),QFont::ExtraBold));

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
    fontData[Lan][PAGE_UPGRADE_CONFIRM].insert("labelText",QFont(instance.fontSuit,instance.pixelToPoint(42),QFont::Medium));
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
