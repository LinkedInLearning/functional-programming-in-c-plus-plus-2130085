#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Lambda to square a number
auto square = [](int x) { return x * x; };

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Use transform to square each element
    std::vector<int> squared(numbers.size());
    std::transform(numbers.begin(), numbers.end(), squared.begin(), square);

    // Sum the squared numbers
    int sum = std::accumulate(squared.begin(), squared.end(), 0);

    std::cout << "Sum of squares: " << sum << "\n"; // Output: 55

    return 0;
}