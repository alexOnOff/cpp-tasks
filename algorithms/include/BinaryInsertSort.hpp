#pragma once

template<typename T>
T* BinaryInsertSort(T* array, unsigned size)
{
    for (size_t i = 1; i < size; i++)
    {
        size_t low_range = 0;
        size_t high_range = i - 1;
        size_t middle;
        T key = array[i];

        while (high_range > low_range)
        {
            middle = low_range + (high_range - low_range) / 2;

            if (key < array[middle])
            {
                high_range = middle;
            }
            else
            {
                low_range = middle + 1 ;
            }
        }

        for (int j = i; low_range < j; j--)
        {
            array[j] = array[j-1];
        }

        array[low_range] = key;


        //std::cout << std::endl << "Iteration:" << i <<  std::endl;

        //for (size_t i = 0; i < size; i++)
        //{
        //    std::cout << array[i] << ' ';
        //}

        //std::cout << std::endl;
    }

    return array;
}