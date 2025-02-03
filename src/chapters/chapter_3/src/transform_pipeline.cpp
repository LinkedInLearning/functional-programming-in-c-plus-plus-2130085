#include <ranges>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8};

    auto pipeline = data
                    | std::views::transform([](int x) { return x * x; })  // Square the numbers
                    | std::views::filter([](int x) { return x % 2 == 0; }); // Keep even numbers

    for (int n : pipeline) {
        std::cout << n << " ";  // Output: 4 16 36 64
    }
    std::cout << std::endl;
}