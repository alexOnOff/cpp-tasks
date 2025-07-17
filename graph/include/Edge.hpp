#pragma once

#include <memory>

namespace gph
{
    template<class T>
    class Edge
    {
    public:
        Edge(unsigned dest, T value = T()) : dest_(dest), value_(value){}
        virtual ~Edge(){}

        unsigned GetDest() { return dest_; }

    protected:
        Edge(){}
    private:
        unsigned dest_;
        T value_;
    };
}