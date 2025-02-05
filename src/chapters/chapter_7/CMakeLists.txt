cmake_minimum_required(VERSION 3.16)
project(Chapter_7_FunctionalReactiveProgramming LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the full path to RxCpp include directory
set(RXCPP_INCLUDE_DIR "/opt/rxcpp/Rx/v2/src")

# Include the RxCpp directory
include_directories(${RXCPP_INCLUDE_DIR})

# Separate executables for each example
add_executable(rxcpp_simple_stream src/rxcpp_simple_stream.cpp)
add_executable(rxcpp_coroutine_ranges src/rxcpp_coroutine_ranges.cpp)
add_executable(realtime_data_stream src/realtime_data_stream.cpp)
add_executable(functional_async_event_handling src/functional_async_event_handling.cpp)
add_executable(challenge_word_frequency src/challenge_word_frequency.cpp)
