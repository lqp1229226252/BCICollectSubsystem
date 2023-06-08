cmake_minimum_required(VERSION 3.5)

project(SampleDevice LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(test)
enable_testing()
#BPSDK
set(BPSDK "BPSDK")
set(BPInclude ${BPSDK}/Include)
if(CMAKE_CL_64)
    file(GLOB BPBIT ${BPSDK}/Bin/x64/*.bit)
    file(GLOB BPDLL ${BPSDK}/Bin/x64/*.dll)
    file(GLOB BPLib ${BPSDK}/Bin/x64/*.lib)
else()
    file(GLOB BPBIT ${BPSDK}/Bin/Win32/*.bit)
    file(GLOB BPDLL ${BPSDK}/Bin/Win32/*.dll)
    file(GLOB BPLib ${BPSDK}/Bin/Win32/*.lib)
endif()
set(BpBIT ${BPBIT} CACHE PATH "bit of bp")
set(BpDLL ${BPDLL} CACHE PATH "dll of bp")
include_directories(${BPInclude})


#Qt库
find_package(Qt5 COMPONENTS  Core widgets REQUIRED)
add_subdirectory(filter)

file(GLOB SRC "./src/*")
file(GLOB BPDevice "./src/BPDevice/*")
file(GLOB FileDevice "./src/FileDevice/*")
file(GLOB Config "./src/Config/*")
file(GLOB RES_EXE "./res/*.exe")
message("exe:${RES_EXE}")
#资源文件
set(RES_EXE ${RES_EXE} CACHE PATH "read file")

add_library(SampleDevice ${SRC} ${BPDevice} ${FileDevice} ${Config})


target_link_libraries(SampleDevice  Qt5::Core Qt5::Widgets  filter ${BPLib})

target_include_directories(SampleDevice PUBLIC "./src")
target_include_directories(SampleDevice PRIVATE "./src/BPDevice" "./src/FileDevice"  "./src/Config" ${BPInclude})
install(TARGETS ${PROJECT_NAME} ARCHIVE)
