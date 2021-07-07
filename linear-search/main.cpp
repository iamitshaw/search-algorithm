#include "iterative.h"

int main(int argc, char* argv[]) {

    /* define a seed value for random_number_generator */
    auto seed{std::chrono::system_clock::now().time_since_epoch().count()};

    /* declare a random_number_generator with a seeded value */
    std::mt19937 random_number_generator(seed);

    /* define an range for random numbers */
    size_t left_bound{7}, right_bound{23};
    std::uniform_int_distribution<size_t> distinct_element(left_bound, right_bound);


    /* define array_size */
    size_t array_size{11};

    /* allocate memory to store heap memory */
    auto* array = new size_t[array_size];

    /* read array elements */
    for (size_t i{0};i < array_size;i+=1) {
        array[i] = distinct_element(random_number_generator);
    }

    /* print array elements */
    std::cout << "Array elements:" << std::endl;
    for (size_t i{0};i < array_size;i++) {
        std::cout << array[i] << " ";
    }

    size_t key_value{distinct_element(random_number_generator)};
    std::cout << "\nKey value: " << key_value << std::endl;

    ssize_t index {linear_search(array, array_size, key_value)};

    if (index != -1) {
        printf("\n%d has been found at position %d.\n", key_value, (index + 1));
    } else {
        printf("\nkey value %d has not been found!\n", key_value);
    }

    /* de-allocate heap memory */
    delete [] array;

    return 0;
}