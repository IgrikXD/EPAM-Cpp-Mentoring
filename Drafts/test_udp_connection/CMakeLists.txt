cmake_minimum_required(VERSION 3.6)
project(UDPCommunicationTest)

find_package(Boost REQUIRED)
if(NOT Boost_FOUND)
    message(SEND_ERROR "Failed to find Boost library!")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

add_executable(SendPacket sendPacket.cpp)
add_executable(PacketListener packetListener.cpp)

target_link_libraries(SendPacket boost_system
                                    boost_thread
                                    pthread)
target_link_libraries(PacketListener boost_system
                                    boost_thread
                                    pthread)