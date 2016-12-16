cmake_minimum_required(VERSION 3.6)
project(Project3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp DrinkItem.cpp DrinkItem.h DrinkMachine.cpp DrinkMachine.h Receipt.cpp Receipt.h)
add_executable(Project3 ${SOURCE_FILES})