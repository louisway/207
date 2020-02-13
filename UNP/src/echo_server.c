#include "unp_mac.h"
#include <time.h>

int main(int argc, char **argv){
  int listenfd, connfd;
  pid_t childpid;
  socklen_t clilen;
  char *ip_str = "192.168.1.9";
  struct sockaddr_in cliaddr, servaddr;
  listenfd = socket(AF_INET, SOCK_STREAM, 0);/* Create Socket, AF_INET:IPV4*/
  bzero(&servaddr, sizeof(servaddr));/* reset servaddr to zero */
  servaddr.sin_family = AF_INET;
  //servaddr.sin_addr.s_addr = htonl(INADDR_ANY);/* htonl host to network byte ; INADDR_ANY means the ip is not specified*/
  if(inet_pton(AF_INET, ip_str, &servaddr.sin_addr) <= 0){
    printf("inet_pton error for %s", ip_str); 
  }
  servaddr.sin_port = htons(SERV_PORT);
  bind(listenfd, (SA *) &servaddr, sizeof(servaddr));
  listen(listenfd, LISTENQ);

  for (;;) {
    clilen = sizeof(cliaddr);
    printf("Listening\n");
    connfd = accept(listenfd, (SA*) &cliaddr, &clilen);
    
    if( (childpid = fork()) == 0){
       close(listenfd);
       str_echo(connfd);
       exit(0); 
    } 
    close(connfd);
  }
}
