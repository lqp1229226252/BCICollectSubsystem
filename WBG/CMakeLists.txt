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


#BCIMonitor
add_subdirectory(BCIMonitor)
add_subdirectory(BCIGameOverData)
add_subdirectory(TCPTool)
add_library(WBG
    ${IndexWidget} ${IntroduceWidget} ${PersonalData}
    ${StartGameWidget} ${StoreWidget} ${UserGameWidget}
    )

target_link_libraries(WBG PUBLIC Qt5::Widgets Qt5::Multimedia Qt5::Charts
                      Qt5::MultimediaWidgets BCIMonitor BCIGameOverData TCPTool)

target_include_directories(WBG PUBLIC  "IndexWidget"
    "IntroduceWidget" "PersonalData"
    "StartGameWidget"  "StoreWidget"
    "UserGameWidget/src" )
