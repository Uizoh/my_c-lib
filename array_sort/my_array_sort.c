#include "my_array_sort.h"


// Quick-sort algorithm implementation
int32_t partition(int32_t* arr, int32_t start, int32_t end) {
    int32_t pivot = end - 1;
    int32_t i = start - 1;

    for (int32_t j = start; j < end; j++) {
        if (arr[j] < arr[pivot]) {
            i += 1;

            int32_t temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    i += 1;

    int32_t temp = arr[pivot];
    arr[pivot] = arr[i];
    arr[i] = temp;

    return i;
}

 
void quickSort(int32_t* arr, int32_t start, int32_t end) {
    if (start >= end) {
        return;
    }

    int32_t pivot = partition(arr, start, end);
    quickSort(arr, start, pivot);
    quickSort(arr, pivot + 1, end);
}


// Insertion sort algorithm implementation
void insertionSort(int32_t* arr, uint32_t len) {
    for (int32_t i = 1; i < len; i++) {
        int32_t j = i;

        while (j > 0 && arr[j - 1] > arr[j]) {
            int32_t temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j -= 1;
        }
    }
}


// Merge sort algorithm implementation
void merge(int32_t* arr, uint32_t len) {

}


void mergeSort(int32_t* arr, uint32_t len) {

}
