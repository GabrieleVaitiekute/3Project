cmake_minimum_required(VERSION 3.5)

project(MyProjects)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable for Vector project
add_executable(Vector vector_main.cpp vector_funkcijos.cpp vector_funkcijos.h vector_studentai.h)

# Add executable for List project
add_executable(List list_main.cpp list_funkcijos.cpp list_funkcijos.h list_studentai.h)

# Add executable for Deque project
add_executable(Deque deque_main.cpp deque_funkcijos.cpp deque_funkcijos.h deque_studentai.h)