// functional_imperative_mix.cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Functional pipeline: Filter even numbers and square them
    std::vector<int> even_squares;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(even_squares), [](int x) { return x % 2 == 0; });
    std::transform(even_squares.begin(), even_squares.end(), even_squares.begin(), [](int x) { return x * x; });

    // Imperative loop: Print the results
    std::cout << "Even squares: ";
    for (int num : even_squares) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}