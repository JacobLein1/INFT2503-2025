cmake_minimum_required(VERSION 4.0)
project(oving7)

set(CMAKE_CXX_STANDARD 20)

add_executable(oving7 main.cpp
        fraction.hpp
        fraction.cpp
        Set.hpp
        Set.cpp)
