#include <iostream>

#include "Parent.hpp"
#include "Child.hpp"
#include "AnotherChild.hpp"
#include "StepChild.hpp"

int main()
{
    StepChild c;
  
    c.Say(); 
    c.AnotherChild::Say();
    static_cast<Child&>(c).Say();

    return 0;
}