cmake_minimum_required(VERSION 3.16)
project(Chapter_3_Ranges LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Separate executables for each example
add_executable(transform_pipeline src/transform_pipeline.cpp)
add_executable(filter_transform_pipeline src/filter_transform_pipeline.cpp)
add_executable(lazy_fibonacci_coroutine src/lazy_fibonacci_coroutine.cpp)
add_executable(challenge_pipeline src/challenge_pipeline.cpp)
