cmake_minimum_required(VERSION 3.5)
project(LeetCode)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -Wall -std=c++11")

set (INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set (OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/output/)
set (COMMON_DIR ${CMAKE_CURRENT_SOURCE_DIR}/common/)
set (PUB_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/pub/)

include_directories(${PUB_INC_DIR})
include_directories(${INCLUDE_DIR})
add_subdirectory (${COMMON_DIR})



