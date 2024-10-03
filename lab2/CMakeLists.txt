cmake_minimum_required(VERSION 3.26)
project(lab2)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(lab2
        main.cpp)
