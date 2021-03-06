#include  "unp_mac.h"

/**
  For some headers are not compatiable in MAC OS, so I commented out unp.h.
  Only config.h and stdio.h are necessary for this program
**/

int main(int argc, char **argv){
  union {
      short s;
      char c[sizeof(short)];
  } un;
  un.s = 0x0102;
  printf("%s: ", CPU_VENDOR_OS);
  if (sizeof(short) == 2) {
    if (un.c[0] == 1 && un.c[1] == 2){
        printf("big-endian\n"); 
    }else if (un.c[0] == 2 && un.c[1] == 1){
        printf("little-endian\n");
    }else{
        printf("unknown\n");
    } 
  } else{
        printf("sizeof(short) = %lu\n", sizeof(short)); 
    } 
   
}
