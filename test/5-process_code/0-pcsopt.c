#include "../../include/head.h"
#include <unistd.h> // pid_t fork(void)
#include <sys/types.h>
#include <sys/wait.h> // pid_t wait(int *status)

void pcs_wait_test()
{
	pid_t pid, ret;
	int status;
	char buf[128];

	pid = fork();

	if (0 == pid) { // 子进程
		scanf("%s", buf);
		puts("child process exited\n");
		exit(0);
	} else if (0 < pid) { // 父进程
		ret = wait(&status);
		if (-1 == ret)
		{
			error(EXIT_FAILURE, errno, "wait failed\n");
		}
		printf("the child pid is %d\n", pid);
		printf("the exit pid is %d\n", ret);
		printf("the status is %d\n", status);
		if (WIFEXITED(status)) { // 子进程正常退出
			puts("exit");
		}
		if (WIFSIGNALED(status)) { // 通过信号使子进程推出
			puts("kill");
		}
	} else {
		error(EXIT_FAILURE, errno, "fork failed\n");
	}
}

void pcs_waitpid_test()
{
	pid_t pid, ret;
	int status;
	char buf[128];

	pid = fork();
	if (0 == pid) { // 子
		scanf("%s", buf);
		puts("child process exited\n");
		exit(2);
	} else if (0 < pid) { // 父
		ret = waitpid(pid, &status, 0);
		printf("child pid = %d\nwait exit status = %d\n", ret, WEXITSTATUS(status));
	} else {
		error(EXIT_FAILURE, errno, "fork failed\n");
	}
}

void pcs_zombie_test()
{
	pid_t pid;
	char buf[128];

	/*signal(SIGCHLD, SIG_IGN);*/

	pid = fork();

	/* 父进程调用wait或者处理SIGCHLD时，子进程正常退出
	 * 否则，子进程成为僵尸进程
	 * */
	if (0 == pid) { // 子
		printf("child process pid=%d exit\n", getpid());
		exit(0);
	} else if (0 < pid) { //父
		printf("print any word to quit\n");
		scanf("%s", buf);
	} else {
		error(EXIT_FAILURE, errno, "fork failure\n");
	}
}

/**
 * @函数说明：pcs_orphan_test 
 * 			  如果父进程先于子进程退出，则子进程退出后，成为孤儿进程
 */
void pcs_orphan_test()
{
	pid_t pid;
	char buf[128];

	pid = fork();

	/* 父进程调用wait或者处理SIGCHLD时，子进程正常退出
	 * 否则，子进程成为僵尸进程
	 * */
	if (0 == pid) { //子
		printf("child process pid=%d\n", getpid());
		printf("print any word to quit\n");
		scanf("%s", buf);
		exit(0);
	} else if (0 < pid) { //父
		printf("father process quit\n");
		sleep(10);
		exit(0);
	} else {
		error(EXIT_FAILURE, errno, "fork failure\n");
	}
}
