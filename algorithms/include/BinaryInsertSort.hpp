#pragma once
#include "BinarySearch.hpp"

template<typename vec, typename type>
void BinaryInsertSort(vec& array, unsigned size)
{
    for (size_t i = 1; i < size; i++)
    {
        int low_range = 0;
        int high_range = i - 1;
        int middle;

        int j = i - 1;
        type key = array[i];

        int pos = BinarySearch<vec, type>(array, key, 0, j);

        while (j >= pos)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}