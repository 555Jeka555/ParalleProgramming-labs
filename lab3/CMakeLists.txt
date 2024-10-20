cmake_minimum_required(VERSION 3.26)
project(lab3)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab3 main.cpp)

target_link_libraries(lab3 winmm)