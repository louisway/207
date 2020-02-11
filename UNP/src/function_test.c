#include  "unp_mac.h"
#include <arpa/inet.h>
/**
  TEST PROGRAM for some functions
**/
void test_inet_aton(){
  char * input = "206.168.112.96";
  struct in_addr nsaddr;
  int output = inet_aton(input,&nsaddr);
  printf("%ul\n",nsaddr.s_addr);
}

int main(int argc, char **argv){
  test_inet_aton();
}
