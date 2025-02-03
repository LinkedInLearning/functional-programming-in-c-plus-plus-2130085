# Chapter 6: Functional Libraries – STL and Boost.Hana

C++ provides a rich set of libraries for functional programming. This chapter explores functional-style algorithms in the STL and metaprogramming with Boost.Hana.

## 🚀 Examples

1. **STL Transform and Accumulate** (`stl_transform_accumulate.cpp`)
    - Uses `std::transform` and `std::accumulate` to process lists.

2. **STL Ranges Filter** (`stl_ranges_filter.cpp`)
    - Uses `std::views::filter` to lazily filter values in a range.

3. **Boost.Hana Tuple Manipulation** (`boost_hana_tuple.cpp`)
    - Demonstrates tuple transformations using `Boost.Hana`.

4. **Challenge: Fibonacci Generator with Boost.Hana** (`challenge_fibonacci_boost_hana.cpp`)
    - Implements a compile-time Fibonacci sequence using `Boost.Hana`.

## 🔧 Build and Run

First, ensure that Boost is installed on your system.

### Install Boost (if needed)
```sh
sudo apt install libboost-all-dev   # Ubuntu
brew install boost                  # macOS