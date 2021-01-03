cmake_minimum_required(VERSION 3.5)
project(ut_sort)

# 设置编译选项
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -Wall -std=c++11")

set (OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../output/)
set (COMMON_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../common/)
set (PUB_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../pub/)
set (OUTPUT_LIBRARY ${OUTPUT_DIR}/lib/)

include_directories(${COMMON_DIR})
include_directories(${PUB_INC_DIR})

link_directories(${OUTPUT_LIBRARY})

aux_source_directory(. SRC_LIST)

# 添加链接库
link_libraries(common)

# 编译生成可执行文件
add_executable(ut_sort ${SRC_LIST})



