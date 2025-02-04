#include <iostream>
#include <coroutine>

// Coroutine to generate a sequence of numbers
struct Generator {
    struct promise_type {
        int current_value;

        Generator get_return_object() {
            return Generator{std::coroutine_handle<promise_type>::from_promise(*this)};
        }

        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }

        void unhandled_exception() { std::terminate(); }

        std::suspend_always yield_value(int value) {
            current_value = value;
            return {};
        }

        void return_void() {}
    };

    std::coroutine_handle<promise_type> handle;

    explicit Generator(std::coroutine_handle<promise_type> h) : handle(h) {}

    ~Generator() {
        if (handle) handle.destroy();
    }

    int next() {
        if (handle.done()) return -1;  // End of sequence
        handle.resume();
        return handle.promise().current_value;
    }
};

Generator generate_numbers() {
    for (int i = 1; i <= 5; ++i) {
        co_yield i;  // Suspend and yield the next value
    }
}

int main() {
    auto gen = generate_numbers();

    // Fixed while-loop syntax
    int value;
    while ((value = gen.next()) != -1) {
        std::cout << "Generated: " << value << "\n";
    }

    return 0;
}
