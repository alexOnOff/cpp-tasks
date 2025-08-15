#pragma once

#include <utility>
#include <algorithm>
#include "Graph.hpp"
#include "WeightEdge.hpp"
#include "DSU.hpp"

namespace gph
{
    using std::vector;
    using std::priority_queue;
    using std::pair;

    template<class T>
    class WeightGraph : public Graph
    {
        template<typename T_>
        class WeightSrcEdge : public WeightEdge<T_>
        {
        public:
            WeightSrcEdge(unsigned dest, unsigned src, T_ value = T_()) : WeightEdge<T_>(dest, value) { src_ = src; }
            WeightSrcEdge(WeightEdge<T_> edge, unsigned src) : WeightEdge<T_>(edge) { src_ = src; }
            ~WeightSrcEdge(){}
            unsigned GetSource() { return src_; }
        protected:
            unsigned src_;
        };

        bool compWeightSrcEdge(WeightGraph::WeightSrcEdge<T> x, WeightGraph::WeightSrcEdge<T> y)
        {
            return x.GetValue() < y.GetValue();
        }

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
            vector<int> parents(n_nodes_, -1);
            vector<T> key(n_nodes_, INT32_MAX);

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
                        parents[dest] = current;
                    }
                }
            }

            for (size_t i = 0; i < parents.size(); i++)
                if(parents[i] != -1)
                    ret_val->AddEdge(parents[i], i, key[i]);
            

            return ret_val;
        }
        
        std::shared_ptr<Graph> Kruskal() override
        {
            unsigned count = 0;
            DSU dsu{this->n_nodes_ };
            std::shared_ptr<WeightGraph> ret_val = std::make_shared<WeightGraph<T>>();
            vector<WeightGraph::WeightSrcEdge<T>> vec_of_edges = MakeSrcEdges();

            ret_val->AddNodes(this->n_nodes_);
            std::sort(vec_of_edges.begin(), vec_of_edges.end(), [] (WeightSrcEdge<T> a, WeightSrcEdge<T> b) { return a.GetValue() < b.GetValue(); });

            for (size_t i = 0; i < vec_of_edges.size(); i++)
            {
                size_t x = vec_of_edges[i].GetSource();
                size_t y = vec_of_edges[i].GetDest();
                T w = vec_of_edges[i].GetValue();

                if (dsu.Find(x) != dsu.Find(y))
                {
                    dsu.Union(x, y);
                    ret_val->AddEdge(x, y, w);
                    if(++count == n_nodes_ - 1) break;
                }
            }

            return ret_val;
        }

    protected:
        vector<vector<WeightEdge<T>>> edges_;
    private:
        vector<WeightGraph::WeightSrcEdge<T>> MakeSrcEdges()
        {
            vector<WeightGraph::WeightSrcEdge<T>> ret_val;

            ret_val.reserve(this->GetEdgesNum());

            for (size_t i = 0; i < this->edges_.size(); i++)
            {
                for (size_t j = 0; j < this->edges_[i].size(); j++)
                {
                    ret_val.push_back(WeightSrcEdge<T>(edges_[i][j].GetDest(), i, edges_[i][j].GetValue()));
                }
            }
            
            return ret_val;
        }
    };
}