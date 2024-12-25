#include "my_array_search.h"
#include <stdint.h>

// Linear search algorithm that loops through an array and returns the index of the target in the array;
// Returns -1 if the target is not found in the given array;
int32_t linearSearch(int32_t* arr, uint32_t len, int32_t target) {
    for (uint32_t i = 0; i < len; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

// Binary search algorithm that starts searching an sorted array from the middle and discarding the half that doesn't contain the target;
// Returns -1 if the target is not found in the given array;
int32_t binarySearch(int32_t* arr, uint32_t len, int32_t target) {
    uint32_t start = 0;
    uint32_t end = len - 1;

    while (start <= end) {
        uint32_t mid = (end + start) / 2;

        if (target == arr[mid])
            return mid;
        else if (target > arr[mid])
            start = mid + 1;
        else 
            end = mid - 1;
    }

    return -1;
}

