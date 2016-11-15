cmake_minimum_required(VERSION 3.6)
project(Tour)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp create.h create.cpp search.h
        search.cpp carGuild.h carGuild.cpp Graph.cpp
        Graph.h
        StackNode.cpp StackNode.h Stack.cpp Stack.h
        Queue.h Queue.cpp QueueNode.cpp QueueNode.h)
add_executable(Tour ${SOURCE_FILES})