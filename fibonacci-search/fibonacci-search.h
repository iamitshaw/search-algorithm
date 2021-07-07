
/* Include Guard */

#ifndef _FIBONACCI_SEARCH_H_
#define _FIBONACCI_SEARCH_H_

#include <bits/stdc++.h>

/* fibonacci search algorithm */
template <typename T>
ssize_t fibonacci_search(const T* array, ssize_t array_size, T key_value) {
    std::vector<ssize_t> sequence;

    /* initial fibonacci sequence */
    sequence.push_back(0);
    sequence.push_back(1);

    ssize_t first_sequence{0};
    ssize_t second_sequence{1};

    /* store the next fibonacci sequence to be obtained after */
    ssize_t third_sequence{first_sequence + second_sequence};

    /* loop until the smallest fibonacci number which is
     * greater than or equal to size_of_array is obtained */
    while (sequence.back() < array_size) {
        /* insert the fibonacci number into the container */
        sequence.push_back(third_sequence);
        first_sequence = second_sequence;
        second_sequence = third_sequence;
        third_sequence = first_sequence + second_sequence;
    }

    size_t current{sequence.size() - 1};
    ssize_t offset{-1};

    while (sequence.at(current) > 1) {
        /* check if sequence[current - 2] is a valid index position */
        ssize_t index{std::min(offset + sequence.at(current - 2), array_size - 1)};

        if (array[index] > key_value) {
            /* if key_value is less than the value of array[index]
             * then cut the sub-array array from offset to i */
            current -= 2;
        } else if (array[index] < key_value) {
            /* if key_value is greater than the value of array[index]
             * then cut the sub-array after (index + 1) */
            current -= 1;
            offset = index;
        } else {
            /* if the element that is being searched
             * is present at the current index  */
            return index;
        }
    }

    /* comparing last element with key_value */
    if (sequence.at(current - 1) != 0 && array[offset + 1] == key_value) {
        return (offset + 1);
    } else {
        /* -1 sentinel is used to indicate
         * that key_value hasn't been found! */
        return -1;
    }
}

#endif