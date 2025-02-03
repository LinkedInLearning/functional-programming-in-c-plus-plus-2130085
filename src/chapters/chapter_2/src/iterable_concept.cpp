#include <concepts>
#include <iostream>
#include <vector>
#include <string>

// Concept to check if T has begin() and end()
template <typename T>
concept Iterable = requires(T t) {
{ t.begin() } -> std::same_as<decltype(t.end())>;
};

// Function to print elements of an iterable container
template <Iterable T>
void printContainer(const T& container) {
    for (const auto& item : container) {
        std::cout << item << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> numbers{1, 2, 3, 4, 5};
    printContainer(numbers);  // Valid

    std::string text = "Hello";
    printContainer(text);     // Valid

    // printContainer(42);    // Error: int is not iterable
}