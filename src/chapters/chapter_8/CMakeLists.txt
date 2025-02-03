cmake_minimum_required(VERSION 3.16)
project(Chapter_8_PatternMatching LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Separate executables for each example
add_executable(basic_pattern_matching src/basic_pattern_matching.cpp)
add_executable(type_specific_overloads src/type_specific_overloads.cpp)
add_executable(challenge_expression_evaluator src/challenge_expression_evaluator.cpp)