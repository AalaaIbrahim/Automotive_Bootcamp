#ifndef _INC_LCS_H_
#define _INC_LCS_H_

#define LCS_MAX_ARRAY_SIZE       10

#define LCS_EMPTY_ARRAY          -1
#define LCS_SIZE_OUT_OF_RANGE    -2
#define LCS_NO_CONSCUTIVE_SEQ    -3
#define LCS_FOUND                 0

/**
 * @brief returns the longest subsequence of consecutive integers
 *        in the given array
 * 
 * @param array a reference to desired array of integers 
 * @param arraySize size of referenced array (should be less than LCS_MAX_ARRAY_SIZE)
 * @param sizeofLCS reference to a variable to return the size of LCS into
 * @return int8_t : LCS_EMPTY_ARRAY 
 *                  LCS_SIZE_OUT_OF_RANGE
 *                  LCS_NO_CONSCUTIVE_SEQ
 *                  LCS_FOUND
 */
int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS);

#endif