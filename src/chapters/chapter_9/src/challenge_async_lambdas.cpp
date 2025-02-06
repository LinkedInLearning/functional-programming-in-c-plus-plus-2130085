// challenge_async_lambdas.cpp
#include <iostream>
#include <future>
#include <vector>
#include <functional>
#include <thread>

void AsyncTask(std::function<void()> task) {
    std::async(std::launch::async, task);
}

int main() {
    // Create tasks using lambda expressions and launch them immediately
    auto task1 = std::async(std::launch::async, []() {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "Task 1 completed\n";
    });

    auto task2 = std::async(std::launch::async, []() {
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
        std::cout << "Task 2 completed\n";
    });

    auto task3 = std::async(std::launch::async, []() {
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        std::cout << "Task 3 completed\n";
    });

    // Create the vector of futures, initializing it with the tasks
    std::vector<std::future<void>> futures = {std::move(task1), std::move(task2), std::move(task3)};

    // Wait for tasks to complete
    for (auto& future : futures) {
        future.get(); // This blocks until the task is complete
    }

    std::cout << "All tasks completed.\n";

    return 0;
}