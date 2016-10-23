cmake_minimum_required(VERSION 3.6)
project(NumericalModelling)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Worksheet1/Exercise4/Exercise4.cpp
        Worksheet1/Exercise6/Exercise6.cpp
        Worksheet1/Exercise7/Exercise7.cpp
        Worksheet2/Exercise1/Exercise1.cpp
        Worksheet2/Exercise2/Exercise2.cpp)
# add_executable(NumericalModelling ${SOURCE_FILES})
add_executable(W1E4 Worksheet1/Exercise4/Exercise4.cpp)
add_executable(W1E6 Worksheet1/Exercise6/Exercise6.cpp)
add_executable(W1E7 Worksheet1/Exercise7/Exercise7.cpp)
add_executable(W2E1 Worksheet2/Exercise1/Exercise1.cpp)
add_executable(W2E2 Worksheet2/Exercise2/Exercise2.cpp)