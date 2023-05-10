cmake_minimum_required(VERSION 3.5)

project(FtpServer LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
#找Qt的字库，类似Qt+=
find_package(Qt5 COMPONENTS Core Gui Network Widgets REQUIRED)
# 添加代码到运行文件
add_executable(FtpServer 
    ftpServer/dataconnection.cpp
    ftpServer/ftpcommand.cpp
    ftpServer/ftpcontrolconnection.cpp
    ftpServer/ftplistcommand.cpp
    ftpServer/ftpretrcommand.cpp
    ftpServer/ftpserver.cpp
    ftpServer/ftpstorcommand.cpp
    ftpserverwidget.cpp
    main.cpp
)

target_link_libraries(FtpServer PRIVATE
    Qt5::Core
    Qt5::Gui
    Qt5::Network
    Qt5::Widgets
)
## 头文件目录，不添加会导致使用这个库的找不到头文件
target_include_directories(FtpServer PUBLIC  ./ftpServer)