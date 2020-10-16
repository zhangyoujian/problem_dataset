cmake_minimum_required(VERSION 2.8.1)
project(LeetCode)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -Wall -std=c++11")

set (INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${INCLUDE_DIR})

set (SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/)

aux_source_directory(. SRC_MAIN_LIST)
aux_source_directory(${SOURCE_DIR} SRC_LIST)

# 编译生成可执行文件
add_executable(leet_code ${SRC_MAIN_LIST} ${SRC_LIST})

install(TARGET leet_code
    RUNTIME DESTINATION bin
)

