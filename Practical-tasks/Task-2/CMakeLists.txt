cmake_minimum_required(VERSION 3.6)
project(hello_world_FLTK)

cmake_policy(SET CMP0072 NEW)

find_package(FLTK REQUIRED)
if(NOT FLTK_FOUND)
    message(SEND_ERROR "Failed to find FLTK!")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
set(SOURCE_FILES hello_world.cpp) 

include_directories(${PROJECT_NAME} /usr/local/include
									/usr/include/freetype2
                                    /usr/include/libpng16
                                    /usr/include/harfbuzz
                                    /usr/include/glib-2.0
                                    /usr/lib/glib-2.0/include
                                    /usr/include/uuid)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

add_definitions(-D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT)

target_link_libraries(${PROJECT_NAME}   ${FLTK_LIBRARIES}
                                        Xrender
                                        Xcursor
                                        Xfixes
                                        Xext
                                        Xft
                                        fontconfig
                                        Xinerama
                                        pthread
                                        dl
                                        m
                                        X11)