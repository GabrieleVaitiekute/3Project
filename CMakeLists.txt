cmake_minimum_required(VERSION 3.5)

project(V1.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable for Class project
add_executable(Class class_main.cpp class_funkcijos.cpp class_funkcijos.h class_studentai.h)
