#ifndef _INSERTIONSORT_H_
#define _INSERTIONSORT_H_

#define IS_MAX_ARRAY_SIZE       10

#define IS_EMPTY_ARRAY          -1
#define IS_SIZE_OUT_OF_RANGE    -2
#define IS_ARRAY_SORTED          0

/**
 * @brief sorts the referenced array using insertion sort algorithm
 * 
 * @param array reference to the array to sort
 * @param arraySize size of the referenced array
 * @return int8_t  Options:
 *                  IS_EMPTY_ARRAY
 *                  IS_SIZE_OUT_OF_RANGE
 *                  IS_ARRAY_SORTED
 */
int8_t insertionSort(int32_t *array, uint8_t arraySize);

/**
 * @brief prints a referenced array 
 * 
 * @param array pointer to the array to print
 * @param arraySize size of the referenced array
 */
void printArray(int32_t *array, uint8_t arraySize);

#endif