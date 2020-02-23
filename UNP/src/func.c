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

void str_cli(FILE *fp, int sockfd){
  int maxfdp1, stdineof;
  fd_set rset;
  char buf[MAXLINE];
  int n;

  stdineof = 0;
  FD_ZERO(&rset);
  for(;;){
    if(stdineof == 0){
      FD_SET(fileno(fp), &rset);//fileno() checlk and reset stream status 
    }
    FD_SET(sockfd, &rset);
    maxfdp1 =fileno(fp)> sockfd?fileno(fp):sockfd+ 1;//the maximum descriptor
    select(maxfdp1, &rset, NULL, NULL,NULL);
    
    if (FD_ISSET(sockfd, &rset)){
      if((n = read(sockfd, buf, MAXLINE)) == 0){
        if(stdineof == 1){
          return;
        }else {
          printf("str_cli: server terminated prematurely"); 
        } 
        write(fileno(stdout), buf, n);
      } 
    } 
    
    if (FD_ISSET(fileno(fp), &rset)){
      if ((n = read(fileno(fp), buf, MAXLINE)) == 0){
        stdineof = 1;
        shutdown(sockfd, SHUT_WR);
        FD_CLR(fileno(fp), &rset);
        continue; 
      }
      write(sockfd, buf, n); 
    }   
  }
}
