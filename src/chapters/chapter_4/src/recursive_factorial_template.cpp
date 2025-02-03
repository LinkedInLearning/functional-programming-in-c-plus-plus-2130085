#include <iostream>

// Primary template
template<int N>
struct Factorial {
    static constexpr int value = N * Factorial<N - 1>::value;
};

// Base case specialization
template<>
struct Factorial<0> {
    static constexpr int value = 1;
};

int main() {
    constexpr int result = Factorial<5>::value;  // Computed at compile time
    std::cout << "Factorial (template) of 5: " << result << "\n";
    return 0;
}