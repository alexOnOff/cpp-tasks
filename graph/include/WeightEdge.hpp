#pragma once

#include "Edge.hpp"

namespace gph
{
    template<class T>
    class WeightEdge : public Edge
    {
    public:
        WeightEdge(unsigned dest, T value = T()) : Edge(dest)
        {
            value_ = value;
        }

        WeightEdge(const WeightEdge& e) : Edge(e.dest_)
        {
            value_ = e.value_;
        }

        ~WeightEdge() {}

        T GetValue() { return value_; }

    protected:
        T value_;
    private:
        WeightEdge() {}
    };
}

