## 测试模板
## 基本上修改project和库名
cmake_minimum_required(VERSION 3.10.0)
project(TCPTool_test)
aux_source_directory(. src)
add_executable(${PROJECT_NAME} ${src})


#add_subdirectory()

#库名就是自己定义的project_name
target_link_libraries(TCPTool_test TCPTool)


##修改MSVC的编码
add_compile_options("/source-charset:utf-8")
add_compile_options("/execution-charset:utf-8")
