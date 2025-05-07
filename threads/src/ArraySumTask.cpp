#include <random>
#include <chrono>
#include <time.h>
#include "ArraySumTask.hpp"

ArraySumTask::ArraySumTask(int array_size, int thread_num)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1);

    data_.reserve(array_size);

    for (size_t i = 0; i < array_size; i++)
        data_.push_back(dist(gen));

    for (size_t i = 0; i < thread_num; i++)
    {
        auto sum = std::promise<int>();
        return_values.push_back(sum.get_future());
        threads_.push_back(std::thread(&ArraySumTask::Calculate, this,
                            i*((array_size + thread_num - 1 )/ thread_num),
                            (i+1 == thread_num) ? array_size : i * ((array_size + thread_num - 1) / thread_num) + (array_size + thread_num - 1) / thread_num,
                            std::move(sum)));
    }
        
}

ArraySumTask::~ArraySumTask()
{
}

void ArraySumTask::Calculate(int from, int to, std::promise<int>&& p)
{
    int sum = 0;

    for (size_t i = from; i < to; i++)
        sum += data_[i];
    
    p.set_value(sum);
}

int ArraySumTask::Run()
{
    int final_sum = 0;
    clock_t t_start = clock();

    for(auto &t: threads_)
        t.join();

    for (size_t i = 0; i < threads_.size(); i++)
    {
        final_sum += return_values[i].get();
    }

    clock_t t_finish = clock();

    std::cout << "sum = " << final_sum << " time: " << (double)(t_finish - t_start) / CLOCKS_PER_SEC << std::endl;

    return final_sum;
}

int ArraySumTask::Check()
{
    int sum = 0;
    clock_t t_start = clock();

    for (auto val : data_)
        sum+= val;
    

    clock_t t_finish = clock();

    std::cout << "check sum = " << sum << " time: " << (double)(t_finish - t_start) / CLOCKS_PER_SEC << std::endl;

    return sum;
}