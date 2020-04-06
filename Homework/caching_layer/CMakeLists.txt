cmake_minimum_required(VERSION 3.3.2)
project(cache CXX)

include_directories("../include")
include_directories("./")
add_executable(cache cache.cpp)
add_executable(cache_client cache_client.cpp)
