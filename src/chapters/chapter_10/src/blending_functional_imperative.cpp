//
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// Transform and sum even numbers using a functional pipeline
int sum_even_numbers(const std::vector<int>& numbers) {
    auto is_even = [](int x) { return x % 2 == 0; };

    std::vector<int> evens;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(evens), is_even);

    return std::accumulate(evens.begin(), evens.end(), 0);
}

int main() {
    std::vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8};

    int result = sum_even_numbers(values);
    std::cout << "Sum of even numbers: " << result << "\n";

    return 0;
}