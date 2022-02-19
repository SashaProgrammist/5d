cmake_minimum_required(VERSION 3.21)
project(5d C)

set(CMAKE_C_STANDARD 99)

add_executable(5d
        main.c
        libs/data_structures/matrix/matrix.h libs/data_structures/matrix/matrix.c
        tasks/task1.c tasks/task2.c tasks/task3.c
        tasks/task4.c tasks/task5.c tasks/task6.c
        tasks/task7.c tasks/task8.c tasks/task9.c
        tasks/task10.c tasks/task11.c tasks/task12.c
        libs/algorithms/oneDimArray/oneDimArray.c libs/algorithms/oneDimArray/oneDimArray.h
        libs/algorithms/heapFunctions/heapFunctions.c libs/algorithms/heapFunctions/heapFunctions.h
        libs/data_structures/matrix/test/testMatrix.h libs/data_structures/matrix/test/testMatrix.c tasks/task13.c tasks/task14.c tasks/task15.c)
