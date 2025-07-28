#pragma once

#include <iostream>
#include <string> 
#include <vector>

using namespace std;

namespace solid
{
    namespace i
    {
        namespace bad
        {
            class IOrder
            {
            public:
                IOrder(){}
                virtual ~IOrder(){}

                virtual void SetTableNumber(unsigned) = 0;
                virtual void SetCost(unsigned) = 0;
                virtual void AddOrder(string) = 0;

                virtual unsigned GetTableNumber(){ return table_number_; }
                virtual unsigned GetCost() {return cost_; }
                virtual vector<string> GetOrderNames() { return names_; }

            protected:
                vector<string> names_;
                unsigned table_number_;
                unsigned cost_;
            };

            class CafeOrder : public IOrder
            {
            public:
                void SetTableNumber(unsigned num){ table_number_ = num; }
                void SetCost(unsigned cost){ cost_ = cost; }
                void AddOrder(string ord){ names_.push_back(ord); }
            };

            class OnlineOrder : public IOrder
            {
            public:
                void SetTableNumber(unsigned num) { throw new runtime_error("No table number"); }
                void SetCost(unsigned cost) { cost_ = cost; }
                void AddOrder(string ord) { names_.push_back(ord); }
            };
        }

        namespace ok
        {
            class IOrder
            {
            public:
                IOrder() {}
                virtual ~IOrder() = 0 {}

                void SetCost(unsigned cost) { cost_ = cost; }
                void AddOrder(string ord) { names_.push_back(ord); }

                virtual unsigned GetCost() { return cost_; }
                virtual vector<string> GetOrderNames() { return names_; }

            protected:
                vector<string> names_;
                unsigned cost_;
            };

            class IOnlineOrder : public IOrder
            {
            public:
                ~IOnlineOrder() = 0 {}

                virtual void SetAuthor(string a) { author_ = a; }
                virtual string GetAuthor() { return author_; }

            protected:
                string author_;
            };

            class IOfflineOrder : public IOrder
            {
            public:
                ~IOfflineOrder() = 0 {}

                virtual void SetTable(unsigned n) { table_number_ = n; }
                virtual unsigned GetTable() { return table_number_; }

            protected:
                unsigned table_number_;
            };

            class CafeOrder : public IOfflineOrder
            {
            public:
                CafeOrder() {}
                ~CafeOrder() {}
            };

            class OnlineOrder : public IOnlineOrder
            {
            public:
                OnlineOrder(){}
                ~OnlineOrder(){}
            };
        }
    }
}