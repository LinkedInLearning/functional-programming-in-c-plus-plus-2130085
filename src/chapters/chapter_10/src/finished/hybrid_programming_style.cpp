// hybrid_programming_style.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Functional part (filtering and transformation)
    std::vector<int> processed_data;
    std::copy_if(data.begin(), data.end(), std::back_inserter(processed_data), [](int x) { return x % 2 == 0; }); // Filter even numbers
    std::transform(processed_data.begin(), processed_data.end(), processed_data.begin(), [](int x) { return x * 2; }); // Multiply by 2

    // Imperative part (aggregation with a possible side-effect of printing)
    int sum = 0;
    for (int value : processed_data) {
        std::cout << "Processing value: " << value << std::endl;  // Side effect for logging
        sum += value;
    }

    std::cout << "Final sum: " << sum << std::endl;

    return 0;
}