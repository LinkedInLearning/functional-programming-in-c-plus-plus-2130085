// async_task_launch.cpp.cpp
#include <coroutine>
#include <iostream>
#include <memory>
#include <thread>

struct task {
    struct promise_type {
        task get_return_object() {
            return task{
                std::coroutine_handle<promise_type>::from_promise(*this)};
        }
        std::suspend_never initial_suspend() noexcept { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() {}
    };

    using handle_type = std::coroutine_handle<promise_type>;

    explicit task(handle_type h) : handle(h) {}

    // We no longer destroy the coroutine in the destructor
    ~task() = default;

    void resume() {
        if (handle) {
            handle.resume();
        }
    }

    handle_type handle;
};

// Function to properly manage coroutine execution
void run_async(task t) {
    std::thread([handle = t.handle]() mutable {
        handle.resume();  // Resume coroutine execution
        if (!handle.done()) {
            std::cerr << "Coroutine was suspended and not finished\n";
        }
        handle.destroy();  // Safe to destroy now since we check if it's done
    }).detach();
}

// Coroutine function
task my_async_task() {
    std::cout << "Starting async task" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Async task finished" << std::endl;
    co_return;
}

int main() {
    run_async(my_async_task());  // Launch coroutine properly

    std::cout << "Main function continues" << std::endl;
    std::this_thread::sleep_for(
        std::chrono::seconds(3));  // Give coroutine time to finish

    return 0;
}
