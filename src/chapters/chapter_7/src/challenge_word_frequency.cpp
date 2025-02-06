// challenge_word_frequency.cpp
#include <rxcpp/rx.hpp>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

namespace rx = rxcpp;

// Observable that emits words from a list
auto word_stream(const std::vector<std::string>& words) {
    return rx::observable<>::iterate(words);
}

int main() {
    std::vector<std::string> words = {
            "hello", "world", "hello", "functional", "world", "programming"
    };

    // Create word stream
    auto stream = word_stream(words);
    std::unordered_map<std::string, int> word_count;

    // Process the stream
    stream.subscribe([&](const std::string& word) {
                         word_count[word]++;
                     },
                     []() {
                         std::cout << "Stream completed.\n";
                     });

    for (const auto& [word, count] : word_count) {
        std::cout << word << ": " << count << "\n";
    }

    return 0;
}