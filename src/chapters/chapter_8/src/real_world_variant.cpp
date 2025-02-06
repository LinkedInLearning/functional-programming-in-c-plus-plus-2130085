// real_world_variant.cpp
#include <iostream>
#include <string>
#include <variant>
#include <vector>

// Represents different types of messages a system might handle
using Message = std::variant<int, std::string, std::vector<double>>;

// Handles a specific message based on its type
void processMessage(const Message& msg) {
    std::visit(
        [](const auto& m) {
            using T = std::decay_t<decltype(m)>;
            if constexpr (std::is_same_v<T, int>) {
                std::cout << "Processing integer message: " << m << std::endl;
            } else if constexpr (std::is_same_v<T, std::string>) {
                std::cout << "Processing string message: " << m << std::endl;
            } else if constexpr (std::is_same_v<T, std::vector<double>>) {
                std::cout << "Processing vector message with " << m.size()
                    << " elements." << std::endl;
            }
        },
        msg);
}

int main() {
    std::vector<Message> messages = {
        Message(10),
        Message(std::string("Hello")),
        Message(std::vector<double>{
            1.0, 2.0, 3.0})
    };
    for (const auto& msg : messages) {
        processMessage(msg);
    }
    return 0;
}
