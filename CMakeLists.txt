cmake_minimum_required(VERSION 3.23)
project(libosmio)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE HEADER ${CMAKE_SOURCE_DIR}/src/*.h)

add_library(libosmio ${HEADER} library.h library.cpp)
