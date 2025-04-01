#include <iostream>

#include "StepChild.hpp"

StepChild::StepChild()
{
    std::cout << "StepChild constructor" << std::endl;
}

StepChild::~StepChild()
{
    std::cout << "StepChild destructor" << std::endl;
}

void StepChild::Say()
{
    std::cout << "StepChild say!" << std::endl;
}