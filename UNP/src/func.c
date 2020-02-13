#include "unp_mac.h"

void err_sys(const char* input){
  perror(input);
  exit(1);
}

void str_echo(int sockfd){
  ssize_t n;
  char buf[MAXLINE];
  while(1){
    if((n=read(sockfd,buf,MAXLINE)) > 0){
      printf("MESSAGE RECEIVED: %s\n",buf);
      write(sockfd, buf, MAXLINE); 
    }
    if(n > 0|| errno != EINTR){
      break;
    }
    if(n < 0 && errno != EINTR){
      err_sys("str_echo: read error");
      
    }
  }
  printf("done\n");
}
