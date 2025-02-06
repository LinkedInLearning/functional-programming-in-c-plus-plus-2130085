#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// Functional refactor of sum_squares
int sum_squares(const std::vector<int>& numbers) {
    auto is_odd = [](int x) { return x % 2 != 0; };
    auto square = [](int x) { return x * x; };

    std::vector<int> odd_squares;
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(odd_squares),
                   [=](int x) { return is_odd(x) ? square(x) : 0; });

    return std::accumulate(odd_squares.begin(), odd_squares.end(), 0);
}

int main() {
    std::vector<int> values = {1, 2, 3, 4, 5};

    int result = sum_squares(values);
    std::cout << "Sum of odd squares: " << result << "\n";

    return 0;
}