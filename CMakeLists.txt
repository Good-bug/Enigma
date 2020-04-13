cmake_minimum_required(VERSION 3.1.0)
project(Enigma)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable( Enigma main.cpp
                Rotor.cpp
                Rotor.h
                Reflector.cpp
                Reflector.h
                Encrypter.cpp
                Encrypter.h
                mainwindow.h
                mainwindow.cpp
                mainwindow.ui
                Buttons.qrc)

#qt files
target_link_libraries(Enigma Qt5::Widgets)

#boost files
find_package(Boost)
include_directories( ${Boost_INCLUDE_DIRS} )
include_directories( ${Boost_LIBRARY_DIR} )

