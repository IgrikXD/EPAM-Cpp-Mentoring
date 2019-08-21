cmake_minimum_required(VERSION 3.6)
project(Radiosonde-finder)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

set(SOURCE_FILES src/main.cpp 
                 src/Gps/GpsData.cpp
                 src/Time/TimeData.cpp
                 src/Telemetry/TelemetryData.cpp
                 test/tools.cpp)

add_executable(Radiosonde-finder ${SOURCE_FILES})

include_directories(src/Gps
                    src/Time
                    src/Telemetry
                    src/rapidxml-1.13
                    test)