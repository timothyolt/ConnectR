cmake_minimum_required(VERSION 3.6)
project(ConnectR)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake-modules-sonar")

if(CMAKE_BUILD_TYPE STREQUAL "Analysis")
    include(SonarAnalysis)
    ADD_TARGET_SONAR("Analysis" "connectR" "connectR_tests" "connectR_tests/tests" "run_tests")
endif()

include_directories(connectR)

add_subdirectory(connectR)
add_subdirectory(connectR_implementation)
add_subdirectory(connectR_tests)
