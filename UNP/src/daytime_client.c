#include "unp_mac.h"

int main(int argc, char **argv){
  int sockfd, n;
  char *ip_str = "192.168.1.9";
  char recvline[MAXLINE+1];
  struct sockaddr_in servaddr;
  if((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0){
    printf("socket error"); 
    return 0;
  }

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(SERV_PORT);
  if(inet_pton(AF_INET, ip_str,&servaddr.sin_addr) <= 0){
    //err_quit("inet_pton error for %s",argv[1]); 
    printf("inet_pton error for %s", ip_str);
  }
  
  if(connect(sockfd,(SA *)&servaddr, sizeof(servaddr))<0){
    printf("connect error"); 
  }
  while( (n=read(sockfd,recvline,MAXLINE))>0){
    recvline[n] = 0;
    printf("%s", recvline); 
  }
  if (n<0) printf("read error");
  close(sockfd);
}
