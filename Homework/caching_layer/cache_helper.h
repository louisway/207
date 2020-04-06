#include "unp_mac.h"
#include <iostream>
#include <string>

#ifndef CACHE_HELPER
#define CACHE_HELPER

class cache_client{
  private:
    std::string ip_str;
    int sockfd;
    int n; 
    char recvline[MAXLINE+1];
    char buf[MAXLINE];
    struct sockaddr_in servaddr;
  public:
    cache_client():ip_str("127.0.0.1"){
      reset();      
    }

    ~cache_client(){
      close(sockfd);
    }

    void close_conn(){
      close(sockfd);    
    }
 
    void reset(){
      if((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0){
        printf("socket error"); 
      }
      bzero(&servaddr, sizeof(servaddr));
      servaddr.sin_family = AF_INET;
      servaddr.sin_port = htons(CACHE_PORT);
      if(inet_pton(AF_INET, ip_str.c_str(),&servaddr.sin_addr) <= 0){
         std::cout << "inet_pton error for " << ip_str << std::endl; 
      }
    }

    std::string set(std::string variable,std::string value){
      reset();
      if(connect(sockfd,(SA *)&servaddr, sizeof(servaddr))<0){
        return "connect error"; 
      }
      std::string command = "set " + variable;
      strcpy(buf, command.c_str());
      write(sockfd, buf, MAXLINE);
      strcpy(buf,value.c_str());
      write(sockfd, buf, MAXLINE);   
      if( (n=read(sockfd,recvline,MAXLINE))>0){
        recvline[n] = 0;
        return std::string(recvline); 
      } 
      if (n<0){ 
        return "read error";
      }
      return "failed"; 
    }

    std::string check(std::string variable){
      reset();
      if(connect(sockfd,(SA *)&servaddr, sizeof(servaddr))<0){
        return "connect error"; 
      }
      std::string command = "check " + variable;
      strcpy(buf, command.c_str());
      write(sockfd, buf, MAXLINE);
      while( (n=read(sockfd,recvline,MAXLINE))>0){
        recvline[n] = 0;
        return std::string(recvline); 
      } 
      if (n<0){ 
        return "read error";
      }
      return "failed"; 
    }

    std::string del(std::string variable){
      reset();
      if(connect(sockfd,(SA *)&servaddr, sizeof(servaddr))<0){
        return "connect error"; 
      }
      std::string command = "delete " + variable;
      strcpy(buf, command.c_str());
      write(sockfd, buf, MAXLINE);
      while( (n=read(sockfd,recvline,MAXLINE))>0){
        recvline[n] = 0;
        return std::string(recvline); 
      } 
      if (n<0){ 
        return "read error";
      }
      return "failed"; 
    }

};
#endif
