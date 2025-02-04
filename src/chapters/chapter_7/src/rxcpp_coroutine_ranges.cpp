#include <rxcpp/rx.hpp>
#include <iostream>

rxcpp::observable<int> generate_values() {
    return rxcpp::observable<>::create<int>([](rxcpp::subscriber<int> subscriber) {
        for (int i = 0; i < 10; ++i) {
            subscriber.on_next(i);
        }
        subscriber.on_completed();
    });
}

int main() {
    auto stream = generate_values()
        .filter([](int v) { return v % 2 == 0; });  // Use RxCpp's filter operator

    stream.subscribe(
        [](int v) { std::cout << "Received: " << v << std::endl; },
        []() { std::cout << "Stream completed" << std::endl; }
    );

    return 0;
}
