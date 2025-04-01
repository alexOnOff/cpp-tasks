#pragma once 

#include "Parent.hpp"

class ThirdChild : public Parent
{
public:
    ThirdChild();
    ~ThirdChild();
    void Do() override;
    void AnotherDo();
private:

};

