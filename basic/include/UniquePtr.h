#pragma once

#include <iostream>

void DoOne(std::unique_ptr<int> a)
{
    *a = 15;
}

void DoSecond(std::unique_ptr<int>& a)
{
    *a = 15;
}

void RunUnique()
{
    {
        std::cout << "Unique pointers" << std::endl;
        int a = 10;

        int* a_ptr = &a;
        std::unique_ptr<int> a_uniq = std::make_unique<int>(a);
        std::unique_ptr<int> a_uniq_sec = std::make_unique<int>(a);

        std::cout << "Base ptr - Adress: " << a_ptr << " Value: " << *a_ptr << std::endl;
        std::cout << "Uniq - Adress: " << a_uniq.get() << " Value: " << *a_uniq << std::endl;
        std::cout << "Sec uniq - Adress: " << a_uniq_sec.get() << " Value: " << *a_uniq_sec << std::endl;

        a = 15;

        std::cout << "Base ptr - Adress: " << a_ptr << " Value: " << *a_ptr << std::endl;
        std::cout << "Uniq - Adress: " << a_uniq.get() << " Value: " << *a_uniq << std::endl;
        std::cout << "Sec uniq - Adress: " << a_uniq_sec.get() << " Value: " << *a_uniq_sec << std::endl;

        // unique_ptr alloc new memory, create pointer and set point value to adress of allocated memory (!)
    }

    {
        std::cout << "No copy Unique pointers" << std::endl;

        int a = 10;
        std::unique_ptr<int> a_uniq = std::make_unique<int>(a);

        std::cout << "Uniq - Adress: " << a_uniq.get() << " Value: " << *a_uniq << std::endl;

        //std::unique_ptr<int> a_uniq_sec = a_uniq; // error, no copy
        //DoOne(a_uniq); // error, no copy
        DoSecond(a_uniq);

        std::cout << "Uniq - Adress: " << a_uniq.get() << " Value: " << *a_uniq << std::endl;
    }
}