#ifndef MY_ARRAY_SORT_
#define MY_ARRAY_SORT_

#include "my_defaults.h"


// An in-place array sorting algorithm that takes the array, the starting and ending index as parameters
void quickSort(int32_t* arr, int32_t start, int32_t end);

// In-place array sorting algorithm
void insertionSort(int32_t* arr, uint32_t len);

// A recursive divide and conquer sorting algorithm that breaks down the array and builds them up in a sorted order
void mergeSort(int32_t* arr, uint32_t len);


#endif
