// challenge_async_lambdas.cpp
#include <functional>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

void AsyncTask(std::function<void()> task) {
    std::async(std::launch::async, task);
}

int main() {
    // Create tasks using lambda expressions and launch them immediately
    std::future<void> task1 = std::async(std::launch::async, []() {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "Task 1 completed\n";
    });

    std::future<void> task2 = std::async(std::launch::async, []() {
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
        std::cout << "Task 2 completed\n";
    });

    std::future<void> task3 = std::async(std::launch::async, []() {
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        std::cout << "Task 3 completed\n";
    });

    // Create the vector of futures and explicitly move each future
    std::vector<std::future<void>> futures;
    futures.push_back(std::move(task1));
    futures.push_back(std::move(task2));
    futures.push_back(std::move(task3));

    // Wait for tasks to complete
    for (auto& future : futures) {
        future.get();  // This blocks until the task is complete
    }

    std::cout << "All tasks completed.\n";

    return 0;
}
