// refactor_imperative_to_functional.cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    // Imperative style
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<int> squared_numbers;
    for (int number : numbers) {
        squared_numbers.push_back(number * number);
    }

    // Functional Style refactoring
    std::vector<int> numbers2 = {1, 2, 3, 4, 5};
    std::vector<int> squared_numbers2(numbers2.size());
    std::transform(numbers2.begin(), numbers2.end(), squared_numbers2.begin(),
                   [](int n) { return n * n; });

    std::cout << "Imperative style: ";
    for (int num : squared_numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Functional style: ";
    for (int num : squared_numbers2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
