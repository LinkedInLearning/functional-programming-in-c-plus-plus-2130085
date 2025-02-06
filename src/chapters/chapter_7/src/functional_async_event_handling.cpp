#include <algorithm>
#include <functional>
#include <future>
#include <iostream>
#include <thread>  // Ensure thread support
#include <vector>

using EventHandler = std::function<void(const std::string&)>;

void simulateEventSource(EventHandler handler) {
    std::vector<std::string> events = {"Event 1", "Event 2", "Event 3",
                                       "Event 4", "Event 5"};

    std::vector<std::future<void>> futures;
    for (const auto& event : events) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        futures.push_back(std::async(std::launch::async, handler, event));
    }

    // Ensure all async tasks finish
    for (auto& f : futures) {
        f.wait();
    }
}

int main() {
    EventHandler functionalHandler = [](const std::string& event) {
        std::cout << "[Functional] Received event: " << event << " in thread "
                  << std::this_thread::get_id() << std::endl;
    };

    auto safeFunctionalHandler = [&](const std::string& event) {
        try {
            functionalHandler(event);
        } catch (const std::exception& e) {
            std::cerr << "Exception in handler: " << e.what() << std::endl;
        }
    };

    simulateEventSource(safeFunctionalHandler);

    std::cout << "Exiting main thread." << std::endl;
    return 0;
}
