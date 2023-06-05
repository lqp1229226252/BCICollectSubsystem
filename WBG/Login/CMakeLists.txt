cmake_minimum_required(VERSION 3.5)
#123

project(Login LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

##添加测试
add_subdirectory(test)
enable_testing()
##修改MSVC的编码
if(MSVC)
    add_compile_options("/source-charset:utf-8")
    add_compile_options("/execution-charset:utf-8")
    add_compile_options("/validate-charset:utf-8")
endif()
#添加模块
add_subdirectory(QRCodeLoginWidget)
add_subdirectory(Register)
 find_package(Qt5 COMPONENTS Widgets sql REQUIRED)

file(GLOB SRC "src/*")
#资源
file(GLOB RES "res/*.qrc")
<<<<<<< HEAD
set(LoginRes ${RES}  CACHE PATH "res of Login")
=======
set(LoginRes ${RES}  CACHE PATH "res of monitor")
>>>>>>> 3fd16a74ea48d64076ce7267f1947e46574ffe28
# add_library(${PROJECT_NAME}  ${SRC} ${res} FileStorage SampleDevice curvegroup)
add_library(${PROJECT_NAME}  ${SRC} ${RES}  QRCodeLoginWidget Register)

target_link_libraries(Login Qt5::Core Qt5::Sql Qt5::Widgets QRCodeLoginWidget Register)
target_include_directories(Login PUBLIC src)



