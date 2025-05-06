#pragma once

#include <iostream>
#include <thread>
#include <mutex>

class Waiter
{
public:
    Waiter();
    ~Waiter();

    void Wait();
    void EndWait();

private:
    static std::mutex mtx_;
    bool isWaiting = false;
    std::thread waiting_thread_;
};

