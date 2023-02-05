project(leetcode_main)

include_directories(${PUB_INC_DIR})
include_directories(${COMMON_DIR}/algorithm/include)
include_directories(${INCLUDE_DIR}/dataset)
include_directories(${INCLUDE_DIR}/leetcode)

set(OUTPUT_LIB_PATH ${OUTPUT_DIR}/lib/)
set(OUTPUT_BIN_PATH ${OUTPUT_DIR}/bin/)

link_directories(${OUTPUT_LIB_PATH})
aux_source_directory(${SOURCE_DIR} SRC_LIST)

# 编译生成可执行文件
add_executable(leetcode_main ${SRC_LIST})

# 添加链接库
target_link_libraries(leetcode_main algorithm dataset leetcode pthread)

install(
    TARGETS leetcode_main
    RUNTIME DESTINATION ${OUTPUT_BIN_PATH}
)





