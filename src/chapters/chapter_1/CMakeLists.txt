cmake_minimum_required(VERSION 3.16)
project(Chapter_1_FunctionalCPP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Separate executables for each example
add_executable(lambda_transform src/lambda_transform.cpp)
add_executable(ranges_transform src/ranges_transform.cpp)
add_executable(accumulate src/accumulate.cpp)
add_executable(bind_partial_application src/bind_partial_application.cpp)
add_executable(challenge_factorial_accumulate src/challenge_factorial_accumulate.cpp)