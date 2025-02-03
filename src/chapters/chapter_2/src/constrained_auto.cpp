#include <concepts>
#include <iostream>

// Integral Concept
template <typename T>
concept Integral = std::is_integral_v<T>;

Integral auto doubleValue(Integral auto x) {
    return x * 2;
}

int main() {
    std::cout << doubleValue(5) << "\n";   // Valid: 5 * 2 = 10
    // std::cout << doubleValue(3.14);    // Error: double is not Integral
}