cmake_minimum_required(VERSION 3.5)
project(Vector2)

set(CMAKE_CXX_STANDARD 11)

# Include directories
include_directories(include)

# Add your source files
set(SOURCES 
    v2_main.cpp
    v2_funkcijos.cpp
)

# Add header files
set(HEADERS
    v2_funkcijos.h
    v2studentai.h
)

# Create executable
add_executable(Vector2 ${SOURCES} ${HEADERS})
