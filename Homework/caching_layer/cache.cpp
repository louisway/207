#include "unp_mac.h"
#include <time.h>
#include <unordered_map>
#include <string>
#include <iostream>

std::string get_variable(std::string commands, int pos){
  int start_pos = pos;
  while(start_pos < commands.length()&&commands[start_pos] == ' '){
    ++start_pos; 
  }
  int length = 0;
  while(start_pos + length < commands.length()&&commands[start_pos+length] != ' '){
    ++length; 
  }
  return commands.substr(start_pos,length);
}

std::string get_command(std::string commands){
   /* 
     1.set variable 
      set variable_name
      value
      return stored or not or 
     2. check variable
      return value or "not exist"
     3. delete variable
      return not exist or deleted
  */ 
  if(commands.length() > 4 && commands.substr(0,3) == "set"){
    return "set"; 
  }else if(commands.length() > 6 && commands.substr(0,5) == "check"){
    return "check"; 
  }else if(commands.length() > 7 && commands.substr(0,6) == "delete"){
    return "delete"; 
  }else{
     return "command is not valid";
  }
}

int main(int argc, char **argv){
  std::unordered_map<std::string,std::string> cache;
  int listenfd, connfd;
  char *ip_str = "127.0.0.1";
  struct sockaddr_in servaddr;
  char buff[MAXLINE];
  time_t ticks;
  listenfd = socket(AF_INET,SOCK_STREAM,0);
  
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  //servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  inet_pton(AF_INET,ip_str,&servaddr.sin_addr);
  servaddr.sin_port = htons(CACHE_PORT);
  
  bind(listenfd, (SA*) &servaddr, sizeof(servaddr));
  
  listen(listenfd, LISTENQ);
  //printf("ip addr: %x\n", htonl(INADDR_ANY));
  //printf("ip addr: %x\n", ntohl(servaddr.sin_addr.s_addr));
  char buf[MAXLINE];
  for(;;) {
      connfd = accept(listenfd, (SA*) NULL, NULL);
      std::string result = "Error!";
      ssize_t n;
      if((n=read(connfd,buf,MAXLINE)) > 0){
        std::cout << "Message Received!" << std::endl;
        std::string command(buf);
        std::string instruction = get_command(command);
        if(instruction == "set"){
          std::string var = get_variable(command,3);
          if((n=read(connfd,buf,MAXLINE))>0){
            std::string value(buf);
            cache[var] = value;
            result = "STORED"; 
          }
          if(n < 0 && errno != EINTR){
            result = "Please try again!"; 
          } 
        }else if(instruction == "check"){
          std::string var = get_variable(command,5);
          if(cache.find(var)==cache.end()){
            result = "Not Exist!"; 
          }else{
            result = cache[var];
          }
        }else if(instruction == "delete"){
          std::string var = get_variable(command,6);
          if(cache.find(var)==cache.end()){
            result = "Not Exist!"; 
          }else{
            cache.erase(var);
            result = "DELETED";
          }
        }else{
           result = "command is not valid";
        }
         
      }
      strcpy(buf,result.c_str());
      write(connfd, buf, MAXLINE);
      close(connfd);
  }  
}
