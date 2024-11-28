cmake_minimum_required(VERSION 3.26)
project(lab5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS -static)

add_executable(lab5 main.cpp
        main1.cpp
        main2.cpp
        main3.cpp
)
