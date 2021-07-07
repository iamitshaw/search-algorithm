
/* Include Guard */

#ifndef _ITERATIVE_LINEAR_SEARCH_H_
#define _ITERATIVE_LINEAR_SEARCH_H_

#include <bits/stdc++.h>

/* iterative linear search algorithm */
template <typename T>
ssize_t linear_search(const T* array, ssize_t array_size, T key_value) {
    for (ssize_t i{0}; i < array_size; i++) {

        /* evaluate whether or not the current
         * element is the required element */
        if (*(array + i) == key_value) {
            return i;
        }
    }

    /* -1 sentinel is used to indicate
    that key_value is not found */
    return -1;
}

#endif