// combining_boost_hana_example.cpp
#include <iostream>
#include <boost/hana.hpp>

namespace hana = boost::hana;

int main() {
    auto tuple = hana::make_tuple(1, 2.0, "hello");

    hana::for_each(tuple, [](auto x) {
        std::cout << x << std::endl;
    });

    return 0;
}