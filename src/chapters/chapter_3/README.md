# Chapter 3: Functional Pipelines with std::ranges and std::views

C++20 introduced the ranges library, making data transformations more readable and efficient. This chapter explores pipelines using `std::ranges` and `std::views`, showing how to compose operations and enable lazy evaluation.

## 🚀 Examples

1. **Transforming a Collection** (`transform_pipeline.cpp`)
    - Squares a list of integers and filters out odd results.

2. **Combining Filters and Transforms** (`filter_transform_pipeline.cpp`)
    - Uses an infinite sequence, filters multiples of 3, multiplies by 10, and selects the first 5 results.

3. **Lazy Evaluation with Coroutines** (`lazy_fibonacci_coroutine.cpp`)
    - Generates an infinite Fibonacci sequence using coroutines and `std::views::take`.

4. **Challenge: Functional Pipeline** (`challenge_pipeline.cpp`)
    - Generates numbers from 1 to 100, squares them, filters those divisible by 5, and selects the first 10.

## 🔧 Build and Run

First, navigate to the `Chapter_3` directory:
```sh
cd chapter_3/build
cmake ..
make