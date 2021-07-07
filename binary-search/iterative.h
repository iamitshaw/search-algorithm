
/* Include Guard */

#ifndef _ITERATIVE_BINARY_SEARCH_H_
#define _ITERATIVE_BINARY_SEARCH_H_

#include <bits/stdc++.h>

/* iterative binary search algorithm */
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
             * only in the left of the current sub-array before the middle element */
            right = mid - 1;
        } else {

            /* if key_value is greater than array[mid] then key_value can be present
             * only in the right of the current sub-array after the middle element */
            left = mid + 1;
        }
    }

    /* -1 sentinel is used to indicate that key_value is not found */
    return -1;
}

#endif