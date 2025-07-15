#pragma once

#include <iostream>

class A
{
    public:
    A(){}
    ~A() 
    {
        std::cout << "A desctructor" << std::endl;
    }
};

class MemoryLeakage
{
public:
    MemoryLeakage();
    ~MemoryLeakage();

    void Do();
private:
};

