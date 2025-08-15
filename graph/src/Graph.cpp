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

    unsigned Graph::GetSize() { return n_nodes_; }

    size_t Graph::GetEdgesNum()
    {
        size_t count = 0;

        for (auto& val : this->edges_)
            count += val.size();
        
        return count;
    }

    vector<unsigned> Graph::DFS(unsigned start_node)
    {
        vector<unsigned> ret_val;
        vector<bool> visited;

        ret_val.reserve(n_nodes_);
        visited.resize(n_nodes_);

        DFS(ret_val, visited, start_node);

        return ret_val;
    }

    vector<unsigned> Graph::BFS(unsigned start_node)
    {
        vector<unsigned> ret_val;
        vector<bool> visited;

        ret_val.reserve(n_nodes_);
        visited.resize(n_nodes_);

        BFS(ret_val, visited, start_node);

        return ret_val;
    }

    vector<unsigned> Graph::DisconnectedDFS(unsigned start_node)
    {
        vector<unsigned> ret_val;
        vector<bool> visited;

        ret_val.reserve(n_nodes_);
        visited.resize(n_nodes_);

        DFS(ret_val, visited, start_node);

        for (size_t i = 0; i < n_nodes_; i++)
        {
            if (!visited[i])
            {
                DFS(ret_val, visited, i);
            }
        }

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

    void Graph::DFS(vector<unsigned>& ret_val, vector<bool>& visited, unsigned node)
    {
        visited[node] = true;
        ret_val.push_back(node);

        for (auto& child : edges_[node])
        {
            if (!visited[child.GetDest()])
            {
                DFS(ret_val, visited, child.GetDest());
            }
        }
    }

    std::shared_ptr<Graph> Graph::Prima(unsigned start_node)
    {
        queue<unsigned> q;
        vector<bool> visited;
        std::shared_ptr<Graph> ret_val = std::make_shared<Graph>();

        visited.resize(this->n_nodes_);
        ret_val->AddNodes(this->n_nodes_);

        q.push(start_node);
        visited[start_node] = true;
        
        while (!q.empty())
        {
            auto current = q.front();

            for (auto& child : edges_[current])
            {
                if (auto index = child.GetDest(); !visited[index])
                {
                    q.push(index);
                    ret_val->AddEdge(current, index);
                    visited[index] = true;
                }
            }

            q.pop();
        }

        return ret_val;
    }

    std::shared_ptr<Graph> Graph::Kruskal()
    {
        std::shared_ptr<Graph> ret_val = std::make_shared<Graph>();
        vector<bool> visited;

        ret_val->AddNodes(this->n_nodes_);
        visited.resize(this->n_nodes_);
        visited[0] = true;

        for (size_t i = 0; i < this->edges_.size() && ret_val->GetEdgesNum() != ret_val->GetSize() - 1; i++) // Ost tree has n_edges = n_nodes - 1 
        {
            for (size_t j = 0; j < edges_[i].size(); j++)
            {
                if (auto index = edges_[i][j].GetDest(); !visited[index])
                {
                    ret_val->AddEdge(i, index);
                    visited[index] = true;
                }
            }
        }

        return ret_val;
    }

    vector<Graph::SrcEdge> Graph::MakeSrcEdges()
    {
        vector<Graph::SrcEdge> ret_val;

        ret_val.reserve(this->GetEdgesNum());

        for (size_t i = 0; i < this->edges_.size(); i++)
        {
            for (size_t j = 0; j < this->edges_[i].size(); j++)
            {
                ret_val.push_back(Graph::SrcEdge(edges_[i][j], i));
            }
        }

        return ret_val;
    }
}