#include <iostream>
#include <functional>

// Composes three functions
auto pipeline(auto f1, auto f2, auto f3) {
    return [=](auto x) {
        return std::invoke(f1, std::invoke(f2, std::invoke(f3, x)));
    };
}

int main() {
    auto add3 = [](int x) { return x + 3; };
    auto doubleValue = [](int x) { return x * 2; };
    auto decrement = [](int x) { return x - 1; };

    auto processPipeline = pipeline(decrement, doubleValue, add3);

    std::cout << "Pipeline Result: " << processPipeline(5) << "\n"; // Output: 15

    return 0;
}