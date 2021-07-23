cmake_minimum_required(VERSION 3.0)
project(structure-creator)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(structure-creator ${SOURCES} create_structure.cpp)
