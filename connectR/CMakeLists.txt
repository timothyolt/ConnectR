cmake_minimum_required(VERSION 3.6)
project(connectR)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES ConnectBoard.hpp ConnectBoard.cpp)

add_library(connectR STATIC ${SOURCE_FILES})
