#pragma once

#include <iostream>

class A
{
public:
    A(){ std::cout << "A constructor" << std::endl; }
    A(int a) : A() { std::cout << "A int constructor" << std::endl; }
    ~A(){ std::cout << "A destructor" << std::endl; }
};

class B : public A
{
public:
    B() /*: A()*/ { std::cout << "B constructor" << std::endl; }
    ~B() { std::cout << "B destructor" << std::endl; }
};

class C : public B
{
public:
    C() /*: B()*/ { std::cout << "C constructor" << std::endl; }
    ~C() { std::cout << "C destructor" << std::endl; }
};

