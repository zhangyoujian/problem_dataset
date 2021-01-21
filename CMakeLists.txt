cmake_minimum_required(VERSION 3.5)
project(LeetCode)

# 设置编译选项
set(CMAKE_C_FLAGS "-O0 ${CMAKE_C_FLAGS}")
add_compile_options(-fPIC)
set(CMAKE_C_FLAGS "-g -lm ${CMAKE_C_FLAGS}")


set (INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set (OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/output/)
set (COMMON_DIR ${CMAKE_CURRENT_SOURCE_DIR}/common/)
set (PUB_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/pub/)

add_subdirectory(${COMMON_DIR})



