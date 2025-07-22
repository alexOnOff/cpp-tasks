#include <iostream>

#include "Graph.hpp"
#include "WeightGraph.hpp"

int main()
{
    //gph::Graph g;
    //
    //g.AddNodes(5);
    //
    //g.AddEdge(0, 1, false);
    //g.AddEdge(1, 2, false);
    //g.AddEdge(1, 4, false);

    //g.Print();

    //for (auto& val : g.DisconnectedDFS())
    //{
    //    std::cout << val << ' ';
    //}

    //////////////////////////////////////////////////////////////////

    //auto g = std::make_shared<gph::Graph>();

    //g->AddNodes(6);

    //g->AddEdge(0, 1, false);
    //g->AddEdge(0, 2, false);
    //g->AddEdge(1, 2, false);
    //g->AddEdge(1, 3, false);
    //g->AddEdge(2, 4, false);
    //g->AddEdge(2, 5, false);
    //g->AddEdge(3, 4, false);
    //g->AddEdge(4, 5, false);
    //
    //auto ost_tree = g->Prima();
    //ost_tree->Print();

    //////////////////////////////////////////////////////////////////

    auto g = std::make_shared<gph::WeightGraph<int>>();

    g->AddNodes(6);

    g->AddEdge(0, 1, false, 1);
    g->AddEdge(0, 2, false, 10);
    g->AddEdge(1, 2, false, 2);
    g->AddEdge(1, 3, false, 3);
    g->AddEdge(2, 4, false, 5);
    g->AddEdge(2, 5, false, 1);
    g->AddEdge(3, 4, false, 3);
    g->AddEdge(4, 5, false, 2);

    auto ost_tree = g->Prima();
    ost_tree->Print();

    return 0;
}