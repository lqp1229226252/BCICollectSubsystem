cmake_minimum_required(VERSION 3.5)

project(BCI LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

##修改MSVC的编码
if(MSVC)
    add_compile_options("/source-charset:utf-8")
    add_compile_options("/execution-charset:utf-8")
endif()

find_package(Qt5 COMPONENTS Widgets sql REQUIRED)
#资源文件
file(GLOB video "video/*")
file(COPY ${video} DESTINATION "video")
##字体资源
file(GLOB font "font/*")
file(COPY ${font} DESTINATION "font")
##电极坐标
file(GLOB chanlocs "device/*")
file(COPY ${chanlocs} DESTINATION "device")
## 曲线资源
file(COPY ${CURVE_RES} DESTINATION "res")
## 添加BP文件
file(COPY ${BpBIT} DESTINATION ".")
file(COPY ${BpDLL} DESTINATION ".")
## 添加解析文件脚本
file(COPY ${RES_EXE} DESTINATION "file")
## 添加mat库
file(COPY ${MATDLL} DESTINATION ".")
#源代码
#数据库
file(GLOB SQL "BCIMysql/*")
#json数据操作
file(GLOB JSON "JsonOperation/*")
#登录
file(GLOB LOGIN "LoginAndRegister/Login/*")
#注册
file(GLOB REGISTER "LoginAndRegister/Register/*")
#发送保存出来的mat文件
file(GLOB FTPSendFile "WBG/FileProcess/FTPSendFile/*")

file(GLOB SRC "src/*")
add_subdirectory(WBG)

add_executable(BCI WIN32 main.cpp src.qrc pic/pic.qrc ${MonitorRes}
    ${SRC} ${SQL} ${JSON} ${LOGIN} ${REGISTER} ${FTPSendFile})


target_link_libraries(BCI PRIVATE Qt5::Widgets Qt5::Sql WBG)
target_include_directories(BCI PRIVATE "src" "BCIMysql" "JsonOperation"
                            "LoginAndRegister/Login" "LoginAndRegister/Register" "WBG/FileProcess/FTPSendFile")
