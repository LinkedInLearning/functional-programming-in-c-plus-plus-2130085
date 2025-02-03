#include <iostream>
#include <functional>

// Multiply function for bind demonstration
int multiply(int x, int y) {
    return x * y;
}

void demo_bind() {
    std::cout << "\n--- std::bind Walkthrough ---\n";

    auto times_five = std::bind(multiply, std::placeholders::_1, 5);
    int result = times_five(10);

    std::cout << "10 multiplied by 5: " << result << "\n";
}

int main() {
    demo_bind();
    return 0;
}