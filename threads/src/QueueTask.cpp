#include <random>
#include <iostream>
#include <chrono>
#include "QueueTask.hpp"

QueueTask::QueueTask(){}

QueueTask::~QueueTask(){}

void QueueTask::Run()
{
    consumer_ = std::thread(&QueueTask::ProducerWork, this);
    producer_ = std::thread(&QueueTask::ConsumerWork, this);

    consumer_.join();
    producer_.join();

    std::this_thread::sleep_for(std::chrono::seconds(2));
}

void QueueTask::ProducerWork()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    {
        std::unique_lock<std::mutex> locker(print_mtx_);
        std::cout << "producer started..." << std::endl;
    }

    while (counter_ > 0)
    {
        int val = dist(gen);

        {
            std::unique_lock<std::mutex> locker(print_mtx_);
            std::cout << "producer generate " << val << std::endl;
        }

        {
            std::unique_lock<std::mutex> locker(queue_mtx_);
            queue_.push(val);
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

        counter_--;
        queue_cv_.notify_one();
    }
}

void QueueTask::ConsumerWork()
{
    {
        std::unique_lock<std::mutex> locker(print_mtx_);
        std::cout << "consumer started..." << std::endl;
    }
    
    while (counter_ > 0)
    {
        std::unique_lock<std::mutex> locker(queue_mtx_);

        queue_cv_.wait(locker);

        while (!queue_.empty())
        {
            std::unique_lock<std::mutex> locker(print_mtx_);
            std::cout << "consumer take " << queue_.front() << std::endl;
            queue_.pop();
        }
    }
}