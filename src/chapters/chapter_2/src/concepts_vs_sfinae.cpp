#include <concepts>
#include <iostream>
#include <type_traits>

// Concept version (C++20)
template <typename T>
requires std::is_arithmetic_v<T>
T square(T x) {
    return x * x;
}

// SFINAE version (Pre-C++20)
template <typename T, typename = std::enable_if_t<std::is_aritmetic_v<T>>>
T square_sfinae(T x) {
    return x * x;
}

int main() {
    std::cout << square(4) << "\n";         // Valid
    std::cout << square_sfinae(4) << "\n";  // Valid
}