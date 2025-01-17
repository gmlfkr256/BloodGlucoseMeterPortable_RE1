/*****************************************************************************
 * (c) COPYRIGHT 2007-2028  Viewtel                                          *
 *                                                                           *
 * ALL RIGHTS RESERVED                                                       *
 *                                                                           *
 * This software is the property of Viewtel and is furnished under           *
 * license by Viewtel.  This software may be used only in accordance         *
 * with the terms of said license.  This copyright notice may not be         *
 * removed, modified or obliterated without the prior written permission     *
 * of Viewtel.                                                               *
 * This software may not be copied, transmitted, provided to or otherwise    *
 * made available to any other person, company, corporation or other entity  *
 * except as specified in the terms of said license.                         *
 * No right, title, ownership or other interest in the software is hereby    *
 * granted or transferred.                                                   *
 * The information contained herein is subject to change without notice and  *
 * should not be construed as a commitment by Viewtel.                       *
 *                                                                           *
 *****************************************************************************/

#ifndef _GAPI_DEF_H
#define _GAPI_DEF_H

/*---------------------------------------------------------------------------*
 * system base                                                               *
 *---------------------------------------------------------------------------*/
#define GAPI_SYS_EMI_VER_SUPPORT			0

// return value
#define GAPI_SUCCESS									0
#define GAPI_FAIL											-1

#define GAPI_SYS_OS_DEV_NAME					"/dev/mmcblk0p1"
#define GAPI_SYS_IOS_DEV_NAME					"/dev/mmcblk0p3"
#define GAPI_SYS_VDATA_DEV_NAME				"/dev/mmcblk0p6"
#define GAPI_SYS_UPGRADE_DEV_NAME			"/dev/mmcblk0p5"

#define GAPI_SYS_GDATA_BASE_DNAME			"glucose_data"
#define GAPI_SYS_SPK_BASE_DNAME				"vdata/spk_data"
#define GAPI_SYS_SPK_EXE_FILE					"spk_play.sh"
#define GAPI_SYS_SPK_RUNNING_STATUS		"/tmp/spk_running"
#define GAPI_SYS_VDATA_BASE_DNAME			"vdata"

// power event file
#define GAPI_SYS_PWR_EVT_FNAME				"/tmp/power_evt"
#define GAPI_SYS_BLOOD_METER_PNAME		"Blood_glucose_meter_portable"

// version files
#define GAPI_SYS_VER_OS_FNAME					"os_version"
#define GAPI_SYS_VER_IOS_FNAME				"ios_version"
#define GAPI_SYS_VER_VDATA_FNAME			"vdata_version"
#define GAPI_SYS_VER_HW_FNAME					"hw_version"
#define GAPI_SYS_SERIAL_NUM_FNAME			"serial_num"

// reboot flag file
#define GAPI_SYS_REBOOT_FLAG_FNAME		"/tmp/upg_reboot"

// upgrade image prefix
#define GAPI_SYS_UPGRADE_IMAGE_PREFIX	"pgm-"

// BLE name file
#define GAPI_SYS_BLE_LOCAL_PREFIX			"HAPPYZONE"
#define	GAPI_SYS_BLE_LOCAL_FNAME			"/tmp/ble_localname"

// user directory prefix
#define GAPI_SYS_USER_DIR_PREFIX			"user_"
#define GAPI_SYS_USER_INFO_FNAME			"user_info"

/*---------------------------------------------------------------------------*
 * system definitions                                                        *
 *---------------------------------------------------------------------------*/
// IPC FIFO for monitoring data base
#define GAPI_IPC_MON_FIFO_FNAME				"/tmp/mon_fifo"
#define GAPI_SYS_BLE_PROG_NAME				"blemgr"

/*---------------------------------------------------------------------------*
 * user data definition                                                      *
 *---------------------------------------------------------------------------*/
typedef enum {
	GAPI_USER_START = 0,
	GAPI_USER_1 = GAPI_USER_START,
	GAPI_USER_2,
	GAPI_USER_MAX
} gapiUserNum_e;

#define GAPI_USER_PWD_DEFAULT_LEN			4

#define GAPI_USER_PWD_SIZE						16
#define GAPI_USER_APP_NAME_SIZE				32
#define GAPI_USER_APP_SUBINFO_SIZE		8

typedef struct gapiSysUserInfo_T {
	char passwd[GAPI_USER_PWD_SIZE];
	char app_name[GAPI_USER_APP_NAME_SIZE];
	char app_subinfo[GAPI_USER_APP_SUBINFO_SIZE];
} __attribute__((__packed__)) gapiSysUserInfo_t;

/*---------------------------------------------------------------------------*
 * led data definition                                                       *
 *---------------------------------------------------------------------------*/
// led number
typedef enum {
	GAPI_LED_START = 0,
	GAPI_LED_NUM1 = GAPI_LED_START,
	GAPI_LED_NUM2,
	GAPI_LED_NUM_MAX
} gapiLedNum_e;

/*---------------------------------------------------------------------------*
 * ADC data definition                                                       *
 *---------------------------------------------------------------------------*/
// channel
typedef enum {
	GAPI_ADC_CH1 = 0,
	GAPI_ADC_CH2,
	GAPI_ADC_CH_MAX
} gapiAdcCh_e;

// rate
#define GAPI_ADC_CH_MAX_RATE					200
#define GAPI_ADC_CH_DFT_RATE					100

// channel data
typedef struct gapiAdcChData_T {
	unsigned char act[GAPI_ADC_CH_MAX];		// 0 or 1
	unsigned short rate;
} __attribute__((__packed__)) gapiAdcChData_t;

/*---------------------------------------------------------------------------*
 * SPK data definition                                                       *
 *---------------------------------------------------------------------------*/
#define GAPI_SPK_DEF_VOL							90		// %

typedef struct gapiSpkData_T {
	unsigned char used;
	unsigned char vol;
	unsigned short revd;
} __attribute__((__packed__)) gapiSpkData_t;

/*---------------------------------------------------------------------------*
 * display data definition                                                   *
 *---------------------------------------------------------------------------*/
// display direction
typedef enum {
	GAPI_DISP_DIR_NORMAL = 0,
	GAPI_DISP_DIR_REVERSE
} gapiDispDir_e;

// display color
typedef enum {
	GAPI_DISP_COLOR_DEFAULT = 0,
	GAPI_DISP_COLOR_BLUE,
	GAPI_DISP_COLOR_RED,
	GAPI_DISP_COLOR_MAX
} gapiDispColor_e;

#define GAPI_DISP_DFT_TS_TIMEOUT				300			// seconds

typedef struct gapiDispData_T {
	unsigned int dir;						// gapiDispDir_e
	unsigned int ts_timeout;		// seconds
	unsigned int color;					// gapiDispColor_e
} __attribute__((__packed__)) gapiDispData_t;

/*---------------------------------------------------------------------------*
 * BAT charge percent                                                        *
 *---------------------------------------------------------------------------*/
typedef struct gapiBatData_T {
	unsigned int charge;		// percent
	unsigned int charging;	// 1: charging, 0: none
} __attribute__((__packed__)) gapiBatData_t;

/*---------------------------------------------------------------------------*
 * act VLLS mode                                                             *
 *---------------------------------------------------------------------------*/
typedef struct gapiVllsAct_T {
	unsigned int with_m4;
} __attribute__((__packed__)) gapiVllsAct_t;

/*---------------------------------------------------------------------------*
 * language                                                                  *
 *---------------------------------------------------------------------------*/
typedef enum {
	GAPI_LANGUAGE_KOREAN = 0,
	GAPI_LANGUAGE_ENGLISH,
	GAPI_LANGUAGE_JAPANESE,
	GAPI_LANGUAGE_CHINESE_S,
	GAPI_LANGUAGE_CHINESE_T,
	GAPI_LANGUAGE_ESPANOL,
	GAPI_LANGUAGE_MAX
} gapiLangSel_e;

typedef struct gapiLangData_T {
	unsigned int used;
} __attribute__((__packed__)) gapiLangData_t;

/*---------------------------------------------------------------------------*
 * potential meter                                                           *
 *---------------------------------------------------------------------------*/
typedef enum {
	GAPI_REGI_CH1 = 0,
	GAPI_REGI_CH2,
	GAPI_REGI_CH_MAX
} gapiRegiCh_e;

#define GAPI_REGI_MAX_128_STEPS						127
#define GAPI_REGI_MAX_256_STEPS						255

typedef struct gapiRegiData_T {
	unsigned short step[GAPI_REGI_CH_MAX];
} __attribute__((__packed__)) gapiRegiData_t;

/*---------------------------------------------------------------------------*
 * temperature                                                               *
 *---------------------------------------------------------------------------*/
typedef enum {
	GAPI_TEMP_CH1 = 0,
	GAPI_TEMP_CH2,
	GAPI_TEMP_CH_MAX
} gapiTempCh_e;

typedef struct gapiTempData_T {
	unsigned char used[GAPI_TEMP_CH_MAX];
	unsigned short revd;
} __attribute__((__packed__)) gapiTempData_t;

/*---------------------------------------------------------------------------*
 * pressure threshold                                                        *
 *---------------------------------------------------------------------------*/
typedef enum {
	GAPI_PRESSURE_CH1 = 0,
	GAPI_PRESSURE_CH2,
	GAPI_PRESSURE_CH_MAX
} gapiPressureCh_e;

#define GAPI_PRESSURE_MAX_RATE				10
#define GAPI_PRESSURE_MAX_VAL					2048

#define GAPI_PRESSURE_TH_DFT_MIN			100
#define GAPI_PRESSURE_TH_DFT_MAX			2000

typedef struct gapiPressureData_T {
	unsigned int min_th;
	unsigned int max_th;
	unsigned int used[GAPI_PRESSURE_CH_MAX];
} __attribute__((__packed__)) gapiPressureData_t;

typedef struct gapiPressureValue_T {
	unsigned int value[GAPI_PRESSURE_CH_MAX];
} __attribute__((__packed__)) gapiPressureValue_t;

/*---------------------------------------------------------------------------*
 * motor setup                                                               *
 *---------------------------------------------------------------------------*/
#define GAPI_MOTOR_MAX_DEPTH					4095
#define GAPI_MOTOR_MAX_SPEED					100			// 0~100

#define GAPI_MOTOR_DFT_DEPTH					4000
#define GAPI_MOTOR_DFT_SPEED					40

typedef struct gapiMotorData_T {
	unsigned short depth;
	unsigned short speed;
} __attribute__((__packed__)) gapiMotorData_t;

/*---------------------------------------------------------------------------*
 * operation data                                                               *
 *---------------------------------------------------------------------------*/
typedef enum {
	GAPI_OPR_MODE_NORMAL = 0,
	GAPI_OPR_MODE_WEB,
	GAPI_OPR_MODE_SELF
} gapiSysOprMode_e;

typedef struct gapiSysOprData_T {
	unsigned int opr_mode;			// gapiSysOprMode_e
} __attribute__((__packed__)) gapiSysOprData_t;

/*---------------------------------------------------------------------------*
 * system hidden data                                                        *
 *---------------------------------------------------------------------------*/
#define GAPI_MTIME_DFT_AM							900		// 09:00
#define GAPI_MTIME_DFT_PM							1300	// 13:00

typedef struct gapiMeasureStartTime_T {
	unsigned short am_hour;
	unsigned short am_min;
	unsigned short pm_hour;
	unsigned short pm_min;
} __attribute__((__packed__)) gapiMeasureStartTime_t;

/*---------------------------------------------------------------------------*
 * BLE                                                                       *
 *---------------------------------------------------------------------------*/
typedef enum {
	GAPI_BLE_ACT_DISABLE,
	GAPI_BLE_ACT_ENABLE,
	GAPI_BLE_ACT_MAX
}	gapiBleAct_e;

typedef enum {
	GAPI_BLE_STAT_WHITE,
	GAPI_BLE_STAT_BLUE,
	GAPI_BLE_STAT_MAX
} gapiBleStat_e;

typedef struct gapiBleAct_T {
	gapiBleAct_e  act;
} __attribute__((__packed__)) gapiBleAct_t;

typedef struct gapiBleStat_T {
	gapiBleStat_e stat;
} __attribute__((__packed__)) gapiBleStat_t;

/*---------------------------------------------------------------------------*
 * system process activity                                                   *
 *---------------------------------------------------------------------------*/
#define GAPI_ACT_START								1
#define GAPI_ACT_STOP									2

// act process type
typedef enum {
	GAPI_PROC_ACT_NONE = 0,
	GAPI_PROC_ACT_CALIBRATION,
	GAPI_PROC_ACT_MEASURE,
	GAPI_PROC_ACT_GAIN,
	GAPI_PROC_ACT_MAX
} gapiProcAct_e;

// error code for process
typedef enum {
	GAPI_PROC_ECODE_NORMAL = 0,
	GAPI_PROC_ECODE_TIMEOUT,
	GAPI_PROC_ECODE_NULL_PTR,
	GAPI_PROC_ECODE_COUNT_ZERO,
	GAPI_PROC_ECODE_MALLOC_FAIL,
	GAPI_PROC_ECODE_NONE_GRADE,
	GAPI_PROC_ECODE_PARAM_FAIL,
	GAPI_PROC_ECODE_RESULT_FAIL,
	GAPI_PROC_ECODE_MAX
} gapiProcErrCode_e;

// system process activity type
typedef struct gapiSysProcAct_T {
	unsigned char proc;					// gapiProcAct_e
	unsigned char act;
	unsigned char user;
	unsigned char idx;					// calibration index or measurement term
	unsigned char cali_order;		// for calibration only
	unsigned char revd[3];
	unsigned int g_val;
} __attribute__((__packed__)) gapiSysProcAct_t;

// process monitoring info
typedef struct gapiSysProcMonInfo_T {
	unsigned char valid;				// 0=invalid, 1=valid
	unsigned char progress;			// 0 ~ 100;
	unsigned char completed;
	unsigned char err_code;			// gapiProcErrCode_e
	unsigned int adc_raw;				// glucose value for measurement
	unsigned int g_opt;					// glucose value 2 for test
	unsigned short hour;
	unsigned short min;
} __attribute__((__packed__)) gapiSysProcMonInfo_t;

/*---------------------------------------------------------------------------*
 * calibration & measurement enum                                            *
 *---------------------------------------------------------------------------*/
// calibration index
typedef enum {
	GAPI_CALI_INDEX_1 = 0,
	GAPI_CALI_IDX_BEFORE_1ST = GAPI_CALI_INDEX_1,		// before meal 1st time
	GAPI_CALI_INDEX_2,
	GAPI_CALI_IDX_BEFORE_2ND = GAPI_CALI_INDEX_2,		// before meal 2nd time
	GAPI_CALI_INDEX_3,
	GAPI_CALI_IDX_AFTER_1H = GAPI_CALI_INDEX_3,			// 1 hou after meal
	GAPI_CALI_INDEX_4,
	GAPI_CALI_IDX_AFTER_1H_H = GAPI_CALI_INDEX_4,		// 1 and half hour after meal
	GAPI_CALI_INDEX_5,
	GAPI_CALI_IDX_AFTER_2H = GAPI_CALI_INDEX_5,			// 2 hours after meal
	GAPI_CALI_INDEX_MAX
} gapiCaliIndex_e;

// calibration execution order
typedef enum {
	GAPI_CALI_ORDER_START = 0,
	GAPI_CALI_ORDER_1ST = GAPI_CALI_ORDER_START,
	GAPI_CALI_ORDER_2ND,
	GAPI_CALI_ORDER_3RD,
	GAPI_CALI_ORDER_MAX
} gapiCaliMeasureOrder_e;

/*---------------------------------------------------------------------------*
 * calibration & measurement config data                                     *
 *---------------------------------------------------------------------------*/
typedef struct gapiCaliMeasureCfgLed_T {
	unsigned char used;
	unsigned char bright;
	unsigned char start;
	unsigned char end;
} __attribute__((__packed__)) gapiCaliMeasureCfgLed_t; 

// limit glucose value
#define GAPI_CALI_GLUCOSE_MIN_VAL					54
#define GAPI_CALI_GLUCOSE_MAX_VAL					400
#define GAPI_MEASURE_GLUCOSE_MIN_VAL			GAPI_CALI_GLUCOSE_MIN_VAL
#define GAPI_MEASURE_GLUCOSE_MAX_VAL			GAPI_CALI_GLUCOSE_MAX_VAL

typedef struct gapiGlucoseLimit_T {
	int low;		// low threahold
	int high;		// high threshold
} __attribute__((__packed__)) gapiGlucoseLimit_t;

typedef struct gapiCaliMeasureCfgUser_T {
	unsigned char user;
	unsigned short adc_rate;
	unsigned char mav_len;
	double cof1;
	double cof2;
	gapiGlucoseLimit_t glu_limit;
	gapiCaliMeasureCfgLed_t led;
} __attribute__((__packed__)) gapiCaliMeasureCfgUser_t;

typedef struct gapiCaliMeasureCfgData_T {
	gapiCaliMeasureCfgUser_t user[GAPI_USER_MAX];
	unsigned int gain_det_time;				// seconds
} __attribute__((__packed__)) gapiCaliMeasureCfgData_t;

/*---------------------------------------------------------------------------*
 * calibaration                                                              *
 *---------------------------------------------------------------------------*/
// calibration data for each index
typedef struct gapiCaliUserIdxValue_T {
	unsigned int valid;
	unsigned int adc[GAPI_CALI_ORDER_MAX];
	unsigned int hr[GAPI_CALI_ORDER_MAX];
	unsigned int temp[GAPI_CALI_ORDER_MAX];
} __attribute__((__packed__)) gapiCaliUserIdxValue_t;

// calibration user info
typedef struct gapiCaliUserInfo_T {
	unsigned char user;
	unsigned char led_sense;
	unsigned char completed;
	unsigned char revd;
	unsigned int glucose_val[GAPI_CALI_INDEX_MAX];
	gapiCaliUserIdxValue_t val[GAPI_CALI_INDEX_MAX];
} __attribute__((__packed__)) gapiCaliUserInfo_t;

typedef struct gapiCaliUserSpecData_T {
	unsigned char user;
	unsigned char idx;
	unsigned char revd[2];
} __attribute__((__packed__)) gapiCaliUserSpecData_t;

// set glucose value for calibration
typedef struct gapiCaliSetGlucose_T {
	unsigned char user;
	unsigned char idx;
	unsigned short glucose;
} __attribute__((__packed__)) gapiCaliSetGlucose_t;

/*---------------------------------------------------------------------------*
 * for process monitoring                                                    *
 *---------------------------------------------------------------------------*/
// TODO
#define GAPI_MEASURE_ADC_RAW_MAX				GAPI_ADC_CH_MAX_RATE
#define GAPI_MEASURE_PRESSURE_RAW_MAX		GAPI_PRESSURE_MAX_RATE

typedef struct gapiMeasureGetRaw_T {
	short mon_elapsed;
	unsigned int temp_valid;
	unsigned short temp_obj[GAPI_TEMP_CH_MAX];
	unsigned short temp_amb[GAPI_TEMP_CH_MAX];
	unsigned short raw_cnt[GAPI_ADC_CH_MAX];
	unsigned short raw_val[GAPI_ADC_CH_MAX][GAPI_MEASURE_ADC_RAW_MAX];
	unsigned short pres_cnt[GAPI_PRESSURE_CH_MAX];
	short pres_val[GAPI_PRESSURE_CH_MAX][GAPI_MEASURE_PRESSURE_RAW_MAX];
} __attribute__((__packed__)) gapiMeasureGetRaw_t;

/*---------------------------------------------------------------------------*
 * for H/W test                                                              *
 *---------------------------------------------------------------------------*/
typedef enum {
	GAPI_HWTEST_ITEM_DISPLAY = 0,
	GAPI_HWTEST_ITEM_SPEAKER,
	GAPI_HWTEST_ITEM_LED,
	GAPI_HWTEST_ITEM_BATTERY,
	GAPI_HWTEST_ITEM_TEMP,
	GAPI_HWTEST_ITEM_TIME,
	GAPI_HWTEST_ITEM_TIMESYNC,
	GAPI_HWTEST_ITEM_REGI_SET,
	GAPI_HWTEST_ITEM_REGI_GET,
	GAPI_HWTEST_ITEM_ADCRATE_SET,
	GAPI_HWTEST_ITEM_ADCRATE_GET,
	GAPI_HWTEST_ITEM_TOUCH,
	GAPI_HWTEST_ITEM_BACKLIGHT,
	GAPI_HWTEST_ITEM_BLE_GET,
	GAPI_HWTEST_ITEM_SYSINFO_GET,
	GAPI_HWTEST_ITEM_SN_SET,
	GAPI_HWTEST_ITEM_FORCE,
	GAPI_HWTEST_ITEM_MOT_SET,
	GAPI_HWTEST_ITEM_MOT_GET,
	GAPI_HWTEST_ITEM_MOT_DEPTH,
	GAPI_HWTEST_ITEM_MOT_UP,
	GAPI_HWTEST_ITEM_MOT_DOWN,
	GAPI_HWTEST_ITEM_MAX
} gapiHwTestActItem_e;

#define GAPI_HWTEST_OPT_MAX_LEN				80

typedef struct gapiHwTestActParam_T {
	int item;		// gapiHwTestActItem_e
	char opt[GAPI_HWTEST_OPT_MAX_LEN];
} __attribute__((__packed__)) gapiHwTestActParam_t;

// measurement activity
typedef struct gapiHwTestMeasureAct_T {
	unsigned int act;		// GAPI_ACT_START or GAPI_ACT_STOP
	unsigned char led_percent[GAPI_LED_NUM_MAX];
} __attribute__((__packed__)) gapiHwTestMeasureAct_t;

/*---------------------------------------------------------------------------*
 * for calibration test                                                      *
 *---------------------------------------------------------------------------*/
typedef enum {
	GAPI_CALITEST_OPMODE_RAW_TEST = 0,
	GAPI_CALITEST_OPMODE_SINGLE_ADJUST,
	GAPI_CALITEST_OPMODE_AMP_TEST_POTENTIOMETER,
	GAPI_CALITEST_OPMODE_AMP_TEST_LED,
	GAPI_CALITEST_OPMODE_AMP_NORMAL,
	GAPI_CALITEST_OPMODE_INVITRO_TEST,
	GAPI_CALITEST_OPMODE_REPEAT_TEST,
	GAPI_CALITEST_OPMODE_MEASURE_TEST,
	GAPI_CALITEST_OPMODE_MAX
} gapiCaliTestOpmode_e;

typedef enum {
	GAPI_CALITEST_LED_1 = 0,
	GAPI_CALITEST_LED_2,
	GAPI_CALITEST_LED_BOTH,
	GAPI_CALITEST_LED_MAX
} gapiCaliTestLed_e;

// raw test
typedef struct gapiCaliTestRaw_T {
	unsigned char led;
	unsigned char bright;
	unsigned short start;
	unsigned short end;
	unsigned char revd[2];
} __attribute__((__packed__)) gapiCaliTestRaw_t;

// single LED adjust
typedef enum {
	GAPI_CALITEST_SA_LED_STEP1 = 0,
	GAPI_CALITEST_SA_LED_STEP2,
	GAPI_CALITEST_SA_LED_MAX_STEP
} gapiCaliTestSaLedStep_e;

typedef struct gapiCaliTestSingleAdjust_T {
	unsigned char led_num;
	unsigned char bright[GAPI_CALITEST_SA_LED_MAX_STEP];
	unsigned char duration;
	unsigned short period;
	unsigned char revd[2];
} __attribute__((__packed__)) gapiCaliTestSingleAdjust_t;

typedef struct gapiCaliTestAmpTest_T {
	unsigned char num;
	unsigned short start_idx;
	unsigned short stop_idx;
	unsigned char step;
	unsigned char regi_ch;
	unsigned char revd;
} __attribute__((__packed__)) gapiCaliTestAmpTest_t;

typedef struct gapiCaliTestAmpNormal_T {
	unsigned char num;
	unsigned short period;
	unsigned char led_step;
	unsigned char regi_step;
	unsigned char revd[3];
} __attribute__((__packed__)) gapiCaliTestAmpNormal_t;

typedef struct gapiCaliTestPressureOpt_T {
	unsigned char used[GAPI_PRESSURE_CH_MAX];
	unsigned char revd[2];
} __attribute__((__packed__)) gapiCaliTestPressureOpt_t;

// in-vitro test
typedef enum {
	GAPI_CALITEST_INVITRO_BRIGHT_START = 0,
	GAPI_CALITEST_INVITRO_BRIGHT_20 = GAPI_CALITEST_INVITRO_BRIGHT_START,
	GAPI_CALITEST_INVITRO_BRIGHT_40,
	GAPI_CALITEST_INVITRO_BRIGHT_60,
	GAPI_CALITEST_INVITRO_BRIGHT_80,
	GAPI_CALITEST_INVITRO_BRIGHT_100,
	GAPI_CALITEST_INVITRO_BRIGHT_MAX
} gapiCaliTestInVitroBright_e;

typedef enum {
	GAPI_CALITEST_INVITRO_MODE_NORMAL = 0,
	GAPI_CALITEST_INVITRO_MODE_ADJUST,
	GAPI_CALITEST_INVITRO_MODE_MAX
} gapiCaliTestInVitroMode_e;

typedef struct gapiCaliTestInVitro_T {
	unsigned char mode;
	unsigned char led;
	unsigned short act;
	unsigned short idle;
	unsigned short loop;
} __attribute__((__packed__)) gapiCaliTestInVitro_t;

// measure test
typedef struct gapiCaliTestMeasure_T {
	unsigned char led;
	unsigned char bright;
	unsigned short start;
	unsigned short end;
	unsigned char save;
	unsigned char len;
	double cof1;
	double cof2;
} __attribute__((__packed__)) gapiCaliTestMeasure_t;

// repeat test
typedef struct gapiCaliTestRepeat_T {
	unsigned char led;
	unsigned char bright;
	unsigned short act;
	unsigned short idle;
	unsigned short loop;
} __attribute__((__packed__)) gapiCaliTestRepeat_t;

// calibration data
typedef struct gapiCaliTestData_T {
	gapiCaliTestRaw_t raw;
	gapiCaliTestSingleAdjust_t sa_led;
	gapiCaliTestAmpTest_t amp_regi;
	gapiCaliTestAmpTest_t amp_led;
	gapiCaliTestAmpNormal_t amp_norm;
	gapiCaliTestPressureOpt_t pres_opt;
	gapiCaliTestInVitro_t invitro;
	gapiCaliTestMeasure_t measure;
	gapiCaliTestRepeat_t repeat;
} __attribute__((__packed__)) gapiCaliTestData_t;

// measurement activity
typedef struct gapiCaliTestMeasureAct_T {
	unsigned char mode;
	unsigned char act;
	unsigned char user;
	unsigned char index;
	unsigned char mon;
	unsigned char revd[3];
} __attribute__((__packed__)) gapiCaliTestMeasureAct_t;

#endif /* _GAPI_DEF_H */

/* End of File */
