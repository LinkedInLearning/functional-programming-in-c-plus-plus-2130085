#include <boost/hana.hpp>
#include <iostream>

namespace hana = boost::hana;

// Computes the nth Fibonacci number at compile time
constexpr auto fibonacci = [](auto n) {
    // Helper function to compute Fibonacci using fold_left
    constexpr auto fib_impl = [](auto n, auto acc) {
        return hana::fold_left(hana::make_range(hana::int_c<0>, n), acc,
            [](auto acc, auto) {
                return hana::make_pair(hana::second(acc), hana::first(acc) + hana::second(acc));
            });
    };
    // Extract the second element, which is the nth Fibonacci number
    return hana::second(fib_impl(n, hana::make_pair(hana::int_c<0>, hana::int_c<1>)));
};

int main() {
    // Create a tuple of indices from 0 to 9
    constexpr auto indices = hana::to_tuple(hana::make_range(hana::int_c<0>, hana::int_c<10>));
    // Transform indices into their corresponding Fibonacci values
    constexpr auto fib_values = hana::transform(indices, fibonacci);

    // Print the Fibonacci sequence
    hana::for_each(fib_values, [](auto val) {
        std::cout << val << " ";
    });
    std::cout << std::endl;

    return 0;
}
