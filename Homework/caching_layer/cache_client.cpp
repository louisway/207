#include "unp_mac.h"
#include "cache_helper.h"
#include <iostream>
#include <string>

int main(int argc, char **argv){
  cache_client test; 
  std::cout<< test.check("paris")<<std::endl;
  test.close_conn();
  std::cout<< test.set("paris", "cloudy")<<std::endl;
  test.close_conn();
  std::cout<< test.check("paris")<<std::endl;
  test.close_conn();
  std::cout<< test.del("paris")<<std::endl;
  test.close_conn();
  std::cout<< test.check("paris")<<std::endl;
  test.close_conn();
}
