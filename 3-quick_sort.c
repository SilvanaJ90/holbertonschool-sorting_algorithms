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
 * quick_sort_aux - check code
 * @array: array
 * @low: value first
 * @high: value last
 * @size: size array
 */

void quick_sort_aux(int *array, int low, int high, size_t size)
{
	int j = low, i = low;
	int pivote;

	pivote = array[high];
	if (low >= high)
		return;

	for (; i < high; i++)
	{
		if (array[i] <= pivote)
		{
			if (i != j)
			{
				/* Intercambiar  */
				swap(&array[i], &array[j]);
				j++;
				print_array(array, size);
			}
			else
				j++;
		}
	}
	if (j != high)
	{
		swap(&array[j], &array[high]);
		print_array(array, size);
	}
	quick_sort_aux(array, low, j - 1, size);
	quick_sort_aux(array, j + 1, high, size);
}


/**
 * quick_sort - check code
 * @array: array
 * @size: size array
 */

void quick_sort(int *array, size_t size)
{
	size_t low = 0, high = size - 1;

	if (!array | !size)
		return;

	quick_sort_aux(array, low, high, size);
}
