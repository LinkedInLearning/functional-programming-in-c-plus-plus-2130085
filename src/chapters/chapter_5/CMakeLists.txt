cmake_minimum_required(VERSION 3.16)
project(Chapter_5_HigherOrderFunctions LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Separate executables for each example
add_executable(move_only_function src/move_only_function.cpp)
add_executable(function_composition src/function_composition.cpp)
add_executable(challenge_function_pipeline src/challenge_function_pipeline.cpp)