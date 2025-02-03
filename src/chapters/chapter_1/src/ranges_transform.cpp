#include <iostream>
#include <vector>
#include <ranges>

void demo_ranges_transform(const std::vector<int>& nums) {
    std::cout << "\n--- Ranges::Transform Walkthrough ---\n";

    auto squared = nums | std::views::transform([](int x) {
        std::cout << "Squaring " << x << "\n";
        return x * x;
    });

    std::cout << "Squared values: ";
    for (int n : squared) std::cout << n << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    demo_ranges_transform(nums);

    return 0;
}