#include <concepts>
#include <iostream>

// Requires clause constraining T to integral types
template <typename T>
requires std::is_integral_v<T>
T increment(T x) {
    return x + 1;
}

int main() {
    std::cout << increment(10) << "\n";  // Valid: int is integral
    // std::cout << increment(3.14);    // Error: double is not integral
}