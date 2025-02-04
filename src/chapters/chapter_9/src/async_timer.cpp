#include <iostream>
#include <thread>
#include <chrono>

class Timer {
public:
    void start() {
        std::thread([this]() {  // Explicitly capture `this`
            for (int i = 0; i < 5; ++i) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "Tick " << i + 1 << std::endl;
            }
        }).detach();
    }
};

int main() {
    Timer t;
    t.start();
    std::this_thread::sleep_for(std::chrono::seconds(6)); // Ensure the program runs long enough
    return 0;
}
