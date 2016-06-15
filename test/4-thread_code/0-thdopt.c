#include "../../include/head.h"
#include <pthread.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <semaphore.h>

#define BUFF_SIZE 128

struct _global_mem {
	char buf[BUFF_SIZE];
	const int buffsize; // 在栈中
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	sem_t sem_r,
		  sem_w;
	pthread_key_t key;
} gmem = {
	.buffsize = BUFF_SIZE,
	.mutex = PTHREAD_MUTEX_INITIALIZER, // 同pthread_mutex_init
	.cond = PTHREAD_COND_INITIALIZER, // 同pthread_cond_init
};

typedef struct _thread_info {
	pthread_t tid;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	char buf[128];
}thdinfo_t;

void *reader(void *arg);
void *writer(void *arg);
void *reader_cond(void *arg);
void *writer_cond(void *arg);
void *reader_sem(void *arg);
void *writer_sem(void *arg);
void *reader_key(void *arg);
void *writer_key(void *arg);
void destructor(void *val);
void *thd_work(void *arg);

/**
 * @函数说明：thd_mutex_test 
 */
void thd_mutex_test()
{
	int i;      // for loop
	void *(*thdhandle[])(void *) = { // thread function pointer array
		reader,
		writer,
	};
	void *thdpara[] = { // thread paramater array
		NULL,
		NULL,
	};
	const int THDNO = sizeof(thdhandle) / sizeof(thdhandle[0]);
	pthread_t thdid[THDNO];
	void *retval = NULL; // 接收线程返回值

	/*
	 * 创建THDNO个线程
	 */
	for (i = 0; i < THDNO; i++)
	{
		if (0 != pthread_create(&thdid[i], NULL, thdhandle[i], thdpara[i]))
		{
			/*fprintf(stderr, "NO %d thread create: %d\n", i ,errno);*/
			error(0, errno, "NO. %d thread was created failed\n", i);
		}
	}

	/*
	 * 等待线程运行
	 */
	for (i = 0; i < THDNO; i++)
	{
		if (0 != pthread_join(thdid[i], &retval))
		{
			/*fprintf(stderr, "NO %d thread join: %d\n", i, errno);*/
			error(0, errno, "NO. %d thread was joined failed\n", i);
		}
		printf("%d\n", (int)retval);
	}

	/* pthread_cancel(thdid)作用是关闭线程 */

	printf("end thd_mutex_test\n");
}

/**
 * @函数说明：thd_cond_test 
 * 			  线程互斥锁和信号量保护临界资源
 */
void thd_cond_test()
{
	int i;      // for loop
	void *(*thdhandle[])(void *) = { // thread function pointer array
		reader_cond,
		reader_cond,
		reader_cond,
		writer_cond,
	};
	void *thdpara[] = { // thread paramater array
		"read cond 1",
		"read cond 2",
		"read cond 3",
		NULL,
	};
	const int THDNO = sizeof(thdhandle) / sizeof(thdhandle[0]);
	pthread_t thdid[THDNO];
	void *retval = NULL; // 接收线程返回值

	/*
	 * 创建THDNO个线程
	 */
	for (i = 0; i < THDNO; i++)
	{
		if (0 != pthread_create(&thdid[i], NULL, thdhandle[i], thdpara[i]))
		{
			error(0, errno, "NO. %d thread was created failed\n", i);
		}
	}

	/*
	 * 等待线程运行
	 */
	for (i = 0; i < THDNO; i++)
	{
		if (0 != pthread_join(thdid[i], &retval))
		{
			error(0, errno, "NO. %d thread was joined failed\n", i);
		}
		printf("threadid %lu return %d\n", (unsigned long int)thdid[i], (int)retval);
	}
}

/**
 * @函数说明：thd_sem_test 
 * 			  测试信号量
 */
void thd_sem_test()
{
	int i;      // for loop
	void *(*thdhandle[])(void *) = { // thread function pointer array
		reader_sem,
		reader_sem,
		reader_sem,
		writer_sem,
	};
	void *thdpara[] = { // thread paramater array
		"read sem 1",
		"read sem 2",
		"read sem 3",
		"writer sem",
		NULL,
	};
	const int THDNO = sizeof(thdhandle) / sizeof(thdhandle[0]);
	pthread_t thdid[THDNO];
	void *retval = NULL; // 接收线程返回值

	if (-1 == sem_init(&gmem.sem_r, 0, // 0 -- 线程使用信号量 1 -- 进程使用
				0))
	{
		error(0, errno, "sem_r failed\n");
	}
	if (-1 == sem_init(&gmem.sem_w, 0, 
				1))
	{
		error(0, errno, "sem_w failed\n");
	}

	/*
	 * 创建THDNO个线程
	 */
	for (i = 0; i < THDNO; i++)
	{
		if (0 != pthread_create(&thdid[i], NULL, thdhandle[i], thdpara[i]))
		{
			error(0, errno, "NO. %d thread was created failed\n", i);
		}
	}

	/*
	 * 等待线程运行
	 */
	for (i = 0; i < THDNO; i++)
	{
		if (0 != pthread_join(thdid[i], &retval))
		{
			error(0, errno, "NO. %d thread was joined failed\n", i);
		}
		printf("threadid %lu return %d\n", (unsigned long int)thdid[i], (int)retval);
	}

	sem_destroy(&gmem.sem_r);
	sem_destroy(&gmem.sem_w);
}

/**
 * @函数说明：thd_key_test 
 * 			  测试线程相关的key值
 */
void thd_key_test()
{
	int i;      // for loop
	void *(*thdhandle[])(void *) = { // thread function pointer array
		reader_key,
		reader_key,
		reader_key,
		writer_key,
	};
	void *thdpara[] = { // thread paramater array
		"read key 1",
		"read key 2",
		"read key 3",
		"write key",
		NULL,
	};
	const int THDNO = sizeof(thdhandle) / sizeof(thdhandle[0]);
	pthread_t thdid[THDNO];
	void *retval = NULL; // 接收线程返回值

	pthread_key_create(&gmem.key, destructor); // 创建线程相关的key值

	/*
	 * 创建THDNO个线程
	 */
	for (i = 0; i < THDNO; i++)
	{
		if (0 != pthread_create(&thdid[i], NULL, thdhandle[i], thdpara[i]))
		{
			error(0, errno, "NO. %d thread was created failed\n", i);
		}
	}

	/*
	 * 等待线程运行
	 */
	for (i = 0; i < THDNO; i++)
	{
		if (0 != pthread_join(thdid[i], &retval))
		{
			error(0, errno, "NO. %d thread was joined failed\n", i);
		}
		printf("threadid %lu return %d\n", (unsigned long int)thdid[i], (int)retval);
	}
}

/**
 * @函数说明：thd_project_test 
 * 			  模拟线程工程
 */
void thd_project_test()
{
	int i;      // for loop
	void *(*thdhandle[])(void *) = { // thread function pointer array
		thd_work,
		thd_work,
		thd_work,
		thd_work,
	};
	const int THDNO = sizeof(thdhandle) / sizeof(thdhandle[0]);
	thdinfo_t *pthdinfo;
	char cmd[16];

	pthdinfo = (thdinfo_t *)malloc(sizeof(thdinfo_t) * THDNO);

	pthread_key_create(&gmem.key, destructor); // 创建线程相关的key值

	/*
	 * 创建THDNO个线程
	 */
	for (i = 0; i < THDNO; i++)
	{
		pthread_mutex_init(&pthdinfo[i].mutex, NULL);
		pthread_cond_init(&pthdinfo[i].cond, NULL);
		sprintf(pthdinfo[i].buf, "data %d\n", i);
		if (0 != pthread_create(&pthdinfo[i].tid, NULL, thdhandle[i], pthdinfo + i))
		{
			error(0, errno, "NO. %d thread was created failed\n", i);
		}
	}

	while (1)
	{
		printf("puts your command:\n");
		/*fgets(cmd, 16, stdin); // 不获取换行符*/
		scanf("%s", cmd);
		switch (cmd[0])
		{
		case '1':
			pthread_cond_signal(&pthdinfo[0].cond);
			break;
		case '2':
			pthread_cond_signal(&pthdinfo[1].cond);
			break;
		case '3':
			pthread_cond_signal(&pthdinfo[2].cond);
			break;
		case '4':
			pthread_cond_signal(&pthdinfo[3].cond);
			break;
		case 'q':
			goto QUIT;
		default:
			break;
		}

		sleep(1);
	}

QUIT:
	/*
	 * 关闭线程
	 */
	for (i = 0; i < THDNO; i++)
	{
		pthread_cancel(pthdinfo[i].tid);
	}
	free(pthdinfo);  // 释放动态分配的空间
	pthdinfo = NULL; // 避免野指针
}

/**
 * @函数说明：reader
 * 			  线程处理函数
 *
 * @函数参数：arg
 *
 * @返回值：
 *          pthread_join接收的
 */
void *reader(void *arg)
{
	pthread_mutex_lock(&gmem.mutex);
	printf("read sleep 3\n");
	sleep(3);
	pthread_mutex_unlock(&gmem.mutex);
	pthread_exit((void *)EXIT_FAILURE);
	return NULL;
}

/**
 * @函数说明：writer 
 * 			  同上
 *
 * @函数参数：arg
 *
 * @返回值：
 */
void *writer(void *arg)
{
	pthread_mutex_lock(&gmem.mutex);
	printf("write sleep 3s\n");
	sleep(3);
	pthread_mutex_unlock(&gmem.mutex);
	pthread_exit((void *)EXIT_SUCCESS);
	return NULL;
}

/**
 * @函数说明：reader_cond 
 * 			  线程处理函数 
 *
 * @函数参数：arg
 *
 * @返回值：
 */
void *reader_cond(void *arg)
{
	pthread_mutex_lock(&gmem.mutex);	
	pthread_cond_wait(&gmem.cond, &gmem.mutex); // 等待条件并释放mutex锁
	printf("%s\n", (char *)arg);
	pthread_mutex_unlock(&gmem.mutex);

	return NULL;
}

/**
 * @函数说明：writer_cond 
 *
 * @函数参数：arg
 *
 * @返回值：
 */
void *writer_cond(void *arg)
{
	int i = 0;
	for (; i < 3; i++)
	{
		sleep(3);
		printf("writer cond called\n");
#if 1
		pthread_cond_signal(&gmem.cond); // pthread_cond_broadcast为广播
#else
		pthread_cond_broadcast(&gmem.cond);
#endif
	}
	return NULL;
}

void *reader_sem(void *arg)
{
	sem_wait(&gmem.sem_r);
	puts((char *)arg);
	sem_post(&gmem.sem_w);
	return NULL;
}

void *writer_sem(void *arg)
{
	int i = 0;
	for (; i < 3; i ++)
	{
		sem_wait(&gmem.sem_w);
		puts((char *)arg);
		sem_post(&gmem.sem_r);
	}
	return NULL;
}

void show_key_value()
{
	char *pval;
	pval = (char *)pthread_getspecific(gmem.key);
	printf("%s\n", pval);
}

void *reader_key(void *arg)
{
	if (0 != pthread_setspecific(gmem.key, arg))
	{
		error(0, errno, "%s-%d-%s failed\n", __func__, __LINE__, __FILE__);
		return (void *)EXIT_FAILURE;
	}
	show_key_value();

	return NULL;
}

void *writer_key(void *arg)
{
	if (0 != pthread_setspecific(gmem.key, arg))
	{
		error(0, errno, "%s-%d-%s failed\n", __func__, __LINE__, __FILE__);
		return (void *)EXIT_FAILURE;
	}
	show_key_value();

	return NULL;
}

void destructor(void *val)
{
	printf("destructor %s\n", (char *)val);
}

void *thd_work(void *arg)
{
	thdinfo_t *info = arg;	

	while (1)
	{
		pthread_mutex_lock(&info->mutex);
		pthread_cond_wait(&info->cond, &info->mutex);
		printf("thd_work %s", info->buf);
		pthread_mutex_unlock(&info->mutex);
	}
}
