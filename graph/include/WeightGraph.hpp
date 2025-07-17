#pragma once

#include "Graph.hpp"
#include "WeightEdge.hpp"

namespace gph
{
    using std::vector;

    template<class T>
    class WeightGraph : public Graph
    {
    public:
        WeightGraph(){}
        WeightGraph(const Graph& g){}

        ~WeightGraph() {}

        void AddEdge(unsigned x, unsigned y, T weight = T()) override
        {
            if (auto max_node = std::max(x, y); max_node > n_nodes_)
            {
                AddNodes(max_node - n_nodes_ + 1);
            }

            Edge e = WeightEdge<T>(y, weight);
            edges_[x].push_back(e);
        }

        void AddEdge(unsigned x, unsigned y, bool directed, T weight = T()) override
        {
            if (directed)
            {
                AddEdge(x, y, weight);
            }
            else
            {
                AddEdge(x, y, weight);
                AddEdge(y, x, weight);
            }
        }
    };
}