#include <iostream>

#include "Parent.hpp"

Parent::Parent()
{
    std::cout << "Parent constructor" << std::endl;
}

Parent::~Parent()
{
    std::cout << "Parent destructor" << std::endl;
}

void Parent::Do()
{
    std::cout << "Do (virtual) from parent!" << std::endl;
}

void Parent::AnotherDo()
{
    std::cout << "AnotherDo (NO virtual) from parent!" << std::endl;
}