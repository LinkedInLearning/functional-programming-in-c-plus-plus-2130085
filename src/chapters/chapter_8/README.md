# Chapter 8: Pattern Matching with std::variant and std::visit

Pattern matching simplifies handling different types within a single value. This chapter explores `std::variant` and `std::visit`, demonstrating type-safe dispatching for functional programming.

## 🚀 Examples

1. **Basic Pattern Matching** (`basic_pattern_matching.cpp`)
    - Uses `std::variant` and `std::visit` to handle multiple types dynamically.

2. **Type-Specific Overloads** (`type_specific_overloads.cpp`)
    - Uses struct-based overload resolution to process different variant types cleanly.

3. **Challenge: Arithmetic Expression Evaluator** (`challenge_expression_evaluator.cpp`)
    - Evaluates mathematical expressions using pattern matching.

## 🔧 Build and Run

### Build the examples
```sh
cd chapter_8/build
cmake ..
make