#include <iostream>
#include <functional>
#include <utility>

// Composes two functions
auto compose(auto f, auto g) {
    return [f, g](auto x) {
        return std::invoke(f, std::invoke(g, x));
    };
}

int increment(int x) { return x + 1; }

int main() {
    auto square = [](int x) { return x * x; };
    auto incrementAndSquare = compose(square, increment);

    std::cout << "Result: " << incrementAndSquare(4) << "\n"; // Output: 25

    return 0;
}