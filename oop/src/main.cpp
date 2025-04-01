#include <iostream>

#include "Parent.hpp"
#include "Child.hpp"
#include "AnotherChild.hpp"
#include "StepChild.hpp"
#include "ThirdChild.hpp"

int main()
{
    ///////////////////////////////////////////
    // Diamond problem
    ///////////////////////////////////////////

    StepChild c;
  
    c.Say(); 
    static_cast<Child&>(c).Say();
    c.AnotherChild::Say();

    ///////////////////////////////////////////
    // Early and latest linking
    ///////////////////////////////////////////

    Parent* third = new ThirdChild();
    third->Do();
    third->AnotherDo();

    return 0;
}