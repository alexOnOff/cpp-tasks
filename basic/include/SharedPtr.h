#pragma once

#include <iostream>

void DoOne(std::shared_ptr<int> a)
{
    *a = 16;
    std::cout << "DoOne counter = " << a.use_count() << std::endl;
}

void DoSecond(std::shared_ptr<int>& a)
{
    *a = 17;
    std::cout << "DoSecond counter = " << a.use_count() << std::endl;
}

void RunShared()
{
    class A
    {
    public:
        A() {}
        ~A()
        {
            std::cout << "A desctructor" << std::endl;
        }

        std::shared_ptr<A> A_friend;
    };

    {
        A a = A();
        std::shared_ptr<A> a_shared = std::make_shared<A>(a);
        std::shared_ptr<A> a_shared_copy = a_shared;

        
        // call destructor twice
    }

    std::cout << std::endl;

    {
        int a = 10;
        std::shared_ptr<int> a_shared = std::make_shared<int>(a);
        std::shared_ptr<int> a_shared_copy = a_shared;

        std::cout << "Shared - Adress: " << a_shared.get() << " Value: " << *a_shared << std::endl;
        std::cout << "Shared copy - Adress: " << a_shared_copy.get() << " Value: " << *a_shared_copy << std::endl;
        std::cout << "Counter = " << a_shared.use_count() << std::endl;

        *a_shared = 15;

        std::cout << "Shared - Adress: " << a_shared.get() << " Value: " << *a_shared << std::endl;
        std::cout << "Shared copy - Adress: " << a_shared_copy.get() << " Value: " << *a_shared_copy << std::endl << std::endl;
    }

    {
        int a = 10;
        std::shared_ptr<int> a_shared = std::make_shared<int>(a);
        std::shared_ptr<int> a_shared_copy = a_shared;

        std::cout << "Shared - Adress: " << a_shared.get() << " Value: " << *a_shared << std::endl;
        std::cout << "Shared copy - Adress: " << a_shared_copy.get() << " Value: " << *a_shared_copy << std::endl;
        std::cout << "Counter = " << a_shared.use_count() << std::endl;

        DoOne(a_shared); // counter +1 because copy pointer, but after -1

        std::cout << "Shared - Adress: " << a_shared.get() << " Value: " << *a_shared << std::endl;
        std::cout << "Shared copy - Adress: " << a_shared_copy.get() << " Value: " << *a_shared_copy << std::endl;
        std::cout << "Counter = " << a_shared.use_count() << std::endl;

        DoSecond(a_shared); // counter not change

        std::cout << "Shared - Adress: " << a_shared.get() << " Value: " << *a_shared << std::endl;
        std::cout << "Shared copy - Adress: " << a_shared_copy.get() << " Value: " << *a_shared_copy << std::endl;
        std::cout << "Counter = " << a_shared.use_count() << std::endl << std::endl;
    }

    {
        std::shared_ptr<A> a_shared_1 = std::make_shared<A>();
        std::shared_ptr<A> a_shared_2 = std::make_shared<A>();

        std::cout << "1 Counter = " << a_shared_1.use_count() << std::endl;
        std::cout << "2 Counter = " << a_shared_2.use_count() << std::endl;

        a_shared_1->A_friend = a_shared_2;
        a_shared_2->A_friend = a_shared_1;

        std::cout << "Add friend" << std::endl;
        std::cout << "1 Counter = " << a_shared_1.use_count() << std::endl;
        std::cout << "2 Counter = " << a_shared_2.use_count() << std::endl;

        // No call destructor!! Memory leakege
    }

}