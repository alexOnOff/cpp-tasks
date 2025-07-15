#include "MemoryLeakage.h"

MemoryLeakage::MemoryLeakage()
{
}

MemoryLeakage::~MemoryLeakage()
{
}

void MemoryLeakage::Do()
{ 
    // where is leakage?
    A a;
    A* p_a = new A(); // here
    
}
