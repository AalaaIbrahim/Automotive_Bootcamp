#include <stdint.h>

#include "../inc/LCS.h"
#include "../inc/InsertionSort.h"

int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS)
{
	uint8_t count = 1, lcs_size = 1;

	if(arraySize == 0 || array==NULL) return LCS_EMPTY_ARRAY;
	if(arraySize>LCS_MAX_ARRAY_SIZE){
        return LCS_SIZE_OUT_OF_RANGE;
    }

	insertionSort(array, arraySize);

    printf("Printing sorted array for testing:\n");
    printArray(array, arraySize);

	for(uint8_t i=1; i<arraySize; i++)
	{
		if(array[i] - array[i-1] == 1)
		{
			count++;
		}
		else
		{
			if(count > lcs_size) lcs_size = count;
			/* Reset the consecutive subsequence count*/
			count = 1;
		}
	}
    if(count > lcs_size) lcs_size = count;
	*sizeofLCS = lcs_size;

	if(lcs_size == 1) return LCS_NO_CONSCUTIVE_SEQ;
	return LCS_FOUND;
}
