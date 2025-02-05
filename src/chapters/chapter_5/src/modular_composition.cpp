// modular_composition.cpp

#include <iostream>
#include <functional>

auto increment = [](int x) { return x + 1; };
auto square = [](int x) { return x * x; };

auto compose(auto f, auto g) {
    return [f, g](auto x) { return f(g(x)); };
}

int main() {
    auto increment_then_square = compose(square, increment);
    std::cout << increment_then_square(3) << std::endl; // Outputs 16 ( (3 + 1) ^ 2 )
    return 0;
}