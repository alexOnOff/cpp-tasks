#include "Counter.hpp"

Counter::Counter()
{
}

Counter::~Counter()
{
}

void Counter::Run()
{
    std::thread t1(&Counter::Add, this, std::ref(counter_), 1);
    std::thread t2(&Counter::Add, this, std::ref(counter_), 2);

    t1.join();
    t2.join();
}

void Counter::RunAtomic()
{
    std::thread t1(&Counter::AddAtomic, this, 1);
    std::thread t2(&Counter::AddAtomic, this, 2);

    t1.join();
    t2.join();
}

void Counter::Add(int& c, int thread_num)
{
    while (counter_ < COUNTER_MAX_VALUE_)
    {
        std::lock_guard<std::mutex> lock(mtx_);
        c++;
        std::cout << c << " - from " << thread_num << " thread\n";
    }
}

void Counter::AddAtomic(int thread_num)
{
    while (atomic_counter_ < COUNTER_MAX_VALUE_)
    {
        atomic_counter_++;
        std::cout << atomic_counter_ << " - from " << thread_num << " thread\n";
    }
}