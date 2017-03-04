cmake_minimum_required(VERSION 3.6)
project(connectR_implementation)

add_executable(run_connectR main.cpp)

target_link_libraries(run_connectR connectR)
