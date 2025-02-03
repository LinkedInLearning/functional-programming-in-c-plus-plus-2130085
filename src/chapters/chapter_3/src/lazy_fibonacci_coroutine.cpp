#include <iostream>
#include <ranges>
#include <coroutine>

struct Generator {
    struct promise_type {
        int current_value = 0;

        Generator get_return_object() { return Generator{this}; }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        void return_void() {}
        std::suspend_always yield_value(int value) {
            current_value = value;
            return {};
        }
        void unhandled_exception() { std::terminate(); }
    };

    Generator(promise_type* p) : promise(p) {}
    Generator(Generator&& other) noexcept : promise(std::exchange(other.promise, nullptr)) {}
    ~Generator() { if (promise) delete promise; }

    struct iterator {
        promise_type* promise;
        bool operator!=(std::default_sentinel_t) const { return true; }
        iterator& operator++() { promise->current_value += 1; return *this; }
        int operator*() const { return promise->current_value; }
    };

    iterator begin() { return iterator{promise}; }
    std::default_sentinel_t end() { return {}; }

private:
    promise_type* promise;
};

Generator fibonacci() {
    int a = 0, b = 1;
    while (true) {
        co_yield a;
        auto temp = a;
        a = b;
        b = temp + b;
    }
}

int main() {
    for (int n : fibonacci() | std::views::take(10)) {
        std::cout << n << " ";  // Output: 0 1 1 2 3 5 8 13 21 34
    }
    std::cout << std::endl;
}