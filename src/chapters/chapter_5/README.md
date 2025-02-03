# Chapter 5: Higher-Order Functions and Function Composition

Higher-order functions allow functions to be passed, returned, and composed. C++23 introduces `std::move_only_function` and `std::invoke` to make handling functions more efficient.

## 🚀 Examples

1. **Move-Only Function** (`move_only_function.cpp`)
    - Uses `std::move_only_function` to enforce move semantics for lambdas.

2. **Function Composition with std::invoke** (`function_composition.cpp`)
    - Demonstrates function composition using `std::invoke`.

3. **Challenge: Function Composition Pipeline** (`challenge_function_pipeline.cpp`)
    - Implements a generic pipeline to compose three functions.

## 🔧 Build and Run

First, navigate to the `Chapter_5` directory:
```sh
cd chapter_5/build
cmake ..
make