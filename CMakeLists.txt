cmake_minimum_required(VERSION 3.26)
project(untitled17 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled17 main.c
        "test vector.c")

add_subdirectory(libs)
target_link_libraries(untitled17 data_structures)
