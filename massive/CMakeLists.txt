cmake_minimum_required(VERSION 3.6)
project(massive)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp massive.cpp massive.hpp)
add_executable(massive ${SOURCE_FILES})