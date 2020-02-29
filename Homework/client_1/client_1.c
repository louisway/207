#include "unp_mac.h"

int main(int argc, char **argv){
  int sockfd, n;
  //char *ip_str = "94.142.241.111";
  char *ip_str = "2a02:898:17:8000::42";
  char recvline[MAXLINE+1];
  //struct sockaddr_in servaddr;
  struct sockaddr_in6 servaddr;
  if((sockfd = socket(AF_INET6,SOCK_STREAM,0)) < 0){
  //if((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0){
    printf("socket error"); 
    return 0;
  }

  bzero(&servaddr, sizeof(servaddr));
  //servaddr.sin_family = AF_INET;
  servaddr.sin6_family = AF_INET6;
  /*
    starwars : port 23
  */
  servaddr.sin6_port = htons(23);
  if(inet_pton(AF_INET6, ip_str,&servaddr.sin6_addr) <= 0){
  //if(inet_pton(AF_INET6, ip_str,&servaddr.sin_addr) <= 0){
    //err_quit("inet_pton error for %s",argv[1]); 
    printf("inet_pton error for %s", ip_str);
  }
 
  for(;;){ 
    if(connect(sockfd,(SA *)&servaddr, sizeof(servaddr))<0){
      printf("connect error"); 
    }
    while( (n=read(sockfd,recvline,MAXLINE))>0){
      recvline[n] = 0;
      printf("%s", recvline); 
    }
    if (n<0){ 
      printf("read error");
      break;
     }
  }
  close(sockfd);
}
