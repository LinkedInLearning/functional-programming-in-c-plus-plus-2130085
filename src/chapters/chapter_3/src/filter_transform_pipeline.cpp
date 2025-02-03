#include <ranges>
#include <iostream>

int main() {
    auto numbers = std::views::iota(1, 20);  // Infinite generator from 1 to 19

    auto result = numbers
                  | std::views::filter([](int x) { return x % 3 == 0; })  // Divisible by 3
                  | std::views::transform([](int x) { return x * 10; })   // Multiply by 10
                  | std::views::take(5);  // Take the first 5 results

    for (int n : result) {
        std::cout << n << " ";  // Output: 30 60 90 120 150
    }
    std::cout << std::endl;
}