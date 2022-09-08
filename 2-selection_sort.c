#include "sort.h"

/**
 * selection_sort - check code
 * @array: pointer array
 * @size: size to array
 */

void selection_sort(int *array, size_t size)
{
	size_t indiceMenor, i, j;

	if (size == 0)
		return;

	/* ordenar a[0]..a[n-2] y a[n-1] en cada pasada */
	for (i = 0; i < size - 1; i++)						/* n */
	{
		/* Comienzo de la exploración en índice i */
		indiceMenor = i;
		/* J explora la sublista a[i+1]...a[n-1] */
		for (j = i + 1; j < size; j++)					/* n^2 */
			if (array[j] < array[indiceMenor])			/* n^2 */
				indiceMenor = j;
				/* situa el elemente mas pequeño en a[i] */
		if (i != indiceMenor)
		{
			double aux = array[i];
			array[i] = array[indiceMenor];
			array[indiceMenor] = aux;
		}
		print_array(array, size);
	}
}
