// async_task_launch.cpp.cpp
#include <iostream>
#include <coroutine>
#include <future>
#include <thread>
#include <functional> // Needed for std::function

struct task {
    struct promise_type {
        task get_return_object() { return {std::coroutine_handle<promise_type>::from_promise(*this)}; }
        std::suspend_never initial_suspend() noexcept { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        void unhandled_exception() {}
        void return_void() {}
    };

    using handle_type = std::coroutine_handle<promise_type>;

    task(handle_type h) : handle(h) {}
    ~task() { if (handle) handle.destroy(); }

    handle_type handle;
};

// Introduce AsyncTask function
void AsyncTask(std::function<task()> coroutineTask) {
    std::async(std::launch::async, coroutineTask);
}

task my_async_task() {
    std::cout << "Starting async task" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Async task finished" << std::endl;
    co_return;
}

int main() {
    // Use AsyncTask to launch the coroutine
    AsyncTask([]() { return my_async_task(); }); // Wrap the coroutine in a lambda

    std::cout << "Main function continues" << std::endl;
    // No need to join, the coroutine will run in its own thread.
    std::this_thread::sleep_for(std::chrono::seconds(3));
    return 0;
}