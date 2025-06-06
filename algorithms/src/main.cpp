#include <iostream>
#include <time.h>
#include "BubbleSort.hpp"
#include "InsertSort.hpp"
#include "BinaryInsertSort.hpp"
#include "QuickSort.hpp"

const int SIZE = 5;

int main()
{   
    srand((unsigned int)time(NULL));
    std::cout << "Hello World!" << std::endl;
    
    std::vector<int> arr ;
    std::vector<int> bubble_arr;
    std::vector<int> insert_arr;
    std::vector<int> bin_insert_arr;
    std::vector<int> quick_arr;

    std::cout << "Initial array:" << std::endl;

    for (size_t i = 0; i < SIZE; i++)
    {
        arr.push_back(rand() % 10);
        bubble_arr.push_back(arr[i]);
        insert_arr.push_back(arr[i]);
        bin_insert_arr.push_back(arr[i]);
        quick_arr.push_back(arr[i]);
        std::cout << arr[i] << ' ';
    }

    BubbleSort<std::vector<int>, int>(bubble_arr, SIZE);
    InsertSort<std::vector<int>>(insert_arr, SIZE);
    BinaryInsertSort<std::vector<int>, int>(bin_insert_arr, SIZE);
    QuickSort<std::vector<int>, int>(quick_arr, 0, SIZE - 1);

    std::cout << std::endl << "After sort buble:" << std::endl;


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

    std::cout << std::endl << "After quick search:" << std::endl;

    for (size_t i = 0; i < SIZE; i++)
    {
        std::cout << quick_arr[i] << ' ';
    }

    arr.clear();
    //insert_arr.clear();
    bubble_arr.clear();
    bin_insert_arr.clear();
    quick_arr.clear();

    return 0;
}