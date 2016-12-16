cmake_minimum_required(VERSION 3.6)
project(Project2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES project2.cpp drinkitem.cpp drinkitem.h receipt.cpp receipt.h drinkmachine.cpp drinkmachine.h)
add_executable(Project2 ${SOURCE_FILES})