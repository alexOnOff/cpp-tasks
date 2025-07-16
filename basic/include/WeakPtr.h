#pragma once

#include <iostream>

void RunWeak()
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
        int a = 10;

        std::shared_ptr<int> a_shared = std::make_shared<int>(a);
        std::weak_ptr<int> a_weak(a_shared);
        std::shared_ptr<int> a_shared_copy = a_weak.lock();

        std::cout << "Uniq - Adress: " << a_shared.get() << " Value: " << *a_shared << std::endl;
        std::cout << "Sec uniq - Adress: " << a_shared_copy.get() << " Value: " << *a_shared_copy << std::endl;

        *a_shared = 15;

        std::cout << "Uniq - Adress: " << a_shared.get() << " Value: " << *a_shared << std::endl;
        std::cout << "Sec uniq - Adress: " << a_shared_copy.get() << " Value: " << *a_shared_copy << std::endl << std::endl;
    }

    {
        A a = A();

        std::shared_ptr<A> a_shared = std::make_shared<A>(a);
        std::weak_ptr<A> a_weak(a_shared);
        std::shared_ptr<A> a_shared_copy = a_weak.lock();

        std::cout << "1 Counter = " << a_shared.use_count() << std::endl;
        std::cout << "2 Counter = " << a_shared_copy.use_count() << std::endl;

        a_shared->A_friend = a_shared_copy;
        a_shared_copy->A_friend = a_shared;

        std::cout << "Add friend" << std::endl;
        std::cout << "1 Counter = " << a_shared.use_count() << std::endl;
        std::cout << "2 Counter = " << a_shared_copy.use_count() << std::endl;
    }
}