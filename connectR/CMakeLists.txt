cmake_minimum_required(VERSION 3.6)
project(connectR)

find_package(Boost 1.60.0)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        Utils.hpp Utils.cpp
        Board.hpp Board.cpp
        Tree.cpp Tree.hpp
        Solver.cpp Solver.hpp)

add_library(connectR STATIC ${SOURCE_FILES})
