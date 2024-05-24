cmake_minimum_required(VERSION 3.5)

project(V3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable for V3 project
add_executable(V3 main.cpp funkcijos.cpp funkcijos.h studentai.h)
