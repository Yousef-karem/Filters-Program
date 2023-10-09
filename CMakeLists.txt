cmake_minimum_required(VERSION 3.25)
project(oop_ass)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(oop_ass
        bmplib.cpp
        bmplib.h
        Filters.cpp
        Filters.h
        main.cpp)
