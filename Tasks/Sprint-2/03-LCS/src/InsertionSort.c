#include <stdint.h>

#include "../inc/InsertionSort.h"

int8_t insertionSort(int32_t *array, uint8_t arraySize)
{
	int32_t temp;

    if(arraySize<0 || array == NULL) {return IS_EMPTY_ARRAY;}

    if(arraySize>IS_MAX_ARRAY_SIZE){
        return IS_SIZE_OUT_OF_RANGE;
    }

	for(uint8_t j=1; j<arraySize; j++)
	{
	    for(uint8_t i=j; i>0; i--)
	    {
		    if(array[i] < array[i-1])
		    {
	    		temp = array[i];
    			array[i] = array[i-1];
			    array[i-1] = temp;
		    }
		    else break;
	    }
	}

    return IS_ARRAY_SORTED;
}


void printArray(int32_t *array, uint8_t arraySize)
{
	for(uint8_t i=0; i<arraySize; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n\n");
}