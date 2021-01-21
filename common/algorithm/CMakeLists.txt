project(algorithm)

include_directories(${PUB_INC_DIR})
include_directories(${COMMON_DIR}/algorithm/include)

set(OUTPUT_LIB_PATH ${OUTPUT_DIR}/lib/)

aux_source_directory(${COMMON_DIR}/algorithm/src SRC_LIST)

# 编译生成链接库
add_library(algorithm SHARED ${SRC_LIST})

target_link_libraries(algorithm pthread)

install(
    TARGETS algorithm
    LIBRARY DESTINATION ${OUTPUT_LIB_PATH}
)





