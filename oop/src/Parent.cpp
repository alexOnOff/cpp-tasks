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