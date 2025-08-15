#pragma once

#include <vector>

class DSU
{
public:
    DSU(size_t classes);
    ~DSU();
    size_t Find(size_t class_id);
    void Union(size_t class_a, size_t class_b);
private:
    DSU();
    std::vector<size_t> parents_;
    std::vector<size_t> rank_;
};

