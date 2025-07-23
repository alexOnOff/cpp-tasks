#pragma once

#include <iostream>
#include <string> 
#include <queue>

using namespace std;

namespace solid
{
    class Recipe
    {
    public:
        Recipe(string name, unsigned cost)
        {
            Name = name;
            Cost = cost;
        }

        ~Recipe() {}

        string Name;
        unsigned Cost;

    private:
    };

    namespace bad
    {
        class Cook
        {
        public:
            Cook() {}
            ~Cook() {}

            queue<Recipe> Orders;

            void Work()
            {
                size_t count;
                unsigned cost;
                unsigned cash = 0;
                string name;

                for (size_t i = 0; i < count; i++)
                {
                    cout << "Enter recipe: ";
                    cin >> name;
                    cout << "Enter cost: ";
                    cin >> cost;
                    Orders.push(Recipe(name, cost));
                }

                while (!Orders.empty())
                {
                    Recipe order = Orders.front();
                    Orders.pop();
                    cout << "Cook " << order.Name << endl;
                    cash += order.Cost;
                }

                cout << "All cash = " << cash << endl;
            }

        private:
        };
    }

    namespace ok
    {
        class IWaiter
        {
        public:
            IWaiter() { Cash = 0; }
            ~IWaiter() {}

            virtual void GetOrder(queue<Recipe>& recipes) = 0;
            virtual unsigned GetCash() { return Cash; }
        protected:
            unsigned Cash;
        };

        class ConsoleWaiter : public IWaiter
        {
        public:
            ConsoleWaiter() {}
            ~ConsoleWaiter() {}

            void GetOrder(queue<Recipe>& recipes) override
            {
                unsigned cost;
                string name;

                cout << "Enter recipe: ";
                cin >> name;
                cout << "Enter cost: ";
                cin >> cost;

                Cash += cost;

                recipes.push(Recipe(name, cost));
            }
        };

        class ICook
        {
        public:
            ICook() {}
            ~ICook() {}
            virtual void Work(queue<Recipe>& recipes) = 0;
        };

        class ConsoleCook : public ICook
        {
        public:
            ConsoleCook() {}
            ~ConsoleCook() {}

            void Work(queue<Recipe>& recipes) override
            {
                while (!recipes.empty())
                {
                    Recipe order = recipes.front();
                    recipes.pop();
                    cout << "Cook " << order.Name << endl;
                }
            }
        };

        class Restaurant
        {
        public:
            Restaurant() {}
            ~Restaurant() {}

            queue<Recipe> Orders;

            void Work(IWaiter* waiter, ICook* cook)
            {
                waiter->GetOrder(Orders); 
                cook->Work(Orders); 
                cout << "All cash = " << waiter->GetCash() << endl; 
            }

        private:
        };
    }
}