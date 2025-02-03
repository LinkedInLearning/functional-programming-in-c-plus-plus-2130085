#include <variant>
#include <iostream>
#include <string>

// Define variant type
using VarType = std::variant<int, double, std::string>;

// Overload structure for lambdas
struct Overloaded {
    void operator()(int arg) const {
        std::cout << "Integer: " << arg << "\n";
    }
    void operator()(double arg) const {
        std::cout << "Double: " << arg << "\n";
    }
    void operator()(const std::string& arg) const {
        std::cout << "String: " << arg << "\n";
    }
};

int main() {
    VarType value = 100;

    std::visit(Overloaded{}, value);

    value = 6.28;
    std::visit(Overloaded{}, value);

    value = std::string("Pattern Matching");
    std::visit(Overloaded{}, value);

    return 0;
}