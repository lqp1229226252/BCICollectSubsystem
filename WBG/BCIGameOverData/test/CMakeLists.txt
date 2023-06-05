## 测试模板
## 基本上修改project和库名
cmake_minimum_required(VERSION 3.10.0)
project(demo_test)
aux_source_directory(. src)
message("${BCIGameOverDataRes}")
add_executable(${PROJECT_NAME} ${src} test.h ${BCIGameOverDataRes})

#库名就是自己定义的project_name
target_link_libraries(${PROJECT_NAME} BCIGameOverData)

##修改MSVC的编码
add_compile_options("/source-charset:utf-8")
add_compile_options("/execution-charset:utf-8")


