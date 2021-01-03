cmake_minimum_required(VERSION 3.5)
project(LeetCode)

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -std=c++11")

set (INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set (OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/output/)
set (COMMON_DIR ${CMAKE_CURRENT_SOURCE_DIR}/common/)
set (PUB_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/pub/)

include_directories(${PUB_INC_DIR})
include_directories(${INCLUDE_DIR})
add_subdirectory (${COMMON_DIR})



