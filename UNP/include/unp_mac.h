/*
 modified unp.h file for mac os
*/
#ifndef __unp_h
#define __unp_h

#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include <arpa/inet.h>

#include <sys/types.h>

/*Socket()*/
#include <sys/socket.h>

/* pid_t fork exec */
#include <unistd.h>

/* sockaddr_in */
#include <netinet/in.h>

/* bzero */
#include <strings.h>

#define SERV_PORT  9877
#define SERV_PORT_STR "9877"
#define LISTENQ 1024 /* maximum number of client connection */
#define SA struct sockaddr

#endif
