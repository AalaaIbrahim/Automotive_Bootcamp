#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "../inc/InsertionSort.h"
#include "../inc/LCS.h"

#pragma warning(disable : 4996)

int main()
{
	uint8_t i = 0, lcs;
	int8_t result;
	int32_t array[30];
	uint8_t line[9], * next;

	printf("\nEnter your array, each element on a separate line\n\n");

	/* Get each array element on a separate line */
	while (fgets(line, sizeof(line), stdin))
	{
		/* Break if user presses Enter on a new line */
		if (!strcmp(line, "\n")) break;

		/* convert each line into long and store it */
		array[i++] = strtol(line, &next, 10);
	}

	result = lcsGetSize(array, i, &lcs);

	switch (result)
	{
	case LCS_FOUND:
		printf("Size of the LCS: %d\n", lcs);
		break;

	case LCS_EMPTY_ARRAY:
		printf("Empty Array!!\n");
		break;

	case LCS_SIZE_OUT_OF_RANGE:
		printf("Array size is out of range.\n");
		break;

	case LCS_NO_CONSCUTIVE_SEQ:
		printf("All array elements are not consecutive.\n");
		break;
	}

	printf("\nPress Enter to exit.");

	while (getchar()) break;

	return 0;
}
