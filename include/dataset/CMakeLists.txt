project(dataset)

include_directories(${INCLUDE_DIR}/dataset/)

set(OUTPUT_LIB_PATH ${OUTPUT_DIR}/lib/)

aux_source_directory(${INCLUDE_DIR}/dataset/ SRC_LIST)

# 编译生成链接库
add_library(dataset SHARED ${SRC_LIST})

target_link_libraries(dataset pthread)

install(
    TARGETS dataset
    LIBRARY DESTINATION ${OUTPUT_LIB_PATH}
)





