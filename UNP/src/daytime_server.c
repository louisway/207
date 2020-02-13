#include "unp_mac.h"
#include <time.h>

int main(int argc, char **argv){
  int listenfd, connfd;
  char *ip_str = "192.168.1.9";
  struct sockaddr_in servaddr;
  char buff[MAXLINE];
  time_t ticks;
  listenfd = socket(AF_INET,SOCK_STREAM,0);
  
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  //servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  inet_pton(AF_INET,ip_str,&servaddr.sin_addr);
  servaddr.sin_port = htons(SERV_PORT);
  
  bind(listenfd, (SA*) &servaddr, sizeof(servaddr));
  
  listen(listenfd, LISTENQ);
  printf("ip addr: %x\n", htonl(INADDR_ANY));
  printf("ip addr: %x\n", ntohl(servaddr.sin_addr.s_addr));

  for(;;) {
      connfd = accept(listenfd, (SA*) NULL, NULL);
      ticks = time(NULL);
      snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
      write(connfd, buff, strlen(buff));
      close(connfd);
  }  
}
