#include <rxcpp/rx.hpp>
#include <iostream>

namespace rx = rxcpp;

int main() {
    // Create an observable stream emitting values from 1 to 5
    auto values = rx::observable<>::range(1, 5);

    // Subscribe to the stream and print each value
    values.subscribe([](int v) {
        std::cout << "Received: " << v << "\n";
    });

    return 0;
}