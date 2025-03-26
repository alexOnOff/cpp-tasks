#pragma once

template<typename T>
T* InsertSort(T* array, unsigned size)
{
    for (size_t i = 1; i < size; i++)
    {
        size_t j = i - 1;
        T key = array[i];

        while (array[j] > key && j >= 0)
        {
            array[j+1] = array[j];
            j -= 1;
        }

        array[j + 1] = key;
    }

    return array;
}