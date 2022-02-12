cmake_minimum_required(VERSION 3.21)
project(5d C)

set(CMAKE_C_STANDARD 99)

add_executable(5d
        main.c
        libs/data_structures/matrix/matrix.h libs/data_structures/matrix/matrix.c
        tasks/task1.c
        libs/algorithms/oneDimArray/oneDimArray.c libs/algorithms/oneDimArray/oneDimArray.h
        libs/algorithms/heapFunctions/heapFunctions.c libs/algorithms/heapFunctions/heapFunctions.h
        tasks/task2.c
        tasks/task3.c)
