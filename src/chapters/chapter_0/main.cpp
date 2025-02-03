#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>

int main() {
    // Get the current time point
    auto now = std::chrono::system_clock::now();

    // Convert to time_t (for compatibility with C-style time functions)
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    // Format the time as a readable string
    std::tm local_time = *std::localtime(&now_c);

    std::cout << "Current Date and Time: "
              << std::put_time(&local_time, "%Y-%m-%d %H:%M:%S")
              << std::endl;

    return 0;
}
