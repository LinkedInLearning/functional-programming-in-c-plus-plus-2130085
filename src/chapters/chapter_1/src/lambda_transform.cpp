#include <iostream>
#include <vector>
#include <algorithm>

// Utility to print a vector
void print_vector(const std::vector<int>& vec) {
    for (int n : vec) std::cout << n << " ";
    std::cout << "\n";
}

// Using lambda with transform
void demo_lambda_transform(std::vector<int>& nums, int multiplier) {
    std::cout << "\n--- Lambda + Transform Walkthrough ---\n";

    std::cout << "Original numbers: ";
    print_vector(nums);

    std::transform(nums.begin(), nums.end(), nums.begin(),
                   [multiplier](int n) {
                       std::cout << "Multiplying " << n << " by " << multiplier << "\n";
                       return n * multiplier;
                   });

    std::cout << "After multiplying by " << multiplier << ": ";
    print_vector(nums);
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int multiplier = 3;

    demo_lambda_transform(nums, multiplier);

    return 0;
}