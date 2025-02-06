cmake_minimum_required(VERSION 3.16)
project(Chapter_8_PatternMatching LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Separate executables for each example
# add_executable(variant_pattern_matching src/variant_pattern_matching.cpp)
# add_executable(visit_example src/visit_example.cpp)
# add_executable(pattern_matching_clarity src/pattern_matching_clarity.cpp)
# add_executable(real_world_variant src/real_world_variant.cpp)
add_executable(challenge_adaptive_processor src/challenge_adaptive_processor.cpp)
