#mini version need
cmake_minimum_required(VERSION 4.2.1)

#project name
project(test1)

#define source_directory variable
aux_source_directory(. SRC_LIST)

#execute independent file
add_executable(main ${SRC_LIST})

