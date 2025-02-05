// realtime_data_stream.cpp
#include <iostream>
#include <rxcpp/rx.hpp>
#include <chrono>
#include <thread>

int main() {
    auto source = rxcpp::observable<>::interval(std::chrono::milliseconds(500))
            .take(5)
            .map([](long i) { return "Data point " + std::to_string(i); });

    source.subscribe(
            [](const std::string& value) { std::cout << "Received: " << value << std::endl; },
            []() { std::cout << "Stream completed." << std::endl; }
    );

    // Keep the program alive until the stream completes
    std::this_thread::sleep_for(std::chrono::seconds(3));
    return 0;
}