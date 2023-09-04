cmake_minimum_required(VERSION 3.5)

project(GameFinishWidget_test LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
file(GLOB res  "../res/*.qrc")
add_executable(GameFinishWidget_test main.cpp ${res})

target_link_libraries(GameFinishWidget_test  PRIVATE
    Qt5::Core Qt5::Widgets GameFinishWidget)
