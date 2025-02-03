#include <concepts>
#include <iostream>

// Floating point concept
template <typename T>
concept FloatingPoint = std::is_floating_point_v<T>;

// Multiply function for floating-point types
template <FloatingPoint T>
T multiply(T a, T b) {
return a * b;
}

int main() {
    std::cout << multiply(3.5, 2.0) << "\n";  // Valid: double
    std::cout << multiply(1.1f, 4.0f) << "\n"; // Valid: float
    // std::cout << multiply(5, 2);           // Error: int is not floating-point
}