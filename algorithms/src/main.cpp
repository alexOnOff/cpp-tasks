#include <iostream>
#include <time.h>
#include "BubbleSort.hpp"
#include "InsertSort.hpp"
#include "BinaryInsertSort.hpp"

const int SIZE = 5;

int main()
{   
    srand((unsigned int)time(NULL));
    std::cout << "Hello World!" << std::endl;

    int* arr = new int[SIZE];
    int* bubble_arr = new int[SIZE];
    int* insert_arr = new int[SIZE];
    int* bin_insert_arr = new int[SIZE];

    std::cout << "Initial array:" << std::endl;

    for (size_t i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 10;// static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
        bubble_arr[i] = arr[i];
        insert_arr[i] = arr[i];
        bin_insert_arr[i] = arr[i];
        std::cout << arr[i] << ' ';
    }

    std::cout << std::endl << "After sort buble:" << std::endl;

    BubbleSort(bubble_arr, SIZE);
    InsertSort(insert_arr, SIZE);
    BinaryInsertSort(bin_insert_arr, SIZE);

    for (size_t i = 0; i < SIZE; i++)
    {
        std::cout << bubble_arr[i] << ' ';
    }

    std::cout << std::endl << "After sort insert:" << std::endl;

    for (size_t i = 0; i < SIZE; i++)
    {
        std::cout << insert_arr[i] << ' ';
    }

    std::cout << std::endl << "After sort insert with binary search:" << std::endl;

    for (size_t i = 0; i < SIZE; i++)
    {
        std::cout << bin_insert_arr[i] << ' ';
    }


    delete[] arr;
    delete[] insert_arr;
    delete[] bubble_arr;

    return 0;
}