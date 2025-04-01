#include <iostream>

#include "ThirdChild.hpp"

ThirdChild::ThirdChild()
{
}

ThirdChild::~ThirdChild()
{
}

void ThirdChild::Do() 
{
    std::cout << "Do (virtual) from ThirdChild!" << std::endl;
}

void ThirdChild::AnotherDo()
{
    std::cout << "AnotherDo (NO virtual) from ThirdChild!" << std::endl;
}