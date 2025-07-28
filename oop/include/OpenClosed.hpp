#pragma once

#include <iostream>

using namespace std;

namespace solid
{
    namespace o
    {
        namespace bad
        {
            class Cook
            {
                Cook() {}
                ~Cook() {}
                void Work()
                {
                    cout << "Step 1" << endl;
                    cout << "Step 2" << endl;
                    cout << "Step 3" << endl;
                    cout << "Step 4" << endl;
                    cout << "Step 5" << endl;
                }
            };
        }

        namespace ok
        {
            class IRecipe
            {
            public:
                virtual ~IRecipe() {}
                virtual void CookIt() = 0;
            };

            class SoupRecipe : public IRecipe
            {
            public:
                ~SoupRecipe() {}
                void CookIt() override
                {
                    cout << "Cook soup step 1" << endl;
                    cout << "Cook soup step 2" << endl;
                    cout << "Cook soup step 3" << endl;
                }
            };

            class SaladRecipe : public IRecipe
            {
            public:
                ~SaladRecipe() {} 
                void CookIt() override
                {
                    cout << "Cook Salad step 1" << endl;
                    cout << "Cook Salad step 2" << endl;
                    cout << "Cook Salad step 3" << endl;
                }
            };

            class Cook
            {
            public:
                Cook() {}
                ~Cook() {}
                void Work(IRecipe* recipe)
                {
                    recipe->CookIt();
                }
            };
        }
    }
}