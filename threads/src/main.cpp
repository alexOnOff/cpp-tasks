#include <iostream>
#include <thread>
#include <chrono>
#include "Waiter.hpp"
#include "Counter.hpp"
#include "QueueTask.hpp"

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

    QueueTask* task = new QueueTask();
    task->Run();

    return 0;
}