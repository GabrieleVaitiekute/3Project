cmake_minimum_required(VERSION 3.5)
project(Deque2)

set(CMAKE_CXX_STANDARD 11)

# Include directories
include_directories(include)

# Add your source files
set(SOURCES 
    d2_main.cpp
    d2_funkcijos.cpp
)

# Add header files
set(HEADERS
    d2_funkcijos.h
    d2studentai.h
)

# Create executable
add_executable(Deque2 ${SOURCES} ${HEADERS})