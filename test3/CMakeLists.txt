#使用CMakeLists.txt所需的最低版本
cmake_minimum_required(VERSION 4.2.1)

#项目的名称
project(test3)

#扫描指定路径，将其所有的源文件都存到定义的变量中
aux_source_directory(路径 变量)

#引用变量，相比手动指定文件更加灵活高效
${变量}

#target，表示要生成目标产物，主要包含三类：可执行文件、动态/静态库文件，还有一些特殊的target暂时不用关心
#可以为target设置属性，如名字位置等，全局属性：为所有target设置属性，局部属性：单独为某些target设置属性

#生成可执行文件，需要指定依赖的源文件
add_executable(可执行文件 源文件...)




>>#windows平台默认指定位MSVC版本，可指定为MINGW版本


#变量除了可以存储文件，还可以表示某个或多个路径，CMake定义的变量有:
CMAKE_SOURCE_DIR：表示项目根目录
CMAKE_CURRENT_SOURCE_DIR：CMakeLists.txt所在目录，也表示当前目录(.)
EXECUTABLE_OUTPUT_PATH：表示所有可执行文件的输出位置，是全局变量
LIBRARY_OUTPUT_PATH：表示所有动态库文件的输出位置，是全局变量

#定义变量或重定向全局变量指向的路径
set(变量 路径...)


#设置任意对象的属性值(如变量、源文件、target等...)，一次只能设置一个属
#性，一般在开发中用的比较少，因为各对象都有专属的属性设置方法，暂不了解
set_property(TARGET 对象 PROPERTY 属性1 属性值1)

#设置某个target的属性值，一次可以设置多个属性
set_target_properties(target PROPERTIES 属性1 属性值1 属性2 属性值2 ...)

#若不设置target属性，target则会使用相应的内置全局变量作为默认输出路径，所以如果不设置，重定向
#全局变量就是在修改相关target的默认输出路径，若后续设置了某个target的属性则会覆盖原本的属性值
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib/dynamic)

#target常用的属性
属性 (Property)	作用 (What it does)	备注/专用命令
RUNTIME_OUTPUT_DIRECTORY	设置可执行文件（及 Windows 下的 DLL）的输出目录。	你之前用到的就是它
LIBRARY_OUTPUT_DIRECTORY	设置动态库（如 .so）的输出目录。	用于 SHARED 库
ARCHIVE_OUTPUT_DIRECTORY	设置静态库（如 .a）的输出目录。	用于 STATIC 库
OUTPUT_NAME	修改最终生成文件的名字（如让 app 生成 my_app）。	不改变 target 的逻辑名
CXX_STANDARD	指定该 target 使用的 C++ 标准（如 11, 14, 17）。	也可用 target_compile_features
POSITION_INDEPENDENT_CODE	是否生成位置无关代码（PIC），对动态库很重要。	常用于 SHARED 库
COMPILE_OPTIONS	为该 target 添加编译选项（如 -Wall）。	建议用 target_compile_options
LINK_OPTIONS	为该 target 添加链接选项。	建议用 target_link_options
DEFINE_SYMBOL	编译共享库时定义预处理器符号，默认是 target_EXPORTS。	用于处理 dllexport/dllimport
VERSION	指定共享库的版本号。	用于 SHARED 库
SOVERSION	指定共享库的 ABI 版本号。	用于 SHARED 库
INSTALL_RPATH	安装后二进制文件使用的 RPATH。	控制运行时库搜索路径


#指定所有target的头文件搜索路径(如：动态/静态库、可执行文件相关的源文件，编译时都会去指定目录下搜索)
include_directories(路径...)

#指定某个target的头文件搜索路径
target_include_directories(target 路径...)

#生成链接库文件，需要指定类型和依赖的源文件
#类型：shared为动态库 static为静态库
add_library(库文件 类型 源文件...)

#windows中的动态库还需要对应的导入库(.lib)，而Linux中不需要
#导入库包含各种符号声明，用来告知加载器去哪找，所以在生成动态库时
#还需要指定导入库的输出路径，而使用第三方动态库时

#为所有target指定依赖的链接库
link_libraries(链接库...)

#为某个target指定依赖的链接库
target_link_libraries(target 链接库...)

#寻找默认路径下指定的链接库，并将其保存到变量中(Linux库的检索路径：/usr/lib)
#适用于自动安装的第三方库(对于Linux会自动配置，但对于Windows一般需要手动配置)
find_library(变量 链接库...)

#寻找指定路径下指定的链接库并将其保存到变量，适用于手动配置的第三方或自定义库
#注意引用变量时的语法，以及库命名规范(命名时lib和后缀不可省略，查找使用时可省)
find_library(变量 链接库... PATHS 链接库路径...)