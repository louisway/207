cmake_minimum_required(VERSION 3.3.2)
project(UNP C)

find_library(sk Socket)
find_library(k Sket)
include_directories("./include")
add_subdirectory(./src)
