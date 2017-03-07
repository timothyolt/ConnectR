cmake_minimum_required(VERSION 3.6)
project(connectR)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_INTERFACE interface/IBoard.hpp interface/ISolver.hpp interface/ITree.hpp interface/BoardSize.hpp)

set(SOURCE_ITERATION1 iteration1/Board2D.hpp iteration1/Board2D.cpp iteration1/TreeBasic.cpp iteration1/TreeBasic.hpp)

set(SOURCE_FILES ${SOURCE_INTERFACE} ${SOURCE_ITERATION1} iteration1/SolverBlank.cpp iteration1/SolverBlank.hpp Utils.hpp Utils.cpp)

add_library(connectR STATIC ${SOURCE_FILES})
