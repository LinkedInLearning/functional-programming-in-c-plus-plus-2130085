#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int main() {
    std::vector<int> numbers = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    // Define a range pipeline
    auto transformed_numbers = numbers
                               // Filter for even numbers
                               | std::views::filter([](int n){ return n % 2 == 0; })
                               // Square each even number
                               | std::views::transform([](int n){ return n * n; })
                               // Take only the first 3 squared even numbers
                               | std::views::take(3);

    // Print the transformed numbers
    std::cout << "Transformed numbers: ";
    for (int num : transformed_numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}