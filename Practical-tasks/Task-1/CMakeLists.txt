cmake_minimum_required(VERSION 3.6)
project(hello_world)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
set(SOURCE_FILES ${PROJECT_NAME}.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})