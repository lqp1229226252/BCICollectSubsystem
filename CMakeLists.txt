## 库的cmake模板
## 基本上修改project和target_link_libraries
cmake_minimum_required(VERSION 3.5)

#设置库的名字
project(FTP)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#找Qt的字库，类似Qt+=
find_package(Qt5 COMPONENTS Core Network widgets  charts REQUIRED)
##修改MSVC的编码
add_compile_options("/source-charset:utf-8")
add_compile_options("/execution-charset:utf-8")

#添加测试代码的文件夹
add_subdirectory(test)

file(GLOB SRC ./src/*)
# 添加代码到库
add_library(${PROJECT_NAME}  ${SRC} )

## 连接所包含的库
target_link_libraries(${PROJECT_NAME}  Qt5::Network Qt5::Core Qt5::Widgets Qt5::Charts)
## 头文件目录，不添加会导致使用这个库的找不到头文件
target_include_directories(${PROJECT_NAME} PUBLIC  ./src)
## 允许测试
enable_testing()
