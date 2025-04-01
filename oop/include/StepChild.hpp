#pragma once 

#include "Child.hpp"
#include "AnotherChild.hpp"

class StepChild : public Child, public AnotherChild
{
public:
    StepChild();
    ~StepChild();
    void Say();
private:

};
