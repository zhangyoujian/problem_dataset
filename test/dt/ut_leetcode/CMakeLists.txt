cmake_minimum_required(VERSION 3.5)
project(ut_leetcode)

# 设置编译选项
set(CMAKE_CXX_FLAGS "-O0 ${CMAKE_CXX_FLAGS}")
add_compile_options(-fPIC)
set(CMAKE_CXX_FLAGS "-g -lm ${CMAKE_CXX_FLAGS}")

# 添加gtest 库文件
set (GTEST_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../gtest/lib)
link_directories(${GTEST_LIB_PATH})
link_libraries(gtest_main.a gtest.a)

set (GTEST_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../gtest/include/)
include_directories(${GTEST_INC_DIR})

set (PUB_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../pub/)
include_directories(${PUB_INC_DIR})

set (OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../output/)
set (OUTPUT_LIB_PATH ${OUTPUT_DIR}/lib/)

set (INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../include/)


set (LEETCODE_INC_DIR ${INCLUDE_DIR}/leetcode/)
include_directories(${LEETCODE_INC_DIR})

link_directories(${OUTPUT_LIB_PATH})

aux_source_directory(. SRC_LIST)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

# 编译生成可执行文件
add_executable(ut_leetcode ${SRC_LIST})

# 添加链接库
target_link_libraries(ut_leetcode leetcode pthread)


