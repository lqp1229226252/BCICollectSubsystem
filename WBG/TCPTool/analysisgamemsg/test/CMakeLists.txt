## 测试模板
## 基本上修改project和库名
cmake_minimum_required(VERSION 3.10.0)
project(analysisgamemsg_test)
aux_source_directory(. src)
add_executable(${PROJECT_NAME} ${src} test.h)

#库名就是自己定义的project_name
target_link_libraries(${PROJECT_NAME} analysisgamemsg)
