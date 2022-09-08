#include "sort.h"

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

/**
 * quick_sort - check code
 * @array: array
 * @size: size to array
 */

void quick_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, ctral, first = 0, last = 0;
	double pivot;

	ctral = ( first + last) / 2;
	pivot = array[ctral];

	i = first;
	j = size - 1;

	do{
		while (array[i] < pivot) i++;
		while (array[j] > pivot) j--;

		if (i <= j)
		{
			swap(&array[i], &array[j]);
			i++;
			j--;
		}
	}while (i <= j);
	if (first < j)
		quick_sort(array, first);
	if (i < last)
		quick_sort(array, last);
}
