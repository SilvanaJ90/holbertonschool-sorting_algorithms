#include "sort.h"
#include <time.h>

/**
 * swap - check code
 * @xp: array
 * @yp: tamapo
 */
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubble_sort(int *array, size_t size)
{
	/*clock_t begin = clock();*/
	size_t i, j;

	/* el -1 es porque no se quiere llegar al final */
	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
			if (array[j] > array[j + 1])
				/* Intercambiar  */
				swap(&array[j], &array[j + 1]);
}

void printArray(int arr[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("%d%s", arr[i], i + 1 == size ? "}" : ", ");
	printf("\n");
}
