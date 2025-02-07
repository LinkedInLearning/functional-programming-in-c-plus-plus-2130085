#include <chrono>
#include <functional>
#include <future>
#include <iostream>
#include <thread>
#include <utility>

// A pure function that performs some computation
int compute_value(int input) {
    // Simulate a time-consuming operation
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return input * 2;
}

// Another pure function for further processing
int process_value(int input) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return input + 10;
}

// Function to launch a computation asynchronously
std::future<int> launch_async_task(std::function<int(int)> task_func, int input) {
    std::packaged_task<int(int)> task(task_func);
    std::future<int> future_result = task.get_future();

    std::thread t([task = std::move(task), input]() mutable { task(input); });
    t.detach();

    return future_result;
}

int main() {
    const int initial_value = 21;

    // Launch the first asynchronous computation
    std::future<int> future_value =
        launch_async_task(compute_value, initial_value);

    std::cout << "Main function continues" << std::endl;

    // Do some other work in the main thread
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // Get the intermediate value
    int intermediate_value = future_value.get();
    std::cout << "Intermediate value: " << intermediate_value << std::endl;

    // Launch the second asynchronous computation with the intermediate value
    std::future<int> final_future =
        launch_async_task(process_value, intermediate_value);

    // Get the final result
    int final_result = final_future.get();

    std::cout << "Initial value: " << initial_value << std::endl;
    std::cout << "Final result: " << final_result << std::endl;

    return 0;
}
