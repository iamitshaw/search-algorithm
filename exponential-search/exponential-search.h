
/* Include Guard */

#ifndef _EXPONENTIAL_SEARCH_H_
#define _EXPONENTIAL_SEARCH_H_

#include <bits/stdc++.h>

/* binary search algorithm */
template <typename T>
ssize_t binary_search(const T* array, ssize_t left, ssize_t right, T key_value) {
    while (left <= right) {
        ssize_t mid{left + (right - left)/2};
        if (*(array + mid) == key_value) {

            /* evaluate whether or not the key_value to be searched
             * is present at the middle of the current sub-array */
            return mid;
        } else if (*(array + mid) > key_value) {

            /* if key_value is less than array[mid] then key_value can be present
             * only in the left of the current sub-array before middle element */
            right = mid - 1;
        } else {

            /* if key_value is greater than array[mid] then key_value can be present
             * only in the right of the current sub-array after the middle element */
            left = mid + 1;
        }
    }

    /* -1 sentinel is used to indicate that key_value isn't found */
    return -1;
}

/* exponential search algorithm */
template <typename T>
ssize_t exponential_search(const T* array, ssize_t array_size, T key_value) {

    if (array_size == 0) {
        /* if no element is present in the array */
        return -1;
    }

    if (array[0] == key_value) {
        /* if first element of the array is the required element */
        return 0;
    }

    ssize_t index{1};

    /* find range for binary search by repeated doubling */
    while (index < array_size) {
        if (array[index] == key_value) {

            /* evaluate whether or not the key_value to be searched is
             * present at the index position of the current sub-array */
            return index;
        } else if (array[index] < key_value) {

            /* if key_value is greater than array[index] then key_value
             * can be present only in the right of the current sub-array
             * after index position element so skip current sub-array */
            index *= 2;
        } else {

            /* if key_value is less than array[index] then key_value can be
             * present only in the left of the current sub-array before the
             * index position element so required block has been reached */
            return binary_search(array, index / 2, index - 1, key_value);
        }
    }

    /* if end block of the array has been reached. */
    return binary_search(array, index / 2, array_size - 1, key_value);
}

#endif