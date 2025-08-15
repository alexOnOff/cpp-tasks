#include "DSU.hpp"

DSU::DSU(){}

DSU::DSU(size_t classes) 
{
    parents_.resize(classes);
    rank_.resize(classes);

    for (size_t i = 0; i < classes; i++)
    {
        parents_[i] = i;
        rank_[i] = 1;
    }
}

DSU::~DSU(){}

size_t DSU::Find(size_t class_id)
{
    if (parents_[class_id] == class_id) return class_id;
    return parents_[class_id] = Find(parents_[class_id]);
}

void DSU::Union(size_t class_a, size_t class_b)
{
    class_a = Find(class_a);
    class_b = Find(class_b);

    if (class_a != class_b) 
    {
        if (rank_[class_a] < rank_[class_b]) parents_[class_a] = class_b;
        else if (rank_[class_a] > rank_[class_b]) parents_[class_b] = class_a;
        else parents_[class_b] = class_a, rank_[class_a]++;
    }
}
