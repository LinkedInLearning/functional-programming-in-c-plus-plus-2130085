#include <iostream>
#include <vector>
#include <numeric>
#include <ranges>

void demo_accumulate(const std::vector<int>& nums) {
    std::cout << "\n--- Accumulate Walkthrough ---\n";

    auto squared = nums | std::views::transform([](int x) { return x * x; });

    int sum_of_squares = std::accumulate(squared.begin(), squared.end(), 0,
                                         [](int sum, int x) {
                                             std::cout << "Adding " << x << " to sum (" << sum << ")\n";
                                             return sum + x;
                                         });

    std::cout << "Sum of squares: " << sum_of_squares << "\n";
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    demo_accumulate(nums);

    return 0;
}