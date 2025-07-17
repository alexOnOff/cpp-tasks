#pragma once

#include "Edge.hpp"

namespace gph
{
    template<class T>
    class WeightEdge : public Edge
    {
    public:
        WeightEdge(unsigned dest, T value = T()) : Edge(dest_), value_(value) {}

        WeightEdge(const Edge& e)
        {
            value_ = e.value_;
        }

        ~WeightEdge() {}

    protected:
        T value_;
    private:
        WeightEdge() {}
    };
}

