#include "sort.h"



void quick_sort_aux(int *array, int first, int last, size_t size)
{
	int i, j, central;
	double pivote;

	if (size < 1)
		return;
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
		print_array(array, size);
	} while (i <= j);
	if (first < j)
		quick_sort_aux(array, first, j, size); /* proceso con sublista izqda */
	if (i < last)
		quick_sort_aux(array, i, last, size); /* mismo proceso sublista drcha */
}

void quick_sort(int *array, size_t size)
{
	int first = 0, last = size - 1;

	quick_sort_aux(array, first, last, size);
}
