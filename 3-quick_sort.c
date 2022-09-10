#include "sort.h"

/**
 * quick_sort_aux - check code
 * @array: array
 * @first: value first
 * @last: value last
 * @size: size array
 */

void quick_sort_aux(int *array, int first, int last, size_t size)
{
	int i, j, central;
	double pivote;

	i = first;
	j = last;

	central = (first + last) / 2;
	pivote = array[central];

	do {
		while (array[i] < pivote)
			i++;
		while (array[j] > pivote)
			j--;
		if (i <= j)
		{
			double tmp;

			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp; /* intercambia a[i] con a[j] */
			i++;
			j--;
		}
	} while (i <= j);
	if (first < j)
		quick_sort_aux(array, first, j, size); /* proceso con sublista izqda */
	if (i < last)
		quick_sort_aux(array, i, last, size); /* mismo proceso sublista drcha */
}

/**
 * quick_sort - check code
 * @array: array
 * @size: size array
 */

void quick_sort(int *array, size_t size)
{
	int first = 0, last = size - 1;

	if (!array | !size)
		return;

	quick_sort_aux(array, first, last, size);
}
