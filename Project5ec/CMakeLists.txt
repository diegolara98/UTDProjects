cmake_minimum_required(VERSION 3.6)
project(Project5ec)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES BinarySearchTree.h Word.cpp Word.h WordUnscramble.cpp)
add_executable(Project5ec ${SOURCE_FILES})