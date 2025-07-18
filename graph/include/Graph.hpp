#pragma once
#include "Edge.hpp"
#include <vector>
#include <iostream>
#include <queue>

namespace gph
{
    using std::vector;
    using std::queue;

    enum NodeStatus
    {
        Undiscovered = 0,
        Discovered = 1,
        Processed = 2
    };

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

        virtual void AddNodes(unsigned count = 1)
        {
            n_nodes_ += count;
            edges_.resize(n_nodes_);
        }

        virtual void  AddEdge(unsigned x, unsigned y)
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

        vector<unsigned> BFS(unsigned start_node = 0)
        {
            vector<unsigned> ret_val { n_nodes_ };
            vector<NodeStatus> status {n_nodes_};

            status[start_node] = Discovered;


            return ret_val;
        }

        vector<unsigned> DFS(unsigned start_node = 0)
        {
            queue<unsigned> q;
            vector<unsigned> ret_val;
            vector<bool> visited;

            ret_val.reserve(n_nodes_);
            visited.resize(n_nodes_);

            visited[start_node] = true;
            q.push(start_node);
            
            while (!q.empty())
            {
                auto current = q.front();

                for (auto& child : edges_[current])
                {
                    if (auto index = child.GetDest(); !visited[index])
                    {
                        q.push(index);
                        visited[index] = true;
                    }
                }
                
                ret_val.push_back(current);
                q.pop();
            }

            return ret_val;
        }

    protected:
        unsigned n_nodes_;
        vector<vector<Edge>> edges_;
    };
}