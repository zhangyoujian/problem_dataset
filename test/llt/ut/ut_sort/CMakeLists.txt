cmake_minimum_required(VERSION 3.5)
project(ut_sort)

# 设置编译选项
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -Wall -std=c++11")


set (GTEST_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../gtest/)

set (GTEST_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../gtest/include/)
include_directories(${GTEST_INC_DIR})

set (GTEST_INC_DIR_INNER ${CMAKE_CURRENT_SOURCE_DIR}/../../../gtest/include/internal/)
include_directories(${GTEST_INC_DIR_INNER})

set (OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../output/)
set (OUTPUT_LIBRARY ${OUTPUT_DIR}/lib/)
link_directories(${OUTPUT_LIBRARY})

set (COMMON_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../common/)
set (COMMON_INC_DIR ${COMMON_DIR}/algorithm/)
include_directories(${COMMON_INC_DIR})

set (PUB_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../pub/)
include_directories(${PUB_INC_DIR})

aux_source_directory(${GTEST_SRC_DIR} GTEST_SRC_LIST)
aux_source_directory(. SRC_LIST)

# 添加链接库
link_libraries(common gtest pthread)

# 编译生成可执行文件
add_executable(ut_sort ${SRC_LIST} ${GTEST_SRC_LIST})

install(
    TARGETS ut_sort
    RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}
)

