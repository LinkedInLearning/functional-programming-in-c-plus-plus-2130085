#include <iostream>
#include <vector>
#include <coroutine>
#include <thread>

// Awaitable task that performs simulated work
struct WorkTask {
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

// Coroutine task
struct Task {
    struct promise_type {
        Task get_return_object() { return {}; }
        std::suspend_never initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() { std::terminate(); }
    };
};

// Task manager coroutine
Task run_tasks() {
    std::vector<std::chrono::milliseconds> durations = {
            std::chrono::milliseconds(500),
            std::chrono::milliseconds(1000),
            std::chrono::milliseconds(1500)
    };

    for (auto d : durations) {
        std::cout << "Starting task for " << d.count() << " ms\n";
        co_await WorkTask{d};
        std::cout << "Task completed after " << d.count() << " ms\n";
    }
}

int main() {
    run_tasks();
    std::this_thread::sleep_for(std::chrono::seconds(2));  // Wait for tasks to complete
    return 0;
}