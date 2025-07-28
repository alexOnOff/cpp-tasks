#include <iostream>

#include "Parent.hpp"
#include "Child.hpp"
#include "AnotherChild.hpp"
#include "StepChild.hpp"
#include "ThirdChild.hpp"
#include "ConstructorCalling.hpp"

#include "SingleResponsibility.hpp"
#include "OpenClosed.hpp"

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

    //solid::s::ok::Restaurant r;
    //solid::s::ok::ConsoleWaiter* cw = new solid::s::ok::ConsoleWaiter();
    //solid::s::ok::ConsoleCook* cc = new solid::s::ok::ConsoleCook();

    //r.Work(cw,cc);
    //
    //delete cw;
    //delete cc;

    // OpenClosed

   solid::o::ok::Cook cook;
   solid::o::ok::IRecipe* rec = new solid::o::ok::SoupRecipe();
   cook.Work(rec);

   delete rec;

    return 0;
}