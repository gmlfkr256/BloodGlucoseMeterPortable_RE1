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

#include "guiapi.h"

using namespace std;

/*---------------------------------------------------------------------------*
 * PROTOTYPES                                                                *
 *---------------------------------------------------------------------------*/
static int ipcSendMsg (vtIpcMsg_t *msgP, int msgLen);
static int ipcRecvMsg (int rfd, void *rDataP, int dataLen);

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
static int ipcSendMsg (vtIpcMsg_t *msgP, int msgLen)
{
	int fd;

	if (!msgP)
		return GAPI_FAIL;

	if ((fd = open (VTIPC_SYSMGR_FIFO_FNAME, O_WRONLY)) == -1) {
		gapiError("couldn't open sysmgr FIFO (%s)...\n", VTIPC_SYSMGR_FIFO_FNAME);
		return GAPI_FAIL;
	}

	if (write (fd, (void *)msgP, msgLen) == -1) {
		close (fd);
		gapiError("couldn't send message to sysmgr...\n");
		return GAPI_FAIL;
	}

	close (fd);

	return GAPI_SUCCESS;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
static int ipcRecvMsg (int rfd, void *rDataP, int dataLen)
{
	fd_set fds;
	struct timeval timeout;
	int sel_rlt, len;
	vtIpcRespMsg_t r_msg;

	memset (&r_msg, 0, sizeof (vtIpcRespMsg_t));

	timeout.tv_usec = 0;
	timeout.tv_sec = GAPI_IPC_RESP_TIMEOUT;

	FD_ZERO (&fds);
	FD_SET (rfd, &fds);

	sel_rlt = select (rfd + 1, &fds, NULL, NULL, &timeout);
	if (sel_rlt == -1) {
		gapiError("failed select for receiving...\n");
		return GAPI_FAIL;
	}
	else if (sel_rlt == 0) {
		gapiError("timeout occured for receiving...\n");
		return GAPI_FAIL;
	}

	if (FD_ISSET (rfd, &fds)) {
		if ((len = read (rfd, (void *)&r_msg, sizeof (vtIpcRespMsg_t))) == -1) {
			gapiError("failed read for receiving...\n");
			return GAPI_FAIL;
		}

		// check header
		if (r_msg.hdr.magic != (VTIPC_SYSMGR_MAGIC_NUM + r_msg.hdr.id)) {
			gapiError("invalid response magic num...\n");
			return GAPI_FAIL;
		}

		if (r_msg.hdr.rlt_sts != VTIPC_RESP_MSG_OK) {
			gapiError("failed state for response...\n");
			return GAPI_FAIL;
		}

		if (rDataP) {
			if (len <= (int) VTIPC_RESP_HDR_LEN) {
				gapiError("too small length: recv=%d...\n", len);
				return GAPI_FAIL;
			}
			else if (len != (int) (VTIPC_RESP_HDR_LEN + dataLen)) {
				gapiError("different length: id=%d, exp=%d, recv=%d...\n", \
					r_msg.hdr.id, VTIPC_RESP_HDR_LEN + dataLen, len);
			}

			memcpy (rDataP, (void *)&(r_msg.body), (len - VTIPC_RESP_HDR_LEN));
		}
		return GAPI_SUCCESS;
	}

	return GAPI_FAIL;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int vtIpcProcess (uint8_t msgId, uint8_t msgAct, void *dataP, int dLen)
{
	vtIpcMsg_t msg;
	int r_fd = -1;

	memset (&msg, 0, sizeof (vtIpcMsg_t));

	if (!dataP || (dLen <= 0))
		return GAPI_FAIL;

	// fill the message
	msg.hdr.magic = VTIPC_SYSMGR_MAGIC_NUM;
	msg.hdr.id = msgId;
	msg.hdr.act = msgAct;
	memcpy (msg.hdr.r_fifo, GAPI_IPC_RX_FIFO_FNAME, strlen (GAPI_IPC_RX_FIFO_FNAME));

	if ((msgAct == VTIPC_MSGACT_SET) || (msgAct == VTIPC_MSGACT_GETOPT)) {
		msg.hdr.b_len = dLen;
		memcpy ((void *)&(msg.body), dataP, dLen);
	}

	// open recv fifo
	if ((r_fd = open (GAPI_IPC_RX_FIFO_FNAME, O_RDWR)) == -1) {
		gapiError("couldn't open rx FIFO (%s)\n", GAPI_IPC_RX_FIFO_FNAME);
		return GAPI_FAIL;
	}

	// clear fifo buffer
	fsync (r_fd);

	// send ipc message to sysmgr
	if (ipcSendMsg (&msg, VTIPC_HDR_LEN + msg.hdr.b_len) != GAPI_SUCCESS)
		goto fail;

	// recv response message from sysmgr
	if (ipcRecvMsg (r_fd, ((msgAct == VTIPC_MSGACT_GET) || \
		(msgAct == VTIPC_MSGACT_GETOPT)) ? dataP : (void *)NULL, dLen) != GAPI_SUCCESS)
	{
		goto fail;
	}

	close (r_fd);
	return GAPI_SUCCESS;

fail:
	if (r_fd != -1)
		close (r_fd);

	return GAPI_FAIL;
}

/*****************************************************************************
 * FUNCTION NAME : 
 * DESCRIPTIONS : 
 * PARAMETERS : 
 * RETURNS : None
 *****************************************************************************/
int vtIpcProbe (void)
{
	struct stat f_stat;

	// check sysmgr FIFO
	if (stat (VTIPC_SYSMGR_FIFO_FNAME, &f_stat) == -1) {
		gapiError("couldn't get state of sysmgr fifo (%s).\n", VTIPC_SYSMGR_FIFO_FNAME);
		return GAPI_FAIL;
	}

	if (!S_ISFIFO (f_stat.st_mode)) {
		gapiError("there is NO sysmgr fifo (%s).\n", VTIPC_SYSMGR_FIFO_FNAME);
		return GAPI_FAIL;
	}

	// check my FIFO for message
	if (stat (GAPI_IPC_RX_FIFO_FNAME, &f_stat) == 0) {
		if (!S_ISFIFO (f_stat.st_mode)) {
			remove (GAPI_IPC_RX_FIFO_FNAME);
		}
		else {
			unlink (GAPI_IPC_RX_FIFO_FNAME);
			usleep (100000);
		}
	}

	if ((mkfifo (GAPI_IPC_RX_FIFO_FNAME, 0x666)) == -1) {
		gapiError("couldn't create fifo (%s).\n", GAPI_IPC_RX_FIFO_FNAME);
		return GAPI_FAIL;
	}

	// check my FIFO for monitoring
	if (stat (GAPI_IPC_MON_FIFO_FNAME, &f_stat) == 0) {
		if (!S_ISFIFO (f_stat.st_mode)) {
			remove (GAPI_IPC_MON_FIFO_FNAME);
		}
		else {
			unlink (GAPI_IPC_MON_FIFO_FNAME);
			usleep (100000);
		}
	}

	if ((mkfifo (GAPI_IPC_MON_FIFO_FNAME, 0x666)) == -1) {
		gapiError("couldn't create fifo (%s).\n", GAPI_IPC_MON_FIFO_FNAME);
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
int vtIpcRemove (void)
{
	unlink (GAPI_IPC_RX_FIFO_FNAME);
	unlink (GAPI_IPC_MON_FIFO_FNAME);

	return GAPI_SUCCESS;
}

/* End of File */
