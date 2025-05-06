#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>

class QueueTask
{
public:
    QueueTask();
    ~QueueTask();

    void Run();

private:
    std::queue<int> queue_;
    std::thread producer_;
    std::thread consumer_;
    std::mutex print_mtx_;
    std::mutex queue_mtx_;
    std::condition_variable queue_cv_;
    int counter_ = 10;

    void ProducerWork();
    void ConsumerWork();
};