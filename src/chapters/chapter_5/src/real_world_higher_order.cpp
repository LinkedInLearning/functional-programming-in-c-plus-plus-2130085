// real_world_higher_order.cpp

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    std::vector<int> squared_numbers(numbers.size());

    // Use std::transform (higher-order function) to square each element
    std::transform(numbers.begin(), numbers.end(), squared_numbers.begin(),
                   [](int x) { return x * x; }
    );

    for (int num: squared_numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}