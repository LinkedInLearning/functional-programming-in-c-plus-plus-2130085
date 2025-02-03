#include <concepts>
#include <iostream>

// Arithmetic Concept
template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

// Concept requiring addition
template <typename T>
concept Addable = requires(T a, T b) {
{ a + b } -> std::convertible_to<T>;
};

// Function constrained by both Arithmetic and Addable
template <Arithmetic T>
T sum(T a, T b) requires Addable<T> {
        return a + b;
}

int main() {
    std::cout << sum(3, 7) << "\n";  // Valid
    std::cout << sum(2.5, 1.5) << "\n";  // Valid
    // std::cout << sum("Hello", "World");  // Error: strings are not Arithmetic
}