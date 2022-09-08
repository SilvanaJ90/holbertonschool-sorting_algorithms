
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
 * partition - check code
 * @array: array
 * @size: size array
 * Return: always i
 */


int partition(int  *array, size_t size)
{
	int pivot;
	size_t i = -1;
	size_t j;

	if (!array || size < 2)
		return (0);

	pivot = array[size - 1];

	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != size - 1)
	{
		swap(&array[i + 1], &array[size - 1]);
	}
	return (i + 1);
}
/**
 * quick_sort - check code
 * @array: Array
 * @size: Size of array
 */
void quick_sort(int *array, size_t size)
{
	size_t pivot;

	if (!array || size < 2)
		return;
	pivot = partition(array, size);
	quick_sort(array, pivot);
	quick_sort(array + pivot, size - pivot);
}

