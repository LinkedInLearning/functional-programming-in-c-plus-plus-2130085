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

    // No destructor cleanup, we handle cleanup elsewhere
    ~task() = default;

    void resume() {
        if (handle) {
            handle.resume();
        }
    }

    handle_type handle;
};

// Run the coroutine in a separate thread while ensuring proper cleanup
void run_async(task t) {
    std::thread([handle = t.handle]() {
        handle.resume();  // Run the coroutine

        while (!handle.done()) {
            std::this_thread::yield();  // Ensure the coroutine is done
        }

        handle.destroy();  // Now it's safe to destroy the coroutine
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
    // Allocate the coroutine on the heap to ensure it survives
    auto* t = new task(my_async_task());
    run_async(*t);  // Launch coroutine properly

    std::cout << "Main function continues" << std::endl;
    std::this_thread::sleep_for(
        std::chrono::seconds(5));  // Give coroutine time to finish

    delete t;  // Free the allocated memory

    return 0;
}
