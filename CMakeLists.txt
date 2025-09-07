cmake_minimum_required(VERSION 3.10)

# Project name and language
project(C++ LANGUAGES CXX)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include headers (so we can #include `file`)
include_directories(include)

# Collect all source files
file(GLOB SRC_FILES src/*.cpp)

# Main executable
add_executable(main main.cpp ${SRC_FILES})

# Add test directory
enable_testing()
add_subdirectory(tests)