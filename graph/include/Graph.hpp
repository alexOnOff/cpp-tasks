#pragma once
#include "Edge.hpp"
#include <vector>
#include <iostream>
#include <queue>

namespace gph
{
    using std::vector;
    using std::queue;

    class Graph
    {
    public:
        Graph();
        Graph(const Graph& g);
        ~Graph();

        virtual void AddNodes(unsigned count = 1);
        virtual void AddEdge(unsigned x, unsigned y);
        virtual void AddEdge(unsigned x, unsigned y, bool directed);
        virtual void Print();

        vector<unsigned> DFS(unsigned start_node = 0);
        vector<unsigned> BFS(unsigned start_node = 0);
        vector<unsigned> DisconnectedBFS(unsigned start_node = 0);

    protected:
        void BFS(vector<unsigned>& ret_val, vector<bool>& visited, unsigned start_node);
        unsigned n_nodes_;
        vector<vector<Edge>> edges_;
    };
}