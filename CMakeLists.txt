cmake_minimum_required(VERSION 3.21)
project(5d C)

set(CMAKE_C_STANDARD 99)

add_executable(5d main.c libs/data_structures/matrix/matrix.h libs/data_structures/matrix/matrix.c)
