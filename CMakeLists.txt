cmake_minimum_required(VERSION 3.15)
project(Enigma)

set(CMAKE_CXX_STANDARD 20)

add_executable(Enigma main.cpp Rotor.cpp Rotor.h Reflector.cpp Reflector.h)
find_package(Boost)
include_directories( ${Boost_INCLUDE_DIRS} )
include_directories( ${Boost_LIBRARY_DIR} )

