# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (porous_structure_generator)

set(SOURCES src/box.cpp src/atom.cpp src/main.cpp)

# Add an executable with the above sources
add_executable(porous_structure_generator ${SOURCES})
set(CMAKE_BUILD_TYPE Debug)

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(porous_structure_generator
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)

