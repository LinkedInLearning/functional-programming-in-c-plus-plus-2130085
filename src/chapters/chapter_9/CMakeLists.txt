cmake_minimum_required(VERSION 3.16)
project(Chapter_9_AdvancedCoroutines LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Separate executables for each example
add_executable(coroutine_lazy_sequence src/coroutine_lazy_sequence.cpp)
add_executable(async_timer src/async_timer.cpp)
add_executable(challenge_async_task_manager src/challenge_async_task_manager.cpp)