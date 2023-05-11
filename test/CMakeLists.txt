## 测试模板
## 基本上修改project和库名
cmake_minimum_required(VERSION 3.10.0)
project(FTPServerTest)
aux_source_directory(. src)
add_executable(${PROJECT_NAME} ${src})

#库名就是自己定义的project_name
target_link_libraries(${PROJECT_NAME} FTPServer)
