#include <iostream>

#include "Graph.hpp"
#include "WeightGraph.hpp"

int main()
{
    gph::WeightGraph<int> g;
    
    g.AddNodes(3);
    g.AddEdge(0, 2, 1);
    g.AddEdge(0, 1, false, 2);
    g.Print();

    return 0;
}