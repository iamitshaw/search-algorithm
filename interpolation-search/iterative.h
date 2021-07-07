
/* Include Guard */

#ifndef _ITERATIVE_INTERPOLATION_SEARCH_H_
#define _ITERATIVE_INTERPOLATION_SEARCH_H_

#include <bits/stdc++.h>

/* interpolation search algorithm */
template <typename T>
ssize_t interpolation_search(const T* array, ssize_t array_size, T key_value) {
    /* declare left and right index */
    ssize_t left{0};
    ssize_t right{array_size - 1};

    while (left <= right) {

        /* if left and right index values are equal then probing for
         * index value will fail and result in divide by zero exception.  */
        if (array[left] == array[right]) {
            return (array[left] == key_value)? left: -1;
        }

        /* Probing the index value but keeping uniform distribution in mind. */
        int index = (int)(left + ((double)(key_value - array[left])/(array[right] - array[left]))
                                 * (right - left));

        if (index < left or index > right) {
            /* -----* bound checking *----- */
            return - 1;
        }

        if (array[index] == key_value) {
            /* evaluate whether or not the key_value to be searched is
             * present at the index position of the current sub-array */
            return index;
        } else if (array[index] > key_value) {
            /* if key_value is less than array[index] then key_value can be present only
             * in the left of the current sub-array before the index position element */
            right = index - 1;
        } else {
            /* if key_value is greater than array[index] then key_value can be present only
             * in the right of the current sub-array after the index position element */
            left = index + 1;
        }
    }

    /* -1 sentinel is used to indicate that key_value isn't found */
    return -1;
}

#endif