#include <iostream>
#include <time.h>
#include "BubbleSort.hpp"

const int SIZE = 10;

int main()
{   
    srand(time(NULL));
    std::cout << "Hello World!" << std::endl;

    float* arr = new float[SIZE];
    float* bubble_arr = new float[SIZE];
    float* insert_arr = new float[SIZE];

    std::cout << "Initial array:" << std::endl;

    for (size_t i = 0; i < SIZE; i++)
    {
        arr[i] = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
        bubble_arr[i] = arr[i];
        insert_arr[i] = arr[i];
        std::cout << arr[i] << ' ';
    }

    std::cout << std::endl << "After sort:" << std::endl;

    BubbleSort(bubble_arr, SIZE);


    for (size_t i = 0; i < SIZE; i++)
    {
        std::cout << bubble_arr[i] << ' ';
    }

    delete[] arr;

    return 0;
}