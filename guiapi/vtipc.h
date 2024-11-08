/*****************************************************************************
 * (c) COPYRIGHT 2007-2018  Viewtel                                          *
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

#ifndef _VT_IPC_H
#define _VT_IPC_H

/*---------------------------------------------------------------------------*
 * sysmgr fifo                                                               *
 *---------------------------------------------------------------------------*/
#define VTIPC_SYSMGR_FIFO_FNAME				"/tmp/sysmgr_fifo"
#define VTIPC_SYSMGR_MAGIC_NUM				0x0715

/*---------------------------------------------------------------------------*
 * ipc message definition                                                    *
 *---------------------------------------------------------------------------*/
/* message id */
typedef enum {
	VTIPC_MSGID_START = 0,

	VTIPC_MSGID_ADC_CH_DATA,
	VTIPC_MSGID_SPK_DATA,
	VTIPC_MSGID_DISP_DATA,
	VTIPC_MSGID_BAT_DATA,
	VTIPC_MSGID_VLLS_ACT,
	VTIPC_MSGID_LANG_DATA,
	VTIPC_MSGID_REGI_DATA,
	VTIPC_MSGID_TEMP_DATA,
	VTIPC_MSGID_OPR_DATA,
	VTIPC_MSGID_PRESSURE_DATA,
	VTIPC_MSGID_SYSTEM_RESET,
	VTIPC_MSGID_SYSTEM_PWR_DN,
	VTIPC_MSGID_INIT_FACTORY,
	VTIPC_MSGID_USER_DELETE,
	VTIPC_MSGID_USER_LOGIN,
	VTIPC_MSGID_USER_LOGOUT,

	// for BLE
	VTIPC_MSGID_INIT_BLE_USER,
	VTIPC_MSGID_BLE_STAT,
	VTIPC_MSGID_BLE_ACT,

	// for calibration
	VTIPC_MSGID_CALI_USER_INFO,
	VTIPC_MSGID_CALI_CLEAR_INFO,
	VTIPC_MSGID_CALI_CLEAR_SPEC_INFO,
	VTIPC_MSGID_CALI_RESTORE_INFO,
	VTIPC_MSGID_CALI_SET_GLUCOSE,

	// configuration for calibration & measure
	VTIPC_MSGID_CALI_USER_DATA,
	VTIPC_MSGID_GLUCOSE_LIMIT,
	VTIPC_MSGID_MOTOR_DATA,
	VTIPC_MSGID_GAIN_DET_TIME,

	// for process activity
	VTIPC_MSGID_SYS_PROC_ACT,

	// for HW Test
	VTIPC_MSGID_HWTEST_ACT,
	VTIPC_MSGID_HWTEST_MON_ACT,
	VTIPC_MSGID_HWTEST_MON_DATA,

	// for calibration test
	VTIPC_MSGID_CALITEST_ACT,
	VTIPC_MSGID_CALITEST_RAW,
	VTIPC_MSGID_CALITEST_DATA,

	// for hidden config data
	VTIPC_MSGID_SYS_MEASURE_DATA,

	VTIPC_MSGID_MAX
} vtIpcMsgId_e;

/* message act */
typedef enum {
	VTIPC_MSGACT_SET = 1,
	VTIPC_MSGACT_GET,
	VTIPC_MSGACT_GETOPT
} vtIpcMsgAct_e;

/*---------------------------------------------------------------------------*
 * request message definition                                                *
 *---------------------------------------------------------------------------*/
#define VTIPC_FIFO_FNAME_SIZE				32
#define VTIPC_BODY_STR_SIZE					80

/* header */
typedef struct vtIpcHdr_T {
	uint16_t magic;		// magic number
	uint8_t id;				// vtIpcMsgId_e
	uint8_t act;			// vtIpcMsgAct_e
	uint16_t b_len;		// body length
	uint16_t revd;		// for alignment
	char r_fifo[VTIPC_FIFO_FNAME_SIZE];		// fifo name for response
} __attribute__((__packed__)) vtIpcHdr_t;

#define	VTIPC_HDR_LEN								(sizeof (vtIpcHdr_t))

typedef union vtIpcMsgKind_T {
		gapiAdcChData_t	adc;
		gapiSpkData_t spk;
		gapiDispData_t disp;
		gapiBatData_t bat;
		gapiVllsAct_t vlls;
		gapiLangData_t lang;
		gapiRegiData_t regi;
		gapiTempData_t temp;
		gapiSysOprData_t opr;
		gapiMeasureStartTime_t mtime;
		gapiPressureData_t pressure;

		// for BLE
		gapiBleStat_t ble_stat;
		gapiBleAct_t ble_act;

		// for calibration
		gapiCaliUserInfo_t cali_info;
		gapiCaliUserSpecData_t cali_spec;
		gapiCaliSetGlucose_t cali_glucose;

		// configuration for calibration & measure
		gapiCaliMeasureCfgUser_t user_cfg;
		gapiGlucoseLimit_t glu_limit;
		gapiMotorData_t motor;

		// for process activity
		gapiSysProcAct_t proc_act;

		// for HW Test
		gapiHwTestActParam_t hwtest_act;
		gapiHwTestMeasureAct_t hwtest_mon_act;
		gapiMeasureGetRaw_t hwtest_mon_data;

		// for calibration test
		gapiCaliTestMeasureAct_t calitest_act;
		gapiMeasureGetRaw_t calitest_mon_data;
		gapiCaliTestData_t calitest_cfg;

		char str_val[VTIPC_BODY_STR_SIZE];
		int int_val;
		uint32_t uint_val;
} __attribute__((__packed__)) vtIpcMsgKind_t;

/* ipc message type */
typedef struct vtIpcMsg_T {
	vtIpcHdr_t hdr;
	vtIpcMsgKind_t body;
} __attribute__((__packed__)) vtIpcMsg_t;

/*---------------------------------------------------------------------------*
 * response message definition                                               *
 *---------------------------------------------------------------------------*/
#define	VTIPC_RESP_MSG_OK						1
#define	VTIPC_RESP_MSG_FAIL					2

/* ipc response header */
typedef struct vtIpcRespHdr_T {
	uint16_t magic;		// returned magic number
	uint8_t id;				// vtIpcMsgId_e
	uint8_t act;			// vtIpcMsgAct_e
	uint16_t b_len;		// body length
	uint16_t rlt_sts;	// VTIPC_RESP_MSG_OK or fail status
} __attribute__((__packed__)) vtIpcRespHdr_t;

#define	VTIPC_RESP_HDR_LEN					(sizeof (vtIpcRespHdr_t))

/* ipc response message type */
typedef struct vtIpcRespMsg_T {
	vtIpcRespHdr_t hdr;
	vtIpcMsgKind_t body;
} __attribute__((__packed__)) vtIpcRespMsg_t;

#endif	/* _VT_IPC_H */

/* End of File */
