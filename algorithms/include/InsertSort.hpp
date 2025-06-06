#pragma once

template<typename T>
T InsertSort(T& array, unsigned size)
{
    for (size_t i = 1; i < size; i++)
    {
        int j = i - 1;
        auto key = array[i];

        while (j >= 0 && array[j] > key)
        {
            array[j+1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }

    return array;
}