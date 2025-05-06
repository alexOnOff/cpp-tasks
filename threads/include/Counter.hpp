#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

class Counter
{
public:
    Counter();
    ~Counter();

    void Run();
    void RunAtomic();

private:
    std::mutex mtx_;
    int counter_ = 0;
    std::atomic<int> atomic_counter_ = 0;

    const int COUNTER_MAX_VALUE_ = 1000;

    void Add(int& c, int thread_num);
    void AddAtomic(int thread_num);
};