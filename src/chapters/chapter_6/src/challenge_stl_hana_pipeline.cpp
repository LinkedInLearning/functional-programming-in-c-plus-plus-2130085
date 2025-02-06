// challenge_stl_hana_pipeline.cpp
#include <iostream>
#include <vector>
#include <ranges>
#include <numeric>
#include <algorithm>
#include <boost/hana.hpp>

namespace hana = boost::hana;

// Generic function to display any iterable
template <typename Iterable>
void display(const Iterable& iterable, const std::string& label) {
    std::cout << label << ": ";
    for (const auto& item : iterable) std::cout << item << " ";
    std::cout << "\n";
}

int main() {
    // Step 1: Generate the numbers 1 to 12 and assign to numbers
    auto numbers = std::views::iota(1, 13);
    display(numbers, "Original numbers");

    // Step 2: Filter out only the odd numbers
    auto odds = numbers | std::views::filter([](int x) { return x % 2 != 0; });
    display(odds, "Filtered odds");

    // Step 3: Square the filtered numbers
    auto squared = odds | std::views::transform([](int x) { return x * x; });
    display(squared, "Squared values");

    // Step 4: Compute the sum of the squared numbers
    int sum_of_squares = std::accumulate(squared.begin(), squared.end(), 0);
    std::cout << "Sum of squares: " << sum_of_squares << "\n";

    // Step 5: Store the results in a tuple (sum of squares, doubled sum)
    auto result_tuple = hana::make_tuple(sum_of_squares, sum_of_squares * 2);

    // Step 6: Retrieve and print the values from the tuple
    std::cout << "Sum of squares: " << hana::at_c<0>(result_tuple) << "\n";
    std::cout << "Doubled sum: " << hana::at_c<1>(result_tuple) << "\n";

    return 0;
}