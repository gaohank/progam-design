#include "../../include/head.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/*
 * shmget shmctl shmop shmat
 * */
#include <sys/ipc.h>
#include <sys/shm.h>

/*
 * shm_open shm_unlink shm_overview
 * */
#include <sys/mman.h>
#include <sys/stat.h>	    /* For mode constants */
#include <fcntl.h>	    /* For O_* constants */
#include <sys/mman.h>   /* mmap */

int shm_posix_test()
{
	int fd;
	pid_t pid;
	struct traffic{
		int type;
		char buf[128];
	}*p_traffic;

	fd = shm_open("/home", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	if (-1 == fd) {
		error(0, errno, "shm_open failed");
		return -1;
	}

	ftruncate(fd, sizeof(struct traffic)); // 设置文件大小

	pid = fork();
	if (-1 == pid) {
		error(0, errno, "fork failed");
		return -1;
	} else if (0 == pid) {//子进程
		p_traffic = mmap(NULL, sizeof(struct traffic), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
		if (MAP_FAILED == p_traffic) {
			error(0, errno, "mmap failed");
			exit(1);
		}
		p_traffic->type = 1024;
		strcpy(p_traffic->buf, "this is shm_* test!");
		exit(0);
	} else {//父进程
		int status;
		waitpid(-1,   /* < -1 -- 任何子进程组ID和pid的绝对值相等的进程 
						 -1 -- 等待任何子进程
						 0 -- 等待任何子进程组ID和调用进程组ID相等的进程
						 >0 -- 等待子进程IP和pid值相等
						*/
				&status,
				0);   // WNOHANG -- 立即返回
		p_traffic = mmap(NULL, sizeof(struct traffic), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
		if (MAP_FAILED == p_traffic) {
			error(0, errno, "mmap failed");
			exit(1);
		}
		printf("status = %d\n", status);
		printf("%p\n", p_traffic);
		printf("type = %d\n", p_traffic->type);
		printf("buf = %s\n", p_traffic->buf);

		shm_unlink("/home");
	}

	return 0;
}
