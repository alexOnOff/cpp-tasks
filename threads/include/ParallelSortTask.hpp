#pragma once

class ParallelSortTask
{
public:
    ParallelSortTask(int array_size = 10, int thread_num = 2);
    ~ParallelSortTask();

    void Run();
    void Check();
private:

};
