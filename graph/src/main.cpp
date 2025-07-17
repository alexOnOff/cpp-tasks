#include <iostream>

#include "Graph.hpp"
#include "WeightGraph.hpp"

int main()
{
    gph::Graph g;
    
    g.AddNodes(5);
    
    g.AddEdge(0, 1, false);
    g.AddEdge(0, 2, false);
    g.AddEdge(0, 3, false);
    g.AddEdge(1, 4, false);
    g.Print();

    for (auto& val : g.DFS())
    {
        std::cout << val << ' ';
    }

    return 0;
}