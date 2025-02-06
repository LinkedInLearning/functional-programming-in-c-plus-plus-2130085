#include <iostream>
#include <vector>
#include <ranges>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8};

    auto even = [](int x) { return x % 2 == 0; };

    // Filter even numbers
    auto evens = numbers | std::views::filter(even);

    std::cout << "Even numbers: ";
    for (int n : evens) {
        std::cout << n << " ";
    }
    std::cout << "\n"; // Output: 2 4 6 8

    return 0;
}