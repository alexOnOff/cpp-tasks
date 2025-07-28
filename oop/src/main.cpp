#include <iostream>

#include "Parent.hpp"
#include "Child.hpp"
#include "AnotherChild.hpp"
#include "StepChild.hpp"
#include "ThirdChild.hpp"
#include "ConstructorCalling.hpp"

#include "SingleResponsibility.hpp"
#include "OpenClosed.hpp"
#include "LiskovSubstitution.hpp"

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

   //solid::o::ok::Cook cook;
   //solid::o::ok::IRecipe* rec = new solid::o::ok::SoupRecipe();
   //cook.Work(rec);

   //delete rec;

   // LiskovSubstitution
   // Preconditions can not be stronger in subclass.
   // Postconditions can not be weaker in subclass.
   // Invariants must be saved in subclass

   ////Bad: i dont know about this realisation
   //solid::l::bad::Restaurant* rest = new solid::l::bad::Cafe();

   //// Restaurant can add big sum, but there is exception:
   //rest->AddMoney(1000);

   //OK:

   solid::l::ok::ICompany* rest = new solid::l::ok::Restaurant();
   rest->AddMoney(1000);

   delete rest;

    return 0;
}