#include <iostream>

#include "AnotherChild.hpp"

AnotherChild::AnotherChild()
{
    std::cout << "AnotherChild constructor" << std::endl;
}

AnotherChild::~AnotherChild()
{
    std::cout << "AnotherChild destructor" << std::endl;
}

void AnotherChild::Say()
{
    std::cout << "AnotherChild Say!" << std::endl;
}