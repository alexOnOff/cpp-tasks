#pragma once
#include <random>
#include <vector>

namespace 
{
    template<typename vec, typename type>
    int part(vec& array, int low, int high)
    {
        type pos = array[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++)
        {
            if (array[j] <= pos)
            {
                i++;
                std::swap(array[i], array[j]);
            }
        }

        std::swap(array[i + 1], array[high]);

        return (i + 1);
    }
}

template<typename vec, typename type>
void QuickSort(vec& array, int low, int high)
{
    if (low < high)
    {
        int pos = part<vec, type>(array, low, high);
        QuickSort<vec, type>(array, low, pos - 1);
        QuickSort<vec, type>(array, pos + 1, high);
    }
}

