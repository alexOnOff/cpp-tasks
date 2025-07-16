#include <iostream>

#include "MemoryLeakage.h"
#include "UniquePtr.h"
#include "SharedPtr.h"
#include "WeakPtr.h"

int main()
{
    std::cout << "Hello basics!" << std::endl;

    ///////////////////////////////////////////
    // Unique pointers
    ///////////////////////////////////////////
    
    std::cout << std::endl << " ========== RunUnique! ==========" << std::endl;
    RunUnique();

    ///////////////////////////////////////////
    // Shared pointers
    ///////////////////////////////////////////

    std::cout << std::endl << " ========== RunShared! ==========" << std::endl;
    RunShared();

    ///////////////////////////////////////////
    // Weak pointers
    ///////////////////////////////////////////

    std::cout << std::endl << " ========== RunWeak! ==========" << std::endl;
    RunWeak();

    ///////////////////////////////////////////
    // Leakage
    ///////////////////////////////////////////

    std::cout << std::endl << " ========== MemoryLeakage! ==========" << std::endl;
    MemoryLeakage m;
    m.Do();

    return 0;
}