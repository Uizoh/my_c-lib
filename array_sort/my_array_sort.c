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
void merge(int32_t* left_array, int32_t* right_array, int32_t* arr, uint32_t len) {
    uint32_t left_len = len / 2;
    uint32_t right_len = len - left_len;

    uint32_t o = 0, l = 0, r = 0; // Indices for original, left and right array

    // Comparing and merging in sorted order
    while (l < left_len && r < right_len) {
        if (left_array[l] < right_array[r]) {
            arr[o] = left_array[l];
            o++;
            l++;
        } else {
            arr[o] = right_array[r];
            o++;
            r++;
        }
    }

    // When no elements from the right array is left to be compared
    while (l < left_len) {
        arr[o] = left_array[l];
        o++;
        l++;
    }

    // When no elements from the left array is left to be compared
    while (r < right_len) {
        arr[o] = right_array[r];
        o++;
        r++;
    }
}


void mergeSort(int32_t* arr, uint32_t len) {
    // Base case
    if (len <= 1)
        return;

    uint32_t mid = len / 2;

    int32_t left_array[mid];
    int32_t right_array[len - mid];

    // Inserting the elements to the left and right arrays
    for (uint32_t i = 0, j = 0; i < len; i++) {
        if (i < mid) {
            left_array[i] = arr[i];
        } else {
            right_array[j] = arr[i];
            j++;
        }
    }

    // Recursive calls
    mergeSort(left_array, mid);
    mergeSort(right_array, len - mid);
    merge(left_array, right_array, arr, len);
}

