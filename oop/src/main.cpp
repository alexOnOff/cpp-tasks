#include <iostream>

#include "Parent.hpp"
#include "Child.hpp"
#include "AnotherChild.hpp"
#include "StepChild.hpp"
#include "ThirdChild.hpp"
#include "ConstructorCalling.hpp"

#include "SingleResponsibility.hpp"

int main()
{
    ///////////////////////////////////////////
    // Diamond problem
    ///////////////////////////////////////////

    //StepChild c;
  
    //c.Say(); 
    //static_cast<Child&>(c).Say();
    //c.AnotherChild::Say();

    ///////////////////////////////////////////
    // Early and latest linking
    ///////////////////////////////////////////

    //Parent* third = new ThirdChild();
    //third->Do();
    //third->AnotherDo();

    ///////////////////////////////////////////
    // Destructors
    ///////////////////////////////////////////

    //Parent* child = new Child();
    //child->Do();
    //delete child;

    ///////////////////////////////////////////
    // ConstructorCalling
    ///////////////////////////////////////////

    //{
    //    C c = C();
    //}

    //{
    //    A a = A(1);
    //}

    ///////////////////////////////////////////
    // SOLID
    ///////////////////////////////////////////

    // SingleResponsibility

    solid::ok::Restaurant r;
    solid::ok::ConsoleWaiter* cw = new solid::ok::ConsoleWaiter();
    solid::ok::ConsoleCook* cc = new solid::ok::ConsoleCook();

    r.Work(cw,cc);
    
    delete cw;
    delete cc;

    // OpenClosed



    return 0;
}