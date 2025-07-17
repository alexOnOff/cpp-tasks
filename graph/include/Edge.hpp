#pragma once

#include <memory>

namespace gph
{
    class Edge
    {
    public:
        Edge(unsigned dest) : dest_(dest){}
        
        Edge(const Edge& e) 
        {
            dest_ = e.dest_;
        }
        
        virtual ~Edge(){}

        unsigned GetDest() { return dest_; }

    protected: 
        unsigned dest_;

    private:
        Edge() {}
    };
}