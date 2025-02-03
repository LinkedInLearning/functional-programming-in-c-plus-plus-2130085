#include <iostream>

// constexpr Fibonacci function
constexpr int fibonacci(int n) {
    return (n <= 1) ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    constexpr int fib10 = fibonacci(10);
    constexpr int fib7 = fibonacci(7);

    std::cout << "Fibonacci(10): " << fib10 << "\n";
    std::cout << "Fibonacci(7): " << fib7 << "\n";

    return 0;
}