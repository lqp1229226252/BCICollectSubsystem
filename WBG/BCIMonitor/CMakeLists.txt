cmake_minimum_required(VERSION 3.5)

project(BCIMonitor LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INSTALL_PREFIX "D:/project/Qt/BCI/BCIMonitor/x86")
##添加测试
add_subdirectory(test)
enable_testing()
##修改MSVC的编码
add_compile_options("/source-charset:utf-8")
add_compile_options("/execution-charset:utf-8")
#添加模块
add_subdirectory(FileStorage)
add_subdirectory(SampleDevice)
add_subdirectory(curvegroup)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

file(GLOB SRC "src/*")
#monitor资源
file(GLOB res "res/*.qrc")
set(MonitorRes ${res} CACHE PATH "res of monitor")
add_library(${PROJECT_NAME}  ${SRC} ${res} FileStorage SampleDevice curvegroup)

target_link_libraries(BCIMonitor  FileStorage SampleDevice curvegroup)
target_link_libraries(BCIMonitor  Qt5::Widgets)
target_include_directories(BCIMonitor PUBLIC src)
