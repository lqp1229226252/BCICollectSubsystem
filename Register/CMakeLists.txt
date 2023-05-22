cmake_minimum_required(VERSION 3.5)

project(Register)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)

if(MSVC)
    add_compile_options("/source-charset:utf-8")
    add_compile_options("/execution-charset:utf-8")
    add_compile_options("/validate-charset:utf-8")
endif()
#添加测试
enable_testing()
add_subdirectory(test)
###获取源文件
file(GLOB SRC ./src/*)


set(Register  CACHE PATH "res of QRCode")
find_package(Qt5 COMPONENTS core widgets charts REQUIRED)
add_library(Register  ${SRC})
target_include_directories(Register PUBLIC "./src/")
target_link_libraries(Register Qt5::Core Qt5::Widgets )

install(TARGETS ${PROJECT_NAME} ARCHIVE)
