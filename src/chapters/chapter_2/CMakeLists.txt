cmake_minimum_required(VERSION 3.16)
project(Chapter_2_Concepts LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Separate executables for each example
add_executable(direct_constraints src/direct_constraints.cpp)
add_executable(requires_clause src/requires_clause.cpp)
add_executable(constrained_auto src/constrained_auto.cpp)
add_executable(iterable_concept src/iterable_concept.cpp)
add_executable(combining_concepts src/combining_concepts.cpp)
add_executable(concepts_vs_sfinae src/concepts_vs_sfinae.cpp)
add_executable(challenge_multiply src/challenge_multiply.cpp)