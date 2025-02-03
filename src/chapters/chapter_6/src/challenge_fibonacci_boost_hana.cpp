#include <boost/hana.hpp>
#include <iostream>

namespace hana = boost::hana;

// Compile-time Fibonacci generator
constexpr auto fibonacci = [](auto n) {
    return hana::unfold_left(1, n, [](auto state) {
        return hana::if_(state < 2,
                         hana::make_tuple(state, state + 1),
                         hana::make_tuple(state, hana::second(state) + hana::first(state)));
    });
};

int main() {
    constexpr auto fibs = fibonacci(8);

    hana::for_each(fibs, [](auto x) {
        std::cout << x << " ";
    });
    std::cout << "\n"; // Output: 1 1 2 3 5 8 13 21

    return 0;
}