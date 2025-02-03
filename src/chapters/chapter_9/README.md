# Chapter 9: Advanced Coroutines in C++

Coroutines, introduced in C++20, enable non-blocking programming by suspending and resuming execution. This chapter explores `co_yield`, `co_return`, and `co_await` to build lazy sequences and asynchronous workflows.

## 🚀 Examples

1. **Lazy Sequence Generator** (`coroutine_lazy_sequence.cpp`)
    - Uses `co_yield` to generate numbers lazily.

2. **Asynchronous Timer** (`async_timer.cpp`)
    - Uses `co_await` to manage a non-blocking delay.

3. **Challenge: Asynchronous Task Manager** (`challenge_async_task_manager.cpp`)
    - Runs multiple tasks concurrently using coroutines.

## 🔧 Build and Run

### Build the examples
```sh
cd chapter_9/build
cmake ..
make