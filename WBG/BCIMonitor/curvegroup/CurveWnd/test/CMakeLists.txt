cmake_minimum_required(VERSION 3.10.0)
project(curve_test)
aux_source_directory(. src)
add_executable(${PROJECT_NAME} ${src})
target_link_libraries(${PROJECT_NAME} curvewnd)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
