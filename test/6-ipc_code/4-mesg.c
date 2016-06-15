#include "../../include/head.h"
#include <unistd.h>    // fork
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
/*
 * POSIX消息队列包含的头文件
 * */
#include <fcntl.h>	    /* For O_* constants */
#include <sys/stat.h>	    /* For mode constants */
#include <mqueue.h>

#define KEY_PATH "/home/gaosongling"
#define KEY_MAJIC 0
#define BUF_SIZE  128

/*
 * POSIX消息队列：
 * mq_open mq_close mq_unlink mq_send mq_receive
 *
 * SYSTEM V消息队列：
 * msgget msgop msgctl msgsnd msgrcv
 *
 * */

int mesg_stat_test()
{
	key_t key;
	int msgid, 
		retval;
	struct msqid_ds msq_state;
	struct msgbuf {// msgsnd要求用该结构体
		long mtype;	 /* message type, must be > 0 */
		char mtext[BUF_SIZE];	 /* message data */
	}sdata;

	key = ftok(KEY_PATH, KEY_MAJIC);

	printf("ftok key = %#x\n", key);

	msgid = msgget(key, IPC_CREAT | 0666);
	if (-1 == msgid) {
		error(0, errno, "semget failed\n");
		return -1;
	}

	sdata.mtype = 1;
	strcpy(sdata.mtext, "hellowrold");

	retval = msgsnd(msgid, &sdata, BUF_SIZE, 0);
	if (-1 == retval) {
		error(0, errno, "msgsnd failed\n");
		return -1;
	}

	retval = msgctl(msgid, IPC_STAT, &msq_state);
	if (-1 == retval) {
		error(0, errno, "msgctl IPC_STAT failed\n");
		return -1;
	}

	printf("key = %#x\n", (int)msq_state.msg_perm.__key);
	printf("uid = %d\n", (int)msq_state.msg_perm.uid);
	printf("gid = %d\n", (int)msq_state.msg_perm.gid);
	printf("cuid = %d\n", (int)msq_state.msg_perm.cuid);
	printf("cgid = %d\n", (int)msq_state.msg_perm.cgid);
	printf("seq = %d\n", (int)msq_state.msg_perm.__seq);
	printf("mode = %o[O]\n", (int)msq_state.msg_perm.cgid);
	printf("current queue num = %d\n", (int)msq_state.msg_qnum);
	printf("current bytes = %d\n", (int)msq_state.__msg_cbytes);
	printf("max bytes = %d\n", (int)msq_state.msg_qbytes);

	/* IPC_SET可以设置msq_state */

	retval = msgctl(msgid, IPC_RMID, NULL);
	if (-1 == retval) {
		error(0, errno, "msgctl IPC_RMID failed\n");
		return -1;
	}

	return 0;
}
 
/**
 * @函数说明：mq_send_recv_test
 *  		  POSIX的消息队列函数测试
 *
 * @返回值：
 */
int mq_send_recv_test()
{
	pid_t pid;
	mqd_t mq;
	struct mq_attr attr;
	int retval;

	attr.mq_flags = 0;
	attr.mq_maxmsg = 10;
	attr.mq_msgsize = 128;
	attr.mq_curmsgs = 0;
	mq = mq_open("/boot", O_CREAT | O_RDWR, 0666, &attr);	
	if (-1 == mq)
	{
		perror("mq_open:");
		return -1;
	}

	pid = fork();
	if (-1 == pid) {
		error(0, errno, "fork failed\n");
	} else if (0 == pid) {// 子进程发送
		char msg1[128] = "send test 1";
		char msg2[128] = "send test 2";
		char msg3[128] = "send test 3";
		retval = mq_send(mq, msg1, 128, 2);
		if (retval == -1)
		{
			perror("mq_send");
			return -1;
		}
		retval = mq_send(mq, msg2, 128, 3);
		if (retval == -1)
		{
			perror("mq_send");
			return -1;
		}
		retval = mq_send(mq, msg3, 128, 1);
		if (retval == -1)
		{
			perror("mq_send");
			return -1;
		}

		exit(0);
	} else {// 父进程接收并释放消息队列
		char msg[128] = {0};
		int size;
		long int curmsg;
		unsigned prio;
		wait(NULL);
		printf("child is quit\n");

		do {
			mq_getattr(mq, &attr);
			curmsg = attr.mq_curmsgs;
			if (0 == curmsg) {
				break;
			}
			printf("mq_flags = %ld\n", attr.mq_flags);
			printf("mq_maxmsg = %ld\n", attr.mq_maxmsg);
			printf("mq_msgsize = %ld\n", attr.mq_msgsize);
			printf("mq_curmsgs = %ld\n", attr.mq_curmsgs);

			size = mq_receive(mq, msg, 128, &prio);
			if (-1 == size)
			{
				perror("mq_receive:");
				return -1;
			}
			printf("recv %s  prio = %d\n", msg, prio);
		} while (1);

		mq_close(mq);
	}
	return 0;
}
