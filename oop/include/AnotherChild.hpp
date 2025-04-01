#pragma once 

#include "Parent.hpp"

class AnotherChild : virtual public Parent
{
public:
    AnotherChild();
    ~AnotherChild();
    void Say();
private:

};
