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

#pragma once

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#include <pthread.h>
#include <time.h>
#include <dirent.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>

#include <iostream>

#include "gapi.h"
#include "vtipc.h"

/*---------------------------------------------------------------------------*
 * type definition
 *---------------------------------------------------------------------------*/
// debug
#define GAPI_DEBUG_EN						1

#if GAPI_DEBUG_EN
#define gapiDebug(fmt, args...) \
	fprintf(stderr, "[GAPI][%s] " fmt, __func__, ##args)
#else
#define gapiDebug(fmt, args...) 
#endif

#define gapiError(fmt, args...) \
	fprintf(stderr, "[GAPI:FAILED][%s] " fmt, __func__, ##args)

// system info
#define GAPI_MASS_STORAGE_MOD			"g_mass_storage"

// fifo
#define GAPI_IPC_RX_FIFO_FNAME		"/tmp/gapi_fifo"
#define GAPI_IPC_RESP_TIMEOUT			3		// 3 sec

// max history info
#define GAPI_HISTORY_MAX_NUM			91

// glucose time zone
typedef enum {
	GAPI_TIME_START = 0,
	GAPI_TIME_WAKE_UP = GAPI_TIME_START,
	GAPI_TIME_BEFORE_BREAKFAST,
	GAPI_TIME_AFTER_BREAKFAST,
	GAPI_TIME_BEFORE_LUNCH,
	GAPI_TIME_AFTER_LUNCH,
	GAPI_TIME_BEFORE_DINNER,
	GAPI_TIME_AFTER_DINNER,
	GAPI_TIME_BEDTIME,
	GAPI_TIME_MAX
} gapiGlucoseTime_e;

// history data info
typedef struct gapiHistValue_T {
	unsigned char valid_flag;
	unsigned char hour;
	unsigned char min;
	unsigned short value;
} gapiHistValue_t;

// history data info
typedef struct gapiHistInfo_T {
	unsigned int date;
	gapiHistValue_t val[GAPI_TIME_MAX];
} gapiHistInfo_t;

// speaker out
typedef enum {
	GAPI_SPK_START = 0,
	GAPI_SPK_MEASURE_START,
	GAPI_SPK_MEASURE_STOP,
	GAPI_SPK_MEASURE_COMPLETED,
	GAPI_SPK_SEL_WAKE_UP,
	GAPI_SPK_SEL_BEFORE_BREAKFAST,
	GAPI_SPK_SEL_AFTER_BREAKFAST,
	GAPI_SPK_SEL_BEFORE_LUNCH,
	GAPI_SPK_SEL_AFTER_LUNCH,
	GAPI_SPK_SEL_BEFORE_DINNER,
	GAPI_SPK_SEL_AFTER_DINNER,
	GAPI_SPK_SEL_BEDTIME,
	GAPI_SPK_VOLUME_BEEP,
	GAPI_SPK_ALM_HIGH,
	GAPI_SPK_ALM_LOW,
	GAPI_SPK_WARN_HIGH,
	GAPI_SPK_WARN_LOW,
	GAPI_SPK_CALI_NEED,
	GAPI_SPK_MEASURE_FAIL,
	GAPI_SPK_MAX
} gapiSpeakerOutKinds_e;

#define GAPI_SPK_FNAME_MEASURE_START					"measure_start.wav"
#define GAPI_SPK_FNAME_MEASURE_STOP						"measure_stop.wav"
#define GAPI_SPK_FNAME_MEASURE_COMPLETED			"measure_completed.wav"
#define GAPI_SPK_FNAME_SEL_WAKE_UP						"wake_up.wav"
#define GAPI_SPK_FNAME_SEL_BEFORE_BREAKFAST		"before_breakfast.wav"
#define GAPI_SPK_FNAME_SEL_AFTER_BREAKFAST		"after_breakfast.wav"
#define GAPI_SPK_FNAME_SEL_BEFORE_LUNCH				"before_lunch.wav"
#define GAPI_SPK_FNAME_SEL_AFTER_LUNCH				"after_lunch.wav"
#define GAPI_SPK_FNAME_SEL_BEFORE_DINNER			"before_dinner.wav"
#define GAPI_SPK_FNAME_SEL_AFTER_DINNER				"after_dinner.wav"
#define GAPI_SPK_FNAME_SEL_BEDTIME						"bedtime.wav"
#define GAPI_SPK_FNAME_VOLUME_BEEP						"beep.wav"
#define GAPI_SPK_FNAME_ALM_HIGH								"alarm_hyperglycemia.wav"
#define GAPI_SPK_FNAME_ALM_LOW								"alarm_hypoglycemia.wav"
#define GAPI_SPK_FNAME_WARN_HIGH							"caution_high_blood_sugar.wav"
#define GAPI_SPK_FNAME_WARN_LOW								"caution_low_blood_sugar.wav"
#define GAPI_SPK_FNAME_CALI_NEED							"calibration_needed.wav"
#define GAPI_SPK_FNAME_MEASURE_FAILED					"measure_failed.wav"

#define GAPI_SPK_LANG_PREFIX_KOREAN						"kr_"
#define GAPI_SPK_LANG_PREFIX_ENGLISH					"en_"
#define GAPI_SPK_LANG_PREFIX_JAPANESE					"jp_"
#define GAPI_SPK_LANG_PREFIX_CHINESE_S				"sc_"
#define GAPI_SPK_LANG_PREFIX_CHINESE_T				"tc_"
#define GAPI_SPK_LANG_PREFIX_ESPANOL					"es_"

/*---------------------------------------------------------------------------*
 * Class                                                                     *
 *---------------------------------------------------------------------------*/
class GuiApi {
	public:
		int getFwVersion (char *rVerP, char *rBleNameP, char *rHwVerP, char *rSerialNumP);
		int setDate (char *dateP);

		int saveMeasurement (int term, gapiHistValue_t *histInfoP);
		int getHistory (int day, gapiHistInfo_t *rHistInfoP);
		int getHistoryAll (gapiHistInfo_t *rHistInfoP);

		int glucoseGetUserInfo (int user, gapiSysUserInfo_t *rUserP);
		int glucoseSetUserPassword (int user, char *passP);
		int glucoseDelUserInfo (int user);
		int glucoseActUserLogin (int user);
		int glucoseActUserLogout (int user);

		int glucoseSetUpgradeStorage (int command);	// GAPI_ACT_START or GAPI_ACT_STOP
		int glucoseGetUpgradeStorage (int *rStateP);	// GAPI_ACT_START or GAPI_ACT_STOP
		int glucoseSetUpgradeCancel (void);
		int glucoseSetGdataStorage (int command);		// GAPI_ACT_START or GAPI_ACT_STOP
		int glucoseGetGdataStorage (int *rStateP);		// GAPI_ACT_START or GAPI_ACT_STOP
		int glucoseSetAdcChData (gapiAdcChData_t *chDataP);
		int glucoseGetAdcChData (gapiAdcChData_t *rChDataP);
		int glucoseSetSpeakerData (gapiSpkData_t *spkDataP);
		int glucoseGetSpeakerData (gapiSpkData_t *rSpkDataP);
		int glucoseSetDispData (gapiDispData_t *dispDataP);
		int glucoseGetDispData (gapiDispData_t *rDispDataP);
		int glucoseGetBatData (gapiBatData_t *rBatDataP);
		int glucoseSetLangData (gapiLangData_t *langDataP);
		int glucoseGetLangData (gapiLangData_t *rLangDataP);
		int glucoseSetRegiData (gapiRegiData_t *regiDataP);
		int glucoseGetRegiData (gapiRegiData_t *rRegiDataP);
		int glucoseSetSysOprData (gapiSysOprData_t *sysDataP);
		int glucoseGetSysOprData (gapiSysOprData_t *rSysDataP);
		int glucoseSetSysMeasureData (gapiMeasureStartTime_t *mTimeP);
		int glucoseGetSysMeasureData (gapiMeasureStartTime_t *rMtimeP);
		int glucoseSetPressureData (gapiPressureData_t *pressureDataP);
		int glucoseGetPressureData (gapiPressureData_t *rPressureDataP);

		int glucoseSpeakerOut (int kinds);
		int glucoseSpeakerCancel (void);
		int glucoseTouchTimeoutOccurred (void);
		int glucoseActReboot (void);
		int glucoseActPowerDown (void);
		int glucoseInitFactory (void);
		int glucoseWakeUpOccurred (void);

		int glucoseInitBlueUser (void);
		int glucoseGetBleStat (gapiBleStat_t *rBleP);
		int glucoseSetBleAct (gapiBleAct_t *bleP);
		int glucoseGetBleAct (gapiBleAct_t *rBleP);

		int glucoseCaliGetUserInfo (gapiCaliUserInfo_t *rInfoP);
		int glucoseCaliClearUserInfo (void);
		int glucoseCaliClearUserSpecInfo (gapiCaliUserSpecData_t *infoP);
		int glucoseCaliRestoreUserInfo (void);
		int glucoseCaliSetGlucoseValue (gapiCaliSetGlucose_t *caliP);

		int glucoseCaliMeasureSetCfgData (gapiCaliMeasureCfgUser_t *userCfgP);
		int glucoseCaliMeasureGetCfgData (gapiCaliMeasureCfgUser_t *rUserCfgP);
		int glucoseSetGlucoseLimit (gapiGlucoseLimit_t *limitP);
		int glucoseGetGlucoseLimit (gapiGlucoseLimit_t *rLimitP);
		int glucoseSetMotorData (gapiMotorData_t *motorP);
		int glucoseGetMotorData (gapiMotorData_t *rMotorP);
		int glucoseSetGainDetTime (uint32_t time);
		int glucoseGetGainDetTime (uint32_t *rTimeP);

		int glucoseSysProcAct (gapiSysProcAct_t *actP);
		int glucoseMonGetRawData (gapiSysProcMonInfo_t *rMonP);

		int glucoseAttach (void);
		int glucoseDetach (void);
};

/* End Of File */
