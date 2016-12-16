cmake_minimum_required(VERSION 3.6)
project(Project5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES BinarySearchTree.cpp BinarySearchTree.h WordUnscramble.cpp Word.cpp Word.h english_words.txt scrambled_words.txt)
add_executable(Project5 ${SOURCE_FILES})