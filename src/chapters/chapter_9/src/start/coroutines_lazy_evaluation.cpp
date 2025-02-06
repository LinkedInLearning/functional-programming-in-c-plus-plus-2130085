// coroutines_lazy_evaluation.cpp
#include <iostream>
#include <coroutine>

struct LazyValue {
    struct promise_type {
        int value;
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        LazyValue get_return_object() { return LazyValue{std::coroutine_handle<promise_type>::from_promise(*this)}; }
        std::suspend_always yield_value(int v) {
            value = v;
            return {};
        }
        void return_void() {}
        void unhandled_exception() {}
    };

    using handle_type = std::coroutine_handle<promise_type>;
    handle_type coroutine;

    LazyValue(handle_type h) : coroutine(h) {}
    ~LazyValue() { if (coroutine) coroutine.destroy(); }

    int get() {
        coroutine.resume();
        return coroutine.promise().value;
    }
};

LazyValue compute_value() {
    std::cout << "Computing value..." << std::endl;
    co_yield 42; // Simulate a time-consuming computation
}

int main() {
    LazyValue lazy_value = compute_value(); // Nothing is computed yet
    std::cout << "Value is needed..." << std::endl;
    int value = lazy_value.get(); // Now the coroutine runs and computes the value
    std::cout << "Value: " << value << std::endl;
    return 0;
}