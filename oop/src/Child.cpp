#include <iostream>

#include "Child.hpp"

Child::Child()
{
    std::cout << "Child constructor" << std::endl;
}

Child::~Child()
{
    std::cout << "Child destructor" << std::endl;
}

void Child::Say()
{
    std::cout << "Child Say!" << std::endl;
}