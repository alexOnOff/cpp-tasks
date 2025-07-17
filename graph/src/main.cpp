#include <iostream>

#include "Graph.hpp"
#include "WeightGraph.hpp"

int main()
{
    std::cout << "Hello graph" << std::endl;

    gph::Graph g;
    
    //g.AddNodes(3);
    g.AddEdge(0, 2);
    g.AddEdge(0, 1, false);
    g.Print();

    gph::Graph g_copy = g;

    g_copy.Print();
    g_copy.AddNodes();
    g_copy.AddEdge(3, 1);

    g.Print();
    g_copy.Print();

    return 0;
}