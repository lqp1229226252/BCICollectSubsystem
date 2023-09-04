cmake_minimum_required(VERSION 3.5)

project(GameFinishWidget LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(test)
enable_testing()

find_package(Qt5 COMPONENTS Core Widgets quickwidgets  REQUIRED)

file(GLOB src "src/*")
file(GLOB chart "src/chart/*")
file(GLOB data "src/data/*")
file(GLOB progressbar "src/progressbar/*")
file(GLOB res  "res/*.qrc")
set(gamefinishres ${res} CACHE PATH "gamefinish of res")

add_library(GameFinishWidget ${src} ${chart} ${data} ${progressbar} ${res})

target_link_libraries(GameFinishWidget PRIVATE Qt5::Core Qt5::Widgets Qt5::QuickWidgets)

target_compile_definitions(GameFinishWidget PRIVATE GAMEFINISHWIDGET_LIBRARY)

target_include_directories(GameFinishWidget PUBLIC "src")
