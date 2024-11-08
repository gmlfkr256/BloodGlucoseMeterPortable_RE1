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

#include "guiapi.h"

using namespace std;

#define GAPI_CFG_BASE_PATH_LEN				48
#define GAPI_CFG_DATA_PATH_LEN				64

/*---------------------------------------------------------------------------*
 * Variables                                                                 *
 *---------------------------------------------------------------------------*/
int g_CurrOprUser = GAPI_USER_1;

static char l_CfgBasePath[GAPI_CFG_BASE_PATH_LEN] = { 0, };
static char l_CfgDataPath[GAPI_USER_MAX][GAPI_CFG_DATA_PATH_LEN] = { 0, };
static char l_CfgUpgradePath[GAPI_CFG_DATA_PATH_LEN] = { 0, };
static int l_wakeUpFlag = 0;
static int l_upgradeStorage = GAPI_ACT_STOP;
static int l_gdataStorage = GAPI_ACT_STOP;
static int l_monFifoFd = -1;

/*---------------------------------------------------------------------------*
 * PROTOTYPES                                                                *
 *---------------------------------------------------------------------------*/
static void *glucoseSignalSet (int signo, void (*funcP)(int));
static int getPreviousDayData (int cYear, int cMon, int cDay, int idx);
static int getHistInfoSub (char *fNameP, gapiHistValue_t *rHistValP);
static int getMassStorageinfo (const char *devNameP, uint8_t *mountP, uint8_t *lsmodP);
static int chkSpeakerProcess (void);
static int massStorageAct (int cmd, const char *devNameP, char *mntPathP);
static int getMountPath (const char *devNameP, char *rMountPathP);
static int clearUserInfoFile (int user, char *fnameP);
static int clearHistoryInfo (int user);
static int systemReboot (void);

extern int vtIpcProcess (uint8_t msgId, uint8_t msgAct, void *dataP, int dLen);
extern int vtIpcProbe (void);
extern int vtIpcRemove (void);

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
static void *glucoseSignalSet (int signo, void (*funcP)(int))
{
	int ret;
	struct sigaction sig;
	struct sigaction osig;

	sig.sa_handler = funcP;
	sigemptyset (&sig.sa_mask);
	sig.sa_flags = 0;
	ret = sigaction (signo, &sig, &osig);
	if (ret < 0) {
		fprintf (stderr, "GUIAPI: (no=%d) sigaction FAILED...\n", signo);
		return ((void *)SIG_ERR);
	}
	else {
		return ((void *)osig.sa_handler);
	}
}

/*****************************************************************************
 * FUNCTION NAME :
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS :
 *****************************************************************************/
static int getPreviousDayData (int cYear, int cMon, int cDay, int idx)
{
	int year, month, day;
	int max_day_mon[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	year = cYear;
	month = cMon;
	day = cDay;

	if(idx < 1)
		goto end;

	// Calculate previous date only  
	day -= idx;

	while (day <= 0) {
		--month;
		if(month == 0) {
			--year;
			month = 12;

			// check leap year
			if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
				max_day_mon[2] = 29;
			}
			else {
				max_day_mon[2] = 28;
			}
		}
		day += max_day_mon[month];
	}

end:
	return ((year * 10000) + (month * 100) + day);
}

/*****************************************************************************
 * FUNCTION NAME :
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS :
 *****************************************************************************/
static int getHistInfoSub (char *fNameP, gapiHistValue_t *rHistValP)
{
	FILE *fp;
	char glucose_data[100] = { 0, };
	char *tmp_ptr, *argv[GAPI_TIME_MAX];
	int k, i;
	char *subargv[2];
	char tmp_buf[32], val[10];

	if (!fNameP || !rHistValP)
		return GAPI_FAIL;

	if ((fp = fopen (fNameP, "r")) == (FILE *)NULL) {
		gapiError("couldn't open file [%s]\n", fNameP);
		return GAPI_FAIL;
	}

	fgets (glucose_data, sizeof (glucose_data) - 1, fp);
	fclose (fp);

	for (k = 0; k < GAPI_TIME_MAX; k++)
		argv[k] = NULL;

	tmp_ptr = glucose_data;
	for (k = 0; k < GAPI_TIME_MAX; k++) {
		argv[k] = strsep (&tmp_ptr, "/");
		if (argv[k] == (char *)NULL)
				break;
	}

 	for (k = 0; k < GAPI_TIME_MAX; k++) {
		if (argv[k] == (char *)NULL)
				break;

		if (!strncmp (argv[k], "N", 1))
			continue;

		memset (tmp_buf, 0, sizeof (tmp_buf));
		strncpy (tmp_buf, argv[k], strlen (argv[k]));

		for (i = 0; i < 2; i++)
			subargv[i] = (char *)NULL;

		tmp_ptr = tmp_buf;
		for (i = 0; i < 2; i++) {
			subargv[i] = strsep (&tmp_ptr, ";");
			if (subargv[i] == (char *)NULL)
				break;
		}

		if ((strlen (subargv[0]) > 0) && (strlen (subargv[1]) > 0)) {
			rHistValP[k].valid_flag = 1;
			rHistValP[k].value = (uint16_t) atoi (subargv[1]);
			strncpy (val, subargv[0], sizeof (val));
			rHistValP[k].min = (uint8_t) atoi (&(val[2]));
			val[2] = '\0';
			rHistValP[k].hour = (uint8_t) atoi (val);
		}
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
static int getMassStorageinfo (const char *devNameP, uint8_t *mountP, uint8_t *lsmodP)
{
	FILE *fp;
	char cmd[80], buf[512];

	if (!devNameP || !mountP || !lsmodP)
		return GAPI_FAIL;

	*mountP = *lsmodP = 0;

	// mount info
	sprintf (cmd, "mount | grep %s", devNameP);
	if ((fp = popen (cmd, "r")) == (FILE *)NULL) {
		gapiError("couldn't open pipe for \"%s\".\n", cmd);
		return GAPI_FAIL;
	}

	buf[0] = '\0';
	fgets (buf, sizeof (buf) - 1, fp);
	if (strlen (buf) > 1) {
		if (strstr (buf, devNameP) != (char *)NULL)
			*mountP = 1;
	}
	pclose (fp);

	// lsmod info
	sprintf (cmd, "lsmod | grep %s", GAPI_MASS_STORAGE_MOD);
	if ((fp = popen (cmd, "r")) == (FILE *)NULL) {
		gapiError("couldn't open pipe for \"%s\".\n", cmd);
		return GAPI_FAIL;
	}

	buf[0] = '\0';
	fgets (buf, sizeof (buf) - 1, fp);
	if (strlen (buf) > 1) {
		if (strstr (buf, GAPI_MASS_STORAGE_MOD) != (char *)NULL)
			*lsmodP = 1;
	}
	pclose (fp);

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
static int chkSpeakerProcess (void)
{
	FILE *fp;
	char spk_cmd[80];
	int exist = 0;

	// check the existence of speaker play process
	sprintf (spk_cmd, "ps -ef | grep %s", GAPI_SYS_SPK_EXE_FILE);
	if ((fp = popen (spk_cmd, "r")) != (FILE *)NULL) {
		char buf[80];

		fgets (buf, sizeof (buf) - 1, fp);
		if (strlen (buf) > 1) {
			if (strstr (buf, GAPI_SYS_SPK_EXE_FILE) != (char *)NULL)
				exist = 1;
		}
		pclose (fp);
	}

	return (exist);
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
static int massStorageAct (int command, const char *devNameP, char *mntPathP)
{
	uint8_t mount_f, lsmod_f;
	char cmd[80];

	if (!devNameP || !mntPathP)
		return GAPI_FAIL;

	if (getMassStorageinfo (devNameP, &mount_f, &lsmod_f) != 0) {
		gapiError("couldn't get mass storage info. (dev=%s)\n", devNameP);
		return GAPI_FAIL;
	}

	if (command == GAPI_ACT_STOP) {		// release usb mass storage
		if (lsmod_f) {
			// rmmod g_mass_storage
			sprintf (cmd, "modprobe -r %s; sleep .5", GAPI_MASS_STORAGE_MOD);
			system (cmd);
		}
		else {
			gapiDebug("already removed mass storage module.\n");
		}

		if (mount_f) {
			gapiDebug("already mounted.\n");
		}
		else {
			// mount device
			sprintf (cmd, "mount -t vfat %s %s -o rw", \
				devNameP, mntPathP);
			system (cmd);
		}
	}
	else {	// GAPI_ACT_START: probe usb mass storage
		// remove g_ether module by force
		system ("modprobe -r g_ether");

		if (mount_f) {
			// umount device
			sprintf (cmd, "umount %s; sleep .5", devNameP);
			system (cmd);
		}
		else {
			gapiDebug("already unmounted.\n");
		}

		if (lsmod_f) {
			gapiDebug("already inserted mass storage module.\n");
		}
		else {
			// modprobe g_mass_storage
			sprintf (cmd, "modprobe %s file=%s stall=0 removable=1", \
				GAPI_MASS_STORAGE_MOD, devNameP);
			system (cmd);
		}
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME :
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS :
 *****************************************************************************/
static int getMountPath (const char *devNameP, char *rMountPathP)
{
	char cmd[128];
	FILE *fp;

	if (!devNameP || !rMountPathP)
		return GAPI_FAIL;

	// mount info
	sprintf (cmd, "mount | grep %s | cut -d' ' -f3", devNameP);
	if ((fp = popen (cmd, "r")) == (FILE *)NULL) {
		gapiError("couldn't open pipe for \"%s\".\n", cmd);
		return GAPI_FAIL;
	}

	rMountPathP[0] = '\0';
	fgets (rMountPathP, GAPI_CFG_DATA_PATH_LEN - 1, fp);
	pclose (fp);

	if (!strcmp (devNameP, GAPI_SYS_VDATA_DEV_NAME)) {
		rMountPathP[strlen (rMountPathP) - 1] = '/';		// replace '\n' to '/'
		strcat (rMountPathP, GAPI_SYS_VDATA_BASE_DNAME);
	}
	else {
		rMountPathP[strlen (rMountPathP) - 1] = '\0';		// remove '\n'
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME :
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS :
 *****************************************************************************/
static int clearUserInfoFile (int user, char *fnameP)
{
	FILE *fp;

	if (!fnameP)
		return GAPI_FAIL;

	if ((fp = fopen (fnameP, "w")) == (FILE *) NULL) {
		gapiError("couldn't open user info file \"%s\".\n", fnameP);
		return GAPI_FAIL;
	}

	fprintf (fp, "%d%d%d%d,1,111111\n", user + 1, user + 1, user + 1, user + 1);
	fflush (fp);
	fclose (fp);

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
static int clearHistoryInfo (int user)
{
	struct stat finfo;
	char cmd[128];

	if (stat (l_CfgDataPath[user], &finfo) == -1) {
		gapiError("stat failed [%s]...\n", l_CfgDataPath[user]);
		return GAPI_FAIL;
	}

	if (!S_ISDIR (finfo.st_mode) && !S_ISLNK (finfo.st_mode)) {
		gapiError("GLUCOSE directory does NOT exist [%s]...\n", l_CfgDataPath[user]);
		return GAPI_FAIL;
	}

	// delete history
	sprintf (cmd, "rm -f %s/*; sync", l_CfgDataPath[user]);
	system (cmd);

	// make a default user info file
	sprintf (cmd, "%s/%s", l_CfgDataPath[user], GAPI_SYS_USER_INFO_FNAME);
	clearUserInfoFile (user, cmd);

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
static int systemReboot (void)
{
	uint32_t tmp = 1;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_SYSTEM_RESET, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)&tmp, sizeof (uint32_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't reset the system.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
void glucoseSigUsr1 (int sig)
{
	l_wakeUpFlag = 1;
	gapiDebug("signal USR1 occurred !!\n");
}

/*---------------------------------------------------------------------------*
 * APIs
 *---------------------------------------------------------------------------*/

/*****************************************************************************
 * FUNCTION NAME :
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS :
 *****************************************************************************/
int GuiApi::getFwVersion (char *rVerP, char *rBleNameP, char *rHwVerP, char *rSerialNumP)
{
	FILE *fp;
	char mnt_path[GAPI_CFG_DATA_PATH_LEN];
	char ver_fname[80], buf[64];
	char os_ver[64] = { 0, }, ios_ver[64] = { 0, };
	char vdata_ver[64] = { 0, }, hw_ver[64] = { 0, };

	if (!rVerP || !rBleNameP || !rHwVerP || !rSerialNumP)
		return GAPI_FAIL;

	// OS version
	if (getMountPath (GAPI_SYS_OS_DEV_NAME, mnt_path) == GAPI_SUCCESS) {
		sprintf (ver_fname, "%s/%s", mnt_path, GAPI_SYS_VER_OS_FNAME);

		fp = fopen (ver_fname, "r");
		if (fp) {
			fgets (os_ver, sizeof (os_ver), fp);
			fclose (fp);
			os_ver[strlen (os_ver) - 1] = '\0';		// remove '\n'
		}
	}

	// VDATA version
	if (getMountPath (GAPI_SYS_VDATA_DEV_NAME, mnt_path) == GAPI_SUCCESS) {
		sprintf (ver_fname, "%s/%s", mnt_path, GAPI_SYS_VER_VDATA_FNAME);
		fp = fopen (ver_fname, "r");
		if (fp) {
			fgets (vdata_ver, sizeof (vdata_ver), fp);
			fclose (fp);
			vdata_ver[strlen (vdata_ver) - 1] = '\0';		// remove '\n'
		}

		// H/W version
		sprintf (ver_fname, "%s/%s", mnt_path, GAPI_SYS_VER_HW_FNAME);
		fp = fopen (ver_fname, "r");
		if (fp) {
			fgets (hw_ver, sizeof (hw_ver), fp);
			fclose (fp);
			hw_ver[strlen (hw_ver) - 1] = '\0';		// remove '\n'
		}

		// Serial Number
		sprintf (ver_fname, "%s/%s", mnt_path, GAPI_SYS_SERIAL_NUM_FNAME);
		fp = fopen (ver_fname, "r");
		if (fp) {
			fgets (buf, sizeof (buf), fp);
			fclose (fp);
			buf[strlen (buf) - 1] = '\0';		// remove '\n'
			strcpy (rSerialNumP, buf);
		}
	}

	// IOS version
	if (getMountPath (GAPI_SYS_IOS_DEV_NAME, mnt_path) == GAPI_SUCCESS) {
		sprintf (ver_fname, "%s/%s", mnt_path, GAPI_SYS_VER_IOS_FNAME);

		fp = fopen (ver_fname, "r");
		if (fp) {
			fgets (ios_ver, sizeof (ios_ver), fp);
			fclose (fp);
			ios_ver[strlen (ios_ver) - 1] = '\0';		// remove '\n'
		}
	}

	sprintf (rVerP, "%s;%s;%s", os_ver, vdata_ver, ios_ver);
	sprintf (rHwVerP, "%s", hw_ver);

	// BLE name
	rBleNameP[0] = '\0';

	fp = fopen (GAPI_SYS_BLE_LOCAL_FNAME, "r");
	if (fp) {
		fgets (buf, sizeof (buf), fp);
		fclose (fp);
		strcpy (rBleNameP, buf);
	}

	gapiDebug("F/W_version=%s, BLE_name=%s, H/W_version=%s, Serial_Number=%s\n", \
		rVerP, rBleNameP, rHwVerP, rSerialNumP);

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::setDate (char *dateP)
{
	int year, mon, day, hour, min;
	char dstr_cmd[80];

	if (!dateP) {
		gapiError("NULL date info.\n");
		return GAPI_FAIL;
	}

	sscanf (dateP, "%d/%d/%d_%d:%d", &year, &mon, &day, &hour, &min);
	sprintf (dstr_cmd, "date -s \"%d-%02d-%02d %02d:%02d:00\"; hwclock --systohc --utc", \
		year, mon, day, hour, min);

	system (dstr_cmd);

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME :
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS :
 *****************************************************************************/
int GuiApi::saveMeasurement (int term, gapiHistValue_t *histValP)
{
	DIR *dir_info = (DIR *)NULL;
	struct dirent *dir_entry;
	struct stat finfo;
	char date_str[32], fname_str[320], buf[128];
	int i, curr_date, found;
	FILE *fp;
	int result = GAPI_FAIL;
	int file_cnt = 0;
	int oldest_file;

	if (!histValP)
		return GAPI_FAIL;

	sprintf (date_str, "%02d%02d;%d", histValP->hour, histValP->min, histValP->value);

	if (term < GAPI_TIME_START || term >= GAPI_TIME_MAX) {
		gapiError("invalid term value (%d).\n", term);
		return GAPI_FAIL;
	}

	// check base directory
	if ((dir_info = opendir (l_CfgDataPath[g_CurrOprUser])) == (DIR *) NULL) {
		gapiError("couldn't open direcotry: %s\n", l_CfgDataPath[g_CurrOprUser]);
		return GAPI_FAIL;
	}

	// get current date
	if ((fp = popen("date \"+%Y%m%d\"", "r")) == (FILE *)NULL) {
		gapiError("couldn't get current time\n");
		goto end;
	}
	fgets (buf, sizeof (buf), fp);
	pclose (fp);
	curr_date = atoi (buf);

	// find the date
	found = 0;
	oldest_file = curr_date;

	while ((dir_entry = readdir (dir_info)) != (struct dirent *) NULL) {
		if (!strcmp (dir_entry->d_name,  ".") || !strcmp (dir_entry->d_name , ".."))
			continue;

		sprintf (fname_str, "%s/%s", l_CfgDataPath[g_CurrOprUser], dir_entry->d_name);
		if (stat (fname_str, &finfo) != -1) {
			if (S_ISREG (finfo.st_mode)) {
				if (curr_date == atoi (dir_entry->d_name)) {
					found = 1;
					break;
				}

				file_cnt++;
				if (oldest_file > atoi (dir_entry->d_name))
					oldest_file = atoi (dir_entry->d_name);
			}
		}
	}
	closedir (dir_info);
	dir_info = (DIR *)NULL;

	sprintf (fname_str, "%s/%d", l_CfgDataPath[g_CurrOprUser], curr_date);
	if (found == 1) {
		char *argv[GAPI_TIME_MAX];
		char tmp_buf[128], *tmp_ptr;

		// read existed data
		if ((fp = fopen (fname_str, "r")) == (FILE *)NULL) {
			gapiError("couldn't open the file: %s\n",  fname_str);
			goto end;
		}
		fgets (tmp_buf, sizeof (tmp_buf), fp);
		fclose (fp);

		// parsing the existed data
		tmp_ptr = tmp_buf;
		for (i = 0; i < GAPI_TIME_MAX; i++)
			argv[i] = (char *)NULL;

		for (i = 0; i < GAPI_TIME_MAX; i++) {
			argv[i] = strsep (&tmp_ptr, "/");
			if (argv[i] == NULL)
				break;
		}

		// fill the value
		buf[0] = '\0';
		for (i = GAPI_TIME_START; i < GAPI_TIME_MAX; i++) {
			if (i == term)
				strcat (buf, date_str);
			else
				strcat (buf, (argv[i] != (char *)NULL) ? argv[i] : "N");

			if (i < GAPI_TIME_BEDTIME)
				strcat (buf, "/");
		}
	}
	else {
		buf[0] = '\0';
		for (i = GAPI_TIME_START; i < GAPI_TIME_MAX; i++) {
			if (i == term)
				strcat (buf, date_str);
			else
				strcat (buf, "N");

			if (i < GAPI_TIME_BEDTIME)
				strcat (buf, "/");
		}
	}

	// save the value
	if ((fp = fopen (fname_str, "w")) != (FILE *)NULL) {
		fputs (buf, fp);
		fflush (fp);
		fclose (fp);
		result = GAPI_SUCCESS;
	}

	if (found == 0) {
		// check the exceedance
		if (file_cnt >= (GAPI_HISTORY_MAX_NUM - 1)) {
			// remove the oldest file
			sprintf (fname_str, "%s/%d", l_CfgDataPath[g_CurrOprUser], oldest_file);
			unlink (fname_str);
			gapiDebug("remove the oldset file: %s ...\n",  fname_str);
		}
	}

	system ("sync");
	system ("sync");

end:
	if (dir_info)
		closedir (dir_info);

	return result;
}

/*****************************************************************************
 * FUNCTION NAME :
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS :
 *****************************************************************************/
int GuiApi::getHistory (int day, gapiHistInfo_t *rHistInfoP)
{
	DIR *dir_info;
	struct dirent *dir_entry;
	struct stat finfo;
	char fname_str[300];
	time_t clock;
	struct tm *date;
	int c_year, c_mon, c_day, day_data;

	if (!rHistInfoP)
		return GAPI_FAIL;

	if ((day < 0) || (day >= GAPI_HISTORY_MAX_NUM)) {
		gapiError("invalid day(%d) info for history...\n", day);
		return GAPI_FAIL;
	}
 
	memset (rHistInfoP, 0, sizeof (gapiHistInfo_t));

	if (stat (l_CfgDataPath[g_CurrOprUser], &finfo) == -1) {
		gapiError("stat failed [%s]...\n", l_CfgDataPath[g_CurrOprUser]);
		return GAPI_FAIL;
	}

	if (!S_ISDIR (finfo.st_mode) && !S_ISLNK (finfo.st_mode)) {
		gapiError("GLUCOSE directory does NOT exist [%s]...\n", l_CfgDataPath[g_CurrOprUser]);
		return GAPI_FAIL;
	}

	/* Get today information */
	clock = time (NULL);
	date = localtime (&clock);

	c_year = date->tm_year + 1900;
	c_mon = date->tm_mon + 1;
	c_day = date->tm_mday;

	day_data = getPreviousDayData (c_year, c_mon, c_day, day);
	rHistInfoP->date = day_data;

	if ((dir_info = opendir (l_CfgDataPath[g_CurrOprUser])) == (DIR *) NULL) {
		gapiError("couldn't open data directory for history [%s]\n", \
			l_CfgDataPath[g_CurrOprUser]);
		return GAPI_FAIL;
	}

	/* get history date */
	while ((dir_entry = readdir (dir_info)) != (struct dirent *) NULL) {
		if (!strcmp (dir_entry->d_name,  ".") || !strcmp (dir_entry->d_name , ".."))
			continue;

		sprintf (fname_str, "%s/%s", l_CfgDataPath[g_CurrOprUser], dir_entry->d_name);
		if (stat (fname_str, &finfo) != -1) {
			if (S_ISREG (finfo.st_mode)) {
				if (atoi (dir_entry->d_name) == day_data) {
					if (getHistInfoSub (fname_str, rHistInfoP->val) == GAPI_SUCCESS) {
						// IKSONG_200827 rHistInfoP->date = day_data;
						;
					}
					else {
						closedir (dir_info);
						gapiError("couldn't open file[%s]\n", fname_str);
						return GAPI_FAIL;
					}
				}
			}
		}
	}
	closedir (dir_info);

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME :
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS :
 *****************************************************************************/
int GuiApi::getHistoryAll (gapiHistInfo_t *rHistInfoP)
{
	DIR *dir_info;
	struct dirent *dir_entry;
	struct stat finfo;
	char fname_str[300];
	time_t clock;
	struct tm *date;
	int c_year, c_mon, c_day;
	int num;

	if (!rHistInfoP)
		return GAPI_FAIL;
 
	for (num = 0; num < GAPI_HISTORY_MAX_NUM; num++) {
		memset (&(rHistInfoP[num]), 0, sizeof (gapiHistInfo_t));
	}

	// check dir
	if (stat (l_CfgDataPath[g_CurrOprUser], &finfo) == -1) {
		gapiError("stat failed [%s]...\n", l_CfgDataPath[g_CurrOprUser]);
		return GAPI_FAIL;
	}

	if (!S_ISDIR (finfo.st_mode) && !S_ISLNK (finfo.st_mode)) {
		gapiError("GLUCOSE directory does NOT exist [%s]...\n", l_CfgDataPath[g_CurrOprUser]);
		return GAPI_FAIL;
	}

	// open dir
	if ((dir_info = opendir (l_CfgDataPath[g_CurrOprUser])) == (DIR *) NULL) {
		gapiError("couldn't open data directory for history [%s]\n", \
			l_CfgDataPath[g_CurrOprUser]);
		return GAPI_FAIL;
	}

	clock = time (NULL);
	date = localtime (&clock);

	c_year = date->tm_year + 1900;
	c_mon = date->tm_mon + 1;
	c_day = date->tm_mday;

	// fill the date info
	for (num = 0; num < GAPI_HISTORY_MAX_NUM; num++) {
		rHistInfoP[num].date = getPreviousDayData (c_year, c_mon, c_day, num);
	}

	/* get history date */
	while ((dir_entry = readdir (dir_info)) != (struct dirent *) NULL) {
		if (!strcmp (dir_entry->d_name,  ".") || !strcmp (dir_entry->d_name , ".."))
			continue;

		sprintf (fname_str, "%s/%s", l_CfgDataPath[g_CurrOprUser], dir_entry->d_name);
		if (stat (fname_str, &finfo) != -1) {
			if (S_ISREG (finfo.st_mode)) {

				c_day = atoi (dir_entry->d_name);
				for (num = 0; num < GAPI_HISTORY_MAX_NUM; num++) {
					if (rHistInfoP[num].date == (unsigned int) c_day) {
						getHistInfoSub (fname_str, rHistInfoP[num].val);
						break;
					}
				}
			}
		}
	}
	closedir (dir_info);

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseGetUserInfo (int user, gapiSysUserInfo_t *rUserP)
{
	char fname[128], buf[80];
	FILE *fp;
	char *p_data, *argv;

	if (!rUserP)
		return GAPI_FAIL;

	if ((user < GAPI_USER_1) || (user >= GAPI_USER_MAX)) {
		gapiError("Invalid user number (%d).\n", user);
		return GAPI_FAIL;
	}

	memset (rUserP, 0, sizeof (gapiSysUserInfo_t));

	// open the file
	sprintf (fname, "%s/%s", l_CfgDataPath[user], GAPI_SYS_USER_INFO_FNAME);
	if ((fp = fopen (fname, "r")) == (FILE *)NULL) {
		gapiError("there is no user info file (%s)\n", fname);
		return GAPI_FAIL;
	}

	buf[0] = '\0';
	fgets (buf, sizeof (buf), fp);
	fclose (fp);

	if (strlen (buf) > 0) {
		p_data = buf;

		// passwd
		if ((argv = strsep (&p_data, ",\n")) != (char *)NULL) {
			strncpy (rUserP->passwd, argv, GAPI_USER_PWD_SIZE - 1);
		}

		// app name
		if ((argv = strsep (&p_data, ",\n")) != (char *)NULL) {
			strncpy (rUserP->app_name, argv, GAPI_USER_APP_NAME_SIZE - 1);
		}

		// app subinfo
		if ((argv = strsep (&p_data, ",\n")) != (char *)NULL) {
			strncpy (rUserP->app_subinfo, argv, GAPI_USER_APP_SUBINFO_SIZE - 1);
		}
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseSetUserPassword (int user, char *passP)
{
	char fname[128], buf[80];
	FILE *fp;
	char *p_data, *argv;
	gapiSysUserInfo_t uinfo = { 0, };

	if (!passP)
		return GAPI_FAIL;

	if ((user < GAPI_USER_1) || (user >= GAPI_USER_MAX)) {
		gapiError("Invalid user number (%d).\n", user);
		return GAPI_FAIL;
	}

	if (strlen (passP) < GAPI_USER_PWD_DEFAULT_LEN) {
		gapiError("[%s] too short the length (%d)...\n", passP, GAPI_USER_PWD_DEFAULT_LEN);
		return GAPI_FAIL;
	}

	if (strlen (passP) >= GAPI_USER_PWD_SIZE) {
		gapiError("[%s] exceed the length (%d)...\n", passP, GAPI_USER_PWD_SIZE);
		return GAPI_FAIL;
	}

	// open the file
	sprintf (fname, "%s/%s", l_CfgDataPath[user], GAPI_SYS_USER_INFO_FNAME);
	if ((fp = fopen (fname, "r")) == (FILE *)NULL) {
		gapiError("couldn't open_1 user info file (%s)\n", fname);
		return GAPI_FAIL;
	}

	buf[0] = '\0';
	fgets (buf, sizeof (buf), fp);
	fclose (fp);

	if (strlen (buf) > 0) {
		p_data = buf;

		// passwd
		strsep (&p_data, ",\n");

		// app name
		if ((argv = strsep (&p_data, ",\n")) != (char *)NULL) {
			strncpy (uinfo.app_name, argv, GAPI_USER_APP_NAME_SIZE - 1);
		}

		// app subinfo
		if ((argv = strsep (&p_data, ",\n")) != (char *)NULL) {
			strncpy (uinfo.app_subinfo, argv, GAPI_USER_APP_SUBINFO_SIZE - 1);
		}
	}
	strcpy (uinfo.passwd, passP);

	// update user info
	if ((fp = fopen (fname, "w")) == (FILE *)NULL) {
		gapiError("couldn't open_2 user info file (%s)\n", fname);
		return GAPI_FAIL;
	}

	fprintf (fp, "%s,%s,%s\n", uinfo.passwd, \
		(strlen (uinfo.app_name) > 0) ? uinfo.app_name : "", \
		(strlen (uinfo.app_subinfo) > 0) ? uinfo.app_subinfo : "");

	fflush (fp);
	fclose (fp);

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseDelUserInfo (int user)
{
	if ((user < GAPI_USER_1) || (user >= GAPI_USER_MAX)) {
		gapiError("Invalid user number (%d).\n", user);
		return GAPI_FAIL;
	}

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_USER_DELETE, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)&user, sizeof (int)) != GAPI_SUCCESS)
	{
		gapiError("couldn't delete user (%d)\n", user);
		return GAPI_FAIL;
	}

	// clear history & user data
	clearHistoryInfo (user);

	// reboot
	return (systemReboot ());
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseActUserLogin (int user)
{
	if ((user < GAPI_USER_1) || (user >= GAPI_USER_MAX)) {
		gapiError("Invalid user number (%d).\n", user);
		return GAPI_FAIL;
	}

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_USER_LOGIN, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)&user, sizeof (int)) != GAPI_SUCCESS)
	{
		gapiError("couldn't login (user=%d)\n", user);
		return GAPI_FAIL;
	}

	// update current operation user
	g_CurrOprUser = user;

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseActUserLogout (int user)
{
	if ((user < GAPI_USER_1) || (user >= GAPI_USER_MAX)) {
		gapiError("Invalid user number (%d).\n", user);
		return GAPI_FAIL;
	}

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_USER_LOGOUT, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)&user, sizeof (int)) != GAPI_SUCCESS)
	{
		gapiError("couldn't logout (user=%d)\n", user);
		return GAPI_FAIL;
	}

	g_CurrOprUser = GAPI_USER_1;

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseSetUpgradeStorage (int command)
{
	if (l_gdataStorage == GAPI_ACT_START) {
		if (command == GAPI_ACT_STOP) {
			if (l_upgradeStorage == GAPI_ACT_STOP) {
				return GAPI_SUCCESS;
			}
		}

		gapiDebug("GDATA storage has alreday used, so deactivate it...\n");
		massStorageAct (GAPI_ACT_STOP, GAPI_SYS_VDATA_DEV_NAME, l_CfgBasePath);
		l_gdataStorage = GAPI_ACT_STOP;
		system ("sleep .5");
	}

	if (massStorageAct (command, GAPI_SYS_UPGRADE_DEV_NAME, l_CfgUpgradePath) != \
		GAPI_SUCCESS)
	{
		return GAPI_FAIL;
	}

	l_upgradeStorage = command;

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseGetUpgradeStorage (int *rStateP)
{
	uint8_t mount_f, lsmod_f;

	if (!rStateP)
		return GAPI_FAIL;

	if (getMassStorageinfo (GAPI_SYS_UPGRADE_DEV_NAME, &mount_f, &lsmod_f) != 0) {
		gapiError("couldn't get upgrade storage info.\n");
		return GAPI_FAIL;
	}

	if (l_upgradeStorage == GAPI_ACT_START) {
		if ((mount_f == 0) && (lsmod_f == 1)) {
			*rStateP = GAPI_ACT_START;
			return GAPI_SUCCESS;
		}
		else {
			gapiError("invalid upgrade storage state (sts=ACT, mount=%d, mod=%d).\n", \
				mount_f, lsmod_f);
			return GAPI_FAIL;
		}
	}
	else {
		if (mount_f == 1) {
			*rStateP = GAPI_ACT_STOP;
			return GAPI_SUCCESS;
		}
		else {
			gapiError("invalid upgrade storage state (sts=DEACT, mount=%d, mod=%d).\n", \
				mount_f, lsmod_f);
			return GAPI_FAIL;
		}
	}
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseSetUpgradeCancel (void)
{
	char mnt_path[GAPI_CFG_DATA_PATH_LEN] = { 0, };
	char cmd[80];

	if (getMountPath (GAPI_SYS_UPGRADE_DEV_NAME, mnt_path) != GAPI_SUCCESS) {
		gapiError("couldn't get mount path of upgrade storage\n");
		return GAPI_FAIL;
	}

	sprintf (cmd, "rm -f %s/%s*; sync", mnt_path, GAPI_SYS_UPGRADE_IMAGE_PREFIX);
	system (cmd);

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseSetGdataStorage (int command)
{
	if (l_upgradeStorage == GAPI_ACT_START) {
		gapiError("upgrade storage is working now, so can't make a GDATA storage...\n");
		return GAPI_FAIL;
	}

	if (massStorageAct (command, GAPI_SYS_VDATA_DEV_NAME, l_CfgBasePath) != \
		GAPI_SUCCESS)
	{
		return GAPI_FAIL;
	}

	l_gdataStorage = command;

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseGetGdataStorage (int *rStateP)
{
	uint8_t mount_f, lsmod_f;

	if (!rStateP)
		return GAPI_FAIL;

	if (l_upgradeStorage == GAPI_ACT_START) {
		gapiDebug("upgrade storage is working now...\n");
		*rStateP = GAPI_ACT_STOP;
		return GAPI_SUCCESS;
	}

	if (getMassStorageinfo (GAPI_SYS_VDATA_DEV_NAME, &mount_f, &lsmod_f) != 0) {
		gapiError("couldn't get GDATA storage info.\n");
		return GAPI_FAIL;
	}

	if (l_gdataStorage == GAPI_ACT_START) {
		if ((mount_f == 0) && (lsmod_f == 1)) {
			*rStateP = GAPI_ACT_START;
			return GAPI_SUCCESS;
		}
		else {
			gapiError("invalid GDATA storage state (sts=ACT, mount=%d, mod=%d).\n", \
				mount_f, lsmod_f);
			return GAPI_FAIL;
		}
	}
	else {
		if (mount_f == 1) {
			*rStateP = GAPI_ACT_STOP;
			return GAPI_SUCCESS;
		}
		else {
			gapiError("invalid GDATA storage state (sts=DEACT, mount=%d, mod=%d).\n", \
				mount_f, lsmod_f);
			return GAPI_FAIL;
		}
	}
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseSetAdcChData (gapiAdcChData_t *chDataP)
{
	if (!chDataP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_ADC_CH_DATA, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)chDataP, sizeof (gapiAdcChData_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't set ADC ch data.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseGetAdcChData (gapiAdcChData_t *rChDataP)
{
	if (!rChDataP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_ADC_CH_DATA, (uint8_t) VTIPC_MSGACT_GET, \
		(void *)rChDataP, sizeof (gapiAdcChData_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't get ADC ch data.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseSetSpeakerData (gapiSpkData_t *spkDataP)
{
	if (!spkDataP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_SPK_DATA, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)spkDataP, sizeof (gapiSpkData_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't set speaker data.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseGetSpeakerData (gapiSpkData_t *rSpkDataP)
{
	if (!rSpkDataP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_SPK_DATA, (uint8_t) VTIPC_MSGACT_GET, \
		(void *)rSpkDataP, sizeof (gapiSpkData_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't get speaker data.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseSetDispData (gapiDispData_t *dispDataP)
{
	if (!dispDataP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_DISP_DATA, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)dispDataP, sizeof (gapiDispData_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't set display data.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseGetDispData (gapiDispData_t *rDispDataP)
{
	if (!rDispDataP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_DISP_DATA, (uint8_t) VTIPC_MSGACT_GET, \
		(void *)rDispDataP, sizeof (gapiDispData_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't get display data.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseGetBatData (gapiBatData_t *rBatDataP)
{
	if (!rBatDataP)
		return GAPI_FAIL;

	/* IKSONG 210512 */
	if (access (GAPI_SYS_PWR_EVT_FNAME, F_OK) == 0)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_BAT_DATA, (uint8_t) VTIPC_MSGACT_GET, \
		(void *)rBatDataP, sizeof (gapiBatData_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't get BAT data.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseSetLangData (gapiLangData_t *langDataP)
{
	if (!langDataP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_LANG_DATA, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)langDataP, sizeof (gapiLangData_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't set language data.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseGetLangData (gapiLangData_t *rLangDataP)
{
	if (!rLangDataP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_LANG_DATA, (uint8_t) VTIPC_MSGACT_GET, \
		(void *)rLangDataP, sizeof (gapiLangData_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't get language data.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseSetRegiData (gapiRegiData_t *regiDataP)
{
	if (!regiDataP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_REGI_DATA, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)regiDataP, sizeof (gapiRegiData_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't set REGI data.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseGetRegiData (gapiRegiData_t *rRegiDataP)
{
	if (!rRegiDataP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_REGI_DATA, (uint8_t) VTIPC_MSGACT_GET, \
		(void *)rRegiDataP, sizeof (gapiRegiData_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't get REGI data.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseSetSysOprData (gapiSysOprData_t *sysDataP)
{
	if (!sysDataP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_OPR_DATA, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)sysDataP, sizeof (gapiSysOprData_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't set SYSTEM data.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseGetSysOprData (gapiSysOprData_t *rSysDataP)
{
	if (!rSysDataP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_OPR_DATA, (uint8_t) VTIPC_MSGACT_GET, \
		(void *)rSysDataP, sizeof (gapiSysOprData_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't get SYSTEM data.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseSetSysMeasureData (gapiMeasureStartTime_t *mTimeP)
{
	if (!mTimeP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_SYS_MEASURE_DATA, (uint8_t) VTIPC_MSGACT_SET, \
		(void *) mTimeP, sizeof (gapiMeasureStartTime_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't set SYSTEM hidden data.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseGetSysMeasureData (gapiMeasureStartTime_t *rMtimeP)
{
	if (!rMtimeP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_SYS_MEASURE_DATA, (uint8_t) VTIPC_MSGACT_GET, \
		(void *) rMtimeP, sizeof (gapiMeasureStartTime_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't get SYSTEM hidden data.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseSetPressureData (gapiPressureData_t *pressureDataP)
{
	if (!pressureDataP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_PRESSURE_DATA, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)pressureDataP, sizeof (gapiPressureData_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't set pressure data.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseGetPressureData (gapiPressureData_t *rPressureDataP)
{
	if (!rPressureDataP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_PRESSURE_DATA, (uint8_t) VTIPC_MSGACT_GET, \
		(void *)rPressureDataP, sizeof (gapiPressureData_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't get pressure data.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseSpeakerOut (int kinds)
{
	gapiLangData_t lang_data;
	char lang_prefix[8] = { 0, }, spk_cmd[128];

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_LANG_DATA, (uint8_t) VTIPC_MSGACT_GET, \
		(void *)&lang_data, sizeof (gapiLangData_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't get language data.\n");
		return GAPI_FAIL;
	}

	switch (lang_data.used) {
		case GAPI_LANGUAGE_KOREAN :
			strcpy (lang_prefix, GAPI_SPK_LANG_PREFIX_KOREAN);
			break;
		case GAPI_LANGUAGE_ENGLISH :
			strcpy (lang_prefix, GAPI_SPK_LANG_PREFIX_ENGLISH);
			break;
		default :
			gapiError("invalid language data: (%d)\n", lang_data.used);
			return GAPI_FAIL;
	}

	// check the existence of speaker play process
	if (chkSpeakerProcess ()) {
		sprintf (spk_cmd, "killall %s", GAPI_SYS_SPK_EXE_FILE);
		system (spk_cmd);
	}

	// make a command
	sprintf (spk_cmd, "%s %s/%s/", GAPI_SYS_SPK_EXE_FILE, l_CfgBasePath, \
		GAPI_SYS_SPK_BASE_DNAME);

	switch (kinds) {
		case GAPI_SPK_MEASURE_START :
			strcat (spk_cmd, lang_prefix);
			strcat (spk_cmd, GAPI_SPK_FNAME_MEASURE_START);
			break;
		case GAPI_SPK_MEASURE_STOP :
			strcat (spk_cmd, lang_prefix);
			strcat (spk_cmd, GAPI_SPK_FNAME_MEASURE_STOP);
			break;
		case GAPI_SPK_MEASURE_COMPLETED :
			strcat (spk_cmd, lang_prefix);
			strcat (spk_cmd, GAPI_SPK_FNAME_MEASURE_COMPLETED);
			break;
		case GAPI_SPK_SEL_WAKE_UP :
			strcat (spk_cmd, lang_prefix);
			strcat (spk_cmd, GAPI_SPK_FNAME_SEL_WAKE_UP);
			break;
		case GAPI_SPK_SEL_BEFORE_BREAKFAST :
			strcat (spk_cmd, lang_prefix);
			strcat (spk_cmd, GAPI_SPK_FNAME_SEL_BEFORE_BREAKFAST);
			break;
		case GAPI_SPK_SEL_AFTER_BREAKFAST :
			strcat (spk_cmd, lang_prefix);
			strcat (spk_cmd, GAPI_SPK_FNAME_SEL_AFTER_BREAKFAST);
			break;
		case GAPI_SPK_SEL_BEFORE_LUNCH :
			strcat (spk_cmd, lang_prefix);
			strcat (spk_cmd, GAPI_SPK_FNAME_SEL_BEFORE_LUNCH);
			break;
		case GAPI_SPK_SEL_AFTER_LUNCH :
			strcat (spk_cmd, lang_prefix);
			strcat (spk_cmd, GAPI_SPK_FNAME_SEL_AFTER_LUNCH);
			break;
		case GAPI_SPK_SEL_BEFORE_DINNER :
			strcat (spk_cmd, lang_prefix);
			strcat (spk_cmd, GAPI_SPK_FNAME_SEL_BEFORE_DINNER);
			break;
		case GAPI_SPK_SEL_AFTER_DINNER :
			strcat (spk_cmd, lang_prefix);
			strcat (spk_cmd, GAPI_SPK_FNAME_SEL_AFTER_DINNER);
			break;
		case GAPI_SPK_SEL_BEDTIME :
			strcat (spk_cmd, lang_prefix);
			strcat (spk_cmd, GAPI_SPK_FNAME_SEL_BEDTIME);
			break;
		case GAPI_SPK_VOLUME_BEEP :
			strcat (spk_cmd, GAPI_SPK_FNAME_VOLUME_BEEP);
			break;
		case GAPI_SPK_ALM_HIGH :
			strcat (spk_cmd, GAPI_SPK_FNAME_ALM_HIGH);
			break;
		case GAPI_SPK_ALM_LOW :
			strcat (spk_cmd, GAPI_SPK_FNAME_ALM_LOW);
			break;
		case GAPI_SPK_WARN_HIGH :
			strcat (spk_cmd, GAPI_SPK_FNAME_WARN_HIGH);
			break;
		case GAPI_SPK_WARN_LOW :
			strcat (spk_cmd, GAPI_SPK_FNAME_WARN_LOW);
			break;
		case GAPI_SPK_CALI_NEED :
			strcat (spk_cmd, GAPI_SPK_FNAME_CALI_NEED);
			break;
		case GAPI_SPK_MEASURE_FAIL :
			strcat (spk_cmd, GAPI_SPK_FNAME_MEASURE_FAILED);
			break;
		default:
			gapiError("invalid speaker out kinds (%d)....\n", kinds);
			return GAPI_SUCCESS;
	}

	// execute speaker play
	strcat (spk_cmd, " &");

	gapiDebug("speaker_cmd: [%s]\n", spk_cmd);
	system (spk_cmd);

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseSpeakerCancel (void)
{
	if (chkSpeakerProcess ()) {
		char cmd[80];

		sprintf (cmd, "killall %s", GAPI_SYS_SPK_EXE_FILE);
		system (cmd);
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseTouchTimeoutOccurred (void)
{
	gapiVllsAct_t vlls;

	gapiDebug("touch timeout occurred. going to pwoer down mode.\n");

	vlls.with_m4 = 1;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_VLLS_ACT, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)&vlls, sizeof (gapiVllsAct_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't set VLLS activity.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseActReboot (void)
{
	return (systemReboot ());
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseActPowerDown (void)
{
	uint32_t tmp = 1;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_SYSTEM_PWR_DN, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)&tmp, sizeof (uint32_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't do power down the system...\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME :
 * DESCRIPTIONS :
 * PARAMETERS :
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseInitFactory (void)
{
	int user;
	uint32_t tmp = 1;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_INIT_FACTORY, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)&tmp, sizeof (uint32_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't execute factory reset.\n");
		return GAPI_FAIL;
	}

	// clear history & user data
	for (user = GAPI_USER_START; user < GAPI_USER_MAX; user++) {
		clearHistoryInfo (user);
	}

	// reboot
	return (systemReboot ());
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseWakeUpOccurred (void)
{
	if (l_wakeUpFlag == 0)
		return GAPI_FAIL;

	l_wakeUpFlag = 0;
	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME :
 * DESCRIPTIONS :
 * PARAMETERS :
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseInitBlueUser (void)
{
  uint32_t tmp = 1;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_INIT_BLE_USER, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)&tmp, sizeof (uint32_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't init the bluetooth user.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME :
 * DESCRIPTIONS :
 * PARAMETERS :
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseGetBleStat (gapiBleStat_t *rBleP)
{
  if (!rBleP)
    return GAPI_FAIL;

  if (vtIpcProcess ((uint8_t) VTIPC_MSGID_BLE_STAT, (uint8_t) VTIPC_MSGACT_GET, \
    (void *)rBleP, sizeof (gapiBleStat_t)) != GAPI_SUCCESS)
  {
    gapiError("couldn't get Bluetooth Status.\n");
    return GAPI_FAIL;
  }

  return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME :
 * DESCRIPTIONS :
 * PARAMETERS :
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseSetBleAct (gapiBleAct_t *bleP)
{
  if (!bleP)
    return GAPI_FAIL;

  if (vtIpcProcess ((uint8_t) VTIPC_MSGID_BLE_ACT, (uint8_t) VTIPC_MSGACT_SET, \
    (void *)bleP, sizeof (gapiBleAct_t)) != GAPI_SUCCESS)
  {
    gapiError("couldn't set Bluetooth Active.\n");
    return GAPI_FAIL;
  }

  return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME :
 * DESCRIPTIONS :
 * PARAMETERS :
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseGetBleAct (gapiBleAct_t *rBleP)
{
  if (!rBleP)
    return GAPI_FAIL;

  if (vtIpcProcess ((uint8_t) VTIPC_MSGID_BLE_ACT, (uint8_t) VTIPC_MSGACT_GET, \
    (void *)rBleP, sizeof (gapiBleAct_t)) != GAPI_SUCCESS)
  {
    gapiError("couldn't get Bluetooth Active.\n");
    return GAPI_FAIL;
  }

  return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseCaliGetUserInfo (gapiCaliUserInfo_t *rInfoP)
{
	if (!rInfoP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_CALI_USER_INFO, (uint8_t) VTIPC_MSGACT_GET, \
		(void *)rInfoP, sizeof (gapiCaliUserInfo_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't get calibration info.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseCaliClearUserInfo (void)
{
	uint32_t tmp = 1;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_CALI_CLEAR_INFO, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)&tmp, sizeof (uint32_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't clear calibration info.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseCaliClearUserSpecInfo (gapiCaliUserSpecData_t *infoP)
{
  if (!infoP)
    return GAPI_FAIL;

	if ((infoP->idx < GAPI_CALI_INDEX_1) || (infoP->idx >= GAPI_CALI_INDEX_MAX)) {
		gapiError("Invalid index number (%d).\n", infoP->idx);
		return GAPI_FAIL;
	}

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_CALI_CLEAR_SPEC_INFO, \
		(uint8_t) VTIPC_MSGACT_SET, \
		(void *)infoP, sizeof (gapiCaliUserSpecData_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't clear specific calibration info.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseCaliRestoreUserInfo (void)
{
	uint32_t tmp = 1;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_CALI_RESTORE_INFO, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)&tmp, sizeof (uint32_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't restore calibration info.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseCaliSetGlucoseValue (gapiCaliSetGlucose_t *caliP)
{
	if (!caliP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_CALI_SET_GLUCOSE, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)caliP, sizeof (gapiCaliSetGlucose_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't set glucose data for calibration.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseCaliMeasureSetCfgData (gapiCaliMeasureCfgUser_t *userCfgP)
{
	if (!userCfgP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_CALI_USER_DATA, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)userCfgP, sizeof (gapiCaliMeasureCfgUser_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't set calibration user config data.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseCaliMeasureGetCfgData (gapiCaliMeasureCfgUser_t *rUserCfgP)
{
	if (!rUserCfgP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_CALI_USER_DATA, (uint8_t) VTIPC_MSGACT_GET, \
		(void *)rUserCfgP, sizeof (gapiCaliMeasureCfgUser_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't get calibration user config data.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseSetGlucoseLimit (gapiGlucoseLimit_t *limitP)
{
	if (!limitP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_GLUCOSE_LIMIT, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)limitP, sizeof (gapiGlucoseLimit_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't set glucose Limit.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseGetGlucoseLimit (gapiGlucoseLimit_t *rLimitP)
{
	if (!rLimitP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_GLUCOSE_LIMIT, (uint8_t) VTIPC_MSGACT_GET, \
		(void *)rLimitP, sizeof (gapiGlucoseLimit_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't get glucose Limit.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseSetMotorData (gapiMotorData_t *motorP)
{
	if (!motorP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_MOTOR_DATA, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)motorP, sizeof (gapiMotorData_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't set motor data.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseGetMotorData (gapiMotorData_t *rMotorP)
{
	if (!rMotorP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_MOTOR_DATA, (uint8_t) VTIPC_MSGACT_GET, \
		(void *)rMotorP, sizeof (gapiMotorData_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't get motor data.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseSetGainDetTime (uint32_t time)
{
	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_GAIN_DET_TIME, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)&time, sizeof (uint32_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't set gain detet time.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseGetGainDetTime (uint32_t *rTimeP)
{
	if (!rTimeP)
		return GAPI_FAIL;

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_GAIN_DET_TIME, (uint8_t) VTIPC_MSGACT_GET, \
		(void *)rTimeP, sizeof (uint32_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't get gain detect time.\n");
		return GAPI_FAIL;
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseSysProcAct (gapiSysProcAct_t *actP)
{
	int rlt = GAPI_SUCCESS;

	if (!actP)
		return GAPI_FAIL;

	if ((actP->act != GAPI_ACT_START) && (actP->act != GAPI_ACT_STOP)) {
		gapiError("invalid command (%d) for process activity...\n", actP->act);
		return GAPI_FAIL;
	}

	if (actP->act == GAPI_ACT_START) {
		// open fifo for monitoring
		if (l_monFifoFd > 0) {
			close (l_monFifoFd);
			usleep (100000);
		}

		if ((l_monFifoFd = open (GAPI_IPC_MON_FIFO_FNAME, O_RDWR)) == -1) {
			gapiError("couldn't open fifo (%s)\n", GAPI_IPC_MON_FIFO_FNAME);
			return GAPI_FAIL;
		}

		// clear fifo buffer
		fsync (l_monFifoFd);
	}

	if (vtIpcProcess ((uint8_t) VTIPC_MSGID_SYS_PROC_ACT, (uint8_t) VTIPC_MSGACT_SET, \
		(void *)actP, sizeof (gapiSysProcAct_t)) != GAPI_SUCCESS)
	{
		gapiError("couldn't set the process activity (proc=%d, act=%d)...\n", \
			actP->proc, actP->act);
		rlt = GAPI_FAIL;
	}

	if ((rlt == GAPI_FAIL) || (actP->act == GAPI_ACT_STOP)) {
		// close fifo
		if (l_monFifoFd > 0) {
			close (l_monFifoFd);
		}
		l_monFifoFd = -1;
	}

	return rlt;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseMonGetRawData (gapiSysProcMonInfo_t *rMonP)
{
	fd_set fds;
	struct timeval timeout;
	int sel_rlt, recv_len, ratio;
	int mon_size = sizeof (gapiSysProcMonInfo_t);
	char buf[mon_size * 10];

	if (!rMonP)
		return GAPI_FAIL;

	memset (rMonP, 0, mon_size);

	if (l_monFifoFd == -1) {
		gapiError("FIFO for monitoring has NOT opened yet...\n");
	}

	timeout.tv_sec = 0;
	timeout.tv_usec = 200000;		// 200 msec

	// check the FIFO
	FD_ZERO (&fds);
	FD_SET (l_monFifoFd, &fds);

	sel_rlt = select (l_monFifoFd + 1, &fds, NULL, NULL, &timeout);
	if (sel_rlt == -1) {
		gapiError("select...\n");
		return GAPI_FAIL;
	}
	else if (sel_rlt == 0) {
		return GAPI_SUCCESS;
	}

	if (!FD_ISSET (l_monFifoFd, &fds)) {
		gapiError("NO data...\n");
		return GAPI_FAIL;
	}

	recv_len = read (l_monFifoFd, buf, mon_size * 10);
	if (recv_len < mon_size) {
		gapiError("recv len is short (%d-%d)\n", recv_len, mon_size);
	}

	if ((ratio = recv_len / mon_size) > 1) {
		memcpy (rMonP, (void *) &(buf[mon_size * (ratio - 1)]), mon_size);
	}
	else {
		memcpy (rMonP, (void *) buf, mon_size);
	}

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseAttach (void)
{
	FILE *fp;
	char temp[128], buf[80];
	int user, need;

	// ignore ctrl^c signal
	signal (SIGINT, SIG_IGN);
	glucoseSignalSet (SIGUSR1, glucoseSigUsr1);

	// mount info for system data
	sprintf (temp, "mount | grep %s | cut -d' ' -f3", GAPI_SYS_VDATA_DEV_NAME);
	if ((fp = popen (temp, "r")) == (FILE *)NULL) {
		gapiError("couldn't open pipe for \"%s\".\n", temp);
		return GAPI_FAIL;
	}

	buf[0] = '\0';
	fgets (buf, sizeof (buf) - 1, fp);
	pclose (fp);

	if (strlen (buf) <= 1) {
		gapiError("there is no system base path...\n");
		return GAPI_FAIL;
	}

	buf[strlen (buf) - 1] = '\0';		// remove '\n'
	strcpy (l_CfgBasePath, buf);

	// check the user directory for glucose data
	for (user = GAPI_USER_1; user < GAPI_USER_MAX; user++) {
		sprintf (l_CfgDataPath[user], "%s/%s/%s%d", l_CfgBasePath, GAPI_SYS_GDATA_BASE_DNAME, \
			GAPI_SYS_USER_DIR_PREFIX, user);
		sprintf (temp, "%s/%s", l_CfgDataPath[user], GAPI_SYS_USER_INFO_FNAME);

		need = 0;
		if (access (l_CfgDataPath[user], F_OK) != 0) {
			if (mkdir (l_CfgDataPath[user], 0755) != 0) {
				gapiError("couldn't make a [%s] user directory...\n", l_CfgDataPath[user]);
				return GAPI_FAIL;
			}
			need = 1;
		}
		else {
			if (access (temp, F_OK) != 0) {
				need = 1;
			}
		}

		if (need) {
			// make a default user info file
			clearUserInfoFile (user, temp);
		}
	}

	// mount info for upgrading
	sprintf (temp, "mount | grep %s | cut -d' ' -f3", GAPI_SYS_UPGRADE_DEV_NAME);
	if ((fp = popen (temp, "r")) == (FILE *)NULL) {
		gapiError("couldn't open pipe for \"%s\".\n", temp);
		return GAPI_FAIL;
	}

	buf[0] = '\0';
	fgets (buf, sizeof (buf) - 1, fp);
	pclose (fp);

	if (strlen (buf) <= 1) {
		gapiError("there is no upgrading path...\n");
		return GAPI_FAIL;
	}

	buf[strlen (buf) - 1] = '\0';		// remove '\n'
	strcpy (l_CfgUpgradePath, buf);

	return (vtIpcProbe ());
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int GuiApi::glucoseDetach (void)
{
	return (vtIpcRemove ());
}

/* End of File */
