cmake_minimum_required(VERSION 3.26)
project(lab6)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

find_package(OpenMP REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
add_executable(lab6_1
        task1.cpp
)
add_executable(lab6_2
        task2.cpp
)
if(OpenMP_CXX_FOUND)
    target_link_libraries(lab6_1 PRIVATE OpenMP::OpenMP_CXX)
    target_link_libraries(lab6_2 PRIVATE OpenMP::OpenMP_CXX)
endif()