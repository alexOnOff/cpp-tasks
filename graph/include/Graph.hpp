#pragma once
#include "Edge.hpp"
#include <vector>
#include <iostream>

namespace gph
{
    using std::vector;

    class Graph
    {
    public:
        Graph() : n_nodes_(0) {}

        Graph(const Graph& g)
        {
            n_nodes_ = g.n_nodes_;
            std::copy(g.edges_.begin(), g.edges_.end(), std::back_inserter(edges_));
        }

        ~Graph(){}

        void AddNodes(unsigned count = 1)
        {
            n_nodes_ += count;
            edges_.resize(n_nodes_);
        }

        void virtual AddEdge(unsigned x, unsigned y)
        {
            if (auto max_node = std::max(x, y); max_node > n_nodes_)
            {
                AddNodes(max_node - n_nodes_ + 1);
            }

            Edge e = Edge(y);
            edges_[x].push_back(e);
        }

        void virtual AddEdge(unsigned x, unsigned y, bool directed)
        {
            if (directed)
            {
                AddEdge(x, y);
            }
            else
            {
                AddEdge(x, y);
                AddEdge(y, x);
            }   
        }

        virtual void Print()
        {
            std::cout << "Graph: " << std::endl;
            for (size_t i = 0; i < n_nodes_; i++)
            {
                std::cout << "Node " << i;

                for (auto& edge : edges_[i])
                {
                    std::cout << " -----> ";
                    std::cout << edge.GetDest();
                }

                std::cout << std::endl;
            }
        }

    protected:
        unsigned n_nodes_;
        vector<vector<Edge>> edges_;
    };
}