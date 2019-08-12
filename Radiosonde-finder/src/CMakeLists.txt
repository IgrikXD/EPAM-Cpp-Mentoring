cmake_minimum_required(VERSION 3.6)
project(Radiosonde-finder)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
set(SOURCE_FILES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

include_directories(Gps Time Telemetry)