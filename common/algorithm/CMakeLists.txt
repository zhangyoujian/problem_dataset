cmake_minimum_required(VERSION 3.5)
project(common)

set(OUTPUT_LIBRARY ${OUTPUT_DIR}/lib/)

aux_source_directory(. SRC_LIST)

# 编译生成链接库
add_library(common SHARED ${SRC_LIST})

install(
    TARGETS common
    LIBRARY DESTINATION ${OUTPUT_LIBRARY}
)

