#include <iostream>
#include <memory>
#include <vector>

// Immutable list wrapper
struct ImmutableList {
    std::shared_ptr<std::vector<int>> data;

    ImmutableList(std::initializer_list<int> values)
            : data(std::make_shared<std::vector<int>>(values)) {}

    ImmutableList add(int value) const {
        auto new_data = std::make_shared<std::vector<int>>(*data);
        new_data->push_back(value);
        return ImmutableList(new_data);
    }

    void print() const {
        for (const auto& v : *data) {
            std::cout << v << " ";
        }
        std::cout << "\n";
    }

private:
    explicit ImmutableList(std::shared_ptr<std::vector<int>> d) : data(std::move(d)) {}
};

int main() {
    ImmutableList list = {1, 2, 3};
    list.print();

    auto new_list = list.add(4);
    new_list.print();
    list.print();  // Original list remains unchanged

    return 0;
}