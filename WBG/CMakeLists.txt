cmake_minimum_required(VERSION 3.5)

project(WBG LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt5 COMPONENTS Widgets charts multimedia multimediawidgets REQUIRED)
#源代码
#WGB
file(GLOB IndexWidget "IndexWidget/*")
file(GLOB IntroduceWidget "IntroduceWidget/*")
file(GLOB PersonalData "PersonalData/*")
file(GLOB StartGameWidget "StartGameWidget/*")
file(GLOB StoreWidget "StoreWidget/*")
file(GLOB UserGameWidget "UserGameWidget/src/*")
file(GLOB TempWidget "TempWidget/*")

#BCIMonitor
add_subdirectory(BCIMonitor)
add_subdirectory(GameFinishWidget)

add_subdirectory(TCPTool)
add_subdirectory(FTPServer)
add_subdirectory(FTPUploadFile)
add_subdirectory(Login)

add_library(WBG
    ${IndexWidget} ${IntroduceWidget} ${PersonalData}
    ${StartGameWidget} ${StoreWidget} ${UserGameWidget}
    ${FTPServerWidget} ${TempWidget}
    )

target_link_libraries(WBG PUBLIC Qt5::Widgets Qt5::Multimedia Qt5::Charts Qt5::MultimediaWidgets
                      BCIMonitor  GameFinishWidget  TCPTool FTPServer FTPUploadFile Login )

target_include_directories(WBG PUBLIC  "IndexWidget"
    "IntroduceWidget" "PersonalData"
    "StartGameWidget"  "StoreWidget"
    "UserGameWidget/src" "TempWidget")
