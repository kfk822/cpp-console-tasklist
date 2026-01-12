cmake_minimum_required(VERSION 3.10)

project(cpp_taskList)

set(CMAKE_CXX_STANDARD_17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp_taskList
	src/main.cpp
	src/taskList.cpp
	src/IO.cpp
	src/fileHandler.cpp
	src/filter.cpp
)

target_include_directories(cpp_taskList PRIVATE external)