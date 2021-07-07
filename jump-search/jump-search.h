
/* Include Guard */

#ifndef _JUMP_SEARCH_H_
#define _JUMP_SEARCH_H_

#include <bits/stdc++.h>

/* linear search algorithm */
template <typename T>
ssize_t linear_search(const T* array, ssize_t start_index, ssize_t end_index, T key_value) {
    for (ssize_t i{start_index};i < end_index;i++) {

        /* evaluate whether or not the current
         * element is the required element */
        if (*(array + i) == key_value) {
            return i;
        }
    }

    /* -1 sentinel is used to indicate
    that key_value isn't found in array */
    return -1;
}

/* jump search algorithm */
template <typename T>
ssize_t jump_search(const T* array, ssize_t array_size, T key_value) {
    ssize_t step_size{static_cast<ssize_t>(std::sqrt(array_size))};

    /* declare variable to store the start
     * index of current block under processing */
    ssize_t start_index_of_block{0};

    /* declare variable to store the end
     * index of the block already processed */
    ssize_t end_index_of_block{0};

    while (start_index_of_block < array_size) {
        if (*(array + start_index_of_block) == key_value) {
            /* if current block's first element is the required element */
            return start_index_of_block;
        } else if (*(array + start_index_of_block) < key_value) {
            /* store the start index of the current block */
            end_index_of_block = start_index_of_block;
        } else {
            /* if required block has been reached */
            return linear_search(array, end_index_of_block, start_index_of_block, key_value);
        }

        /* skip the current block */
        start_index_of_block += step_size;
    }

    /* if end block has been reached */
    return linear_search(array, end_index_of_block, array_size, key_value);
}

#endif