#include <variant>
#include <iostream>

// Expression types
struct Add {
    int a, b;
};
struct Subtract {
    int a, b;
};
struct Value {
    int v;
};

// Define the variant for expressions
using Expression = std::variant<Add, Subtract, Value>;

// Visitor to evaluate the expression
struct Evaluate {
    int operator()(Add expr) const {
        return expr.a + expr.b;
    }
    int operator()(Subtract expr) const {
        return expr.a - expr.b;
    }
    int operator()(Value expr) const {
        return expr.v;
    }
};

int main() {
    Expression expr1 = Add{5, 3};       // 5 + 3
    Expression expr2 = Subtract{10, 4}; // 10 - 4
    Expression expr3 = Value{42};       // Just a value

    std::cout << "Result 1: " << std::visit(Evaluate{}, expr1) << "\n";
    std::cout << "Result 2: " << std::visit(Evaluate{}, expr2) << "\n";
    std::cout << "Result 3: " << std::visit(Evaluate{}, expr3) << "\n";

    return 0;
}