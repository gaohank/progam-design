#ifndef __COMMON_H__
#define __COMMON_H__

#include "../../include/head.h"
#include <sys/types.h>	       /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h> 	// sockaddr_in
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 10000
#define CLIENT_PORT 20000
#define SERVER_ADDR "192.168.8.193"
#define CLIENT_ADDR "192.168.8.193"

#define BUFF_SIZE 1024

#endif
