cmake_minimum_required(VERSION 3.10.0)
project(usergamewidget)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS core widgets  REQUIRED)

add_subdirectory(test)
file(GLOB src ./src/*)
file(GLOB res ./res/*.qrc)
add_library(${PROJECT_NAME} ${src} ${res})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets)
target_include_directories(${PROJECT_NAME} PUBLIC "./src")

enable_testing()
