cmake_minimum_required(VERSION 3.16)
project(Chapter_6_FunctionalLibraries LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Boost library (without components)
find_package(Boost REQUIRED)

# Separate executables for each example
add_executable(stl_transform_accumulate src/stl_transform_accumulate.cpp)
add_executable(stl_ranges_filter src/stl_ranges_filter.cpp)
add_executable(boost_hana_tuple src/boost_hana_tuple.cpp)
add_executable(challenge_fibonacci_boost_hana src/challenge_fibonacci_boost_hana.cpp)

# Include Boost headers
target_include_directories(boost_hana_tuple PRIVATE ${Boost_INCLUDE_DIR})
target_include_directories(challenge_fibonacci_boost_hana PRIVATE ${Boost_INCLUDE_DIR})
