#include <iostream>
#include <string> // Include <string> for string operations
#include <boost/hana.hpp>

int main() {
    auto my_tuple = boost::hana::make_tuple(10, "hello", 3.14);

    auto transformed_tuple = boost::hana::transform(my_tuple, [](auto x) {
        if constexpr (std::is_same_v<decltype(x), const char*>) {
            // Concatenate C-style strings using std::string
            std::string str(x);
            return str + str;
        } else {
            // For other types (int, double), just add
            return x + x;
        }
    });

    boost::hana::for_each(transformed_tuple, [](auto x) {
        std::cout << x << std::endl;
    });

    return 0;
}
