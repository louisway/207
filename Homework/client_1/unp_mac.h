/*
 modified unp.h file for mac os
*/
#ifndef __unp_h
#define __unp_h

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

#include <sys/types.h>
#include <sys/select.h>
#include <poll.h>
/*Socket()*/
#include <sys/socket.h>

/* pid_t fork exec */
#include <unistd.h>
#include <errno.h>

/* sockaddr_in */
#include <netinet/in.h>

/* bzero */
#include <strings.h>

#define SERV_PORT  9877
#define SERV_PORT_STR "9877"
#define LISTENQ 1024 /* maximum number of client connection */
#define SA struct sockaddr
#define MAXLINE 10000

void str_echo(int sockfd);
void err_sys(const char* input);
void str_cli(FILE *fp, int sockfd);
#endif
