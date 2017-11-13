cmake_minimum_required(VERSION 3.8)
project(splass1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Files.h Environment.h Commands.h FileSystem.h GlobalVariables.h main.cpp Files.cpp)
add_executable(splass1 ${SOURCE_FILES})