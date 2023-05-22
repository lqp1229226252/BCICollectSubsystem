cmake_minimum_required(VERSION 3.5)

project(QRCodeLoginWidget)

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
##获取源文件
file(GLOB SRC ./src/*)
file(GLOB RES ./res/*.qrc)


set(QRCodeLoginWidget ${RES} CACHE PATH "res of QRCode")
find_package(Qt5 COMPONENTS core widgets charts REQUIRED)
add_library(QRCodeLoginWidget  ${SRC} ${RES} )
target_include_directories(QRCodeLoginWidget PUBLIC "./src/")
target_link_libraries(QRCodeLoginWidget Qt5::Core Qt5::Widgets )

install(TARGETS ${PROJECT_NAME} ARCHIVE)
