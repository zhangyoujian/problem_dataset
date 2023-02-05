project(leetcode)

include_directories(${INCLUDE_DIR}/leetcode/)

set(OUTPUT_LIB_PATH ${OUTPUT_DIR}/lib/)

aux_source_directory(${INCLUDE_DIR}/leetcode/ SRC_LIST)

# 编译生成链接库
add_library(leetcode SHARED ${SRC_LIST})

target_link_libraries(leetcode pthread)

install(
    TARGETS leetcode
    LIBRARY DESTINATION ${OUTPUT_LIB_PATH}
)





