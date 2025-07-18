#include "Graph.hpp"

namespace gph
{
    Graph::Graph()
    {
        n_nodes_ = 0;
    }

    Graph::Graph(const Graph& g)
    {
        n_nodes_ = g.n_nodes_;
        std::copy(g.edges_.begin(), g.edges_.end(), std::back_inserter(edges_));
    }

    Graph::~Graph() {}

    void Graph::AddNodes(unsigned count )
    {
        n_nodes_ += count;
        edges_.resize(n_nodes_);
    }

    void Graph::AddEdge(unsigned x, unsigned y)
    {
        if (auto max_node = std::max(x, y); max_node > n_nodes_)
        {
            AddNodes(max_node - n_nodes_ + 1);
        }

        Edge e = Edge(y);
        edges_[x].push_back(e);
    }

    void Graph::AddEdge(unsigned x, unsigned y, bool directed)
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

    void Graph::Print()
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

    vector<unsigned> Graph::DFS(unsigned start_node)
    {
        vector<unsigned> ret_val{ n_nodes_ };
        //vector<NodeStatus> status {n_nodes_};

        //status[start_node] = Discovered;

        return ret_val;
    }

    vector<unsigned> Graph::BFS(unsigned start_node)
    {
        queue<unsigned> q;
        vector<unsigned> ret_val;
        vector<bool> visited;

        ret_val.reserve(n_nodes_);
        visited.resize(n_nodes_);

        BFS(ret_val, visited, start_node);

        return ret_val;
    }

    vector<unsigned> Graph::DisconnectedBFS(unsigned start_node)
    {
        vector<unsigned> ret_val;
        vector<bool> visited;

        ret_val.reserve(n_nodes_);
        visited.resize(n_nodes_);

        BFS(ret_val, visited, start_node);

        for (size_t i = 0; i < n_nodes_; i++)
        {
            if (!visited[i])
            {
                BFS(ret_val, visited, i);
            }
        }

        return ret_val;
    }

    void Graph::BFS(vector<unsigned>& ret_val, vector<bool>& visited, unsigned start_node)
    {
        queue<unsigned> q;

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
    }

}