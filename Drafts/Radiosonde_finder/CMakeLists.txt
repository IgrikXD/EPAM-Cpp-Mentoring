cmake_minimum_required(VERSION 3.1)

project(Radiosonde_finder LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS
    Core
    Quick
REQUIRED)

set(SOURCE_FILES BaloonDataContainer/BaloonDataContainer.cpp
                 main.cpp
                 qml.qrc)

add_executable(Radiosonde_finder ${SOURCE_FILES})
target_compile_definitions(Radiosonde_finder PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(Radiosonde_finder PRIVATE
    Qt5::Core
    Qt5::Quick
)

include_directories(BaloonDataContainer)
