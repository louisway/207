#include  "unp_mac.h"

/* verified */
#include <arpa/inet.h>


/* verified */
#include <sys/socket.h>

/* verified */
#include <sys/select.h>

/* verified */
#include <unistd.h>

/* verified */
#include <netinet/in.h>

/* verified */
#include <strings.h>

/**
  TEST PROGRAM for some functions
**/

void test_inet_aton(){
/*
  verified
*/
  char * input = "206.168.112.96";
  struct in_addr nsaddr;
  int output = inet_aton(input,&nsaddr);
  printf("%ul\n",nsaddr.s_addr);
}

void test_bzero_strings(){
/* verified */
  struct sockaddr_in servaddr;
  bzero(&servaddr,sizeof(servaddr));
}

int main(int argc, char **argv){
  test_inet_aton();
  test_bzero_strings();
}
