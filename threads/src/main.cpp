#include <iostream>
#include <thread>
#include <chrono>
#include "Waiter.hpp"
#include "Counter.hpp"
#include "QueueTask.hpp"
#include "ArraySumTask.hpp"

int main()
{
    std::cout << "Hello threads" << std::endl;

    ///////////////////////////////////////////
    // Waiting..
    ///////////////////////////////////////////

    //Waiter* w = new Waiter();
    //w->Wait();
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    //w->EndWait();

    ///////////////////////////////////////////
    // Counter
    ///////////////////////////////////////////

    //Counter* counter = new Counter();
    ////counter->Run();
    //counter->RunAtomic();

    ///////////////////////////////////////////
    // QueueTask (Producer and Consumer)
    ///////////////////////////////////////////

    //QueueTask* task = new QueueTask();
    //task->Run();

    ///////////////////////////////////////////
    // Array sum
    ///////////////////////////////////////////

    ArraySumTask* task = new ArraySumTask(1000000000,16);
    task->Run();
    task->Check();

    return 0;
}