cmake_minimum_required(VERSION 3.28)
project(untitled3 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled3 main.c
        libs/data_structures/matrix/matrix.c
        libs/data_structures/matrix/matrix.h
        libs/data_structures/matrix/matrix.h
        libs/data_structures/matrix/matrix.c
        libs/data_structures/vector_void/vector_void.c
        libs/data_structures/vector/vector.c
        libs/data_structures/unordered_array_set/unordered_set.c
        libs/data_structures/ordered_array_set/ordered_set.c
        libs/data_structures/bitset/bitset.c
        libs/algorithms/algorithm.c
)