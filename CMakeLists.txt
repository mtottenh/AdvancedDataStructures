cmake_minimum_required (VERSION 2.6)
project (Exercises)


SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11 -g")
   
SET(CMAKE_CXX_COMPILER "clang++")


#Basic Data Strucutres
include_directories ("${PROJECT_SOURCE_DIR}/src/data_structures")
add_subdirectory (src/data_structures)

include_directories("${PROJECT_SOURCE_DIR}/src/algorithms")
add_subdirectory (src/algorithms)

include_directories("${PROJECT_SOURCE_DIR}/test")
add_subdirectory (test)

add_executable (DataStructureExercises src/data_structures/main.cxx)
target_link_libraries (DataStructureExercises  TestLib DataStructures stdc++) 

add_executable (AlgorithmExercises src/algorithms/main.cxx)
target_link_libraries(AlgorithmExercises Algorithms TestLib stdc++)


set (EXTRA_LIBS ${EXTRA_LIBS} Algorithms DataStructures stdc++)

add_executable (InsertionSort test/InsertionSort.cpp)
target_link_libraries (InsertionSort ${EXTRA_LIBS} TestLib)

add_executable (MergeSort test/MergeSort.cpp)
target_link_libraries (MergeSort ${EXTRA_LIBS} TestLib)

add_executable (HeapSort test/HeapSort.cpp)
target_link_libraries (HeapSort ${EXTRA_LIBS} TestLib)

add_executable (BSTSort test/BSTSort.cpp)
target_link_libraries (BSTSort ${EXTRA_LIBS} TestLib)

add_executable (AVLSort test/AVLSort.cpp)
target_link_libraries (AVLSort ${EXTRA_LIBS} TestLib)

enable_testing ()
add_test("InsertionSort" InsertionSort)
add_test("MergeSort" MergeSort)
add_test("HeapSort" HeapSort)
add_test("BSTSort" BSTSort)
add_test("AVLSort" AVLSort)

