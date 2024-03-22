cmake_minimum_required(VERSION 3.5)
project(List2)

set(CMAKE_CXX_STANDARD 11)

# Include directories
include_directories(include)

# Add your source files
set(SOURCES 
    l2_main.cpp
    l2_funkcijos.cpp
)

# Add header files
set(HEADERS
    l2_funkcijos.h
    l2studentai.h
)

# Create executable
add_executable(List2 ${SOURCES} ${HEADERS})