#include <functional>
#include <iostream>

// A higher-order function accepting move-only functions
void applyFunction(std::move_only_function<int(int)> func, int value) {
    std::cout << "Result: " << func(value) << "\n";
}

int main() {
    auto square = [](int x) { return x * x; };

    // Pass a lambda to applyFunction
    applyFunction(std::move(square), 5);

    return 0;
}