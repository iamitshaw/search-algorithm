
/* Include Guard */

#ifndef _RECURSIVE_LINEAR_SEARCH_H_
#define _RECURSIVE_LINEAR_SEARCH_H_

#include <bits/stdc++.h>

/* recursive linear search algorithm */
template <typename T>
ssize_t linear_search(const T* array, ssize_t array_size, T key_value, ssize_t start_index = 0) {
    if (start_index < array_size) {
        /* if current element under consideration has
         * not exceeded last element of the array */

        if (array[start_index] == key_value) {
            /* evaluate whether or not current
             * element is the required element */

            return start_index;
        } else {
            /* scan unprocessed sub-array for key_value */
            return linear_search(array, array_size, key_value, (start_index + 1));
        }
    } else {

        /* -1 sentinel is used to indicate
        that key_value is not found */
        return -1;
    }
}

#endif