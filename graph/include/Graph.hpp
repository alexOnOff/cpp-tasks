#pragma once
#include "Edge.hpp"
#include <vector>
#include <iostream>

namespace gph
{
    using std::vector;

    template<class T>
    class Graph
    {
    public:
        Graph() : n_nodes_(0) {}
        ~Graph(){}

        void AddNodes(unsigned count = 1)
        {
            n_nodes_ += count;
            edges_.resize(n_nodes_);
        }

        void AddEdge(unsigned x, unsigned y, T weight = T())
        {
            if (auto max_node = std::max(x, y); max_node > n_nodes_)
            {
                AddNodes(max_node - n_nodes_ + 1); //TODO: check this
            }

            Edge<T> e = Edge<T>(y, weight);
            edges_[x].push_back(e);
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

    private:
        unsigned n_nodes_;
        vector<vector<Edge<T>>> edges_;
    };
}