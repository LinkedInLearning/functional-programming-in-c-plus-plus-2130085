#include <rxcpp/rx.hpp>
#include <iostream>
#include <coroutine>
#include <ranges>

namespace rx = rxcpp;

// Coroutine that returns an observable
rx::observable<int> generate_values() {
    for (int i = 1; i <= 10; ++i) {
        co_yield i;  // Emit each value to the observable stream
    }
}

int main() {
    auto stream = generate_values()
                  | std::views::filter([](int v) { return v % 2 == 0; })  // Filter even numbers
                  | std::views::transform([](int v) { return v * 2; });    // Double the values

    for (int v : stream) {
        std::cout << "Processed: " << v << "\n";
    }
    return 0;
}