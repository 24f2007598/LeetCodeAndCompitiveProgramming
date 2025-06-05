cmake_minimum_required(VERSION 3.31)
project(heap2)

set(CMAKE_CXX_STANDARD 20)

add_executable(heap2 main.cpp
        MaxHeap1.cpp
        MaxHeap1.h
        Solution.cpp
        MaxHeap.h
        MaxHeapFactory.cpp
        MaxHeapFactory.h
)
