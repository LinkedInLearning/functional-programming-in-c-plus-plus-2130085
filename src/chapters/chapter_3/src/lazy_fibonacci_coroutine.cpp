#include <coroutine>
#include <iostream>
#include <memory>
#include <optional>
#include <ranges>
#include <vector>
#include <span>

// Coroutine return type
struct Generator {
    struct promise_type {
        std::optional<int> current_value;

        Generator get_return_object() {
            return Generator{std::coroutine_handle<promise_type>::from_promise(*this)};
        }

        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }

        std::suspend_always yield_value(int value) {
            current_value = value;
            return {};
        }

        void return_void() {}
        void unhandled_exception() { std::terminate(); }
    };

    std::coroutine_handle<promise_type> handle;

    explicit Generator(std::coroutine_handle<promise_type> h) : handle(h) {}
    Generator(const Generator&) = delete;
    Generator(Generator&& other) noexcept : handle(other.handle) { other.handle = {}; }
    ~Generator() { if (handle) handle.destroy(); }

    std::optional<int> next() {
        if (!handle || handle.done()) return std::nullopt;
        handle.resume();
        return handle.promise().current_value;
    }
};

// Infinite Fibonacci coroutine generator
Generator fibonacci() {
    int a = 0, b = 1;
    while (true) {
        co_yield a;
        int temp = a + b;
        a = b;
        b = temp;
    }
}

int main() {
    auto gen = fibonacci();
    for (int i = 0; i < 20; ++i) {
        if (auto value = gen.next()) {
            std::cout << *value << " ";
        } else {
            break;
        }
    }
    std::cout << std::endl;

    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Use std::ranges::views::all to avoid ref_view issues
    auto transformed = std::ranges::views::all(numbers) | std::views::transform([](int x) { return x * x; });

    std::cout << "Transformed numbers: ";
    for (int x : transformed) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
