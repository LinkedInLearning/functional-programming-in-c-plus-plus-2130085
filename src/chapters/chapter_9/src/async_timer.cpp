#include <iostream>
#include <chrono>
#include <thread>
#include <coroutine>

// Awaitable timer that suspends the coroutine
struct Timer {
    std::chrono::milliseconds duration;

    bool await_ready() { return false; }
    void await_suspend(std::coroutine_handle<> handle) {
        std::thread([=]() {
            std::this_thread::sleep_for(duration);
            handle.resume();
        }).detach();
    }
    void await_resume() {}
};

struct Task {
    struct promise_type {
        Task get_return_object() { return {}; }
        std::suspend_never initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() { std::terminate(); }
    };
};

// Asynchronous coroutine function
Task run_timer() {
    std::cout << "Timer started...\n";
    co_await Timer{std::chrono::seconds(2)};
    std::cout << "Timer completed!\n";
}

int main() {
    run_timer();
    std::this_thread::sleep_for(std::chrono::seconds(3));  // Wait for coroutine to finish
    return 0;
}