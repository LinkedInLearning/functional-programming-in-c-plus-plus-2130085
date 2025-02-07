// immutable_shared.cpp
#include <iostream>
#include <memory>

struct ImmutableData {
    int value;
};

int main() {
    std::shared_ptr<ImmutableData> data = std::make_shared<ImmutableData>();
    data -> value = 42;

    std::shared_ptr<ImmutableData> data2 = data;

    // To "modify" immutably, create a new instance
    std::shared_ptr<ImmutableData> data3 = std::make_shared<ImmutableData>();
    data3->value = data->value + 10;

    std::cout << "Data1 value: " << data->value << std::endl;
    std::cout << "Data2 value: " << data2->value << std::endl;
    std::cout << "Data3 value: " << data3->value << std::endl;

    return 0;
}
