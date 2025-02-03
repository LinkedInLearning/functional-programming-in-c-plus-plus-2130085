#include <iostream>
#include <vector>
#include <numeric>

// Recursive factorial function
int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

// Sum of factorials using accumulate and lambda
void factorial_challenge(const std::vector<int>& nums) {
    std::cout << "\n--- Factorial Challenge Solution ---\n";

    int sum_of_factorials = std::accumulate(nums.begin(), nums.end(), 0,
                                            [](int sum, int n) {
                                                int fact = factorial(n);
                                                std::cout << "Factorial of " << n << " is " << fact << "\n";
                                                return sum + fact;
                                            });

    std::cout << "Sum of factorials: " << sum_of_factorials << "\n";
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};

    factorial_challenge(nums);

    return 0;
}