cmake_minimum_required(VERSION 3.6)

project(Radiosonde-finder)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS 
    Gui 
    Quick 
    Location
    QuickControls2
REQUIRED)

add_executable(Radiosonde-finder
    main.cpp
    qml.qrc
)

target_link_libraries(Radiosonde-finder 
    Qt5::Gui
    Qt5::Quick
    Qt5::Location
    Qt5::QuickControls2
)
