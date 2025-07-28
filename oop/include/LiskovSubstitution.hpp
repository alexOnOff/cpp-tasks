#pragma once

#include <iostream>

namespace solid
{
    namespace l
    {
        namespace bad
        {
            class Restaurant
            {
            public:
                Restaurant(){ Cash = 0; }
                ~Restaurant(){}
                
                virtual void AddMoney(int cash)
                {
                    if (cash < 0)
                    {
                        throw std::runtime_error("U can't add neg number");
                    }

                    Cash += cash;
                } 

            protected:
                int Cash;
            };

            class Cafe : public Restaurant
            {
            public:
                Cafe(){}
                ~Cafe(){};

                virtual void AddMoney(int cash) override
                {
                    if (cash < 0)
                    {
                        throw std::runtime_error("U can't add neg number");
                    }

                    if (Cash + cash > 200)
                    {
                        throw std::runtime_error("U can't add more");
                    }

                    Cash += cash;
                }
            };
        }

        namespace ok
        {
            class ICompany
            {
            public:
                ICompany(){}
                ~ICompany(){}
                virtual void AddMoney(int cash) = 0;
            protected:
                int Cash;
            };


            class Restaurant : public ICompany
            {
            public:
                Restaurant() { Cash = 0; }
                ~Restaurant() {}

                virtual void AddMoney(int cash) override
                {
                    if (cash < 0)
                    {
                        throw std::runtime_error("U can't add neg number");
                    }

                    Cash += cash;
                }
            };

            class Cafe : public ICompany
            {
            public:
                Cafe() {}
                ~Cafe() {};

                virtual void AddMoney(int cash) override
                {
                    if (cash < 0)
                    {
                        throw std::runtime_error("U can't add neg number");
                    }

                    if (Cash + cash > 200)
                    {
                        throw std::runtime_error("U can't add more");
                    }

                    Cash += cash;
                }
            };
        }
    }
}