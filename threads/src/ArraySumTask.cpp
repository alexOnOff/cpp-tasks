#include <random>
#include <chrono>
#include "ArraySumTask.hpp"

ArraySumTask::ArraySumTask(int array_size, int thread_num)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1);

    data_.reserve(array_size);

    for (size_t i = 0; i < array_size; i++)
    {
        data_.push_back(dist(gen));
        std::cout << data_[i] << ' ';
    }
        
    std::cout << std::endl;

    for (size_t i = 0; i < thread_num; i++)
    {
        auto sum = std::promise<int>();
        return_values.push_back(sum.get_future());
        threads_.push_back(std::thread(&ArraySumTask::Calculate, this,
                            i*(array_size / thread_num), 
                            (i+1 == thread_num) ? array_size : i * (array_size / thread_num), 
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
    {
        //std::lock_guard<std::mutex> lock(mtx_);
        sum += data_[i];
    }

    p.set_value(sum);
}

int ArraySumTask::Run()
{
    int final_sum = 0;

    for(auto &t: threads_)
        t.join();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    for (size_t i = 0; i < threads_.size(); i++)
    {
        auto val = return_values[i].get();
        std::cout << "part = " << val << std::endl;
        final_sum += val;
    }

    std::cout << "sum = " << final_sum << std::endl;

    return final_sum;
}

int ArraySumTask::Check()
{
    int sum = 0;

    for (auto val : data_)
    {
        sum+= val;
    }

    std::cout << "check sum = " << sum << std::endl;

    return sum;
}