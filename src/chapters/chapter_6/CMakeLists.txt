cmake_minimum_required(VERSION 3.16)
project(Chapter_6_FunctionalLibraries LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Boost library
find_package(Boost REQUIRED)

# Separate executables for each example
add_executable(stl_transform_accumulate src/stl_transform_accumulate.cpp)
add_executable(stl_ranges_filter src/stl_ranges_filter.cpp)
add_executable(boost_hana_tuple src/boost_hana_tuple.cpp)
add_executable(challenge_fibonacci_boost_hana src/challenge_fibonacci_boost_hana.cpp)

# Link Boost::Hana to relevant targets
target_link_libraries(boost_hana_tuple Boost::Boost)
target_link_libraries(challenge_fibonacci_boost_hana Boost::Boost)