#pragma once 

#include "Parent.hpp"

class Child : virtual public Parent
{
public:
    Child();
    ~Child();
    void Say();
private:

};
