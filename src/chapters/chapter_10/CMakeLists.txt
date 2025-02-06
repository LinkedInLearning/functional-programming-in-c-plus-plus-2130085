cmake_minimum_required(VERSION 3.16)
project(Chapter_10_FunctionalVsImperative LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Separate executables for each example
add_executable(blending_functional_imperative src/blending_functional_imperative.cpp)
add_executable(immutable_shared src/immutable_shared.cpp)
add_executable(func_pipe_loops src/func_pipe_loops.cpp)
add_executable(hybrid_programming_style src/hybrid_programming_style.cpp)
add_executable(challenge_functional_refactor src/challenge_functional_refactor.cpp)
