#include <variant>
#include <iostream>
#include <string>

// Define a variant that can hold int, double, or std::string
using VarType = std::variant<int, double, std::string>;

int main() {
    VarType value = 42;  // Initially an int

    // Define a visitor (overloaded lambdas)
    auto visitor = [](auto&& arg) {
        std::cout << "Type: " << typeid(arg).name() << ", Value: " << arg << "\n";
    };

    // Apply visitor to the variant
    std::visit(visitor, value);

    // Assign a different type to the variant
    value = 3.14;
    std::visit(visitor, value);

    value = std::string("Hello, world!");
    std::visit(visitor, value);

    return 0;
}