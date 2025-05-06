#include "Waiter.hpp"

Waiter::Waiter()
{
}

Waiter::~Waiter()
{
}

std::mutex Waiter::mtx_;

void Waiter::Wait()
{
    isWaiting = true;

    waiting_thread_ = std::thread([](bool& wait)
        {
            std::lock_guard<std::mutex> lock(mtx_);
            std::cout << "Wait";

            while (wait)
            {
                
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << '.';
                std::cout.flush();
            }

            std::cout << '\n';
        }, std::ref(isWaiting));

    waiting_thread_.detach();
}

void Waiter::EndWait()
{
    isWaiting = false;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
