cmake_minimum_required(VERSION 3.22.1)
project(os_exe4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Main Graph.cpp
        algo.cpp
        main.cpp)
