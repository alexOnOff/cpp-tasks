#pragma once

#include <iostream>
#include <thread>
#include <future>
#include <vector>

class ArraySumTask
{
public:
    ArraySumTask(int array_size = 10, int thread_num = 2);
    ~ArraySumTask();

    int Run();
    int Check();

private:
    std::vector<int> data_;
    std::vector<std::thread> threads_;
    std::vector<std::future<int>> return_values;
    std::mutex mtx_;
    
    void Calculate(int from, int to, std::promise<int>&& p);
};

