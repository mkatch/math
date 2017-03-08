cmake_minimum_required(VERSION 3.4.1)
project(Test)

file(GLOB TEST_SOURCES *.cpp)

add_executable(run_tests ${TEST_SOURCES})
set_property(TARGET run_tests PROPERTY CXX_STANDARD 11)
set_property(TARGET run_tests PROPERTY CXX_STANDARD_REQUIRED TRUE)
