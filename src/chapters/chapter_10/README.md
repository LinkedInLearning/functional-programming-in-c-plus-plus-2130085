# Chapter 10: Blending Functional and Imperative Programming

Functional programming emphasizes immutability, pure functions, and declarative code, while imperative programming allows direct state manipulation and control flow. This chapter explores blending these paradigms for optimal flexibility and readability.

## 🚀 Examples

1. **Blending Functional and Imperative Code** (`blending_functional_imperative.cpp`)
    - Uses `std::copy_if` (functional) to filter values and `std::accumulate` (imperative) to sum them.

2. **Immutable Data Structures** (`immutable_data_structures.cpp`)
    - Uses `std::shared_ptr` to emulate immutability in a C++ list.

3. **Challenge: Functional Refactor** (`challenge_functional_refactor.cpp`)
    - Transforms an imperative loop into a functional pipeline with `std::transform` and `std::accumulate`.

## 🔧 Build and Run

### Build the examples
```sh
cd chapter_10/build
cmake ..
make