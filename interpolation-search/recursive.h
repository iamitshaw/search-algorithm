
/* Include Guard */

#ifndef _RECURSIVE_INTERPOLATION_SEARCH_H_
#define _RECURSIVE_INTERPOLATION_SEARCH_H_

#include <bits/stdc++.h>

/* recursive interpolation search algorithm */
ssize_t interpolation_search(const size_t* array, ssize_t right, size_t key_value, ssize_t left=0) {

    if (left < right) {

        /* if left and right index values are equal then probing for
         * index value will fail and result in divide by zero exception. */
        if (array[left] == array[right]) {
            return (array[left] == key_value)? left: -1;
        }

        /* Probing the index value but keeping uniform distribution in mind. */
        auto index = (ssize_t)(left + ((double)(key_value - array[left])/(double)(array[right] - array[left]))
                                      * (double)(right - left));

        if (index < left or index > right) {
            /* -----* bound checking *----- */
            return -1;
        }

        if (array[index] == key_value) {
            /* evaluate whether or not the key_value to be searched is
             * present at the index position of the current sub-array */
            return index;
        } else if (array[index] > key_value) {
            /* if key_value is less than array[index] then key_value can be present only
             * in the left of the current sub-array before the index position element */
            return interpolation_search(array, index - 1, key_value, left);
        } else {
            /* if key_value is greater than array[index] then key_value can be present only
             * in the right of the current sub-array after the index position element */
            return interpolation_search(array,  right, key_value, index + 1);
        }
    } else {

        /* -1 sentinel is used to indicate that key_value isn't found */
        return -1;
    }
}

#endif