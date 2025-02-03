# Chapter 7: Functional Reactive Programming (FRP) with RxCpp

Functional Reactive Programming (FRP) models computations as reactions to asynchronous data streams and events. This chapter explores RxCpp, coroutines, and ranges for building reactive pipelines.

## 🚀 Examples

1. **Simple RxCpp Stream** (`rxcpp_simple_stream.cpp`)
    - Uses `rxcpp::observable` to emit and process a sequence of numbers.

2. **RxCpp with Coroutines and Ranges** (`rxcpp_coroutine_ranges.cpp`)
    - Integrates RxCpp with coroutines and `std::views::filter` for reactive transformations.

3. **Challenge: Word Frequency Counter** (`challenge_word_frequency.cpp`)
    - Implements an RxCpp-based word frequency counter.

## 🔧 Build and Run

First, ensure that RxCpp is installed on your system.

### Install RxCpp (if needed)
```sh
sudo apt install librxcpp-dev   # Ubuntu
brew install rxcpp              # macOS