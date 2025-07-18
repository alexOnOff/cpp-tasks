#include <iostream>

#include "Graph.hpp"
#include "WeightGraph.hpp"

int main()
{
    gph::Graph g;
    
    g.AddNodes(5);
    
    //g.AddEdge(0, 1, false);
    //g.AddEdge(0, 2, false);
    //g.AddEdge(1, 2, false);
    //g.AddEdge(1, 3, false);
    //g.AddEdge(2, 4, false);
    //g.AddEdge(3, 4, false);

    g.Print();

    for (auto& val : g.DisconnectedBFS())
    {
        std::cout << val << ' ';
    }

    return 0;
}