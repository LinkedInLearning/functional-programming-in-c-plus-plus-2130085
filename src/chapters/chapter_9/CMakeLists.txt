cmake_minimum_required(VERSION 3.16)
project(Chapter_9_AdvancedCoroutines LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_COMPILER /usr/bin/clang++)  # Ensure this is the correct path

# Ensure coroutine support
# add_compile_options(-fcoroutines)

# Executables
add_executable(lazy_sequence_generator src/lazy_sequence_generator.cpp)
add_executable(async_task_launch src/async_task_launch.cpp)
add_executable(coroutines_lazy_evaluation src/coroutines_lazy_evaluation.cpp)
add_executable(concurrent_tasks_functional src/concurrent_tasks_functional.cpp)
add_executable(challenge_async_lambdas src/challenge_async_lambdas.cpp)

# Explicitly link coroutine support (stdc++ is the default, but keeping it explicit)
target_link_libraries(lazy_sequence_generator stdc++)
target_link_libraries(async_task_launch stdc++)
target_link_libraries(coroutines_lazy_evaluation stdc++)
target_link_libraries(concurrent_tasks_functional stdc++)
target_link_libraries(challenge_async_lambdas stdc++)
