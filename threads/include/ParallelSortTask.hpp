#pragma once

#include<iostream>
#include<vector>
#include<thread>
#include<random>

class ParallelSortTask
{
public:
    ParallelSortTask(size_t array_size = 10, unsigned thread_num = 2);
    ~ParallelSortTask();

    void Run();
    void Check();
private:
    unsigned thread_num_;
    std::vector< int> nums_;
};
