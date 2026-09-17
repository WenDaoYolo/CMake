#生成时CMake所需的最低版本号
cmake_minimum_required(VERSION 4.2.1)

#项目名称
project(test2)

#定义源文件目录变量
aux_source_directory(${CMAKE_SOURCE_DIR}/src SRC_LIST)

#指定可执行文件依赖的源文件
add_executable(test2_main ${SRC_LIST})

#指定所需头文件的所在目录
include_directories(${CMAKE_SOURCE_DIR}/include)

#指定可执行文件的输出目录
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)