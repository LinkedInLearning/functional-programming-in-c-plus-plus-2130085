# Chapter 1: Functional Programming in Modern C++

Modern C++ supports functional programming principles through lambdas, closures, and standard algorithms. This chapter explores how to use `std::transform`, `std::accumulate`, and `std::bind` to write expressive and declarative code.

## 🚀 Examples

1. **Lambda and Transform** (`lambda_transform.cpp`)
    - Uses `std::transform` with a lambda to modify a vector.

2. **Ranges Transform** (`ranges_transform.cpp`)
    - Uses `std::views::transform` for lazy transformations.

3. **Accumulate for Summing Squares** (`accumulate.cpp`)
    - Uses `std::accumulate` to sum squared values.

4. **Partial Application with std::bind** (`bind_partial_application.cpp`)
    - Demonstrates `std::bind` for function composition.

5. **Challenge: Factorial Sum using Accumulate** (`challenge_factorial_accumulate.cpp`)
    - Uses `std::accumulate` to compute the sum of factorials.

## 🔧 Build and Run

First, navigate to the `Chapter_1` directory:
```sh
cd chapter_1/buils
cmake ..
make