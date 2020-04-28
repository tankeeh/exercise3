cmake_minimum_required(VERSION 3.15)
project(exercise2)

set(CMAKE_CXX_STANDARD 11)

add_executable(exercise3
        zmytest/RandomGens/RandomValues.cpp
        zlasdtest/test.cpp
        zmytest/test.cpp
        main.cpp
)