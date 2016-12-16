cmake_minimum_required(VERSION 3.6)
project(Assignment3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp DoubleLinkedList.cpp  OrderedDoubleLinkedList.cpp  PhoneBookEntry.cpp  PhoneBook.cpp Stack.cpp Stack.h Queue.cpp Queue.h)
add_executable(Assignment3 ${SOURCE_FILES})