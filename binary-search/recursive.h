
/* Include Guard */

#ifndef _RECURSIVE_BINARY_SEARCH_H_
#define _RECURSIVE_BINARY_SEARCH_H_

#include <bits/stdc++.h>

/* recursive binary search algorithm */
template <typename T>
ssize_t binary_search(const T* array, ssize_t left, ssize_t right, T key_value) {
    if (left <= right) {
        ssize_t mid{left + (right - left)/2};
        if (*(array + mid) == key_value) {

            /* evaluate whether or not the key_value to be searched
             * is present at the middle of the current sub-array */
            return mid;
        } else if (*(array + mid) > key_value) {

            /* if key_value is less than array[mid] then key_value can be present
             * only in the left of the current sub-array before the middle element */
            return binary_search(array, left, mid - 1, key_value);
        } else {

            /* if key_value is greater than array[mid] then key_value can be present
             * only in the right of the current sub-array after the middle element */
            return binary_search(array, mid + 1, right, key_value);
        }
    } else {

        /* -1 sentinel is used to indicate that key_value is not found */
        return -1;
    }
}

#endif