cmake_minimum_required(VERSION 3.24)
project(ALC)

set(CMAKE_CXX_STANDARD 17)

add_executable(ALC main.cpp)

set(CMAKE_EXE_LINKER_FLAGS "-static")