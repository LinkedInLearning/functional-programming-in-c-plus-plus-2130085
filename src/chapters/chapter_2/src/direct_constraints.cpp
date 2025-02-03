#include <concepts>
#include <iostream>

// Arithmetic concept - ensures the type is an arithmetic type (int, float, etc.)
template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

// Generic function that only works with arithmetic types
template <Arithmetic T>
T add(T a, T b) {
return a + b;
}

int main() {
    std::cout << add(5, 3) << "\n";          // Valid: int is arithmetic
    std::cout << add(4.5, 1.5) << "\n";      // Valid: double is arithmetic
    // std::cout << add("Hello", "World");   // Error: std::string is not Arithmetic
}