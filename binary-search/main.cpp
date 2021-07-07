#include "recursive.h"

template <typename T>
ssize_t partition(T* array, ssize_t left, ssize_t right) {

    /* initialize the seed value for the random engine generator */
    auto seed{std::chrono::system_clock::now().time_since_epoch().count()};

    /* declare a random_number_generator with a seeded value */
    std::mt19937 random_engine_generator(seed);

    std::uniform_int_distribution<size_t> distinct_number(left, right);
    size_t index{distinct_number(random_engine_generator)};

    /* place the randomly selected element at end of the current list */
    std::swap(*(array + index), *(array + right));

    /* initialize i to store the count of elements less than
     * the element array[right] in the current list */
    ssize_t i = left - 1;
    for (auto j{left};j < right;j++) {
        if (*(array + j) < *(array + right)) {
            i += 1;
            std::swap(*(array + i), *(array + j));
        }
    }
    std::swap(*(array + i + 1), *(array + right));
    return (i + 1);
}

/* quick-sort algorithm */
template <typename T>
void quick_sort(T* array, ssize_t left, ssize_t right) {
    if (left < right) {
        /* get a pivot value */
        ssize_t pivot = partition(array, left, right);

        /* decompose the array around pivot value */
        quick_sort(array, left, pivot - 1);
        quick_sort(array, pivot + 1, right);
    }
}

/* driver program */
int main(int argc, char* argv[]) {
    /* define a seed value for random_number_generator */
    auto seed{std::chrono::system_clock::now().time_since_epoch().count()};

    /* declare a random_number_generator with a seeded value */
    std::mt19937 randomNumberGenerator(seed);

    /* define an range for random numbers */
    size_t left_bound{7}, right_bound{23};
    std::uniform_int_distribution<size_t> distinct_element(left_bound, right_bound);


    /* define array_size */
    size_t array_size{13};

    /* allocate memory to store heap memory */
    auto* array = new size_t[array_size];

    /* read array elements */
    for (size_t i{0};i < array_size;i+=1) {
        array[i] = distinct_element(randomNumberGenerator);
    }

    /* print array elements */
    std::cout << "Array elements:" << std::endl;
    for (size_t i{0};i < array_size;i++) {
        std::cout << array[i] << " ";
    }

    size_t key_value{distinct_element(randomNumberGenerator)};
    std::cout << "\nKey value: " << key_value << std::endl;

    double start{static_cast<double>(clock())};
    /* sort array elements */
    quick_sort(array, 0, array_size - 1);
    double end{static_cast<double>(clock())};

    /* calculate time required */
    double time_required{(end - start)/CLOCKS_PER_SEC};
    std::cout << "Sorting time: " << time_required << "sec" << std::endl;

    /* print sorted array */
    std::cout << "\nSorted array:" << std::endl;
    for (size_t i{0};i < array_size;i++) {
        std::cout << array[i] << " ";
    }

    /* search key_value */
    start = {static_cast<double>(clock())};
    ssize_t index {binary_search(array, 0, array_size - 1, key_value)};
    end = {static_cast<double>(clock())};

    /* calculate time required */
    time_required = {(end - start)/CLOCKS_PER_SEC};
    std::cout << "\nSearching time: " << time_required << "sec" << std::endl;

    if (index != -1) {
        printf("\n%d has been found at position %d.\n", key_value, (index + 1));
    } else {
        printf("\nkey value %d has not been found!\n", key_value);
    }

    /* de-allocate heap memory */
    delete [] array;

    return 0;
}