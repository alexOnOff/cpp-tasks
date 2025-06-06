#pragma once

#include <algorithm>

template<typename vec, typename type>
void BubbleSort(vec& array, unsigned size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}