cmake_minimum_required(VERSION 3.28)

project(algorithms
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS Off)
set(CMAKE_COLOR_DIAGNOSTICS On)
add_compile_options(-Wall -Wextra -Wpedantic)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/insertion_sort")
