cmake_minimum_required(VERSION 3.16)
project(Chapter_7_FunctionalReactiveProgramming LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find RxCpp library
find_package(RxCpp REQUIRED)

# Separate executables for each example
add_executable(rxcpp_simple_stream src/rxcpp_simple_stream.cpp)
add_executable(rxcpp_coroutine_ranges src/rxcpp_coroutine_ranges.cpp)
add_executable(challenge_word_frequency src/challenge_word_frequency.cpp)

# Link RxCpp to relevant targets
target_link_libraries(rxcpp_simple_stream RxCpp::RxCpp)
target_link_libraries(rxcpp_coroutine_ranges RxCpp::RxCpp)
target_link_libraries(challenge_word_frequency RxCpp::RxCpp)