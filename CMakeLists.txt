cmake_minimum_required(VERSION 3.29)
project(os_exe4)

set(CMAKE_CXX_STANDARD 14)

include_directories(clauses1_4)
include_directories(clauses8_9)

add_executable(Guard
        clauses8_9/Guard.cpp
        clauses8_9/Guard.hpp)
