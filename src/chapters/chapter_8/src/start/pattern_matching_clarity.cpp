// pattern_matching_clarity.cpp
#include <iostream>
#include <variant>
#include <string>

struct PrintVisitor {
    void operator()(int i) const { std::cout << "Integer: " << i << std::endl; }
    void operator()(double d) const { std::cout << "Double: " << d << std::endl; }
    void operator()(const std::string& s) const { std::cout << "String: " << s << std::endl; }
};

int main() {
    std::variant<int, double, std::string> data = 3.14;
    std::visit(PrintVisitor{}, data);
    return 0;
}