#include <stdint.h>

#include "../inc/LCS.h"
#include "../inc/InsertionSort.h"

int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS)
{
	uint8_t count = MIN_LCS_LENGTH, lcs_size = MIN_LCS_LENGTH;
	uint8_t Local_iterator;

	if(arraySize == 0 || array==NULL) return LCS_EMPTY_ARRAY;
	if(arraySize>LCS_MAX_ARRAY_SIZE){
        return LCS_SIZE_OUT_OF_RANGE;
    }

	/* Sort Array */
	insertionSort(array, arraySize);

    printf("Printing sorted array for testing:\n");
    printArray(array, arraySize);

	for(Local_iterator=1; Local_iterator<arraySize; Local_iterator++)
	{
		if(array[Local_iterator] - array[Local_iterator-1] == 1)
		{
			count++;
		}
		else
		{
			if(count > lcs_size) lcs_size = count;
			/* Reset the consecutive subsequence count*/
			count = MIN_LCS_LENGTH;
		}
	}
    if(count > lcs_size) lcs_size = count;
	*sizeofLCS = lcs_size;

	if(lcs_size == MIN_LCS_LENGTH) return LCS_NO_CONSCUTIVE_SEQ;
	return LCS_FOUND;
}
