#pragma once

#include <utility>

#include "Graph.hpp"
#include "WeightEdge.hpp"

namespace gph
{
    using std::vector;
    using std::priority_queue;
    using std::pair;

    template<class T>
    class WeightGraph : public Graph
    {
    public:
        WeightGraph(){}
        WeightGraph(const Graph& g){}

        ~WeightGraph() {}

        void AddNodes(unsigned count = 1) override
        {
            n_nodes_ += count;
            edges_.resize(n_nodes_);
        }

        void AddEdge(unsigned x, unsigned y, T weight = T())
        {
            if (auto max_node = std::max(x, y); max_node > n_nodes_)
            {
                AddNodes(max_node - n_nodes_ + 1);
            }

            WeightEdge e = WeightEdge<T>(y, weight);
            edges_[x].push_back(e);
        }

        void AddEdge(unsigned x, unsigned y, bool directed, T weight = T())
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

        void Print() override
        {
            std::cout << "Graph: " << std::endl;
            for (size_t i = 0; i < n_nodes_; i++)
            {
                for (auto& edge : edges_[i])
                {
                    std::cout << "        ";
                    std::cout << edge.GetValue();
                }

                std::cout << std::endl << "Node " << i;

                for (auto& edge : edges_[i])
                {
                    std::cout << " -----> ";
                    std::cout << edge.GetDest();
                }

                std::cout << std::endl;
            }
        }

        std::shared_ptr<Graph> Prima(unsigned start_node = 0) override
        {
            using dist = pair<T, unsigned>;

            std::shared_ptr<WeightGraph> ret_val = std::make_shared<WeightGraph<T>>();
            priority_queue<dist, vector<dist>, std::greater<dist>> pq; // pair<distance, node>
            vector<bool> visited(n_nodes_, false);
            vector<T> key(n_nodes_, INT32_MAX);

            visited.resize(n_nodes_);
            ret_val->AddNodes(this->n_nodes_);

            pq.push(std::make_pair(0, start_node));
            key[start_node] = 0;

            while (!pq.empty())
            {
                unsigned current = pq.top().second;
                pq.pop();

                if(visited[current]) continue;

                visited[current] = true;

                for (auto& node : this->edges_[current])
                {
                    unsigned dest = node.GetDest();
                    T weight = node.GetValue();

                    if (!visited[dest] && key[dest] > weight)
                    {
                        key[dest] = weight; 
                        pq.push(std::make_pair(key[dest], dest));
                        ret_val->AddEdge(current, dest, weight);
                    }
                }
            }

            return ret_val;
        }

    protected:
        vector<vector<WeightEdge<T>>> edges_;
    };
}