cmake_minimum_required(VERSION 4.2.1)
project(test5)

set(LIBS ${CMAKE_SOURCE_DIR}/lib/static ${CMAKE_SOURCE_DIR}/lib/dynamic)

aux_source_directory(${CMAKE_SOURCE_DIR}/src SRC_LIST)
add_executable(test5_main ${SRC_LIST})
set_target_properties(
    test5_main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    OUTPUT_NAME "TEST5"
)

set(HEAD_LIST ${CMAKE_SOURCE_DIR}/include)
target_include_directories(test5_main PRIVATE ${HEAD_LIST})

target_link_directories(test5_main PRIVATE ${LIBS})
target_link_libraries(test5_main add sub)