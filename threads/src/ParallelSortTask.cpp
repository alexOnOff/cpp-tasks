#include "ParallelSortTask.hpp"
#include "QuickSort.hpp" 
#include <algorithm>

ParallelSortTask::ParallelSortTask(size_t array_size, unsigned thread_num) : thread_num_(thread_num)
{
    std::random_device rd;   
    std::mt19937 gen(rd());  
    std::uniform_int_distribution<int> dist(-5, 5); 

    nums_.reserve(array_size);

    for (size_t i = 0; i < array_size; i++)
        nums_.push_back(dist(gen));
}

ParallelSortTask::~ParallelSortTask()
{
    nums_.clear();
}

void ParallelSortTask::Run()
{
    //std::vector<int> copy;
    //std::copy(nums_.begin(), nums_.end(), std::back_inserter(copy));

    std::vector<std::thread> threads;
    size_t chunk_size = nums_.size() / thread_num_;
    size_t step = chunk_size;

    clock_t t_start = clock();

    for (size_t i = 0; i < thread_num_; i++)
    {
        size_t start = i * chunk_size;
        size_t end = (i == thread_num_ - 1)? nums_.size() - 1 : start + chunk_size - 1;
        threads.emplace_back(QuickSort<std::vector<int>, int>, std::ref(nums_), start, end);
    }

    for (auto& thread: threads)
        thread.join();
    
    while (step < nums_.size())
    {
        for (size_t i = 0; i < nums_.size() - step; i += 2 * step)
        {
            size_t left = i;
            size_t mid = i + step;
            size_t right = std::min<size_t>(i + 2 * step, nums_.size());
            std::inplace_merge(nums_.begin() + left, nums_.begin() + mid, nums_.begin() + right);
        }
        step *= 2;
    }

    clock_t t_finish = clock();

    std::cout << "parralel time: " << (double)(t_finish - t_start) / CLOCKS_PER_SEC << std::endl;

    //t_start = clock();
    //QuickSort<std::vector<int>, int>(copy, 0, copy.size() - 1);
    //t_finish = clock();
    //std::cout << "one thread time: " << (double)(t_finish - t_start) / CLOCKS_PER_SEC << std::endl;
}

void ParallelSortTask::Check()
{
    if (std::is_sorted(nums_.begin(), nums_.end()))
        std::cout << "Sorted!";
    else
        std::cout << "Not sorted!";
    std::cout << std::endl;
}