# Chapter 4: Template Metaprogramming and Compile-Time Computation

C++ template metaprogramming enables computations at compile time, reducing runtime overhead. This chapter explores recursive templates and `constexpr` functions in C++20/23.

## 🚀 Examples

1. **Recursive Templates for Factorial** (`recursive_factorial_template.cpp`)
    - Computes factorial using recursive template instantiations.

2. **Compile-Time Factorial Using constexpr** (`constexpr_factorial.cpp`)
    - Uses `constexpr` functions to compute factorial at compile time.

3. **Fibonacci Sequence with constexpr** (`constexpr_fibonacci.cpp`)
    - Computes Fibonacci numbers at compile time.

4. **Matrix Multiplication at Compile Time** (`constexpr_matrix_multiplication.cpp`)
    - Performs matrix multiplication entirely at compile time.

5. **Challenge: constexpr Factorial** (`challenge_constexpr_factorial.cpp`)
    - Uses `constexpr` to compute factorial and define an array size.

## 🔧 Build and Run

First, navigate to the `Chapter_4` directory:
```sh
cd chapter_4/build
cmake ..
make