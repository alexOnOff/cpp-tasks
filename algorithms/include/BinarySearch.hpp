#pragma once


template<typename vec, typename type>
int BinarySearch(vec& array, type value , unsigned low_range, unsigned high_range)
{
    int mid = low_range + (high_range - low_range)/2;

    if(low_range >= high_range)
        return (value > array[low_range] ? (low_range + 1) : low_range);

    if (array[mid] == value)
    {
        return mid;
    }
    else if(array[mid] > value)
    {
        return BinarySearch(array, value, low_range, mid);
    }
    else
    {
        return BinarySearch(array, value, mid+1, high_range);
    }
}
