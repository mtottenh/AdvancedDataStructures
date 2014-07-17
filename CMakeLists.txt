cmake_minimum_required (VERSION 2.6)
project (Exercises)

#Compiler Flags
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11 -g")
SET(CMAKE_CXX_COMPILER "clang")


#Basic Data Strucutres
include_directories ("${PROJECT_SOURCE_DIR}/src/data_structures")
add_subdirectory (src/data_structures)

add_executable (DataStructureExercises src/data_structures/main.cxx)
target_link_libraries (DataStructureExercises DataStructures stdc++) 


