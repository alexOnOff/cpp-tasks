#include <iostream>

#include "Graph.hpp"

int main()
{
    std::cout << "Hello graph" << std::endl;

    gph::Graph<int> g;
    
    //g.AddNodes(3);
    g.AddEdge(0, 2);
    g.AddEdge(0, 1);
    g.AddEdge(1, 0);
    g.Print();

    return 0;
}