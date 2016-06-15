#include "../../include/head.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h> // wait or waitpid
#include <unistd.h>

#include <fcntl.h>	    /* For O_* constants */
#include <sys/stat.h>	    /* For mode constants */
#include <semaphore.h> // posix sem

#define IPC_KEY 0x01020304
#define SEMNUMS 3
#define SEMOPNUMS 3
 
/**
 * @函数说明：sem_func_test 
 * 			  测试信号灯集的各个函数功能
 */
int sem_func_test()
{
	int semid, retval, i;
	unsigned short semarray[SEMNUMS];
	struct sembuf semops[SEMOPNUMS];

	/* 创建有SEMNUMS个信号量的信号灯集，如果新建
	 * 则其权限为：0666 & ～(umask) */
	if (-1 == (semid = semget(IPC_KEY, SEMNUMS, IPC_CREAT | 0666))) {
		error(0, errno, "semget failed\n");
		return -1;			
	}

	/*
	 * 获得信号灯集中所有信号量的值，此时第二个参数忽略
	 * */
	if (-1 == semctl(semid, 0, GETALL, semarray))
	{
		error(0, errno, "semctl GETALL failed\n");
		return -1;			
	}
	printf("semval[0] = %d\nsemval[1] = %d\nsemval[2] = %d\n", 
			semarray[0], semarray[1], semarray[2]);

	semarray[0] = 0;
	semarray[1] = 1;
	semarray[2] = 2;

	if (-1 == semctl(semid, 0, SETALL, semarray))
	{
		error(0, errno, "semctl SETALL failed\n");
		return -1;			
	}	

	for (i = 0; i < SEMNUMS; i++)
	{
		/*
		 * 获得信号灯集中第i个信号量的值
		 * */
		if (-1 == (retval = semctl(semid, i, GETVAL)))
		{
			error(0, errno, "semctl GETALL failed\n");
			return -1;			
		}
		printf("retval[%d] = %d\n", i, retval);
	}

	semops[0].sem_num = 0;
	semops[0].sem_op = -1; /* p */
	semops[0].sem_flg = IPC_NOWAIT; /* semop返回失败，errno设置为EAGAIN */
	semops[1].sem_num = 1;
	semops[1].sem_op = -1; /* p */
	semops[1].sem_flg = 0; /* default, enable block */
	semops[2].sem_num = 2;
	semops[2].sem_op = -2; /* p */
	semops[2].sem_flg = SEM_UNDO; /* 当程序异常结束，将信号量设置为初始值，避免锁死其他程序 */

	for (i = 0; i < SEMOPNUMS; i++)
	{
		/*
		 * 第三个参数是正数，表示semops中所有的元素个数
		 * */
		if (-1 == semop(semid, semops + i, 1))
		{
			if (errno == EAGAIN)
			{
				printf("sem[%d] IPC_NOWAIT\n", i);
				continue;
			}
			error(0, errno, "semop failed\n");
			return -1;
		}

		printf("after semop\n");
	}

	/* IPC_RMID时，第二个参数无效 */
	if (-1 == semctl(semid, 0, IPC_RMID))
	{
		error(0, errno, "semctl IPC_RMID failed\n");
		return -1;
	}

	return 0;
}

/**
 * @函数说明：posix_sem_test
 *
 * @返回值：
 */
int posix_sem_test()
{
	sem_t* sid;
	pid_t pid;

	/*if (0 != sem_init(&sid, 1, 0)) {// 1 -- process 目前linux未实现 0 -- sem value*/
		/*error(0, errno, "sem_init failed\n");*/
	/*}*/
	sid = sem_open("/hank", O_CREAT | O_RDWR, 0666);
	if (SEM_FAILED == sid) {
		error(0, errno, "sem_open failed");
	}

	pid = fork();
	if (-1 == pid) {
		error(0, errno, "fork failed\n");
	} else if (0 == pid) {
		printf("child process wait sem\n");
		sem_wait(sid);
		printf("child get sem and exit\n");
		exit(0);
	} else {
		sleep(5);
		printf("father process post sem\n");
		sem_post(sid);
		wait(NULL);
		printf("father process close sem\n");
		sem_close(sid);
	}

	return 0;
}
