project(common)

include_directories(${PUB_INC_DIR})
include_directories(${COMMON_DIR}/algorithm/)

set(OUTPUT_LIB_PATH ${OUTPUT_DIR}/lib/)

aux_source_directory(${COMMON_DIR}/algorithm/ SRC_LIST)

# 编译生成链接库
add_library(common SHARED ${SRC_LIST})

target_link_libraries(common pthread)

install(
    TARGETS common
    LIBRARY DESTINATION ${OUTPUT_LIB_PATH}
)





