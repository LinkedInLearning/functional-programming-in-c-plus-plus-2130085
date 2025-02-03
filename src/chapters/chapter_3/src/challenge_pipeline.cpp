#include <ranges>
#include <iostream>

int main() {
    // Create a pipeline to process numbers from 1 to 100
    auto result = std::views::iota(1, 101)  // Generate numbers from 1 to 100
                  | std::views::transform([](int x) { return x * x; })  // Square each number
                  | std::views::filter([](int x) { return x % 5 == 0; })  // Filter divisible by 5
                  | std::views::take(10);  // Take the first 10 results

    // Print the results
    std::cout << "First 10 squared numbers divisible by 5:\n";
    for (int n : result) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}