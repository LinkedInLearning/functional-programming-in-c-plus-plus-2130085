// challenge_adaptive_processor.cpp
#include <algorithm>
#include <boost/hana.hpp>
#include <cctype>
#include <iostream>
#include <string>
#include <variant>
#include <vector>

namespace hana = boost::hana;

using DataVariant = std::variant<int, std::string, std::vector<double>>;

int main() {
    DataVariant data = 5;
    auto config = hana::make_tuple(2.5, 3);

    auto visitor = [&](auto& arg) {
        hana::for_each(config, [&](auto param) {
            if (std::holds_alternative<int>(data)) {
                if constexpr (std::is_same_v<decltype(param), double>)
                    std::cout
                        << "Int: "
                        << (std::get<int>(data) * param + hana::at_c<1>(config))
                        << "\n";
            } else if (std::holds_alternative<std::string>(data)) {
                if constexpr (std::is_same_v<decltype(param), double>) {
                    std::string s = std::get<std::string>(data);
                    std::transform(
                        s.begin(), s.end(), s.begin(),
                        [](unsigned char c) { return std::toupper(c); });
                    std::cout << "Str: " << s << "\n";
                }
            } else if (std::holds_alternative<std::vector<double>>(data)) {
                if constexpr (std::is_same_v<decltype(param), double>) {
                    std::cout << "Vec: ";
                    for (double num : std::get<std::vector<double>>(data))
                        std::cout << (num * param + hana::at_c<1>(config))
                                  << " ";
                    std::cout << "\n";
                }
            }
        });
    };

    std::visit(visitor, data);
    data = std::string("less code");
    std::visit(visitor, data);
    data = std::vector<double>{1, 2, 3};
    std::visit(visitor, data);
    return 0;
}
