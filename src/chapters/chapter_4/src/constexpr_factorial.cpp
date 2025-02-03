#include <iostream>
#include <array>

// Factorial using constexpr function
constexpr int factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("Negative input!");
    }
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() {
    constexpr int result = factorial(6);  // Compile-time computation
    std::array<int, factorial(4)> arr = {};  // Array of size 24

    std::cout << "Factorial (constexpr) of 6: " << result << "\n";
    std::cout << "Array size (factorial 4): " << arr.size() << "\n";
    return 0;
}