cmake_minimum_required(VERSION 4.2.1)
project(test4)

aux_source_directory(${CMAKE_SOURCE_DIR}/src SRC_LIST)
add_executable(test4_main ${SRC_LIST})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

set_target_properties(
    test4_main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_NAME "TEST4"
)

set(HEAD_LIST ${CMAKE_SOURCE_DIR}/include)
include_directories(${HEAD_LIST})
target_include_directories(test4_main PRIVATE ${CMAKE_SOURCE_DIR})

#windows平台生成静态库(gcc移植版)
add_library(sub STATIC ${CMAKE_SOURCE_DIR}/src/sub.cpp)
set_target_properties(
    sub PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/static#静态库输出路径
)

#windows平台生成动态库(gcc移植版)
add_library(add SHARED ${CMAKE_SOURCE_DIR}/src/add.cpp)
set_target_properties(
    add PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/dynamic#动态库输出路径
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/dynamic#导入库输出路径
    WINDOWS_EXPORT_ALL_SYMBOLS ON                           #强制生成导入库
)

#链接cmake生成的动态库
target_link_libraries(test4_main sub add)