#include <array>
#include <iostream>

// Recursive constexpr factorial
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() {
    constexpr int result = factorial(5);  // Compile-time evaluation

    // Use the result in a compile-time array
    std::array<int, factorial(4)> arr = {};  // Array of size 24

    std::cout << "Factorial of 5: " << result << "\n";
    std::cout << "Size of array: " << arr.size() << "\n";

    return 0;
}