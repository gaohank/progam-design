#include "common.h"

int tcp_demo() 
{
	int sockfd;
	struct sockaddr_in seraddr;
	char buff[BUFF_SIZE];
	pid_t pid;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (-1 == sockfd) {
		error(0, errno, "sockfd");
		return -1;
	}

	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(CLIENT_PORT); // 主机字节序转为网络字节序
	seraddr.sin_addr.s_addr = inet_addr(CLIENT_ADDR); // 网络地址in_addr，uint32_t

	pid = fork();

	if (0 > pid) {
		error(0, errno, "fork");
	} else if (0 == pid) {// 子进程

		/*connect()*/

		strcpy(buff, "helloworld");
		if (-1 == send(sockfd, buff, strlen(buff) + 1, 0)) {
			error(0, errno, "send");
		}

		memset(buff, 0, BUFF_SIZE);
		if (-1 == recv(sockfd, buff, BUFF_SIZE, 0)) {
			error(0, errno, "recv");
		}

		printf("client recv %s\n", buff);
		exit(1);
	} else {// 父进程

		if (-1 == bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr))) {
			error(0, errno, "bind");
			return -1;
		}

		if (-1 == listen(sockfd, 10)) {
			error(0, errno, "listen");
			return -1;
		}

		int connfd;
		if (-1 == (connfd = accept(sockfd, NULL, NULL))) {
			error(0, errno, "listen");
			return -1;
		}

		if (-1 == recv(connfd, buff, BUFF_SIZE, 0)) {
			error(0, errno, "recv");
		}
		printf("server recv %s\n", buff);
		strcat(buff, "---test");
		if (-1 == send(connfd, buff, strlen(buff) + 1, 0)) {
			error(0, errno, "send");
		}
	}

	close(sockfd);

	return 0;
}
