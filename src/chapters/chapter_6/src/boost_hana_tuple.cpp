#include <boost/hana.hpp>
#include <iostream>
#include <string>

namespace hana = boost::hana;

int main() {
    auto tuple = hana::make_tuple(1, "Hello", 3.14);

    // Apply a transformation to each element
    auto transformed = hana::transform(tuple, [](auto x) {
        return x + x;
    });

    // Print the results
    hana::for_each(transformed, [](auto x) {
        std::cout << x << " ";
    });
    std::cout << "\n"; // Output: 2 HelloHello 6.28

    return 0;
}