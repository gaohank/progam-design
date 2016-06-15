#include "../../include/head.h"
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void do_timer(sigval_t val)
{
	/*printf("buf = %s, len = %d\n", (char *)val.sival_ptr, val.sival_int);*/
	printf("buf = %s\n", (char *)val.sival_ptr);
}

/**
 * @函数说明：timer_by_thread 
 * 			  使用线程处理显示定时器
 */
void timer_by_thread()
{
	struct sigevent evt;
	timer_t timerid;
	char buf[] = "helloworld";
	struct itimerspec timeval, oldval;

	evt.sigev_value.sival_ptr = buf; // 给线程处理函数传入的参数
	evt.sigev_notify = SIGEV_THREAD; // 当定时到时，将sigev_notify_function作为线程处理函数执行
	evt.sigev_notify_function = do_timer; // 定义定时器处理函数

	/* 获得定时器ID，注册定时器事件 */
	if (0 != timer_create(
				CLOCK_REALTIME,  // 定时器测量时间参数，根据系统实时时钟
				&evt, 			 // 指定定时到达时的处理
				&timerid))
	{
		error(EXIT_FAILURE, errno, "timer_create");
	}

	/* 设置定时器定时时间, interval为间隔 */
	timeval.it_interval.tv_sec = 1;
	timeval.it_interval.tv_nsec = 50 * 1000000; // 50ms

	/* 设置第一次触发定时器的时间 */
	timeval.it_value.tv_sec = 3;
	timeval.it_value.tv_nsec = 0; // 0ns

	/* 设置并开启POSIX定时器 */
	if (0 != timer_settime(
				timerid, 
				0, 	// 指定it_value触发时间是系统时间的相对值
					// 1及TIMER_ABSTIME时，为一个绝对值，系统时间达到该值时触发
				&timeval, 
				&oldval)) // oldval可以为NULL，不为空时，返回上一次定时间隔和下次触发的时间
	{
		error(EXIT_FAILURE, errno, "timer_settime");
	}

	printf("第一次启动3.0s，定时时间1.050s\n");

	sleep(10);
	printf("old interval sec %ld\n", oldval.it_interval.tv_sec);
	printf("old interval nsec %ld\n", oldval.it_interval.tv_nsec);
	printf("old value sec %ld\n", oldval.it_value.tv_sec);
	printf("old value nsec %ld\n", oldval.it_value.tv_nsec);

	timer_delete(timerid); // 删除定时器
}

/**
 * @函数说明：timer_stop_by_thread 
 * 			  关闭定时器
 */
void timer_stop()
{
	struct sigevent evt;
	timer_t timerid;
	char buf[] = "helloworld",
		 buff[10];
	struct itimerspec timeval;

	/*evt.sigev_value.sival_int = strlen(buf);*/
	evt.sigev_value.sival_ptr = buf; // 给线程处理函数传入的参数
	evt.sigev_notify = SIGEV_THREAD; // 当定时到时，将sigev_notify_function作为线程处理函数执行
	evt.sigev_notify_function = do_timer; // 定义定时器处理函数

	/* 获得定时器ID，注册定时器事件 */
	if (0 != timer_create(
				CLOCK_REALTIME,  // 定时器测量时间参数，根据系统实时时钟
				&evt, 			 // 指定定时到达时的处理
				&timerid))
	{
		if (errno == EEXIST)
		{
			printf("the timer is already exist\n");
		}
		else
		{
			error(EXIT_FAILURE, errno, "timer_create");
		}
	}

RESTART:
	/* 设置定时器定时时间, interval为间隔 */
	timeval.it_interval.tv_sec = 1;
	timeval.it_interval.tv_nsec = 0;

	/* 设置第一次触发定时器的时间 */
	timeval.it_value.tv_sec = 1;
	timeval.it_value.tv_nsec = 0; // 0ns

	/* 设置并开启POSIX定时器 */
	if (0 != timer_settime(timerid, 0, &timeval, NULL))
	{
		error(EXIT_FAILURE, errno, "timer_settime");
	}

	printf("启动1s，定时时间1s\n");

STOP:
	printf("print stop to stop the timer\n");
	scanf("%s", buff);

	if (strcmp(buff, "stop"))
	{
		goto STOP;
	}
	/* 关闭定时器 */
	timeval.it_value.tv_sec = 0;
	timeval.it_value.tv_nsec = 0;
	timer_settime(timerid, 0, &timeval, NULL);

QUIT:
	printf("print \"quit\" to quit test, print \"restart\" to restart\n");
	scanf("%s", buff);

	if (0 == strcmp(buff, "restart"))
	{
		goto RESTART;
	}
	else if (strcmp(buff, "quit"))
	{
		goto QUIT;
	}

	timer_delete(timerid); // 删除定时器
}
